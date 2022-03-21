#ifndef NES_H
#define NES_H
#include "type.hpp"
#include "RAM.hpp"
#include "CPU.hpp"
#include "cassette.hpp"
namespace nes{
  class NES{
  private:
    cassette cst("hogehoge");
    CPU cpu;
    RAM ram;
  public:
    NES();
}
