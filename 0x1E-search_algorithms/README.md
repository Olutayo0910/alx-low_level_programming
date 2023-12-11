# 0x1E. C - Search Algorithms

## Introduction

This project explores and implements search algorithms in C. Understanding these algorithms is fundamental for developing efficient solutions in various applications.

## Project Overview

- **Project Name:** Search Algorithms
- **Author:** Wilfried Hennuyer
- **Weight:** 1
- **Start Date:** Dec 11, 2023, 6:00 AM
- **End Date:** Dec 14, 2023, 6:00 AM
- **Checker Release:** Dec 12, 2023, 12:00 AM
- **Auto Review:** Launched at the deadline

## Learning Objectives

- Explain search algorithms
- Understand linear and binary search
- Identify the best algorithm for specific needs

## Resources

- [Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm)
- [Space complexity (1)](https://en.wikipedia.org/wiki/Space_complexity)

## Requirements

- Editors: vi, vim, emacs
- Compilation: Ubuntu 20.04 LTS, gcc, options: -Wall -Werror -Wextra -pedantic -std=gnu89
- README.md: Mandatory
- Coding Style: Betty style
- Global Variables: Not allowed
- Functions per File: No more than 5
- printf Function: Only allowed standard library printf
- Header Files: Prototypes in search_algos.h, include guarded

## Tasks

### Task 0: Linear Search

#### Prototype

```c
int linear_search(int *array, size_t size, int value);

Searches for a value using Linear search
Returns the index or -1 if not found

### Task 1: Binary Search

```c
int binary_search(int *array, size_t size, int value);

Searches for a value using Binary search
Returns the index or -1 if not found

### Tasks 2-5: Big O Notations
Describes time and space complexity for linear and binary search

### Task 6: Space Complexity

```c
int **allocate_map(int n, int m);

