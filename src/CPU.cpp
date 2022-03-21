#include "CPU.hpp"
#include "type.hpp"
namespace nes{
  CPU::CPU(RAM &mem) : bus(mem){}
  CPU::reset(){
    byte low = bus.read(0xfffc);
    byte high = bus.read(0xfffd);
    byte2 addr = (high << 8) + low;
    PC=addr;
    SP=0x01FD;
    P_N=false;
    P_V=false;
    P_R=true;     
    P_B=true; 
    P_D=false;
    P_I=true; 
    P_Z=false;
    P_C=false;
  }
  CPU::interrupt(byte high_addr,byte low_addr){
    byte low = bus.read(low_addr);
    byte high = bus.read(high_addr);
    byte2 addr = (high << 8) + low;
    bus.write(SP,PC >> 8);
    bus.write(SP-1,PC & 0x0011);
    SP=SP-2;    
    PC=addr;
  }
};
