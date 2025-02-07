// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcollatz.h for the primary calling header

#include "Vcollatz.h"
#include "Vcollatz__Syms.h"

//==========

VL_CTOR_IMP(Vcollatz) {
    Vcollatz__Syms* __restrict vlSymsp = __VlSymsp = new Vcollatz__Syms(this, name());
    Vcollatz* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcollatz::__Vconfigure(Vcollatz__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vcollatz::~Vcollatz() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vcollatz::_eval_initial(Vcollatz__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcollatz::_eval_initial\n"); );
    Vcollatz* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vcollatz::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcollatz::final\n"); );
    // Variables
    Vcollatz__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcollatz* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcollatz::_eval_settle(Vcollatz__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcollatz::_eval_settle\n"); );
    Vcollatz* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcollatz::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcollatz::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    go = VL_RAND_RESET_I(1);
    n = VL_RAND_RESET_I(32);
    dout = VL_RAND_RESET_I(32);
    done = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
