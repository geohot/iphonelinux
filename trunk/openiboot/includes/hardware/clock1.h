#ifndef HW_CLOCK1_H
#define HW_CLOCK1_H

#include "hardware/s5l8900.h"

// Constants
#define NUM_PLL 4
#define FREQUENCY_BASE 12000000
#define PLL0_INFREQ_DIV FREQUENCY_BASE /* 12 MHz */
#define PLL1_INFREQ_DIV FREQUENCY_BASE /* 12 MHz */
#define PLL2_INFREQ_DIV FREQUENCY_BASE /* 12 MHz */
#define PLL3_INFREQ_DIV 13500000 /* 13.5 MHz */
#define PLL0_INFREQ_MULT 0x8000
#define PLL1_INFREQ_MULT 0x8000
#define PLL2_INFREQ_MULT 0x8000
#define PLL3_INFREQ_MULT FREQUENCY_BASE

// Devices
#define CLOCK1 0x3C500000

// Registers
#define CLOCK1_CONFIG0 0x0
#define CLOCK1_CONFIG1 0x4
#define CLOCK1_CONFIG2 0x8
#define CLOCK1_PLL0CON 0x20
#define CLOCK1_PLL1CON 0x24
#define CLOCK1_PLL2CON 0x28
#define CLOCK1_PLL3CON 0x2C
#define CLOCK1_PLLMODE 0x44
#define CLOCK1_CL2_GATES 0x48
#define CLOCK1_CL3_GATES 0x4C

// Values
#define CLOCK1_Separator 0x20

#define CLOCK1_CLOCKPLL(x) GET_BITS((x), 12, 2)
#define CLOCK1_CLOCKDIVIDER(x) (GET_BITS((x), 0, 4) + 1)
#define CLOCK1_CLOCKHASDIVIDER(x) GET_BITS((x), 8, 1)

#define CLOCK1_MEMORYPLL(x) GET_BITS((x), 12, 2)
#define CLOCK1_MEMORYDIVIDER(x) (GET_BITS((x), 16, 4) + 1)
#define CLOCK1_MEMORYHASDIVIDER(x) GET_BITS((x), 24, 1)

#define CLOCK1_BUSPLL(x) GET_BITS((x), 12, 2)
#define CLOCK1_BUSDIVIDER(x) (GET_BITS((x), 16, 4) + 1)
#define CLOCK1_BUSHASDIVIDER(x) GET_BITS((x), 24, 1)

#define CLOCK1_UNKNOWNPLL(x) GET_BITS((x), 12, 2)
#define CLOCK1_UNKNOWNDIVIDER1(x) (GET_BITS((x), 0, 4) + 1)
#define CLOCK1_UNKNOWNDIVIDER2(x) (GET_BITS((x), 4, 4) + 1)
#define CLOCK1_UNKNOWNDIVIDER(x) (CLOCK1_UNKNOWNDIVIDER1(x) * CLOCK1_UNKNOWNDIVIDER2(x))
#define CLOCK1_UNKNOWNHASDIVIDER(x) GET_BITS((x), 8, 1)

#define CLOCK1_PERIPHERALDIVIDER(x) GET_BITS((x), 9, 3)

#define CLOCK1_UNKNOWN2PLL(x) GET_BITS((x), 28, 3)
#define CLOCK1_UNKNOWN2DIVIDER(x) GET_BITS((x), 16, 4)
#define CLOCK1_UNKNOWN2HASDIVIDER(x) GET_BITS((x), 24, 1)

#define CLOCK1_PLLMODE_ONOFF(x, y) (((x) >> (y)) & 0x1)
#define CLOCK1_PLLMODE_DIVIDERMODE(x, y) (((x) >> (y + 4)) & 0x1)
#define CLOCK1_PLLMODE_DIVIDE 0
#define CLOCK1_PLLMODE_MULTIPLY 1

#define CLOCK1_MDIV(x) (((x) >> 8) & 0x3FF)
#define CLOCK1_PDIV(x) (((x) >> 24) & 0x3F)
#define CLOCK1_SDIV(x) ((x) & 0x3)

#endif
