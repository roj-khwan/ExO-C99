# libexo
libexo is a library that was a combination of 3 sources file, create for the purpose of computing a game of tictactoe.

## Headers Files
## board.h
board.h was created for handle normal board logic, with a define board size in the header files, if desire you can fix the `BOARD_SIZE`. As far as I know the program was dynamically program to handle board of any size.
## game.h 
game.h was created for handle logic of a game tictactoe, this too was dynamically program to handle every board size
## bitutils.h
bitutils.h was create for two function, set and get a bit from an array of bytes.

## Functions
### game.h
- int checkfull(board_t board): check if the board is full or not.
- int checkwin(board_t board, uint8_t piece): check if the piece is win or not, determine by the alignment.
- int play(board_t board, uint8_t side, uint64_t pos): simple function to place and reject placing in case of out of bound or filled position.
- int display(board_t board): display the whold board from bottom to top suitable for numkeys user.
### board.h
- void create(board_t* out): allocate minimize amount of boardbyte_t for the board.
- int getpiece(board_t board, uint64_t pos): fetching the piece from the board data at given position.
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