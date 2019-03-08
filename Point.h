#ifndef Point_H
#define Point_H

class Point
{
public:
    Point(){}
    Point(const int x, const int y,const int c=40,int b=0) : x(x), y(y) ,color(c),bias(b) {}//默认最大值为40 若值为40则不改变颜色打印
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
