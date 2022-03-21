#ifndef TYPE_H
#define TYPE_H
#include <stdint.h>
#include <vector>
namespace nes{
  enum intr_type{
		 NMI,
		 RESET,
		 IRQ_BRK
  };
  
  using byte=uint8_t;
  using byte2=uint16_t;

  
};
#endif
