#define EXT_SRAM_BASE       0x20100000
#define EXT_SRAM_SIZE         (0x200000- 0x10000)
#define EXT_SRAM_END        0x201FFFFF
#define FLASH_BASE      0x10000000
//#define FLASH_end        0x102FFFFF;


#define IRAM_BASE       0x300000
#define IRAM_END        0x30FFFF

//#define WORD_BOUND_EXT_SRAM ((unsigned long)(EXT_SRAM_BASE+(EXT_SRAM_SIZE>>2)))
#define WORD_BOUND_EXT_SRAM 0x201ffff0//((unsigned long)(EXT_SRAM_BASE+(EXT_SRAM_SIZE>>1)))

//((unsigned long)(EXT_SRAM_LIMIT)>>2)
__arm void StartTestRam(void)
{
	register unsigned long long* pU64;
	register unsigned long long  u64_TstVal;
	
	pU64 = (unsigned long long*)(EXT_SRAM_BASE);
	u64_TstVal = WORD_BOUND_EXT_SRAM;
	u64_TstVal = 0xff;
	while (((unsigned long )pU64) < (WORD_BOUND_EXT_SRAM))
	{
		*pU64++ = u64_TstVal;
		u64_TstVal +=  0xff;
	}
	//Control Part
	pU64 = (unsigned long long*)(EXT_SRAM_BASE);
	u64_TstVal = 0xff;
	while (((unsigned long )pU64) < (WORD_BOUND_EXT_SRAM))
	{
		if (*pU64 != u64_TstVal)
		while (1);
		else pU64++;
		u64_TstVal +=  0xff;
	}

}
#ifdef BS_G45_TEST

