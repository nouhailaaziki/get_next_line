# Get Next Line

`get_next_line` is a function that allows you to read a line from a file descriptor, one line at a time, even if the line is very long or ends with a newline character. This project is a common exercise in C programming to understand file handling, dynamic memory allocation, and efficient algorithm design.

---

## Table of Contents

- [Introduction](#introduction)
- [How It Works](#how-it-works)
- [Project Requirements](#project-requirements)
- [Usage](#usage)
- [Code Breakdown](#code-breakdown)
- [Testing](#testing)
- [Things to Consider](#things-to-consider)
- [Bonus Features](#bonus-features)
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

## Usage

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd get_next_line
   ```

2. Compile the code:
   ```bash
   gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
   ```

3. Test the function with a sample file:
   ```bash
   ./gnl < test_file.txt
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

## Conclusion

The `get_next_line` project is an excellent opportunity to enhance your understanding of file handling, memory management, and modular programming in C. By completing this project, you’ll gain valuable experience in developing efficient and reliable code that adheres to strict requirements.

Happy coding! 🚀
