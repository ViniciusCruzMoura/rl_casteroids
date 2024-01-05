#ifndef GAME_H
#define GAME_H

#include "raylib.h"

#define WIN_RES_W 256
#define WIN_RES_H 192

typedef enum GameScreen { LOGO, TITLE, GAMEPLAY, ENDING } GameScreen;

typedef struct Game {
    GameScreen current_screen;
    float screen_scale;
    int screen_width;
    int screen_height;
    bool game_paused;
    int frames_counter;
    int element_position_y;
} Game;

extern Game game;

void InitGame();         // Initialize game
void UpdateGame();       // Update game (one frame)
void DrawGame();         // Draw game (one frame)
void UnloadGame();       // Unload game assets

#endif // GAME_H