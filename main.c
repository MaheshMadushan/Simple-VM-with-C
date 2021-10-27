#include <stdio.h>
#include <string.h>
#include <header.h>
#include <stdbool.h>

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};

int ip = 0; // instruction pointer
int sp = -99; // stack pointer
int stack[512];
bool running = true;

int main(){
    while(running){
        eval(fetch()); // PSH
        ip++; // incrementing PC
    }
    return 0;
}

int fetch(){
    return program[ip];
}

void eval(int instr){
    switch(instr){
        case HLT:{
            running = false;
            break;
        }
        case PSH:{
            sp++;
            stack[sp] = program[++ip]; // ++ip is assign to x (program[x]) then increment if ip = 98 after ++ip program[99]
        }
        case ADD: {
            int a = stack[sp--];
            int b = stack[sp--];
            int result=a+b;
            stack[sp++] = result;
            break;
        }
        case POP:{
            int poped_value = stack[sp--];
            printf("popped value %d\n",poped_value);
            break;
        }
    }
}