// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcollatz.h for the primary calling header

#include "Vcollatz__pch.h"
#include "Vcollatz__Syms.h"
#include "Vcollatz___024root.h"

void Vcollatz___024root___ctor_var_reset(Vcollatz___024root* vlSelf);

Vcollatz___024root::Vcollatz___024root(Vcollatz__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vcollatz___024root___ctor_var_reset(this);
}

void Vcollatz___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vcollatz___024root::~Vcollatz___024root() {
}
