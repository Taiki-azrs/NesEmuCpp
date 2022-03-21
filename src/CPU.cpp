#include "CPU.hpp"
#include "type.hpp"
namespace nes{
  CPU::get_sp(){
    return SP;
  }
  CPU::set_sp(addr){

  }
  CPU::reset(byte2 addr){
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
  CPU::interrupt(byte2 addr_sp,byte2 addr_pc){
    SP=addr_sp;    
    PC=addr_pc;
  }
};
