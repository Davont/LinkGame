#ifndef RanKing_H
#define RanKing_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class Player
{
   public:
        int number;//����
        string name;//����
        double time;//ʱ��
        int score;//����
    Player(){;}
    Player(int num,string n,double t,int s);//���캯����Ҵ��θ�ֵ
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
    int addtype;//���а�����
    int num;//���а��е�����
    Player arr[5];
    string add[6];
public:
    Ranking(int t);
    ~Ranking();
    int Judge(const Player &pla);//�ж����������Ƿ��ܼ������а� ������ �򷵻�������λ�� ���������򷵻�����ֵ
    void Add(const Player &pla,const int pos);//��� �������������λ�� ��� ����ǰ��������Ա����
    Player * GetAll(int& total);
} ;
#endif
