; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;
;          .-.                                                          ;
;    __   /   \   __                                                    ;
;   (  `'.\   /.'`  )   LibASM - ft_strdup.s                            ;
;    '-._.(;;;)._.-'                                                    ;
;    .-'  ,`"`,  '-.                                                    ;
;   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        ;
;       //\   /         Last Updated: Mon Feb 13 22:09:46 CET 2023      ;
;      ||  '-'                                                          ;
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;

extern _malloc
extern _ft_strlen
extern _ft_strcpy

section .text

; Allocates and duplicates any given string
; and returns it
; 
; 0 - rdi	const char *	String to duplicate
; 
; Returns a duplicate of the string
; If it fails, it returns a NULL pointer instead
; and sets ErrNo to ENOMEM (Code: 12)

global _ft_strdup
_ft_strdup:

	push	rbp				; Push rbp to align the stack
	mov		rbp, rsp		; Ensures stack alignement using rsp

	call	_ft_strlen		; Call ft_strlen function to get amount of memory to allocate
							; Its arguement is already stored in `rdi` registry

	push	rsi				; Temporarily stores rsi
	push	rdi				; Temporarily stores rdi

	mov		rdi, rax		; Set return value of strlen into argument for malloc
	inc		rdi				; Increment by one for the NUL terminating character
	call	_malloc			; Finally call the MALLOC function

	cmp		rax, 0			; CONDTION: if malloc fails (is NULL):
	je		errHandle		; 	Jump to error handler block

	mov		rdi, rax		; Move allocated pointer to first argument
	pop		rsi				; Emplace back into second argument
	call	_ft_strcpy		; Finally call the FT_STRCPY function

	mov		rdi, rsi		; Emplace back Source string
	pop		rsi				; Restores initial state of rsi
	pop		rbp				; Restores stack pointer
	ret						; END OF FUNCTION

errHandle:

	xor		rax, rax		; Sets the return value to NULL pointer

	pop		rdi				; Emplace back (emptying used stack)
	pop		rsi				; Restores initial state of rsi
	pop		rbp				; Restores stack pointer
	ret						; END OF FUNCTION