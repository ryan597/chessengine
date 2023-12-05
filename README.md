# chessengine

C++ chess engine

Beginning of a project to build my own chess engine along with GUI for playing against the engine.

First tasks:
- Design base classes for the board representation
- Enable pieces to move
- Generate all legal moves (if in check etc.)
- Update PGN with notations
- Basic GUI with pieces and ability to move them

## Building

Using the included `CMakeLists.txt` file.

```bash
git clone https://github.com/ryan597/chessengine.git
cd chessengine && mkdir build
cmake -S src -B build
cd build && make
```