typedef void (*funcp_t) (void);
#pragma section = "MYOVERLAY"
//`#pragma location="MYOVERLAY"
//`char chPORT2;
#pragma section = "MYOVERLAY1"
#pragma section = "MYOVERLAY1_init"
#pragma section = "MYOVERLAY2_init"
void SwitchToOverlay1(void)
{
char * from = __section_begin("MYOVERLAY1_init");
char * to = __section_begin("MYOVERLAY");
long size      = __section_size ("MYOVERLAY1_init");
memcpy(to, from,size);// __section_size("MYOVERLAY1_init"));
}
void SwitchToOverlay2(void)
{
char * from = __section_begin("MYOVERLAY2_init");
char * to = __section_begin("MYOVERLAY");
long size      = __section_size ("MYOVERLAY2_init");
memcpy(to, from, size);//__section_size("MYOVERLAY2_init"));
}
__arm void StartTestRom2(void); 
long StartTest(void) 
{
unsigned int i;
funcp_t f_p = (funcp_t) 
        ((char*) __section_begin("MYOVERLAY") + 0); /* +1 for Thumb instr */
		//StartTestRom2();
		SwitchToOverlay1();
		//f_p();
		SwitchToOverlay2();
		f_p();
		//StartTestRam
		//StartTestRom2();
return 0;		
}
void DbgBrPKFunc(long i,long j);
extern unsigned short const __checksum;
extern unsigned int __checksum_begin;
extern unsigned int __checksum_end;
__arm void StartTestRom(void) @ "MYOVERLAY"
{
unsigned int i;
  unsigned short sum = 1;
  unsigned char *point = (unsigned char *)FLASH_BASE; 
  for ( i = (0xF); i > 0; i--)
    sum += *point++;	
}
__root __arm void StartTestRom1(void) @ "MYOVERLAY1"
{

  //'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  //~~~~~~~~~~~~~     Перевірка контрольної суми програми       ~~~~
  //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
  unsigned int i,j;
  unsigned short sum = 1;
  unsigned char *point = ((unsigned char *)&__checksum_begin);
  //for ( i = ((unsigned int)&__checksum_end -(unsigned int)&__checksum_begin +1); i > 0; i--)
   for ( j = 0,i = ((unsigned int)&__checksum_end -(unsigned int)&__checksum_begin +1); i > 0,i>j; i--)
    {
	sum += *point++;//DbgBrPKFunc(i,j);
	}
///////////////////////////////////////////////////////////////	
//   Activate WatchDog
	//.GPIO_SetBits  (GPIOF, GPIO_Pin_6);
	//
///////////////////////////////////////////////////////////////	
	
  if (sum != (unsigned short)__checksum)
  {
	//return;-0x20000
	i = sum - (__checksum>>8);// Need for Iar Check Calc IAR fierst calc __checksum
	i -= __checksum&0xff;     // then insert in code (for big size calc _checksum)
	if(i!=__checksum)
    while(1);
	
  }
  //else
  {
	
	//...i = 0x6C000000+0x400000;
	//...*((unsigned char*)i) = 0;
	//...i = 0x6C000000+0x200000;
    //...*((unsigned char*)i) = 0;
  }
    //.GPIO_ResetBits(GPIOF, GPIO_Pin_6);
	
}
__arm void StartTestRom2(void) 
{

  //'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  //~~~~~~~~~~~~~     Перевірка контрольної суми програми       ~~~~
  //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
  unsigned int i,j;
  unsigned short sum = 1;
  unsigned char *point = ((unsigned char *)&__checksum_begin);
  for (j = 0, i = ((unsigned int)&__checksum_end -(unsigned int)&__checksum_begin +1); i > 0,i>j; i--)
    {sum += *point++;DbgBrPKFunc(i,j);}
///////////////////////////////////////////////////////////////	
//   Activate WatchDog
	//.GPIO_SetBits  (GPIOF, GPIO_Pin_6);
	//
///////////////////////////////////////////////////////////////	
	
  if (sum != (unsigned short)__checksum)
  {
	//return;-0x20000
	i = sum - (__checksum>>8);// Need for Iar Check Calc IAR fierst calc __checksum
	i -= __checksum&0xff;     // then insert in code (for big size calc _checksum)
	if(i!=__checksum)
    while(1);
	
  }
  //else
  {
	
	//...i = 0x6C000000+0x400000;
	//...*((unsigned char*)i) = 0;
	//...i = 0x6C000000+0x200000;
    //...*((unsigned char*)i) = 0;
  }
    //.GPIO_ResetBits(GPIOF, GPIO_Pin_6);
	
}
#define WORD_BOUND_EXT_SRAM1 ((unsigned long)(EXT_SRAM_BASE+(EXT_SRAM_SIZE>>1)))
__root __arm void StartTestRam1(void)  @ "MYOVERLAY2"
{
	register unsigned long* pU32;
	register unsigned long  u32_TstVal;
	
	pU32 = (unsigned long*)(EXT_SRAM_BASE);
	u32_TstVal = WORD_BOUND_EXT_SRAM;
	u32_TstVal = 0xff;
	//while (*pU32!=0) *pU32 = u32_TstVal;
	while (((unsigned long)pU32) < (WORD_BOUND_EXT_SRAM1))
	{
		*pU32++ = u32_TstVal;
		u32_TstVal +=  0xff;
	}
	//Control Part
	pU32 = (unsigned long*)(EXT_SRAM_BASE);
	u32_TstVal = 0xff;
	while (((unsigned long)pU32) < (WORD_BOUND_EXT_SRAM1))
	{
		if (*pU32 != u32_TstVal)
		while (1);
		else pU32++;
		u32_TstVal +=  0xff;
	}

}
void DbgBrPKFunc(long i , long j)
{
Cyc:
if (i<j+4)
goto Cyc;//while(1);

}
/*
#define WORD_BOUND_EXT_SRAM1 ((unsigned long)(EXT_SRAM_BASE+(EXT_SRAM_SIZE>>1)))
__root __arm void StartTestRam1(void)  @ "MYOVERLAY2"
{
	register unsigned long long* pU64;
	register unsigned long long u64_TstVal;
	
	pU64 = (unsigned long long*)(EXT_SRAM_BASE);
	u64_TstVal = WORD_BOUND_EXT_SRAM;
	u64_TstVal = 0xff;
	while (((unsigned long )pU64) < (WORD_BOUND_EXT_SRAM1))
	{
		*pU64++ = u64_TstVal;
		u64_TstVal +=  0xff;
	}
	//Control Part
	pU64 = (unsigned long long*)(EXT_SRAM_BASE);
	u64_TstVal = 0xff;
	while (((unsigned long )pU64) < (WORD_BOUND_EXT_SRAM1))
	{
		if (*pU64 != u64_TstVal)
		while (1);
		else pU64++;
		u64_TstVal +=  0xff;
	}

}

__arm void StartTestRam(void)
{
	register unsigned long* pU32;
	register unsigned long  u32_TstVal;
	
	pU32 = (unsigned long*)(EXT_SRAM_BASE);
	u32_TstVal = WORD_BOUND_EXT_SRAM;
	u32_TstVal = 0xff;
	while (((unsigned long)pU32) < (WORD_BOUND_EXT_SRAM))
	{
		*pU32++ = u32_TstVal;
		u32_TstVal +=  0xff;
	}
	//Control Part
	pU32 = (unsigned long*)(EXT_SRAM_BASE);
	u32_TstVal = 0xff;
	while (((unsigned long)pU32) < (WORD_BOUND_EXT_SRAM))
	{
		if (*pU32 != u32_TstVal)
		while (1);
		else pU32++;
		u32_TstVal +=  0xff;
	}

}

*/
void TestLite(void)
{
   AT91C_BASE_PIOD->PIO_PER  = (1<<23)|(0xFFFF);
   AT91C_BASE_PIOD->PIO_OER  = (1<<23)|(0xFFFF);
   AT91C_BASE_PIOD->PIO_CODR = (0xFFFF);
   AT91C_BASE_PIOD->PIO_SODR = (1<<23);
   AT91C_BASE_PIOD->PIO_SODR = (0xFF);
   AT91C_BASE_PIOD->PIO_CODR = (1<<23);
}
#endif

