#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <cstdlib>

#include "Event.h"

template<typename T>
class Queue{
public:
  Queue(){
    this->front = new T;
    //如果内存分配失败，则不继续运行
    if(!this->front){
      exit(-1);
    }

    this->front->next = NULL;
    this->rear = this->front;
  }

  ~Queue(){
    //清空当前队列中的元素
    this->clearQueue();

    //删除头节点
    delete this->front;

  }

  void clearQueue(){
    T* temp_node;

    while(this->front->next){
      temp_node = this->front->next;
      this->front->next = temp_node->next;
      delete temp_node;
    }

    this->front->next = NULL;
    this->rear = this->front;
  }

  T* push(T& node){
    T* new_node = new T;
    //内存分配失败
    if(!new_node){
      exit(-1);
    }

    *new_node = node;
    this->rear->next = new_node;
    this->rear = new_node;
    return this->front;
  }

  T* pop(){
    if(!this->front->next){
      return NULL;
    }

    T* temp_node = this->front->next;
    this->front->next = temp_node->next;

    if(this->rear = temp_node) this->rear = this->front;//如果只有一个节点，则把尾节点指向头节点
    return temp_node;
  }

  T* Eventpush(Event &event){
    Event* temp = new Event;
    if(!temp){
      exit(-1);
    }
    *temp = event;

    //如果队列中没有event，则直接入队
    if(!this->front->next){
      push(*temp);
      return this->front;
    }

    Event *temp_event_list = this->front;

    while(temp_event_list->next && temp_event_list->next->occur_time<event.occur_time){
      temp_event_list = temp_event_list->next;
    }

    temp->next = temp_event_list->next;
    temp_event_list->next = temp;

    return this->front;
  }

  int length(){
    T* temp_node;
    temp_node = this->front->next;
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
