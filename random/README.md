#### GENERAL

- This is the main working directiory. All code should start here.
- After you are done testing your [code](#about-the-code "About the code") copy the new files
    into the parent directory. Do not copy any file with a 
    main function in it.
- For clean directory try and use only the [main.c](#about-mainc "About main.c") for testing.
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

#### About **main.c**

- Use [#ifdef](https://gcc.gnu.org/onlinedocs/cpp/Ifdef.html#Ifdef-1) to comment out blocks of code.
- Place all test cases you need here.
- Use descriptive macro names that can be easily understood.
- Add a comment next to the macro definition if you can't
    come up with a descriptive name.
- Comment out your macro definition rather than deleting the
    entire code.

#### About the code

- Document properly!
- Group similar functions inside one file with a
    descriptive name.
