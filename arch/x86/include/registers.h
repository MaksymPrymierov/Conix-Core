#pragma once

/* 
	Registers of the CRT Microcontroller
*/
#define CRT_INDEX_REGISTER 				0x3D4	// CRT index register
#define CRT_DATA_REGISTER				0x3D5	// CRT data register
#define CRT_HORIZONTAL_TOTAL 			0x00	// Horizontal Total Register
#define CRT_END_HORIZONTAL_DISPLAY		0x01	// End Horizontal Blanking Register
#define CRT_START_HORIZONTAL_BLANKING	0x02	// Start Horizontal Blanking Register
#define CRT_END_HORIZONTAL_BLANKING		0x03	// End Horizontal Blanking Register
#define CRT_START_HORIZONTAL_RETRACE	0x04	// Start Horizontal Retrace Register
#define CRT_END_HORIZONTAL_RETRACE		0x05	// End Horizontal Retrace Register
#define CRT_VERTICAL_TOTAL				0x06	// Vertical Total Register
#define CRT_OVERFLOW					0x07	// Overflow Register
#define CRT_PRESET_ROW_SCAN				0x08	// Preset Row Scan Register
#define CRT_MAXIMUM_SCAN_LINE			0x09	// Maximum Scan Line Register
#define CRT_CURSOR_START				0x0A	// Cursor Start Register
#define CRT_CURSOR_END					0x0B	// Cursor End Register
#define CRT_START_ADDRESS_HIGH			0x0C	// Start Address High Register
#define CRT_START_ADDRESS_LOW			0x0D	// Start Address Low Register
#define	CRT_CURSOR_LOCATION_HIGH		0x0E	// Cursor Location High Register
#define CRT_CURSOR_LOCATION_LOW			0x0F	// Cursor Location Low Register
#define CRT_VERTICAL_RETRACE_START		0x10    // Vertical Retrace Start Register
#define CRT_VERTICAL_RETRACE_END		0x11	// Vertical Retrace End Register
#define CRT_VERTICAL_DISPLAY_ENABLE_END	0x12	// Vertical Display Enable End Register
#define CRT_OFFSET						0x13	// Offset Register
#define CRT_UNDERLINE_LOCATION			0x14	// Underline Location Register
#define CRT_START_VERTICAL_BLANKING		0x15	// Start Vertical Blanking Register
#define CRT_END_VERTICAL_BLANKING		0x16	// End Vertical Blanking Register
#define CRT_MODE_CONTROL				0x17	// CRT Mode Control Register
#define CRT_LINE_COMPARE				0x18	// Line Compare Register