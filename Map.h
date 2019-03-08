#ifndef Map_H
#define Map_H

#include <vector>
#include "Point.h"
#include "Tools.h"
#include "LinkGame.h"
class Map
{

private:
    std::vector<Point> initmap;
    int bias;
    //保存初始地图
    /*Map类可自定义多种地图，只需将表示地图的各个点保存在相应的map中，并在Snake类中增加相应判断撞墙函数即可
    std::vector<Point> map1;
    std::vector<Point> map2;
    */
public:
    Map();
    void ClearText();
    void PrintText();
    void Surface();
    Map(int wide,int bias);
    Map(LinkGame* link,int b);
    void AddPoint(Point p)
    {
        initmap.emplace_back(p);
    }
    void PrintInitmap(int st=10);//绘制初始地图
};
#endif // Map_H
