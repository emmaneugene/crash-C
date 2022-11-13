# CA code clinic 2

## A brief introduction to programming in C

### Overview

1. "Hello world"
2. Variables, datatypes, conventions
3. Operators and precedence
4. Conditionals
5. Loops
6. Functions
7. Arrays, pointers and memory
8. Strings
9. Structs
10. Tips, tools and resources

### 1. Hello world

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
		printf("Hello, world!\n");
}
```

- What's the significance of:
  - `#include`?
  -  `stdio.h`?
  -  `main`?
  -  `int argc, char *argv[]`?
- How do you run this program? What are the steps involved, and why do we need them?

### 2. Variables, datatypes, conventions

- Basic datatypes: `char`, `short`, `int`, `long`, `float`, `double`

- The `sizeof` operator tells you how much space the datatype occupies up in *bytes*

- It's possible to 'convert' one datatype into another with typecasting

- Variables can be *declared*, *assigned* or *initialized*

- Naming conventions in C:

  - use alphanumeric characters, `_` as a substitute for whitespace

  - lowercase for local variables
  - uppercase for constants
  - first character should not be a number

### 3. Operators and precedence

- Similar to BODMAS in mathematics, operators in C also have their own levels precedence
- Find out more about precedence [here](https://www.tutorialspoint.com/cprogramming/c_operators_precedence.htm)
- If unsure, it never hurts to use parentheses () 

### 4. Conditionals

- Using boolean logic to control the execution specific blocks of code
- De Morgan's theorem (prove it for yourself with a truth table)
- Short-circuiting operators:  `||` ,  `&&`

### 5. Loops

- Repeating blocks of code until a certain stopping condition is met (still a boolean)
- What's the difference between `for`, `while`, `do while`? Is it possible to convert one into the other?
- Nested loops

### 6. Functions and scope

- Distinguish between function *declaration* vs *implementation*

```c
// Declaration
void common_factors(int x, int y);

// Implementation
void common_factors(int x, int y) {
		int lowest = x < y ? x : y;
		
		for (int i = 2; i <= lowest; i++) {
				if (x % i == 0 && y % i == 0) {
						printf("Common factor: %d\n", i)
				}
		}
}
```

- Understand the concept of a *function frame*, *stack* and *heap*
- Understand the general intuition behind recursion

### 7. Arrays, pointers and memory allocation

- What is an array? What makes it useful?
  - Contiguous block of memory for storing a certain datatype

- What is a pointer? What makes it useful
- null reference
- Passing by *reference* vs passing by *value*
- Visualizing using memory state diagrams
- `malloc`, `calloc` and `free` - how do they work? 

### 8. Strings

- All strings are `char` arrays

- How do we know when a string terminates?

- Strings declared using `*` are immutable

  ```c
  #include <stdio.h>
  
  void fun(char *str) {
      printf("%c\n", str[1]);
      str[1] = 'a';
  }
  
  int main(void) {
      char *mystr = "Hello"; // constant, immutable, read-only
      char mystr2[] = "Testing"; // mutable
  
      fun(mystr2);
      printf("%s\n", mystr);
      printf("%s\n", mystr2);
  }
  ```

  

### 9. Structs

- Logical grouping of datatypes, allowing for greater abstraction
- Foundation for Object-Oriented Programming (your next course)

### 10. Useful libraries, tips, tools and resources

#### Libraries

- `string.h`

- `math.h`
- `stdlib.h`
- `limits.h`

- Feel free to make your own as well!

#### Tips

- Get comfortable with the command line

- Read and understand your compile and runtime errors

- Write comments to structure your logic, or as a placeholder for future code

- Pay attention to variable names, especially as code gets more complex

- Handle corner cases first

  ❌ Don't do this

  ```c
  int main(void) {
  		if (!/*corner case*/) {
  				// Main body
  		}
  		// Handle corner case
  }
  ```

  ✅ Do this

  ```c
  int main(void) {
  		if (/*corner case*/) {
  				// Handle corner case
  				return
  		}
  		
  		// Main body
  }
  ```

  

- Revisit old problems and come up with better solutions. Be able to explain the tradeoffs involved with each 

#### Resources

<u>Command line</u>:

- [The Missing Semester](https://missing.csail.mit.edu/)
- [Linux commands](https://www.freecodecamp.org/news/the-linux-commands-handbook/)

<u>General learning</u>:

- [Cheatsheets](https://github.com/emmaneugene/cheatsheets)

- [Use The Keyboard](https://usethekeyboard.com/)

- [X in Y minutes](https://learnxinyminutes.com/)

- [Visual Algo](https://visualgo.net/en)

- [Roadmaps](https://roadmap.sh/)

  