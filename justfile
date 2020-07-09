
setup:
  git submodule init
  git submodule update
  meson builddir
  cd src/libpe && make

build:
  cd builddir && ninja

run:
  cd builddir && ninja
  cd builddir && ./xdi

test:
  cd builddir && ninja
  cd builddir && ./xdi_tests
