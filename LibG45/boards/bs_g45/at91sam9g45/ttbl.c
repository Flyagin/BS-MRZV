/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2006
 *
 *    File name   : ttbl.c
 *    Description : MMU Translation tables
 *
 *    History :
 *    1. Date        : Sep, 19 2006
 *       Author      : Stanimir Bonev
 *       Description : Create
 *
 *        The physical memory map is:
 *
 *      0x00000000
 *                  |---------------------------|
 *      0x0000003F  |       iRAM  Vectors       |
 *                  |---------------------------|
 *      0x00000040  |           iRAM            |
 *                  |      RW Nocached          |
 *      0x03FFFFFF  |---------------------------|
 *      0x04000000  |     DMA Dummy Area        |
 *                  |      RW Nocached          |
 *                  |---------------------------|
 *      0x08000000  |      iRAM   (mirror)      |
 *                  |       RW Nocached         |
 *      0x0BFFFFFF  |---------------------------|
 *                  |                           |
 *                  ~                           ~
 *                  |                           |
 *                  |---------------------------|
 *      0x20000000  |          AHB ch 5         |
 *                  |        RW Nocached        |
 *      0x200BFFFF  |---------------------------|
 *                  |                           |
 *                  ~                           ~
 *                  |                           |
 *                  |---------------------------|
 *      0x30000000  |          AHB ch 6         |
 *                  |        RW Nocached        |
 *      0x31FFFFFF  |---------------------------|
 *                  |                           |
 *                  ~                           ~
 *                  |                           |
 *                  |---------------------------|
 *      0x40000000  |          AHB ch 7         |
 *                  |        RW Nocached        |
 *      0x400FFFFF  |---------------------------|
 *                  |                           |
 *                  ~                           ~
 *      0xE1000000  |                           |
 *                  |---------------------------|
 *                  |                           |
 *                  |  SRAM RO  cached 128kB    |
 *      0xE101FFFF  |                           |
 *      0xE1020000  |---------------------------|
 *                  |                           |
 *                  |  SRAM RO  No cached 128kB |
 *      0xE103FFFF  |                           |
 *      0xE1040000  |---------------------------|
 *                  |                           |
 *                  |  SDRAM RW  cached 128kB   |
 *      0xE105FFFF  |                           |
 *      0xE1060000  |---------------------------|
 *                  |                           |
 *                  |  SDRAM RW  No cached 128kB|
 *      0xE107FFFF  |                           |
 *      0x81000000  |---------------------------|
 *
 *    $Revision: 30870 $
 **************************************************************************/
#include "ttbl.h"

#pragma segment="MMU_TT"

#pragma location="MMU_TT"
#pragma data_alignment=16384
__no_init Int32U L1Table[L1_ENTRIES_NUMB];

#pragma location="MMU_TT"
#pragma data_alignment=2048
__no_init Int32U L2Coarses1[L2_CP_ENTRIES_NUMB];

#pragma location="MMU_TT"
#pragma data_alignment=2048
__no_init Int32U L2Coarses2[L2_CP_ENTRIES_NUMB];

//#pragma location="MMU_TT"
//#pragma data_alignment=2048
//__no_init Int32U L2Coarses3[L2_CP_ENTRIES_NUMB];


