// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vrange.h for the primary calling header

#ifndef VERILATED_VRANGE___024ROOT_H_
#define VERILATED_VRANGE___024ROOT_H_  // guard

#include "verilated.h"


class Vrange__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vrange___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(go,0,0);
    VL_OUT8(done,0,0);
    CData/*0:0*/ range__DOT__cgo;
    CData/*0:0*/ range__DOT__cdone;
    CData/*3:0*/ range__DOT__num;
    CData/*0:0*/ range__DOT__running;
    CData/*0:0*/ range__DOT__we;
    CData/*3:0*/ range__DOT__addr;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(count,15,0);
    SData/*15:0*/ range__DOT__din;
    VL_IN(start,31,0);
    IData/*31:0*/ range__DOT__n;
    IData/*31:0*/ range__DOT__c1__DOT__dout;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 16> range__DOT__mem;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vrange__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vrange___024root(Vrange__Syms* symsp, const char* v__name);
    ~Vrange___024root();
    VL_UNCOPYABLE(Vrange___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
