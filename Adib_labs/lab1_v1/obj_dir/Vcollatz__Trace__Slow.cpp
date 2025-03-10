// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcollatz__Syms.h"


//======================

void Vcollatz::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vcollatz::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcollatz__Syms* __restrict vlSymsp = static_cast<Vcollatz__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vcollatz::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vcollatz::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vcollatz__Syms* __restrict vlSymsp = static_cast<Vcollatz__Syms*>(userp);
    Vcollatz* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vcollatz::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vcollatz__Syms* __restrict vlSymsp = static_cast<Vcollatz__Syms*>(userp);
    Vcollatz* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"go", false,-1);
        tracep->declBus(c+3,"n", false,-1, 31,0);
        tracep->declBus(c+4,"dout", false,-1, 31,0);
        tracep->declBit(c+5,"done", false,-1);
        tracep->declBit(c+1,"collatz clk", false,-1);
        tracep->declBit(c+2,"collatz go", false,-1);
        tracep->declBus(c+3,"collatz n", false,-1, 31,0);
        tracep->declBus(c+4,"collatz dout", false,-1, 31,0);
        tracep->declBit(c+5,"collatz done", false,-1);
    }
}

void Vcollatz::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vcollatz::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vcollatz__Syms* __restrict vlSymsp = static_cast<Vcollatz__Syms*>(userp);
    Vcollatz* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vcollatz::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vcollatz__Syms* __restrict vlSymsp = static_cast<Vcollatz__Syms*>(userp);
    Vcollatz* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk));
        tracep->fullBit(oldp+2,(vlTOPp->go));
        tracep->fullIData(oldp+3,(vlTOPp->n),32);
        tracep->fullIData(oldp+4,(vlTOPp->dout),32);
        tracep->fullBit(oldp+5,(vlTOPp->done));
    }
}
