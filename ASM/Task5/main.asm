start:
    ;ldi		r16,	8
	;ldi		r17,	3
	;call	u_mul

	ldi		r16,	-4
	ldi		r17,	5
	call	s_mul		; -20 == 1111 1111 1110 1100
    rjmp	start


u_mul:
	; r16 - mutiplicand
	; r17 - multiplier / result low
	; r18 - result high
	clr		r18			; clear result high byte
	ldi		r19,	8	; set loop counter
	lsr		r17			; rotate multiplier
u1:
	brcc	u2				; if carry is clear, go to u2..
	add		r18,	r16		; ..else add multiplicand to result high byte
u2:
	ror		r18		; rotate result high byte
	ror		r17		; rotate result low / multiplier
	dec		r19		; decrement counter
	brne	u1		; if zero is not set, go to u1
	ret


s_mul:
	; r16 - multiplicand
	; r17 - multiplier / result low byte
	; r18 - result high byte
	clr		r18			; clear result high
	ldi		r19,	8	; set loop counter
s1:
	brcc	s2				; if carry is clear, go to s2..
	add		r18,	r16		; ..else add multiplicant to result high byte
s2:
	sbrc	r17,	0		; pass if 0 bit of r17 is set..
	sub		r18,	r16		; ..else subtract multiplicand from result high byte
	asr		r18			; shift right result high byte
	ror		r17			; rotate result low / multiplier
	dec		r19			; decrement loop count
	brne	s1			; if zero if not set, go to s1
	ret