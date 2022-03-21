#ifndef RAM_H
#define RAM_H
#include "type.hpp"

namespace nes{
  class RAM{
  public:
    RAM();
    byte read(byte2 addr);
    void write(byte2 addr,byte value);
    void set_cassette(cassette cst);
  private:
    std::vector<byte> ram;
    
#endif
