/***************************************************************************
 * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *
 * is provided to you without charge, and with no warranty.  You may give  *
 * away copies of JOVE, including sources, provided that this notice is    *
 * included in all the files.                                              *
 ***************************************************************************/

#include "jove.h"
#include "ctype.h"

int	SyntaxTable = FUNDAMENTAL;	/* Current table to use. */

const unsigned char CharTable[NMAJORS][NCHARS] = {
    {
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_P,	_P,	_P,	_P,	_P,	_P,	_P,	_P,
	_Op|_P,	_Cl|_P,	_P,	_P,	_P,	_P,	_P,	_P,
	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,
	_W|_N,	_W|_N,	_P,	_P,	_P,	_P,	_P,	_P,
	_P,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,
	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,
	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,
	_W|_U,	_W|_U,	_W|_U,	_Op|_P,	_P,	_Cl|_P,	_P,	_P,
	_P,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,
	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,
	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,
	_W|_L,	_W|_L,	_W|_L,	_Op|_P,	_P,	_Cl|_P,	_P,	_C,
#ifdef IBMPC
	0, _W|_L, 0, 0, _W|_L, 0, 0, 0, 0, 0, 0, 0, 0, 0, _W|_U, 0,
	0, 0, 0, 0, _W|_L, 0, 0, 0, 0, _W|_U, _W|_U, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#endif /* IBMPC */
#ifdef MAC	/* See Inside Macintosh Vol One p. 247 */
	_W|_U, _W|_U, _W|_U, _W|_U, _W|_U, _W|_U, _W|_U, _W|_L,
	_W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L,
	_W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L,
	_W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L,
	_P, _P, _P, _P, _P, _P, _P, _P,
	_P, _P, _P, _P, _P, _P, _W|_U, _W|_U,
	_P, _P, _P, _P, _P, _W|_U, _W|_L, _W|_U,
	_W|_U, _W|_L, _P, _P, _P, _W|_U, _W|_L, _W|_L,
	_P, _P, _P, _P, _P, _P, _W|_U, _P,
	_P, _P, _P, _W|_U, _W|_U, _W|_U, _W|_U, _W|_U,
	_P, _P, _P, _P, _P, _P, _P, _P,
	_W|_U, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#endif /* MAC */
    },

    {
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_P,	_P,	_P,	_P,	_P,	_P,	_P,	_P|_W,
	_Op|_P,	_Cl|_P,	_P,	_P,	_P,	_P,	_P,	_P,
	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,
	_W|_N,	_W|_N,	_P,	_P,	_P,	_P,	_P,	_P,
	_P,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,
	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,
	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,
	_W|_U,	_W|_U,	_W|_U,	_Op|_P,	_P,	_Cl|_P,	_P,	_P,
	_P,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,
	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,
	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,
	_W|_L,	_W|_L,	_W|_L,	_Op|_P,	_P,	_Cl|_P,	_P,	_C,
#ifdef IBMPC
	0, _W|_L, 0, 0, _W|_L, 0, 0, 0, 0, 0, 0, 0, 0, 0, _W|_U, 0,
	0, 0, 0, 0, _W|_L, 0, 0, 0, 0, _W|_U, _W|_U, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#endif /* IBMPC */
#ifdef MAC	/* See Inside Macintosh Vol One p. 247 */
	_W|_U, _W|_U, _W|_U, _W|_U, _W|_U, _W|_U, _W|_U, _W|_L,
	_W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L,
	_W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L,
	_W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L, _W|_L,
	_P, _P, _P, _P, _P, _P, _P, _P,
	_P, _P, _P, _P, _P, _P, _W|_U, _W|_U,
	_P, _P, _P, _P, _P, _W|_U, _W|_L, _W|_U,
	_W|_U, _W|_L, _P, _P, _P, _W|_U, _W|_L, _W|_L,
	_P, _P, _P, _P, _P, _P, _W|_U, _P,
	_P, _P, _P, _W|_U, _W|_U, _W|_U, _W|_U, _W|_U,
	_P, _P, _P, _P, _P, _P, _P, _P,
	_W|_U, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
#endif /* MAC */
    },

    {
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_P,	_P,	_P,	_P,	_P|_W,	_P,	_P,	_P,
	_Op|_P,	_Cl|_P,	_P,	_P,	_P,	_P,	_P,	_P,
	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,
	_W|_N,	_W|_N,	_P,	_P,	_P,	_P,	_P,	_P,
	_P,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,
	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,
	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,
	_W|_U,	_W|_U,	_W|_U,	_Op|_P,	_P,	_Cl|_P,	_P,	_P|_W,
	_P,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,
	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,
	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,
	_W|_L,	_W|_L,	_W|_L,	_Op|_P,	_P,	_Cl|_P,	_P,	_C,
#ifndef ASCII
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#endif /* ASCII */
    },

#ifdef LISP
    {
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_C,	_C,	_C,	_C,	_C,	_C,	_C,	_C,
	_P,	_W|_P,	_P,	_P,	_W|_P,	_W|_P,	_W|_P,	_P,
	_Op|_P,	_Cl|_P,	_W|_P,	_W|_P,	_P,	_W|_P,	_P,	_W,
	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,	_W|_N,
	_W|_N,	_W|_N,	_W|_P,	_P,	_W|_P,	_W|_P,	_W|_P,	_W|_P,
	_W|_P,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,
	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,
	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,	_W|_U,
	_W|_U,	_W|_U,	_W|_U,	_Op|_P,	_P,	_Cl|_P,	_W|_P,	_W|_P,
	_P,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,
	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,
	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,	_W|_L,
	_W|_L,	_W|_L,	_W|_L,	_Op|_W|_P,	_W|_P,	_Cl|_W|_P,	_W|_P,	_W|_C,
#ifndef ASCII
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#endif /* ASCII */
    },
#endif	/* LISP */
};

