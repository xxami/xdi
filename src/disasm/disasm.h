#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <libpe/pe.h>

typedef enum disasm_file_err {
  disasm_load_err = 0,
  disasm_parse_err = 1,
  disasm_invalid_format = 2,
  disasm_ok = 3
} disasm_file_err;

typedef struct {
  pe_ctx_t pef;
} disasm_file_t;

// parse PE executable, and prepare for reading disassembly
disasm_file_err load_win64(disasm_file_t* f, const char *file_name);

