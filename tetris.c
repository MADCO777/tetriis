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
