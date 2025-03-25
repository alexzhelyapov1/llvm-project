add_llvm_component_group(LexArch)

set(LLVM_TARGET_DEFINITIONS LexArch.td)

tablegen(LLVM LexArchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM LexArchGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM LexArchGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM LexArchGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM LexArchGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM LexArchGenCallingConv.inc -gen-callingconv)
tablegen(LLVM LexArchGenAsmWriter.inc -gen-asm-writer)

add_public_tablegen_target(LexArchCommonTableGen)

add_llvm_target(LexArchCodeGen
  LexArchTargetMachine.cpp
  LexArchRegisterInfo.cpp
  LexArchInstrInfo.cpp
  LexArchSubtarget.cpp
  LexArchAsmPrinter.cpp
  LexArchISelDagToDag.cpp
  LexArchISelLowering.cpp
  LexArchMCInstLower.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  LexArchInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  LexArch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
