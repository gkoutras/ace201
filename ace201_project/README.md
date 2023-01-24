# ACE201 Project

The goal of the project was to create a program in C language, together with the use of ready-made code, which had to recursively implement a game (solving a maze) of two options (two functions). Then convert the program in CLang and finally in MIPS Assembly language.

---

## Preparation

Implementation of the required task for this project was based on prior knowledge of C and CLang, as well as deepening prior knowledge of MIPS Assembly through familiarization with the stack, recursive functions, register conventions, polling, and interrupts.

## Task Description

The required program together with the use of ready-made code, had to recursively implement a game (solving a maze) of two options (two functions). Once the program met the appropriate functionality, it had to be converted to a MIPS Assembly. The options were as follows:

1. The implementation of the game that involved the user traversing a maze with the goal of exiting it.
2. Solving and locating the optimal path to the exit using the appropriate key.

In addition, after the conversion to MIPS Assembly, a few code modifications were requested regarding the following functions:

1. The implementation of a dummy function `read_ch`, which, taking advantage of the polling technique, as soon as it read a character from the keyboard, should switch to one of the above options without requiring the "Enter" key for input.
2. The modification of the Assembly exceptions, so that an interruption is triggered from the keyboard to detect and read each new character that is going to be entered by the user.

## Implementation Description

The answers to the tasks of the project and the results found are explained bellow:

1. The implementation of the first task was made through three functions. The `main` function, which was the only function requested for the first query, was performed via `switch cases` in ASCII format for each character entered by the user. For any of the five cases ("W", "A", "S", "D" and "E") chosen by the user, `main` performed the player's movement or found the optimal solution of the maze respectively by calling the given recursive function each time. After each case the maze was printed so that the user could see his position at each step.
2. For the second request, the conversion from C to CLang was required. In MIPS Assembly it was deemed necessary to know the stack properties, as this way it was possible to describe the recursive function call. In addition, a C to MIPS Assembly conversion of the `usleep` function was requested, which on each call to `printLabyrinth` would very briefly delay the printing of the maze, resulting in smoother program flow. Finally the character input by the user was done using code `12` in the appropriate `syscall` command.
3. For the implementation of the Polling technique, unlike the initial input of a character by the user, no `syscall` was called. The Receiver Control address was initially assigned to a register. Then a repetitive operation was performed until the value of the register which will indicate the least significant bit from 0 becomes 1 (Ready Bit). When the Ready Bit becomes 1 then it is possible to enter a character, so a load byte command is called to the Receiver Data address and the program receives a character from the user and reads it without waiting for "Enter".
4. Finally, for the implementation of Interrupts it was necessary to modify the `exceptions_mips.s` file of SPIM as well as the code. In MIPS Assembly, interrupts first had to be enabled, which was done using the tutorial code. After creating two memory locations, `cdata` and `cflag` in `.data` and initializing them to the value 0, the code in `main` followed, which through a `forLoop` checked if `cflag` was equal to 1. When `cflag` becomes 1 it resets, since 1 indicates that there is a new character to read. This character is stored in the `cdata` variable. When the user presses a character, the `forLoop` will be interrupted for a while until the interrupt handler code, which is in `exceptions_mips.s`, is run, then the `cflag` will be reset to 0 and the `forLoop` will run again until another character comes from the user. In the `exceptions_mips.s` file `cdata` and `cflag` were given values each time the interrupt was triggered, this was achieved with the help of the `$k0` and `$k1` registers.

## Conclusion

The conclusions obtained from the implementation of the project lead to a better understanding of MIPS Assembly functions such as the stacks of recursive functions, the polling technique and interrupts through modifications to a `.s` file.
