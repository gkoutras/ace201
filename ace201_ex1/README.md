# ACE201 Assignment 1

The goal of this assignment was to study the behavior of the C language in memory address mappings and to become familiar with hexadecimal representation, through writing code.

---

## Preparation

For this assignment, it was mainly necessary to understand how the memory is structured in the C language. However, it was also necessary to know how to sort the various elements in the memory addresses (variables, pointers, etc.).

## Task Description

 The tasks were as follows:

- Task A: Examining the addresses of elements of an array in memory, from a ready-made code, combined with some further experimentation, based on pointer arithmetic.
- Task B: The correlation check of the addresses in which three variables of the same type (`int`) were registered.
- Task C: The declaration of two structures with the same fields (two characters and an integer) in a different order and the checking of differences in their sizes.
- Task D: Correlation check of addresses to which four pointers returned from differently sized dynamic `malloc` allocation (1, 10, 16, and 32) were registered.
- Task E: The comparison and understanding of the addresses of the constant `main`, a global variable, a local variable, and a pointer returned by dynamic `malloc` binding.

## Implementation Description

The answers to the tasks of this assignment and the results found are explained bellow:

- Task A: For the ready-made code, it is initially observed that all the hexadecimal addresses of the elements of array `A` have a distance of 4 bytes between them, as well as the size of each element as an integer. Then, after initializing the index `p` with the value of the address of `var1`, the addresses and then the values of `var1` and `var2` were printed as decimals and hexadecimals, while finally the value of `var1` was changed by reference and `var2` by index arithmetic. After the array `A` has been declared for ten integer values, the first `printf` is executed, which prints the address of the first element of the array, `A[0]` in hexadecimal. Accordingly, for `A + 1`, the address where the second element of the array is registered,` A[1]` is printed with a difference of 4 bytes from that of the first (the same will also apply to `&A[1]` since they represent the same thing in a different format). However, for `(int)A + 1`, the output is the address of the first element, `A[0]`, increased by one byte, and this is because in the specific type casting the address of the position immediately after `(+ 1)` is printed from first element `A[0]`, not the address of the next element. Finally, two `printf` commands are used to display the size of the array, `A` and a random element of it,` A[0]`. The results are 40 bytes (10 integers of 4 bytes) and 4 bytes respectively.
- Task B: After declaring three local variables of the same type (`int`), using three `printf` commands, their hexadecimal addresses were printed. These variables are stored in the "stack" segment of memory, and for this reason each address was 4 bytes away from the next and the addresses seemed to have a descending number instead of ascending.
- Task C: After declaring two structures, `str1` and `str2` whose data were the same (two characters and an integer) but in a different order (`char`, `int`, `char` and `char`, `char`, `int` respectively), the sizes that were finally printed appeared not to be equal to the sum of the sizes of each data group. This happens because alignment paddings are generally created in the memory (blocks of a number of bytes in which all the elements that "fit" will be bound, or in other words the number of bytes that divides the number of padding bytes of the block. Thus the alignment of each element is done like this: For each member a space equal to the largest size of the type contained in the structure's command block (4 bytes due to integer) must be reserved. So for the `str1` structure 1 byte will be reserved for the first character, but the rest 3 bytes remaining cannot be reserved by the next integer, so all 4 are reserved instead. The next 4 bytes are reserved by the integer, while the last character will have 1 byte reserved by it along with the remaining 3 for the block. Total of 12 bytes. Accordingly, for the `str2` structure 1 byte will be reserved for the first character and another 1 byte for the second since the rest of the 3 bytes are capable of being reserved, while in the next block 4 bytes will be reserved for the integer, since the new balance of 2 bytes is insufficient. Total of 8 bytes.
- Task D. After four pointers were first declared and their addresses returned by four different consecutive `malloc` commands were printed, it was noticed that the distances between them were not equal to the spaces allocated. The reason for this is that the end of the allocated memory area depends on either the compiler or the operating system, thus also affecting the distances between the returned addresses.
- Task E. After first declaring a global variable, a local variable, and a pointer whose address will be returned by a `malloc`, the addresses where the elements were registered were printed with the appropriate `printf` commands along with the address of the `main` function in memory. The distances between their addresses differed, and that's because the local variable is stored in high addresses ("stack" segment), the global variable and `main` in low addresses ("data" and "text" segment respectively), while finally the address returned by `malloc` is in the dynamic "heap" segment.

## Conclusion

The conclusions obtained from this assignment lead to a better understanding of the properties and structure of memory in the C language, as well as of the address distances of various elements such as variables and functions.
