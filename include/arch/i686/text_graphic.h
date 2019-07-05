#ifndef TEXT_GRAPHIC_H
#define TEXT_GRAPHIC_H

#include <kernel/types.h>

#define TEXT_GRAPHIC_MEMORY 	0xB8000
#define TEXT_GRAPHIC_HEIGHT 	25
#define TEXT_GRAPHIC_WIDTH 	80
#define TEXT_GRAPHIC_CAPACITY 	2000
#define TEXT_GRAPHIC_LAST_LINE 	1920
#define TEXT_GRAPHIC_COLOR    	0x0700

/* 
 *	int text_graphic_init(u16* video_buffer)
 *	Initializing text graphics for kernel output.
 *	The function takes a point on the video buffer array.
 */
extern int text_graphic_init(u16* video_buffer);

/*	
 *	int printk(const char* form, ...)
 *	Formatted output from the kernel.
 */
extern int printk(const char* form, ...);

#endif