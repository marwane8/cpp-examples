#ifndef INCLUDE_ANIMATOR
#define INCLUDE_ANIMATOR

#include "raylib-cpp.hpp"

struct Block
{
    int _x;
    int _y;
    int _width;
    int _height;
    raylib::Color _color;
    Block(int x,int y,int w,int h, raylib::Color _color): _x(x),_y(y),_width(w),_height(h){}
};


class Animator{

private:
    raylib::Window& m_window;
    std::vector<Block> m_blocks;
    int m_canvas_h;
    int m_canvas_w;
   
public:
    Animator(raylib::Window& window, int canvas_h, int canvas_w);
    void initBlocks(std::vector<int> numbers);
    void selectionSort();
    void drawFrame();
    const std::vector<Block>& getBlocks();
};

#endif