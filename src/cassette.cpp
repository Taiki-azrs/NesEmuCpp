#include "cassette.hpp"
namespace nes{
  cassete::cassete(std::string filename){
    std::ifstream ifs(filename,std::ios::binary);
    ifs.seekg(0, std::ios::end); //seek end
    long long int size = ifs.tellg(); // current pos(size)
    ifs.seekg(0);
    byte *data = new byte[size];
    ifs.read(data,size);
    
  }
}
