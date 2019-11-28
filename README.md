![GitHub Logo](https://www.holbertonschool.com/holberton-logo.png)


# simple_shell

simple_shell is a command line interpreter, this shell is a limited version from Ken Thomas (1971) original shell. This project is developed for the full-stack program of Holberton School.

## Implementation

Clone it from GitHub [simple_shell](https://github.com/JDorangetree/simple_shell.git) to install locally.

```bash
git clone https://github.com/JDorangetree/simple_shell.git
```

When downloaded compile as follows
```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
And to launch it, excecute the following command.
Interactive mode
```./hsh```
Non interactive mode
```echo "ls" | ./hsh```
## Requirements
simple_shell is designed to run in the Ubuntu 14.04 LTS linux environment and to be compiled using the GNU compiler collection v. ```gcc 4.8.4``` with flags```-Wall```, -```Werror```, ```-Wextra```, and ```-pedantic```.

## Usage
This simple_shell is meant to intepretate simple commands as ```sh``` does, with limited functionallity. The next fucntionalities are tested and are available to use.
### Features


- [x] handles command line arguments
- [x] uses exit built-in
- [x] shell continues upon Crtl+C (**^C**)
- [x] handles comments (#)
- [x] Interactive and non-interactive mode.

| Function | Description |
| ------ | ------ |
| exit_ | `Handle exit syscall` |
| ctrl_c | `Manage ctr^C signal` |
| access_ | `fork process for commands execution` |
| prerror | `prints the errors` |
| _putchar | `print a character` |
| print_n | `print a number |
| print_unsigned_int | `prints an integer` |
| tokenizer | `custom function to tokenize an array of pointers` |
| _strlen | `return the length of a string` |
| word_count | `counts the number of words of a string` |
| own_free | `custom function to free an array of pointers` |

## Usage examples
#### Interactive mode
```
$ ./hsh
$ /bin/ls -l
total 104
-rw-r--r--  1 juanzuluagapizza  staff     15 Nov 18 17:51 README.md
-rw-r--r--  1 juanzuluagapizza  staff    522 Nov 22 08:21 _own_realloc.c
-rw-r--r--  1 juanzuluagapizza  staff   1262 Nov 19 10:02 _strtok.c
-rwxr-xr-x  1 juanzuluagapizza  staff  13992 Nov 19 16:09 a.out
drwxr-xr-x  3 juanzuluagapizza  staff     96 Nov 19 14:16 a.out.dSYM
-rwxr-xr-x  1 juanzuluagapizza  staff  13344 Nov 22 08:52 hsh
-rw-r--r--  1 juanzuluagapizza  staff    226 Nov 22 08:21 orange.h
-rw-r--r--  1 juanzuluagapizza  staff   1415 Nov 22 17:03 orangesh.c
```
#### Non-Interactive mode

```
$ echo "/bin/ls -l" | ./hsh
total 104
-rw-r--r--  1 juanzuluagapizza  staff     15 Nov 18 17:51 README.md
-rw-r--r--  1 juanzuluagapizza  staff    522 Nov 22 08:21 _own_realloc.c
-rw-r--r--  1 juanzuluagapizza  staff   1262 Nov 19 10:02 _strtok.c
-rwxr-xr-x  1 juanzuluagapizza  staff  13992 Nov 19 16:09 a.out
drwxr-xr-x  3 juanzuluagapizza  staff     96 Nov 19 14:16 a.out.dSYM
-rwxr-xr-x  1 juanzuluagapizza  staff  13344 Nov 22 08:52 hsh
-rw-r--r--  1 juanzuluagapizza  staff    226 Nov 22 08:21 orange.h
-rw-r--r--  1 juanzuluagapizza  staff   1415 Nov 22 17:03 orangesh.c
```
## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Authors
[Julian Naranjo](https://github.com/JDorangetree) 
[Juan Pablo Zuluaga](https://github.com/juanzuluaga91/)