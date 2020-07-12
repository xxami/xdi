
#include <stdio.h>
#include <libpe/pe.h>
#include <klib/kvec.h>
#include <disasm/disasm.h>

const char* hello_world = "tests/test_applications/hello-world.exe";

int main(void) {
  disasm_file_t f;
  disasm_err err = load_win64(&f, hello_world);
  if (err != disasm_ok)
    return 1;
  printf("Begin disassemble\n");
  err = disasm_step_once(&f);
  if (err != disasm_ok)
    return 1;
  printf("Successfully stepped once\n");
  return 0;
}
