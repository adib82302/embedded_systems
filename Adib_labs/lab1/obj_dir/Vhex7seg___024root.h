// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vhex7seg.h for the primary calling header

#ifndef VERILATED_VHEX7SEG___024ROOT_H_
#define VERILATED_VHEX7SEG___024ROOT_H_  // guard

#include "verilated.h"


class Vhex7seg__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vhex7seg___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(a,3,0);
    VL_OUT8(y,6,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vhex7seg__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vhex7seg___024root(Vhex7seg__Syms* symsp, const char* v__name);
    ~Vhex7seg___024root();
    VL_UNCOPYABLE(Vhex7seg___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
