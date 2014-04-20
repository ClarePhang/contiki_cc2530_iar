/**
 * \file
 *
 *   Definition of some debugging functions.
 *
 *   putstring() and puthex() are from msp430/watchdog.c
 *
 * \author
 *         George Oikonomou - <oikonomou@users.sourceforge.net>
 */

#include "8051def.h"
#include "debug.h"
#include <stdio.h>      // Ϊ���ض���putchar

static const char hexconv[] = "0123456789abcdef";
static const char binconv[] = "01";
/*---------------------------------------------------------------------------*/
void
putstring(char *s)
{
  while(*s) {
    putchr(*s++);
  }
}
/*---------------------------------------------------------------------------*/
void
puthex(uint8_t c)
{
  putchr(hexconv[c >> 4]);
  putchr(hexconv[c & 0x0f]);
}
/*---------------------------------------------------------------------------*/
void
putbin(uint8_t c)
{
  unsigned char i = 0x80;
  while(i) {
    putchr(binconv[(c & i) != 0]);
    i >>= 1;
  }
}
/*---------------------------------------------------------------------------*/
void
putdec(uint8_t c)
{
  uint8_t div;
  uint8_t hassent = 0;
  for(div = 100; div > 0; div /= 10) {
    uint8_t disp = c / div;
    c %= div;
    if((disp != 0) || (hassent) || (div == 1)) {
      hassent = 1;
      putchar('0' + disp);
    }
  }
}

// �ض���putchar�������������ʹ��printf
int 
putchar(int c){  
  if(c== '\n'){  
    putchr('\r');         // ����س�����֤
  }  
  putchr( (uint8_t) c);   
  return c;  
}
/*---------------------------------------------------------------------------*/


