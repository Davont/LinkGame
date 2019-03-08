#ifndef Point_H
#define Point_H

class Point
{
public:
    Point(){}
    Point(const int x, const int y,const int c=40,int b=0) : x(x), y(y) ,color(c),bias(b) {}//Ĭ�����ֵΪ40 ��ֵΪ40�򲻸ı���ɫ��ӡ
    void Print();
    void Print(int c);
    void PrintCircular();
    void PrintCircular(int c);
    void Clear();
    void ChangePosition(const int x, const int y,const int bias=0);
    void ChangeColor(const int c);
    void ChangeBias(const int s){bias=s;};
    bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }
    int GetX(){ return this->x; }
    int GetY(){ return this->y; }
    int GetC(){ return this->color;}
private:
    int x, y;
    int color;
    int bias;
};
#endif // Point_H
