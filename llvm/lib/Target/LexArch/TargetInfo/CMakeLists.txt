add_llvm_component_library(LLVMLexArchInfo
  LexArchTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  LexArch
  )
