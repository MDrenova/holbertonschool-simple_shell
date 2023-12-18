# Simple Shell Project

This project is a simple implementation of a shell in C. A shell, in computing, is a software program that provides an interface between the user and the operating system[1]. Users issue commands through the shell, which interprets the commands and passes them onto the operating system to execute[6]. It includes basic functionalities such as executing commands, handling environment variables, and tokenization.

## How This Code Works

The shell works by continuously prompting the user for input, interpreting the input as a command, and then executing the command. Here's a step-by-step breakdown of how the code works:

1. `main(int __attribute__((unused)) argc, char *argv[])`: This is the main function of the shell. It starts an infinite loop that prompts the user for input and reads the input line.

2. `command_read(char *s, char *name)`: This function is called within the main function. It reads the input command and decides what to do with it. If the command is "exit", it returns a signal to end the program. If the command is "env", it calls the `_printenv()` function to print the environment variables. Otherwise, it tokenizes the command into an array and passes it to the `execute()` function.

3. `_getenv(char *var)`: This function is used to get the value of an environment variable. It's used within the `command_path()` function to get the value of the "PATH" variable.

4. `command_path(char *cmd)`: This function is called within the `execute()` function. It finds the full path of a command by searching the directories listed in the "PATH" environment variable.

5. `execute(char *cmd_arr[], char *name)`: This function is called within the `command_read()` function. It executes the command. It first calls the `command_path()` function to get the full path of the command, then it uses the `fork` and `execve` system calls to create a new process and load the program into memory for execution.

6. `_printenv(void)`: This function prints the environment variables. It's called within the `command_read()` function when the "env" command is entered.

Each function is designed to handle a specific task, making the code modular and easier to understand and debug.

## Learning Objectives

- Understanding of **Syscalls**
- Handling **Process Environment**
- Implementing **Tokenization**
- Understanding **Shell Execution Flow**

## Usage

To use this shell, follow these steps:

1. Clone the repository to your local machine.
2. Navigate to the directory containing the source files.
3. Compile the C files using the following command: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
4. Run the resulting executable: `./hsh`
5. You will be greeted with a "Welcome to Shell $" prompt where you can start entering your commands.

## Testing

To test the shell, you can enter commands at the prompt and observe the output. You can also write scripts with a series of commands and run them with the shell to see if the output matches your expectations.

Here are two simple examples:

1. **Single Command Test:**

    After starting the shell, type `ls -l` and press enter. The shell should list the contents of the current directory in a long listing format, just like the standard `ls -l` command in Unix-based systems.

2. **Script Test:**

    You can create a text file with a series of commands, each on a new line. For example, you might create a file called `test_script.txt` with the following contents:

    ```bash
    ls -l
    pwd
    echo Hello, World!
    ```

    Save and close `test_script.txt`, then run the script with the shell by typing `./hsh test_script.txt` in your terminal. The shell should execute each command in order and display the results.


## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
