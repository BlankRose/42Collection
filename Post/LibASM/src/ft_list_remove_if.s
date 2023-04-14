; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;
;          .-.                                                          ;
;    __   /   \   __                                                    ;
;   (  `'.\   /.'`  )   LibASM - ft_list_remove_if.s                    ;
;    '-._.(;;;)._.-'                                                    ;
;    .-'  ,`"`,  '-.                                                    ;
;   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        ;
;       //\   /         Last Updated: Thu Apr 13 18:38:17 CEST 2023     ;
;      ||  '-'                                                          ;
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;

extern _free
section .text

; Removes an element, using a compare function which returns 0
; if condition is fullfilled, against a data reference. It will
; call free() and use another function pointer as a data cleaner
; and attach following up elements and update the pointer to the
; begin accordingly
; 
; 0 - rdi	t_list **					Beginning of the list
; 1 - rsi	void *						Reference data
; 2 - rdx	int (*)(void *, void *)		Compare function
; 3 - rcx	void (*)(void *)			Data cleaner function

global _ft_list_remove_if
_ft_list_remove_if:

	push	rbp					; Stores initial state of RSI
	push	rbx					; Stores initial state of RBX
	push	r12					; Stores initial state of R12

	mov		r12, [rdi]			; Set FIRST to BEGIN
	xor		rbx, rbx			; Set PREVIOUS to NULL

	test	rdi, rdi			; CONDITION: If BEGIN is NULL:
	jz		loopEnd				; 	Get to END
	test	rdx, rdx			; CONDITION: If COMPARe is NULL:
	jz		loopEnd				; 	Get to END
	test	rcx, rcx			; CONDITION: If DATA CLEANER is NULL:
	jz		loopEnd				; 	Get to END

loopStart:

	cmp		QWORD [rdi], 0		; CONDITION: If CURRENT is NULL:
	jz		loopEnd				; 	Get to END

	push	rdi					; Stores state of RDI
	push	rsi					; Stores state of RSI
	push	rdx					; Stores state of RDX
	push	rcx					; Stores state of RCX

	mov		r8, [rdi]			; Retrieve CURRENT in R8
	mov		rdi, [r8]			; Stores CURRENT's DATA in RDI

	test	rdi, rdi			; CONDITION: If DATA is NULL:
	jz		compare				; 	Get to COMPARE
	call	rdx					; ELSE: Call DATA COMPARE function (DATA, REF)

loopMiddle:

	pop		rcx					; Restores state of RCX
	pop		rdx					; Restores state of RDX
	pop		rsi					; Restores state of RSI
	pop		rdi					; Restores state of RDI

	test	rax, rax			; CONDITION: If cmp is NULL:
	jz		freeStruct			; 	Get to FREE

	mov		rbx, [rdi]			; Retrieve CURRENT in RBX
	mov		r8,	[rbx + 8]		; Set TMP to CURRENT's NEXT
	mov		[rdi], r8			; Set CURRENT to TMP
	jmp		loopStart			; Get to CURRENT

freeStruct:

	mov		r8, [rdi]			; Retrieve CURRENT into R8
	mov		rbp, [r8 + 8]		; Set TMP to CURRENT's NEXT

	push	rsi					; Stores state of RSI
	push	rdx					; Stores state of RDX
	push	rcx					; Stores state of RCX
	push	rdi					; Stores state of RDI

	mov		rdx, [rdi]			; Move into second ARG: CURRENT
	mov		rdi, [rdx]			; Move into first ARG: DATA CLEANER pointer function
	call	rcx					; Call DATA CLEANER function

	pop		rdi					; Restores initial state of RDI
	push	rdi					; Stores state of RDI

	mov		rdx, [rdi]			; Retrieve CURRENT into RDX
	mov		rdi, rdx			; Move into first ARG: CURRENT pointer
	call	_free				; Call FREE function

	pop		rdi					; Restores state of RDI
	pop		rcx					; Restores state of RCX
	pop		rdx					; Restores state of RDX
	pop		rsi					; Restores state of RSI
	mov		[rdi], rbp			; Set begin to TMP

	test	rbx, rbx			; CONDITION: If RBX exists:
	jnz		setPrevious			;	Get to SET PREVIOUS
	mov		r12, rbp			; Move RBP into R12
	jmp		loopStart			; Get to START

setPrevious:

	mov		[rbx + 8], rbp		; Set NEXT of PREVIOUS to NEXT
	jmp		loopStart			; Get to START

compare:

	xor		rdi, rsi			; Move RSI into RDI
	mov		rax, rdi			; Move RDI to RAX
	jmp		loopMiddle			; Get to MIDDLE

loopEnd:

	mov		[rdi], r12			; *begin = first
	pop		r12					; Restores initial state of rbx
	pop		rbx					; Restores initial state of rbx
	pop		rbp					; Restores initial state of rbp
	ret							; END OF FUNCTION
