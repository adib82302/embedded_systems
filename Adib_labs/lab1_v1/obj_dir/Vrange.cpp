// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vrange__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vrange::Vrange(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vrange__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , go{vlSymsp->TOP.go}
    , done{vlSymsp->TOP.done}
    , count{vlSymsp->TOP.count}
    , start{vlSymsp->TOP.start}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vrange::Vrange(const char* _vcname__)
    : Vrange(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vrange::~Vrange() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vrange___024root___eval_debug_assertions(Vrange___024root* vlSelf);
#endif  // VL_DEBUG
void Vrange___024root___eval_static(Vrange___024root* vlSelf);
void Vrange___024root___eval_initial(Vrange___024root* vlSelf);
void Vrange___024root___eval_settle(Vrange___024root* vlSelf);
void Vrange___024root___eval(Vrange___024root* vlSelf);

void Vrange::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrange::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vrange___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vrange___024root___eval_static(&(vlSymsp->TOP));
        Vrange___024root___eval_initial(&(vlSymsp->TOP));
        Vrange___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vrange___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vrange::eventsPending() { return false; }

uint64_t Vrange::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vrange::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vrange___024root___eval_final(Vrange___024root* vlSelf);

VL_ATTR_COLD void Vrange::final() {
    Vrange___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vrange::hierName() const { return vlSymsp->name(); }
const char* Vrange::modelName() const { return "Vrange"; }
unsigned Vrange::threads() const { return 1; }
void Vrange::prepareClone() const { contextp()->prepareClone(); }
void Vrange::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vrange::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vrange___024root__trace_decl_types(VerilatedVcd* tracep);

void Vrange___024root__trace_init_top(Vrange___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vrange___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vrange___024root*>(voidSelf);
    Vrange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vrange___024root__trace_decl_types(tracep);
    Vrange___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vrange___024root__trace_register(Vrange___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vrange::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vrange::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vrange___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
