; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;
;          .-.                                                          ;
;    __   /   \   __                                                    ;
;   (  `'.\   /.'`  )   LibASM - ft_strcmp.s                            ;
;    '-._.(;;;)._.-'                                                    ;
;    .-'  ,`"`,  '-.                                                    ;
;   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        ;
;       //\   /         Last Updated: Mon Feb 13 15:52:13 CET 2023      ;
;      ||  '-'                                                          ;
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;

extern _ft_strlen
section .text

; Compares two given strings byte after byte, and stops
; comparing until they two bytes differs or until one has
; a NUL terminating character
; 
; 0 - rdi	const char *	First string
; 1 - rsi	const char *	Second string
; 
; Returns the difference between the characters when
; it stops comparings

global _ft_strcmp
_ft_strcmp:

	xor		rcx, rcx				; Sets counter to 0 (rsi unused so can use it)
									; Also `xor` is more space efficient than `mov` for this task

loopStart:

	mov		al, byte [rdi + rcx]	; Get first string current character
	cmp		byte [rsi + rcx], al	; CONDITION: if current character of second string is different:
	jne		loopEnd					; 	Get to END

	cmp		[rdi + rcx], byte 0		; CONDITION: if current character of first string is NUL:
	je		loopEnd					;	Get to END
	cmp		[rsi + rcx], byte 0		; CONDITION: if current character of second string is NUL:
	je		loopEnd					;	Get to END

	inc		rcx						; Move forward the pointers
	jmp		loopStart				; Get to START

loopEnd:

	movzx	rax, byte [rdi + rcx]	; Get current character of first string
	movzx	rcx, byte [rsi + rcx]	; Get current character of second string
	sub		rax, rcx				; Finally get the difference
	ret								; END OF FUNCTION

