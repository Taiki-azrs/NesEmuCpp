#ifndef CASSETTE_H
#define CASSETE_H
#include "type.hpp"
#include <fstream>
namespace nes{
  class cassete{
  public:
    cassete(std::string filename);
  private:
    std::vector<byte> PRG_ROM;
    std::vector<byte> CHR_ROM;
#endif
