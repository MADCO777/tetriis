#include "tetris.h"

// Variables globales
int board[HEIGHT][WIDTH] = {0};
HighScore highScores[MAX_SCORES];
int scoreCount = 0;
int currentScore = 0;
int level = 1;

// Formas de los tetrominos (7 tipos)
int shapes[7][4][4][4] = {
    // I-piece
    {{{0,0,0,0}, {1,1,1,1}, {0,0,0,0}, {0,0,0,0}},
     {{0,0,1,0}, {0,0,1,0}, {0,0,1,0}, {0,0,1,0}},
     {{0,0,0,0}, {0,0,0,0}, {1,1,1,1}, {0,0,0,0}},
     {{0,1,0,0}, {0,1,0,0}, {0,1,0,0}, {0,1,0,0}}},
    
    // J-piece
    {{{1,0,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}},
     {{0,1,1,0}, {0,1,0,0}, {0,1,0,0}, {0,0,0,0}},
     {{0,0,0,0}, {1,1,1,0}, {0,0,1,0}, {0,0,0,0}},
     {{0,1,0,0}, {0,1,0,0}, {1,1,0,0}, {0,0,0,0}}},
    
    // L-piece
    {{{0,0,1,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}},
     {{0,1,0,0}, {0,1,0,0}, {0,1,1,0}, {0,0,0,0}},
     {{0,0,0,0}, {1,1,1,0}, {1,0,0,0}, {0,0,0,0}},
     {{1,1,0,0}, {0,1,0,0}, {0,1,0,0}, {0,0,0,0}}},
    
    // O-piece
    {{{0,1,1,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}},
     {{0,1,1,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}},
     {{0,1,1,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}},
     {{0,1,1,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}}},
    
    // S-piece
    {{{0,1,1,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}},
     {{0,1,0,0}, {0,1,1,0}, {0,0,1,0}, {0,0,0,0}},
     {{0,0,0,0}, {0,1,1,0}, {1,1,0,0}, {0,0,0,0}},
     {{1,0,0,0}, {1,1,0,0}, {0,1,0,0}, {0,0,0,0}}},
    
    // T-piece
    {{{0,1,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}},
     {{0,1,0,0}, {0,1,1,0}, {0,1,0,0}, {0,0,0,0}},
     {{0,0,0,0}, {1,1,1,0}, {0,1,0,0}, {0,0,0,0}},
     {{0,1,0,0}, {1,1,0,0}, {0,1,0,0}, {0,0,0,0}}},
    
    // Z-piece
    {{{1,1,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}},
     {{0,0,1,0}, {0,1,1,0}, {0,1,0,0}, {0,0,0,0}},
     {{0,0,0,0}, {1,1,0,0}, {0,1,1,0}, {0,0,0,0}},
     {{0,1,0,0}, {1,1,0,0}, {1,0,0,0}, {0,0,0,0}}}
};

void clearScreen() {
    system("cls");
}

void setCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawASCIIArt() {
    printf("  _______ ______ _______ ______  _____ \n");
    printf(" |__   __|  ____|__   __|  ____|/ ____|\n");
    printf("    | |  | |__     | |  | |__  | (___  \n");
    printf("    | |  |  __|    | |  |  __|  \\___ \\ \n");
    printf("    | |  | |____   | |  | |____ ____) |\n");
    printf("    |_|  |______|  |_|  |______|_____/ \n");
    printf("                                       \n");
}

void showMainMenu() {
    int choice = 0;
    char input;
    
    while(1) {
        clearScreen();
        drawASCIIArt();
        
        printf("\n\n");
        printf("          === MENU PRINCIPAL ===\n");
        printf("          ┌───────────────────┐\n");
        printf("          │ 1. Jugar          │\n");
        printf("          │ 2. Instrucciones  │\n");
        printf("          │ 3. Puntajes Altos │\n");
        printf("          │ 4. Salir          │\n");
        printf("          └───────────────────┘\n");
        printf("\nSeleccione una opcion (1-4): ");
        
        input = getch();
        choice = input - '0';
        
        switch(choice) {
            case 1:
                playGame();
                break;
            case 2:
                showInstructions();
                break;
            case 3:
                showHighScores();
                break;
            case 4:
                clearScreen();
                printf("Gracias por jugar! Hasta pronto!\n");
                exit(0);
            default:
                printf("\nOpcion invalida! Presione cualquier tecla...");
                getch();
        }
    }
}

void showInstructions() {
    clearScreen();
    printf("=== INSTRUCCIONES DEL TETRIS ===\n\n");
    printf("OBJETIVO:\n");
    printf("Completar lineas horizontales con los bloques que caen.\n");
    printf("Cada linea completa se elimina y suma puntos.\n\n");
    
    printf("CONTROLES:\n");
    printf("← → : Mover pieza izquierda/derecha\n");
    printf("↓   : Bajar pieza mas rapido\n");
    printf("↑   : Rotar pieza\n");
    printf("ESPACIO : Bajar pieza al fondo\n");
    printf("P    : Pausar juego\n");
    printf("ESC  : Salir al menu\n\n");
    
    printf("ELEMENTOS VISUALES:\n");
    printf("□□□ - Bloque solido\n");
    printf("███ - Pieza actual\n");
    printf("Puntuacion - Puntos acumulados\n");
    printf("Nivel - Velocidad del juego\n\n");
    
    printf("Presione cualquier tecla para volver al menu...");
    getch();
}

