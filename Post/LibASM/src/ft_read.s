; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;
;          .-.                                                          ;
;    __   /   \   __                                                    ;
;   (  `'.\   /.'`  )   LibASM - ft_read.s                              ;
;    '-._.(;;;)._.-'                                                    ;
;    .-'  ,`"`,  '-.                                                    ;
;   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        ;
;       //\   /         Last Updated: Fri Apr 14 12:24:53 CEST 2023     ;
;      ||  '-'                                                          ;
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;

extern ___error
section .text

; Read from a target FD and stores within the given buffer
; 
; 0 - rdi	int				file description
; 1 - rsi	void *			buffer to store
; 2 - rdx	size_t			number of bytes to read
; 
; Returns number of bytes read
; 0 usually means no more to read
; Upon error, it returns -1 and errno is set

global _ft_read
_ft_read:

	mov		rax, 0x2000003	; Define the target system call	syscall
	syscall					; Others variables for this system call
							; is already given in this function's params

							; CONDITION: if carry flag is set (defined by SYSCALL):
	jc		errHandle		;	Get to ERROR
	ret						; END OF FUNCTION

errHandle:

	mov		r8, rax			; Stores return value (RCX is used by ___error)
	push	r8				; Push R8 on the stack for alignement
	call	___error 		; Get the pointer to ErrNo
	pop		r8				; Pop out R8
	mov		[rax], r8		; Move stored data inside pointer

	mov		rax, -1			; Set return value to -1
	ret						; END OF SECTION