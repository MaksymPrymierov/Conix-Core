#ifndef IDT_H
#define IDT_H

struct idtEntry{
  unsigned short baseLow;
  unsigned short sel;
  unsigned char  always0;
  unsigned char  flags;
  unsigned short baseHigh;
} __attribute__ ((packed));

struct idtPtr{
  unsigned short limit;
  unsigned long   base;
} __attribute__ ((packed));

struct idtEntry idt[256];
struct idtPtr   idtp;

extern void idtLoad(unsigned long);

void idtSetGate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
void idtInstall();

#endif
