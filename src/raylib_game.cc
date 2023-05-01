/*******************************************************************************************
*
*   raylib 9years gamejam template
*
*   Template originally created with raylib 4.5-dev, last time updated with raylib 4.5-dev
*
*   Template licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#if defined(PLATFORM_WEB)
  #define CUSTOM_MODAL_DIALOGS            // Force custom modal dialogs usage
  #include <emscripten/emscripten.h>      // Emscripten library - LLVM to JavaScript compiler
#endif

static const int screenWidth = 256;
static const int screenHeight = 256;

static void UpdateDrawFrame(void);    

int main(void)
{
#if !defined(_DEBUG)
  SetTraceLogLevel(LOG_NONE);         
#endif
  InitWindow(screenWidth, screenHeight, "raylib 9yr gamejam");
    
#if defined(PLATFORM_WEB)
  emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
  SetTargetFPS(60);     

  while (!WindowShouldClose())   
  {
    UpdateDrawFrame();
  }
#endif   

  CloseWindow();   

  return 0;
}

void UpdateDrawFrame(void)
{   
  BeginDrawing();
    ClearBackground(RAYWHITE);
  EndDrawing();
}