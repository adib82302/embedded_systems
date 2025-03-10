// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcollatz__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vcollatz::Vcollatz(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcollatz__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , go{vlSymsp->TOP.go}
    , done{vlSymsp->TOP.done}
    , n{vlSymsp->TOP.n}
    , dout{vlSymsp->TOP.dout}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vcollatz::Vcollatz(const char* _vcname__)
    : Vcollatz(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcollatz::~Vcollatz() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vcollatz___024root___eval_debug_assertions(Vcollatz___024root* vlSelf);
#endif  // VL_DEBUG
void Vcollatz___024root___eval_static(Vcollatz___024root* vlSelf);
void Vcollatz___024root___eval_initial(Vcollatz___024root* vlSelf);
void Vcollatz___024root___eval_settle(Vcollatz___024root* vlSelf);
void Vcollatz___024root___eval(Vcollatz___024root* vlSelf);

void Vcollatz::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcollatz::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcollatz___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vcollatz___024root___eval_static(&(vlSymsp->TOP));
        Vcollatz___024root___eval_initial(&(vlSymsp->TOP));
        Vcollatz___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vcollatz___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vcollatz::eventsPending() { return false; }

uint64_t Vcollatz::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vcollatz::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vcollatz___024root___eval_final(Vcollatz___024root* vlSelf);

VL_ATTR_COLD void Vcollatz::final() {
    Vcollatz___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcollatz::hierName() const { return vlSymsp->name(); }
const char* Vcollatz::modelName() const { return "Vcollatz"; }
unsigned Vcollatz::threads() const { return 1; }
void Vcollatz::prepareClone() const { contextp()->prepareClone(); }
void Vcollatz::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vcollatz::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vcollatz___024root__trace_decl_types(VerilatedVcd* tracep);

void Vcollatz___024root__trace_init_top(Vcollatz___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcollatz___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcollatz___024root*>(voidSelf);
    Vcollatz__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vcollatz___024root__trace_decl_types(tracep);
    Vcollatz___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vcollatz___024root__trace_register(Vcollatz___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vcollatz::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vcollatz::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vcollatz___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
