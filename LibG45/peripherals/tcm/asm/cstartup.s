;------------------------------------------------------------------------------
;-         ATMEL Microcontroller Software Support  -  ROUSSET  -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;-----------------------------------------------------------------------------
;- File source          : cstartup_boot.arm
;- Object               : Generic CStartup
;- Compilation flag     : None
;-
;- 1.0 01/22/04 	FBr : Creation ARM ADS
;------------------------------------------------------------------------------
;--------------------------------
;- ARM Core Mode and Status Bits
;--------------------------------

ARM_MODE_USER           EQU     0x10
ARM_MODE_FIQ            EQU     0x11
ARM_MODE_IRQ            EQU     0x12
ARM_MODE_SVC            EQU     0x13
ARM_MODE_ABORT          EQU     0x17
ARM_MODE_UNDEF          EQU     0x1B
ARM_MODE_SYS            EQU     0x1F

I_BIT                   EQU     0x80
F_BIT                   EQU     0x40
T_BIT                   EQU     0x20

;------------------------------------------------------------------------------
;- Stack Area Definition
;-----------------------
;- 
;------------------------------------------------------------------------------
IRQ_STACK_SIZE         EQU      0x10
FIQ_STACK_SIZE         EQU      0x04
ABT_STACK_SIZE         EQU      0x04
UND_STACK_SIZE         EQU      0x04
SVC_STACK_SIZE         EQU      0x04
USER_STACK_SIZE        EQU      0x400

;------------------------------------------------------------------------------
;- Area Definition
;-----------------
;- Must be defined as function to put first in the code as it must be mapped
;- at offset 0 of the flash EBI_CSR0, ie. at address 0 before remap.
;------------------------------------------------------------------------------
                AREA        reset, CODE, READONLY

    INCLUDE   AT91SAM9264.inc

;	IMPORT __use_no_semihosting_swi
;------------------------------------------------------------------------------
;- Define the entry point
;------------------------

	EXPORT	__ENTRY
__ENTRY

;------------------------------------------------------------------------------
;- Exception vectors ( before Remap )
;------------------------------------
;- These vectors are read at address 0.
;- They absolutely requires to be in relative addresssing mode in order to 
;- guarantee a valid jump. For the moment, all are just looping (what may be 
;- dangerous in a final system). If an exception occurs before remap, this 
;- would result in an infinite loop. 
;------------------------------------------------------------------------------
                B           InitReset       	; reset
undefvec
                B           undefvec        	; Undefined Instruction
swivec
                B           swivec          	; Software Interrupt
pabtvec
                B           pabtvec         	; Prefetch Abort
dabtvec 
                B           dabtvec         	; Data Abort
rsvdvec
                B           rsvdvec         	; reserved
