// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrange.h for the primary calling header

#include "Vrange__pch.h"
#include "Vrange___024root.h"

void Vrange___024root___ico_sequent__TOP__0(Vrange___024root* vlSelf);

void Vrange___024root___eval_ico(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval_ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vrange___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vrange___024root___ico_sequent__TOP__0(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___ico_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.range__DOT__addr = (0xfU & ((IData)(vlSelfRef.range__DOT__we)
                                           ? (IData)(vlSelfRef.range__DOT__num)
                                           : vlSelfRef.start));
}

void Vrange___024root___eval_triggers__ico(Vrange___024root* vlSelf);

bool Vrange___024root___eval_phase__ico(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval_phase__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vrange___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vrange___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vrange___024root___eval_act(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vrange___024root___nba_sequent__TOP__0(Vrange___024root* vlSelf);

void Vrange___024root___eval_nba(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vrange___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vrange___024root___nba_sequent__TOP__0(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__range__DOT__running;
    __Vdly__range__DOT__running = 0;
    IData/*31:0*/ __Vdly__range__DOT__n;
    __Vdly__range__DOT__n = 0;
    CData/*3:0*/ __Vdly__range__DOT__num;
    __Vdly__range__DOT__num = 0;
    SData/*15:0*/ __Vdly__range__DOT__din;
    __Vdly__range__DOT__din = 0;
    CData/*0:0*/ __Vdly__range__DOT__cgo;
    __Vdly__range__DOT__cgo = 0;
    CData/*0:0*/ __Vdly__done;
    __Vdly__done = 0;
    IData/*31:0*/ __Vdly__range__DOT__c1__DOT__dout;
    __Vdly__range__DOT__c1__DOT__dout = 0;
    CData/*0:0*/ __Vdly__range__DOT__cdone;
    __Vdly__range__DOT__cdone = 0;
    SData/*15:0*/ __VdlyVal__range__DOT__mem__v0;
    __VdlyVal__range__DOT__mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__range__DOT__mem__v0;
    __VdlyDim0__range__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__range__DOT__mem__v0;
    __VdlySet__range__DOT__mem__v0 = 0;
    // Body
    __Vdly__range__DOT__c1__DOT__dout = vlSelfRef.range__DOT__c1__DOT__dout;
    __Vdly__range__DOT__cdone = vlSelfRef.range__DOT__cdone;
    __VdlySet__range__DOT__mem__v0 = 0U;
    __Vdly__range__DOT__running = vlSelfRef.range__DOT__running;
    __Vdly__range__DOT__n = vlSelfRef.range__DOT__n;
    __Vdly__range__DOT__din = vlSelfRef.range__DOT__din;
    __Vdly__range__DOT__cgo = vlSelfRef.range__DOT__cgo;
    __Vdly__done = vlSelfRef.done;
    __Vdly__range__DOT__num = vlSelfRef.range__DOT__num;
    if (((IData)(vlSelfRef.go) & (~ (IData)(vlSelfRef.range__DOT__running)))) {
        __Vdly__range__DOT__running = 1U;
        __Vdly__range__DOT__n = vlSelfRef.start;
        __Vdly__range__DOT__num = 0U;
        __Vdly__range__DOT__din = 0U;
        __Vdly__range__DOT__cgo = 1U;
    }
    if (vlSelfRef.range__DOT__we) {
        __VdlyVal__range__DOT__mem__v0 = vlSelfRef.range__DOT__din;
        __VdlyDim0__range__DOT__mem__v0 = vlSelfRef.range__DOT__addr;
        __VdlySet__range__DOT__mem__v0 = 1U;
    }
    if (vlSelfRef.range__DOT__running) {
        if (vlSelfRef.range__DOT__we) {
            vlSelfRef.range__DOT__we = 0U;
            if ((0xfU == (IData)(vlSelfRef.range__DOT__num))) {
                __Vdly__range__DOT__running = 0U;
                __Vdly__done = 1U;
            } else {
                __Vdly__range__DOT__n = ((IData)(1U) 
                                         + vlSelfRef.range__DOT__n);
                __Vdly__range__DOT__num = (0xfU & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.range__DOT__num)));
                __Vdly__range__DOT__din = 0U;
                __Vdly__range__DOT__cgo = 1U;
            }
        } else if (((IData)(vlSelfRef.range__DOT__cdone) 
                    & (~ (IData)(vlSelfRef.range__DOT__cgo)))) {
            vlSelfRef.range__DOT__we = 1U;
        } else if ((1U & (~ (IData)(vlSelfRef.range__DOT__cgo)))) {
            __Vdly__range__DOT__din = (0xffffU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.range__DOT__din)));
        }
    }
    if (vlSelfRef.range__DOT__cgo) {
        __Vdly__range__DOT__c1__DOT__dout = vlSelfRef.range__DOT__n;
        __Vdly__range__DOT__cdone = 0U;
        __Vdly__range__DOT__cgo = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.range__DOT__cdone)))) {
        if ((1U == vlSelfRef.range__DOT__c1__DOT__dout)) {
            __Vdly__range__DOT__cdone = 1U;
        } else {
            __Vdly__range__DOT__c1__DOT__dout = ((1U 
                                                  & vlSelfRef.range__DOT__c1__DOT__dout)
                                                  ? 
                                                 ((IData)(1U) 
                                                  + 
                                                  ((IData)(3U) 
                                                   * vlSelfRef.range__DOT__c1__DOT__dout))
                                                  : 
                                                 VL_SHIFTR_III(32,32,32, vlSelfRef.range__DOT__c1__DOT__dout, 1U));
        }
    }
    if (vlSelfRef.done) {
        __Vdly__done = 0U;
    }
    vlSelfRef.count = vlSelfRef.range__DOT__mem[vlSelfRef.range__DOT__addr];
    vlSelfRef.range__DOT__c1__DOT__dout = __Vdly__range__DOT__c1__DOT__dout;
    vlSelfRef.range__DOT__running = __Vdly__range__DOT__running;
    vlSelfRef.done = __Vdly__done;
    vlSelfRef.range__DOT__n = __Vdly__range__DOT__n;
    vlSelfRef.range__DOT__cdone = __Vdly__range__DOT__cdone;
    vlSelfRef.range__DOT__cgo = __Vdly__range__DOT__cgo;
    vlSelfRef.range__DOT__din = __Vdly__range__DOT__din;
    vlSelfRef.range__DOT__num = __Vdly__range__DOT__num;
    vlSelfRef.range__DOT__addr = (0xfU & ((IData)(vlSelfRef.range__DOT__we)
                                           ? (IData)(vlSelfRef.range__DOT__num)
                                           : vlSelfRef.start));
    if (__VdlySet__range__DOT__mem__v0) {
        vlSelfRef.range__DOT__mem[__VdlyDim0__range__DOT__mem__v0] 
            = __VdlyVal__range__DOT__mem__v0;
    }
}

void Vrange___024root___eval_triggers__act(Vrange___024root* vlSelf);

bool Vrange___024root___eval_phase__act(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vrange___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vrange___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vrange___024root___eval_phase__nba(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vrange___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrange___024root___dump_triggers__ico(Vrange___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vrange___024root___dump_triggers__nba(Vrange___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vrange___024root___dump_triggers__act(Vrange___024root* vlSelf);
#endif  // VL_DEBUG

void Vrange___024root___eval(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vrange___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("range.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vrange___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vrange___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("range.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vrange___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("range.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vrange___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vrange___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vrange___024root___eval_debug_assertions(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.go & 0xfeU))) {
        Verilated::overWidthError("go");}
}
#endif  // VL_DEBUG
