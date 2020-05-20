#ifndef _RANFOM_HPP_
#define _RANDOM_HPP_
#include <cstdlib>
#include <cmath>

class Random{
  inline static double uniform(double max=1){
    return ((double)std::rand()/(RAND_MAX))*max;
  }
};


#endif
