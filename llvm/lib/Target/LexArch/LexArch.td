include "llvm/Target/Target.td"
include "LexArchRegisterInfo.td"
include "LexArchInstrInfo.td"
include "LexArchCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def LexArchInstrInfo : InstrInfo;
def LexArch : Target {
  let InstructionSet = LexArchInstrInfo;
}
