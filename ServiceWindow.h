#ifndef _SERVICEWINDOW_H_
#define _SERVICEWINDOW_H_

#include "Customer.h"

enum WindowStatus{
  SERVICE,
  IDLE
};

class ServiceWindow{
public:
  inline ServiceWindow(){
    window_status = IDLE;
  }

  inline bool isIdle() const{
    return window_status == IDLE;
  }

  inline void serveCustomer(Customer &customer){
    this->customer = customer;
  }

  inline void setBusy(){
    window_status = SERVICE;
  }

  inline void setIdle(){
    window_status = IDLE;
  }

  inline int getCustomerArriveTime() const{
    return customer.arrive_time;
  }

  inline int getCustomerDuration() const{
    return customer.duration;
  }

private:
  Customer customer;
  WindowStatus window_status;
};


#endif
