#ifndef CASSETTE_H
#define CASSETTE_H
#include "type.hpp"
#include <fstream>
namespace nes{
  class cassette{
  public:
    cassette(std::string filename);
    byte read_PRG(byte2 addr); 
    byte read_CHR(byte2 addr);
    int size_of_PRG();
    int size_of_CHR();
  private:
    std::vector<byte> PRG_ROM;
    std::vector<byte> CHR_ROM;
  };
};
#endif
