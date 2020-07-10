## xdi

## build reqs
- modern c compiler (ie. gcc 10+)
- meson: https://mesonbuild.com/
- ninja: https://ninja-build.org/

## optional
- just: https://github.com/casey/just

```sh
# prepare submodules & dependencies
just setup
# build with meson/ninja
just build
# run
just run
```

## testing
```sh
# cross compile w64 test applications
cd test_applications
just build-w64
cd ..

# run tests
just test
```

*(if not using just, build using standard meson workflow)*