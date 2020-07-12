#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <libpe/pe.h>

typedef enum disasm_err {
  disasm_load_err,
  disasm_parse_err,
  disasm_invalid_format,
  disasm_seek_err,
  disasm_eof_err,
  disasm_stream_closed,
  disasm_ok
} disasm_err;

typedef enum x64_opcode {
  x64_op_undefined,
  x64_op_call,
} x64_opcode;

typedef struct {
  pe_ctx_t pef;
  long int ins_offset;
  int eof;
} disasm_file_t;

typedef struct {
  x64_opcode opcode;
} disasm_instruction_t;

// parse PE executable, and prepare for reading disassembly
disasm_err load_win64_pe(disasm_file_t *f, const char *file_name);

// parse the next instruction starting at code entry point
disasm_err disasm_step(disasm_file_t *f, disasm_instruction_t *ins);
