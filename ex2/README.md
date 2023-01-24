# ACE201 Assignment 2

The goal of this assignment was to get familiar with the management of structures in memory, and with the CLang language.

---

## Preparation

For this assignment, it was mainly necessary to recall previous knowledge about pointers and applications in linked lists, as well as to study and understand the way CLang works. The purpose was to create a program in C that would implement all the requested functions, and since it met this functionality, a part of this program should be converted into CLang language.

## Task Description

The task was to write a linked list implementation code in C language and then convert it to CLang. Each element of the list had to include three values (`short id`, `int value`, `struct node *next`), while the last element was an integer indicating the memory address of the next element in the list. The list had to be dynamic and the program had to support the following 10 functions:

1. Create a list.
2. Insert item in the list in ascending order.
3. Delete a specific item from the list.
4. Print the existence or not of a particular item in the list.
5. Print the number of items in the list.
6. Print address of specific item.
7. Print address of the list.
8. Print size of specific element in bytes.
9. Print list size in bytes.
10. Exit

## Implementation Description

Implementig this assignment required an understanding of pointer theory in C, and the linked lists to which they apply. These conversions were made through changes in the syntax of specific commands, such as condition commands (`if`, `else`) and repetition loops (`for`, `while`) along with their logical operators (`AND`, `OR`). More specifically, it required the use of `goto` and `label` statements in which the previous operations were converted into operations between registers (global variables) through which program variables were represented (each variable in C was mapped to a register). Finally, because of the number of variables in such a number of functions program, in which most of the 32 registers were used, and because of the conversions of the aforementioned commands that occupied more lines of code, it was expected that the program written in CLang would have more lines than that written in C.

## Conclusion

This assignment helped in a deeper understanding of the memory, and was a beginning for understanding the Assembly language, since CLang is an intermediate code in C and Assembly. It also became clear how the functions provided by C are expressed using only 32 global variables (registers), which is how CLang and by extension Assembly works.
