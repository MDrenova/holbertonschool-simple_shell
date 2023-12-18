# Simple Shell in C

This project is a simple implementation of a shell in C. A shell, in computing, is a software program that provides an interface between the user and the operating system. Users issue commands through the shell, which interprets the commands and passes them onto the operating system to execute. It includes basic functionalities such as executing commands, handling environment variables, and tokenization.



## Table of Contents
1. [How This Code Works](#how%20this%20code%20works)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Testing](#Testing)
6. [Contributing](#contributing)
7. [Authors](#Authors)

## How This Code Works

The shell works by continuously prompting the user for input, interpreting the input as a command, and then executing the command. Here's a step-by-step breakdown of how the code works:

1. `main(int __attribute__((unused)) argc, char *argv[])`: This is the main function of the shell. It starts an infinite loop that prompts the user for input and reads the input line.

2. `command_read(char *s, char *name)`: This function is called within the main function. It reads the input command and decides what to do with it. If the command is "exit", it returns a signal to end the program. If the command is "env", it calls the `_printenv()` function to print the environment variables. Otherwise, it tokenizes the command into an array and passes it to the `execute()` function.

3. `_getenv(char *var)`: This function is used to get the value of an environment variable. It's used within the `command_path()` function to get the value of the "PATH" variable.

4. `command_path(char *cmd)`: This function is called within the `execute()` function. It finds the full path of a command by searching the directories listed in the "PATH" environment variable.

5. `execute(char *cmd_arr[], char *name)`: This function is called within the `command_read()` function. It executes the command. It first calls the `command_path()` function to get the full path of the command, then it uses the `fork` and `execve` system calls to create a new process and load the program into memory for execution.

6. `_printenv(void)`: This function prints the environment variables. It's called within the `command_read()` function when the "env" command is entered.

Each function is designed to handle a specific task, making the code modular and easier to understand and debug.

## Features
- The shell reads line by line from the standard input.
- The shell parses the line into tokens (e.g., paths).
- The shell can be exited using `exit` command.
- The shell executes the command and waits for the command to finish, i.e., `waitpid`.
- The shell allows changing directories using `cd` command.

## Installation
To install the shell, follow these steps:
1. Clone the repository: `git clone https://github.com/yourusername/simple-shell.git`
2. Navigate to the project directory: `cd simple-shell`

## Usage

To use this shell, follow these steps:


1. Compile the C files using the following command: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
2. Run the resulting executable: `./hsh`
3. You will be greeted with a **'$'** prompt where you can start entering your commands.
4. `exit`: Exits the shell.

## Testing

To test the shell, you can enter commands at the prompt and observe the output. 

Here is a simple example:

1. **Script Test:**

    After starting the shell, type `ls -l` and press enter. The shell should list the contents of the current directory in a long listing format, just like the standard `ls -l` command in Unix-based systems.


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change. Please make sure to update tests as appropriate.

## Authors

- [Arbes Avdiaj](https://github.com/arbesavdiaj)

- [Mateo Drenova](https://github.com/MDrenova)

- [Blerim Balliu](https://github.com/blerim2)

- [Ralf Semi](https://github.com/rifla93)


