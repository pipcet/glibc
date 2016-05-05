#NO_APP
        .set __gcc_pc_update, 0
        .set __gcc_bogotics_backwards, 0
	.include "asmjs-macros.s"
	.text
	.pushsection .javascript%S,"a"
	.global __sigsetjmp_fp
	.popsection
	.p2align 4+8
	.pushsection .javascript%S,"a"
    function f_$
	.codetextlabel __sigsetjmp_fp
	(dpc, sp, r0, r1, rpc, pc0) {
	dpc = dpc|0;
	sp = sp|0;
        r0 = r0|0;
        r1 = r1|0;
        rpc = rpc|0;
        pc0 = pc0|0;
        var r2 = 0;
        var r3 = 0;
	var fp = 0;
	var ap = 0;
	var rp = 0;
	var i0 = 0;
	var i1 = 0;
	var i2 = 0;
	var i3 = 0;
        sp = sp-16|0;
	mainloop:
	while(1) {
	switch (dpc|0) {
	.codetextlabeldeffirst __sigsetjmp_fp
	.labeldef_debug .LFB0
	ap = sp+16|0;
	sp = sp-80|0;
	fp = sp|0;
	sp = sp-24|0;
	.labeldef_debug .LCFI0
        .codetextlabeldef .L_setjmp_0
        foreign_abort(-1|0, rpc|0, a0|0, r0|0, fp|0);
        foreign_abort(-1|0, HEAP32[a0>>2]|0, HEAP32[a0+4>>2]|0, HEAP32[a0+8>>2]|0, HEAP32[a0+12>>2]|0);
        HEAP32[r0>>2] = rpc|0;
        HEAP32[r0+4>>2] = a0|0;
        HEAP32[r0+8>>2] = fp+80|0;
        dpc = $
        .dpc .LI19B
        ;
        rp = f_$
        .codetextlabel __sigjmp_save
        (0, sp|0, r0|0, r1|0, (dpc+pc0)|0, $
        .codetextlabel __sigjmp_save
        )|0;
        if (rp&3) {
                break mainloop;
        }
        .labeldef_internal .LI19B
        rv = 0;
	return fp+80|0;
	.labeldef_debug .LFE0
	.codetextlabeldeflast .ends.__sigsetjmp_fp
 default:
	rp = sp|0;
        fp = sp|0;
	sp = HEAP32[(rp+8)>>2]|0;
	r0 = HEAP32[(rp+16)>>2]|0;
	r1 = HEAP32[(rp+20)>>2]|0;
	r2 = HEAP32[(rp+24)>>2]|0;
	r3 = HEAP32[(rp+28)>>2]|0;
	i0 = HEAP32[(rp+32)>>2]|0;
	i1 = HEAP32[(rp+36)>>2]|0;
	i2 = HEAP32[(rp+40)>>2]|0;
	ap = HEAP32[(rp+44)>>2]|0;
	continue;
	}}
	if ((rp&3) == 1) {
		HEAP32[(fp+0)>>2] = 0xffff;
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
	}
	return rp|0;}
	.popsection
	.pushsection .special.export,"a"
	.pushsection .javascript%S,"a"
	.ascii "f_"
	.codetextlabel __sigsetjmp_fp
	.ascii ": f_"
	.codetextlabel __sigsetjmp_fp
	.ascii ",\n"
	.popsection
	.section .special.define,"a"
	.pushsection .javascript%S,"a"
	.ascii "\tdeffun({name: \"f_"
	.codetextlabel __sigsetjmp_fp
	.ascii "\", symbol: \"__sigsetjmp_fp\", pc0: "
	.codetextlabel __sigsetjmp_fp
	.ascii ", pc1: "
	.codetextlabel .ends.__sigsetjmp_fp
	.ascii "});\n"
	.popsection
	.popsection
