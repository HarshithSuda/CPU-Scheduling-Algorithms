Operating Systems Algorithm Simulators in C

This repository contains C-based simulators for three fundamental components of operating systems: CPU Scheduling, Disk Scheduling, and Memory Management. These programs were developed to implement, visualize, and analyze the performance of various core algorithms that are crucial for OS efficiency and resource management.

🚀 Features

Triple Simulators: Includes separate implementations for CPU Scheduling, Disk Scheduling, and Page Replacement algorithms.

Wide Range of Algorithms: Covers a comprehensive suite of over a dozen classic OS algorithms.

Performance Analysis: Calculates and displays key performance metrics for each simulator (e.g., Turnaround Time, Total Head Movement, Page Faults).

Varied Input Handling:

The CPU Scheduler uses randomized inputs to simulate realistic workloads.

The Disk Scheduler and Memory Management simulators use hardcoded request queues for consistent testing and direct comparison between algorithms.

Efficient C Implementation: Utilizes fundamental C concepts like pointers, dynamic memory allocation, and data structures.

🧠 Part 1: CPU Scheduling Simulator

This simulator demonstrates strategies for managing process execution on the CPU to optimize utilization and minimize wait times.

Algorithms Implemented:

First-Come, First-Served (FCFS)

Shortest Job First (SJF)

Shortest Remaining Time First (SRTF)

Round Robin (RR)

Multilevel Feedback Queue: A complex scheduling algorithm that uses multiple queues with different priority levels and scheduling policies, allowing processes to move between queues.

Performance Metrics Calculated:

Completion Time (CT), Turnaround Time (TAT), Waiting Time (WT)

💿 Part 2: Disk Scheduling Simulator

This simulator demonstrates how to optimize the movement of a disk's read/write head to reduce seek time and improve I/O performance.

Algorithms Implemented:

First-Come, First-Served (FCFS)

Shortest Seek Time First (SSTF)

SCAN (Elevator Algorithm)

C-SCAN (Circular SCAN)

LOOK & C-LOOK

Performance Metric Calculated:

Total Head Movement

💾 Part 3: Memory Management (Page Replacement) Simulator

This simulator demonstrates virtual memory management techniques by implementing page replacement algorithms. The goal is to minimize the number of page faults when a process requests a page that is not in memory.

Algorithms Implemented:

First-In, First-Out (FIFO): Replaces the oldest page in memory.

Least Recently Used (LRU): Replaces the page that has not been used for the longest period.

Optimal (OPT): Replaces the page that will not be used for the longest period in the future (serves as a theoretical benchmark).

Performance Metric Calculated:

Total Page Faults

🛠️ How to Use

Prerequisites

You need a C compiler, such as GCC, installed on your system.

Compilation and Execution

Clone the repository.

Navigate to the project directory in your terminal.

Compile the desired C file:

gcc SRTF.c -o srtf_scheduler

gcc Disk_Scheduling.c -o disk_scheduler

gcc LRU_Memory.c -o lru_memory

Run the executable:

./srtf_scheduler

./disk_scheduler

./lru_memory
`
