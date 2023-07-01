/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   Mainminijuego.cpp
 * Author: mario
 *
 * Created on 5 de junio de 2023, 13:04
 */

#include "raylib.h"
#include "Funciones.h"
#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Initialization
    //---------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    int util_asteroides = MAX_ASTEROIDES;
    Asteroide campoAsteroides[MAX_ASTEROIDES];
    IniciaCampo(campoAsteroides, util_asteroides);
    
    PoliReg triangulo(3, Punto2D(screenWidth/2, screenHeight), 10);
    Asteroide nave(triangulo, Punto2D(10,0), 180);
    nave.rotar();
    
    
    int util_disparos = 0;
    Asteroide disparos[MAX_DISPAROS];

    InitWindow(screenWidth, screenHeight, "Asteroid");
    int framesCounter = 0;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //----------------------------------------------------------
    

    // Main game loop
    bool fin = false;
    
    while (!WindowShouldClose() and !fin) // Detect window close button or ESC key
    {
        // Update
        //-----------------------------------------------------
        
        // Mover y rotar cada asteroide
        MoverAsteroides(campoAsteroides, util_asteroides);

        // Mover cada misil
        MoverMisiles(disparos, util_disparos);

        // Comprobar y gestionar colision misil-borde
        ColisionMB(disparos, util_disparos);

        // Comprobar colisiones asteroide-asteroide
        ColisionAA(campoAsteroides, util_asteroides);

        // Comprobar y gestionar colisiones asteroide-borde
        ColisionAB(campoAsteroides, util_asteroides);

        // Comprobar y gestionar colisiones misil-asteroide
        ColisionMA(disparos, util_disparos, campoAsteroides, util_asteroides);

        // Comprobar y gestionar colisiones nave-asteroide
        bool choque_nave = ChoqueNA(nave, campoAsteroides, util_asteroides);

        // Comprobar y gestionar pulsaciones de teclas
        if (IsKeyDown(KEY_A) or IsKeyPressed(KEY_A))
            moverNave(nave, false);

        if (IsKeyDown(KEY_D) or IsKeyPressed(KEY_D))
            moverNave(nave, true);

        if (IsKeyPressed(KEY_W))
            disparar(nave, disparos, util_disparos);

        // Comprobar y gestionar fin del juego
        if (choque_nave or util_asteroides == 0) fin = true;
                
        
        framesCounter++;
        //-----------------------------------------------------

        // Draw
        //-----------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        // Dibujar asteroides
        for (int i = 0; i < util_asteroides; i++){
            Vector2 centro = {campoAsteroides[i].getCentro().getX(),
                              campoAsteroides[i].getCentro().getY()};
            
            DrawPolyLines(centro, campoAsteroides[i].getRoca().getLados(),
                          campoAsteroides[i].getRoca().getRadio(),
                          campoAsteroides[i].getRotacion(), BROWN);
        }
        
        // Dibujar misiles
        for (int i = 0; i < util_disparos; i++){
            Vector2 centro = {disparos[i].getCentro().getX(),
                              disparos[i].getCentro().getY()};

            DrawPolyLines(centro, disparos[i].getRoca().getLados(),
                          disparos[i].getRoca().getRadio(),
                          disparos[i].getRotacion(), RED);
        }
        
        // Dibujar nave
        Vector2 centro = {nave.getCentro().getX(), nave.getCentro().getY()};

        DrawPolyLinesEx(centro, nave.getRoca().getLados(),
                      nave.getRoca().getRadio(), nave.getRotacion(), 20, BLUE);
        
        if (fin){ 
            cout << "GAME OVER!" << endl;
            DrawText("GAME OVER!", 350, 200, 30, GRAY);
        }
        
        
        DrawFPS(10, 10);
        EndDrawing();
        //-----------------------------------------------------
    }

    // De-Initialization
    //---------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //----------------------------------------------------------

    return 0;
}

/*
 
 int main(int argc, char** argv) {
    // Initialization
    //---------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - bouncing ball");

    Vector2 ballPosition = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    Vector2 ballSpeed = {5.0f, 4.0f};
    int ballRadius = 20;

    bool pause = 0;
    int framesCounter = 0;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //----------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //-----------------------------------------------------
        if (IsKeyPressed(KEY_SPACE))
            pause = !pause;

        if (!pause) {
            ballPosition.x += ballSpeed.x;
            ballPosition.y += ballSpeed.y;

            // Check walls collision for bouncing
            if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius))
                ballSpeed.x *= -1.0f;
            if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius))
                ballSpeed.y *= -1.0f;
        } else framesCounter++;
        //-----------------------------------------------------

        // Draw
        //-----------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircleV(ballPosition, ballRadius, MAROON);
        DrawText("PRESS SPACE to PAUSE BALL MOVEMENT", 10, GetScreenHeight() - 25, 20, LIGHTGRAY);

        // On pause, we draw a blinking message
        if (pause && ((framesCounter / 30) % 2)) DrawText("PAUSED", 350, 200, 30, GRAY);

        DrawFPS(10, 10);

        EndDrawing();
        //-----------------------------------------------------
    }

    // De-Initialization
    //---------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //----------------------------------------------------------

    return 0;
 
 */