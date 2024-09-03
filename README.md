Embedded format
===============

```
$ cmake -S . -B build
$ cmake --build build
```

Original size:

```
$ l build/experiment 
332K -rwxrwxr-x 1 ghawkins ghawkins 330K Sep  3 21:24 build/experiment*
```

After adding `-static`:

```
$ l build/experiment 
2.6M -rwxrwxr-x 1 ghawkins ghawkins 2.6M Sep  3 21:27 build/experiment*
```

Optimizing for size:

```
$ cmake -DCMAKE_BUILD_TYPE=MinSizeRel -S . -B build
$ cmake --build build
$ ls -Flas build/experiment 
2440 -rwxrwxr-x 1 ghawkins ghawkins 2495520 Sep  3 21:34 build/experiment*
```

Optimizing to `O3` level:

```
$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
$ cmake --build build
$ ls -Flas build/experiment 
2472 -rwxrwxr-x 1 ghawkins ghawkins 2528704 Sep  3 21:37 build/experiment*
```

With nothing but `std::puts("3")` and `MinSizeRel`:

```
$ ls -Flas build/experiment 
880 -rwxrwxr-x 1 ghawkins ghawkins 900352 Sep  3 21:44 build/experiment*
```

Adding `-DFMT_STATIC_THOUSANDS_SEPARATOR='.'` etc. (see this issues [comment](https://github.com/fmtlib/fmt/issues/3547#issuecomment-1649878688)) did reduce things by 12KiB but relative to its at least 1.5MiB cost that doesn't seem significant:

```
$ cmake -DCMAKE_BUILD_TYPE=MinSizeRel -S . -B build
ghawkins@localhost:~/git/embedded-format$ cmake --build build --verbose
ghawkins@localhost:~/git/embedded-format$ ls -Flas build/experiment 
2428 -rwxrwxr-x 1 ghawkins ghawkins 2483520 Sep  3 22:03 build/experiment*
```

Note: the `--verbose` above causes it to show all the `g++` steps and shows that the `-D` definitions are used where expected.

TODO: see how they affect the output of the preprocessor.
