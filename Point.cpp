#include "Point.h"
#include "Tools.h"
#include <iostream>

void Point::Print()//输出方块
{
    SetColor(color);
    SetCursorPosition(x+bias, y+bias);
    std::cout << "■" ;
}

void Point::PrintCircular()//输出圆形
{
    SetColor(color);
    SetCursorPosition(x+bias, y+bias);
    std::cout << "●" ;
}
void Point::Print(int c)//输出方块
{
    SetColor(c);
    SetCursorPosition(x+bias, y+bias);
    std::cout << "■" ;
}

void Point::PrintCircular(int c)//输出圆形
{
    SetColor(c);
    SetCursorPosition(x+bias, y+bias);
    std::cout << "●" ;
}


void Point::Clear()//清除输出
{
    SetColor(0);
    SetCursorPosition(x+bias, y+bias);
    std::cout << "  " ;
}

void Point::ChangePosition(const int x, const int y,const int bias)//改变坐标
{
    this->x = x;
    this->y = y;
    this->bias=bias;
}
void Point::ChangeColor(const int c)
{
    this->color=c;
}
