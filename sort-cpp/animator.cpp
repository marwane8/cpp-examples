#include "animator.h"
#include "raylib-cpp.hpp"


Animator::Animator(raylib::Window& window, int canvasW, int canvasH)
:m_window(window), m_canvas_w(canvasW),m_canvas_h(canvasH)
{
}


void Animator::initBlocks(std::vector<int> numbers) {
    int max = *std::max_element(numbers.begin(),numbers.end());
    int blockW = 15;
    int step= (m_canvas_h - 30)/max;

    int x = 30;
    for ( int num : numbers) {
        int blockH = 10 + (num * step);
        int y = m_canvas_h - blockH;
        m_blocks.push_back(Block(x,y,blockH,blockW,BLACK));
        x = x + blockW;
    }
}

bool start = true;
void Animator::selectionSort(){
    if (start) {
        for (auto i=0; i<m_blocks.size(); i++){
            Block& currBlk = m_blocks[i];
            currBlk._color = raylib::RED;
            int minIdx = i;

            for (auto j=i+1; j<m_blocks.size(); j++){
                Block& nextBlk = m_blocks[j];
                nextBlk._color = raylib::SKYBLUE;
                drawFrame();
                if (nextBlk._width < m_blocks[minIdx]._width) {
                    if (minIdx != i) m_blocks[minIdx]._color = raylib::BLACK;
                    minIdx = j;
                    m_blocks[minIdx]._color = raylib::PURPLE;
                } else {
                    nextBlk._color = raylib::BLACK;
                }
            }

            if (minIdx != i) {
                auto tmpBlk = currBlk;
                currBlk._width = m_blocks[minIdx]._width;
                currBlk._y = m_blocks[minIdx]._y;

                m_blocks[minIdx]._width = tmpBlk._width;
                m_blocks[minIdx]._y = tmpBlk._y;
                m_blocks[minIdx]._color = raylib::BLACK;
            }

            drawFrame();
        }
        start = false;

    }
    drawFrame();
}

void Animator::drawFrame(){
        BeginDrawing();
        {
            m_window.ClearBackground(RAYWHITE);
             for (Block& b : m_blocks){
                 b._color.DrawRectangle(b._x,b._y,b._height,b._width);
             }
        }
        EndDrawing();

}