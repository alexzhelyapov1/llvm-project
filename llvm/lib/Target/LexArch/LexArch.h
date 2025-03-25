#ifndef LLVM_LIB_TARGET_LexArch_LexArch_H
#define LLVM_LIB_TARGET_LexArch_LexArch_H

#include "MCTargetDesc/LexArchMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define LEXARCH_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define LEXARCH_DUMP(Color) {}

#define LEXARCH_DUMP_RED LEXARCH_DUMP(llvm::raw_ostream::RED)
#define LEXARCH_DUMP_GREEN LEXARCH_DUMP(llvm::raw_ostream::GREEN)
#define LEXARCH_DUMP_YELLOW LEXARCH_DUMP(llvm::raw_ostream::YELLOW)
#define LEXARCH_DUMP_CYAN LEXARCH_DUMP(llvm::raw_ostream::CYAN)
#define LEXARCH_DUMP_MAGENTA LEXARCH_DUMP(llvm::raw_ostream::MAGENTA)
#define LEXARCH_DUMP_WHITE LEXARCH_DUMP(llvm::raw_ostream::WHITE)
namespace llvm {
class LexArchTargetMachine;
class FunctionPass;
class LexArchSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerLexArchMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                  AsmPrinter &AP);
bool LowerLexArchMachineOperandToMCOperand(const MachineOperand &MO,
                                       MCOperand &MCOp, const AsmPrinter &AP);
FunctionPass *createLexArchISelDag(LexArchTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_LexArch_LexArch_H