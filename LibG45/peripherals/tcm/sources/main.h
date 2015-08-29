//*----------------------------------------------------------------------------
//*      ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : main.h
//* Object              : 
//*
//* 1.0 27/03/03 HIi    : Creation
//*----------------------------------------------------------------------------

#ifndef main_h
#define main_h

#include    "embedded_services.h"

#define AT91C_MASTER_CLOCK				48000000
#define AT91C_BAUD_RATE					115200

#define AT91C_DOWNLOAD_BASE_ADDRESS		0x20000000
#define AT91C_DOWNLOAD_MAX_SIZE			0x00020000

#define AT91C_OFFSET_VECT6				0x14		//* Offset for ARM vector 6

#define AT91C_VERSION	"VER 1.0"
// Global variables and functions definition
extern unsigned int GetTickCount(void);
#endif