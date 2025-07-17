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
        controls.RegDst=;
        controls.Jump=;
        controls.Branch=;
        controls.MemRead=;
        controls.MemtoReg=;
        controls.ALUOp=;
        controls.MemWrite=;
        controls.ALUSrc=;
        controls.RegWrite=; 
    }
    else
    {
        if(op==001000) // add immediate
        {
            controls.RegDst=0;
            controls.Jump=0;
            controls.Branch=0;
            controls.MemRead=0;
            controls.MemtoReg=0;
            controls.ALUOp=0;
            controls.MemWrite=0;
            controls.ALUSrc=1;
            controls.RegWrite=1; 
        }
        else
        {
            if(op==100011) // load word
            {
                controls.RegDst=0;
                controls.Jump=0;
                controls.Branch=0;
                controls.MemRead=1;
                controls.MemtoReg=1;
                controls.ALUOp=0;
                controls.MemWrite=0;
                controls.ALUSrc=1;
                controls.RegWrite=1; 
            }
            else
            {
                if(op==101011) // store word
                {
                    controls.RegDst=2;
                    controls.Jump=0;
                    controls.Branch=0;
                    controls.MemRead=0;
                    controls.MemtoReg=2;
                    controls.ALUOp=0;
                    controls.MemWrite=1;
                    controls.ALUSrc=1;
                    controls.RegWrite=0; 
                }
                else
                {
                    if(op==001111) // load upper immediate
                    {
                        controls.RegDst=0;
                        controls.Jump=0;
                        controls.Branch=0;
                        controls.MemRead=0;
                        controls.MemtoReg=0;
                        controls.ALUOp=3;
                        controls.MemWrite=0;
                        controls.ALUSrc=1;
                        controls.RegWrite=1; 
                    }
                    else
                    { 
                        if(op==000100) // branch on equal
                        {
                            controls.RegDst=2;
                            controls.Jump=0;
                            controls.Branch=1;
                            controls.MemRead=0;
                            controls.MemtoReg=2;
                            controls.ALUOp=1;
                            controls.MemWrite=0;
                            controls.ALUSrc=0;
                            controls.RegWrite=0; 
                        }
                        else
                        {
                            if(op==001010) // set less than immediate
                            {
                                controls.RegDst=0;
                                controls.Jump=0;
                                controls.Branch=0;
                                controls.MemRead=0;
                                controls.MemtoReg=0;
                                controls.ALUOp=2;
                                controls.MemWrite=0;
                                controls.ALUSrc=1;
                                controls.RegWrite=1; 
                            }
                            else
                            {
                                if(op==001011) // set less than unsigned immediate
                                {
                                    controls.RegDst=0;
                                    controls.Jump=0;
                                    controls.Branch=0;
                                    controls.MemRead=0;
                                    controls.MemtoReg=0;
                                    controls.ALUOp=2;
                                    controls.MemWrite=0;
                                    controls.ALUSrc=1;
                                    controls.RegWrite=1; 
                                }
                                else
                                {
                                    if(op==000010) // jump
                                    {
                                        controls.RegDst=2;
                                        controls.Jump=1;
                                        controls.Branch=0;
                                        controls.MemRead=0;
                                        controls.MemtoReg=2;
                                        controls.ALUOp=2;
                                        controls.MemWrite=0;
                                        controls.ALUSrc=2;
                                        controls.RegWrite=0; 
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
{

}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{

}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{

}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{

}

