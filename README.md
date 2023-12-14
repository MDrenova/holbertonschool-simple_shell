# Simple Shell in C

## Table of Contents
1. [Description](#description)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Commands](#commands)
6. [Contributing](#contributing)

## Description
This project is a simple implementation of a shell in C. It demonstrates the basics of how a shell works. That is: read, parse, fork, exec, and wait. Since its purpose is to demonstrate, the shell is minimal and has very few commands. However, adding more features and commands should be relatively straightforward.

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
3. Compile the shell program: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Usage
To run the shell:
1. Make sure you are in the project directory.
2. Run the shell executable: `./shell`

## Commands
- `cd [directory]`: Changes the current directory to `[directory]`. If `[directory]` is not provided, changes to the HOME directory.
- `exit`: Exits the shell.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change. Please make sure to update tests as appropriate.

## Authors

- [Arbes Avdiaj](https://github.com/arbesavdiaj)

- [Mateo Drenova](https://github.com/MDrenova)

- [Blerim Balliu](https://github.com/blerim2)

- [Ralf Semi](https://github.com/rifla93)


