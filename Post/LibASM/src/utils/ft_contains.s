; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;
;          .-.                                                          ;
;    __   /   \   __                                                    ;
;   (  `'.\   /.'`  )   LibASM - ft_contains.s                          ;
;    '-._.(;;;)._.-'                                                    ;
;    .-'  ,`"`,  '-.                                                    ;
;   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        ;
;       //\   /         Last Updated: Sun Feb 12 19:40:43 CET 2023      ;
;      ||  '-'                                                          ;
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;

section .text

; Searches if the given character is contained within
; the set of character (excluding '\0')
; 
; 0 - rdi	const char *	Character set
; 1 - rsi	char			Target character
; 
; Returns the index where the character is located in the set
; If it couldn't be found, it returns -1


global _ft_contains
_ft_contains:

	xor		rax, rax				; Initializes counter to 0

loopStart:

	cmp		[rdi + rax], byte 0		; CONDITION: if current character is NUL:
	je		loopEndNotFound			; 	Get to END NOT FOUND

	cmp		[rdi + rax], rsi		; CONDITION: if current character is target character:
	je		loopEndFound			; 	Get to END FOUND

	inc		rax						; Move forward the pointer
	jmp		loopStart				; Get to START

loopEndNotFound:

	mov		rax, -1					; Set return value to -1
									; FALLTHROUGH

loopEndFound:

	ret								; END OF FUNCTION