<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0:2d333b,50:58a6ff,100:3fb950&height=200&section=header&text=Minishell&fontSize=50&fontColor=ffffff&fontAlignY=35&desc=A%20POSIX-Compliant%20Shell%20in%20C&descSize=18&descAlignY=55&animation=twinkling" width="100%"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white"/>
  <img src="https://img.shields.io/badge/Norm-42-000000?style=for-the-badge&logo=42&logoColor=white"/>
  <img src="https://img.shields.io/badge/Build-Makefile-064F8C?style=for-the-badge&logo=cmake&logoColor=white"/>
  <img src="https://img.shields.io/badge/Status-Completed-3fb950?style=for-the-badge"/>
</p>

---

## 📖 About

**Minishell** is a lightweight POSIX-compliant shell built entirely in C as part of the [42 School](https://42.fr/) curriculum. It replicates core behaviors of `bash`, including command execution, pipes, redirections, environment variable expansion, and signal handling — all implemented from scratch using raw system calls.

> _"As beautiful as a shell."_ — 42 Subject

---

## ✨ Features

| Category | Details |
|:---------|:--------|
| **Prompt** | Interactive prompt with command history (`readline`) |
| **Builtins** | `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit` |
| **Execution** | Searches and launches executables via `PATH` or absolute/relative paths |
| **Pipes** | Full pipe chain support (`cmd1 | cmd2 | cmd3 | ...`) |
| **Redirections** | Input `<`, Output `>`, Append `>>`, Here-document `<<` |
| **Env Variables** | Expansion of `$VAR` and `$?` (last exit status) |
| **Quotes** | Single quotes `' '` (literal) and double quotes `" "` (with expansion) |
| **Signals** | `Ctrl+C`, `Ctrl+D`, `Ctrl+\` behave like in bash |

---

## 🏗️ Architecture

```
Minishell/
├── includes/
│   └── minishell.h          # Main header — structs, prototypes, macros
├── srcs/
│   ├── builtins/            # Built-in command implementations
│   │   ├── cd.c
│   │   ├── echo.c / echo_utils.c
│   │   ├── env.c
│   │   ├── exit.c / exit_utils.c
│   │   ├── export.c / export_utils.c
│   │   ├── pwd.c
│   │   └── unset.c
│   ├── lexer.c / lexer_utils.c        # Tokenization
│   ├── parser.c                        # AST construction
│   ├── make_token.c / token_utils.c    # Token management
│   ├── expand.c / expand_utils.c       # Variable expansion
│   ├── no_expand_quote.c / no_expand_utils.c  # Quote handling
│   ├── exec.c / exec_utils.c          # Command execution & fork
│   ├── pipe.c                          # Pipe management
│   ├── change_fd.c                     # File descriptor redirections
│   ├── init_cmd.c / cmd_utils.c        # Command struct init
│   ├── init_data.c / init_data_utils.c # Shell data initialization
│   ├── init_global.c                   # Global state
│   ├── signal.c                        # Signal handlers
│   ├── main.c / main_utils.c          # Entry point & REPL loop
│   ├── add_link.c / new_link.c        # Linked list operations
│   └── free_data.c                     # Memory cleanup
├── libft/                   # Custom C standard library (42)
└── Makefile                 # Build system
```

---

## 🔧 Shell Pipeline

```
Input ──▶ Lexer ──▶ Parser ──▶ Expander ──▶ Executor
  │         │         │           │            │
  │      Tokenize   Build      Resolve      Fork &
  │      input      command    $VARS &      execve()
  │      string     tree       quotes       with pipes
  │                                         & redirects
  ▼
Prompt (readline)
```

---

## 🚀 Getting Started

### Prerequisites

- **GCC** or **Clang**
- **Make**
- **readline** library (`libreadline-dev` on Debian/Ubuntu)

### Build & Run

```bash
# Clone the repository
git clone https://github.com/Wesper-Dev/Minishell.git
cd Minishell

# Compile
make

# Launch
./minishell
```

### Usage Examples

```bash
minishell$ echo "Hello, World!"
Hello, World!

minishell$ ls -la | grep ".c" | wc -l
24

minishell$ cat < input.txt > output.txt

minishell$ export USER=Arnaud && echo $USER
Arnaud

minishell$ << EOF cat
> line 1
> line 2
> EOF
line 1
line 2
```

---

## 🧪 Tested Against

- **Bash** reference behavior for all builtins
- Edge cases: empty commands, unclosed quotes, multiple pipes, nested redirections
- Signal handling in parent and child processes
- Memory leaks checked with **Valgrind**

---

## 📚 Key Concepts Learned

- **Process creation** — `fork()`, `execve()`, `waitpid()`
- **Inter-process communication** — `pipe()`, `dup2()`
- **File descriptor management** — redirections, here-documents
- **Lexing & Parsing** — tokenization, recursive descent
- **Signal handling** — `sigaction()`, terminal control
- **Memory management** — custom allocators, leak-free design

---

## 👥 Authors

- **[Arnaud Durand](https://github.com/Wesper-Dev)** — 42 Paris

---

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0:2d333b,50:58a6ff,100:3fb950&height=100&section=footer" width="100%"/>
</p>
