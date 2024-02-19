/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  bits.h                                                 */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: February 14, 2024 [06:03 pm]             */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#ifndef _BITS
# define _BITS

// RAW BITS MANIPULATIONS
// ///////////////////////////

#define setBits(value, bits)\
	(value |= bits)

#define delBits(value, bits)\
	(value &= ~(bits))

#define toggleBits(value, bits)\
	(value ^= bits)

#define hasBit(value, bit)\
	(value & (bit))

#define resetBits(value)\
	value = 0


// T_DEV MANIPULATIONS
// ///////////////////////////

#define major(id)\
	  ((id & 0x00000000000fff00u) >>  8)\
	| ((id & 0xfffff00000000000u) >> 32)

#define minor(id)\
	  ((id & 0x00000000000000ffu) >>  0)\
	| ((id & 0x00000ffffff00000u) >> 12)

#endif /* _BITS */
