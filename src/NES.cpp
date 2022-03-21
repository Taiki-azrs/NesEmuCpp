#include "NES.hpp"
namespace nes{
  NES::NES(){
    ram.set_cassette(cst);
  }
  void NES::reset(){
    byte low = ram.read(0xfffc);
    byte high = ram.read(0xfffd);
    byte2 addr = (high << 8) + low;
    cpu.reset(addr);
  }
  void NES::interrupt(byte high_addr,byte low_addr){
    byte low = ram.read(low_addr);
    byte high = ram.read(high_addr);
    byte2 addr = (high << 8) + low;
    byte2 sp = cpu.get_sp();
    byte2 pc = cpu.get_pc();    
    ram.write(sp,pc >> 8);
    ram.write(sp-1,pc & 0x0011);
    interrupt(sp-2,addr);    
  }
  
}
