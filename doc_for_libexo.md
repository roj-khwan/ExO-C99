# libexo.a
libexo is a library that was a combination of 3 sources file, create for the purpose of computing a game of tictactoe.

## Structure
libexo was create in structure of this
```
game.h -> board.h -> bitutils.h
```
But there maybe a time where you only want to use bitutils for your code, but not the whole game, so I create a total of 4 libraries!
### Libraries
#### libgame.a
depend on libboard.a and handle high-level game logics such as check win/full, play, and display the board.
#### libboard.a
depend on libbitutils.a and handle base board level stuffs, such as create and destroy, get and set.
#### libbitutils.a
low level bit manipulation tools, do not depend on any libs, they handle only low-level bit stuff, get and set.
#### libexo.a
simply an interface wrapper for the app/main.c to use.
Despite my word choices of dependencies, each library can run on their own without the need of the depending library due to being static library.

## Functions
### game.h
- int checkfull(board_t board): check if the board is full or not.
- int checkwin(board_t board, uint8_t piece): check if the piece is win or not, determine by the alignment.
- int play(board_t board, uint8_t side, uint64_t pos): simple function to place and reject placing in case of out of bound or filled position.
- int display(board_t board): display the whold board from bottom to top suitable for numkeys user.
### board.h
- void create(board_t* out): allocate minimize amount of boardbyte_t for the board.
- int getpiece(board_t boa
Despite my word choices of dependencies, each library can run on their own without the need of the depending library due to being static library.rd, uint64_t pos): fetching the piece from the board data at given position.
- int place(board_t board, uint8_t side, uint64_t pos): placing piece at given pos without any care and will overwrite the position.
- int checkpattern(board_t board, uint64_t* arr, size_t length, uint8_t piece): check if the given position in the arr was all matching with the given piece.
- void destroy(board_t out): free the allocated memory from the board.
### bitutils.h
- int setbit(byte_t* target, uint64_t bit, uint8_t value): set bit at the given postion in the array of bytes.
- int getbit(byte_t* target, uint64_t bit): get bit at the given postion in the array of bytes.

## Types
`byte_t`: `uint8_t`
`boardbyte_t`: `uint8_t` byte use for board.
`board_t`: `boardbyte_t*` | `uint8_t*` use for concatnation the need to type all the long name and prevent type errors.
