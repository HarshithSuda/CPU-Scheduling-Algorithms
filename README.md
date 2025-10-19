Here’s a **clean, professional, and visually appealing version** of your README file — formatted with **emojis, badges, sections, code styling, and clear typography** to make it look like a top GitHub project 👇

---

# 🧩 Operating Systems Kernel Algorithm Simulator


A **comprehensive C-based simulator suite** that implements, analyzes, and visualizes core **Operating System algorithms**.
It provides an experimental playground to explore **performance trade-offs** across the three pillars of OS management — **CPU Scheduling, Memory Management, and Disk Scheduling**.

---

## 🚀 Core Simulation Modules

This project is divided into three self-contained modules, each representing a key domain of OS design.

---

### 🧠 1. CPU Scheduling

Simulates how processes are assigned to the CPU, optimizing **throughput**, **waiting time**, and **response time**.
It uses randomized process data to model **dynamic workloads**.

#### ⚙️ Algorithms Implemented

| Algorithm                                | Type           | Description                                                            |
| ---------------------------------------- | -------------- | ---------------------------------------------------------------------- |
| **First-Come, First-Served (FCFS)**      | Non-Preemptive | Executes processes strictly in order of arrival.                       |
| **Shortest Job First (SJF)**             | Non-Preemptive | Chooses the process with the smallest burst time.                      |
| **Shortest Remaining Time First (SRTF)** | Preemptive     | Preemptive SJF — switches if a new process has shorter remaining time. |
| **Round Robin (RR)**                     | Preemptive     | Uses a fixed time quantum for each process in a cyclic queue.          |
| **Multilevel Feedback Queue (MLFQ)**     | Preemptive     | Uses multiple queues with dynamic priorities and variable time slices. |

📊 **Key Metric:** Average Turnaround Time & Average Waiting Time

---

### 💾 2. Memory Management (Page Replacement)

Models **virtual memory paging**, simulating how pages are replaced in physical RAM to minimize **page faults**.

#### ⚙️ Algorithms Implemented

| Algorithm                      | Description                                                                    |
| ------------------------------ | ------------------------------------------------------------------------------ |
| **First-In, First-Out (FIFO)** | Replaces the oldest loaded page.                                               |
| **Least Recently Used (LRU)**  | Replaces the page least recently referenced.                                   |
| **Optimal (OPT)**              | Theoretical best — replaces the page not used for the longest future duration. |

📊 **Key Metric:** Total Page Faults

---

### 💿 3. Disk Scheduling

Simulates disk head movement for various I/O request scheduling algorithms to minimize **seek time** and **head movement**.

#### ⚙️ Algorithms Implemented

| Algorithm                           | Description                                                   |
| ----------------------------------- | ------------------------------------------------------------- |
| **First-Come, First-Served (FCFS)** | Processes requests in the order they arrive.                  |
| **Shortest Seek Time First (SSTF)** | Serves the nearest request to the current head.               |
| **SCAN (Elevator Algorithm)**       | Moves in one direction servicing all requests, then reverses. |
| **C-SCAN (Circular SCAN)**          | Like SCAN, but jumps to the start after reaching the end.     |
| **LOOK & C-LOOK**                   | Optimized versions that travel only as far as needed.         |

📊 **Key Metric:** Total Head Movement

---

## 🛠️ How to Compile and Run

### ✅ Prerequisites

* A **C compiler** (e.g., `gcc`)
* **git** for cloning the repository

### 📥 Clone the Repository

```bash
git clone https://github.com/HarshithSuda/CPU-Scheduling-Algorithms.git
cd CPU-Scheduling-Algorithms
```

### ⚙️ Compile the Desired Module

Each module is implemented in a separate C file.
You can compile and run any simulator independently:

```bash
# Example: Disk Scheduling
gcc Disk_Scheduling.c -o disk_sim

# Example: Round Robin CPU Scheduling
gcc Round_Robin.c -o rr_sim
```

### ▶️ Run the Executable

```bash
./disk_sim
```

The program outputs performance metrics (like average waiting time or total head movement) directly to the terminal.

---

## 📈 Example Output

```
--- Disk Scheduling Simulation ---
Order of Access: 98 → 183 → 37 → 122 → 14 → 124
Total Head Movement: 208 Cylinders
```

---

## 📚 Learning Objectives

* Understand the **core mechanisms** behind OS resource management.
* Compare algorithmic **performance metrics** through direct simulation.
* Gain **hands-on experience** with CPU scheduling, memory paging, and disk optimization logic.

---

## 💡 Future Enhancements

* 🔍 Add **visual graphs** for CPU Gantt charts.
* 🧩 Integrate **interactive CLI menus**.
* 🧠 Extend with **process synchronization** (Semaphores, Deadlocks).

---

## 👨‍💻 Author

**Harshith Suda**
🎓 B.Tech, NIT Andhra Pradesh
💼 Passionate about Operating Systems, Algorithms, and System Design

🔗 [GitHub Profile](https://github.com/HarshithSuda)

---

Would you like me to make it **GitHub-Markdown optimized with collapsible sections** (like `<details>` tags for algorithms and run instructions) for a cleaner professional appearance?
