## Instruction on Running 

- change parameter in `main.cpp` under `main()` section, `scheduling(int n, int sa, int q)`, in which `n` represents the number of processes, `sa` represents the scheduling algorithm to use. 1 signifies FIFO; 2 siginifies RR with quantum _q_, _`q`_ represents the quantum for RR scheduling. _q_ is present only if sa = 2  
- run the program: `cd scheduling` to src folder and run `g++ main.cpp scheduling.cpp` and `./a.out` to see output on console 