// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcollatz.h for the primary calling header

#include "Vcollatz__pch.h"
#include "Vcollatz___024root.h"

void Vcollatz___024root___eval_act(Vcollatz___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcollatz__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcollatz___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vcollatz___024root___nba_sequent__TOP__0(Vcollatz___024root* vlSelf);

void Vcollatz___024root___eval_nba(Vcollatz___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcollatz__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcollatz___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vcollatz___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vcollatz___024root___nba_sequent__TOP__0(Vcollatz___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcollatz__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcollatz___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__dout;
    __Vdly__dout = 0;
    CData/*0:0*/ __Vdly__done;
    __Vdly__done = 0;
    // Body
    __Vdly__dout = vlSelfRef.dout;
    __Vdly__done = vlSelfRef.done;
    if (vlSelfRef.go) {
        __Vdly__dout = vlSelfRef.n;
        __Vdly__done = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.done)))) {
        if ((1U == vlSelfRef.dout)) {
            __Vdly__done = 1U;
        } else {
            __Vdly__dout = ((1U & vlSelfRef.dout) ? 
                            ((IData)(1U) + ((IData)(3U) 
                                            * vlSelfRef.dout))
                             : VL_SHIFTR_III(32,32,32, vlSelfRef.dout, 1U));
        }
    }
    vlSelfRef.dout = __Vdly__dout;
    vlSelfRef.done = __Vdly__done;
}

void Vcollatz___024root___eval_triggers__act(Vcollatz___024root* vlSelf);

bool Vcollatz___024root___eval_phase__act(Vcollatz___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcollatz__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcollatz___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vcollatz___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vcollatz___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vcollatz___024root___eval_phase__nba(Vcollatz___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcollatz__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcollatz___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vcollatz___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcollatz___024root___dump_triggers__nba(Vcollatz___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcollatz___024root___dump_triggers__act(Vcollatz___024root* vlSelf);
#endif  // VL_DEBUG

void Vcollatz___024root___eval(Vcollatz___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcollatz__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcollatz___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vcollatz___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("collatz.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vcollatz___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("collatz.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vcollatz___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vcollatz___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vcollatz___024root___eval_debug_assertions(Vcollatz___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vcollatz__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcollatz___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.go & 0xfeU))) {
        Verilated::overWidthError("go");}
}
#endif  // VL_DEBUG
