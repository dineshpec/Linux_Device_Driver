# ofd — Our First Driver (simple Linux kernel module)

This repository contains a tiny Linux kernel module named `ofd` ("Our First Driver"). It's a minimal example module that logs messages when inserted and removed. It's intended for learning how to build and load kernel modules.

## What it does

- Prints messages to the kernel log at load and unload time.
- No device nodes, sysfs entries, or parameters — just a simple module skeleton.

## Files

- `ofd.c` — module source
- `Makefile` — simple Makefile to build the module (produces `ofd.ko`)
- `Module.symvers`, `modules.order` — build artifacts

## Build

Make sure you have kernel headers and build tools installed for your running kernel. On Debian/Ubuntu that is typically:

```bash
sudo apt-get install build-essential linux-headers-$(uname -r)
```

To build the module in this directory:

```bash
make
```

This will produce `ofd.ko` (the kernel object) along with other build artifacts.

## Install / Remove

To insert the module:

```bash
sudo insmod ofd.ko
# or: sudo /sbin/insmod ofd.ko
```

To remove it:

```bash
sudo rmmod ofd
```

Check kernel messages (dmesg) to see the module's log messages:

```bash
dmesg | tail -n 20
```

Example output you should see when inserting/removing:

```
ofd: init start
ofd: init success
ofd: exit called
```

## Module metadata

- Author: Dinesh
- License: GPL
- Description: Our First Driver

Since the module is licensed as GPL, it can link against GPL-only symbols.

## Notes and troubleshooting

- The module is compiled against the kernel headers available on the build machine. If `insmod` fails with unresolved symbols, build the module on the target machine (or install matching kernel headers).
- Use `modinfo ofd.ko` to inspect module metadata after building.
- If you make changes to the source, run `make clean` then `make`.

## Cleaning

```bash
make clean
```

## License

This code declares `MODULE_LICENSE("GPL")` in `ofd.c`. If you want to publish the repository, add an explicit license file (e.g., `COPYING` or `LICENSE`).

---

If you'd like, I can also add a short `CONTRIBUTING.md`, a simple test harness, or automatically-generated `modinfo` examples. Let me know what else you want documented.