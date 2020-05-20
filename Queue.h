#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <cstdlib>

#include "Event.h"

template<typename T>
class Queue{
public:
  Queue();
  ~Queue();
  void clearQueue();
  T* push(T &node);
  T* pop();
  T* Eventpush(Event &event);
  inline int length() const {
    return len;
  }

private:
  T* front;
  T* rear;
  int len;
};


#endif
