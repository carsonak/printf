#### GENERAL

- This is the main working directiory. All code should start here.
- After you are done testing your [code](#about-the-code "About the code") copy the new files
    into the parent directory. Do not copy any file with a 
    main function in it.
- For a clean directory and files place test-files in [test-files](#about-test-files "About Test-Files").
- Follow [the cycle!](#the-cycle "The cycle")
- Compiling command: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o printf

#### The cycle

1. ***PULL* ON MAIN**
2. ***BRANCH* / *SWITCH* TO BRANCH**
3. **CODE**
4. ***SWITCH* TO MAIN**
5. ***PULL***
6. ***MERGE* BRANCHES**
7. **REPEAT**

#### About **Test-Files**

- Place all test files that you need in [test-files](../testfiles "test-files directory"). Copy them
    into your working directory to test your code.
- After you are done with your test file remove it from all other
    directories except [test-files](../testfiles "test-files directory").

#### About the code

- Document properly!
- Group similar functions inside one file with a descriptive name.
- Before storing any characters inside the buffer make sure to
    check if it is full and flush it if is full.
- The Buffer has its own **[independent index](_printf.c "#L13: buffer_index")**. Pointer *[buf_i](_printf.c "#L19: buf_i")* should
    point to this index at all times and is passed on to every
    function that writes content to the buffer in order to
    consistently keep track of the total number of characters in
    the buffer.