irqvec
                ldr         pc, [pc,#-0xF20]    ; IRQ : read the AIC
fiqvec
                B           fiqvec          	; FIQ
	
;-------------------
;- The reset handler
;-------------------
InitReset

; SRAM = 160kB and is mapped in 0x300000
;with ITCM and DTCM = 64Kb SRAM is 32Kb size
RAMLIMIT	EQU      0x308000

;------------------------------------------------------------------------------
;- Setup the stack for each mode
;-------------------------------
	ldr     r0, =RAMLIMIT

;- Set up Fast Interrupt Mode and set FIQ Mode Stack
	msr     CPSR_c, #ARM_MODE_FIQ:OR:I_BIT:OR:F_BIT
	mov     r13, r0                     ; Init stack FIQ
	sub     r0, r0, #FIQ_STACK_SIZE

;- Set up Interrupt Mode and set IRQ Mode Stack
	msr     CPSR_c, #ARM_MODE_IRQ:OR:I_BIT:OR:F_BIT
	mov     r13, r0                     ; Init stack IRQ
	sub     r0, r0, #IRQ_STACK_SIZE
 
;- Set up Abort Mode and set Abort Mode Stack
	msr     CPSR_c, #ARM_MODE_ABORT:OR:I_BIT:OR:F_BIT
	mov     r13, r0                     ; Init stack Abort
	sub     r0, r0, #ABT_STACK_SIZE

;- Set up Undefined Instruction Mode and set Undef Mode Stack
	msr     CPSR_c, #ARM_MODE_UNDEF:OR:I_BIT:OR:F_BIT
	mov     r13, r0                     ; Init stack Undef
	sub     r0, r0, #UND_STACK_SIZE

;- Set up Supervisor Mode and set Supervisor Mode Stack
	msr     CPSR_c, #ARM_MODE_SVC:OR:I_BIT:OR:F_BIT
	mov     r13, r0                     ; Init stack Sup
	sub     r0, r0, #SVC_STACK_SIZE

;- Set up user Mode and set Undef Mode Stack
	msr     CPSR_c, #ARM_MODE_SYS:OR:I_BIT:OR:F_BIT
	mov     r13, r0                     ; Init stack Sup
	sub     r0, r0, #USER_STACK_SIZE

;------------------------------------------------------------------------------
;- Low level Init is performed in a C function: AT91F_LowLevelInit (APMC, AIC, EBI, ....)
;- Init Stack Pointer to a valid memory area before calling AT91F_LowLevelInit
;----------------------------------------------------------------------

	IMPORT     AT91F_LowLevelInit
	
	ldr       r0, = AT91F_LowLevelInit
	mov       lr, pc
	bx        r0


;------------------------------------------------------------------------------
;- Initialise C variables
;------------------------
;- Following labels are automatically generated by the linker. 
;- RO: Read-only = the code
;- RW: Read Write = the data pre-initialized and zero-initialized.
;- ZI: Zero-Initialized.
;- Pre-initialization values are located after the code area in the image.
;- Zero-initialized datas are mapped after the pre-initialized.
;- Note on the Data position : 
;- If using the ARMSDT, when no -rw-base option is used for the linker, the 
;- data area is mapped after the code. You can map the data either in internal
;- SRAM ( -rw-base=0x40 or 0x34) or in external SRAM ( -rw-base=0x2000000 ).
;- Note also that to improve the code density, the pre_initialized data must 
;- be limited to a minimum.
;------------------------------------------------------------------------------

	add     r2, pc,#-(8+.-CInitData)  ; @ where to read values (relative)
	ldmia   r2, {r0, r1, r3, r4}
	
	cmp         r0, r1                  ; Check that they are different
	beq         EndRW
LoopRW	
	cmp         r1, r3                  ; Copy init data
	ldrcc       r2, [r0], #4
	strcc       r2, [r1], #4
	bcc         LoopRW
EndRW

	mov         r2, #0
LoopZI	
	cmp         r3, r4                  ; Zero init
	strcc       r2, [r3], #4
	bcc         LoopZI
 
	b           EndInitC
                
CInitData
 	IMPORT      |Image$$RO$$Limit|      ; End of ROM code (=start of ROM data)
	IMPORT      |Image$$RW$$Base|       ; Base of RAM to initialise
	IMPORT      |Image$$ZI$$Base|       ; Base and limit of area
	IMPORT      |Image$$ZI$$Limit|      ; Top of zero init segment
	
	DCD     |Image$$RO$$Limit|      ; End of ROM code (=start of ROM data)
 	DCD     |Image$$RW$$Base|       ; Base of RAM to initialise
 	DCD     |Image$$ZI$$Base|       ; Base and limit of area
 	DCD     |Image$$ZI$$Limit|      ; Top of zero init segment
EndInitC

;------------------------------------------------------------------------------
; Enable interrupts
;------------------------------------------------------------------------------
  	msr     CPSR_c, #ARM_MODE_SVC:OR:F_BIT

;------------------------------------------------------------------------------
;- Branch on C code Main function (with interworking)
;----------------------------------------------------
;- Branch must be performed by an interworking call as either an ARM or Thumb 
;- main C function must be supported. This makes the code not position-
;- independant. A Branch with link would generate errors 
;------------------------------------------------------------------------------
	IMPORT      main
_main
__main
	EXPORT    _main
	EXPORT    __main
	ldr       r0, =main
	mov       lr, pc
	bx        r0

;------------------------------------------------------------------------------
;- Loop for ever
;---------------
;- End of application. Normally, never occur.
;- Could jump on Software Reset ( B 0x0 ).
;------------------------------------------------------------------------------
End
	b           End
	
	
	
            END
