#include "cassette.hpp"
#define HEADER 16
namespace nes{
  cassette::cassette(std::string filename){
    // read cassette
    std::ifstream ifs(filename,std::ios::binary);
    ifs.seekg(0, std::ios::end); //seek end
    long long int size = ifs.tellg(); // current pos(size)
    ifs.seekg(0);
    //byte *data = new byte[size];
    char *data = new char[size];
    ifs.read(data,size);
    uint32_t CHR_Pages = data[5];
    uint32_t PRG_Pages = data[4];
    cassette::PRG_ROM.resize(PRG_Pages * 0x4000);
    cassette::CHR_ROM.resize(CHR_Pages * 0x2000);
    
    uint32_t PRG_ROMStart = HEADER;
    uint32_t PRG_ROMEnd = PRG_ROMStart + PRG_Pages * 0x4000;
    uint32_t CHR_ROMStart = PRG_ROMEnd;
    uint32_t CHR_ROMEnd = CHR_ROMStart + CHR_Pages * 0x2000;
    //printf("CHR_ROM:%d-%d=%dbytes,%d\n:",CHR_ROMStart,CHR_ROMEnd,CHR_ROMEnd-CHR_ROMStart,cassette::CHR_ROM.size());
    for(uint32_t i=PRG_ROMStart;i<PRG_ROMEnd;i++){
      PRG_ROM[i]=data[i];
    }
    for(uint32_t i=CHR_ROMStart;i<CHR_ROMEnd;i++){
      uint32_t offset_chr_rom=i-CHR_ROMStart;
      CHR_ROM[offset_chr_rom]=data[i];
    }
  }

  byte cassette::read_PRG(byte2 addr){
    return PRG_ROM[addr];
  }
  int cassette::size_of_PRG(){
    return PRG_ROM.size();
  }
  int cassette::size_of_CHR(){
    return CHR_ROM.size();
  }
  byte cassette::read_CHR(byte2 addr){
    return CHR_ROM[addr];
  }  
}
