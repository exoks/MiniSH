
# **MiniSH** #
**MiniSH** is a simple shell like **bash**.
<img width="1164" alt="Image" src="https://github.com/user-attachments/assets/ac24122e-bed0-4d6b-9094-b734a7bcd6ed" />

## **Table of Contents** ## 
1. [Introduction](#MiniSH)  
2. [Features](#features)  
3. [MiniSH Struct](#minish-structure)
4. [How It Works](#how-it-works)
  - [1. User Input](#1-reads-user-input-from-the-terminal) 
  - [2. Lexer](#2-lexer) 
      - [Tokenizer](#tokenizer-lexical-analysis-)
      - [Analyzer](#analyzer-syntactic--semantic-checks-)
      - [Continuation prompts](#continuation-promptes-)
  - [3. Parser](#3-parser) 
    - [Example Command](#example-command-)
    - [Corresponding AST](#corresponding-ast--binary-tree)
  - [4. Expander](#4-expander)
      - [ENV Expansion](#env-expansion-var))
      - [Tilde Expansion (`~`)](#tilde-expansion-) 
      - [Wildcard Expansion](#wildcard-expansion-) 
      - [Exit Status Expansion](#exit-status-expansion-) 
      - [Heredoc](#heredoc-)
  - [5. Interpreter](#5-interpreter-executor)
      - [Sequential command separator `;`](#sequential-command-separator-)
      - [Logical Operators](#logical-operators--and-)
          - [`&&` operator](#--and-operator--)
          - [`||` operator](#--or-operator--)
      - [Pipeline Management](#pipeline-management-)
      - [Redirections Management](#manages-redirections--)
      - [Built-in Commands](#built-in-commands)
          - [Simple Commands]()
          - [Compound Commands]()
      - [External Commands](#external-commands)
      - [Subshells `(...)`](#subshells-)
      - [Signals Management](#signals-management)
5. [Usage Guide](#usage-guide)  

---

## **Features** ##
* **Interactive** shell prompt
* **Continuation prompt** to handle incomplete commands 
  * Pipe (`pipe>`)
  * Logical AND (`cmdand>`)
  * Logical OR (`cmdor>`)
  * Single Quote (`quote>`)
  * Double Quote (`dquote>`)
  * Subshells(`subsh..subsh>`)
* **Built-in** commands
  * `echo`
  * `cd`
  * `pwd`
  * `export`
  * `unset`
  * `env`
  * `exit`
  * `clear`
* Command Execution (with full path resolution)
* Environment variables (`$ENV`)
* Multi-pipe support (`cmd1 | cmd2 | cmd3`)
* Logical operators
  * `&&` - and operator
  * `||` - or operator
* Sequential command separator (`;`)
* Subshells (`(...)`)
* Redirections (`>`, `<`, `>>`)
* Heredoc (`<<`)
* Wildcards (`*`) for filename expansion
* Signal handling (`Ctrl+C`, `Ctrl+D`) 
* Variable expansion (`$VAR`)
* Error Handling
* Exit Status Codes
* `.git` directory detection
* Displays the current working directory in the `minish` prompt.
* History tracking

--- 

## **MiniSH Structure** ##
<img width="300" alt="Image" src="https://github.com/user-attachments/assets/ca150e0b-59c3-478e-8ac9-2c2f89fe9b3f" />

---

## **How It Works** ##
### 1. Reads user input from the terminal ###

### 2. **Lexer** ###
Responsible for breaking down the user's input command line into meaningful **tokens**, based on the [**Finite State Machine (FSM)**](https://en.wikipedia.org/wiki/Finite-state_machine) concept.
##### **Tokenizer (Lexical Analysis) :** #####
- Scans the input string and converts it into **tokens**, categorizing elements such as commands, operators, and literals...
##### **Analyzer (Syntactic & Semantic Checks) :** #####
- Validates the **token sequence**, detecting **syntax errors**, ensuring **logical token order** (Grammar), Identifying **incomplete token sequences** to display **Continuation promptes**.

> ##### **Continuation promptes :** ##### 
> <img width="500" alt="Image" src="https://github.com/user-attachments/assets/529e2f03-e9e3-4bed-9150-d84ada87a4dd" />
> <img width="500" alt="Image" src="https://github.com/user-attachments/assets/8d926069-73b7-4884-b651-4ac5ea1a2bd1" />
> <img width="500" alt="Image" src="https://github.com/user-attachments/assets/c6f4bf1e-3e25-4988-96de-8b0371efbb9f" />
> <img width="500" alt="Image" src="https://github.com/user-attachments/assets/53aa41c5-a852-45e9-af47-3e7306922b21" />
> <img width="500" alt="Image" src="https://github.com/user-attachments/assets/35f99dd2-1a6c-435a-b398-6c7f97059b83" />
> <img width="500" alt="Image" src="https://github.com/user-attachments/assets/def1e7d8-d7ab-4075-aba2-b88dba0c298d" />

### 3. **Parser** ###
Processes the **token sequence** and constructs an **Abstract Syntax Tree (AST)** using the **[Recursive Descent Parsing](https://www.geeksforgeeks.org/recursive-descent-parser/)** algorithm.
##### Example Command : #####
```bash
(cd && echo "=> /HOME" || echo "Failed") | grep "Changed" ; echo "End"
```
##### Corresponding AST : Binary Tree ####
```bash
                                          Root Node
                                            [`;`]
                                             / \
                                            /   \
                                        [`|`]   [echo "End"] 
                                        /   \
                                   [`()`]   [grep "Changed"]
                                     | 
                                   [`&&`]
                                   /    \
                                [cd]   [`||`]
                                       /    \
                                      /      \
                       [echo "=> /HOME"]    [echo "Failed"]
```
This shows how the command is split into parts, with each operator (`;`, `|`, `&&`, `||`, `()`) forming a node in the tree. The recursive descent parser processes each part in order of operator priority, ensuring the command is parsed and executed correctly.

---

##### MiniSH operators priority: ####
1. `;`
2. `&&` and `||`
3. Pipes `|` 
4. `cmds` and `subshell`

---

### 4. **Expander** ###
Responsible for handling **variable substitution** (`$USER`), **wildcard expansion** (`*`), and **tilde** (`~`) ...

##### **ENV Expansion (`$VAR`)** #####
  - Replaces variables with their values from the environment. 
  - Example : 
    ```bash
    echo "Hello, $USER"
    ```
  - If `$USER="oezzaou"`, it becomes:
    ```bash
    echo "Hello, oezzaou"
    ```

##### **Tilde Expansion (`~`)** ##### 
  - Expands `~` to the user's home directory (`$HOME`)
  - Example : 
    ```bash
    cd ~
    ```
  - If `$HOME=/home/hael-mou`, it expands to:
    ```bash
    cd /home/heal-mou
    ```
##### **Wildcard Expansion (`*`)** ##### 
  - Expands patterns into matching filenames
  - Example : 
    ```bash
    ls -rsl *.cpp 
    ```
  - If the directory contains `main.cpp` and `Class.cpp`, It expands to:
    ```bash
    ls -rsl main.cpp Class.cpp
    ```

##### **Exit Status Expansion (`$?`)** ##### 
  - Expands to the exit status of the last executed command.
  - Example : 
    ```bash
    echo $? 
    ```
  - If the last command is `command not found`, It will exit with `127` status code, it expands to:
    ```bash
    echo 127 
    ```

##### **Heredoc `<<`** #####
  - `heredoc` allows the user to redirect multi-line input into a command, typically for commands that expect input, such as `cat` or `sort`. 
  - Example : 
    ```bash
    cat << EOF 
    Hello, $USER from minish 
    ...
    EOF
    ```
    > - `cat` will receive the text between `<< EOF` and closing `EOF` as input  
    > - The `expander` first detects the `heredoc` operator (`<<`) in the parsed command  
    > - The `expander` extracts the delimiter  
    > - The `expander` reads `heredoc` content  
    > - The `expander` expands `heredoc` content (`$USER`, '~', ...)

### 5. **Interpreter (Executor)**
The interpreter is responsible for executing the Abstract Syntax Tree (AST) recursively.

##### **Sequential command separator (`;`)** #####
  - Commands separated by `;` are executed **sequentially**, regardless of **success** or **failure**.
  - Example:
    ```bash
    echo "Hello, MiniSH"; ls -l; pwd
    ```
    > `minish` executes `echo "Hello, MiniSH`.    
    > `minish` executes `ls -l`.  
    > `minish` executes `pwd`.  
    > Each command runs *independently*.

##### **Logical Operators (`&&` and `||`)** #####

###### `&&` ( and operator ) : ######
  - `&&` executes the second command only if the first one succeeds (exit status 0).
  - Example:
    ```bash
    cd ~ && echo "We are in $HOME"
    ```
    > If `cd ~` succeeds (exit status == 0), `echo "we are in $HOME` runs.    
    > If `cd ~` fails (exit status != 0), `echo "we are in $HOME` is skipped.    

###### `||` ( or operator ) : ######
  - `||` executes the second command only if the first one fails (nonzero exit status) 
    ```bash
    rm -r test/ || echo "no such file or directory"
    ```
    > If `rm` fails, echo runs to print an error message.
  - Example: Combining Both: `||` and `&&` 
    ```bash
    make && ./minish || echo "minish: Build failed"
    ```
    > If `make` succeeds, `./minish` runs.  
    > If either `make` or `./minish` fails, `echo "minish: Build failed"` runs.

##### **Pipeline Management (`cmd1` | `cmd2` | ... | `cmdn`)** ##### 
  - The Interpreter sets up pipes to connect multiple processes.
  - Example:
    ```bash
    cat hello.txt | awk '/World/{print $2}'
    ```
    > The shell creates a `pipe`.  
    > It forks two child processes:
    >   * `cat` writes to `pipe`'s write-end.  
    >   * `awk` reads from `pipe`'s read-end.

    > The `minish` ***waits*** for both processes.

##### **Manages Redirections (`<`, `>`, `>>` and `heredoc`-`<<`)** #####
  - If redirection is detected, The interpreter replaces standard (input/output) of the child process.
  - Example : 
    ```bash
    < infile.txt cat -e > outfile.txt
    ```
    > The `minish` redirects `stdin` to infile.txt.  
    > The `minish` redirects `stdout` to outfile.txt.

##### **Built-in Commands** ##### 
###### - **Simple Commands :** ######
  - When a command like `echo` or `cd` is used, the `minish` performs the operation directly **without forking** a new process.
  - Example : 
    ```bash
    cd
    ```
    > The `minish` changes the current directory itself (without calling `/bin/cd`).  
    > No child process is created

###### - **Compound Commands :** ######
  - When these built-in commands are combined with other shell constructs like pipes or subshells, the `minish` may need to **fork** a **new process** to execute them in the appropriate context. 
  - Example : 
    ```bash
    cd | ls
    ```
    > The `minish` won't change the current directory itself.  

##### **External Commands** #####
  - If the command is not built-in, the interpreter calls `fork()` and `execve()` ***syscalls*** to run the program.
  - Example : 
    ```bash
    ls -a
    ```
    > The `minish` forks a new ***child process**.    
    > The child process calls `execve("/bin/ls", ["ls", "-a"], env)`.  
    > The **parent process** ***waits** for the child to finish (`waitpid()`).

##### **Subshells `(...)`** #####
  - Commands inside **parentheses `()`** are executed in a **subshell** (a child process).
  - Example : 
    ```bash
    (cd ~ && ls)
    ```
    > The `minish` forks a new ***child process**.  
    > Inside the subshell, it changes the directory to `$HOME` and runs `ls`.  
    > The **parent `minish`’s** working directory is **unchanged**.

##### **Signals Management** ##### 
  - `Ctrl+C`: Sends a `SIGINT` signal, which interrupts the currently running command.
  - `Ctrl+D`: Sends an `EOF` (End of File) signal to the `minish`, causing it to exit or terminate the current command if no command is running.

---

## **Usage Guide** ##

1. Clone **MiniSH** repository: 
```bash
git clone https://github.com/exoks/MiniSH.git
cd MiniSH
```
2. Build `minishell` executable:
```bash
make
```
3. Run `minishell` executable
```bash
make run
```
---
