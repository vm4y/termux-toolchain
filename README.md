# termux-toolchain

Portable Android development toolchain for Termux environments.

This repository provides pre-packaged archives that can be extracted directly into a Termux installation. The goal is to simplify deployment of a ready-to-use Android NDK toolchain and a standalone Python runtime without requiring users to build everything from source.

---

## Android NDK Toolchain (Termux Edition)

A pre-packaged Android NDK environment adapted for use inside Termux.

This toolchain is based on the LLVM/Clang toolchain distributed with the Android NDK and has been modified for easier integration with Termux workflows.

The included Python package inside the NDK environment has also been modified to improve compatibility with Termux-based development environments.

### Installation

Download the NDK release archive and extract it into your Termux home directory:

```bash
tar -zxf ndk-25.2.9519653.tar.gz \
    -C /data/data/com.termux/files/home \
    --recursive-unlink \
    --preserve-permissions
```

After extraction, restart your shell:

```bash
exec bash
```

### Configure Environment (Optional)

Add the Android NDK tools to your shell environment:

```bash
export ANDROID_NDK_HOME="$HOME/android-sdk/ndk/25.2.9519653"
export ANDROID_NDK_ROOT="$ANDROID_NDK_HOME"

export PATH="$ANDROID_NDK_HOME:$PATH"
```

Reload your shell:

```bash
source ~/.bashrc
```

Verify:

```bash
ndk-build --version
```

> Note:
> If you need direct access to LLVM tools such as `clang`, `clang++`, or `llvm-ar`,
> add `toolchains/llvm/prebuilt/linux-x86_64/bin` to your `PATH`.

### Included Components

- Android NDK
- LLVM / Clang
- LLD
- libc++
- Build utilities
- Modified Python runtime for Termux compatibility

### Intended Use

- Native Android development
- JNI projects
- C/C++ cross-compilation
- Reverse engineering workflows
- LLVM-based toolchains

### Original Source

https://github.com/codehasan/dex2c/releases/tag/ollvm-termux


---

## Portable Python Runtime

A standalone Python build packaged as a portable archive.

This package contains a portable Python runtime that can be extracted and executed without depending on the system Python installation.

## Why Portable Python?

A common question is:

> Why not just use `pkg install python` from Termux?

For most users, the official Termux package is the recommended choice.

However, some older projects depend on specific Python versions, dependency versions, or runtime behavior that may no longer be available after future package updates.

When Python or related packages are upgraded in Termux, existing projects can stop working due to:

- Python version changes
- Dependency version changes
- ABI differences
- Removed or deprecated features
- Build-system incompatibilities

A portable Python distribution provides a fixed runtime environment that can be archived, redistributed, and reused without relying on the current state of the Termux repositories.

This improves reproducibility and helps preserve older projects that are known to work with a specific Python release.

### Why not use old repositories such as Tur Repo?

Third-party repositories may eventually become unavailable, stop receiving maintenance, or remove older packages.

In addition, installing packages from external repositories still relies on package manager metadata and repository availability.

A portable archive is self-contained:

- No repository required
- No package manager required
- No dependency on future repository availability
- Easy to archive and redistribute
- Suitable for long-term project preservation

The goal of this repository is not to replace the official Termux packages, but to provide reproducible toolchain snapshots that remain usable even if upstream packages change in the future.

### About Python

Official website:

https://www.python.org/

Official documentation:

https://docs.python.org/3/

### Build Information

- Python Version: 3.12.13
- Architecture: Android aarch64
- Shared library build
- Portable distribution

### Installation

Extract the archive:

```bash
tar -zxf python-3.12.13-aarch64-android.tar.gz
```

Run Python:

```bash
./python --version    #this is wrapper binary for bin/python3
./bin/python3 --version
```

Interactive shell:

```bash
./python
```

Execute a script:

```bash
./python script.py
```

### Example

```bash
./python -c 'import sys; print(sys.version)'
```

---

## Repository Structure

```text
Releases
├── ndk-25.2.9519653.tar.gz
└── python-3.12.13-aarch64-android.tar.gz
```

---

## Requirements

- Android device
- Termux environment
- aarch64 architecture

---

## Notes

These archives are intended for users who familiar with:

- Android NDK
- LLVM / Clang
- ELF binaries
- Cross-compilation
- Termux environments

Always verify archive contents before extraction and ensure that the release matches your target architecture.

---

## License

Refer to the licenses provided by the original projects:

- Android NDK
- LLVM Project
- Python Software Foundation

This repository primarily distributes repackaged binaries and convenience archives intended for Termux-based development workflows.
