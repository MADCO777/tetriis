#ifndef TETRIS_H
#define TETRIS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 10
#define HEIGHT 20
#define MAX_SCORES 10

// Estructuras
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point blocks[4];
    int type;
    int rotation;
} Tetromino;

typedef struct {
    char name[3];
    int score;
} HighScore;

// Variables globales
extern int board[HEIGHT][WIDTH];
extern HighScore highScores[MAX_SCORES];
extern int scoreCount;

// Funciones del menú
void showMainMenu();
void showInstructions();
void showHighScores();
void playGame();

// Funciones del juego
void initBoard();
void drawBoard();
void drawTetromino(Tetromino *t, int visible);
int checkCollision(Tetromino *t);
void rotateTetromino(Tetromino *t);
void mergeTetromino(Tetromino *t);
int clearLines();
void updateScore(int lines);
void saveHighScore(int score);
void loadHighScores();
void drawASCIIArt();

// Utilidades
void clearScreen();
void setCursorPosition(int x, int y);
void setColor(int color);

#endif
