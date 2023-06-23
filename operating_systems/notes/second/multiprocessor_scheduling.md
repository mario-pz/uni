# Multiprocessor Scheduling

Multiprocessor scheduling refers to the allocation of tasks or processes to multiple processors in a multiprocessor system. The goal is to efficiently utilize the available processors and optimize overall system performance. There are several scheduling methods used in multiprocessor systems, including time sharing, gang sharing, and space sharing. Let's explore each method in detail.

## Time Sharing

Time sharing, also known as time slicing or round-robin scheduling, is a multiprocessor scheduling method where each processor is assigned a fixed time slice or quantum. The processors take turns executing tasks or processes for their allocated time slice before switching to the next task. This method ensures fairness and prevents any one task from monopolizing the processors.

### Disadvantage

The disadvantage of time sharing is that it can lead to reduced overall system performance due to the overhead of context switching between tasks.

### Exercise: Time Sharing Scheduling

Consider a multiprocessor system with three processors (P1, P2, and P3) and four tasks (T1, T2, T3, and T4). The time slice for each processor is 20 ms. The execution times for each task are as follows:

- T1: 30 ms
- T2: 40 ms
- T3: 50 ms
- T4: 20 ms

To schedule the tasks using time sharing, follow these steps:

1. Assign the tasks to the processors in a round-robin fashion, ensuring each processor receives an equal number of tasks.
   - P1: T1
   - P2: T2
   - P3: T3

2. Execute each task for the allocated time slice (20 ms) on the corresponding processor.


```
   | Time (ms) | P1     | P2     | P3     |
   | --------- | ------ | ------ | ------ |
   | 0         | T1(20) | T2(20) | T3(20) |
   | 20        | T1(10) | T2(20) | T3(30) |
   | 40        | T2(10) | T3(20) | T1(0)  |
   | 60        | T2(0)  | T3(10) | T1(0)  |
   | 70        | T3(0)  | T2(0)  | T1(0)  |
```


3. After completing the first set of tasks, if there are any remaining tasks, continue the round-robin execution.

```

   | Time (ms) | P1     | P2     | P3     |
   | --------- | ------ | ------ | ------ |
   | 70        | T3(10) | T2(10) | T4(20) |
   | 90        | T3(0)  | T2(0)  | T4(20) |
   | 110       | T4(0)  | T3(0)  | T2(0)  |

```

4. Repeat step 3 until all tasks are completed.


```
   | Time (ms) | P1     | P2     | P3     |
   | --------- | ------ | ------ | ------ |
   | 110       | T4(10) |        |        |
   | 130       | T4(0)  |        |        |
```


5. The scheduling is complete when all tasks have been executed.
## Space Sharing
*(Used when processes depend on each other)*

Space sharing, also known as load sharing or load balancing, is a multiprocessor scheduling method where tasks or processes are dynamically assigned to available processors based on the current workload. The goal is to distribute the workload evenly among the processors to maximize resource utilization and system performance.

### Disadvantage 
If a process ends early it will not be released till the whole group is done

### Exercise: Space Sharing Scheduling

Consider a multiprocessor system with three processors (P1, P2, and P3) and five tasks (T1, T2, T3, T4, and T5). Each task's execution time is as follows:

- T1: 40 ms
- T2: 20 ms
- T3: 30 ms
- T4: 25 ms
- T5: 35 ms

To schedule the tasks using space sharing, follow these steps:

1. Initially, all processors are available. Assign the first task to the least loaded processor.

```
   | Time (ms) | P1     | P2     | P3     |
   | --------- | ------ | ------ | ------ |
   | 0         | T1(40) |        |        |

```

2. Calculate the current load on each processor based on the assigned tasks' remaining execution times.
 
```
  | Processor | Current Load |
   | --------- | ------------ |
   | P1        | 40 ms        |
   | P2        | 0 ms         |
   | P3        | 0 ms         |
```

3. Assign the next task to the least loaded processor.

```
   | Time (ms) | P1     | P2     | P3     |
   | --------- | ------ | ------ | ------ |
   | 0         | T1(40) | T2(20) |        |
```

4. Update the load on each processor.

```
   | Processor | Current Load |
   | --------- | ------------ |
   | P1        | 40 ms        |
   | P2        | 20 ms        |
   | P3        | 0 ms         |

```

5. Continue assigning tasks to the least loaded processor until all tasks are assigned and executed.

```
   | Time (ms) | P1     | P2     | P3     |
   | --------- | ------ | ------ | ------ |
   | 0         | T1(40) | T2(20) | T3(30) |
   | 20        | T1(20) | T2(0)  | T3(10) |
   | 30        | T1(10) | T4(25) | T3(0)  |
   | 35        | T1(5)  | T4(20) |        |
   | 40        | T1(0)  | T4(15) |        |
   | 55        |        | T4(0)  |        |
   | 70        |        | T5(35) |        |
   | 105       |        |        |        |

```

6. The scheduling is complete when all tasks have been executed.

## Gang Sharing

![](https://m.media-amazon.com/images/M/MV5BMThlOWE3MWEtZjM4Ny00M2FiLTkyMmYtZGY3ZTcyMzM5YmNlXkEyXkFqcGdeQWpnYW1i._V1_.jpg)

Gang sharing, also known as fixed assignment scheduling, involves dedicating a group of processors to execute a specific set of tasks together as a gang. In this method, the processors allocated to a gang work cooperatively to execute the gang's tasks. This approach is suitable for tasks that require inter-process communication or synchronization.

### Exercise: Gang Sharing Scheduling

Consider a multiprocessor system with four processors (P1, P2, P3, and P4) and two gangs of tasks (Gang A and Gang B). Gang A consists of three tasks (T1, T2, and T3), and Gang B consists of two tasks (T4 and T5). Each task's execution time is as follows:

- T1: 30 ms
- T2: 20 ms
- T3: 40 ms
- T4: 25 ms
- T5: 15 ms

To schedule the gangs using gang sharing, follow these steps:

1. Assign a fixed set of processors to each gang. For this example, let Gang A use P1 and P2, and Gang B use P3 and P4.

2. Execute the tasks within each gang concurrently on their assigned processors.


```
   | Time (ms) | P1     | P2     | P3     | P4     |
   | --------- | ------ | ------ | ------ | ------ |
   | 0         | T1(30) | T2(20) | T4(25) | T5(15) |
   | 15        | T1(15) | T2(5)  | T4(10) | T5(0)  |
   | 25        | T1(5)  | T2(0)  | T4(0)  |        |
   | 30        | T1(0)  |        |        |        |
   | 40        |        |        |        |        |

```

3. After completing the tasks for one gang, move on to the next gang.


```
   | Time (ms) | P1     | P2     | P3     | P4     |
   | --------- | ------ | ------ | ------ | ------ |
   | 40        | T3(40) |        |        |        |
   | 55        | T3(25) |        |        |        |
   | 65        | T3(15) |        |        |        |
   | 80        | T3(0)  |        |        |        |
```


4. The scheduling is complete when all gangs and their tasks have been executed.

# References


* ![](https://youtu.be/rUFHVVaVt7g)
* ![](https://youtu.be/L56xPaMxYHs)