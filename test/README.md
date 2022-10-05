# Test Folder
This test folder contains test files that checks for stack operations

> Note: All functions should be written inside the `1-stack_operations.c` file. Compilation should be done as stated below
> Use the header file `monty.h` (i.e `#include "monty.h"`)
> You don't have to declare the `top` variable because it is a global variable and it has been declared already, simply use it!

### Task 0
- Write a function that checks if a stack empty or not
- Prototype: `int isempty(void);`
- Return: 1 if it is empty or 0 if not empty
```
vagrant@ubuntu-focal:~/monty$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 test/0-main.c 1-stack_operations.c -o a
vagrant@ubuntu-focal:~/monty$ ./a
The stack is empty
The stack is not empty
The stack is empty
vagrant@ubuntu-focal:~/monty$
```

### Task 1
- Write a function that print all the element in the stack
- Prototype: `int pall(void);`
- Return: The number of element printed
```
vagrant@ubuntu-focal:~/monty$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 test/1-main.c 1-stack_operations.c -o b
vagrant@ubuntu-focal:~/monty$ ./b
9
8
-> 2 elements
vagrant@ubuntu-focal:~/monty$
```
