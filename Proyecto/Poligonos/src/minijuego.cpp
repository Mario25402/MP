/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   minijuego.cpp
 * Author: mario
 *
 * Created on 24 de mayo de 2023, 13:04
 */

#include "raylib.h"
#include "Asteroide.h"
#include "Punto2D.h"
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

    InitWindow(screenWidth, screenHeight, "raylib [shapes] Asteroid");

    const int MAX_ASTEROIDES = 20;
    int util_asteroides = 0;
    Asteroide campoAsteroides[MAX_ASTEROIDES];
    
    Asteroide nave;
    
    PoliReg triangulo(3, Punto2D(0,0), 1);
    Asteroide misil(triangulo, Punto2D(0,-3));
    
    const int MAX_DISPAROS = 10;
    int util_disparos = 0;
    Asteroide disparos[MAX_DISPAROS];
    
    const int INICIO = 0;

    bool pause = 0;
    int framesCounter = 0;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //----------------------------------------------------------
    
    /*************************************/
    /*******INICIALIZAR LOS DATOS*********/
    /*************************************/

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //-----------------------------------------------------
        
        // Mover y rotar cada asteroide
        for (int i = 0; i < util_asteroides; ++i){
            campoAsteroides[i].mover();
            campoAsteroides[i].rotar();
        }
        
        // Mover cada misil
        for (int i = 0; i < util_disparos; ++i)
            disparos[i].mover();
        
        // Comprobar y gestionar colision misil-borde
        if (disparos[INICIO].getRoca().getCentro().getY() <
            disparos[INICIO].getRoca().getRadio()){
            
            for (int i = 1; i < util_disparos; i++)
                disparos[i-1] = disparos[i];
            
            util_disparos--;
        }
        
        // Comprobar colisiones asteroide-asteroide
        for (int i = 0; i < util_asteroides; i++){
            for (int j = i+1; j < util_asteroides; j++){
                if (campoAsteroides[i].colision(campoAsteroides[j])){
                    Punto2D tmp = campoAsteroides[i].getVelocidad();
                    campoAsteroides[i].setVelocidad(campoAsteroides[j].getVelocidad());
                    campoAsteroides[j].setVelocidad(tmp);
                }
            }
        }
        
        // Comprobar y gestionar colisiones asteroide-borde
        for (int i = 0; i < util_asteroides; ++i){
            if (campoAsteroides[i].getRoca().getCentro().getX() <
                campoAsteroides[i].getRoca().getRadio() or 
                campoAsteroides[i].getRoca().getCentro().getY() <
                campoAsteroides[i].getRoca().getRadio()){
                
                Punto2D actual = campoAsteroides[i].getVelocidad();
                Punto2D nueva = Punto2D(-actual.getX(), -actual.getY());
            }
                
        }
        
        // Comprobar y gestionar colisiones misil-asteroide
        for (int i = 0; i < util_disparos; i++){
            for (int j = util_asteroides - 1; j <= 0; j--){
                if (disparos[i].colision(campoAsteroides[j])){
                    
                    // Eliminar misil
                    for (int k = i+1; k < util_disparos; k++)
                        disparos[k-1] = disparos[k];
            
                    util_disparos--;
                    
                    // Modificar asteroide
                    if (campoAsteroides[j].getRoca().getLados() > 3){
                        int lados = campoAsteroides[j].getRoca().getLados() - 1;
                        Punto2D centro = campoAsteroides[j].getRoca().getCentro();
                        float radio = campoAsteroides[j].getRoca().getRadio();
                        
                        PoliReg nueva(lados, centro, radio);
                        campoAsteroides[j].setRoca(nueva);
                    }
                    
                    else{
                        if (j != util_asteroides)
                            campoAsteroides[j] = campoAsteroides[util_asteroides];
                        
                        util_asteroides--;
                    }
                }
            }
        }
        
        // Comprobar y gestionar colisiones nave-asteroide
        
        bool choque_nave = false;
        
        for (int i = 0; i < util_asteroides and !choque_nave; ++i){
            if (nave.colision(campoAsteroides[i]))
                choque_nave = true;
        }
        
        // Comprobar y gestionar pulsaciones de teclas
        if (IsKeyPressed(KEY_A))
            nave.moverNave(false);
            
        if (IsKeyPressed(KEY_D))
            nave.moverNave(true);
            
        if (IsKeyPressed(KEY_W)){
            if (util_disparos + 1 <= MAX_DISPAROS){
                util_disparos++;
                disparos[util_disparos] = misil;
            }
        }
        
        // Comprobar y gestionar fin del juego
        bool fin = false;
        
        if (choque_nave or util_asteroides = 0)
            fin = true; // Dibujar un mensaje, sleep y salir
        
        
        framesCounter++;
        
        /*if (IsKeyPressed(KEY_SPACE))
            pause = !pause;

        if (!pause) {
            ballPosition.x += ballSpeed.x;
            ballPosition.y += ballSpeed.y;

            // Check walls collision for bouncing
            if ((ballPosition.x >= (GetScreenWidth() - ballRadius)) || (ballPosition.x <= ballRadius))
                ballSpeed.x *= -1.0f;
            if ((ballPosition.y >= (GetScreenHeight() - ballRadius)) || (ballPosition.y <= ballRadius))
                ballSpeed.y *= -1.0f;
        }
        else framesCounter++;*/
        //-----------------------------------------------------

        // Draw
        //-----------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        //DrawCircleV(ballPosition, ballRadius, MAROON);
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