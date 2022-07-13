# CombinaCount [![MIT License](https://img.shields.io/apm/l/atomic-design-ui.svg?)](https://github.com/tterb/atomic-design-ui/blob/master/LICENSEs)
Is a commandline program for finding numerical solutions to combinatorial problems. Many combinatorial functions are supported see [Documentation](#Documentation).

Table of Contents
-----------------
- [Dependencies](#Dependencies)
- [Installation](#Installation)
- [Documentation](#Documentation)

## Dependencies
Cmake for the makefile
 ```bash
  sudo apt install cmake
  ```
Ncurses to link to the library to run CombinaCount
 ```bash
  sudo apt install libncurses5-dev libncursesw5-dev
  ```
Git to cline this repo
 ```bash
  sudo apt install git
  ```
GCC(GNU C Compiler) to compile and run
 ```bash
  sudo apt install cmake libncurses5-dev libncursesw5-dev git build-essential
  ```
## Installation
After installing the dependencies clone this repo using the running the following command in the terminal.
 ```bash
  git clone https://github.com/benLBrook/CombinaCount.git
  ```
Then change directory to CombinaCount and 
build with gcc:
```bash
  cd ./CombinaCount
  make comb
  ```
To run the code use
```bash
  make run
  ```
You can remove the executable by running make clean:
```bash
  make clean
  ```
## Documentation

[Documentation](https://linktodocumentation)

