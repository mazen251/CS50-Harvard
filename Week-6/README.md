# Week-6: Python

To simplify and allow you to write code more easily, speed is going to be a tradeoff. Because C allows you, the programmer, to make decisions about memory management, it may run faster than Python – depending on your code. While C only runs your lines of code, Python runs all the code that comes under the hood with it when you call Python’s built-in functions.

**Importing Libraries:**

In Python, for efficiency purposes, you can choose to import certain functions from certain libraries. You don't have to import the whole library or include it like in C.

**Syntax Differences:**

For instance in C:
```python
string name = get_string("What's Your Name? ");
printf("Hello, %s\n", name);
```
In Python:

1. 
```python
name  = get_string("What's Your Name? ")
print("Hello, " + name)
```
The `+` is joining the two strings together (concatenating).

2. 
```python
print("Hello,", name)  # as a second argument (it will put the space)
```
3. (MOST COMMON WAY)
```python
print(f"Hello, {name}")  # format string (f string)
```
**Data Types:**

(NO DATA TYPES IN PYTHON, you don't have to specify the data type for a variable)

**Addition with int [using input]:**
```python
# Prompt user for x
x = input("x: ")            # 1

# Prompt user for y
y = input("y: ")            # 2

# Perform addition
print(x + y)               # treated as a concatenating strings
```
Instead we should write:
```python
# Prompt user for x
x = int(input("x: "))

# Prompt user for y
y = int(input("y: "))

# Perform addition
print(x + y)              # will add the integers
```
You can also remove the conversion from `x` and `y` and write it as:

`print(int(x) + int(y))`

**Syntax Differences:**

In Python, you can't use `++` (increment operator) like in C. Instead, you use:
```python
counter = counter + 1  # or
counter += 1
```
**Data Types in C vs Python:**

In C, we had 7 common data types:
- `bool`
- `char` (X)
- `double` (X)
- `float`
- `int`
- `long` (X)
- `string` (str instead of string)

New data types in Python:
- `range`
- `list` (like an array but better)
- `tuple`
- `dict` (dictionaries, hash tables)
- `set` (collection of values that gets rid of duplicates)

**CS50 Library:**

The CS50 library will provide:
- `get_float`
- `get_int`
- `get_string`

**Function Collision:**

For any reason you have a function named the same as one in a library, you can specify that you want to use the library's function by prefixing it with the library name. For example:

```python
import cs50
x = cs50.get_int("x: ")  # it won't collide with your function
```
**Conditionals in Python:**

```python
if x > y:
    print("X is bigger than Y")
elif x < y:
    print("X is smaller than Y")
else:
    print("X is equal to Y")
```
**String Comparisons in C vs Python:**

In C, comparing strings using `==` compares memory addresses. You use `strcmp` to compare the actual content. In Python, you can use `==` to compare strings directly.

**Logical Operators Example:**

In C:

```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree? ");
    if (c == 'Y' || c == 'y')
    {
        printf("Agreed.\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not agreed.\n");
    }
}
```
In Python:

```python
from cs50 import get_string

# Prompt user to agree
s = get_string("Do you agree? ")

# Check whether agreed
if s == "Y" or s == "y":
    print("Agreed.")
elif s == "N" or s == "n":
    print("Not agreed.")
```

Another approach using lists:

```python
from cs50 import get_string

# Prompt user to agree
s = get_string("Do you agree? ")

# Check whether agreed
if s in ["y", "yes"]:
    print("Agreed.")
elif s in ["n", "no"]:
    print("Not agreed.")
```

**Methods and Object-Oriented Programming:**

When a function belongs to a specific object, it is known as a method. Methods are functions built inside objects. For example:

```python
from cs50 import get_string

# Prompt user to agree
s = get_string("Do you agree? ").lower()

# Check whether agreed
if s in ["y", "yes"]:
    print("Agreed.")
elif s in ["n", "no"]:
    print("Not agreed.")
```

**Loops:**

`while` loop:

```python
i = 0
while i < 3:
    print("meow")
    i += 1
```
`for` loop:

```python
for i in range(3):
    print("meow")
```
`do while` loop in Python:

```python
while True:
    # your code here
    break
```

**Functions:**
```python
def functionName():
    # code here

def main():
    meow(3)

def meow(n):
    for i in range(n):
        print("meow")

main()
```

**Truncation:**

Truncation does not occur in Python. Python handles floating-point precision better.

**Floating Point Imprecision:**

```python
z = x / y
print(f"{z:.50f}")
```

**Integer Overflow:**

Integer overflow does not occur in Python. The size of the `int` will grow to fit the number.

**Exceptions:**

```python
def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Not an integer")

def main():
    x = get_int("x: ")
    y = get_int("y: ")
    print(x + y)

main()
```

**Mario:**

```python
print("?" * 4)

for i in range(3):
    print("#" * 4)
```

**Lists:**

Lists are a data structure in Python with built-in methods:

```python
scores = [72, 73, 33]
average = sum(scores) / len(scores)

names = ["Carter", "David", "John"]
name = input("Name: ")

for n in names:
    if name == n:
        print("Found")
        break`
else:
    print("Not found")
```

Using `in` for linear search:

```python
names = ["Carter", "David", "John"]
name = input("Name: ")

if name in names:
    print("Found")
else:
    print("Not found")
```

**Dictionaries:**

```python
from cs50 import get_string`

people = [
    {"name": "Carter", "number": "+1-617-495-1000"},
    {"name": "David", "number": "+1-617-495-1000"},
    {"name": "John", "number": "+1-949-468-2750"},
]

name = get_string("Name: ")
for person in people:
    if person["name"] == name:
        print(f"Found {person['number']}")
        break
else:
    print("Not found")
```
Using a simplified dictionary:

```python
people = {
    "Carter": "+1-617-495-1000",
    "David": "+1-617-495-1000",
    "John": "+1-949-468-2750",
}

name = get_string("Name: ")
if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not found")
```

**Conclusion:**

One of the advantages of Python is its massive user-base and similarly large number of third-party libraries.