const TtSectionBlock_t TtSB[] =
{
  // L1
   L1_SECTIONS_ENTRY(      1,0x0000000,0x0000000        ,3,1,0,0),
   L1_SECTIONS_ENTRY(      1,0x00300000,0x00300000        ,3,1,0,0),
   L1_SECTIONS_ENTRY(      4,0x00500000,0x00500000        ,3,1,0,0),
   L1_SECTIONS_ENTRY(      1,0x00600000,0x00600000        ,3,1,0,0),
   L1_SECTIONS_ENTRY(      1,0x00700000,0x00700000        ,3,1,0,0),
   L1_SECTIONS_ENTRY(      1,0x00800000,0x00800000        ,3,1,0,0),
   //L1_SECTIONS_ENTRY(  1 ,0xFFF00000,0xFFF00000 ,3,2,0,0),
  // 256 MB RW coarse table internal Memory Area
  // L1_COARSES_PAGE_ENTRY(  9,0x0000000,(Int32U)L2Coarses1  ,1    ),
   //   1 MB Flash section cached (CS0)
  L1_SECTIONS_ENTRY(      1,0x10000000,0x10000000        ,3,1,1,0),
  L1_SECTIONS_ENTRY(      1,0x10100000,0x10100000        ,3,1,1,0),
  L1_SECTIONS_ENTRY(      1,0x10200000,0x10200000        ,3,1,1,0),
  L1_SECTIONS_ENTRY(      1,0x10300000,0x10300000        ,3,1,1,0),
  L1_SECTIONS_ENTRY(      1,0x10700000,0x10700000        ,3,1,0,0),
  
   L1_SECTIONS_ENTRY(      1,0x20000000,0x20000000        ,3,1,1,0),
  //   1 MB SRAM section no cached (CS1)
  L1_SECTIONS_ENTRY(      1,0x20100000,0x20100000        ,3,1,1,0),
  L1_SECTIONS_ENTRY(      1,0x20200000,0x20200000        ,3,1,1,0),
  L1_SECTIONS_ENTRY(      1,0x20300000,0x20300000        ,3,1,0,0),
  
  L1_SECTIONS_ENTRY(      1,0x70000000,0x70000000        ,3,1,1,0),
  L1_SECTIONS_ENTRY(      1,0x70100000,0x70100000        ,3,1,1,0),
  L1_SECTIONS_ENTRY(      1,0x70200000,0x70200000        ,3,1,1,0),
  L1_SECTIONS_ENTRY(      1,0x70300000,0x70300000        ,3,1,1,0),
  L1_SECTIONS_ENTRY(      1,0x70400000,0x70400000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x70500000,0x70500000        ,3,1,1,0),
  L1_SECTIONS_ENTRY(      1,0x70600000,0x70600000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x70700000,0x70700000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x70800000,0x70800000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x70900000,0x70900000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x70A00000,0x70A00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x70B00000,0x70B00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x70C00000,0x70C00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x70D00000,0x70D00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x70E00000,0x70E00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x70F00000,0x70F00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71000000,0x71000000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71100000,0x71100000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71200000,0x71200000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71300000,0x71300000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71400000,0x71400000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71500000,0x71500000        ,3,1,1,0),
  L1_SECTIONS_ENTRY(      1,0x71600000,0x71600000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71700000,0x71700000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71800000,0x71800000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71900000,0x71900000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71A00000,0x71A00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71B00000,0x71B00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71C00000,0x71C00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71D00000,0x71D00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71E00000,0x71E00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x71F00000,0x71F00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72000000,0x72000000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72100000,0x72100000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72200000,0x72200000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72300000,0x72300000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72400000,0x72400000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72500000,0x72500000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72600000,0x72600000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72700000,0x72700000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72800000,0x72800000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72900000,0x72900000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72A00000,0x72A00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72B00000,0x72B00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72C00000,0x72C00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72D00000,0x72D00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72E00000,0x72E00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x72F00000,0x72F00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73000000,0x73000000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73100000,0x73100000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73200000,0x73200000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73300000,0x73300000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73400000,0x73400000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73500000,0x73500000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73600000,0x73600000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73700000,0x73700000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73800000,0x73800000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73900000,0x73900000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73A00000,0x73A00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73B00000,0x73B00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73C00000,0x73C00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73D00000,0x73D00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73E00000,0x73E00000        ,3,1,0,0),
  L1_SECTIONS_ENTRY(      1,0x73F00000,0x73F00000        ,3,1,0,0),
  
  
  
 /* 
   // 256 MB RW section no cached (CS2 DMA  area)
  L1_SECTIONS_ENTRY(  1 ,0x30000000,0x30000000 ,3,1,0,0),
  
  // 256 MB RW section no cached (CS3 DMA  area)
  L1_SECTIONS_ENTRY(  1 ,0x40000000,0x40000000 ,3,1,0,0),
  
  // 256 MB RW section no cached (CS4 DMA  area)
  L1_SECTIONS_ENTRY(  1 ,0x50000000,0x50000000 ,3,1,0,0),
  
  // 256 MB RW section no cached (CS5 DMA  area)
  L1_SECTIONS_ENTRY(  1 ,0x60000000,0x60000000 ,3,1,0,0),
  
  // 256 MB RW section no cached (DDRSDRC0 DMA  area)
  L1_SECTIONS_ENTRY(  32 ,0x70000000,0x70000000 ,3,1,0,0),
  
   // 6 MB RW section no cached (Internal peripherals  area )
  L1_SECTIONS_ENTRY(  6 ,0xFFF70000,0xFFF70000 ,3,2,0,0),
   // 1 MB RW section no cached (Internal peripherals  area )
  //L1_SECTIONS_ENTRY(  1 ,0xFFFF0000,0xFFFF0000 ,3,2,0,0),
  */
   L1_SECTIONS_ENTRY(  1 ,0xFFF00000,0xFFF00000 ,3,1,0,0),
  TSB_INVALID,
  // L2 coarse table 16 * 64kB = 1024kB
  L2_CT_LARGE_PAGE_ENTRY(2,0x00000000,0x00000000,3,3,3,3,0,0),
  // L2 coarse table 16 * 64kB = 1024kB
  L2_CT_LARGE_PAGE_ENTRY(1,0x00100000,0x00100000,3,3,3,3,0,0),
  // L2 coarse table 16 * 64kB = 1024kB
  L2_CT_LARGE_PAGE_ENTRY(1,0x00200000,0x00200000,3,3,3,3,0,0),
  // L2 coarse table 16 * 64kB = 1024kB
  L2_CT_LARGE_PAGE_ENTRY(2,0x00300000,0x00300000,3,3,3,3,0,0),
  // L2 coarse table 16 * 64kB = 1024kB
  L2_CT_LARGE_PAGE_ENTRY(16,0x00400000,0x00400000,3,3,3,3,0,0),
  
  L2_CT_LARGE_PAGE_ENTRY(16,0x00500000,0x00500000,3,3,3,3,0,0),
  // L2 coarse table 16 * 64kB = 1024kB
  L2_CT_LARGE_PAGE_ENTRY(16,0x00600000,0x00600000,3,3,3,3,0,0),
  // L2 coarse table 16 * 64kB = 1024kB
  L2_CT_LARGE_PAGE_ENTRY(16,0x00700000,0x00700000,3,3,3,3,0,0),
  // L2 coarse table 16 * 64kB = 1024kB
  L2_CT_LARGE_PAGE_ENTRY(16,0x00800000,0x00800000,3,3,3,3,0,0),
  // L2 coarse table 16 * 64kB = 1024kB
  L2_CT_LARGE_PAGE_ENTRY(16,0x00900000,0x00900000,3,3,3,3,0,0),
  
 
  TSB_INVALID,
//  // L2 coarse table 8 * 64kB = 512kB
//  L2_CT_LARGE_PAGE_ENTRY(8,0xE0000000,0xE0000000,2,2,2,2,1,0),
//  L2_CT_LARGE_PAGE_ENTRY(8,0xE0080000,0xE0080000,2,2,2,2,0,0),
//  TSB_INVALID,
  
  TSB_INVALID
};

