#include "NES.hpp"
namespace nes{
  NES::NES(){
    ram.set_cassette(cst);
  }
  void NES::reset(){
    byte low = ram.read(0xfffc);
    byte high = ram.read(0xfffd);
    byte2 addr = (high << 8) + low;
    cpu.set_pc(addr);
  }
}
