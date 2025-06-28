# 🖨️ ft_printf | 42 School Project

### Recreating the magic of `printf`, one format specifier at a time.

![42 School Badge](https://img.shields.io/badge/42-School-blue)
![Score](https://img.shields.io/badge/Score-125%2F100-brightgreen)

> *"The art of formatting output: A deep dive into variadic functions and flag parsing."*

---

## 🎯 Project Overview

`ft_printf` is a fundamental project at 42 School that requires us to re-create the functionality of the standard C library's `printf` function. This project is a major step in learning how to handle a variable number of arguments (variadic functions) and how to parse complex formatting flags to produce precisely formatted output.

My implementation successfully handles a variety of format specifiers and all the standard bonus flags.

---

## 🚀 Getting Started

#### 1. Clone the repository:

```bash
git clone https://github.com/MEHDIJAD/42cursus-ft_printf.git
```

#### 2. Navigate to the project directory:

```bash
cd 42Cursus-ft_printf
```
#### 3. Compile the library:

```bash
make
```

## ✨ Supported Conversions & Flags

This project handles the following conversions and formatting flags:

### Supported Conversions
| Specifier | Output Type |
| :---: | :--- |
| **`%c`** | A single character. |
| **`%s`** | A string of characters. |
| **`%p`** | A `void *` pointer address in hexadecimal format. |
| **`%d`** | A signed decimal integer. |
| **`%i`** | A signed integer in base 10. |
| **`%u`** | An unsigned decimal integer. |
| **`%x`** | An unsigned integer in lowercase hexadecimal format. |
| **`%X`** | An unsigned integer in uppercase hexadecimal format. |
| **`%%`** | A literal percent sign. |

### Bonus: Supported Flags
| Flag | Description |
| :---: | :--- |
| **`-`** | Left-justifies the output within the specified width. |
| **`+`** | Forces the display of a sign (`+` or `-`) for signed numbers. |
| **` ` (space)** | If no sign is written, a space is inserted before the value. |
| **`0`** | Pads the output with leading zeros instead of spaces. Ignored if `-` is present. |
| **`#`** | Prepends `0x` or `0X` for `%x` and `%X` specifiers. |
| **`.` (precision)**| Specifies the minimum number of digits to be written. For strings, it's the maximum number of characters. |
| **`(number)` (width)** | Specifies a minimum field width for the output. |

---

## 🪾 Project Structure
```bash
.
├── Makefile
├── ft_printf.c
├── ft_printf.h
└── print_utils
    ├── ft_print_percentage.c
    ├── ft_printaddress.c
    ├── ft_printchar.c
    ├── ft_printdigit.c
    ├── ft_printhex.c
    ├── ft_printstr.c
    ├── ft_printunsigned.c
    ├── ft_tools.c
    └── ft_utils.c

2 directories, 12 files
```
## 🤖 Code Flow & Logic

The core of `ft_printf` is a loop that iterates through the format string. When it encounters a `%`, it enters a parsing and dispatching phase.

```mermaid
%%{init: {'theme': 'base', 'themeVariables': { 'primaryColor': '#e3f2fd', 'secondaryColor': '#e8f5e9'}}}%%
flowchart TD
    A[Start ft_printf] --> B[Initialize va_list];
    B --> C{Loop through format string};
    C -- "char is not '%'" --> D[Write char & increment count];
    D --> C;
    C -- "char is '%'" --> E[Enter Parsing Phase];

    subgraph Parse[Parsing Phase]
        E --> F[ft_get_flags: Parse all flags like '-', '0', '+', '#', ' '];
        F --> G[ft_count_width: Parse field width];
        G --> H[ft_count_precision: Parse precision after '.'];
        H --> I[ft_skip: Find the format specifier e.g., 's', 'd'];
    end
    style Parse fill:#e3f2fd,stroke:#1565c0

    I --> J[Call ft_print_format];

    subgraph Dispatch[Dispatch & Print Phase]
        J --> K{Switch on format specifier};
        K -- 'c' --> L[ft_printchar];
        K -- 's' --> M[ft_printstr];
        K -- 'd', 'i' --> N[ft_printdigit];
        K -- 'p', 'x', 'X', 'u', '%' --> O[... and so on];
    end
    style Dispatch fill:#e8f5e9,stroke:#2e7d32

    O --> P[Add printed length to total count];
    P --> C;

    C -- "End of string" --> Q[va_end & Return total count];

    style Q fill:#d4edda,stroke:#155724,stroke-width:2px,color:#155724
```

## 📋 Usage Examples

**`main.c`**
```c
#include "ft_printf.h"

int main(void)
{
    char    *s = "Hello, World!";
    int     num = -42;
    void    *ptr = s;

    ft_printf("--- Testing ft_printf ---\n");
    ft_printf("String: [%s]\n", s);
    ft_printf("Number: [%d]\n", num);
    ft_printf("Pointer: [%p]\n", ptr);
    ft_printf("Unsigned: [%u]\n", 42);
    ft_printf("Hex: [%x] and [%X]\n", 255, 255);
    ft_printf("Character: [%c]\n", 'A');
    ft_printf("A percent sign: [%%]\n");
    ft_printf("\n--- Testing Flags ---\n");
    ft_printf("Width: [%10d]\n", num);
    ft_printf("Zero-padding: [%010d]\n", num);
    ft_printf("Left-justify: [%-10d]\n", num);
    ft_printf("Plus sign: [%+d]\n", 42);
    ft_printf("Space sign: [% d]\n", 42);
    ft_printf("Precision: [%.5s]\n", s);
    ft_printf("Hash flag: [%#x]\n", 99);

    return (0);
}
```
### Compile Command
```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o printf
```

### 🔁 Visualizing the `va_list` Lifecycle

```mermaid
sequenceDiagram
    participant main as "main()"
    participant ft_printf as "ft_printf()"
    participant va_list as "Argument Stack (va_list)"

    main->>ft_printf: Calls ft_printf("...", arg1, arg2)

    activate ft_printf
    ft_printf->>va_list: va_start(ap, format)
    note right of ft_printf: Initializes 'ap' to point to arg1

    loop For each '%'
        ft_printf->>va_list: va_arg(ap, type)
        va_list-->>ft_printf: Returns current argument (e.g., arg1)
        note right of ft_printf: 'ap' now points to the next argument
    end

    ft_printf->>va_list: va_end(ap)
    note right of ft_printf: Cleans up the list

    deactivate ft_printf
    ft_printf-->>main: Returns total character count
```


## ⚙️ Under the Hood: The Magic of Variadic Functions

**ft_printf works because of a set of C macros defined in <stdarg.h> that allow functions to accept a variable number of arguments.**

| Macro | Description |
| :--- | :--- |
| **`va_list`** | A special type that holds information about the variable arguments. Think of it as a pointer to the argument list on the stack. |
| **`va_start(ap, format)`** | Initializes the `va_list` (`ap`). It needs the last *named* argument (`format`) to know where the variable arguments begin on the stack. |
| **`va_arg(ap, type)`** | This is the workhorse. It retrieves the **next** argument from the list, assuming it is of the specified `type` (e.g., `int`, `char *`). It also advances the internal pointer to the next argument. This is why parsing the format specifier is so critical—you have to tell `va_arg` the correct type to pull. |
| **`va_end(ap)`** | Cleans up the `va_list` when you are done. It's essential for portability and avoiding undefined behavior. |

## 👨‍💻 Author

- 42 Intra: [eel-garo](https://profile.intra.42.fr/users/eel-garo)
- GitHub: [MEHDIJAD](https://github.com/MAHDIJAD)
