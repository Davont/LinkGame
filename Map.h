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
    //�����ʼ��ͼ
    /*Map����Զ�����ֵ�ͼ��ֻ�轫��ʾ��ͼ�ĸ����㱣������Ӧ��map�У�����Snake����������Ӧ�ж�ײǽ��������
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
    void PrintInitmap(int st=10);//���Ƴ�ʼ��ͼ
};
#endif // Map_H
