# Data Structures and Algorithms

This repository contains **Data Structures and Algorithms implementations in C++**, organized by topic (CRUD operations and Algorithms and built using **CMake**.
---

## Project Structure

```
dsa/
├── CMakeLists.txt
├── bin/                    # All compiled executables
│   └── array_crud
│
├── CRUD/
│   ├── array/
│   │   ├── array.cpp
│   │   └── CMakeLists.txt
│   └── linked-list/
│       ├── linked_list.cpp
│       └── CMakeLists.txt
│
├── algorithms/
│   ├── sorting/
│   ├── searching/
│
├── build/                  # CMake build directory (generated)
└── README.md
```

---

## Requirements

* **Linux / macOS**
* **CMake ≥ 3.16**
* **GCC ≥ 13** or **Clang ≥ 16**

Check versions:

```zsh
cmake --version
g++ --version
```

---

## Build Instructions

### Configure (Debug build)

```zsh
cmake -B build -DCMAKE_BUILD_TYPE=Debug
```

### Build

```zsh
mkdir -p build bin
cd build
cmake ..
cmake --build .
```

Output example:

```
[100%] Built target array_crud
```

Executable will be generated in:

```
bin/array_crud
```

---

## Run

```zsh
./bin/array_crud
```

---

## Debug and Release Builds

### Debug Build (with sanitizers)

```zsh
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

### Release Build (optimized)

```zsh
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

---

## Adding New Programs

### Example: Add Linked List CRUD

1. Create source file:

```
CRUD/linked-list/linked_list.cpp
```

2. Add executable in `CRUD/linked-list/CMakeLists.txt`:

```cmake
add_executable(linked_list_crud linked_list.cpp)
```

3. Rebuild:

```zsh
cmake --build build
```

Binary output:

```
bin/linked_list_crud
```

---

## Objective

* Learn core **Data Structures** (Array, Linked List, Stack, Queue, Trees, Graphs)
* Implement **CRUD operations**
* Practice **Algorithms** (Searching, Sorting, Graph, DP)
* Use **modern C++17**
* Learn **CMake** and real-world build systems

---

## Tools Used

* **C++17**
* **CMake**
* **GCC / Clang**
* **clangd**
* **clang-format**

---
## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
## Author

**Laksh Krishna Sharma**
Learning DSA, C++, and system-level development
