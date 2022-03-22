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
  CPU::interrupt(enum intr_type t){
    byte high_addr;
    byte low_addr;
    switch(t){
    case NMI:
      high_addr=0xfffb;
      low_addr=0xfffa;
      break;
    case RESET:
      reset();
      return;
    case IRQ:
      if(P_I){
	return;
      }else{
	P_B=false;
	high_addr=0xffff;
	low_addr=0xfffe;
	break;
      }
    case BRK:
      if(P_I){
	return;
      }else{
	P_B=true;
	PC++;
	high_addr=0xffff;
	low_addr=0xfffe;
	break;
      }
    }
    byte low = bus.read(low_addr);
    byte high = bus.read(high_addr);
    byte2 addr = (high << 8) + low;
    push_stack(PC >> 8);
    push_stack(PC & 0x00FF);
    push_stack(P_N << 7 |
	       P_V << 6 |
	       P_R << 5 |
	       P_B << 4 |
	       P_D << 3 |
	       P_I << 2 |
	       P_Z << 1 |
	       P_C)
    
    P_I=true;
    PC=addr;
  }
  CPU::push_stack(byte value){
    bus.write(SP,value);
    SP--;
  }
  CPU::pop_stack(){
    SP++;
    return bus.read(SP);
  }
};
