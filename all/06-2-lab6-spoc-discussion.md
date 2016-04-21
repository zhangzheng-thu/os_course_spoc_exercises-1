# lab6 spoc 思考题

- 有"spoc"标记的题是要求拿清华学分的同学要在实体课上完成，并按时提交到学生对应的ucore_code和os_exercises的git repo上。


## 个人思考题

### 总体介绍

 - ucore中的调度点在哪里，完成了啥事？
 - 进程控制块中与调度相关的字段有哪些？
 - ucore的就绪队列数据结构在哪定义？在哪进行修改？
 - ucore的等待队列数据结构在哪定义？在哪进行修改？

### 调度算法支撑框架

 - 调度算法支撑框架中的各个函数指针的功能是啥？会被谁在何种情况下调用？
 - 调度函数schedule()的调用函数分析，可以了解进程调度的原因。请分析ucore中所有可能的调度位置，并说明可能的调用原因。
  
### 时间片轮转调度算法

 - 时间片轮转调度算法是如何基于调度算法支撑框架实现的？
 - 时钟中断如何调用RR_proc_tick()的？

### stride调度算法

 - stride调度算法的思路？ 
 - stride算法的特征是什么？
 - stride调度算法是如何避免stride溢出问题的？
 - 无符号数的有符号比较会产生什么效果？
 - 什么是斜堆(skew heap)?

##课堂问答题

###为什么只用32位整数存stride的数值就够了？溢出时如何判断大小？

> 因为STRIDE_MAX – STRIDE_MIN <= PASS_MAX <= BIG_STRIDE 并且 stride, pass 是无符号整数，又因为delta =（Proc.A.stride – Proc.B.stride），则 |delta| <= 2^31 。
> 令 PASS_MAX 为小于 2^31 的无符号整数，假设 Proc.B.stride 加上了程序B的 pass，比较 (int)delta 与 0 的大小。
>如果 (int)delta > 0 ，则 Proc.B.stride 溢出，通过 Proc.A.stride – Proc.B.stride - 2^32 计算大小；
>若 (int)delta < 0 ，则 Proc.B.stride 未溢出。

## 小组练习与思考题

### (1)(spoc) 跟踪和展现ucore的处理机调度过程

在ucore执行处理机调度时，跟踪并显示上一个让出CPU线程的暂停代码位置和下一个进入执行状态线程的开始执行位置。
```
见代码
```
### (2)(spoc) 理解调度算法支撑框架的执行过程

即在ucore运行过程中通过`cprintf`函数来完整地展现出来多个进程在调度算法和框架的支撑下，在相关调度点如何动态调度和执行的细节。(越全面细致越好)
```
见代码
```
请完成如下练习，完成代码填写，并形成spoc练习报告
> 需写练习报告和简单编码，完成后放到git server 对应的git repo中

### 练习用的[lab6 spoc exercise project source code](https://github.com/chyyuu/ucore_lab/tree/master/labcodes_answer/lab6_result)