int
ismword(c)
int	c;
{
	return ((CharTable[curbuf->b_major])[c]&(_W));
}

#ifdef IBMPC
const char	CaseEquiv[NCHARS] = {
	'\000',	'\001',	'\002',	'\003',	'\004',	'\005',	'\006',	'\007',
	'\010',	'\011',	'\012',	'\013',	'\014',	'\015',	'\016',	'\017',
	'\020',	'\021',	'\022',	'\023',	'\024',	'\025',	'\026',	'\027',
	'\030',	'\031',	'\032',	'\033',	'\034',	'\035',	'\036',	'\037',
	'\040',	'!',	'"',	'#',	'$',	'%',	'&',	'\'',
	'(',	')',	'*',	'+',	',',	'-',	'.',	'/',
	'0',	'1',	'2',	'3',	'4',	'5',	'6',	'7',
	'8',	'9',	':',	';',	'<',	'=',	'>',	'?',
	'@',	'A',	'B',	'C',	'D',	'E',	'F',	'G',
	'H',	'I',	'J',	'K',	'L',	'M',	'N',	'O',
	'P',	'Q',	'R',	'S',	'T',	'U',	'V',	'W',
	'X',	'Y',	'Z',	'[',	'\\',	']',	'^',	'_',
	'`',	'A',	'B',	'C',	'D',	'E',	'F',	'G',
	'H',	'I',	'J',	'K',	'L',	'M',	'N',	'O',
	'P',	'Q',	'R',	'S',	'T',	'U',	'V',	'W',
	'X',	'Y',	'Z',	'{',	'|',	'}',	'~',	'\177',
	128, 154, 130, 131, 142, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143,
	144, 145, 146, 147, 153, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159,
	160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175,
	176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191,
	192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207,
	208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223,
	224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
	240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255
};
#endif /* IBMPC */

