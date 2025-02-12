// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vrange__Syms.h"


void Vrange___024root__trace_chg_0_sub_0(Vrange___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vrange___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root__trace_chg_0\n"); );
    // Init
    Vrange___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrange___024root*>(voidSelf);
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vrange___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vrange___024root__trace_chg_0_sub_0(Vrange___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelfRef.range__DOT__cgo));
        bufp->chgBit(oldp+1,(vlSelfRef.range__DOT__cdone));
        bufp->chgIData(oldp+2,(vlSelfRef.range__DOT__n),32);
        bufp->chgCData(oldp+3,(vlSelfRef.range__DOT__num),4);
        bufp->chgBit(oldp+4,(vlSelfRef.range__DOT__running));
        bufp->chgBit(oldp+5,(vlSelfRef.range__DOT__we));
        bufp->chgSData(oldp+6,(vlSelfRef.range__DOT__din),16);
        bufp->chgSData(oldp+7,(vlSelfRef.range__DOT__mem[0]),16);
        bufp->chgSData(oldp+8,(vlSelfRef.range__DOT__mem[1]),16);
        bufp->chgSData(oldp+9,(vlSelfRef.range__DOT__mem[2]),16);
        bufp->chgSData(oldp+10,(vlSelfRef.range__DOT__mem[3]),16);
        bufp->chgSData(oldp+11,(vlSelfRef.range__DOT__mem[4]),16);
        bufp->chgSData(oldp+12,(vlSelfRef.range__DOT__mem[5]),16);
        bufp->chgSData(oldp+13,(vlSelfRef.range__DOT__mem[6]),16);
        bufp->chgSData(oldp+14,(vlSelfRef.range__DOT__mem[7]),16);
        bufp->chgSData(oldp+15,(vlSelfRef.range__DOT__mem[8]),16);
        bufp->chgSData(oldp+16,(vlSelfRef.range__DOT__mem[9]),16);
        bufp->chgSData(oldp+17,(vlSelfRef.range__DOT__mem[10]),16);
        bufp->chgSData(oldp+18,(vlSelfRef.range__DOT__mem[11]),16);
        bufp->chgSData(oldp+19,(vlSelfRef.range__DOT__mem[12]),16);
        bufp->chgSData(oldp+20,(vlSelfRef.range__DOT__mem[13]),16);
        bufp->chgSData(oldp+21,(vlSelfRef.range__DOT__mem[14]),16);
        bufp->chgSData(oldp+22,(vlSelfRef.range__DOT__mem[15]),16);
        bufp->chgIData(oldp+23,(vlSelfRef.range__DOT__c1__DOT__dout),32);
    }
    bufp->chgBit(oldp+24,(vlSelfRef.clk));
    bufp->chgBit(oldp+25,(vlSelfRef.go));
    bufp->chgIData(oldp+26,(vlSelfRef.start),32);
    bufp->chgBit(oldp+27,(vlSelfRef.done));
    bufp->chgSData(oldp+28,(vlSelfRef.count),16);
    bufp->chgCData(oldp+29,(vlSelfRef.range__DOT__addr),4);
}

void Vrange___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrange___024root__trace_cleanup\n"); );
    // Init
    Vrange___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrange___024root*>(voidSelf);
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
