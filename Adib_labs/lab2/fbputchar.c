/*
 * fbputchar.c: Framebuffer character generator for VGA display
 * CSEE 4840 Lab 2
 *
 * Assumes 32bpp and provides functions to render text and manage the screen.
 */

#include "fbputchar.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <string.h>

#define FBDEV "/dev/fb0"
#define FONT_WIDTH 8
#define FONT_HEIGHT 16
#define BITS_PER_PIXEL 32

struct fb_var_screeninfo fb_vinfo;
struct fb_fix_screeninfo fb_finfo;
unsigned char *framebuffer;
static unsigned char font[];

/*
 * Open the framebuffer to prepare it for writing.
 * Returns 0 on success or an error code on failure.
 */
int fbopen() {
    int fd = open(FBDEV, O_RDWR); 
    if (fd == -1) return FBOPEN_DEV;

    if (ioctl(fd, FBIOGET_FSCREENINFO, &fb_finfo)) 
        return FBOPEN_FSCREENINFO;

    if (ioctl(fd, FBIOGET_VSCREENINFO, &fb_vinfo)) 
        return FBOPEN_VSCREENINFO;

    if (fb_vinfo.bits_per_pixel != 32) 
        return FBOPEN_BPP;

    framebuffer = mmap(0, fb_finfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (framebuffer == (unsigned char *)-1) 
        return FBOPEN_MMAP;

    return 0;
}

/*
 * Draw a character at the specified row and column.
 */
void fbputchar(char c, int row, int col) {
    int x, y;
    unsigned char pixels, *pixelp = font + FONT_HEIGHT * c;
    unsigned char mask;
    unsigned char *pixel, *left = framebuffer +
        (row * FONT_HEIGHT * 2 + fb_vinfo.yoffset) * fb_finfo.line_length +
        (col * FONT_WIDTH * 2 + fb_vinfo.xoffset) * BITS_PER_PIXEL / 8;

    for (y = 0 ; y < FONT_HEIGHT * 2 ; y++, left += fb_finfo.line_length) {
        pixels = *pixelp;
        pixel = left;
        mask = 0x80;
        for (x = 0 ; x < FONT_WIDTH ; x++) {
            if (pixels & mask) {    
                pixel[0] = 255; // Red
                pixel[1] = 255; // Green
                pixel[2] = 255; // Blue
                pixel[3] = 0;
            } else {
                pixel[0] = 0;
                pixel[1] = 0;
                pixel[2] = 0;
                pixel[3] = 0;
            }
            pixel += 4;
            mask >>= 1;
        }
        if (y & 0x1) pixelp++;
    }
}

/*
 * Draw a string at the specified row and column.
 */
void fbputs(const char *s, int row, int col) {
    char c;
    while ((c = *s++) != 0) fbputchar(c, row, col++);
}

/*
 * Clear the entire screen.
 */
void fbclear() {
    for (int y = 0; y < 23; y++) {
        for (int x = 0; x < 64; x++) {
            fbputchar(' ', y, x);
        }
    }
}
