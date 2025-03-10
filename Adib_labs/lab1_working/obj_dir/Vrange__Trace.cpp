// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vrange__Syms.h"


void Vrange::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vrange__Syms* __restrict vlSymsp = static_cast<Vrange__Syms*>(userp);
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vrange::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vrange__Syms* __restrict vlSymsp = static_cast<Vrange__Syms*>(userp);
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->range__DOT__cgo));
            tracep->chgBit(oldp+1,(vlTOPp->range__DOT__cdone));
            tracep->chgIData(oldp+2,(vlTOPp->range__DOT__n),32);
            tracep->chgCData(oldp+3,(vlTOPp->range__DOT__num),4);
            tracep->chgBit(oldp+4,(vlTOPp->range__DOT__running));
            tracep->chgBit(oldp+5,(vlTOPp->range__DOT__we));
            tracep->chgSData(oldp+6,(vlTOPp->range__DOT__din),16);
            tracep->chgSData(oldp+7,(vlTOPp->range__DOT__mem[0]),16);
            tracep->chgSData(oldp+8,(vlTOPp->range__DOT__mem[1]),16);
            tracep->chgSData(oldp+9,(vlTOPp->range__DOT__mem[2]),16);
            tracep->chgSData(oldp+10,(vlTOPp->range__DOT__mem[3]),16);
            tracep->chgSData(oldp+11,(vlTOPp->range__DOT__mem[4]),16);
            tracep->chgSData(oldp+12,(vlTOPp->range__DOT__mem[5]),16);
            tracep->chgSData(oldp+13,(vlTOPp->range__DOT__mem[6]),16);
            tracep->chgSData(oldp+14,(vlTOPp->range__DOT__mem[7]),16);
            tracep->chgSData(oldp+15,(vlTOPp->range__DOT__mem[8]),16);
            tracep->chgSData(oldp+16,(vlTOPp->range__DOT__mem[9]),16);
            tracep->chgSData(oldp+17,(vlTOPp->range__DOT__mem[10]),16);
            tracep->chgSData(oldp+18,(vlTOPp->range__DOT__mem[11]),16);
            tracep->chgSData(oldp+19,(vlTOPp->range__DOT__mem[12]),16);
            tracep->chgSData(oldp+20,(vlTOPp->range__DOT__mem[13]),16);
            tracep->chgSData(oldp+21,(vlTOPp->range__DOT__mem[14]),16);
            tracep->chgSData(oldp+22,(vlTOPp->range__DOT__mem[15]),16);
            tracep->chgIData(oldp+23,(vlTOPp->range__DOT__c1__DOT__dout),32);
        }
        tracep->chgBit(oldp+24,(vlTOPp->clk));
        tracep->chgBit(oldp+25,(vlTOPp->go));
        tracep->chgIData(oldp+26,(vlTOPp->start),32);
        tracep->chgBit(oldp+27,(vlTOPp->done));
        tracep->chgSData(oldp+28,(vlTOPp->count),16);
        tracep->chgCData(oldp+29,(vlTOPp->range__DOT__addr),4);
    }
}

void Vrange::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vrange__Syms* __restrict vlSymsp = static_cast<Vrange__Syms*>(userp);
    Vrange* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
