Operating Systems Kernel Algorithm Simulator

<p align="center">
<img src="https://www.google.com/search?q=https://img.shields.io/badge/Language-C-blue.svg" alt="Language C">
<img src="https://www.google.com/search?q=https://img.shields.io/badge/Platform-OS%2520Independent-green.svg" alt="Platform OS Independent">
<img src="https://www.google.com/search?q=https://img.shields.io/badge/Status-Complete-brightgreen.svg" alt="Status Complete">
</p>

A comprehensive, C-based collection of simulators designed to implement, analyze, and visualize the core logic of fundamental Operating Systems algorithms. This project explores the trade-offs and performance of various strategies across three critical domains of OS management.

🚀 Core Simulation Modules

This project is divided into three distinct modules, each focusing on a key area of Operating Systems theory.

🧠 1. CPU Scheduling

Analyzes how processes are assigned to the CPU. The goal is to maximize throughput and minimize response time. The simulator uses randomized inputs to model realistic, dynamic workloads.

Algorithm Implemented

Type

Description

First-Come, First-Served

Non-Preemptive

Executes processes in strict arrival order.

Shortest Job First

Non-Preemptive

Prioritizes the process with the smallest execution time.

Shortest Remaining Time First

Preemptive

A preemptive version of SJF; switches to a new process if it has less remaining time.

Round Robin

Preemptive

Assigns a fixed time-slice (quantum) to each process in a circular queue.

Multilevel Feedback Queue

Preemptive

A complex algorithm using multiple queues with varying priorities and time slices.

Key Metric: Average Turnaround Time & Average Waiting Time

💾 2. Memory Management (Page Replacement)

Simulates virtual memory by modeling how the OS swaps pages between RAM and disk. The goal is to minimize page faults.

Algorithm Implemented

Description

First-In, First-Out (FIFO)

Replaces the oldest page that was brought into memory.

Least Recently Used (LRU)

Replaces the page that has gone the longest without being referenced.

Optimal (OPT)

Replaces the page that will not be used for the longest time in the future (theoretical benchmark).

Key Metric: Total Page Faults

💿 3. Disk Scheduling

Models how the disk's read/write head moves to fulfill I/O requests. The primary goal is to minimize the total seek time.

Algorithm Implemented

Description

First-Come, First-Served

Services requests in the order they are received.

Shortest Seek Time First

Services the request closest to the current head position.

SCAN (Elevator)

Moves in one direction servicing all requests, then reverses.

C-SCAN (Circular SCAN)

Like SCAN, but jumps back to the beginning after reaching the end.

LOOK & C-LOOK

Optimizations of SCAN/C-SCAN that only travel to the last request in a direction.

Key Metric: Total Head Movement

🛠️ How to Compile and Run

Prerequisites

A C compiler (like GCC) must be installed.

git for cloning the repository.

Steps

Clone the repository:

git clone [https://github.com/HarshithSuda/CPU-Scheduling-Algorithms.git](https://github.com/HarshithSuda/CPU-Scheduling-Algorithms.git)
cd CPU-Scheduling-Algorithms


Compile the desired simulator:
Each module is in its own file. Compile the one you wish to run.

# Example for the Disk Scheduling module
gcc Disk_Scheduling.c -o disk_sim

# Example for a CPU Scheduling algorithm
gcc Round_Robin.c -o rr_sim


Run the executable:

./disk_sim


The program will output the performance metrics directly to the console.
`
