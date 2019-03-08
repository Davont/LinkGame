#include"RanKing.h"
#include<fstream>
#include<istream>
using namespace std;
istream &operator >>(istream & in,Player & pla)
{
    in>>pla.number;
    in>>pla.name;
    in>>pla.score;
    in>>pla.time;
    return in;
}
ostream &operator <<(ostream &out, const Player & pla)
{
    out<<pla.number<<'\t';
    out<<pla.name<<'\t';
    out<<pla.score<<'\t';
    out<<pla.time<<'\n';
    return out;
}
    Ranking::Ranking(int t)
    {
        addtype=t;
        num=0;
        ifstream inf;
        for(int i=0;i<5;i++)
        {
        	arr[i].number=0;
            arr[i].time=0;
            arr[i].name="";
            arr[i].score=0;
		}
        switch(addtype)
        {
        case 0:
            inf.open("unlimited_hard.txt");//0无难
            break;
        case 1:
            inf.open("unlimited_normal.txt");//1无普通
            break;
        case 2:
            inf.open("unlimited_easy.txt");//
            break;
        case 3:
            inf.open("limited_hard.txt");//
            break;
        case 4:
            inf.open("limited_normal.txt");//
            break;
        case 5:
            inf.open("limited_easy.txt");//
            break;
        };
			while(inf>>arr[num])
			{
				num++;
			}
        inf.close();
    }
    int Ranking::Judge(const Player &pla)
    {
        int i;
        for(i=num-1;i>=0;i--)
        {
                if(pla.score<arr[i].score)
                {
                    break;
                }
                else if(pla.score==arr[i].score)
                {
                    if(pla.time>arr[i].time)
                    {
                        break;
                    }
                }
        }
        if(i+1>=5)
        {
            return i+1;
        }
        else
        {
            return i+1;
        }
        return 0;
    }
    void Ranking::Add(const Player &pla,const int pos)
    {
    	if(pos>=5)
            return;
        else
        {
            for(int i=3;i>=pos;i--)
            {
                arr[i+1].number=arr[i].number+1;
                arr[i+1].time=arr[i].time;
                arr[i+1].name=arr[i].name;
                arr[i+1].score=arr[i].score;
            }
            arr[pos].number=pla.number;
            arr[pos].time=pla.time;
            arr[pos].name=pla.name;
            arr[pos].score=pla.score;
            if(num<=4)
                num++;
        }
    }
    Ranking::~Ranking()
    {
        ofstream out;
        switch(addtype)
        {
        case 0:
            out.open("unlimited_hard.txt");
            break;
        case 1:
            out.open("unlimited_normal.txt");
            break;
        case 2:
            out.open("unlimited_easy.txt");
            break;
        case 3:
            out.open("limited_hard.txt");
            break;
        case 4:
            out.open("limited_normal.txt");
            break;
        case 5:
            out.open("limited_easy.txt");
            break;
        };
        for(int i=0;i<num;i++)
        {
            out<<arr[i];
        }
        out.close();
    }
    Player* Ranking::GetAll(int &total)
    {
        total=num;
        Player *all=new Player[num];
        for(int i=0;i<num;i++)
        {
            all[i].score=arr[i].score;
            all[i].time=arr[i].time;
            all[i].name=arr[i].name;
            all[i].number=arr[i].number;
        }
        return all;
    }
/*int main()
{
	Player pla;
	pla.name="sml";
	pla.number=1;
	pla.score=1101;
	pla.time=102;
	Ranking ran(0);
	int num;
	num=ran.Judge(pla);
	ran.Add(pla,num);
	Player* p=NULL;
	int num2;
	p=ran.GetAll(num2);
	for(int i=0;i<num2;i++)
   {
       cout<<p[0]<<endl;
       cout<<num2;
    }*/
/*
    Ranking ran(0);
    Player* p=NULL;
	int num2;
	p=ran.GetAll(num2);
	for(int i=0;i<num2;i++)
   {
       cout<<p[i];
    }
 }*/
