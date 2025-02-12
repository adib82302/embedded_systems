// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrange.h for the primary calling header

#include "Vrange__pch.h"
#include "Vrange___024root.h"

VL_ATTR_COLD void Vrange___024root___eval_static__TOP(Vrange___024root* vlSelf);
VL_ATTR_COLD void Vrange___024root____Vm_traceActivitySetAll(Vrange___024root* vlSelf);

VL_ATTR_COLD void Vrange___024root___eval_static(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vrange___024root___eval_static__TOP(vlSelf);
    Vrange___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void Vrange___024root___eval_static__TOP(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval_static__TOP\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.range__DOT__running = 0U;
}

VL_ATTR_COLD void Vrange___024root___eval_initial(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vrange___024root___eval_final(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrange___024root___dump_triggers__stl(Vrange___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vrange___024root___eval_phase__stl(Vrange___024root* vlSelf);

VL_ATTR_COLD void Vrange___024root___eval_settle(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vrange___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("range.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vrange___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrange___024root___dump_triggers__stl(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vrange___024root___ico_sequent__TOP__0(Vrange___024root* vlSelf);

VL_ATTR_COLD void Vrange___024root___eval_stl(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vrange___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vrange___024root___eval_triggers__stl(Vrange___024root* vlSelf);

VL_ATTR_COLD bool Vrange___024root___eval_phase__stl(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vrange___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vrange___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrange___024root___dump_triggers__ico(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___dump_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrange___024root___dump_triggers__act(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrange___024root___dump_triggers__nba(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vrange___024root____Vm_traceActivitySetAll(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root____Vm_traceActivitySetAll\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Vrange___024root___ctor_var_reset(Vrange___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->go = VL_RAND_RESET_I(1);
    vlSelf->start = VL_RAND_RESET_I(32);
    vlSelf->done = VL_RAND_RESET_I(1);
    vlSelf->count = VL_RAND_RESET_I(16);
    vlSelf->range__DOT__cgo = VL_RAND_RESET_I(1);
    vlSelf->range__DOT__cdone = VL_RAND_RESET_I(1);
    vlSelf->range__DOT__n = VL_RAND_RESET_I(32);
    vlSelf->range__DOT__num = VL_RAND_RESET_I(4);
    vlSelf->range__DOT__running = VL_RAND_RESET_I(1);
    vlSelf->range__DOT__we = VL_RAND_RESET_I(1);
    vlSelf->range__DOT__din = VL_RAND_RESET_I(16);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->range__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->range__DOT__addr = VL_RAND_RESET_I(4);
    vlSelf->range__DOT__c1__DOT__dout = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
