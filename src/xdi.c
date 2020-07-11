
#include <stdio.h>
#include <libpe/pe.h>
#include <klib/kvec.h>
#include <disasm/disasm.h>

const char* hello_world = "test_applications/hello-world.exe";

int main(void) {
  disasm_file_t f;
  disasm_file_err err = load_win64(&f, hello_world);
  if (err != disasm_ok)
    return 1;
  printf("Begin disassemble\n");
	return 0;
}
