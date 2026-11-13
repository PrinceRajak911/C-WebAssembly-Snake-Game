# C WebAssembly Snake Game

A classic Snake game written in C and compiled to WebAssembly (WASM) using Emscripten[cite: 1, 2], rendered on an HTML5 `<canvas>` element[cite: 1].

## Overview

This project demonstrates how to separate core game logic from browser rendering[cite: 1, 2]:
* **Game Engine (`snake.c`)**: Manages the 20×20 grid state, snake movement, collision detection, food spawning, and score tracking[cite: 2].
* **Frontend (`index.html`)**: Captures keyboard events, runs the main game loop (`120ms` tick rate), and renders the state from WASM memory onto a `400x400` HTML5 canvas[cite: 1].

## Project Structure

* `snake.c` — Core C source code containing game state and exported getter/setter functions[cite: 2].
* `index.html` — Browser UI, input listeners, and HTML5 Canvas rendering loop[cite: 1].
* `snake.js` — Emscripten-generated JavaScript glue code that loads and initializes the WebAssembly module[cite: 1, 3].
* `snake.wasm` — Compiled WebAssembly binary containing the C game logic[cite: 3, 5].

## Controls

| Key | Action |
| :--- | :--- |
| **Arrow Keys** (`↑`, `↓`, `←`, `→`) | Steer the snake[cite: 1] |
| **Spacebar** | Restart the game[cite: 1] |

## Building from Source

To recompile `snake.c` into `snake.js` and `snake.wasm`[cite: 1, 2, 3], install the [Emscripten SDK](https://emscripten.org/) and run:

```bash
emcc snake.c -o snake.js \
  -s EXPORTED_FUNCTIONS="['_initGame', '_setDirection', '_stepGame', '_getSnakeX', '_getSnakeY', '_getLength', '_getFoodX', '_getFoodY', '_getGameOver', '_getScore']"
