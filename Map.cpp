#include "map.h"
#include <windows.h>
#include "LinkGame.h"
void Map::PrintInitmap(int st)//绘制初始地图
{
    for (auto& point : initmap)
    {
        if(point.GetC()<40)
            SetColor(point.GetC());
        else
            SetColor(3);
        point.Print();
        Sleep(5);//调用Sleep函数可营造动画效果
    }
}
Map::Map(int wide,int bias)
{
    this->bias=bias;
        for(int i=1;i<=wide-1;i++)
        {
            initmap.emplace_back(Point(1,i+1,3,this->bias));
            initmap.emplace_back(Point(i,1,3,this->bias));
            initmap.emplace_back(Point(wide,wide-i,3,this->bias));
            initmap.emplace_back(Point(wide-i+1,wide,3,this->bias));
        }
}
Map::Map(LinkGame* lin,int b)
{
    EleType ele;
    bias=b;
    for(int i=0;i<lin->GetMaxR();i++)
    {
        for(int j=0;j<lin->GetMaxC();j++)
        {
            if(!lin->GetEle(i+1, j+1, &ele))//这个位置得点在1起点坐标系下是否有值
                AddPoint(Point(i+2,j+2,ele,bias));//若有值 存入其2起点真实坐标系的值
        }
    }
}
Map::Map()
{
    int i=-18;
    initmap.emplace_back(Point(      9     ,   4      +i,2));
    initmap.emplace_back(Point(       10 ,      4   +i,2));
    initmap.emplace_back(Point(       11   ,   4      +i,2));
    initmap.emplace_back(Point(       12   ,   4     +i,2));
    initmap.emplace_back(Point(       13   ,    4     +i,2));
    initmap.emplace_back(Point(       14   ,    4     +i,2));
    initmap.emplace_back(Point(        15  ,    4     +i,2));
    initmap.emplace_back(Point(       16   ,    4     +i,2));
    initmap.emplace_back(Point(        17  ,     4    +i,2));
    initmap.emplace_back(Point(       18   ,     4    +i,2));
    initmap.emplace_back(Point(        19  ,    4    +i,2));
    initmap.emplace_back(Point(        20  ,    4     +i,2));
    initmap.emplace_back(Point(        21 ,     4    +i,2));
    initmap.emplace_back(Point(        22  ,    4     +i,2));
    initmap.emplace_back(Point(         22 ,   5      +i,2));
    initmap.emplace_back(Point(        22 ,     6    +i,2));
    initmap.emplace_back(Point(        22  ,     7    +i,2));
    initmap.emplace_back(Point(      22    ,     8   +i,2));
    initmap.emplace_back(Point(         12 ,  11    +i,2));
    initmap.emplace_back(Point(        13  ,     11   +i,2));
    initmap.emplace_back(Point(         15,      11  +i,2));
    initmap.emplace_back(Point(       16   ,     11   +i,2));
    initmap.emplace_back(Point(         17 ,      11  +i,2));
    initmap.emplace_back(Point(        18  ,      11  +i,2));
    initmap.emplace_back(Point(        19  ,    11    +i,2));
    initmap.emplace_back(Point(         20 ,     11   +i,2));
    initmap.emplace_back(Point(         21,      11  +i,2));
    initmap.emplace_back(Point(       22   ,    11    +i,2));
    initmap.emplace_back(Point(      15    ,    15  +i,2));
    initmap.emplace_back(Point(      16    ,   15     +i,2));
    initmap.emplace_back(Point(       17   ,     15   +i,2));
    initmap.emplace_back(Point(        18  ,       15 +i,2));
    initmap.emplace_back(Point(       19   ,       15 +i,2));
    initmap.emplace_back(Point(        20  ,      15  +i,2));
    initmap.emplace_back(Point(        21  ,      15  +i,2));
    initmap.emplace_back(Point(        22  ,      15  +i,2));
    initmap.emplace_back(Point(     15     ,    16    +i,2));
    initmap.emplace_back(Point(        15  ,    17   +i,2));
    initmap.emplace_back(Point(      15    ,    18  +i,2));
    initmap.emplace_back(Point(      16    ,      18  +i,2));
    initmap.emplace_back(Point(       17   ,      18  +i,2));
    initmap.emplace_back(Point(        18  ,     18   +i,2));
    initmap.emplace_back(Point(       19   ,     18   +i,2));
    initmap.emplace_back(Point(        20  ,      18  +i,2));
    initmap.emplace_back(Point(        21  ,      18  +i,2));
    initmap.emplace_back(Point(        22  ,      18  +i,2));
    initmap.emplace_back(Point(       9    ,     22   +i,2));
    initmap.emplace_back(Point(        10 ,       22 +i,2));
    initmap.emplace_back(Point(        11,     22   +i,2));
    initmap.emplace_back(Point(       12   ,      22  +i,2));
    initmap.emplace_back(Point(        13  ,       22 +i,2));
    initmap.emplace_back(Point(        14  ,        22+i,2));
    initmap.emplace_back(Point(         15 ,    22    +i,2));
    initmap.emplace_back(Point(        16  ,     22   +i,2));
    initmap.emplace_back(Point(         17 ,      22  +i,2));
    initmap.emplace_back(Point(       18   ,     22   +i,2));
    initmap.emplace_back(Point(        19  ,       22 +i,2));
    initmap.emplace_back(Point(         20,      22  +i,2));
    initmap.emplace_back(Point(       21   ,      22  +i,2));
    initmap.emplace_back(Point(        22  ,     22   +i,2));
    initmap.emplace_back(Point(       15   ,    23    +i,2));
    initmap.emplace_back(Point(        16  ,     23   +i,2));
    initmap.emplace_back(Point(         17 ,      23  +i,2));
    initmap.emplace_back(Point(       13   ,     24   +i,2));
    initmap.emplace_back(Point(        14,       24 +i,2));
    initmap.emplace_back(Point(         17 ,       24 +i,2));
    initmap.emplace_back(Point(         12 ,       25 +i,2));
    initmap.emplace_back(Point(        18  ,     25   +i,2));
    initmap.emplace_back(Point(         19 ,      25  +i,2));
    initmap.emplace_back(Point(          11,      26 +i,2));
    initmap.emplace_back(Point(          20,      26  +i,2));
    initmap.emplace_back(Point(          9 ,    27    +i,2));
    initmap.emplace_back(Point(           10  ,  27   +i,2));
    initmap.emplace_back(Point(         21 ,     27   +i,2));
    initmap.emplace_back(Point(         22 ,      27  +i,2));
    initmap.emplace_back(Point(          22,     28+i,2));
}
void Map::PrintText()
{
    for(auto& p :initmap)
    {
        if(p.GetY()>=0)
        {
            p.Print();
        }
    }
}
void Map::ClearText()
{
    for(auto&p:initmap)
    {
        if(p.GetY()>=0)
            p.Clear();
        p.ChangePosition(p.GetX(),p.GetY()+1);
    }
}
void Map::Surface()
{
    while(initmap.back().GetY()<35)
    {
        ClearText();
        PrintText();
        Sleep(70);
    }
}
