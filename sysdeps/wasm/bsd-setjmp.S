#NO_APP
        .set __gcc_pc_update, 0
        .set __gcc_bogotics_backwards, 0
	.include "wasm-macros.s"
	.text
	.pushsection .javascript%S,"a"
	.global setjmp
	.popsection
	.p2align 4+8
	.pushsection .javascript%S,"a"
(
        .wasmtextlabeldeffirst setjmp
        .ascii "\""
        f_$
        .textlabel setjmp
        .ascii "\""

        (block
		(i32.store (i32.add (get_local $fp) (i32.const 0)) (i32.add (get_local $fp) (i32.const 48)))
		(i32.store (i32.add (get_local $fp) (i32.const 4)) (i32.shl (get_local $pc0) (i32.const 4)))
		(i32.store (i32.add (get_local $fp) (i32.const 8)) (i32.shl (i32.add (get_local $pc0) (get_local $dpc)) (i32.const 4)))
		(i32.store (i32.add (get_local $fp) (i32.const 12)) (get_local $rpc))
		(i32.store (i32.add (get_local $fp) (i32.const 16)) (get_local $sp))
		(i32.store (i32.add (get_local $fp) (i32.const 20)) (i32.const 1008))
		(i32.store (i32.add (get_local $fp) (i32.const 24)) (get_local $r0))
		(i32.store (i32.add (get_local $fp) (i32.const 28)) (get_local $r1))
		(i32.store (i32.add (get_local $fp) (i32.const 32)) (get_local $r2))
		(i32.store (i32.add (get_local $fp) (i32.const 36)) (get_local $r3))
		(i32.store (i32.add (get_local $fp) (i32.const 40)) (get_local $r4))
		(i32.store (i32.add (get_local $fp) (i32.const 44)) (get_local $r5))
	)
	(set $sp (i32.add (get_local $sp1) (i32.const -16)))
	.labeldef_debug .LFB0
	(set $sp (i32.add (get_local $sp) (i32.const -80)))
	(set $fp (get_local $sp))
        (i32.store (get_local $r0) (get_local $rpc))
        (i32.store (i32.add (get_local $r0) (i32.const 4)) (get_local $pc0))
        (i32.store (i32.add (get_local $r0) (i32.const 8)) (i32.add (get_local $fp) (i32.const 80)))
        (set_local $r1 (i32.const 0))
        (set_local $rp (call f_$
        .ncodetextlabel __sigjmp_save
        (i32.const 0) (get_local $sp) (get_local $r0) (get_local $r1) (get_local $rpc)
        .ncodetextlabel __sigjmp_save
        ))
        (if (i32.and (get_local $rp) (i32.const 3)) (br $mainloop))
	(return (i32.add (get_local $fp) (i32.const 80)))
	.set __wasm_fallthrough, 0
	.labeldef_debug .LFE0
	.wasmtextlabeldeflast .ends.funcall
	(set_local $rp (get_local $sp))
		(set_local $pc0 (i32.shr_u (i32.load (i32.add (get_local $rp) (i32.const 4))) (i32.const 4)))
		(set_local $dpc (i32.sub (i32.shr_u (i32.load (i32.add (get_local $rp) (i32.const 8))) (i32.const 4)) (get_local $pc0)))
		(set_local $rpc (i32.load (i32.add (get_local $rp) (i32.const 12))))
		(set_local $sp (i32.load (i32.add (get_local $rp) (i32.const 16))))
		(set_local r0 (i32.load (i32.add (get_local $rp) (i32.const 24))))
		(set_local r1 (i32.load (i32.add (get_local $rp) (i32.const 28))))
		(set_local r2 (i32.load (i32.add (get_local $rp) (i32.const 32))))
		(set_local r3 (i32.load (i32.add (get_local $rp) (i32.const 36))))
		(set_local r4 (i32.load (i32.add (get_local $rp) (i32.const 40))))
		(set_local r5 (i32.load (i32.add (get_local $rp) (i32.const 44))))
	(set_local $fp (get_local $rp))
)
