# C - Stacks, Queues - LIFO, FIFO

This project reviewed the concepts of LIFO and FIFO methods, stacks, queues, linked lists, and global variables in C programming.

## General


- What do LIFO and FIFO mean?
LIFO stands for Last In First Out.
FIFO stands for First In First Out.

- What is a stack, and when to use it?
A stack is a data structure where data could be inserted and/or removed from the top. During insertion, data is stacked on top of the structure. If there's capacity, data could continuously be stacked on top. During removal, the data at the very top will be removed first, hence, a stack is also known as LIFO.

- What is a queue, and when to use it?
A queue is also a data structure where data could be inserted and/or removed. Its difference from a stack is that during insertion, data is inserted at the back of the structure and during removal, data is removed from the front. When data is inserted into the structure, it's called enqueue and when it's removed, it's called dequeue also known as FIFO.

- What are the common implementations of stacks and queues?
A stock could be implemented using arrays or linked lists. A queue could be implemented using two stacks in that the original data is in the first stack and stored in the second stack as it gets inserted and removed.

- What are the most common use cases of stacks and queues?
In stacks and queues, data could be inserted (push and enqueue respectively) and removed (pop and dequeue respectively) in an organized matter.

- What is the proper way to use global variables?
A global variable should be declared and defined in the header file using extern. This ensures the global variable would be available for use in all source files related to executing a program.

## Requirements

### General


- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You allowed to use a maximum of one global variable
- No more than 5 functions per file
- You are allowed to use the C standard library
- The prototypes of all your functions should be included in your header file called monty.h
- Don’t forget to push your header file
- All your header files should be include guarded
- You are expected to do the tasks in the order shown in the project

## The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

### The monty program


- Usage: monty file
        where file is the path to the file containing Monty byte code

- If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
- If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
        where <file> is the name of the file
- If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
        where is the line number where the instruction appears.
        Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
        it executed properly every line of the file
        it finds an error in the file
        an error occured
- If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
- You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

## Tasks

### 0. push, pall 

Implement the push and pall opcodes.

#### The push opcode

The opcode push pushes an element to the stack.

- Usage: **push <int>**
where <int> is an integer

- if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
        where is the line number in the file

-  You won’t have to deal with overflows. Use the atoi function

#### The pall opcode

The opcode pall prints all the values on the stack, starting from the top of the stack.

- Usage **pall**
- Format: see example
- If the stack is empty, don’t print anything

### 1. print

Implement the pint opcode.

#### The pint opcode

The opcode pint prints the value at the top of the stack, followed by a new line.

- Usage: **pint**
If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

### 2. pop

Implement the pop opcode.

#### The pop opcode

The opcode pop removes the top element of the stack.

- Usage: **pop**
If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

### 3. swap

Implement the swap opcode.

#### The swap opcode

The opcode swap swaps the top two elements of the stack.

- Usage: **swap**
If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

### 4. add

Implement the add opcode.

#### The add opcode

The opcode add adds the top two elements of the stack.

- Usage: **add**
- If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    - The top element of the stack contains the result
    - The stack is one element shorter


### 5. nop

Implement the nop opcode.

#### The nop opcode

The opcode nop doesn’t do anything.

- Usage: **nop**
