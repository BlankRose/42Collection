; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;
;          .-.                                                          ;
;    __   /   \   __                                                    ;
;   (  `'.\   /.'`  )   LibASM - ft_write.s                             ;
;    '-._.(;;;)._.-'                                                    ;
;    .-'  ,`"`,  '-.                                                    ;
;   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        ;
;       //\   /         Last Updated: Sat Feb 11 18:47:03 CET 2023      ;
;      ||  '-'                                                          ;
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;

section .text

; Simple function which computes the length of
; any given string
; 
; 0 - rdi	const char *	target string to measure
; 
; Returns the length of the string
; 
; It is undefinied behavior if the string is NULL
; or doesn't contains any NUL characters


global	_ft_strlen
_ft_strlen:

	xor		rcx, rcx				; Sets counter to 0
									; `xor` is more space efficient than `mov` for this task

loopStart:

	cmp		[rdi + rcx], byte 0		; CONDITION: if current character is NUL character:
	je		loopEnd					; 	Get to END

	inc		rcx						; Increment counter
	jmp		loopStart				; Get to START

loopEnd:

	mov		rax, rcx				; Sets the return value
	ret								; END OF FUNCTION
