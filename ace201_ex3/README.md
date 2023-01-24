# ACE201 Assignment 3

The goal of this assignment was to create a program in CLang language.

---

## Preparation

For this assignment, the focus was to convert code from CLang to MIPS Assembly. The implementation of the requirements of this workshop was based on the deepening of the previous knowledge of CLang as well as the familiarity with the MIPS Assembly language, through a simple at first glance conversion. 

## Task Description

The program in CLang, which had to be executed repeatedly and each time, based on the user's input, had to implemet one of four options (three functions and a block of termination commands). After the program met this functionality, a part of its code had to be converted to MIPS Assembly language. The options were as follows:

1. Reading a number N and printing the adjacent triangle on the screen:
2. Reading a number N and displaying a message informing whether the number is odd or even.
3. Reading five integers from the console and printing five times their values.
4. Exit.

## Implementation Description

The answers to the tasks of this assignment and the results found are explained bellow:

1. The first function to be implemented processed an integer from the user, took it as its only argument and through the appropriate `goto` labels and proper use of registers, formed the triangle of numbers that was needed. By using two `forLabel`, one to change the row (their number is equal to the number of the user) and one to print each element of a row, the triangle was implemented and in order to find the total number of elements the value of a register was increased with zero initial value on each print of each item.
2. The second function required needed to process an integer and check if it was odd or even. The function took as its only argument the number to be entered by the user and since the use of the modulus (`%`) command was not allowed, its operation was carried out through recursion. The value returned by the callback was, as indicated, assigned to the function's return register, returning to `main` 0 or 1. There `main`, depending on that value, printed the appropriate message about the nature of the number.
3. The third and last function, had to process five integers, entered by the user, which were read and entered into the array `array` in `main`. The function accepted as an argument the address of `array` and `arrayTimesFive` arrays, and through two `forLabel` (since the multiplication operation was forbidden by the task), the values of each element of `array` were quintupled, stored in `arrayTimesFive` and returned the original address of `array` after assigning it, as indicated, to the function's return register, then displaying the respective results.
4. Finally and after the user has selected, the `main` register that was in the condition of an initial `whileLabel` with a value of 1 (state `true`) for continuous repetition of the program, changes its value to 0 (state `false`) and closes the `whileLabel` loop, terminating the program.

## Conclusion

This assignment lead to a better and more effectively understanding of the functions of CLang and memory in the C language, as well as the founding of the first practical bases in the syntax of the MIPS Assembly language.
