#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

const int program[] = {
    PSH, 345,
    PSH, 989,
    ADD,
    POP,
    HLT
}; // simple program that runs on this VM

// global variables
int ip = 0; // instruction pointer
int sp = -99; // stack pointer
int stack[512]; // stack of size 512
bool running = true;

// fetches data or instrction in the program
int fetch(){
    return program[ip];
}

// instructions get evaluated here and execute command or do outputs
void evalIns(int instr){
    switch(instr){
        case HLT:{
            running = false;
            break;
        }
        case PSH:{
            sp++;
            stack[sp] = program[++ip]; // ++ip is assign to x (program[x]) then increment if ip = 98 after ++ip program[99]
            break;
        }
        case ADD: {
            int a = stack[sp--];
            int b = stack[sp--];
            int result=a+b;
            stack[++sp] = result;
            break;
        }
        case POP:{
            int poped_value = stack[sp--];
            printf("popped value %d\n",poped_value);
            break;
        }
    }
}

int main(){
    while(running){
        evalIns(fetch()); // PSH
        ip++; // incrementing PC
    }
    return 0;
}

