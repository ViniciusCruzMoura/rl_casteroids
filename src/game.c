#include <string.h>
#include <stdio.h>
#include "game.h"

void InitGame() 
{
    game.current_screen = LOGO;
    game.screen_scale = 3.0;
    game.screen_width = WIN_RES_W*game.screen_scale;
    game.screen_height = WIN_RES_H*game.screen_scale;
    
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(game.screen_width, game.screen_height, "raylib - CPong");
    if (!IsWindowFullscreen()) {
        // game.screen_width = GetMonitorWidth(GetCurrentMonitor());
        // game.screen_height = GetMonitorHeight(GetCurrentMonitor());
        // game.screen_scale = game.screen_height/WIN_RES_H;
        game.screen_scale = game.screen_width/WIN_RES_W;
        SetWindowSize(game.screen_width, game.screen_height);
        // ToggleFullscreen();
    }

    game.game_paused = false;  // Game paused state toggle
    game.frames_counter = 0;  // General pourpose frames counter
    
    SetTargetFPS(60);
}

void UpdateGame()
{
    switch(game.current_screen)
    {
        case LOGO: 
        {
            // Update LOGO screen data here!
            
            game.frames_counter++;
            
            if (game.frames_counter > 180) 
            {
                game.current_screen = TITLE;    // Change to TITLE screen after 3 seconds
                game.frames_counter = 0;
            }
            
        } break;
        case TITLE: 
        {
            // Update TITLE screen data here!
            
            game.frames_counter++;
            
            if (IsKeyPressed(KEY_ENTER)) game.current_screen = GAMEPLAY;

        } break;
        case GAMEPLAY:
        { 
            // Update GAMEPLAY screen data here!

            if (IsKeyPressed(KEY_SPACE)) game.game_paused = !game.game_paused;

            if (!game.game_paused)
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
            
            game.frames_counter++;
            
            if (IsKeyPressed(KEY_ENTER))
            {
                // Replay / Exit game logic
                game.current_screen = TITLE;
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
        
        switch(game.current_screen) 
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
                
                if ((game.frames_counter/30)%2 == 0) DrawText("PRESS [ENTER] to START", GetScreenWidth()/2 - MeasureText("PRESS [ENTER] to START", 20)/2, GetScreenHeight()/2 + 60, 20, DARKGRAY);

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
                
                if ((game.frames_counter/30)%2 == 0) DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth()/2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20)/2, GetScreenHeight()/2 + 80, 20, GRAY);
                
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
            "- game.current_screen (%d)\n" \
            "- game.frames_counter (%d)\n" \
            "- game.winner (%s)\n"
            , GetMonitorWidth(GetCurrentMonitor())
            , GetMonitorHeight(GetCurrentMonitor())
            , game.current_screen
            , game.frames_counter
            , game.winner
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