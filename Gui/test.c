#if !defined(sram_not_test)

#include <string.h>

#define EXT_SRAM_BASE       0x20000000
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
extern __arm  void StartTestDDR(void);
__arm void StartTestRom1(void);
 __arm void StartTestRam1(void);
 
typedef void (*funcp_t) (void);
#pragma section = "MYOVERLAY"
//`#pragma location="MYOVERLAY"
//`char chPORT2;
#pragma section = "MYOVERLAY1"
#pragma section = "MYOVERLAY1_init"
#pragma section = "MYOVERLAY2_init"
#pragma section = "MYOVERLAY3_init"

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
void SwitchToOverlay3(void)
{
char * from = __section_begin("MYOVERLAY3_init");
char * to = __section_begin("MYOVERLAY");
long size      = __section_size ("MYOVERLAY3_init");
memcpy(to, from, size);//__section_size("MYOVERLAY2_init"));
}




__arm void StartTestRom2(void); 
long StartTest(void) 
{
unsigned int i;
funcp_t f_p = (funcp_t) 
        ((char*) __section_begin("MYOVERLAY") + 0); /* +1 for Thumb instr */
//		StartTestRom2();
		SwitchToOverlay1();
//		#ifdef  BS_G45_FL_RL
//			__asm volatile("BKPT 4");
//    	#endif 	  	 
		StartTestRom1();//f_p();//
//		#ifdef  BS_G45_FL_RL
//			__asm volatile("BKPT 4");
//    	#endif 
		SwitchToOverlay2();
		StartTestRam1();//f_p();//
//		#ifdef  BS_G45_FL_RL
//			__asm volatile("BKPT 4");
//    	#endif 
		SwitchToOverlay3();
		StartTestDDR();//f_p();//
		//
		
return 0;		
}

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
  unsigned int i;
  unsigned short sum = 1;
  unsigned char *point = ((unsigned char *)&__checksum_begin);
  for ( i = ((unsigned int)&__checksum_end -(unsigned int)&__checksum_begin +1); i > 0; i--)
    sum += *point++;
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
	{
		#ifdef  BS_G45_FL_RL
				__asm volatile("BKPT 4");
		#endif 
		while(1);
	}
    
	
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
  unsigned int i;
  unsigned short sum = 1;
  unsigned char *point = ((unsigned char *)&__checksum_begin);
  for ( i = ((unsigned int)&__checksum_end -(unsigned int)&__checksum_begin +1); i > 0; i--)
    sum += *point++;
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
    ;//.while(1);
	
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
	//~pU32 = (unsigned long*)__section_begin(".bss" );//(EXT_SRAM_BASE);
	//~pU32 += 4;
	//~pU32 &= 3;
#ifndef BS_G45_SRAM
	u32_TstVal = WORD_BOUND_EXT_SRAM;
	u32_TstVal = 0xff;
 
	while (((unsigned long)pU32) < (0x203FFFFF))
	{
		*pU32++ = u32_TstVal;
		u32_TstVal +=  0xff;
	}
	//Control Part
	pU32 = (unsigned long*)(EXT_SRAM_BASE);
	u32_TstVal = 0xff;
	while (((unsigned long)pU32) < (0x203FFFFF))
	{
		if (*pU32 != u32_TstVal)
		{
		     #ifdef  BS_G45_FL_RL
			__asm volatile("BKPT 4");
			#endif 	
			while (1);
		}			
		else pU32++;
		u32_TstVal +=  0xff;
	}
#endif
}
/*  */


#define EXT_DDR_BASE  0x70000000     
#define EXT_DDR_SIZE  0X3FFFFFF     
#define EXT_DDR_END   0x73FFFFFF     

#define WORD_BOUND_DDR ((unsigned long)(EXT_DDR_BASE+(EXT_DDR_SIZE>>1)))
__root __arm void StartTestDDR1(void) // @ "MYOVERLAY3"
{
	register unsigned long* pU32;
	register unsigned long  u32_TstVal;
	register long i;
	
	pU32 = (unsigned long*)(EXT_DDR_BASE);

#ifndef BS_G45_SRAM
	u32_TstVal = WORD_BOUND_DDR;
	u32_TstVal = 0xff;
	//for (i = 0; i< 0x40; i++)
	{
		while (((unsigned long)pU32) < (WORD_BOUND_DDR))//WORD_BOUND_DDR
		{
			*pU32++ = u32_TstVal;
			u32_TstVal +=  0xff;
		}
		//Control Part
		pU32 = (unsigned long*)(EXT_DDR_BASE);
		u32_TstVal = 0xff;
		while (((unsigned long)pU32) < (WORD_BOUND_DDR))//WORD_BOUND_DDR
		{
			if (*pU32 != u32_TstVal)
			{
				#ifdef  BS_G45_FL_RL
				__asm volatile("BKPT 4");
				#endif 	
				while (1);
			}			
			else pU32++;
			u32_TstVal +=  0xff;
		}
	}
#endif
}



__root __arm void StartTestDDR(void)  @ "MYOVERLAY3"
{
	register unsigned long* pU32;
	register unsigned long  u32_TstVal;
	register long i;
	
	pU32 = (unsigned long*)(EXT_DDR_BASE);

#ifndef BS_G45_SRAM
	u32_TstVal = WORD_BOUND_DDR;
	u32_TstVal = 0xff;
	for (i = 0; i< 0x40; i++)
	{
		while (((unsigned long)pU32) < (0x100000))//WORD_BOUND_DDR
		{
			*pU32++ = u32_TstVal;
			u32_TstVal +=  0xff;
		}
		//Control Part
		pU32 = (unsigned long*)(EXT_DDR_BASE);
		u32_TstVal = 0xff;
		while (((unsigned long)pU32) < (0x100000))//WORD_BOUND_DDR
		{
			if (*pU32 != u32_TstVal)
			{
				#ifdef  BS_G45_FL_RL
				__asm volatile("BKPT 4");
				#endif 	
				while (1);
			}			
			else pU32++;
			u32_TstVal +=  0xff;
		}
	}
#endif
}









#endif
/*
long StartTest(void) <<===========================Use this form for suitable Debuging
{
unsigned int i;
funcp_t f_p = (funcp_t) 
        ((char*) __section_begin("MYOVERLAY") + 0); 

		SwitchToOverlay1();
//		#ifdef  BS_G45_FL_RL
//			__asm volatile("BKPT 4");
//    	#endif 	  	 
		StartTestRom1();//f_p();//         <<--   Use this form for suitable Debuging
//		#ifdef  BS_G45_FL_RL
//			__asm volatile("BKPT 4");
//    	#endif 
		SwitchToOverlay2();
		StartTestRam1();//f_p();//       <<--Use this form for suitable Debuging
//		#ifdef  BS_G45_FL_RL
//			__asm volatile("BKPT 4");
//    	#endif 
		SwitchToOverlay3();
		StartTestDDR();//f_p();//       <<---Use this form for suitable Debuging
		
		//
		
return 0;		
}


*/

#endif