const TtTableBlock_t TtTB[] =
{
  {L1Table,TableL1},
  {L2Coarses1,TableL2_Coarse},
  {L2Coarses2,TableL2_Coarse},
//  {L2Coarses3,TableL2_Coarse},
  TTB_INVALID
};

//EMC_CS0_N in the address range 0xE000 0000 to 0xE0FF FFFF Flash 512Kx32 
//• EMC_CS1_N in the address range 0xE100 0000 to 0xE1FF FFFF Sram 128 Kx32
//• EMC_CS2_N in the address range 0xE200 0000 to 0xE2FF FFFF Sram 4kx16
//• EMC_CS3_N in the address range 0xE300 0000 to 0xE3FF FFFF Input/Output 64 <-One K block





//.const TtSectionBlock_t TtSB[] =
//.{
//.  // L1
//.  // 192 MB RW section no cached (iRAM DMA dummy area)
//.  L1_SECTIONS_ENTRY(    192,0x00000000,0x00000000 ,3,1,0,0),
//.  //   1 MB RW coarse table (AHB ch 5)
//.  L1_COARSES_PAGE_ENTRY(  1,0x20000000,(Int32U)L2Coarses1  ,1    ),
//.  //  32 MB RW section no cached (AHB ch 6)
//.  L1_SECTIONS_ENTRY(     32,0x30000000,0x30000000        ,3,1,0,0),
//.  //   1 MB RW section no cached (AHB ch 7)
//.  L1_SECTIONS_ENTRY(      1,0x40000000,0x40000000        ,3,1,0,0),
//.  //   1 MB Flash section cached (EMC0)
//.  L1_SECTIONS_ENTRY(      1,0xE0000000,0xE0000000        ,2,1,1,0),
//.  //   1 MB Flash section no cached (EMC0)
//.  L1_SECTIONS_ENTRY(      1,0xE0100000,0xE0100000        ,2,1,0,0),
//.  //   1 MB Flash section cached (EMC0)
//.//  L1_COARSES_PAGE_ENTRY(  1,0xE0000000,(Int32U)L2Coarses2  ,0    ),
//.  //   1 MB SRAM coarse table (EMC1)
//.  L1_COARSES_PAGE_ENTRY(  1,0xE1000000,(Int32U)L2Coarses2  ,1    ),
//.  //   4 MB RW section no cached (EMC2)
//.  L1_SECTIONS_ENTRY(      4,0xE2000000,0xE2000000        ,3,1,0,0),
//.  //  16 MB RW section no cached (EMC3)
//.  L1_SECTIONS_ENTRY(     16,0xE3000000,0xE3000000        ,3,1,0,0),
//.  TSB_INVALID,
//.  // L2 coarse table 12 * 64kB = 768kB
//.  L2_CT_LARGE_PAGE_ENTRY(12,0x20000000,0x20000000,3,3,3,3,0,0),
//.  TSB_INVALID,
//.//  // L2 coarse table 8 * 64kB = 512kB
//.//  L2_CT_LARGE_PAGE_ENTRY(8,0xE0000000,0xE0000000,2,2,2,2,1,0),
//.//  L2_CT_LARGE_PAGE_ENTRY(8,0xE0080000,0xE0080000,2,2,2,2,0,0),
//.//  TSB_INVALID,
//.  // L2 coarse table 63 * 4kB = 252kB
//.  L2_CT_SMALL_PAGE_ENTRY(63,0xE1000000,0xE1000000,2,2,2,2,1,0),
//.  // L2 coarse table 1 * 4kB = 4kB
//.  L2_CT_SMALL_PAGE_ENTRY(1 ,0xE103F000,0xE103F000,2,2,2,2,0,0),
//.  // L2 coarse table 63 * 4kB = 252kB
//.  L2_CT_SMALL_PAGE_ENTRY(63,0xE1040000,0xE1040000,3,3,3,3,1,1),
//.  // L2 coarse table 1 * 4kB = 4kB
//.  L2_CT_SMALL_PAGE_ENTRY(1 ,0xE107F000,0xE107F000,3,3,3,3,0,0),
//.  TSB_INVALID
//.};
//.
//.const TtTableBlock_t TtTB[] =
//.{
//.  {L1Table,TableL1},
//.  {L2Coarses1,TableL2_Coarse},
//.  {L2Coarses2,TableL2_Coarse},
//.//  {L2Coarses3,TableL2_Coarse},
//.  TTB_INVALID
//.};
