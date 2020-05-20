#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include "Random.h"

//const int RANDOM_PARAMETER = 100;

struct Customer{
  int arrive_time;
  int duration;
  struct Customer *next;

  Customer(int arrive_time=0,int duration = Random::uniform(RANDOM_PARAMETER)):
    arrive_time(arrive_time),
    duration(duration),
    next(NULL){}
};

#endif
