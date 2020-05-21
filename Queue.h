#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <cstdlib>

#include "Event.h"

template<typename T>
class Queue{
public:
  Queue(){
    front = new T;
    //如果内存分配失败，则不继续运行
    if(!front){
      exit(-1);
    }

    front->next = NULL;
    rear = front;
  }

  ~Queue(){
    //清空当前队列中的元素
    clearQueue();

    //删除头节点
    delete front;

  }

  void clearQueue(){
    T* temp_node;

    while(front->next){
      temp_node = front->next;
      front->next = temp_node->next;
      delete temp_node;
    }

    front->next = NULL;
    rear = front;
  }

  T* push(T& node){
    T* new_node = new T;
    //内存分配失败
    if(!new_node){
      exit(-1);
    }

    *new_node = node;
    rear->next = new_node;
    rear = new_node;
    return front;
  }

  T* pop(){
    if(!front->next){
      return NULL;
    }

    T* temp_node = front->next;
    front->next = temp_node->next;

    if(rear = temp_node) rear = front;//如果只有一个节点，则把尾节点指向头节点
    return temp_node;
  }

  T* Eventpush(Event &event){
    Event* temp = new Event;
    if(!temp){
      exit(-1);
    }
    *temp = event;

    //如果队列中没有event，则直接入队
    if(!front->next){
      push(*temp);
      return front;
    }

    Event *temp_event_list = front;

    while(temp_event_list->next && temp_event_list->next->occur_time<event.occur_time){
      temp_event_list = temp_event_list->next;
    }

    temp->next = temp_event_list->next;
    temp_event_list->next = temp;

    return front;
  }

  int length(){
    T* temp_node;
    temp_node = front->next;
    int len = 0;
    while(temp_node){
      temp_node = temp_node->next;
      len++;
    }
    return len;
  }

private:
  T* front;
  T* rear;
};

#endif
