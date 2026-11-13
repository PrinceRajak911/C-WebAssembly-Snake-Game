#include <stdlib.h>

#define GRID 20

int snakeX[400], snakeY[400];
int length = 3;
int foodX = 5, foodY = 5;
int dirX = 1, dirY = 0;
int isGameOver = 0;
int score = 0;

void initGame() {
    length = 3;
    isGameOver = 0;
    score = 0;
    dirX = 1; 
    dirY = 0;

    for (int i = 0; i < length; i++) {
        snakeX[i] = 10 - i;
        snakeY[i] = 10;
    }
}

void setDirection(int dir) {
    if (dir == 0 && dirY != 1)  { dirX = 0;  dirY = -1; } // Up
    if (dir == 1 && dirY != -1) { dirX = 0;  dirY = 1;  } // Down
    if (dir == 2 && dirX != 1)  { dirX = -1; dirY = 0;  } // Left
    if (dir == 3 && dirX != -1) { dirX = 1;  dirY = 0;  } // Right
}

void stepGame() {
    if (isGameOver) return;

    for (int i = length - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    snakeX[0] += dirX;
    snakeY[0] += dirY;

    if (snakeX[0] < 0 || snakeX[0] >= GRID || snakeY[0] < 0 || snakeY[0] >= GRID) {
        isGameOver = 1;
        return;
    }

    for (int i = 1; i < length; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
            isGameOver = 1;
            return;
        }
    }

    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        if (length < 399) length++;
        score += 10;
        foodX = rand() % GRID;
        foodY = rand() % GRID;
    }
}

int getSnakeX(int index) { return snakeX[index]; }
int getSnakeY(int index) { return snakeY[index]; }
int getLength()          { return length; }
int getFoodX()           { return foodX; }
int getFoodY()           { return foodY; }
int getGameOver()        { return isGameOver; }
int getScore()           { return score; }