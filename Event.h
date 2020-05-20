#ifndef _EVENT_H_
#define _EVENT_H_

#include "Random.h"

const int RANDOM_PARAMETER = 100;

struct Event{
  int occur_time;
  int event_type;

  Event * next;

  Event(int occur_time = Random::uniform(RANDOM_PARAMETER),int event_type=-1):
    occur_time(occur_time),
    event_type(event_type),
    next(NULL){}
};

#endif
