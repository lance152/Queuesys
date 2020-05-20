#include "QueueSystem.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
  std::srand((unsigned)std::time(0));

  int total_service_time = 240;
  int window_num = 4;
  int simulate_num = 1e5;

  QueueSystem system(total_service_time,window_num);
  system.simulate(simulate_num);

  std::cout<<"The average time of customer stay in bank: "<<system.getAvgStayTime()<<std::endl;
  std::cout<<"The number of customer arrive bank per minute: "<<system.getAvgCustomers()<<std::endl;
}
