# Week 3: Algorithms

## Overview
In Week 3 of CS50, we explored various algorithms and data structures, focusing on different types of searches, sorting algorithms, and the concept of recursion. We also learned about Big O, Omega, and Theta notations to analyze algorithm efficiency.

## Algorithms

### Divide and Conquer
- **Concept:** Divides the problem into smaller subproblems, solves each recursively, and combines results.
- **Time Complexity:** Often involves logarithmic time complexity (O(log n)).

### Hashing
- **Concept:** Uses hash functions to index into a table for efficient data storage and retrieval.

### Linear Search
- **Description:** Checks each element in sequence.
- **Time Complexity:** O(n)
- **Example Code:**
```c
for (int i = 0; i < n; i++) {
    if (array[i] == target) {
        return i;
    }
}
```

### Binary Search

- **Description:** Divides the search interval in half each time. Requires sorted data.
- **Time Complexity:** O(log n)
- **Example Code:**
```c
while (low <= high) {
    int mid = (low + high) / 2;
    if (array[mid] == target) {
        return mid;
    } else if (array[mid] < target) {
        low = mid + 1;
    } else {
        high = mid - 1;
    }
}
```

## Big O Notation

- O(1): Constant time.

- O(n): Linear time.

- O(n log n): Log-linear time, e.g., merge sort.

- O(n^2): Quadratic time, e.g., bubble sort.

- O(log n): Logarithmic time, e.g., binary search.

## Omega and Theta Notation

- Omega (Ω): Represents the best-case scenario for an algorithm's time complexity.

- Theta (Θ): Represents the exact asymptotic behavior, with both upper and lower bounds.

## Sorting Algorithms

### Selection Sort

- **Description:** Finds the smallest element and places it at the beginning.
- **Time Complexity:** O(n^2)
- **Pseudocode:**

```bash
For i from 0 to n–1
    Find smallest number between numbers[i] and numbers[n-1]
    Swap smallest number with numbers[i]
```

### Bubble Sort

- **Description:** Repeatedly swaps adjacent elements if they are out of order.
- **Time Complexity:** O(n^2) with a best case of O(n) if no swaps are needed.
- **Pseudocode:**

```bash
For i from 0 to n–2
    If numbers[i] and numbers[i+1] are out of order
        Swap them
    If no swaps
        Quit
```

### Merge Sort

- **Description:** Divides the array into halves, sorts them, and merges them.
- **Time Complexity:** O(n log n)
- **Pseudocode:**

```bash
If only one number
    Quit
Else
    Sort left half
    Sort right half
    Merge sorted halves
```

## Recursion

- **Concept:** A function calls itself to solve smaller instances of the problem.
- **Example Code:**

```c
void draw(int n) {
    if (n <= 0) {
        return;
    }
    draw(n - 1);
    for (int i = 0; i < n; i++) {
        printf("#");
    }
    printf("\n");
}
```

## Data Structures

### Custom Data Structures
- **Concept:** Use struct in C to define complex types.
- **Example Code:**

```c
typedef struct {
    string name;
    string number;
} person;

int main(void) {
    person people[3];
    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";
    people[1].name = "David";
    people[1].number = "+1-617-495-1000";
    people[2].name = "John";
    people[2].number = "+1-949-468-2750";

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

## Summary

This week covered algorithmic thinking, different search and sort algorithms, and recursion. Understanding these concepts is crucial for analyzing and improving algorithm efficiency.





