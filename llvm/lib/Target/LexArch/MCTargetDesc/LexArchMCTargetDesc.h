#ifndef LLVM_LIB_TARGET_LEXARCH_MCTARGETDESC_LEXARCHMCTARGETDESC_H
#define LLVM_LIB_TARGET_LEXARCH_MCTARGETDESC_LEXARCHMCTARGETDESC_H

// Defines symbolic names for LexArch registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "LexArchGenRegisterInfo.inc"

// Defines symbolic names for the LexArch instructions.
#define GET_INSTRINFO_ENUM
#include "LexArchGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_LEXARCH_MCTARGETDESC_LEXARCHMCTARGETDESC_H
