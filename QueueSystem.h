#ifndef _QUEUESYSTEM_H_
#define _QUEUESYSTEM_H_

#include "Event.h"
#include "Queue.h"
#include "ServiceWindow.h"

class QueueSystem{
public:
  //构造函数
  QueueSystem(int _total_service_time, int _window_num);

  //析构
  ~QueueSystem();

  //模拟
  void simulate(int simulate_time);

  //获取顾客平均逗留时间
  inline double getAvgStayTime() const{
    return avg_stay_time;
  }

  //获取平均每分钟顾客数量
  inline double getAvgCustomers() const{
    return avg_customers;
  }

private:
  int window_num;
  int total_service_time;
  int total_customer_num;
  int total_customer_stay_time;

  ServiceWindow* windows;
  Queue<Customer> customer_list;
  Queue<Event> event_list;
  Event* current_event;

  double avg_stay_time;
  double avg_customers;

  //系统运行一次,返回顾客逗留了多久
  double run();

  //初始化参数
  void init();

  //清空参数
  void end();

  //获取空闲窗口索引
  int getIdleServiceWindow();

  //处理顾客到达事件
  void customerArrived();

  //处理顾客离开事件
  void customerDeparture();
};

#endif
