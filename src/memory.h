#ifndef MEMORY_H
#define MEMORY_H

#define MEM_SIZE 1024

int mem[MEM_SIZE];

int mem_read(int addr);
void mem_write(int addr, int value);

#endif
