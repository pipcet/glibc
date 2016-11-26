#NO_APP
        .set __gcc_pc_update, 0
        .set __gcc_bogotics_backwards, 0
	.include "wasm32-macros.s"
	.text
        .pushsection .wasm.payload.code
	.global setjmp
        defun setjmp, FiiiiiiiE
        return[1]
        end
        endefun setjmp
