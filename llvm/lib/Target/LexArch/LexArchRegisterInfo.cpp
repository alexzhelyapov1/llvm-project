#include "LexArchRegisterInfo.h"
#include "LexArch.h"
#include "LexArchFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "LexArchGenRegisterInfo.inc"

LexArchRegisterInfo::LexArchRegisterInfo() : LexArchGenRegisterInfo(LexArch::R0) {
  LEXARCH_DUMP_GREEN
}
const MCPhysReg *
LexArchRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  LEXARCH_DUMP_GREEN
  return CSR_LexArch_SaveList;
}

BitVector LexArchRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  LEXARCH_DUMP_GREEN
  LexArchFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(LexArch::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(LexArch::R2);
  }
  return Reserved;
}

bool LexArchRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool LexArchRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  LEXARCH_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register LexArchRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  LEXARCH_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? LexArch::R2 : LexArch::R1;
}

const uint32_t *
LexArchRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  LEXARCH_DUMP_GREEN
  return CSR_LexArch_RegMask;
}