void loadHighScores() {
    FILE *file = fopen("scores.dat", "rb");
    if (file == NULL) {
        // Crear puntajes por defecto si no existe el archivo
        for (int i = 0; i < MAX_SCORES; i++) {
            sprintf(highScores[i].name, "UVG");
            highScores[i].score = 1000 - (i * 100);
        }
        scoreCount = MAX_SCORES;
        return;
    }
    
    scoreCount = fread(highScores, sizeof(HighScore), MAX_SCORES, file);
    fclose(file);
}

void saveHighScore(int score) {
    char name[4];
    printf("\nNuevo puntaje alto! %d puntos\n", score);
    printf("Ingrese sus iniciales (3 letras): ");
    scanf("%3s", name);
    
    // Insertar en la posicion correcta
    int pos = -1;
    for (int i = 0; i < scoreCount; i++) {
        if (score > highScores[i].score) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1 && scoreCount < MAX_SCORES) {
        pos = scoreCount;
    }
    
    if (pos != -1) {
        // Mover puntajes hacia abajo
        for (int i = MAX_SCORES - 1; i > pos; i--) {
            highScores[i] = highScores[i-1];
        }
        
        strcpy(highScores[pos].name, name);
        highScores[pos].score = score;
        
        if (scoreCount < MAX_SCORES) {
            scoreCount++;
        }
        
        // Guardar en archivo
        FILE *file = fopen("scores.dat", "wb");
        if (file != NULL) {
            fwrite(highScores, sizeof(HighScore), scoreCount, file);
            fclose(file);
        }
    }
}

void showHighScores() {
    loadHighScores();
    
    clearScreen();
    printf("=== PUNTAJES DESTACADOS ===\n\n");
    printf("┌──────┬─────────┬────────┐\n");
    printf("│ Pos  │ Jugador │ Puntos │\n");
    printf("├──────┼─────────┼────────┤\n");
    
    for (int i = 0; i < scoreCount; i++) {
        printf("│ %-4d │   %-3s   │ %-6d │\n", i+1, highScores[i].name, highScores[i].score);
        if (i < scoreCount - 1) {
            printf("├──────┼─────────┼────────┤\n");
        }
    }
    printf("└──────┴─────────┴────────┘\n\n");
    
    printf("Presione cualquier tecla para volver...");
    getch();
}

void initBoard() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            board[y][x] = 0;
        }
    }
    currentScore = 0;
    level = 1;
}

void drawBoard() {
    clearScreen();
    printf("=== TETRIS - UVG ===\n");
    printf("Puntaje: %-6d  Nivel: %d\n", currentScore, level);
    printf("┌");
    for (int i = 0; i < WIDTH; i++) printf("──");
    printf("┐\n");
    
    for (int y = 0; y < HEIGHT; y++) {
        printf("│");
        for (int x = 0; x < WIDTH; x++) {
            if (board[y][x]) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("│\n");
    }
    
    printf("└");
    for (int i = 0; i < WIDTH; i++) printf("──");
    printf("┘\n");
    
    printf("Controles: ←→ mover  ↑ rotar  ↓ bajar  ESPACIO fondo  P pausa  ESC salir\n");
}

void drawTetromino(Tetromino *t, int visible) {
    for (int i = 0; i < 4; i++) {
        int x = t->blocks[i].x;
        int y = t->blocks[i].y;
        if (y >= 0) {
            setCursorPosition(x * 2 + 1, y + 4);
            if (visible) {
                printf("██");
            } else {
                printf("  ");
            }
        }
    }
}

int checkCollision(Tetromino *t) {
    for (int i = 0; i < 4; i++) {
        int x = t->blocks[i].x;
        int y = t->blocks[i].y;
        
        if (x < 0 || x >= WIDTH || y >= HEIGHT) {
            return 1;
        }
        
        if (y >= 0 && board[y][x]) {
            return 1;
        }
    }
    return 0;
}

void rotateTetromino(Tetromino *t) {
    Tetromino temp = *t;
    t->rotation = (t->rotation + 1) % 4;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (shapes[t->type][t->rotation][i][j]) {
                t->blocks[i].x = temp.blocks[0].x + j;
                t->blocks[i].y = temp.blocks[0].y + i - 1;
            }
        }
    }
    
    if (checkCollision(t)) {
        *t = temp;
    }
}

void mergeTetromino(Tetromino *t) {
    for (int i = 0; i < 4; i++) {
        int x = t->blocks[i].x;
        int y = t->blocks[i].y;
        if (y >= 0) {
            board[y][x] = 1;
        }
    }
}

