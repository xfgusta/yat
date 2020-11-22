# yat

yat (yet another tree) is a very simple version of [tree](https://en.wikipedia.org/wiki/Tree_(command)) for Linux.

## Examples

### Test directory

```
$ mkdir -p test/hello test/hi/every/one test/.hidden
$ touch test/yat.c test/hello/world.txt
$ ln -s ../hello/world.txt test/hi/new_world
```

### Usage examples

```
$ yat test
test/
  hello/
    world.txt
  hi/
    every/
      one/
    new_world
  yat.c

4 directories, 3 files
$ cd test
$ yat
./
  hello/
    world.txt
  hi/
    every/
      one/
    new_world
  yat.c

4 directories, 3 files
$ yat hi hello
hi/
  every/
    one/
  new_world

hello/
  world.txt

2 directories, 2 files
```

## Build

```
$ make
```

## Install

```
# make install
```

## Uninstall

```
# make uninstall
```
