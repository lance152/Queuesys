一个简单的事件驱动银行排队系统

整个队列系统（Queue System）有一个顾客队列（Queue）以及n个服务窗口（Service Window),还有两种事件（顾客到达事件，顾客离开事件）

对于整个系统，我们需要提供两个参数：1. 总共的服务时间 2. 服务窗口数量
我们希望通过给定以上两个参数，以及总共的模拟次数，来算出每个顾客的平均停留时间以及每分钟到达顾客的数量

我们需要实现的东西有：
1. 服务窗口类
2. 顾客队列类
3. 顾客结构

细分一下，我们需要：

1. QueueSystem 类 //队列系统（整个系统）
根据我们的main函数，这个类需要至少三个接口，1. 模拟 simulate（）2. 获取顾客平均逗留时间 getAvgStayTime（）3. 获取平均每分钟顾客数 getAvgCustomers（）
以上需要public权限
内部需要一些private函数来帮助，需要
1.1 init（） 初始化顾客队列
1.2 run（）系统运行一次
1.3 end（） 收尾，清空参数
1.4 getIdleServiceWindow（）获取空闲窗口索引
1.5 customerArrived（） 处理顾客到达事件
1.6 customerDeparture（） 处理顾客离开事件
成员包括：
1.1 服务窗口总数 window_num;
1.2 总的营业时间 total_service_time
1.3 顾客总的逗留时间 total_customer_stay_time
1.4 顾客总数 total_customer_num
1.5 Queue<Customer>
1.6 Queue<Event>
1.7 ServiceWindow* window
1.8 Event* current_event

2. ServiceWindow 类 //服务窗口类
成员：
Customer customer；
WindowStatus window_status （这里我们使用了enum）

成员函数：
1. 构造函数
2. isIdle（） 返回该服务窗口是否空闲
3. serveCustomer(Customer &customer) 表示该服务窗口正在服务客户
4. setBusy（） 设置该服务窗口为占用
5. setIdle（） 设置该服务窗口为空闲
6. getCustomerArriveTime（） 获取顾客到来时间
7. getCustomerDuration（） 获取顾客逗留时间

3. Queue 类 //顾客队列类，这里我们选择自己实现一个队列
因为我们有customer队列以及event队列，所以需要用模板类
成员：
1. 头节点
2. 尾节点

成员函数：
1. 构造函数
2. 析构函数
3. 清空队列
4. 入队
5. 出队
6. 对于事件，由于他的occur_time是随机的，我们需要一个特殊的函数把他插入到合适的位置
7. 长度


4. Customer 类//顾客类，即queue中每个结点的类型
这里不需要定义一个类，用一个struct即可
变量：
1. arrive_time
2. duration
3. 下一个节点的指针

构造函数（int arrive_time=0,int duration = Random::uniform(RANDOM_PARAMETER)

5. Event 类//事件类
类似customer类，我们用一个struct
变量：
1. occur_time
2. event_type // -1表示到达事件，>=0表示离开事件,同时数值表示离开的窗口索引
3. Event* next
