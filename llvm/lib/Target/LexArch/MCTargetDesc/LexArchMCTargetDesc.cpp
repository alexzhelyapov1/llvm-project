#include "MCTargetDesc/LexArchInfo.h"
#include "LexArch.h"
#include "LexArchInstPrinter.h"
#include "LexArchMCAsmInfo.h"
#include "TargetInfo/LexArchTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "LexArchGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "LexArchGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "LexArchGenSubtargetInfo.inc"

static MCRegisterInfo *createLexArchMCRegisterInfo(const Triple &TT) {
  LEXARCH_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitLexArchMCRegisterInfo(X, LexArch::R0);
  return X;
}

static MCInstrInfo *createLexArchMCInstrInfo() {
  LEXARCH_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitLexArchMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createLexArchMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  LEXARCH_DUMP_MAGENTA
  return createLexArchMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createLexArchMCAsmInfo(const MCRegisterInfo &MRI,
                                     const Triple &TT,
                                     const MCTargetOptions &Options) {
  LEXARCH_DUMP_MAGENTA
  MCAsmInfo *MAI = new LexArchELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(LexArch::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createLexArchMCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  LEXARCH_DUMP_MAGENTA
  return new LexArchInstPrinter(MAI, MII, MRI);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeLexArchTargetMC() {
  LEXARCH_DUMP_MAGENTA
  Target &TheLexArchTarget = getTheLexArchTarget();
  RegisterMCAsmInfoFn X(TheLexArchTarget, createLexArchMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheLexArchTarget, createLexArchMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheLexArchTarget, createLexArchMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheLexArchTarget,
                                          createLexArchMCSubtargetInfo);

  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(TheLexArchTarget, createLexArchMCInstPrinter);
}
