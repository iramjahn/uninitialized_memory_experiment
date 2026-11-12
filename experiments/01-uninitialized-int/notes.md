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
<fill in after running>