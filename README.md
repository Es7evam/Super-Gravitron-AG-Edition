# Super-Gravitron-AG-Edition

A super-gravitron based game, with an evolutionary algorithm approach in order to play it.

## Configuration
It is possible to change the speed of the game using the classes/globalconstants.hh final, there you find the refresh time for the blasts and the players

## Building
It is necessary to have libncurses installed, you can check on how to do it on your linux distribution.

To build, use:
```bash
make
```

To run the game standalone
```
./a.out
```

To run the game with the evolutionary algorithm.
```
./a.out evolution
```

To load the previous best score
```
./a.out evolution --load
```
