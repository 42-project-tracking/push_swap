**Push_swap 42 Project**

**Overview**

The Push_swap project requires you to sort a stack of integers using two stacks (A and B) and a specific set of operations. In this tutorial, we'll be using the Radix sort algorithm, which sorts numbers by their digits.

**Step 1: Understanding Radix Sort**

Radix sort is a non-comparative sorting algorithm that works on integers by processing individual digits. It sorts numbers from the least significant digit (rightmost) to the most significant digit (leftmost).

Consider the following stack:

``16 127 91 890 19``

Step 1 (Sorting by Last Digit):
``
890
091
016
127
019
``
Step 2 (Sorting by Second Last Digit):
``
016
019
127
890
091
``
Step 3 (Final Sorting by First Digit):
``016 019 091 127 890``

**Step 2: Implementation Details**

**Maximum Digits**

To apply Radix sort, you first need to find out the maximum number of digits in the list. This will be used as a stopping condition for the loop (you loop max_digits times).

**Using Stacks**

The key challenge in this project is that you're only allowed to use two stacks. To overcome this, you'll run the Radix sort algorithm on the binary representations of the integers.

Two bitwise operators are used:

``>`` (Right Shift): This shifts the bits of a number to the right. For example, 5 >> 1 shifts the bits of 5 one step to the right, resulting in 2 (in binary, 101 becomes 10).
``&`` (And): This compares the bits of two numbers and sets the spots where both have a 1 to 1, the rest to 0. For example, 5 & 1 compares the binary representations of 5 (101) and 1 (001). The result is 1.

These operators help in finding the maximum number of digits and comparing the bits at each spot for sorting.

Bitwise Operations Example (file: src/radix_sort.c)

``if (((top_a->simple >> i) & 1) == 1)``

This line checks the i-th bit of top_a->simple.

**Step 3: Handling Negative Numbers**

Radix sort doesn't handle negative numbers well, as -100 has more bits than 100. To solve this, you can index the numbers in your stack and sort them using their indexes.

Example:
``
78
-2
100
-18
5
``
Becomes:
``
3
1
4
0
2
``
**Step 4: Special Cases**

Radix sort may not perform well with small stacks, as it always runs max_bits times. To address this, you can hardcode solutions for cases with 3 and 5 values (in simple_sort.c).

**Conclusion**

With this approach, you can efficiently sort stacks of integers using Radix sort within the constraints of the Push_swap project. Good luck, and feel free to ask if you have any further questions!









