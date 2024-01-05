#ifndef GAME_H
#define GAME_H

#include "raylib.h"

#define WIN_RES_W 256
#define WIN_RES_H 192

typedef enum GameScreen { LOGO, TITLE, GAMEPLAY, ENDING } GameScreen;

// Actors
typedef struct Shoot {
    Vector2 position;
    Vector2 speed;
    float radius;
    float rotation;
    int lifeSpawn;
    bool active;
    Color color;
} Shoot;

typedef struct Player {
    Vector2 position;
    Vector2 speed;
    float acceleration;
    float rotation;
    Vector3 collider;
    Color color;
    Shoot shoot[10];
} Player;

typedef struct Meteor {
    Vector2 position;
    Vector2 speed;
    float radius;
    bool active;
    Color color;
} Meteor;

typedef struct Game {
    GameScreen current_screen;
    float screen_scale;
    int screen_width;
    int screen_height;
    bool game_paused;
    int frames_counter;
    Player player;
    Meteor meteor[8];
    bool game_over;
    bool victory;
    float ship_height;
    int destroyed_meteors_count;
} Game;

extern Game global;

void InitGame();         // Initialize game
void UpdateGame();       // Update game (one frame)
void DrawGame();         // Draw game (one frame)
void UnloadGame();       // Unload game assets

#endif // GAME_H