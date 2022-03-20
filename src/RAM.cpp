#include "RAM.hpp"
namespace nes{
  RAM::RAM(){
    ram(0x1000,0);
  }
  byte RAM::read(byte2 addr){
    return ram[addr];
  }
  void RAM::write(byte2 addr,byte value){
    ram[addr]=value;
  }
    
      
