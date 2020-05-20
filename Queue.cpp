#include "Queue.h"

template<typename T>
Queue<T>::Queue(){
  front = new T;
  //如果内存分配失败，则不继续运行
  if(!front){
    exit(-1);
  }

  front->next = NULL;
  rear = front;
  len = 0;
}

template<typename T>
Queue<T>::~Queue(){
  //清空当前队列中的元素
  this->clearQueue();

  //删除头节点
  delete front;

}

template<typename T>
void Queue<T>::clearQueue(){
  T* temp_node;

  while(front->next){
    temp_node = front->next;
    front->next = temp_node->next;
    delete temp_node;
  }

  front->next = NULL;
  rear = front;
}

template<typename T>
T* Queue<T>::push(T& node){
  T* new_node = new T;
  //内存分配失败
  if(!new_node){
    exit(-1);
  }

  *new_node = node;
  rear->next = new_node;
  rear = new_node;
  len++;
  return front;
}

template<typename T>
T* Queue<T>::pop(){
  if(!front->next){
    return NULL;
  }

  T* temp_node = front->next;
  front->next = temp_node->next;

  if(rear = temp_node) rear = front;//如果只有一个节点，则把尾节点指向头节点
  return temp_node;
}

template<typename T>
T* Queue<T>::Eventpush(Event &event){
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
  len++;

  return this->front;
}
