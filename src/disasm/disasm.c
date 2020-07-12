
#include <disasm/disasm.h>

disasm_err load_win64_pe(disasm_file_t *f, const char *file_name) {
  f->eof = 0;
  f->ins_offset = 0;
  pe_options_e options = LIBPE_OPT_NOCLOSE_FD;
  pe_err_e err = pe_load_file_ext(&f->pef, file_name, (1 << 0));
  if (err != LIBPE_E_OK) {
    if (err == LIBPE_E_FDOPEN_FAILED) {
      printf("FSTAT FAILED");
    }
    printf("Failed to load file: %s\n", file_name);
    printf("Possible I/O error in libpe\n");
    return disasm_load_err;
  }
  err = pe_parse(&f->pef);
  if (err != LIBPE_E_OK) {
    printf("Unable to parse file: %s\n", file_name);
    printf("Is this a valid PE file?\n");
    return disasm_parse_err;
  }
  if (!pe_is_pe(&f->pef)) {
    printf("PE format not detected in file: %s\n", file_name);
    return disasm_invalid_format;
  }
  printf("Valid PE file detected\n"); 
  printf("Entry point found at: %#lx\n", (long int) f->pef.pe.entrypoint);
  f->ins_offset = (long int) f->pef.pe.entrypoint;
  if (f->pef.stream == NULL) {
    printf("File stream closed unexpectedly\n");
    return disasm_stream_closed;
  }
  err = fseek(f->pef.stream, f->ins_offset, SEEK_SET);
  if (err != 0) {
    printf("Seek error in file stream");
    return disasm_seek_err;
  }
  return disasm_ok;
}

disasm_err disasm_step(disasm_file_t *f, disasm_instruction_t *ins) {
  ins->opcode = x64_op_undefined;
  if (f->eof)
    return disasm_eof_err;
  char c[15];
  for (int i = 0; i < 15; i++) {
    c[i] = fgetc(f->pef.stream);
    printf("Parsed instruction byte: %x\n", c[i] & 0xff);
    if (feof(f->pef.stream)) {
      f->eof = 1;
      break;
    }
  }
  return disasm_ok;
}
