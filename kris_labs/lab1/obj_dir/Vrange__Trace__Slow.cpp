// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vrange__Syms.h"


//======================

void Vrange::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vrange::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vrange__Syms* __restrict vlSymsp = static_cast<Vrange__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vrange::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vrange::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vrange__Syms* __restrict vlSymsp = static_cast<Vrange__Syms*>(userp);
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vrange::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vrange__Syms* __restrict vlSymsp = static_cast<Vrange__Syms*>(userp);
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+25,"clk", false,-1);
        tracep->declBit(c+26,"go", false,-1);
        tracep->declBus(c+27,"start", false,-1, 31,0);
        tracep->declBit(c+28,"done", false,-1);
        tracep->declBus(c+29,"count", false,-1, 15,0);
        tracep->declBus(c+31,"range RAM_WORDS", false,-1, 31,0);
        tracep->declBus(c+32,"range RAM_ADDR_BITS", false,-1, 31,0);
        tracep->declBit(c+25,"range clk", false,-1);
        tracep->declBit(c+26,"range go", false,-1);
        tracep->declBus(c+27,"range start", false,-1, 31,0);
        tracep->declBit(c+28,"range done", false,-1);
        tracep->declBus(c+29,"range count", false,-1, 15,0);
        tracep->declBit(c+1,"range cgo", false,-1);
        tracep->declBit(c+2,"range cdone", false,-1);
        tracep->declBus(c+3,"range n", false,-1, 31,0);
        tracep->declBus(c+4,"range num", false,-1, 3,0);
        tracep->declBit(c+5,"range running", false,-1);
        tracep->declBit(c+6,"range we", false,-1);
        tracep->declBus(c+7,"range din", false,-1, 15,0);
        {int i; for (i=0; i<16; i++) {
                tracep->declBus(c+8+i*1,"range mem", true,(i+0), 15,0);}}
        tracep->declBus(c+30,"range addr", false,-1, 3,0);
        tracep->declBit(c+25,"range c1 clk", false,-1);
        tracep->declBit(c+1,"range c1 go", false,-1);
        tracep->declBus(c+3,"range c1 n", false,-1, 31,0);
        tracep->declBus(c+24,"range c1 dout", false,-1, 31,0);
        tracep->declBit(c+2,"range c1 done", false,-1);
    }
}

void Vrange::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vrange::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vrange__Syms* __restrict vlSymsp = static_cast<Vrange__Syms*>(userp);
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vrange::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vrange__Syms* __restrict vlSymsp = static_cast<Vrange__Syms*>(userp);
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->range__DOT__cgo));
        tracep->fullBit(oldp+2,(vlTOPp->range__DOT__cdone));
        tracep->fullIData(oldp+3,(vlTOPp->range__DOT__n),32);
        tracep->fullCData(oldp+4,(vlTOPp->range__DOT__num),4);
        tracep->fullBit(oldp+5,(vlTOPp->range__DOT__running));
        tracep->fullBit(oldp+6,(vlTOPp->range__DOT__we));
        tracep->fullSData(oldp+7,(vlTOPp->range__DOT__din),16);
        tracep->fullSData(oldp+8,(vlTOPp->range__DOT__mem[0]),16);
        tracep->fullSData(oldp+9,(vlTOPp->range__DOT__mem[1]),16);
        tracep->fullSData(oldp+10,(vlTOPp->range__DOT__mem[2]),16);
        tracep->fullSData(oldp+11,(vlTOPp->range__DOT__mem[3]),16);
        tracep->fullSData(oldp+12,(vlTOPp->range__DOT__mem[4]),16);
        tracep->fullSData(oldp+13,(vlTOPp->range__DOT__mem[5]),16);
        tracep->fullSData(oldp+14,(vlTOPp->range__DOT__mem[6]),16);
        tracep->fullSData(oldp+15,(vlTOPp->range__DOT__mem[7]),16);
        tracep->fullSData(oldp+16,(vlTOPp->range__DOT__mem[8]),16);
        tracep->fullSData(oldp+17,(vlTOPp->range__DOT__mem[9]),16);
        tracep->fullSData(oldp+18,(vlTOPp->range__DOT__mem[10]),16);
        tracep->fullSData(oldp+19,(vlTOPp->range__DOT__mem[11]),16);
        tracep->fullSData(oldp+20,(vlTOPp->range__DOT__mem[12]),16);
        tracep->fullSData(oldp+21,(vlTOPp->range__DOT__mem[13]),16);
        tracep->fullSData(oldp+22,(vlTOPp->range__DOT__mem[14]),16);
        tracep->fullSData(oldp+23,(vlTOPp->range__DOT__mem[15]),16);
        tracep->fullIData(oldp+24,(vlTOPp->range__DOT__c1__DOT__dout),32);
        tracep->fullBit(oldp+25,(vlTOPp->clk));
        tracep->fullBit(oldp+26,(vlTOPp->go));
        tracep->fullIData(oldp+27,(vlTOPp->start),32);
        tracep->fullBit(oldp+28,(vlTOPp->done));
        tracep->fullSData(oldp+29,(vlTOPp->count),16);
        tracep->fullCData(oldp+30,(vlTOPp->range__DOT__addr),4);
        tracep->fullIData(oldp+31,(0x10U),32);
        tracep->fullIData(oldp+32,(4U),32);
    }
}