int clearLines() {
    int linesCleared = 0;
    for (int y = HEIGHT - 1; y >= 0; y--) {
        int full = 1;
        for (int x = 0; x < WIDTH; x++) {
            if (!board[y][x]) {
                full = 0;
                break;
            }
        }
        
        if (full) {
            linesCleared++;
            for (int yy = y; yy > 0; yy--) {
                for (int x = 0; x < WIDTH; x++) {
                    board[yy][x] = board[yy-1][x];
                }
            }
            for (int x = 0; x < WIDTH; x++) {
                board[0][x] = 0;
            }
            y++;
        }
    }
    return linesCleared;
}

void updateScore(int lines) {
    int points = 0;
    switch(lines) {
        case 1: points = 100 * level; break;
        case 2: points = 300 * level; break;
        case 3: points = 500 * level; break;
        case 4: points = 800 * level; break;
    }
    currentScore += points;
    
    level = currentScore / 1000 + 1;
}

Tetromino createNewTetromino() {
    Tetromino t;
    t.type = rand() % 7;
    t.rotation = 0;
    
    // Posicion inicial (centro superior)
    int startX = WIDTH / 2 - 1;
    int startY = -2;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (shapes[t.type][0][i][j]) {
                t.blocks[i].x = startX + j;
                t.blocks[i].y = startY + i;
            }
        }
    }
    
    return t;
}

void playGame() {
    initBoard();
    loadHighScores();
    srand(time(NULL));
    
    Tetromino current = createNewTetromino();
    Tetromino next = createNewTetromino();
    
    int gameOver = 0;
    int paused = 0;
    clock_t lastTime = clock();
    
    while (!gameOver) {
        if (_kbhit()) {
            int key = _getch();
            
            if (key == 27) { // ESC
                return;
            }
            
            if (key == 'p' || key == 'P') {
                paused = !paused;
                if (paused) {
                    setCursorPosition(0, HEIGHT + 8);
                    printf("PAUSA - Presione P para continuar");
                } else {
                    setCursorPosition(0, HEIGHT + 8);
                    printf("                                  ");
                }
                continue;
            }
            
            if (!paused) {
                Tetromino temp = current;
                
                switch(key) {
                    case 75: // Left
                        for (int i = 0; i < 4; i++) temp.blocks[i].x--;
                        break;
                    case 77: // Right
                        for (int i = 0; i < 4; i++) temp.blocks[i].x++;
                        break;
                                       case 80: // Flecha abajo
                        for (int i = 0; i < 4; i++) temp.blocks[i].y++;
                        break;
                    case 72: // Flecha arriba (rotar)
                        {
                            Tetromino rotated = current;
                            rotated.rotation = (rotated.rotation + 1) % 4;
                            // Actualizar bloques según rotación
                            int idx = 0;
                            for (int i = 0; i < 4; i++) {
                                for (int j = 0; j < 4; j++) {
                                    if (shapes[rotated.type][rotated.rotation][i][j]) {
                                        rotated.blocks[idx].x = current.blocks[0].x - (current.blocks[0].x - j);
                                        rotated.blocks[idx].y = current.blocks[0].y - (current.blocks[0].y - i);
                                        idx++;
                                    }
                                }
                            }
                            if (!checkCollision(&rotated)) {
                                current = rotated;
                            }
                        }
                        continue;
                    case 32: // Espacio - bajar al fondo
                        while (!checkCollision(&temp)) {
                            current = temp;
                            for (int i = 0; i < 4; i++) temp.blocks[i].y++;
                        }
                        mergeTetromino(&current);
                        int lines = clearLines();
                        updateScore(lines);
                        current = next;
                        next = createNewTetromino();
                        if (checkCollision(&current)) {
                            gameOver = 1;
                        }
                        continue;
                }
                
                if (!checkCollision(&temp)) {
                    current = temp;
                }
            }
        }
        
        if (!paused) {
            clock_t now = clock();
            double elapsed = (double)(now - lastTime) / CLOCKS_PER_SEC;
            double speed = 1.0 / level;
            
            if (elapsed > speed) {
                Tetromino temp = current;
                for (int i = 0; i < 4; i++) temp.blocks[i].y++;
                
                if (!checkCollision(&temp)) {
                    current = temp;
                } else {
                    mergeTetromino(&current);
                    int lines = clearLines();
                    updateScore(lines);
                    current = next;
                    next = createNewTetromino();
                    if (checkCollision(&current)) {
                        gameOver = 1;
                    }
                }
                lastTime = now;
            }
        }
        
        drawBoard();
        drawTetromino(&current, 1);
        Sleep(50);
    }
    
    clearScreen();
    printf("=== FIN DEL JUEGO ===\n");
    printf("Tu puntaje: %d\n", currentScore);
    saveHighScore(currentScore);
    printf("Presione cualquier tecla para volver al menu...");
    getch();
}
