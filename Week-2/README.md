# Week 2: Arrays

Compiling isn't exactly what we described it as last week. Previously, we used "compiling" as a catch-all phrase that we claimed converts source code to machine code. However, to be more precise, compiling is just one of four steps involved in turning the source code you and I write into binary machine code (0's and 1's).

## Compilation Steps:

1. **Preprocessing**: This step includes operations like find-and-replace (e.g., `#include` directives). It takes the functions you need from libraries and includes them as prototypes in your file, so when you use a library function, the compiler knows about it.

2. **Compiling**: This step converts C code to assembly language—a very old language written by humans before machine code. Note that assembly language is still not machine code.

3. **Assembling**: This converts assembly language to machine code (0's and 1's).

4. **Linking**: During execution, your code, the library code, machine instructions, and other components are combined. The linking step intelligently combines all these separately compiled files into a single final file, which might be named `hello` or whatever you choose. It results in one large file of 0's and 1's.

> **READ MORE ABOUT REVERSE ENGINEERING MACHINE CODE TO SOURCE CODE** - Sounds interesting!

## Introducing the Debugger Tool in VS Code

Use `debug50` for ease:

In the terminal, write `debug50 ./filename`. Before running it, make sure to run the `make` command, as the debugger helps with logical errors but not syntax errors.

After running, you’ll need to set a breakpoint.

**DEBUGGING IS REALLY IMPORTANT** (REWATCH)

```c
int main(void)
{
    int score1 = 72;
    int score2 = 73;
    int score3 = 74;

    printf("My average is: %f\n", (score1 + score2 + score3) / 3);
}
```
In the code above, dividing integers will result in an integer, discarding floating-point numbers. To fix this, you can either typecast or change the data type of scores to float. The simplest fix is to change 3 to 3.0 since having one float in the equation elevates the entire calculation to floating-point.

## Arrays

An array is a sequence of values stored consecutively in memory without gaps.

```c
int scores[3]; // Allocates an array of size three (three integers in a row)
scores[0] = 72; // Assigns the value 72 to the first element of the array
```
In C, you cannot directly ask an array for its length as you can in other languages. It's better to use a constant to remember the length.


In C, strings are essentially arrays of characters, so you can treat them as arrays:
```c
string s = "HI!";
printf("%c %c %c\n", s[0], s[1], s[2]); // Outputs: HI!
```

- QUESTION: If strings and arrays are the same, how does the computer know where a string ends? Unlike arrays, which have a defined size, strings can vary in length.

- - ANSWER: A special sentinel value, the null terminator ('\0'), is used to indicate the end of a string. This value is a byte with all zero bits, signaling the end of the string.


### Example Notes:

- The string.h library contains many string manipulation functions. For example, strlen returns the length of a string:

```c
int length = strlen(name);
```

- using get_string and printing:

```c
string s = get_string("What's your name? ");
printf("What's up? "); // Note: No newline, so the next output continues on the same line
```

- To print a string without using printf and %s, you could iterate over each character:

```c
for (int i = 0, size = strlen(s); i < size; i++)
{
    printf("%c", s[i]);
}
// This loop avoids repeatedly calling strlen by storing its result in a variable.
```

- To manually find the end of a string:

```c
string name = "mazen";
int n = 0;

while(name[n] != '\0')
{
    n++;
}

printf("Your name is: %i\n", n);
```

- The ctype.h library provides toupper() and tolower() functions to change character case:

```c
string s = get_string("What's your name? ");
for(int i = 0, n = strlen(s); i < n; i++)
{
    printf("%c", toupper(s[i]));
}
```

Alternatively, you can manually check and adjust case:

```c
if (s[i] >= 'a' && s[i] <= 'z') {
    s[i] -= 32; // Difference in ASCII values between lowercase and uppercase
}
```

## Command Line Arguments

You can write code to take input from the command line:

- Normal Way:

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("Hello, %s\n", answer);
}
```

- Command Line Argument Way:

```c
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("Hello, %s\n", argv[1]);
    }
    else
    {
        printf("Hello, world\n");
    }
}
```

Executing `./greet David` would result in the program outputting "Hello, David."

## Summing Up

In this lesson, we learned more about compiling and how data is stored within a computer. Specifically, I learned:

- Generally, how a compiler works.

- How to debug your code using various methods.

- How to utilize arrays within your code.

- How arrays store data consecutively in memory.

- How strings are essentially arrays of characters.

- How to interact with arrays in your code.

- How to pass command-line arguments to your programs.

- The basic building blocks of cryptography.









