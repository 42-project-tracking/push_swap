# Push_swap 42 Project

## Overview

The Push_swap project requires you to sort a stack of integers using two stacks (A and B) and a specific set of operations. In this tutorial, we'll be using the Radix sort algorithm, which sorts numbers by their digits.

## Step 1: Understanding Radix Sort

Radix sort is a non-comparative sorting algorithm that works on integers by processing individual digits. It sorts numbers from the least significant digit (rightmost) to the most significant digit (leftmost).

Consider the following stack:

```
16 

127 

91 

890

19
```

### 1. (Sorting by Last Digit):

```
890

091

016

127

019
```

### 2. (Sorting by Second Last Digit):

```
016

019

127

890

091
```

### Step 3 (Final Sorting by First Digit):

```
016 

019 

091 

127 

890
```

## Step 2: Implementation Details

### Maximum Digits

To apply Radix sort, you first need to find out the maximum number of digits in the list. This will be used as a stopping condition for the loop (you loop max_digits times).

### Using Stacks

The key challenge in this project is that you're only allowed to use two stacks. To overcome this, you'll run the Radix sort algorithm on the binary representations of the integers.

**Two bitwise operators are used:**

```'>>' (Right Shift)``` 

This shifts the bits of a number to the right. For example, 5 >> 1 shifts the bits of 5 one step to the right, resulting in 2 (in binary, 101 becomes 10).

```'&' (And)```

This compares the bits of two numbers and sets the spots where both have a 1 to 1, the rest to 0. For example, 5 & 1 compares the binary representations of 5 (101) and 1 (001). The result is 1.

These operators help in finding the maximum number of digits and comparing the bits at each spot for sorting.

Bitwise Operations Example (file: src/radix_sort.c)

``if (((top_a->simple >> i) & 1) == 1)``

This line checks the i-th bit of top_a->simple.

## Bitwise Operations Examples


## Right Shift (>>) Example:

### Problem:

Shift the bits of 5 one step to the right.

```
int num = 5;
int result = num >> 1;
```

### Explanation:

5 in binary is 101.

Shifting one step to the right gives 10, which is 2 in decimal.


## And (&) Example:

### Problem:

Perform a bitwise AND operation between 5 and 1.

```
int num1 = 5;
int num2 = 1;
int result = num1 & num2;
```

### Explanation:

5 in binary is 101.

1 in binary is 001.

Performing the AND operation:

First bit: 1 & 0 = 0

Second bit: 0 & 0 = 0

Third bit: 1 & 1 = 1

The result is 001, which is 1 in decimal.


## Checking a Bit in a Number Example:

### Problem:

Check if the 2nd bit (from the right) of 7 is 1.

```
int num = 7;
int bit_position = 1; // 0-based index, so 1 corresponds to the 2nd bit from the right
int is_bit_set = (num >> bit_position) & 1;
```

### Explanation:

7 in binary is 111.

Shifting one step to the right gives 11, which is 3 in decimal.

Performing a bitwise AND with 1 checks the least significant bit.

The result is 1, indicating that the 2nd bit is set.

### Additional Note:

These examples demonstrate how bitwise operations work on individual bits within binary representations of numbers. In the context of your Push_swap project, these operations are 

used to manipulate the bits to determine the maximum number of digits and to compare the bits at each position during sorting.

## Step 3: Handling Negative Numbers

Radix sort doesn't handle negative numbers well, as -100 has more bits than 100. To solve this, you can index the numbers in your stack and sort them using their indexes.

Example:

```
78
-2
100
-18
5
```

Becomes:

```
3
1
4
0
2
```

## Step 4: Special Cases

Radix sort may not perform well with small stacks, as it always runs max_bits times. To address this, you can hardcode solutions for cases with 3 and 5 values (in simple_sort.c).

## Error handling

Most tricky thing is integer overflow checking, here is a nice implementation of atoi with integrated int overflow check (approach 3)
https://www.geeksforgeeks.org/write-your-own-atoi/
Other than that it is pretty straightforward, check the subject for details:)
