#include <string.h>
#include <stdio.h>
#include "game.h"

void InitGame() 
{
    global.current_screen = LOGO;
    global.screen_scale = 3.0;
    global.screen_width = WIN_RES_W*global.screen_scale;
    global.screen_height = WIN_RES_H*global.screen_scale;
    
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(global.screen_width, global.screen_height, "raylib - CPong");
    if (!IsWindowFullscreen()) {
        // global.screen_width = GetMonitorWidth(GetCurrentMonitor());
        // global.screen_height = GetMonitorHeight(GetCurrentMonitor());
        // global.screen_scale = global.screen_height/WIN_RES_H;
        global.screen_scale = global.screen_width/WIN_RES_W;
        SetWindowSize(global.screen_width, global.screen_height);
        // ToggleFullscreen();
    }

    global.game_paused = false;  // Game paused state toggle
    global.frames_counter = 0;  // General pourpose frames counter

    global.game_over = false;
    global.victory = false;
    global.destroyed_meteors_count = 0;

    // Initialization player
    global.player.position = (Vector2){global.screen_width/2, global.screen_height/2 - global.screen_height/2};
    global.player.speed = (Vector2){0, 0};
    global.player.acceleration = 0;
    global.player.rotation = 0;
    ship_height = (PLAYER_BASE_SIZE/2)/tanf(20*DEG2RAD);
    global.player.collider = (Vector3){
        global.player.position.x + sin(global.player.rotation*DEG2RAD)*(ship_height/2.5f), 
        global.player.position.y - cos(global.player.rotation*DEG2RAD)*(ship_height/2.5f), 
        12
    };
    global.player.color = LIGHTGRAY;

    

    // Initialization shoot

    // Initialization meteor

    SetTargetFPS(60);
}

void UpdateGame()
{
    switch(global.current_screen)
    {
        case LOGO: 
        {
            // Update LOGO screen data here!
            
            global.frames_counter++;
            
            if (global.frames_counter > 180) 
            {
                global.current_screen = TITLE;    // Change to TITLE screen after 3 seconds
                global.frames_counter = 0;
            }
            
        } break;
        case TITLE: 
        {
            // Update TITLE screen data here!
            
            global.frames_counter++;
            
            if (IsKeyPressed(KEY_ENTER)) global.current_screen = GAMEPLAY;

        } break;
        case GAMEPLAY:
        { 
            // Update GAMEPLAY screen data here!

            if (IsKeyPressed(KEY_SPACE)) global.game_paused = !global.game_paused;

            if (!global.game_paused)
            {
                // TODO: Gameplay logic

                //movimentar a nave, um botão para rotacionar, e outro para acelerar
                //movimentar uma lista de asteroides para N direções
                //a nave pode atirar um numero N de projeteis
                //se os projeteis passarem do limite da tela ele é destroidos
                //se já utilizou todos os projeteis, a nava nao pode atirar
                //se projetiu colidir com o asteroide entao ambos sao destroidos
                
            }

        } break;
        case ENDING: 
        {
            // Update END screen data here!
            
            global.frames_counter++;
            
            if (IsKeyPressed(KEY_ENTER))
            {
                // Replay / Exit game logic
                global.current_screen = TITLE;
            }
            
        } break;
        default: break;
    }
}

void DrawGame()
{
    BeginDrawing();

        // ClearBackground(RAYWHITE);
        ClearBackground(BLACK);
        
        switch(global.current_screen) 
        {
            case LOGO: 
            {
                // Draw LOGO screen here!
                
                DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
                
            } break;
            case TITLE: 
            {
                // Draw TITLE screen here!
                
                DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
                
                if ((global.frames_counter/30)%2 == 0) DrawText("PRESS [ENTER] to START", GetScreenWidth()/2 - MeasureText("PRESS [ENTER] to START", 20)/2, GetScreenHeight()/2 + 60, 20, DARKGRAY);

                //desenhar nave
                //desenhar uma lista de asteroides
                
            } break;
            case GAMEPLAY:
            { 
                // Draw GAMEPLAY screen here!
                
            } break;
            case ENDING: 
            {
                // Draw END screen here!
                
                DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                
                if ((global.frames_counter/30)%2 == 0) DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth()/2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20)/2, GetScreenHeight()/2 + 80, 20, GRAY);
                
            } break;
            default: break;
        }
        /** 
        char buf[1024];
        snprintf(
            buf, 1024, 
            "Debug:\n" \
            "- GetMonitorWidth: (%d)\n" \
            "- GetMonitorHeight: (%d)\n" \
            "- global.current_screen (%d)\n" \
            "- global.frames_counter (%d)\n" \
            "- global.winner (%s)\n"
            , GetMonitorWidth(GetCurrentMonitor())
            , GetMonitorHeight(GetCurrentMonitor())
            , global.current_screen
            , global.frames_counter
            , global.winner
            );
        DrawRectangle(0, 0, MeasureText(buf, 10), GetScreenHeight()/2, Fade(SKYBLUE, 0.5f));        
        DrawRectangleLines(0, 0, MeasureText(buf, 10), GetScreenHeight()/2, BLUE);
        DrawText(TextFormat(buf), 0, 0, 10, WHITE);
        */
    EndDrawing();
}

void UnloadGame()
{
    // Unload textures
}