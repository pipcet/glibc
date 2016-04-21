#NO_APP
        .set __gcc_pc_update, 0
        .set __gcc_bogotics_backwards, 0
	.include "asmjs-macros.s"
	.text
	.pushsection .javascript%S,"a"
	.global __sigsetjmp
	.popsection
	.p2align 4+8
	.pushsection .javascript%S,"a"
    function f_$
	.codetextlabel __sigsetjmp
	(pc, sp, r0, r1, rpc, rfp) {
	pc = pc|0;
	sp = sp|0;
        r0 = r0|0;
        r1 = r1|0;
        rpc = rpc|0;
        rfp = rfp|0;
        var r2 = 0;
        var r3 = 0;
	var fp = 0;
	var ap = 0;
	var rp = 0;
	var i0 = 0;
	var i1 = 0;
	var i2 = 0;
	var i3 = 0;
	var f0 = 0.0;
	var f1 = 0.0;
	var f2 = 0.0;
	var f3 = 0.0;
	mainloop:
	while(1) {
	switch (pc|0) {
	.codetextlabeldeffirst __sigsetjmp
	.labeldef_debug .LFB0
	ap = sp+16|0;
	sp = sp-80|0;
	fp = sp|0;
	sp = sp-24|0;
	.labeldef_debug .LCFI0
        .codetextlabeldef .L_setjmp_0
        HEAP32[r0>>2] = rpc|0;
        HEAP32[r0+4>>2] = rfp|0;
        HEAP32[r0+8>>2] = fp+80|0;
        sp = sp-16|0;
	HEAP32[sp>>2] = ($
	.codetextlabel .LI19B
	);
        rp = f_$
        .codetextlabel __sigjmp_save
        ($
        .codetextlabel __sigjmp_save
        >>4, sp|0, r0|0, r1|0, pc|0, fp|0)|0;
        if (rp&3) {
                pc = $
                .codetextlabel .LI19B
                >>4;
                break mainloop;
        }
        .labeldef_internal .LI19B
        rv = 0;
	return fp+80|0;
	.labeldef_debug .LFE0
	.codetextlabeldeflast .ends.__sigsetjmp
 default:
	rp = sp|0;
        fp = sp|0;
	pc = HEAP32[(rp+4)>>2]>>4;
	sp = HEAP32[(rp+8)>>2]|0;
	r0 = HEAP32[(rp+16)>>2]|0;
	r1 = HEAP32[(rp+20)>>2]|0;
	r2 = HEAP32[(rp+24)>>2]|0;
	r3 = HEAP32[(rp+28)>>2]|0;
	i0 = HEAP32[(rp+32)>>2]|0;
	i1 = HEAP32[(rp+36)>>2]|0;
	i2 = HEAP32[(rp+40)>>2]|0;
	ap = HEAP32[(rp+44)>>2]|0;
	f0 = +HEAPF64[(rp+48)>>3];
	f1 = +HEAPF64[(rp+56)>>3];
	f2 = +HEAPF64[(rp+64)>>3];
	f3 = +HEAPF64[(rp+72)>>3];
	continue;
	}}
	if ((rp&3) == 1) {
		HEAP32[(fp+0)>>2] = 0xffff;
		HEAP32[(fp+4)>>2] = pc<<4;
		HEAP32[(fp+8)>>2] = sp|0;
		HEAP32[(fp+12)>>2] = 80;
		HEAP32[(fp+16)>>2] = r0|0;
		HEAP32[(fp+20)>>2] = r1|0;
		HEAP32[(fp+24)>>2] = r2|0;
		HEAP32[(fp+28)>>2] = r3|0;
		HEAP32[(fp+32)>>2] = i0|0;
		HEAP32[(fp+36)>>2] = i1|0;
		HEAP32[(fp+40)>>2] = i2|0;
		HEAP32[(fp+44)>>2] = ap|0;
		HEAPF64[(fp+48)>>3] = +f0;
		HEAPF64[(fp+56)>>3] = +f1;
		HEAPF64[(fp+64)>>3] = +f2;
		HEAPF64[(fp+72)>>3] = +f3;
	}
	return rp|0;}
	.popsection
	.pushsection .special.export,"a"
	.pushsection .javascript%S,"a"
	.ascii "f_"
	.codetextlabel __sigsetjmp
	.ascii ": f_"
	.codetextlabel __sigsetjmp
	.ascii ",\n"
	.popsection
	.section .special.define,"a"
	.pushsection .javascript%S,"a"
	.ascii "\tdeffun({name: \"f_"
	.codetextlabel __sigsetjmp
	.ascii "\", symbol: \"__sigsetjmp\", pc0: "
	.codetextlabel __sigsetjmp
	.ascii ", pc1: "
	.codetextlabel .ends.__sigsetjmp
	.ascii "});\n"
	.popsection
	.popsection
