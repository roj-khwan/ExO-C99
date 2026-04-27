# ExO-C99
ExO-C99 is simply a tictactoe program that is written in c programming language, as a personal project of mine on messing with bit and byte.

## Description
ExO-C99 as an program is a simply two player tictactoe, that was optimized for space.
### Library
ExO-C99 offer a library that able to use on other program called [libexo](doc_for_libexo.md)

## How to use
### Requirements
- Make 4.3+
- C Compiler, in my case I use gnu 13.3.0+
In case of interest of the program or the library, it can be simply done by downloading the program thru favorable method.
If the files were present, please run the given command on your command prompt/terminal in the project.
```bash
make
```

### How the game run
- The game start with a question of where to place the first piece, O.
- Players allow to choose from position 1 - 9, as given in the diagram below.
```
789
456
123
```
- The program will invalidate invalid input and given another chance to player in the case.
- As player progress the program will switch the side automatically, and also checking the win and others board's state at the end of every turn.
the first one to make 3 in a row will win!!! :)

## Features
- Fast and Memory Optimized
- Able to used its API of libexo.a for others project with tictactoe.
- Fun little game

## License
MIT License, so basically free use, you can use it however you like ;)