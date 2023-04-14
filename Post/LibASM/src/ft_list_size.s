; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;
;          .-.                                                          ;
;    __   /   \   __                                                    ;
;   (  `'.\   /.'`  )   LibASM - ft_list_size.s                         ;
;    '-._.(;;;)._.-'                                                    ;
;    .-'  ,`"`,  '-.                                                    ;
;   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        ;
;       //\   /         Last Updated: Tue Feb 14 00:37:41 CET 2023      ;
;      ||  '-'                                                          ;
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;

section .text

; Computes the length of the list
; from the given starting point
; 
; 0 - rdi	t_list *		Starting point
; 
; Returns the number of elements

global _ft_list_size
_ft_list_size:

	push	rdi				; Stores initial state of rdi
	xor		rax, rax		; Initializes counter to 0

loopStart:

	cmp		rdi, qword 0	; CONDITION: if current is NULL:
	je		loopEnd			; 	Get to END

	mov		rdi, [rdi + 8]	; Get the NEXT pointer
	inc		rax				; Increment counter
	jmp		loopStart		; Get to START

loopEnd:

	pop		rdi				; Restores initial state of rdi
	ret						; END OF FUNCTION