#ifdef MAC
const char	CaseEquiv[NCHARS] = {
	'\000',	'\001',	'\002',	'\003',	'\004',	'\005',	'\006',	'\007',
	'\010',	'\011',	'\012',	'\013',	'\014',	'\015',	'\016',	'\017',
	'\020',	'\021',	'\022',	'\023',	'\024',	'\025',	'\026',	'\027',
	'\030',	'\031',	'\032',	'\033',	'\034',	'\035',	'\036',	'\037',
	'\040',	'!',	'"',	'#',	'$',	'%',	'&',	'\'',
	'(',	')',	'*',	'+',	',',	'-',	'.',	'/',
	'0',	'1',	'2',	'3',	'4',	'5',	'6',	'7',
	'8',	'9',	':',	';',	'<',	'=',	'>',	'?',
	'@',	'A',	'B',	'C',	'D',	'E',	'F',	'G',
	'H',	'I',	'J',	'K',	'L',	'M',	'N',	'O',
	'P',	'Q',	'R',	'S',	'T',	'U',	'V',	'W',
	'X',	'Y',	'Z',	'[',	'\\',	']',	'^',	'_',
	'`',	'A',	'B',	'C',	'D',	'E',	'F',	'G',
	'H',	'I',	'J',	'K',	'L',	'M',	'N',	'O',
	'P',	'Q',	'R',	'S',	'T',	'U',	'V',	'W',
	'X',	'Y',	'Z',	'{',	'|',	'}',	'~',	'\177',
	0x80,	0x81,	0x82,	0x83,	0x84,	0x85,	0x86,	0x87,
	0xCB,	0x89,	0x80,	0xCC,	0x81,	0x82,	0x83,	0x8F,
	0x90,	0x91,	0x92,	0x93,	0x94,	0x95,	0x84,	0x97,
	0x98,	0x99,	0x85,	0xCD,	0x9C,	0x9D,	0x9E,	0x86,
	0xA0,	0xA1,	0xA2,	0xA3,	0xA4,	0xA5,	0xA6,	0xA7,
	0xA8,	0xA9,	0xAA,	0xAB,	0xAC,	0xAD,	0xAE,	0xAF,
	0xB0,	0xB1,	0xB2,	0xB3,	0xB4,	0xB5,	0xC6,	0xB7,
	0xB8,	0xB8,	0xBA,	0xBB,	0xBC,	0xBD,	0xAE,	0xAF,
	0xC0,	0xC1,	0xC2,	0xC3,	0xC4,	0xC5,	0xC6,	0xC7,
	0xC8,	0xC9,	0xCA,	0xCB,	0xCC,	0xCD,	0xCE,	0xCE,
	0xD0,	0xD1,	0xD2,	0xD3,	0xD4,	0xD5,	0xD6,	0xD7,
	0xD8,	0,		0,		0,		0,		0,		0,		0,
	0,		0,		0,		0,		0,		0,		0,		0,
	0,		0,		0,		0,		0,		0,		0,		0,
	0,		0,		0,		0,		0,		0,		0,		0,
	0,		0,		0,		0,		0,		0,		0,		0
};
#endif /* MAC */

#ifdef ASCII
const char CaseEquiv[] = {
	'\000',	'\001',	'\002',	'\003',	'\004',	'\005',	'\006',	'\007',
	'\010',	'\011',	'\012',	'\013',	'\014',	'\015',	'\016',	'\017',
	'\020',	'\021',	'\022',	'\023',	'\024',	'\025',	'\026',	'\027',
	'\030',	'\031',	'\032',	'\033',	'\034',	'\035',	'\036',	'\037',
	'\040',	'!',	'"',	'#',	'$',	'%',	'&',	'\'',
	'(',	')',	'*',	'+',	',',	'-',	'.',	'/',
	'0',	'1',	'2',	'3',	'4',	'5',	'6',	'7',
	'8',	'9',	':',	';',	'<',	'=',	'>',	'?',
	'@',	'A',	'B',	'C',	'D',	'E',	'F',	'G',
	'H',	'I',	'J',	'K',	'L',	'M',	'N',	'O',
	'P',	'Q',	'R',	'S',	'T',	'U',	'V',	'W',
	'X',	'Y',	'Z',	'[',	'\\',	']',	'^',	'_',
	'`',	'A',	'B',	'C',	'D',	'E',	'F',	'G',
	'H',	'I',	'J',	'K',	'L',	'M',	'N',	'O',
	'P',	'Q',	'R',	'S',	'T',	'U',	'V',	'W',
	'X',	'Y',	'Z',	'{',	'|',	'}',	'~',	'\177'
};
#endif /* ASCII */
