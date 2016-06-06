//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : com.c
//* Object              :
//* Creation            : HIi   03/27/2003
//*
//*----------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include "com.h"

extern int AT91F_Putc(int ch);
extern int AT91F_Getc(void) ;

static char erase_seq[] = "\b \b";		/* erase sequence	*/
static char   tab_seq[] = "        ";	/* used to expand TABs	*/

FILE __stdout;
FILE __stdin;


/* Our implementation of fputc */
int fputc(int ch, FILE *f)
{
    return(AT91F_Putc(ch));
}


/* Our implementation of fgetc */
int fgetc(FILE *f)
{
	return (AT91F_Getc());
}


//*-----------------------------------------------------------------------------
//* Function Name       : AT91F_ClrScr()
//* Object              : Send a clear screen on the USART
//* Input Parameters    :
//* Return value		:
//*-----------------------------------------------------------------------------
void AT91F_ClrScr(void)
{
	printf(CLRSCREEN);
}


//*-----------------------------------------------------------------------------
//* Function Name       : AT91F_DeleteChar()
//* Object              :
//* Input Parameters    :
//* Return value		:
//*-----------------------------------------------------------------------------
char *AT91F_DeleteChar(char *buffer, char *p, int *colp, int *np, int plen)
{
	char *s;

	if (*np == 0) {
		return (p);
	}

	if (*(--p) == '\t') {			/* will retype the whole line	*/
		while (*colp > plen) {
			printf(erase_seq);
			(*colp)--;
		}
		for (s=buffer; s<p; ++s) {
			if (*s == '\t') {
				printf(tab_seq+((*colp) & 07));
				*colp += 8 - ((*colp) & 07);
			} else {
				++(*colp);
				fputc (*s, &__stdout);
			}
		}
	} else {
		printf(erase_seq);
		(*colp)--;
	}
	(*np)--;
	return (p);
}



//*-----------------------------------------------------------------------------
//* Function Name       : AT91F_ReadLine()
//* Object              :
//* Input Parameters    :
//* Return value		:
//*-----------------------------------------------------------------------------
int AT91F_ReadLine (const char *const prompt, char *console_buffer)
{
	char *p = console_buffer;
	int	n = 0;					/* buffer index		*/
	int	plen = strlen (prompt);	/* prompt length	*/
	int	col;					/* output column cnt	*/
	char	c;

	/* print prompt */
	if (prompt)
		printf(prompt);
	col = plen;

	for (;;) {
		c = fgetc(&__stdin);

		switch (c) {
			case '\r':				/* Enter		*/
			case '\n':
				*p = '\0';
				printf ("\r\n");
				return (p - console_buffer);

			case 0x03:				/* ^C - break	*/
				console_buffer[0] = '\0';	/* discard input */
				return (-1);

			case 0x15:				/* ^U - erase line	*/
				while (col > plen) {
					printf(erase_seq);
					--col;
				}
				p = console_buffer;
				n = 0;
				continue;

			case 0x17:				/* ^W - erase word 	*/
				p = (char *)AT91F_DeleteChar(console_buffer, p, &col, &n, plen);
				while ((n > 0) && (*p != ' ')) {
					p=(char *)AT91F_DeleteChar(console_buffer, p, &col, &n, plen);
				}
				continue;

			case 0x08:				/* ^H  - backspace	*/
			case 0x7F:				/* DEL - backspace	*/
				p=(char *)AT91F_DeleteChar(console_buffer, p, &col, &n, plen);
			continue;

			default:
			/*
			 * Must be a normal character then
			 */
			if (n < (AT91C_CB_SIZE -2))
			{
				++col;		/* echo input		*/
				fputc(c, &__stdout);
				*p++ = c;
				++n;
			}
			else
			{			/* Buffer full		*/
				fputc ('\a', &__stdout);
			}
		}
	}
}


//*-----------------------------------------------------------------------------
//* Function Name       : AT91F_WaitKeyPressed()
//* Object              :
//* Input Parameters    :
//* Return value		:
//*-----------------------------------------------------------------------------
int AT91F_WaitKeyPressed(void)
{
   	printf("> ");
	return fgetc(&__stdin);
}


