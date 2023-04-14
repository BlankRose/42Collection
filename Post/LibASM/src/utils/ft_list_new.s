; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;
;          .-.                                                          ;
;    __   /   \   __                                                    ;
;   (  `'.\   /.'`  )   LibASM - ft_list_new.s                          ;
;    '-._.(;;;)._.-'                                                    ;
;    .-'  ,`"`,  '-.                                                    ;
;   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        ;
;       //\   /         Last Updated: Tue Feb 14 00:13:37 CET 2023      ;
;      ||  '-'                                                          ;
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;

extern _malloc
section .text

; Creates a new t_list structure, and emplace
; within its structure the given data
; 
; 0 - rdi	void *			data
; 
; Returns the newly created structure
; If it fails, it returns a NULL pointer instead
; and sets ErrNo to ENOMEM (Code: 12)

global _ft_list_new
_ft_list_new:

	push	rbp						; Push rbp to align the stack

	push	rdi						; Temporarily stores rdi
	mov		rdi, 16					; ARGUMENT: 2 ptrs x 8 bytes each = 16 total bytes
	call	_malloc					; FUNCTION: malloc(8)
	pop		rdi						; Restores initial state of rdi

	cmp		rax, 0					; CONDTION: if malloc fails (is NULL):
	je		errHandle				; 	Jump to error handler block

	mov		[rax], rdi				; Sets DATA pointer to function's ARGUMENT
	mov		qword [rax + 8], 0		; Sets NEXT pointer to NULL (cannot apply xor here)

	pop		rbp						; Restores initial state of rbp
	ret								; END OF FUNCTION

errHandle:

	xor		rax, rax				; Sets the return value to NULL pointer
	pop		rbp						; Restores initial state of rbp
	ret								; END OF FUNCTION