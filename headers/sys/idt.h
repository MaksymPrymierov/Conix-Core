#ifndef IDT_H
#define IDT_H

/*
 * Data structure for idt.
 */
struct idtEntry{
  unsigned short baseLow;
  unsigned short sel;
  unsigned char  always0;
  unsigned char  flags;
  unsigned short baseHigh;
} __attribute__ ((packed));

/* 
 * Pointer to the structure with data for idt.
 */
struct idtPtr{
  unsigned short limit;
  unsigned int   base;
} __attribute__ ((packed));

/*
 * Idt array.
 */
struct idtEntry idt[256];

/*
 * Pointer to an array with idt.
 */
struct idtPtr   idtp;

/*
 * This function load idt array.
 */
extern void idtLoad();

/*
 * This function creates a new descriptor in the idt array.
 */
void idtSetGate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);

/*
 * Installs and sets a pointer to an array with them.
 */
void idtInstall();

#endif
