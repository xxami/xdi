
project('xdi', 'c', default_options: [
  'c_std=c18',
  'warning_level=3'
])

optional_gcc_args = [
  '-fstack-protector-strong'
]

compiler = meson.get_compiler('c')

foreach arg: optional_gcc_args
  if compiler.has_argument(arg)
    add_project_arguments(arg, language: 'c')
  endif
endforeach

exe_entry_point = ['src/xdi.c']

exe_src = [
  'src/cheat/xdi.c'
]

test_src = [
  'tests/xdi_tests.c'
]

test_includes = [
  include_directories('./src'),
  include_directories('./src/cheat')
]

executable('xdi', sources: exe_entry_point + exe_src)
executable('xdi_tests', sources: exe_src + test_src, include_directories: test_includes)
