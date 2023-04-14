; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;
;          .-.                                                          ;
;    __   /   \   __                                                    ;
;   (  `'.\   /.'`  )   LibASM - ft_atoi_base.s                         ;
;    '-._.(;;;)._.-'                                                    ;
;    .-'  ,`"`,  '-.                                                    ;
;   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        ;
;       //\   /         Last Updated: Thu Apr 13 18:22:57 CEST 2023     ;
;      ||  '-'                                                          ;
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;

section .text

; Converts an string representation of a given
; base to its corresponding integer representation
; or until the string is not part of the base
; 
; 0 - rdi	char *			String to convert
; 1 - rsi	char *			Base of the representation
; 
; Returns its integer representation
; Upon error, it returns 0 if the arguments are invalid


global _ft_atoi_base
_ft_atoi_base:

	push	rbx						; Stores initial state of RBX

	xor		rax, rax				; Set total to 0
	xor		rbx, rbx				; Set sign to 0, aka POSITIVE
	mov		rcx, -1					; Set length to -1

	test	rdi, rdi				; CONDITION: If STRING is NULL:
	jz		loopEnd					; 	Get to END
	test	rsi, rsi				; CONDITION: If STRING is NULL:
	jz		loopEnd					; 	Get to END

loopCheckStart:

	inc		rcx						; Move forward length counter
	cmp		[rsi + rcx], byte 0		; CONDITION: If current character is NUL:
	jz		loopCheckEnd			; 	Get to CHECK END

									; GLOBAL CONDITION:
									; 	if (is_space() OR is_sign()): Get to END

	cmp		[rsi + rcx], byte 9		; CONDITION: If current character is HT (\t):
	je		loopEnd					; 	Get to END
	cmp		[rsi + rcx], byte 10	; CONDITION: If current character is NL (\n):
	je		loopEnd					; 	Get to END
	cmp		[rsi + rcx], byte 11	; CONDITION: If current character is VT (\v):
	je		loopEnd					; 	Get to END
	cmp		[rsi + rcx], byte 12	; CONDITION: If current character is NP (\f):
	je		loopEnd					; 	Get to END
	cmp		[rsi + rcx], byte 13	; CONDITION: If current character is CR (\r):
	je		loopEnd					; 	Get to END
	cmp		[rsi + rcx], byte 32	; CONDITION: If current character is SP ( ):
	je		loopEnd					; 	Get to END
	cmp		[rsi + rcx], byte 43	; CONDITION: If current character is +:
	je		loopEnd					; 	Get to END
	cmp		[rsi + rcx], byte 45	; CONDITION: If current character is -:
	je		loopEnd					; 	Get to END

	mov		r8, rcx					; Set search index to current
	inc		r8						; Move forward search index

loopCheckDup:

	cmp		[rsi + r8], byte 0		; CONDITION: If current character is NUL:
	jz		loopCheckStart			; 	Get to CHECK START

	mov		r9b, [rsi + r8]			; Retrieve current character
	cmp		[rsi + rcx], byte r9b	; CONDITION: If current character is searched:
	je		loopEnd					; 	Get to END

	inc		r8						; Move forward search index
	jmp		loopCheckDup			; Get to CHECK DUP

loopCheckEnd:

	cmp		rcx, 1					; CONDITION: If length is 1 or less:
	jle		loopEnd					; 	Get to END
	mov		r8, -1					; Set index to -1

loopWhitespace:

	inc		r8						; Move forward index
	cmp		[rdi + r8], byte 0		; CONDITION: If current character is NUL:
	je		loopEnd					; 	Get to END

									; GLOBAL CONDITION:
									; 	while (is_space()): Continue

	cmp		[rdi + r8], byte 9		; CONDITION: If current character is HT (\t):
	je		loopWhitespace			; 	Skip and continue
	cmp		[rdi + r8], byte 10		; CONDITION: If current character is NL (\n):
	je		loopWhitespace			; 	Skip and continue
	cmp		[rdi + r8], byte 11		; CONDITION: If current character is VT (\v):
	je		loopWhitespace			; 	Skip and continue
	cmp		[rdi + r8], byte 12		; CONDITION: If current character is NP (\f):
	je		loopWhitespace			; 	Skip and continue
	cmp		[rdi + r8], byte 13		; CONDITION: If current character is CR (\r):
	je		loopWhitespace			; 	Skip and continue
	cmp		[rdi + r8], byte 32		; CONDITION: If current character is SP ( ):
	je		loopWhitespace			; 	Skip and continue
	jmp		loopSign				; ELSE: Get to SIGNS

negative:
	xor		bl, 1					; Reverse stored SIGN
positive:
	inc		r8						; Move forward index

loopSign:

	cmp		[rdi + r8], byte 43		; CONDITION: If current character is '+':
	je		positive				; 	Get to POSITIVE
	cmp		[rdi + r8], byte 45		; CONDITION: If current character is '-':
	je		negative				; 	Get to NEGATIVE

loopMath:

	cmp		[rdi + r8], byte 0		; CONDITION: If current character is NUL:
	je		applySign				; 	Get to END
	mov		r9, -1					; Set search index to -1

loopLookUp:

	inc		r9						; Move forward search index
	mov		r10b, byte [rsi + r9]	; Retrieve current character

	cmp		r10b, byte 0			; CONDITION: If current character is NUL:
	je		applySign				; 	Get to END
	cmp		[rdi + r8], byte r10b	; CONDITION: If current character is not searched:
	jne		loopLookUp				; 	Get to LOOKUP

	mul		rcx						; Multiply result by length
	add		rax, r9					; Add position to result

	inc		r8						; Move forward index
	jmp		loopMath				; Get to MATHS

applySign:

	cmp		rbx, 0					; CONDITION: If POSITIVE:
	jz		loopEnd					; 	Get to END
	neg		rax						; ELSE: Negate result

loopEnd:

	pop		rbx						; Restores initial state of RBX
	ret								; END OF FUNCTION
