#NO_APP
        .macro .import3 module, extname, name
        .section .str.lib,"ams",1
        .data
.ifndef __str_\name
__str_\name:
        .asciz "\extname"
.endif
.ifndef __str_\module
__str_\module:
        .asciz "\module"
.endif
        .text
        .global \name
        .pushsection .javascript%S,"a"
function f_$
        .codetextlabel \name
    (pc,sp,r0,r1,rpc,rfp) {
        pc = pc|0;
        sp = sp|0;
        r0 = r0|0;
        r1 = r1|0;
        rpc = rpc|0;
        rfp = rfp|0;
        var fp = 0;
        var rp = 0;
        var a = 0;
        mainloop:
        while(1) {
        switch (pc|0) {
        .codetextlabeldeffirst \name
        .labeldef_debug .LFB0
        .cfi_startproc
        sp = (sp|0)-16|0;
        fp = sp|0;
        rp = fp|1;
        pc = $
        .codetextlabel \name\().0
        >>4;
        break mainloop;
        .codetextlabeldef \name\().0
// 3 "import-macro-c.c" 1
        rp = foreign_extcall(
                .datatextlabel __str_\module
                |0,
                .datatextlabel __str_\name
                |0, pc|0, sp+16|0)|0;
        if (rp & 3) {
            rp = fp|1;
            pc = $
            .codetextlabel \name\().0
            >>4;
            break mainloop;
        } else {
            rp = fp|1;
            pc = $
            .codetextlabel \name\().1
            >>4;
            break mainloop;
        }
        .codetextlabeldef \name\().1
// 0 "" 2
        return fp+16|0;
        .set __asmjs_fallthrough, 0
        .cfi_endproc
        .labeldef_debug .LFE0
        .codetextlabeldeflast .ends.\name
 default:
        rp = sp|0;
        pc = HEAP32[rp+4>>2]>>4;
        sp = HEAP32[rp+8>>2]|0;
        fp = rp|0;
        continue;
        }
        {
        bogotics = (bogotics|0)-1|0;
        a = ((bp_hit)|0) | ((bogotics|0)<0);
        if ((a|0) != 0) {
                if (fp|0) {
                        rp = fp|1;
                        break mainloop;
                }
        }
        }
        }
        if ((rp & 3) == 1) {
        HEAP32[fp+0>>2] = 0x0000000f;
        HEAP32[fp+4>>2] = pc<<4;
        HEAP32[fp+8>>2] = sp|0;
        HEAP32[fp+12>>2] = 16;
        }
        return rp|0;}

        .popsection
        .p2align 4+8

        .pushsection .special.export,"a"
        .pushsection .javascript%S,"a"
        .ascii "f_"
        .codetextlabel \name
        .ascii ": f_"
        .codetextlabel \name
        .ascii ",\n"
        .popsection
        .popsection
        .pushsection .special.define,"a"
        .pushsection .javascript%S,"a"
        .ascii "\tdeffun({na"
        .ascii "me: \"f_"
        .codetextlabel \name
        .ascii "\", symbol: \"\name\", pc0: "
        .codetextlabel \name
        .ascii ", pc1: "
        .codetextlabel .ends.\name
        .ascii "});\n"
        .popsection
        .popsection
        .endm

