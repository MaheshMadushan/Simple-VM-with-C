/***
 * A header file is a file with extension .h which contains C function
 * declarations and macro definitions to be shared between 
 * several source files. There are two types of header files: the files that the programmer writes 
 * and the files that comes with your compiler.
 * You request to use a header file in your program by 
 * including it with the C preprocessing directive #include, 
 * like you have seen inclusion of stdio.h header file, 
 * which comes along 
 * with your compiler.
 * Including a header file is equal to copying the content of the header file 
 * but we do not do it because it will be error-prone and it is not a good idea to copy the
 * content of a header file in the source files, especially if we have multiple source files in a program.
 * A simple practice in C or C++ programs is that we keep all the constants, macros, system 
 * wide global variables, and function prototypes in the header files 
 * and include that header file wherever it is required.
**/

// registers
typedef enum {
    A,B,C,D,E,F,
    NUM_OF_REGISTERS
} Registers;

// all instructions
typedef enum {
    HLT, // 0  -- hlt              :: halts program
    PSH, // 1  -- psh val          :: pushes <val> to stack
    POP, // 2  -- pop              :: pops value from stack
    ADD, // 3  -- add              :: adds top two vals on stack
    MUL, // 4  -- mul              :: multiplies top two vals on stack
    DIV, // 5  -- div              :: divides top two vals on stack
    SUB, // 6  -- sub              :: subtracts top two vals on stack
    SLT, // 7  -- slt reg_a, reg_b :: pushes (reg_a < reg_b) to stack
    MOV, // 8  -- mov reg_a, reg_b :: movs the value in reg_a to reg_b
    SET, // 9  -- set reg, val     :: sets the reg to value
    LOG, // 10 -- log a            :: prints out a
    IF,  // 11 -- if reg val ip    :: if the register == val branch to the ip
    IFN, // 12 -- ifn reg val ip   :: if the register != val branch to the ip
    GLD, // 13 -- gld reg          :: loads a register to the stack
    GPT, // 14 -- gpt reg          :: pushes top of stack to the given register
    NOP  // 15 -- nop              :: nothing
} InstructionSet;