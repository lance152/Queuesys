#include "QueueSystem.h"

QueueSystem::QueueSystem(int _total_service_time, int _window_num):
  total_service_time(_total_service_time),
  window_num(_window_num),
  total_customer_stay_time(0),
  total_customer_num(0){
    windows = new ServiceWindow[window_num];
  }

QueueSystem::~QueueSystem(){
  delete[] windows;
}

void QueueSystem::simulate(int simulate_time){
  double sum = 0;
  for(int i=0;i<simulate_time;i++){
    sum+= run();
  }

  avg_stay_time = (double)sum/simulate_time;
  avg_customers = (double)total_customer_num/total_service_time;
}

void QueueSystem::init(){
  Event* event = new Event;
  current_event = event;
}

void QueueSystem::end(){
  //设置所有窗口空闲
  for(int i=0;i!=window_num;i++){
    windows[i].setIdle();
  }
  //清空顾客队列
  customer_list.clearQueue();

  //清空事件队列
  event_list.clearQueue();
}

double QueueSystem::run(){
  init();
  while(current_event){
    if(current_event->event_type==-1){
      //顾客到达事件
      customerArrived();
    }else{
      customerDeparture();
    }
    delete current_event;

    //获得新事件
    current_event = event_list.pop();
  }
  end();
  return (double) total_customer_stay_time/total_customer_num;
}

int QueueSystem::getIdleServiceWindow(){
  for(int i=0;i!=window_num;i++){
    if(windows[i].isIdle()){
      return i;
    }
  }
  return -1;
}

//处理顾客到达事件
void QueueSystem::customerArrived(){
  //下一个顾客到达时间间隔，假设100分钟内一定有顾客来
  int intertime = Random::uniform(100);
  //下一个顾客到达时间
  int time = current_event->occur_time+intertime;
  //生成顾客到达事件
  Event temp_event(time);

  //如果该顾客在总服务时间前到达，则加入事件队列
  if (time<total_service_time){
    event_list.Eventpush(temp_event);
  }

  //把顾客加入顾客队列
  Customer *customer = new Customer(current_event->occur_time);
  if(!customer){
    exit(-1);
  }
  //找到空闲的窗口
  int idleindex = getIdleServiceWindow();
  if(idleindex>=0){
    customer = customer_list.pop();
    windows[idleindex].serveCustomer(*customer);
    windows[idleindex].setBusy();

    //同时需要一个顾客离开事件
    Event temp_event(current_event->occur_time+customer->duration,idleindex);
    event_list.Eventpush(temp_event);
  }
  delete customer;
}

//处理顾客离开事件
void QueueSystem::customerDeparture(){
  //首先判断离开时间是否大于总服务时间，如果大于则不管
  //然后要计算顾客总的逗留时间
  //如果顾客队列中有人，则立即服务该顾客
  //如果没人则把该窗口设置为idle
  if(current_event->occur_time>total_service_time){
    return;
  }
  total_customer_stay_time += windows[current_event->event_type].getCustomerDuration();

  if(customer_list.length()){
    Customer *customer;
    customer = customer_list.pop();
    windows[current_event->event_type].serveCustomer(*customer);

    //生成顾客离开事件
    Event temp_event(current_event->occur_time+customer->duration,current_event->event_type);
    event_list.Eventpush(temp_event);

    delete customer;
  }else{
    windows[current_event->event_type].setIdle();
  }

}
