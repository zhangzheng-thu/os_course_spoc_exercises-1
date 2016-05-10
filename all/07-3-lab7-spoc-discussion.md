# 同步互斥(lec 19 lab7) spoc 思考题

 
## 小组思考题

1. (扩展练习) 每人用ucore中的信号量和条件变量两种手段分别实现40个同步问题中的一题。向勇老师的班级从前往后，陈渝老师的班级从后往前。请先理解与采用python threading 机制实现的异同点。

2. （扩展练习）请在lab7-answer中分析
  -  cvp->count含义是什么？cvp->count是否可能<0, 是否可能>1？请举例或说明原因。
  ```
  cvp->count是等待的进程的数目
  cvp->count正常情况下不可能会<0,因为cvp->count总是先增加后减少，如果<0,则存在错误
  cvp->count也可以>1，即有多个等待的进程
  ```
  -  cvp->owner->next_count含义是什么？cvp->owner->next_count是否可能<0, 是否可能>1？请举例或说明原因。
  ```
  cvp->owner->next_count的含义是发出了signal信号，并处于等待的进程数目。
  cvp->owner->next_count不会<0，因为cvp->owner->next_count是先加后减。
  cvp->owner->next_count也不会>1，因为进程之间存在互斥锁，原因是如果cvp->owner->next_count++，变成1，并唤醒上一个进程，自身进入等待后，上一个进程执行完毕后必然会通过cvp->owner->next_count>0的判断，执行signal操作，返回到上一进程，并执行cvp->owner->next_count--操作，又变成0。
  ```
  -  目前的lab7-answer中管程的实现是Hansen管程类型还是Hoare管程类型？请在lab7-answer中实现另外一种类型的管程。
  ```
  Hansen管程
  ```
  -  现在的管程（条件变量）实现是否有bug?

