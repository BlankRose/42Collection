; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;
;          .-.                                                          ;
;    __   /   \   __                                                    ;
;   (  `'.\   /.'`  )   LibASM - ft_write.s                             ;
;    '-._.(;;;)._.-'                                                    ;
;    .-'  ,`"`,  '-.                                                    ;
;   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        ;
;       //\   /         Last Updated: Fri Apr 14 12:24:36 CEST 2023     ;
;      ||  '-'                                                          ;
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;

extern ___error
section .text

; Write out the given buffer on the terminal
; 
; 0 - rdi	int				file descriptor
; 1 - rsi	const void *	buffer to write
; 2 - rdx	size_t			number of bytes to write
; 
; Returns number of bytes written
; Upon error, it returns -1 and errno is set


global _ft_write
_ft_write:

	mov		rax, 0x2000004	; Define the target system call
	syscall					; Others variables for this system call
							; is already given in this function's params

							; CONDITION: if carry flag is set (defined by SYSCALL):
	jc		errHandle		;	Get to ERROR
	ret						; END OF FUNCTION

errHandle:

	mov		r8, rax			; Store return value (RCX is used by ___error)
	push	r8				; Push R8 on the stack for alignement
	call	___error 		; Get the pointer to ErrNo
	pop		r8				; Pop out R8
	mov		[rax], r8		; Move stored data inside pointer

	mov		rax, -1			; Set return value to -1
	ret						; END OF SECTION