#ifndef K
#define K
#include<time.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include"Point.h"
using namespace std;
typedef int Status;
typedef int EleType;
typedef int Pos;
class LinkGame {
protected: //private �е�Ԫ�����ⶨ�� ��ֻ�Ǿ�����
	int Score;	//���� �ɹ�ɾ��һ�� ���ɹ�����һ��ɾ������ �ͼ�һ�� ������ʼΪ0��
	int	**arr;//��ά����һά������  ����ÿɴ�����ֵ����ʹ洢 ��������Ԫ�ظ������ܽ϶� Ӣ����ĸ���ܲ�����
			//�������Ŵ�arr[0][0]��ʼ ��  arr[MaxR-1][MaxC-1] Ϊ���һ��Ԫ��
			//�洢��ʽ���� ֻҪ�ҵ���GetEle����  ������ 0 0  ���ص��ǵ�һ�е�һ��Ԫ�ؼ��ɣ�
	int MaxR;//(�����)
	int MaxC;//������У�
public://�����������������ǰһ��Ҫ�������� ���ÿ�����ִ���һ�����
	   //
	   //Ҫ��EleTypeͳһ��һ������ int double ʲô�Ķ�����
	   //Status ͳһ��һ������
	LinkGame(EleType maxR, EleType maxC, int elenum, int numrange);//ֱ���ڹ��캯���а��յ���������maxR �����maxC  ��ʼ��LinkGame
	Status GetEle(Pos x, Pos y, EleType *ele);// ��������Ԫ�� ��Status���� 1�������ڴ�Ԫ�أ���ͨ������ele ����Ԫ�ص�ֵ ��Status ����0
	Status Get_CRNum(Pos x1, Pos y1, Pos x2, Pos y2,Pos q);//�����������꣬��һ��ֵq��ʹ֮������q���Ӧ����һ������
	Status Judge(Pos x1, Pos y1, Pos x2, Pos y2);//�ж����������Ԫ���Ƿ����ɾ�� ������ɾ�� �򷵻�0����������ɾ�� �򷵻�1 ������������ �ɸ��ݲ�ͬ�����岻ͬ��ֵ
	Status Delete(Pos x1, Pos y1, Pos x2, Pos y2);//ɾ���˵�ַ������Ԫ�� ���ɹ� �򷵻�0 �������� �ɸ��ݲ�ͬ�����岻ͬ��ֵ
	Status Judge_If_Restar();//�ж��������Ƿ���������������������Ԫ�أ���������ڣ��򷵻�0����������1
	void ReStar();//���ú�Ԫ�� ֮��������� ת������Ԫ�ؿ���ɾ�� ���������Ԫ�ؿ���ɾ�� �򲻲�����������������Ԫ�ؿ���ɾ���ˣ��򷵻�0  ���д��� �ɸ��ݲ�ͬ�����岻ͬ��ֵ
	Status GetScore(EleType *s);//���ط�����ֵ �ҷ���0 ���������� �ɸ��ݲ�ͬ�����岻ͬ��ֵ
	Status Print();
    EleType GetMaxR(){return MaxR;}//�����Ҽӵ�������ȡMaxR�� ��Ӱ������ ��Ҫɾ
    EleType GetMaxC(){return MaxC;}
    Status Supporter(Point &p1,Point &p2);//��ʾ���� ����Ϊ�û����ؿ���ʾ�ĵ㣻
};
#endif // LinkGame_H
