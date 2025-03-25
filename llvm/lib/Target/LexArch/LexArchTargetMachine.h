#ifndef LLVM_LIB_TARGET_LEXARCH_LEXARCHTARGETMACHINE_H
#define LLVM_LIB_TARGET_LEXARCH_LEXARCHTARGETMACHINE_H

#include "LexArchSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheLexArchTarget;

class LexArchTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  LexArchSubtarget Subtarget;

public:
  LexArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const LexArchSubtarget *getSubtargetImpl(const Function &) const override {
    LEXARCH_DUMP_CYAN
    return &Subtarget;
  }
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_LEXARCH_LEXARCHTARGETMACHINE_H
