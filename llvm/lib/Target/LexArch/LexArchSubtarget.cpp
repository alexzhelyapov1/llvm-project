#include "LexArchSubtarget.h"
#include "LexArch.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "lexArch-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "LexArchGenSubtargetInfo.inc"

LexArchSubtarget::LexArchSubtarget(const Triple &TT, const std::string &CPU,
                           const std::string &FS, const TargetMachine &TM)
    : LexArchGenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS), TLInfo(TM, *this),
      FrameLowering(*this), InstrInfo() {
  LEXARCH_DUMP_CYAN
}