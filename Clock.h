#ifndef Clcok_H
#define Clcok_H
#include<time.h>
class Clocker
{
    public:
    Clocker(){};
    virtual double Getnow()=0;

};
class Counter:public Clocker
{
    double start;//��ʼ��ʱ��
public:
    Counter():start((double)clock()/CLOCKS_PER_SEC){;}
    double Getnow(){return (double)clock()/CLOCKS_PER_SEC-start;}
};
class CounterDown:public Clocker
{
    double start;
    double down;//��ʼ����ʱ�ĵ�
    public:
    CounterDown(double k):start((double)clock()/CLOCKS_PER_SEC),down(k){}
    double Getnow(){return down+start-(double)clock()/CLOCKS_PER_SEC;}
};
#endif
