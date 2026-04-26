# ExO-C99 Task List

## Core Game Logic
- [x] Implement `place()` function in board.c - place pieces on board
- [ ] Implement win condition checking in game.c
- [ ] Implement draw condition checking
- [ ] Add move validation (check if position already occupied)
- [ ] Implement game state tracking (current player, game status)

## Board/Display
- [ ] Create board display/print function (visualize 3x3 grid)
- [ ] Add coordinate validation (0-8 or row/col conversion)
- [ ] Test board state persistence across operations

## Player & Game Flow
- [ ] Add player turn management (X vs O)
- [ ] Implement game initialization/reset
- [ ] Add game loop structure in main.c
- [ ] Add player input handling (console input parsing)
- [ ] Add undo/move history (optional)

## AI/Bot Implementation
- [ ] Implement Minimax algorithm (mentioned in README)
- [ ] Add bot player integration
- [ ] Test bot move selection
- [ ] Add difficulty levels (optional)

## Testing
- [ ] Add unit tests for `place()` function
- [ ] Add unit tests for win/draw conditions
- [ ] Add unit tests for move validation
- [ ] Add integration tests (full game flow)

## Polish
- [ ] Add error handling for invalid moves
- [ ] Add game end messages
- [ ] Clean up compiler warnings in board.c
- [ ] Add configuration file (if needed)
- [ ] Documentation for game rules

## Optional/Future
- [ ] Network multiplayer
- [ ] Save/load game state
- [ ] Performance benchmarks for minimax
- [ ] GUI version
