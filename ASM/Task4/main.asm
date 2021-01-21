start:
    ; loading numbers
    ldi		r16,	10
	mov		r6,		r16

    ldi		r16,	11
	mov		r7,		r16

    ldi		r16,	12
	mov		r8,		r16

    ldi		r16,	13
	mov		r9,		r16

    ldi		r16,	14
	mov		r10,	r16

    ldi		r16,	15
	mov		r11,	r16

    ldi		r16,	16
	mov		r12,	r16

    ldi		r16,	17
	mov		r13,	r16

    ldi		r16,	18
	mov		r14,	r16

    ldi		r16,	19
	mov		r15,	r16
	
	; sum up all numbers
	add		r15,	r14
	add		r15,	r13
	add		r15,	r12
	add		r15,	r11
	add		r15,	r10
	add		r15,	r9
	add		r15,	r8
	add		r15,	r7
	add		r15,	r6

	; divide sum by 10
	ldi		r16,	10
	call	div

	rjmp start

div:
	clr		r18
	sub		r15,	r16
	inc		r18
	brcc	PC-2
	dec		r18				; quotient
	add		r15,	r16		; remainder in r15
	ret
