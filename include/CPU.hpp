#ifndef CPU_H
#define CPU_H
#include <type.hpp>
#include "RAM.hpp"
namespace nes{
  class CPU{
  public:
    CPU(RAM &mem);
    void reset();
    void interrupt(byte high_addr,byte low_addr);
    void push_stack(byte value);
    void pop_stack();
  private:
    byte A;
    byte X;
    byte Y;
    byte2 PC=0x0000;
    byte2 SP=0x01FD;
    bool P_N=false;
    bool P_V=false;
    bool P_R=true;
    bool P_B=true;
    bool P_D=false;
    bool P_I=true;
    bool P_Z=false;
    bool P_C=false;
    
    RAM &bus;    
  };
};
#endif
