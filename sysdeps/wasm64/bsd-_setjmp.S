#NO_APP
        .set __gcc_pc_update, 0
        .set __gcc_bogotics_backwards, 0
	.include "wasm64-macros.s"
	.text
	.pushsection .javascript%S,"a"
	.global _setjmp
	.popsection
	.p2align 4+8
	.pushsection .javascript%S,"a"
(
        .wasmtextlabeldeffirst _setjmp
        .ascii "\""
        f_$
        .textlabel _setjmp
        .ascii "\""

        (block
		(i64.store (i64.add (get_local $fp) (i64.const 0)) (i64.add (get_local $fp) (i64.const 96)))
		(i64.store (i64.add (get_local $fp) (i64.const 8)) (i64.shl (get_local $pc0) (i64.const 4)))
		(i64.store (i64.add (get_local $fp) (i64.const 16)) (i64.shl (i64.add (get_local $pc0) (get_local $dpc)) (i64.const 4)))
		(i64.store (i64.add (get_local $fp) (i64.const 24)) (get_local $rpc))
		(i64.store (i64.add (get_local $fp) (i64.const 32)) (get_local $sp))
		(i64.store (i64.add (get_local $fp) (i64.const 40)) (i64.const 1008))
		(i64.store (i64.add (get_local $fp) (i64.const 48)) (get_local $r0))
		(i64.store (i64.add (get_local $fp) (i64.const 56)) (get_local $r1))
		(i64.store (i64.add (get_local $fp) (i64.const 64)) (get_local $r2))
		(i64.store (i64.add (get_local $fp) (i64.const 72)) (get_local $r3))
		(i64.store (i64.add (get_local $fp) (i64.const 80)) (get_local $r4))
		(i64.store (i64.add (get_local $fp) (i64.const 88)) (get_local $r5))
	)
	(set $sp (i64.add (get_local $sp1) (i64.const -16)))
	.labeldef_debug .LFB0
	(set $sp (i64.add (get_local $sp) (i64.const -160)))
	(set $fp (get_local $sp))
        (i64.store (get_local $r0) (get_local $rpc))
        (i64.store (i64.add (get_local $r0) (i64.const 8)) (get_local $pc0))
        (i64.store (i64.add (get_local $r0) (i64.const 16)) (i64.add (get_local $fp) (i64.const 80)))
        (set_local $r1 (i64.const 0))
        (set_local $rp (call f_$
        .ncodetextlabel __sigjmp_save
        (i64.const 0) (get_local $sp) (get_local $r0) (get_local $r1) (get_local $rpc)
        .ncodetextlabel __sigjmp_save
        ))
        (if (i64.and (get_local $rp) (i64.const 3)) (br $mainloop))
	(return (i64.add (get_local $fp) (i64.const 160)))
	.set __wasm_fallthrough, 0
	.labeldef_debug .LFE0
	.wasmtextlabeldeflast .ends._setjmp
	(set_local $rp (get_local $sp))
		(set_local $pc0 (i64.shr_u (i64.load (i64.add (get_local $rp) (i64.const 4))) (i64.const 4)))
		(set_local $dpc (i64.sub (i64.shr_u (i64.load (i64.add (get_local $rp) (i64.const 16))) (i64.const 4)) (get_local $pc0)))
		(set_local $rpc (i64.load (i64.add (get_local $rp) (i64.const 24))))
		(set_local $sp (i64.load (i64.add (get_local $rp) (i64.const 32))))
		(set_local r0 (i64.load (i64.add (get_local $rp) (i64.const 48))))
		(set_local r1 (i64.load (i64.add (get_local $rp) (i64.const 56))))
		(set_local r2 (i64.load (i64.add (get_local $rp) (i64.const 64))))
		(set_local r3 (i64.load (i64.add (get_local $rp) (i64.const 72))))
		(set_local r4 (i64.load (i64.add (get_local $rp) (i64.const 80))))
		(set_local r5 (i64.load (i64.add (get_local $rp) (i64.const 88))))
	(set_local $fp (get_local $rp))
)
