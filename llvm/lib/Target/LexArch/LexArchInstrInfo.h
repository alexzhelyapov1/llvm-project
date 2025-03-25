#ifndef LLVM_LIB_TARGET_LEXARCH_LEXARCHINSTRINFO_H
#define LLVM_LIB_TARGET_LEXARCH_LEXARCHINSTRINFO_H

#include "LexArchRegisterInfo.h"
#include "MCTargetDesc/LexArchInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "LexArchGenInstrInfo.inc"

namespace llvm {

class LexArchSubtarget;

class LexArchInstrInfo : public LexArchGenInstrInfo {
public:
  LexArchInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_LEXARCH_LEXARCHINSTRINFO_H
