#include "LexArchTargetMachine.h"
#include "LexArch.h"
#include "TargetInfo/LexArchTargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeLexArchTarget() {
  // Register the target.
  LEXARCH_DUMP_CYAN
  RegisterTargetMachine<LexArchTargetMachine> A(getTheLexArchTarget());
}

LexArchTargetMachine::LexArchTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {
  LEXARCH_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// LexArch Code Generator Pass Configuration Options.
class LexArchPassConfig : public TargetPassConfig {
public:
  LexArchPassConfig(LexArchTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  LexArchTargetMachine &getLexArchTargetMachine() const {
    return getTM<LexArchTargetMachine>();
  }

  bool addInstSelector() override {
    LEXARCH_DUMP_CYAN
    addPass(createLexArchISelDag(getLexArchTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *LexArchTargetMachine::createPassConfig(PassManagerBase &PM) {
  LEXARCH_DUMP_CYAN
  return new LexArchPassConfig(*this, PM);
}

TargetLoweringObjectFile *LexArchTargetMachine::getObjFileLowering() const {
  LEXARCH_DUMP_CYAN
  return TLOF.get();
}
