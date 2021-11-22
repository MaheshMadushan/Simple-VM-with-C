#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

const int program[] = {
    PSH, 345,
    PSH, 989,
    MUL,
    POP,
    HLT
}; // simple program that runs on this VM

// creating registers array of size num of registers
static int registers[NUM_OF_REGISTERS];

// global variables
int ip = 0; // instruction pointer
int sp = 0; // stack pointer
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
            stack[sp] = program[++ip]; // ++ip is assign to x (program[x]) then increment if ip = 98 after ++ip program[99]
            sp++;
            break;
        }
        case IF: {
            int reg = program[++ip]; // reg
            int value = program[++ip]; // value to compare
            int newip =  program[++ip];
            if(registers[stack[--sp]] == value){
                ip = newip;
                // TODO : do jump true
            }
            break;
        }
        // adds top elements in stack
        case ADD: {
            registers[A] = stack[--sp];
            registers[B] = stack[--sp];
            registers[C] = registers[A] + registers[B];
            stack[++sp] = registers[C];
            break;
        }
        // mul top elenets in the stack
        case MUL:{
            registers[A] = stack[--sp];
            registers[B] = stack[--sp];
            registers[C] = registers[A] * registers[B];
            stack[++sp] = registers[C];
            break;
        }
         case DIV:{
            registers[A] = stack[--sp];
            registers[B] = stack[--sp];
            registers[C] = registers[A] / registers[B];
            stack[++sp] = registers[C];
            break;
        }
        case SUB:{
            registers[A] = stack[--sp];
            registers[B] = stack[--sp];
            registers[C] = registers[A] - registers[B];
            stack[++sp] = registers[C];
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
    // this executes fetch decode execute cycle
    while(running){
        evalIns(fetch()); // PSH
        ip++; // incrementing PC
    }
    return 0;
}

