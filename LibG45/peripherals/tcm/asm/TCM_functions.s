;------------------------------------------------------------------------------
;-         ATMEL Microcontroller Software Support  -  ROUSSET  -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;-----------------------------------------------------------------------------
;- File source          : it_handler.s
;- Object               : Example of IT handler calling a C function
;- Compilation flag     : None
;-
;- 1.0 16/03/01 	ODi, : Creation ARM ADS
;------------------------------------------------------------------------------
	AREA        tcm_map_function, CODE, READONLY
;------------------------------------------------------------------------------
;- LISR vector handler for system peripherals
;--------------------------------------------
;- This macro save the context, call the LISR dispatch routine, and restore
;- the context
;------------------------------------------------------------------------------
    INCLUDE   AT91SAM9264.inc

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

SWI_FOR_ITCM			EQU		0x100000
SWI_FOR_DTCM			EQU		0x200000


;------------------------------------------------------------------------------
;- Function         : AT91F_WriteITCMRegionRegister
;- Treatments       : Maps ITCM region register
;- Operations       : Maps the ITCM to enable the core to directly access 
;-					(without going through AHB) it
;------------------------------------------------------------------------------
                EXPORT      AT91F_WriteDTCMRegionRegister

;- Map ITCM to enable the core to get direct access to it.

AT91F_WriteDTCMRegionRegister
;msr         CPSR_c,#I_BIT:OR:ARM_MODE_FIQ:OR:F_BIT
	
	MCR	p15,0,r0,c9,c1,0
    
	mov pc, lr
	
;------------------------------------------------------------------------------
;- Function         : AT91F_WriteDTCMRegionRegister
;- Treatments       : Maps DTCM region register
;- Operations       : Maps the DTCM to enable the core to directly access 
;-					(without going through AHB) it
;------------------------------------------------------------------------------
                EXPORT      AT91F_WriteITCMRegionRegister	
	
;- Map DTCM to enable the core to get direct access to it
 
AT91F_WriteITCMRegionRegister
    
	MCR	p15,0,r0,c9,c1,1
	
	mov pc,lr

;------------------------------------------------------------------------------
;- Function         : AT91F_WriteITCMRegionRegister_SWI
;- Treatments       : Maps ITCM region register
;- Operations       : Maps the ITCM to enable the core to directly access 
;-					(without going through AHB) it. It uses a SWI to switch to
;-					SVC mode in order to execute MCR and MRC instructions
;------------------------------------------------------------------------------
                EXPORT      AT91F_WriteITCMRegionRegister_SWI

;- Map ITCM to enable the core to get direct access to it (with SWI)

AT91F_WriteITCMRegionRegister_SWI

	stmfd	sp!, {r0-r12,lr}
	swi	SWI_FOR_ITCM
	ldmia	sp!, {r0-r12,pc}
	
;------------------------------------------------------------------------------
;- Function         : AT91F_WriteITCMRegionRegister_SWI
;- Treatments       : Maps ITCM region register
;- Operations       : Maps the ITCM to enable the core to directly access 
;-					(without going through AHB) it. It uses a SWI to switch to
;-					SVC mode in order to execute MCR and MRC instructions
;------------------------------------------------------------------------------
                EXPORT      AT91F_WriteDTCMRegionRegister_SWI

;- Map DTCM to enable the core to get direct access to it (with SWI)

AT91F_WriteDTCMRegionRegister_SWI

	stmfd	sp!, {r0-r12,lr}
	swi	SWI_FOR_DTCM
	ldmia	sp!, {r0-r12,pc}


;------------------------------------------------------------------------------
;- Function         : AT91F_SWI_Handler
;------------------------------------------------------------------------------
				EXPORT		AT91F_SWI_Handler	
				
AT91F_SWI_Handler

;	stmfd	sp!, {r0-r12,lr}
	ldr		r1, [lr,#-4]      ;- Calculates the address of SWI instruction and 
							  ;- stores in r1.
	bic		r1,r1,#0xff000000
	cmp		r1,#SWI_FOR_ITCM
	beq		AT91F_WriteITCMRegionRegister
	cmp		r1,#SWI_FOR_DTCM
	beq		AT91F_WriteDTCMRegionRegister
;	ldmia	sp!, {r0-r12,pc}
	
;------------------------------------------------------------------------------
;- End of File
;------------------------------------------------------------------------------


End
		END
