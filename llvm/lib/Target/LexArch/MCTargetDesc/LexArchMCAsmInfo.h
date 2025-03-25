#ifndef LLVM_LIB_TARGET_LEXARCH_MCTARGETDESC_LEXARCHMCASMINFO_H
#define LLVM_LIB_TARGET_LEXARCH_MCTARGETDESC_LEXARCHMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class LexArchELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit LexArchELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_LEXARCH_MCTARGETDESC_LEXARCHMCASMINFO_H