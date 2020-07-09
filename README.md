# xdi

```sh
# install libpe
git submodule init
git submodule update

# build libpe
cd src/libpe
make

# return to base directory
cd ../..

# create meson build directory
# one time only
meson build

# build
cd build
ninja

# run
./xdi
./xdi_tests
```
