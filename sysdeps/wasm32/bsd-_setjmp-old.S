#NO_APP
        .set __gcc_pc_update, 0
        .set __gcc_bogotics_backwards, 0
	.include "wasm32-macros.s"
	.text
        .pushsection .wasm.payload.code
	.global _setjmp
        defun _setjmp, FiiiiiiiE
        .flush
        local.get $rfp
        i32.load a=2 8
        local.get $rpc
        i32.store a=2 0
        local.get $sp1
        i32.const -80
        i32.add
        local.set $sp
        local.get $r0
        local.get $rpc
        i32.store a=2 4
        local.get $r0
        local.get $rfp
        i32.store a=2 8
        local.get $r0
        local.get $sp
        i32.const 80
        i32.add
        i32.store a=2 12
        i32.const 0
        local.set $r1
        .dpc .LI7
        local.set $dpc
        i32.const 0
        local.get $sp
        local.get $r0
        local.get $r1
        local.get $rpc
        local.get $rfp
        call __sigjmp_save
        local.set $rp
        i32.const 3
        local.get $rp
        i32.and
        if[]
        throw
        end
        end
        .wasmtextlabeldpcdef .LI7
        local.get $sp
        i32.const 80
        i32.add
        return
        end
        endefun _setjmp
