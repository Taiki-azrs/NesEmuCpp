#include "RAM.hpp"
namespace nes{
  RAM::RAM(){
    ram.resize(0x10000);
  }
  byte RAM::read(byte2 addr){
    return ram[addr];
  }
  void RAM::write(byte2 addr,byte value){
    ram[addr]=value;
  }
    
  void RAM::set_cassette(cassette cst){
    for(int i=0;i<cst.size_of_PRG();i++){
      RAM::write(0x8000+i,cst.read_PRG(i))
    }
  }
