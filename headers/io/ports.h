#ifndef PORTS_H
#define PORTS_H

/*
 * The function inb() reads data from the port specified
 * by the argument (unsigned short port).
 */
extern unsigned char inb(unsigned short port);

/*
 * The function outb() sends data to the specified port.
 */
extern void outb(unsigned short port, unsigned char data);

#endif
