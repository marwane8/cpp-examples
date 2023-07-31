#include "animator.h"
#include "raylib-cpp.hpp"


void drawFrame(raylib::Window& window, std::vector<Block>& blocks);

int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "Sort C++");

    raylib::Color foreground = RED;
    raylib::Color secondary(0,68,130);
    raylib::Color background = RAYWHITE;

    Animator animator(window,screenWidth,screenHeight);
    std::vector<int> test{23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    animator.initBlocks(test);

    SetTargetFPS(15);

    // Main game loop
    while (!window.ShouldClose()) {    // Detect window close button or ESC key

        animator.selectionSort();
        
    }

    return 0;
}

