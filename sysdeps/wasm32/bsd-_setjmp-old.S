#NO_APP
        .set __gcc_pc_update, 0
        .set __gcc_bogotics_backwards, 0
	.include "wasm32-macros.s"
	.text
        .pushsection .wasm.payload.code
	.global _setjmp
        defun _setjmp, FiiiiiiiE
        .flush
        get_local $rfp
        i32.load a=2 8
        get_local $rpc
        i32.store a=2 0
        get_local $sp1
        i32.const -80
        i32.add
        set_local $sp
        get_local $r0
        get_local $rpc
        i32.store a=2 4
        get_local $r0
        get_local $rfp
        i32.store a=2 8
        get_local $r0
        get_local $sp
        i32.const 80
        i32.add
        i32.store a=2 12
        i32.const 0
        set_local $r1
        .dpc .LI7
        set_local $dpc
        i32.const 0
        get_local $sp
        get_local $r0
        get_local $r1
        get_local $rpc
        get_local $rfp
        call __sigjmp_save
        set_local $rp
        i32.const 3
        get_local $rp
        i32.and
        if[]
        throw1
        end
        end
        .wasmtextlabeldpcdef .LI7
        get_local $sp
        i32.const 80
        i32.add
        return
        end
        endefun _setjmp
