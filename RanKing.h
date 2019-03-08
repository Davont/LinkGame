#ifndef RanKing_H
#define RanKing_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class Player
{
   public:
        int number;//排名
        string name;//姓名
        double time;//时间
        int score;//分数
    Player(){;}
    Player(int num,string n,double t,int s);//构造函数玩家带参赋值
};
/*Player::Player(int num,string n,double t,int s)
{
    number=num;
    name=n;
    time=t;
    score=s;
}*/
class Ranking
{
    int addtype;//排行榜类型
    int num;//排行榜中的人数
    Player arr[5];
    string add[6];
public:
    Ranking(int t);
    ~Ranking();
    int Judge(const Player &pla);//判断引入的玩家是否能加入排行榜 若可以 则返回其数组位置 若不可以则返回其他值
    void Add(const Player &pla,const int pos);//添加 根据输入的数组位置 添加 并提前将其他成员后移
    Player * GetAll(int& total);
} ;
#endif
