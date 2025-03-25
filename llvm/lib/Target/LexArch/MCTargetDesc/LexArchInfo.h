#ifndef LLVM_LIB_TARGET_LEXARCH_MCTARGETDESC_LEXARCHINFO_H
#define LLVM_LIB_TARGET_LEXARCH_MCTARGETDESC_LEXARCHINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace LexArchOp {
enum OperandType : unsigned {
  OPERAND_LEXARCHM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace LexArchOp

} // end namespace llvm

#endif
