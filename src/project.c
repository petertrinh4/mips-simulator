#include "spimcore.h"


/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{ 

}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{

}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{

}



/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{

}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{

}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{

}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{   unsigned A = data1;
    unsigned B = (ALUSrc == 1) ? extended_value : data2;  // Choose input B based on ALUSrc
    unsigned ALUControl;

    // Set ALUControl based on ALUOp and funct (for R-type instructions)
    if (ALUOp == 0) {
        ALUControl = 0; // Addition (for instructions like lw, sw)
    }
    else if (ALUOp == 1) {
        ALUControl = 1; // Subtraction (for instructions like beq)
    }
    else if (ALUOp == 2) {
        ALUControl = 2; // Set Less Than (for slt, sltu)
    }
    else if (ALUOp == 3) {
        ALUControl = 6; // Shift Left by 16 (for lui)
    }
    else if (ALUOp == 4) {
        ALUControl = 4; // AND (for andi)
    }
    else if (ALUOp == 5) {
        ALUControl = 5; // OR (for ori)
    }
    else if (ALUOp == 6) {
        ALUControl = 7; // NOT A (for negation)
    }
    else if (ALUOp == 7) {
        // For R-type, we use funct field to set the ALU control
        switch (funct) {
            case 32: ALUControl = 0; break; // add
            case 34: ALUControl = 1; break; // sub
            case 36: ALUControl = 4; break; // and
            case 37: ALUControl = 5; break; // or
            case 42: ALUControl = 2; break; // slt
            case 43: ALUControl = 3; break; // sltu
            default: return 1;  // Invalid funct
        }
    } else {
        return 1;  // Invalid ALUOp
    }

    // Now call ALU function to perform the operation
    ALU(A, B, ALUControl, ALUresult, Zero);

    return 0;
}
    
}



/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{ 
        if (MemRead || MemWrite) {
        // Ensure address is word-aligned
        if (ALUresult % 4 != 0) {
            return 1; // Invalid memory access
        }

        unsigned mem_index = ALUresult >> 2;

        if (MemRead) {
            *memdata = Mem[mem_index]; // Load word
        }

        if (MemWrite) {
            Mem[mem_index] = data2; // Store word
        }
    }
    return 0;
}

}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{
  if (RegWrite == 1) {
        unsigned dest = (RegDst == 1) ? rd : rt;
        unsigned value = (MemtoReg == 1) ? memdata : ALUresult;
        Reg[dest] = value;

}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{

}

