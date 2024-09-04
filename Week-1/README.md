# Week 1: C

## Source Code vs. Machine Code

- **Source Code**: This is the code that humans write in high-level programming languages. 

- **Machine Code**: Computers only understand binary (0's and 1's). Whether it's numbers, characters, commands, or instructions, they're all represented in binary. Writing machine code directly isn't ideal for humans, so we use high-level languages (like C). However, we need a program to convert the source code into machine code, so the computer can execute it. This program is called a **compiler**.

### Creating and Compiling Files in VS Code

- To create a file in VS Code, use the terminal command:
```bash
code hello.c
```
- To compile the file from source code to machine code, use:
```bash
make hello
```
- To run the compiled machine code, use:
```bash
./hello
```
Note: You must repeat the compile and run steps every time you make a change to the source code.


## Example of C Code (Hello, World!!)
```bash
include <stdio.h>

int main(void)
{
    printf("Hello, World\n"); // printf = formatted output
}
```

- The \n starts a new line. Without it, the $ sign in the terminal would appear right after the printed text.

-  In C (and many other programming languages), much of the functionality is tucked away in separate files, which you need to include using #include <filename.h>. For example, #include <stdio.h> lets you use standard input and output functions like printf().

- The CS50 Library: CS50 provides a C library to make life easier in the first few weeks, reducing some of the overhead and overwhelming aspects of learning a new programming language, especially C.


### Another Example:
```bash
string answer = get_string("What's your name? ");
printf("Hello, %s\n", answer);
```

Explanation: get_string() is a function from the CS50 library that allows you to receive a string from the user. %s is a placeholder for the string variable answer in the printf() function.

## Loops in C

### While Loop

```bash
int i = 3;

while (i > 0)
{
    printf("Meow!!\n");
    i--;
}
```
This loop will print "Meow!!" three times. You can modify it to start from 0 and increment i, or use true as the condition to create an infinite loop.

### For Loop
```bash
for (int i = 0; i < 3; i++)
{
    printf("Meow!!\n");
}
```
You can remove the condition (i < 3) to create an infinite loop.

### Do-While Loop
```bash
do
{
    // Operation
}
while (condition);
```


## Functions in C

A function in C is defined with three key elements:

- Name: The name of the function.

- Return Value: What the function returns.

- Arguments: The inputs the function takes (if any).

Example:

```bash
void meow(void)
{
    // Function body
}
```

Explanation: void means the function doesn't return a value, and the void in parentheses means it doesn't take any inputs.

### Example of an Add Function

```bash
include <stdio.h>
include <cs50.h>

int add(int a, int b); // Function prototype

int main(void)
{
    int x = get_int("Enter x: ");
    int y = get_int("Enter y: ");
    printf("%i\n", add(x, y));
}

int add(int a, int b)
{
    return a + b;
}
```

The function prototype informs the compiler about the function's name, return type, and parameters before its actual definition.


## Understanding int main(void)

The main() function in C always returns a value. A return value of 0 indicates success, while any other value indicates an error.

## Popular Linux Commands

- cd: Change directory

- cp: Copy files

- ls: List files in the current directory

- mkdir: Make a new directory

- mv: Move or rename files (e.g., mv meow.c woof.c)

- rm: Remove files (e.g., rm hello.c, then confirm with y or n)

- rmdir: Remove directories

## Constants

Constant Variables:

```bash
const int z = 5;
```
The const keyword ensures the variable can't be changed accidentally.

## Integer Overflow and Data Types

- Integer Overflow: This occurs when you exceed the maximum value a data type can hold, causing it to wrap around to a lower value.

Examples of data types:

int = 32 bits
long = 64 bits
float = 32 bits
double = 64 bits (more precision than float)

- Truncation: Dividing an int by an int results in an int, even if the mathematical result should be a floating-point number.

Solution: Typecasting

```bash
include <stdio.h>
include <cs50.h>

int main(void)
{
    int x = get_int("Enter x: ");
    int y = get_int("Enter y: ");
    float z = (float)x / (float)y;
    printf("%f\n", z);
}
```
You can also declare x and y as floats from the beginning if that suits your needs better.


