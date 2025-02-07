// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrange.h for the primary calling header

#include "Vrange.h"
#include "Vrange__Syms.h"

//==========

void Vrange::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrange::eval\n"); );
    Vrange__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("range.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vrange::_eval_initial_loop(Vrange__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("range.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vrange::_sequent__TOP__1(Vrange__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange::_sequent__TOP__1\n"); );
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__range__DOT__running;
    CData/*3:0*/ __Vdly__range__DOT__num;
    CData/*0:0*/ __Vdly__range__DOT__cgo;
    CData/*0:0*/ __Vdly__done;
    CData/*3:0*/ __Vdlyvdim0__range__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__range__DOT__mem__v0;
    CData/*0:0*/ __Vdly__range__DOT__cdone;
    SData/*15:0*/ __Vdly__range__DOT__din;
    SData/*15:0*/ __Vdlyvval__range__DOT__mem__v0;
    IData/*31:0*/ __Vdly__range__DOT__n;
    IData/*31:0*/ __Vdly__range__DOT__c1__DOT__dout;
    // Body
    __Vdly__range__DOT__c1__DOT__dout = vlTOPp->range__DOT__c1__DOT__dout;
    __Vdly__range__DOT__cdone = vlTOPp->range__DOT__cdone;
    __Vdlyvset__range__DOT__mem__v0 = 0U;
    __Vdly__done = vlTOPp->done;
    __Vdly__range__DOT__cgo = vlTOPp->range__DOT__cgo;
    __Vdly__range__DOT__din = vlTOPp->range__DOT__din;
    __Vdly__range__DOT__n = vlTOPp->range__DOT__n;
    __Vdly__range__DOT__running = vlTOPp->range__DOT__running;
    __Vdly__range__DOT__num = vlTOPp->range__DOT__num;
    vlTOPp->count = vlTOPp->range__DOT__mem[vlTOPp->range__DOT__addr];
    __Vdly__range__DOT__cdone = 0U;
    if (vlTOPp->range__DOT__cgo) {
        __Vdly__range__DOT__c1__DOT__dout = vlTOPp->range__DOT__n;
    } else {
        if (vlTOPp->range__DOT__cdone) {
            __Vdly__range__DOT__cdone = 1U;
        } else {
            if ((1U & vlTOPp->range__DOT__c1__DOT__dout)) {
                __Vdly__range__DOT__c1__DOT__dout = 
                    ((IData)(1U) + ((IData)(3U) * vlTOPp->range__DOT__c1__DOT__dout));
            } else {
                __Vdly__range__DOT__c1__DOT__dout = 
                    (vlTOPp->range__DOT__c1__DOT__dout 
                     >> 1U);
                if ((2U == vlTOPp->range__DOT__c1__DOT__dout)) {
                    __Vdly__range__DOT__cdone = 1U;
                }
            }
        }
    }
    if (vlTOPp->range__DOT__we) {
        __Vdlyvval__range__DOT__mem__v0 = vlTOPp->range__DOT__din;
        __Vdlyvset__range__DOT__mem__v0 = 1U;
        __Vdlyvdim0__range__DOT__mem__v0 = vlTOPp->range__DOT__addr;
    }
    if (((IData)(vlTOPp->go) & (~ (IData)(vlTOPp->range__DOT__running)))) {
        __Vdly__range__DOT__running = 1U;
        __Vdly__range__DOT__n = vlTOPp->start;
        __Vdly__range__DOT__num = 0U;
        __Vdly__range__DOT__din = 1U;
        __Vdly__range__DOT__cgo = 1U;
    }
    if (vlTOPp->range__DOT__running) {
        if (vlTOPp->range__DOT__we) {
            vlTOPp->range__DOT__we = 0U;
            if ((0xfU == (IData)(vlTOPp->range__DOT__num))) {
                __Vdly__range__DOT__running = 0U;
                __Vdly__done = 1U;
            } else {
                __Vdly__range__DOT__n = ((IData)(1U) 
                                         + vlTOPp->range__DOT__n);
                __Vdly__range__DOT__num = (0xfU & ((IData)(1U) 
                                                   + (IData)(vlTOPp->range__DOT__num)));
                __Vdly__range__DOT__din = 1U;
                __Vdly__range__DOT__cgo = 1U;
            }
        } else {
            if (((IData)(vlTOPp->range__DOT__cdone) 
                 & (~ (IData)(vlTOPp->range__DOT__cgo)))) {
                vlTOPp->range__DOT__we = 1U;
            } else {
                if ((1U & (~ (IData)(vlTOPp->range__DOT__cgo)))) {
                    __Vdly__range__DOT__din = (0xffffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlTOPp->range__DOT__din)));
                }
            }
        }
    }
    if (vlTOPp->range__DOT__cgo) {
        __Vdly__range__DOT__cgo = 0U;
    }
    if (vlTOPp->done) {
        __Vdly__done = 0U;
    }
    vlTOPp->range__DOT__c1__DOT__dout = __Vdly__range__DOT__c1__DOT__dout;
    if (__Vdlyvset__range__DOT__mem__v0) {
        vlTOPp->range__DOT__mem[__Vdlyvdim0__range__DOT__mem__v0] 
            = __Vdlyvval__range__DOT__mem__v0;
    }
    vlTOPp->done = __Vdly__done;
    vlTOPp->range__DOT__n = __Vdly__range__DOT__n;
    vlTOPp->range__DOT__cdone = __Vdly__range__DOT__cdone;
    vlTOPp->range__DOT__cgo = __Vdly__range__DOT__cgo;
    vlTOPp->range__DOT__din = __Vdly__range__DOT__din;
    vlTOPp->range__DOT__running = __Vdly__range__DOT__running;
    vlTOPp->range__DOT__num = __Vdly__range__DOT__num;
}

VL_INLINE_OPT void Vrange::_settle__TOP__3(Vrange__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange::_settle__TOP__3\n"); );
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->range__DOT__addr = (0xfU & ((IData)(vlTOPp->range__DOT__we)
                                         ? (IData)(vlTOPp->range__DOT__num)
                                         : vlTOPp->start));
}

void Vrange::_eval(Vrange__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange::_eval\n"); );
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    vlTOPp->_settle__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vrange::_change_request(Vrange__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange::_change_request\n"); );
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vrange::_change_request_1(Vrange__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange::_change_request_1\n"); );
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vrange::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((go & 0xfeU))) {
        Verilated::overWidthError("go");}
}
#endif  // VL_DEBUG
