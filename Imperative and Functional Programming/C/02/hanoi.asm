const disk_nr = r1
const src = r2
const dst = r3
const extra = r4

in disk_nr
in src
in dst
in extra

call hanoi

hanoi:
	cmp disk_nr, 0
	je move
		; target disk is not 0
		; move disk above target to spare peg
		; move target
		; move other disks to target
		
		push extra
		push dst
		push src
		push disk_nr
		
		; swap dst and spare
		mov r13, dst
		mov dst, extra
		mov extra, r13
		
		; move disk above target
		sub disk_nr, disk_nr, 1
		call hanoi
		
		; move target disk
		; (remember dst & spare are swapped)
		out src
		out 5
		out extra; dst
		out 5
		
		; move disks that were in the way
		mov r13, src
		mov src, dst
		mov dst, extra
		mov extra, r13
		
		call hanoi
		
		; fix s, d, x
		pop disk_nr
		pop src
		pop dst
		pop extra
		ret
	
	move:
		; target disk is on top
		out src
		out 5
		out dst
		out 5
	
	ret
ret