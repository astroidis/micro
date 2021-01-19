m:
	;call	pp1
	call	pp2
	call	pp3
	jmp		m

pp1:
	ldi		r16,	10		; load dec constant
	ldi		r17,	0x10	; load hex constant 
	ldi		r18,	0x20
	ldi		r19,	0x30
	mov		r1,		r16
	mov		r2,		r17
	mov		r3,		r18
	mov		r4,		r19
	ldi		xh,		0x01	; higher part of x address
	ldi		xl,		0x60	; lower part of x address
	st		x+,		r1		; load data from registers to ram
	st		x+,		r2
	st		x+,		r3
	st		x+,		r4
	ld		r10,	-x		; reading data at 0x0163
	sts		0x0070,	r16
	lds		r5,		0x0060
	push	r1
	push	r2
	push	r3
	push	r4
	pop		r14
	pop		r13
	pop		r12
	pop		r11
	ret
	
pp2:
	; A = N * 7 (N = 11)
	.EQU	N = 11
	ldi		r16,	N	; load N
	ldi		r17,	7
	mul		r16,	r17
	
	ldi		xh,		0x01
	ldi		xl,		0x60
	st		x+,		r0	; move result to 0x0160 and inc x

	; B = (N * 3) mod 21
	ldi		r16,	N
	ldi		r17,	3
	mul		r16,	r17
	mov		r17,	r0
	ldi		r16,	21
	call	div
	st		x+,		r17

	; C = 35
	ldi		r16,	35
	st		x+, 	r16

	; D = 71 mod N
	ldi		r16,	71 % N
	st		x,		r16

	ret

div:
	clr		r18
	sub		r17,	r16
	inc		r18
	brcc	PC-2
	dec		r18				; quotient
	add		r17,	r16		; remainder in r17
	ret

pp3:
	ldi		xh,		0x01
	ldi		xl,		0x60

	ld		r1,		x+
	ld		r2,		x+
	ld		r3,		x+
	ld		r4,		x

	push	r4
	push	r3
	push	r2
	push	r1

	pop		r11
	pop		r12
	pop		r13
	pop		r14
	
	ret
