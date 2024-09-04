# Week 4: Memory

## Overview
In Week 4, we explored how computers use memory, focusing on binary, decimal, and hexadecimal systems. We also examined pointers, arrays, and memory management in C.

## Number Systems

- **Binary:** Base-2, used by computers.
- **Decimal:** Base-10, used by humans.
- **Hexadecimal:** Base-16, used to represent memory addresses. It includes 16 symbols: 0-9 and A-F (e.g., FF in hexadecimal is 255 in decimal).

## Addressing and Pointers

### Address-of Operator (`&`)
- **Purpose:** Retrieves the memory address of a variable.
- **Syntax Example:**
```c
  int n = 50;
  printf("%p\n", &n); // Output: memory address of n
```

### Dereference Operator (*)
- **Purpose:** Accesses the value at a given memory address.
- **Syntax Example:**
```c
int n = 50;
int *p = &n; // Pointer p stores the address of n
printf("%p\n", p); // Output: address stored in p
printf("%i\n", *p); // Output: value at the address stored in p (50)
```

### Pointer Declaration
- **Purpose:** Declare a pointer variable that stores memory addresses.
- **Syntax Example:**
```c
int *p; // p is a pointer to an int
```

### Pointers and Arrays
- **Arrays:** Stored contiguously in memory. Strings are arrays of characters ending with a null terminator (NUL character).
- **Strings as Pointers:** A string in C is actually a pointer to the first character in an array of characters.
- **Example:**

```c
char *s = "HI!";
printf("%p\n", s); // s is a pointer to the first character in the string
```

## String Comparison
- **Note:** Use strcmp for comparing strings because == compares addresses, not content.
- **Example:**
```c
char *s = get_string("s: ");
char *t = get_string("t: ");

if (s == t) {
    printf("same\n");
} else {
    printf("diff\n");
}
```

## Dynamic Memory Management

`malloc
`
- **Purpose:** Allocates memory dynamically.
- **Syntax Example:**

```c
int *array = malloc(10 * sizeof(int)); // Allocates memory for an array of 10 integers
```

`
free
`
- **Purpose:** Frees previously allocated memory.
- **Syntax Example:**

```c
free(array); // Frees the memory allocated for array
```

## Conclusion

This week introduced fundamental concepts of memory management, including how to use pointers, arrays, and dynamic memory allocation in C. Understanding these concepts is crucial for effective programming in C.