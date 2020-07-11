
#include <stdio.h>
#include <libpe/pe.h>
#include <klib/kvec.h>
#include <disasm/disasm.h>

const char* hello_world = "test_applications/hello-world.exe";

int main(void) {
  pe_ctx_t ctx;
  pe_err_e err = pe_load_file(&ctx, hello_world);
  if (err != LIBPE_E_OK) {
    pe_error_print(stderr, err);
    return 1;
  }

  err = pe_parse(&ctx);
  if (err != LIBPE_E_OK) {
    pe_error_print(stderr, err);
    return 1;
  }

  if (!pe_is_pe(&ctx)) {
    printf("Unexpected error parsing PE file");
    return 1;
  }

  printf("Entrypoint: %#lx\n", ctx.pe.entrypoint);
	return 0;
}
