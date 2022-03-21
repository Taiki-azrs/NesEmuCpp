#ifndef CPU_H
#define CPU_H
#include <type.hpp>
namespace nes{
  class CPU{
  public:
    void set_pc(addr);
    void reset();
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
    
    
  };
};
#endif
