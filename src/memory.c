#include <stdio.h>
#include "memory.h"

int mem_read(int addr) {
    if(addr < 0 || addr >= MEM_SIZE) {
        printf("Memory read error at %d\n", addr);
        return 0;
    }
    return mem[addr];
}

void mem_write(int addr, int value) {
    if(addr < 0 || addr >= MEM_SIZE) {
        printf("Memory write error at %d\n", addr);
        return;
    }
    mem[addr] = value;
}
