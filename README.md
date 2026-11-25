# LabMon

A C++20 Linux memory monitor, built with CMake and packaged with Nix.

```bash
nix-build
./result/bin/labmon
```

Shows total and available RAM in GiB, updated every second.

Includes a NixOS VM configuration: `vm.nix`.