
#include <disasm/disasm.h>

disasm_err load_win64(disasm_file_t *f, const char *file_name) {
  pe_err_e err = pe_load_file(&f->pef, file_name);
  if (err != LIBPE_E_OK) {
    printf("Failed to load file: %s\n", file_name);
    printf("Possible io error");
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
  printf("Entry point found at: %#lx\n", (long unsigned int) f->pef.pe.entrypoint);
  f->ins_offset = (long int) &f->pef.pe.entrypoint;
  err = fseek(f->pef.stream, f->ins_offset, SEEK_SET);
  if (err != 0) {
    printf("Seek error in file stream");
    return disasm_seek_err;
  }
  return disasm_ok;
}

disasm_err disasm_step_once(disasm_file_t *f, disasm_instruction_t *ins) {
  if (f->eof)
    return disasm_eof_err;
  char c[15];
  for (int i = 0; i < 15; i++) {
    c[i] = fgetc(f->pef.stream);
    printf("Parsed instruction byte: %x\n", c[i]);
    if (feof(f->pef.stream)) {
      f->eof = 1;
      break;
    }
  }
}
