#include "spimcore.h"


/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{
    switch(ALUControl) {
        case 0:
            *ALUresult = A+B;
            break;
        case 1:
            *ALUresult = A-B;
            break;
        case 2:
            if((int)A < (int)B) {*ALUresult = 1; break;}
            else {*ALUresult = 0; break;}
        case 3:
            if(A < B) {*ALUresult = 1; break;}
            else {*ALUresult = 0; break;}
        case 4:
            *ALUresult = A&B;
            break;
        case 5:
            *ALUresult = A|B;
            break;
        case 6:
            *ALUresult = B<<16;
            break;
        case 7:
            *ALUresult = ~A;
            break;
    }
    *Zero = (*ALUresult == 0) ? 1 : 0; // Zero flag
}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{
    if(PC % 4 != 0) {
        return 1; // Halts
    }
    
    *instruction = Mem[PC >> 2];

    return 0;
}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{

    // Parse instruction and split into fields

    op = 
    r1 = 
    r2 = 
    r3 =
    funct =
    offset =
    jsec =
}



/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{



    if(op==000000) // R-Type
    {
        controls->RegDst=1;
        controls->Jump=0;
        controls->Branch=0;
        controls->MemRead=0;
        controls->MemtoReg=0;
        controls->ALUOp=10;
        controls->MemWrite=0;
        controls->ALUSrc=0;
        controls->RegWrite=1; 
    }
    else
    {
        if(op==001000) // add immediate
        {
            controls->RegDst=0;
            controls->Jump=0;
            controls->Branch=0;
            controls->MemRead=0;
            controls->MemtoReg=0;
            controls->ALUOp=0;
            controls->MemWrite=0;
            controls->ALUSrc=1;
            controls->RegWrite=1; 
        }
        else
        {
            if(op==100011) // load word
            {
                controls->RegDst=0;
                controls->Jump=0;
                controls->Branch=0;
                controls->MemRead=1;
                controls->MemtoReg=1;
                controls->ALUOp=0;
                controls->MemWrite=0;
                controls->ALUSrc=1;
                controls->RegWrite=1; 
            }
            else
            {
                if(op==101011) // store word
                {
                    controls->RegDst=2;
                    controls->Jump=0;
                    controls->Branch=0;
                    controls->MemRead=0;
                    controls->MemtoReg=2;
                    controls->ALUOp=0;
                    controls->MemWrite=1;
                    controls->ALUSrc=1;
                    controls->RegWrite=0; 
                }
                else
                {
                    if(op==001111) // load upper immediate
                    {
                        controls->RegDst=0;
                        controls->Jump=0;
                        controls->Branch=0;
                        controls->MemRead=0;
                        controls->MemtoReg=0;
                        controls->ALUOp=3;
                        controls->MemWrite=0;
                        controls->ALUSrc=1;
                        controls->RegWrite=1; 
                    }
                    else
                    { 
                        if(op==000100) // branch on equal
                        {
                            controls->RegDst=2;
                            controls->Jump=0;
                            controls->Branch=1;
                            controls->MemRead=0;
                            controls->MemtoReg=2;
                            controls->ALUOp=1;
                            controls->MemWrite=0;
                            controls->ALUSrc=0;
                            controls->RegWrite=0; 
                        }
                        else
                        {
                            if(op==001010) // set less than immediate
                            {
                                controls->RegDst=0;
                                controls->Jump=0;
                                controls->Branch=0;
                                controls->MemRead=0;
                                controls->MemtoReg=0;
                                controls->ALUOp=2;
                                controls->MemWrite=0;
                                controls->ALUSrc=1;
                                controls->RegWrite=1; 
                            }
                            else
                            {
                                if(op==001011) // set less than unsigned immediate
                                {
                                    controls->RegDst=0;
                                    controls->Jump=0;
                                    controls->Branch=0;
                                    controls->MemRead=0;
                                    controls->MemtoReg=0;
                                    controls->ALUOp=2;
                                    controls->MemWrite=0;
                                    controls->ALUSrc=1;
                                    controls->RegWrite=1; 
                                }
                                else
                                {
                                    if(op==000010) // jump
                                    {
                                        controls->RegDst=2;
                                        controls->Jump=1;
                                        controls->Branch=0;
                                        controls->MemRead=0;
                                        controls->MemtoReg=2;
                                        controls->ALUOp=2;
                                        controls->MemWrite=0;
                                        controls->ALUSrc=2;
                                        controls->RegWrite=0; 
                                    }
                                    else
                                    {
                                        Halt = 1;
                                    }
                                }
                            }
                        }
                    }
                    
                }
                
            }
        }
    }
    
}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
    *data1 = Reg[r1];
    *data2 = Reg[r2];
}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{
extended_value=00000000000000000000000000000000; // create empty 32 bit integer
extended_value = extended_value + offset;
if (offset>=1000000000000000)   // check if positive or negative
{
    extended_value = extended_value + 11111111111111110000000000000000; // if negative, fill left half with 1s
}
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

