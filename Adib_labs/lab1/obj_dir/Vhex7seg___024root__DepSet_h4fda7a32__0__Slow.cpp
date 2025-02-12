// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhex7seg.h for the primary calling header

#include "Vhex7seg__pch.h"
#include "Vhex7seg__Syms.h"
#include "Vhex7seg___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhex7seg___024root___dump_triggers__stl(Vhex7seg___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vhex7seg___024root___eval_triggers__stl(Vhex7seg___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vhex7seg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhex7seg___024root___eval_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vhex7seg___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
