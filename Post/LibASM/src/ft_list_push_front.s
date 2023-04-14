; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;
;          .-.                                                          ;
;    __   /   \   __                                                    ;
;   (  `'.\   /.'`  )   LibASM - ft_list_push_front.s                   ;
;    '-._.(;;;)._.-'                                                    ;
;    .-'  ,`"`,  '-.                                                    ;
;   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        ;
;       //\   /         Last Updated: Tue Feb 14 00:14:02 CET 2023      ;
;      ||  '-'                                                          ;
; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;

extern _ft_list_new
section .text

; Creates and emplace a list at the front
; of the list and update the begin pointer
; 
; 0 - rdi	t_list **		Begin of the list
; 1 - rsi	void *			New list's content
; 
; Upon error, the begin pointer is now updated


global _ft_list_push_front
_ft_list_push_front:

	push	rbp				; Push rbp to align the stack

	push	rdi				; Temporarily stores rdi
	mov		rdi, rsi		; Move new list's content as first argument
	call	_ft_list_new	; Call the function to allocate the new list
	pop		rdi				; Restores initial state of rdi

	cmp		rax, 0			; CONDITION: if creation failed (NULL):
	je		errHandle		; 	Jump to error handler block

	mov		rcx, [rdi]		; Stores within rcx current TOP
	mov		[rax + 8], rcx	; Emplace current TOP within the NEXT
	mov		[rdi], rax		; Set current TOP to the new list
							; FALLTHROUGH

errHandle:

	pop		rbp				; Restores stack alignement
	ret						; END OF FUNCTION