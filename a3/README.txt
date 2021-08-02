Assignment 3 for CS 570
Summer, 2021
Dong Lin
Cssc4206
Redid: 827228799

Description
This program implements a memory allocation and deallocation simulation in an operating system. The allocation strategies implemented are first fit and best fit, assuming the system has 256K memory divided in to 2K blocks. A process may request between 3 to 10 units of memory. There are three major components of the program, the memory components (first fit and best fit implemented through inheritance), the request generation component, and the statistics reporting components. The memory allocation components utilize a doubly linked list for allocation and deallocation using the allocate_mem, deallocate_mem functions. The reporting class reports the external fragmentation, average allocation tie, and the percentage of allocation fails. 

Requirements
This program compiles on Linux, and it is written in C++.

Lessons Learned
I learned a lot about memory allocation and deallocation using first fit and best fit algorithms. It is clear by using the best fit algorithm, there are a lot more traverses and despite its name, it is not more efficient than first fit. The average allocation time (number of traversals) of first fit vs best fit is around 7 to 10.
 
Compilation
Use the included Makefile. 
make clean
make

Files
main.c driver
membestfit.h	header for best fit
memmgr.h	header for first fit
reqgen.h	header for request generation
statrep.h	header for statistical reporting
dll.h		header for doubly linked list 
membestfit.cpp	implementation for best fit
memmgr.cpp	implementation for first fit
reqgen.cpp	implementation for request generation
statrep.cpp	implementation for statistical reporting
Makefile
README.txt

Configuration
See the Makefile

Testing
It has been tested on a home machine running windows 10 and edoras. 

Member
Dong Lin
cssc4206
redid: 827228799

Licensing
No license is required.


