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
