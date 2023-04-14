; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;
;          .-.                                                          ;
;    __   /   \   __                                                    ;
;   (  `'.\   /.'`  )   LibASM - ft_list_sort.s                         ;
;    '-._.(;;;)._.-'                                                    ;
;    .-'  ,`"`,  '-.                                                    ;
;   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        ;
;       //\   /         Last Updated: Thu Apr 13 13:42:45 CEST 2023     ;
;      ||  '-'                                                          ;
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;

section .text

; Sorts a list accordingly, using a given comparaison function
; and updates the beginning pointer aswell
; 
; 0 - rdi	t_list **					Beginning of the list
; 1 - rsi	int (*)(void *)				Compare function
; 
; Does nothing if begin or comparator are NULL




global _ft_list_sort
_ft_list_sort:

	test	rdi, rdi			; CONDITION: If BEGIN is NULL:
	jz		errHandle			; 	Get to END
	test	rsi, rsi			; CONDITION: If COMPARATOR is NULL:
	jz		errHandle			; 	Get to END

	mov		r10, [rdi]			; Set FIRST to BEGIN
								; FALLTHROUGH

loopStart:

	cmp		qword [rdi], 0		; CONDITION: If BEGIN is NULL:
	jz		loopEnd				; 	Get to END

	mov		rcx, [rdi]			; Retrieve CURRENT into RCX
	mov		r9, [rcx + 8]		; Retrieve CURRENT's NEXT into RBX
								; FALLTHROUGH

loopNext:

	test	r9, r9				; CONDITION: If NEXT does exists:
	jnz		dataCompare			; 	Get to COMPARE

	mov		rcx, [rdi]			; Set CURRENT to BEGIN
	mov		r9, [rcx + 8]		; Set NEXT to CURRENT's NEXT
	mov		[rdi], r9			; Set BEGIN to NEXT
	jmp		loopStart			; Get to START

dataCompare:

	push	rdi					; Stores state of RDI
	push	rsi					; Stores state of RSI

	mov		rax, rsi			; Move COMPARATOR into RAX
	mov		rcx, [rdi]			; Move BEGIN into RCX

	mov		rdi, [rcx]			; Set CURRENT's DATA as first argument
	mov		rsi, [r9]			; Set NEXT's DATA as second argument
	call	rax					; Call COMPARATOR function

	pop		rsi					; Restores state of RSI
	pop		rdi					; Restores state of RDI

	cmp		rax, 0				; CONDITION: If return value is greater than 0:
	jg		dataSwap			; 	Get to SWAP

	mov		rcx, [r9 + 8]		; Set CURRENT to NEXT's NEXT
	mov		r9, rcx				; Set NEXT to CURRENT
	jmp		loopNext			; Get to NEXT ITER

dataSwap:

	mov		r8, [rdi]			; Set TARGET to BEGIN
	mov		rcx, [r8]			; Set CURRENT to TARGET's DATA
	mov		rax, [r9]			; Set OTHER to NEXT's DATA

	mov		[r8], rax			; Set TARGET's DATA to OTHER
	mov		[r9], rcx			; Set NEXT's DATA to CURRENT

	mov		rcx, [r9 + 8]		; Set CURRENT to NEXT's NEXT
	mov		r9, rcx				; Set NEXT to CURRENT
	jmp		loopNext			; Get to NEXT ITER

loopEnd:

	mov		[rdi], r10			; Set BEGIN to FIRST
								; FALLTHROUGH

errHandle:

	ret							; END OF FUNCTION
