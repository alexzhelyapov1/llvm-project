add_llvm_component_library(LLVMLexArchDesc
  LexArchMCTargetDesc.cpp
  LexArchMCAsmInfo.cpp
  LexArchInstPrinter.cpp

  LINK_COMPONENTS
  MC
  Support
  LexArchInfo

  ADD_TO_COMPONENT
  LexArch
 )
