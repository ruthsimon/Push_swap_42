# Push_swap_42
Push Swap is a sorting algorithm project that challenges you to efficiently sort a stack of integers using a limited set of instructions. The goal is to arrange the numbers in ascending order on one stack while adhering to the given constraints.

The project involves two stacks, 'A' and 'B', and a set of operations that can be performed on these stacks. The allowed operations include swapping the top elements of the stacks, rotating the entire stack, and pushing an element from one stack to another.

Your task is to implement a series of operations that will transform the initial configuration of stack 'A' into a sorted order. The challenge lies in minimizing the number of operations performed, as efficiency is a crucial aspect of the evaluation.

# Features
Sorting a stack of integers in ascending order.
A limited set of stack operations: swap, rotate, and push.
Efficient algorithm design to minimize the number of operations.
Command-line interface for easy interaction and testing.

# How it works
To begin, gather input arguments from the user and convert the string representations to integers using atoi. Eliminate any repetitions within the input and employ a stack data structure to store the numbers. For sorting, initially use qsort or a similar algorithm. As an optimization strategy, iteratively find the median until only 3 numbers remain, and then perform a final sorting using a small sorting algorithm, such as TinySort. After sorting, calculate the push price for each number in both stacks. The push price represents the number of steps required to bring a specific number to the top. Each element in stack B will have a target number in stack A, where the target is the smallest number greater than the element in B with minimal difference. Finally, determine the push price for each number in stack B, considering the cost of moving both stack A and stack B elements to the top. Select the cheapest push price and execute the corresponding push operation from stack B to stack A.To optimize the sorting process, initially, store the numbers in an integer array and apply a sorting algorithm . To enhance efficiency, iteratively find the median and push numbers greater than the median until only three numbers remain. Employ TinySort, or a similar efficient sorting algorithm, for the final sorting of the reduced set of numbers. This approach streamlines the sorting procedure, improving overall performance in the context of the specified algorithm.

# Getting Started
To get started with Push Swap, clone the repository and follow the instructions in the README to run the program on your local machine.

# Usage
Run the Push Swap program with the provided command-line interface, providing the initial stack configuration as input. The program will output the sequence of operations to sort the stack.
# ./push_swap [arguments]
# checker-  sh checker.sh
# visualizer- python3 python_visualizer.py `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"`

# Acknowledgments
Inspired by the concept of stack sorting algorithms.
Thanks to the open-source community for valuable insights and discussions.
If you found this helpful, give it a 
