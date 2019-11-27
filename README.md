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
This simple_shell is meant to intepretate simple commands as ```sh``` does, with limited functionallity. The next fucntionality are tested and are available to use.
## Example

### Features
- [x] uses the PATH
- [x] implements builtins
- [x] handles command line arguments
- [x] custom strtok function
- [x] uses exit status
- [x] shell continues upon Crtl+C (**^C**)
- [x] handles comments (#)
- [x] handles **;**
- [x] custom getline type function
- [x] handles **&&** and **||**
- [x] aliases
- [x] variable replacement
##### Output

```
$ ./hsh
$ ls -l
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