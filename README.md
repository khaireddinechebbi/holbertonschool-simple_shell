
# Table of contents

    - Holberton Simple Shell
    - What is the shell?
    - Essential Functionalities of the Simple Shell:
    - Files description
    - List of allowed functions and system calls for this project
    - USAGE
    - TEAM
    - Diagram


# Holberton Simple Shell

Holberton Simple Shell is a basic UNIX command interpreter written in C language for educational purposes. It implements a subset of the features found in the traditional Unix shell, such as executing commands, handling errors, and supporting basic built-in commands.

# What is the shell?

The shell is a program that takes commands from the keyboard via the terminal, and gives them to the operating system to perform.

## Essential Functionalities of the Simple Shell:

    Loop
    Read
    Parse
    Execute

## Files description

- shell.h
- shell.c
- execute.c
- search_path.c
- split_line.c
- AUTHORS 

## List of allowed functions and system calls for this project

 
    execve (man 2 execve)
    exit (man 3 exit)
    fflush (man 3 fflush)
    fork (man 2 fork)
    free (man 3 free)
    getline (man 3 getline)
    isatty (man 3 isatty)
    kill (man 2 kill)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (__xstat) (man 2 stat)
    lstat (__lxstat) (man 2 lstat)
    fstat (__fxstat) (man 2 fstat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)

## USAGE

You can try our shell by following these steps:

    Step 1: Clone our repository using this command, (you need to have git  
    installed on your machine first)

    git clone https://github.com/MatriMariem/simple_shell

    Step 2: Change directory to simple_shell: 

    cd simple_shell

    Step 3: Compile the C files in this way:   

    gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

    Step 4: Run the shell

    ./hsh

    Exiting the shell When you want to exit the shell,
    you can use one of the following methods:

    1: Type the command "exit"

    exit

    2: Press on Ctrl + D

# TEAM

salah essioui

khairechebbi

##              Diagram 
![This diagram explain how shell work](https://github.com/khaireddinechebbi/holbertonschool-simple_shell/blob/main/Diagramme%20sans%20nom.drawio.png)
