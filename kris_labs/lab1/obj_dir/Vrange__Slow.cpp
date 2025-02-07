// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrange.h for the primary calling header

#include "Vrange.h"
#include "Vrange__Syms.h"

//==========

VL_CTOR_IMP(Vrange) {
    Vrange__Syms* __restrict vlSymsp = __VlSymsp = new Vrange__Syms(this, name());
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vrange::__Vconfigure(Vrange__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vrange::~Vrange() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vrange::_initial__TOP__2(Vrange__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange::_initial__TOP__2\n"); );
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->range__DOT__running = 0U;
}

void Vrange::_eval_initial(Vrange__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange::_eval_initial\n"); );
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vrange::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange::final\n"); );
    // Variables
    Vrange__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vrange::_eval_settle(Vrange__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange::_eval_settle\n"); );
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vrange::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    go = VL_RAND_RESET_I(1);
    start = VL_RAND_RESET_I(32);
    done = VL_RAND_RESET_I(1);
    count = VL_RAND_RESET_I(16);
    range__DOT__cgo = VL_RAND_RESET_I(1);
    range__DOT__cdone = VL_RAND_RESET_I(1);
    range__DOT__n = VL_RAND_RESET_I(32);
    range__DOT__num = VL_RAND_RESET_I(4);
    range__DOT__running = VL_RAND_RESET_I(1);
    range__DOT__we = VL_RAND_RESET_I(1);
    range__DOT__din = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            range__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }}
    range__DOT__addr = VL_RAND_RESET_I(4);
    range__DOT__c1__DOT__dout = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
