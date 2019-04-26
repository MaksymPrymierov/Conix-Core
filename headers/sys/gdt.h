#ifndef GDT_H
#define GDT_H

/*
 * Data structure for gdt.
 */
struct gdtEntry {
        unsigned short limitLow;
        unsigned short baseLow;
        unsigned char  baseMiddle;
        unsigned char  access;
        unsigned char  granularity;
        unsigned char  baseHigh;
} __attribute__ ((packed));

/*
 * Pointer to the structure with data for gdt.
 */
struct gdtPtr
{
        unsigned short limit;
        unsigned int   base;
} __attribute__ ((packed));

/*
 * Gdt array.
 */
struct gdtEntry gdt[5];

/*
 * Pointer to an array with gdt.
 */
struct gdtPtr   gp;

/*
 * This function removes and installs new gdt.
 */
extern void gdtFlush();

/*
 * This function creates a new descriptor in the gdt array.
 */
void createDescriptor(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);

/*
 * Initializes all descriptors and sets a pointer to an array with them.
 */
void gdtInit();

#endif
