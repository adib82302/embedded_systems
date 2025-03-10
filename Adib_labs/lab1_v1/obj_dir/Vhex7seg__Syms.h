// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VHEX7SEG__SYMS_H_
#define VERILATED_VHEX7SEG__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vhex7seg.h"

// INCLUDE MODULE CLASSES
#include "Vhex7seg___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vhex7seg__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vhex7seg* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vhex7seg___024root             TOP;

    // CONSTRUCTORS
    Vhex7seg__Syms(VerilatedContext* contextp, const char* namep, Vhex7seg* modelp);
    ~Vhex7seg__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
