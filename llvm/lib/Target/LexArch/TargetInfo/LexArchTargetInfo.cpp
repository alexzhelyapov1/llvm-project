#include "TargetInfo/LexArchTargetInfo.h"
#include "LexArch.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheLexArchTarget() {
  LEXARCH_DUMP_YELLOW
  static Target TheLexArchTarget;
  return TheLexArchTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeLexArchTargetInfo() {
  LEXARCH_DUMP_YELLOW
  RegisterTarget<Triple::lexArch> X(getTheLexArchTarget(), "lexArch",
                                "lexArch - new super arch", "LEXARCH");
}
