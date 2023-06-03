# Process Contention Scope (PCS) and System Contention Scope (SCS)

PCS and SCS are terms used in the context of thread synchronization in parallel computing systems. Let's understand each scope:

## Process Contention Scope
- It refers to the scope of thread synchronization within a single process.
- synchronization primitives (e.g., locks, mutexes) are used to coordinate access to shared resources among threads within the same process.
- Threads within the process contend for the synchronization objects, and only threads within the same process are affected.
- Its useful when you want to synchronize threads within a specific process without affecting threads in other processes.
- However, it doesn't provide synchronization across processes and is limited to coordinating threads within the same process.

## System Contention Scope
- It refers to the scope of thread synchronization across the entire system, involving multiple processes.
- synchronization primitives are used to coordinate access to shared resources across threads in different processes.
- Threads from multiple processes can contend for the synchronization objects, and the synchronization mechanism ensures correctness and fairness.
- Its useful when you need to coordinate access to shared resources that are accessed by threads from different processes.
- It allows for synchronization and coordination across processes, ensuring consistency in accessing shared resources.

In summary, Process Contention Scope (PCS) is concerned with synchronization within a single process, while System Contention Scope (SCS) deals with synchronization across multiple processes. The choice between PCS and SCS depends on the specific requirements of your parallel computing system and the nature of the shared resources being accessed.