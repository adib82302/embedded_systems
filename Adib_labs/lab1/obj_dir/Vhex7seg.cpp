// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vhex7seg__pch.h"

//============================================================
// Constructors

Vhex7seg::Vhex7seg(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vhex7seg__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vhex7seg::Vhex7seg(const char* _vcname__)
    : Vhex7seg(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vhex7seg::~Vhex7seg() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vhex7seg___024root___eval_debug_assertions(Vhex7seg___024root* vlSelf);
#endif  // VL_DEBUG
void Vhex7seg___024root___eval_static(Vhex7seg___024root* vlSelf);
void Vhex7seg___024root___eval_initial(Vhex7seg___024root* vlSelf);
void Vhex7seg___024root___eval_settle(Vhex7seg___024root* vlSelf);
void Vhex7seg___024root___eval(Vhex7seg___024root* vlSelf);

void Vhex7seg::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vhex7seg::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vhex7seg___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vhex7seg___024root___eval_static(&(vlSymsp->TOP));
        Vhex7seg___024root___eval_initial(&(vlSymsp->TOP));
        Vhex7seg___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vhex7seg___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vhex7seg::eventsPending() { return false; }

uint64_t Vhex7seg::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vhex7seg::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vhex7seg___024root___eval_final(Vhex7seg___024root* vlSelf);

VL_ATTR_COLD void Vhex7seg::final() {
    Vhex7seg___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vhex7seg::hierName() const { return vlSymsp->name(); }
const char* Vhex7seg::modelName() const { return "Vhex7seg"; }
unsigned Vhex7seg::threads() const { return 1; }
void Vhex7seg::prepareClone() const { contextp()->prepareClone(); }
void Vhex7seg::atClone() const {
    contextp()->threadPoolpOnClone();
}
