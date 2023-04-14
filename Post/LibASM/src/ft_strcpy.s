; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;
;          .-.                                                          ;
;    __   /   \   __                                                    ;
;   (  `'.\   /.'`  )   LibASM - ft_strdup.s                            ;
;    '-._.(;;;)._.-'                                                    ;
;    .-'  ,`"`,  '-.                                                    ;
;   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        ;
;       //\   /         Last Updated: Sat Feb 11 19:00:29 CET 2023      ;
;      ||  '-'                                                          ;
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;

section .text

; Copy the source string into the destination string
; including the terminating NUL character
; 
; 0 - rdi	char *			Destination
; 1 - rsi	const char *	Source
; 
; Returns destination
; 
; It is undefinied behavior if the strings overleaps


global _ft_strcpy
_ft_strcpy:

	xor		rcx, rcx				; Sets counter to 0
									; `xor` is more space efficient than `mov` for this task

loopStart:

	mov		rax, [rsi + rcx]		; Get the character value of Source
	mov		[rdi + rcx], rax		; Use it to set Destination's character
									; Seems to not be possible to do it straight away

	cmp		[rsi + rcx], byte 0		; CONDITION: if current character is NUL character:
	je		loopEnd					; 	Get to END

	inc		rcx						; Move forward the pointers
	jmp		loopStart				; Get to START

loopEnd:

	mov		rax, rdi		; Sets return value with pointer of Destination
	ret						; END OF FUNCTION