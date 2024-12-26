# Get Next Line

`get_next_line` is a function that allows you to read a line from a file descriptor, one line at a time, even if the line is very long or ends with a newline character. This project is a common exercise in C programming to understand file handling, dynamic memory allocation, and efficient algorithm design.

---

## Table of Contents

- [Introduction](#introduction)
- [How It Works](#how-it-works)
- [Project Requirements](#project-requirements)
- [Code Breakdown](#code-breakdown)
- [Testing](#testing)
- [Things to Consider](#things-to-consider)
- [Bonus Features](#bonus-features)
- [Key Concepts](#key-concepts)
- [Conclusion](#conclusion)

---

## Introduction

The `get_next_line` project is part of the 42 coding curriculum. The primary goal is to implement a function that reads and returns a line from a file descriptor. The function is designed to handle various edge cases, including large lines, files without newlines, and different buffer sizes.

Key learning objectives include:
- Handling multiple file descriptors simultaneously(in bonus part).
- Managing dynamic memory efficiently.
- Writing clean and reusable code.

---

## How It Works

The `get_next_line` function reads from a file descriptor (mandatory part) or more (bonus part) using a specified buffer size. It processes the data, stores it in memory, and returns one line at a time, including the newline character (if present).

Here's a high-level overview of the workflow:
1. Read data from the file descriptor into a buffer.
2. Append the data to a static variable to preserve state between function calls.
3. Extract the next line from the stored data.
4. Return the extracted line to the caller.
5. Repeat until the end of the file is reached.

---

## Project Requirements

To successfully complete the project, you must:

1. Implement the function prototype:
   ```c
   char *get_next_line(int fd);
   ```

2. Ensure the function works for:
   - Files of any size.
   - Standard input (`stdin`).
   - Multiple file descriptors simultaneously (in bonus).

3. Adhere to the following constraints:
   - Use only allowed functions: `read`, `malloc`, and `free`.
   - No memory leaks or invalid memory access.
   - Efficient handling of large files and buffer sizes.

4. Define a buffer size using the `BUFFER_SIZE` macro during compilation:
   ```bash
   gcc -D BUFFER_SIZE=42 -o get_next_line get_next_line.c
   ```
---

## Code Breakdown

The project typically consists of the following files:

- **get_next_line.c**: Contains the main logic to read and return the next line.
- **get_next_line_utils.c**: Helper functions for memory management and string operations.
- **get_next_line.h**: Header file with function prototypes and includes.

### Key Functions

1. **get_next_line**: The main function that reads a line from the file descriptor.
2. **ft_strjoin**: Concatenates two strings dynamically.
3. **ft_strchr**: Locates the first occurrence of a character in a string.
4. **ft_strdup**: Duplicates a string.
5. **ft_substr**:  Returns the substring of the given string.
---

## Testing

### Provided Test Cases

- **Basic Tests**: Verify the function reads lines correctly from a simple file.
- **Edge Cases**:
  - Empty files.
  - Files without newlines.
  - Very large files or lines.
- **Standard Input**: Test reading from the terminal.

### Custom Test Cases

You can create custom test files and use the function to validate behavior.

---

## Things to Consider

1. **Buffer Size**: The value of `BUFFER_SIZE` significantly affects performance. A larger buffer reduces the number of `read` calls but increases memory usage.
2. **Memory Leaks**: Ensure all allocated memory is freed appropriately.
3. **Static Variables**: Use a static variable to preserve the state across function calls.
4. **Error Handling**: Return `NULL` for invalid file descriptors or errors during reading.

---

## Bonus Features

### Multiple File Descriptor Support

The bonus part requires handling multiple file descriptors simultaneously. Use an array or a data structure to maintain separate states for each file descriptor.

### Improved Performance

Optimize string operations and minimize memory allocations for better performance.

---

## Key Concepts

### 1. Static variable

In C programming, a **static variable** is one that retains its value across multiple function calls, meaning that its value is preserved between invocations of the function in which it is defined. Static variables are initialized only once, and they do not get destroyed when the function exits, unlike automatic (local) variables that are destroyed when the function scope ends.

**Characteristics of Static Variables**

- Persistent Value Across Function Calls:

   - Static variables maintain their values between function calls, meaning they "remember" their value from the last time the function was called. This is in contrast to local variables, which are reinitialized each time the function is called.

- Memory Location:

   - Static variables are stored in the data segment of the memory (instead of the stack), unlike local variables which are stored on the stack.

- Scope:

   - The scope of a static variable is local to the function or file where it is declared, but its lifetime is extended for the duration of the program. Even though it behaves like a local variable in terms of scope, it acts like a global variable in terms of persistence.

- Initialization:

   - If a static variable is not explicitly initialized, it will automatically be set to ```zero``` for types like ```int```, and to ```NULL``` for pointer types, such as ```char*```. This is different from automatic local variables, which hold garbage values if not initialized.

**Syntax**
```c
static data_type variable_name;
```
- static: The keyword that makes the variable static.
- data_type: The type of the variable (e.g., int, char, etc.).
- variable_name: The name of the variable.

**Example 1: Static Variable Inside a Function**
```c
#include <stdio.h>

void counter() {
    static int count = 0;  // Static variable
    count++;
    printf("Count: %d\n", count);
}

int main() {
    counter();  // Count: 1
    counter();  // Count: 2
    counter();  // Count: 3
    return 0;
}
```

**Explanation**:

- The count variable inside the counter() function is static. It starts at 0 and is incremented with each call. Unlike a regular local variable, its value is preserved between function calls.
- Each time counter() is called, the value of count is increased, and the function outputs the updated value.

**Example 2: Static Variable with File Scope**
```c
#include <stdio.h>

static int num = 10;  // Static variable with file scope

void display() {
    printf("Number: %d\n", num);
}

int main() {
    display();  // Number: 10
    num = 20;
    display();  // Number: 20
    return 0;
}
```
**Explanation:**

- The num variable is declared static, which means it is only accessible within the file. If another file tries to access num, it will not be able to, because its scope is limited to the file in which it is declared.

**Key Points About Static Variables**

- Persistence: The value of a static variable persists across multiple function calls, making it useful for situations where you need to retain state information.
- Scope: While a static variable's lifetime is the same as the program’s execution, its scope is restricted to the block (or file) in which it is defined.
- Use in Recursion: Static variables are often used in recursive functions to retain information between recursive calls.
- Global Static Variables: If declared at file scope with the static keyword, they are only accessible within that file, making them invisible to other files (this helps in encapsulating variables to avoid conflicts).

**Advantages of Static Variables**

- Memory Efficiency: Static variables are allocated once and not reallocated during function calls.
- Persistence of State: They are ideal when you need to maintain state information between multiple invocations of a function, such as for counting function calls, accumulating results, or handling flags.
- Encapsulation: When used with file scope, they provide a form of encapsulation, as the variable is not accessible outside of the file, reducing the risk of accidental modification by other parts of the program.

In summary, static variables are useful for cases where you need to retain data across function calls or limit the visibility of variables to specific parts of your program while keeping them alive for the duration of the program’s execution.

### 2. BUFFER_SIZE

   - Definition: BUFFER_SIZE is a macro (constant) that determines the number of bytes the program will read at a time from a file descriptor using the read() system call.
   - Purpose: A larger BUFFER_SIZE reduces the number of read() calls by reading more data at once, while a smaller size minimizes memory usage but may require more calls.
   - Example:
```c
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
```
Here, BUFFER_SIZE is set to 42 bytes. The function will read up to 42 bytes from the file descriptor in one call.

### 3. read()

   - Definition: read() is a system call in C that reads a specified number of bytes from a file descriptor into a buffer.
   - Syntax:
```c
ssize_t read(int fd, void *buf, size_t count);
```
- fd: The file descriptor to read from.
- buf: A pointer to the memory where the read data will be stored.
- count: The maximum number of bytes to read.
- Return value: Returns the number of bytes actually read, 0 for end-of-file (EOF), or -1 for an error.
   - Example:
```
char buffer[43];
ssize_t bytes_read = read(fd, buffer, 42);
```

### 4. open()

- Definition: open() is a system call that opens a file and returns a file descriptor.
- Syntax:
```c
int open(const char *pathname, int flags, mode_t mode);
```
- pathname: The path to the file.
- flags: flags: Specifies the mode in which to open the file (e.g., O_RDONLY for read-only, O_CREAT to create the file if it doesn’t exist, or O_RDWR for read and write access,...etc).
- mode: Defines the file permissions to be set if the file is created (e.g., 0777 grants read, write, and execute permissions to the owner, group, and others).
- Return value: Returns a file descriptor on success or -1 on error.
Example:
```c
int fd = open("file.txt", O_RDONLY);
```

### 5. fd (File Descriptor)

- Definition: A file descriptor is an integer that uniquely identifies an open file within a process.
- Purpose: It acts as a handle for performing operations like read(), write(), or close() on the file.
- Common File Descriptors:
   - 0: Standard input (stdin).
   - 1: Standard output (stdout).
   - 2: Standard error (stderr).
- Example:
```c
int fd = open("file.txt", O_RDONLY);
if (fd < 0) {
    perror("Error opening file");
}
```

###  6. offset

- Definition: The offset refers to the position in a file where the next read or write operation will begin.
- How It Works: When a file is opened, the offset starts at 0 (the beginning of the file). As you read or write data, the offset moves forward. Functions like lseek() can manually adjust the offset(but it's forbidden).

### 7. System Call
- Definition: A system call is a low-level function provided by the operating system to interact with hardware and perform essential operations like file handling, process management, and communication.
- Purpose: System calls act as the bridge between user-space programs (like your C code) and the kernel.
- Examples:
   - File-related system calls: read(), write(), open(), close().
   - Process-related system calls: fork(), execve(), wait().
   - Memory-related system calls: mmap(), brk().
- How It Works: System calls are invoked by the program using special instructions that switch the CPU to kernel mode to execute privileged operations.
- Example:
```c
ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
```
---
## Conclusion

The `get_next_line` project is an excellent opportunity to enhance your understanding of file handling, memory management, and modular programming in C. By completing this project, you’ll gain valuable experience in developing efficient and reliable code that adheres to strict requirements.

Happy coding! 🚀
