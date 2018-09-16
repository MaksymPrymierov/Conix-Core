#include <stdint.h>
#include "../../headers/io/io.h"

void create_descriptor(uint32_t base, uint32_t limit, uint16_t flag){
    uint64_t descriptor;
 
    // Create the high 32 bit segment
    descriptor  =  limit       & 0x000F0000;         // set limit bits 19:16
    descriptor |= (flag <<  8) & 0x00F0FF00;         // set type, p, dpl, s, g, d/b, l and avl fields
    descriptor |= (base >> 16) & 0x000000FF;         // set base bits 23:16
    descriptor |=  base        & 0xFF000000;         // set base bits 31:24
 
    // Shift by 32 to allow for low part of segment
    descriptor <<= 32;
 
    // Create the low 32 bit segment
    descriptor |= base  << 16;                       // set base bits 15:0
    descriptor |= limit  & 0x0000FFFF;               // set limit bits 15:0

    printText("Create gdt type: ", 0x07);
    printNumber(flag, 0x07);
    printText("\n", 0x07);
    printNumber(descriptor, 0x07);
    printText("\n", 0x07);
}
