# Process Management Simulator

A C-based process scheduling simulator that implements fundamental operating system concepts, specifically process management using a ready queue data structure.

## Overview

This project provides a simulation framework for process scheduling algorithms. It implements a FIFO (First-In-First-Out) ready queue using a linked-list data structure to manage processes in a simulated operating system environment.

## Project Structure

```
process-management-sim/
├── process.h           # Process structure definition and interface
├── process.c           # Process initialization implementation
├── ready-queue.h       # Queue data structure and operations interface
├── ready-queue.c       # Queue implementation (linked-list based)
└── main.c              # Main program demonstrating queue operations
```

## Components

### Process Management (`process.h`, `process.c`)
Defines the fundamental process structure with attributes for process identification and management.

**Structure:**
- `process` - Contains process metadata (currently PID only)

**Functions:**
- `init_process()` - Initialize a process with a given process ID

### Ready Queue (`ready-queue.h`, `ready-queue.c`)
Implements a FIFO queue using a singly-linked list to manage processes waiting for CPU time.

**Data Structures:**
- `node` - Linked list node containing process data
- `queue` - Queue structure with head and tail pointers

**Operations:**
- `init_queue()` - Initialize an empty queue
- `enqueue()` - Add a process to the end of the queue
- `dequeue()` - Remove a process from the front of the queue
- `display_queue()` - Print all processes currently in the queue
- `free_queue()` - Deallocate all queue memory

## Building the Project

### Current Method

The project currently includes `.c` files directly in `main.c`. To build:

```bash
gcc main.c -o process-sim
./process-sim
```

### Recommended Method (Separate Compilation)

For better maintainability and build performance:

```bash
gcc process.c ready-queue.c main.c -o process-sim
```

Or compile separately and link:

```bash
gcc -c process.c -o process.o
gcc -c ready-queue.c -o ready-queue.o
gcc -c main.c -o main.o
gcc process.o ready-queue.o main.o -o process-sim
```

### Using Make (Recommended)

A Makefile can be added for automated builds:

```bash
make        # Build the project
make clean  # Remove build artifacts
```

## Current Functionality

The simulator currently demonstrates basic queue operations:

1. Creates a ready queue
2. Initializes multiple processes with unique PIDs
3. Enqueues processes into the ready queue
4. Displays the queue contents
5. Properly frees allocated memory

**Example Output:**
```
P12 P18 P34
```

## Implementation Details

### Queue Behavior
- **Empty Queue:** Both head and tail pointers are NULL
- **Single Element:** Head and tail point to the same node
- **Enqueue:** Adds to the tail, returns -1 for first element, 0 otherwise
- **Dequeue:** Removes from the head, returns -1 if empty, 0 on success
- **Order:** FIFO (First-In-First-Out)

### Memory Management
All dynamically allocated memory is properly freed using `free_queue()` before program termination.

## Development Status

This project is in early development. Current focus areas:

- Basic queue operations (implemented)
- Process structure foundation (implemented)
- Future enhancements will include:
  - Additional process attributes (arrival time, burst time, priority)
  - Scheduling algorithm implementations
  - Performance metrics and statistics
  - Multiple queue support for multi-level feedback queues

## Technical Requirements

- C compiler (GCC recommended)
- Standard C library
- POSIX-compliant system (for `unistd.h`)

## Known Issues

- `init_process()` in `process.c` missing explicit return value
- `main.c` includes `.c` files directly instead of using proper header-only includes

## License

This project is provided as-is for educational purposes.
