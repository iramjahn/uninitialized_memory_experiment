# Experiment 01: Reading an uninitialized int

## Experiment
A C program declares a local variable `int x;` without assigning it a value,
then prints it with `printf`. I compiled and ran it three ways:

1. `gcc uninit.c -o uninit` (default settings)
2. `gcc -Wall uninit.c -o uninit` (all common warnings enabled)
3. `gcc -O2 uninit.c -o uninit` (optimizations enabled)

Question: what does C do when you read a variable that was never initialized?

## Prediction
It won't compile.

## Why I thought this
Because x is just an int without anything assigned to it.

## Results
My prediction was wrong, as the program compiled in all 3 cases

| Command | Compiled? | Warning | Output |
|---|---|---|---|
| `gcc uninit.c -o uninit` | Yes | None | 32764 |
| `gcc -Wall uninit.c -o uninit` | Yes | `'x' is used uninitialized [-Wuninitialized]` | 32766 |
| `gcc -O2 uninit.c -o uninit` | Yes | None | 0 |

## Follow-up
### Follow-up: printing the address of x (`uninit_addr.c`)
- value of x: 32765 (hex 7ffd)
- address of x: 0x7ffd8d375f44

## What I think is happening (first attempt — later found to be wrong)
Because x was declared as an int, so it only stores 4 bytes, since it wasn't assigned a value, the program doesn't read what was stored at the address, rather just the upper half of the address of x in the stack since that matches 4 bytes.

## Revised understanding through chatting with AI (after leftover.c)
Before main runs, the C library’s startup code runs first. It uses the stack and writes various values on that whiteboard, including some 8-byte pointers to other places on the stack.
That startup code finishes, but it doesn’t erase anything. Its old values stay on the whiteboard.
Then main runs and declares int x. That doesn’t erase anything either. It just puts a label on 4 bytes of the whiteboard and calls them x.
Those 4 bytes happened to contain the top half of one of the old pointers left behind by startup code: 0x00007ffd, which is 32765.