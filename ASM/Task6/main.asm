start:
	.def	A	= r20
	.def	C	= r21
	.def	D	= r22

	ldi		A,	27
	ldi		C,	35
	ldi		D,	5
	
	; (A + [0x0150]) * 2
	lds		r15,	0x0150
	add		A,		r15
	lsl		A
	
	; (C * 0x05)
	ldi		r16,	0x05
	mul		C,		r16
	mov		C,		r0

	; (0xAA & D)
	andi	D,		0xAA

	add		D,		A
	adc		D,		C

	; compare previous sum with contet of [0x0160]
	; result is the greater of these two values
	; will be saved in D
	lds		r15,	0x0160
	cp		D,		r15
	brcc	end				; if r15 > D then go to end
	mov		D,	r15		
		
end:
    rjmp start

