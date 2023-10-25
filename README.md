# 42-Get_next_line
42-Cursus : Get_next_line
# get_next_line - Reading Lines from a File Descriptor

## Description
**get_next_line** is a function that reads and returns a line from a file descriptor, one line at a time. It's a useful tool for reading text files in a sequential manner.

## Table of Contents
- [Mandatory Part](#mandatory-part)
- [Bonus Part](#bonus-part)

### Mandatory Part

**Parameters**:
- `fd`: The file descriptor to read from.

**Return Value**:
- Read line: Correct behavior
- NULL: There is nothing else to read, or an error occurred

**External Functions**: read, malloc, free

**Description**:
- This function returns a line read from a file descriptor.
- Repeated calls to `get_next_line()` allow you to read the text file pointed to by the file descriptor, one line at a time.
- It returns the line that was read or NULL if there is nothing else to read or if an error occurred.
- The returned line should include the terminating `\n` character, except if the end of the file was reached and does not end with a `\n` character.

**Buffer Size**:
- You can define the buffer size for `read()` by adding the `-D BUFFER_SIZE=n` option to your compiler call. The value of `n` can be modified.

### Bonus Part

**Bonus Part Requirements**:
- Develop `get_next_line()` using only one static variable.
- Your `get_next_line()` can manage multiple file descriptors at the same time.
