#include "Point.h"
#include "Tools.h"
#include <iostream>

void Point::Print()//�������
{
    SetColor(color);
    SetCursorPosition(x+bias, y+bias);
    std::cout << "��" ;
}

void Point::PrintCircular()//���Բ��
{
    SetColor(color);
    SetCursorPosition(x+bias, y+bias);
    std::cout << "��" ;
}
void Point::Print(int c)//�������
{
    SetColor(c);
    SetCursorPosition(x+bias, y+bias);
    std::cout << "��" ;
}

void Point::PrintCircular(int c)//���Բ��
{
    SetColor(c);
    SetCursorPosition(x+bias, y+bias);
    std::cout << "��" ;
}


void Point::Clear()//������
{
    SetColor(0);
    SetCursorPosition(x+bias, y+bias);
    std::cout << "  " ;
}

void Point::ChangePosition(const int x, const int y,const int bias)//�ı�����
{
    this->x = x;
    this->y = y;
    this->bias=bias;
}
void Point::ChangeColor(const int c)
{
    this->color=c;
}
