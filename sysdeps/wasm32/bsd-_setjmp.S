#NO_APP
        .set __gcc_pc_update, 0
        .set __gcc_bogotics_backwards, 0
	.include "wasm32-macros.s"
	.text
	.global _setjmp
        defun _setjmp, FiiiiiiiE
        return[1]
        end
        endefun _setjmp
