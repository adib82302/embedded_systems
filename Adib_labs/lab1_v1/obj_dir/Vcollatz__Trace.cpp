// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcollatz__Syms.h"


void Vcollatz::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vcollatz__Syms* __restrict vlSymsp = static_cast<Vcollatz__Syms*>(userp);
    Vcollatz* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vcollatz::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vcollatz__Syms* __restrict vlSymsp = static_cast<Vcollatz__Syms*>(userp);
    Vcollatz* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk));
        tracep->chgBit(oldp+1,(vlTOPp->go));
        tracep->chgIData(oldp+2,(vlTOPp->n),32);
        tracep->chgIData(oldp+3,(vlTOPp->dout),32);
        tracep->chgBit(oldp+4,(vlTOPp->done));
    }
}

void Vcollatz::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vcollatz__Syms* __restrict vlSymsp = static_cast<Vcollatz__Syms*>(userp);
    Vcollatz* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
