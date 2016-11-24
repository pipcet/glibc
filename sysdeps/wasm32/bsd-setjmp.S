#NO_APP
        .set __gcc_pc_update, 0
        .set __gcc_bogotics_backwards, 0
	.include "wasm32-macros.s"
	.text
	.global setjmp
        defun setjmp, FlllllllE
        i64.const -16
        get_local $sp1
        i64.add
        set_local $sp
        i64.const -160
        get_local $sp
        i64.add
        set_local $sp
        get_local $sp
        set_local $fp
        get_local $r0
        i32.wrap_i64
        get_local $rpc
        call[2] $i64_store
        get_local $r0
        i64.const 8
        i64.add
        i32.wrap_i64
        get_local $pc0
        call[2] $i64_store
        get_local $r0
        i64.const 16
        i64.add
        i32.wrap_i64
        get_local $fp
        i64.const 80            ; XXX
        i64.add
        call[2] $i64_store
        i64.const 0
        set_local $r1
        i64.const 0
        get_local $sp
        get_local $r0
        get_local $r1
        get_local $rpc
        i64.const __sigjmp_save
        call[6] __sigjmp_save
        get_local $fp
        i64.const 160
        i64.add
        return[1]
        endefun setjmp
