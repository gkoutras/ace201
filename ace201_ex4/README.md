# ACE201 Assignment 4

The goal of this assignment was to create a program in MIPS Assembly language.

---

## Preparation

For this assignment, the focus was to write code in MIPS Assembly language. The implementation of the required task was based on prior knowledge of the CLang language, as well as deepening the prior knowledge of MIPS Assembly by converting the entire code of the previous assignment along with new code that was needed.

## Task Description

The program in MIPS Assembly, which had to be executed repeatedly and each time, based on the user's input, needed to implement one of five options (four functions and a block of termination instructions). The program contained pieces of previous assignments, while the new code had to be first written in CLang language and, if it met the appropriate functionality, CLang had to be converted into MIPS Assembly. The options were as follows:

1. Reading a number N and printing the adjacent triangle on the screen along with the total number of its elements:
2. Reading a number N and displaying a message informing whether the number is odd or even.
3. Reading five integers from the console and printing four times their values.
4. Reading a string and printing it by changing uppercase to lowercase letters and vice versa.
5. Exit.

## Implementation Description

The answers to the tasks of this assignment and the results found are explained bellow:

1. The first function to be implemented processed an integer from the user, printed a triangle based on that number, and returned the elements of the triangle. To convert the code into Assembly, commands for printing and typing by the user (load immediate `li`, load address `la`, `syscall`) were used in `main`, as well as the `move` assignment command. The function used condition statements such as `slt`, `slti beq`, which represented the for labels used in CLang.
2. The second function required was to process an integer `N` and check if it was odd or even. The function accepted the number from the user and after appropriate arithmetic it produced the result. In MIPS Assembly the description of the function was simple since it consisted of two labels. The commands used, again, were none other than the condition commands `slti`, `bne`, and the assignment commands `move` and `addi`.
3. The third function was to process five integers entered by the user, which were read and written to the array `array` in `main`. The function then quadrupled the value of each element and stored it in the `multipliedArray`. Then these values were read from `main`. In Assembly, in addition to the condition and assignment commands, `lw` and `sw` (load word and store word) commands were also used, which each time the for label ran in `main` loaded and stored corresponding values per 4 bytes of each integer (as the counter increased each time the loop ended). Inside the function the commands `lw`, `sw`, `slti`, `beq`, `add`, `addi` were again used.
4. In the fourth case, the user typed a string into `main`, it was stored in a string, and the function then reversed the letters of the string (from uppercase to lowercase and vice versa), and passed the new string to a second string. The new, reversed string was then printed to `main`. Implementing this function required knowledge of the ASCII code and the relationship between lowercase and uppercase digits in it. In Assembly, the string treatment was different than in `array`. The function had to take into account the size of the string (which was preemptively set to 100) every time the program ran, so a counter was defined that controlled its size, while the `lb` (load byte) command was also used to to register addresses and to achieve char array arithmetic.
5. Finally and after the user's choice, the main register which was in the condition of an initial `whileLabel` with a value of 1 (state `true`) for continuous repetition of the program, changes its value to 0 (state `false`) in order to close the `whileLabel` loop, terminating the program.

## Conclusion

This assignment lead to a better understanding of functions of MIPS Assembly language such as calling, returning functions and dealing with strings, as well as to a better and more meaningful understanding of properties and functions of MIPS Assembly language.
