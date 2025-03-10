// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vhex7seg__pch.h"
#include "Vhex7seg.h"
#include "Vhex7seg___024root.h"

// FUNCTIONS
Vhex7seg__Syms::~Vhex7seg__Syms()
{
}

Vhex7seg__Syms::Vhex7seg__Syms(VerilatedContext* contextp, const char* namep, Vhex7seg* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(29);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
