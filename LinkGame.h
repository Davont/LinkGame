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
protected: //private 中的元素随意定义 我只是举例子
	int Score;	//分数 成功删除一次 即成功调用一次删除函数 就加一分 分数初始为0分
	int	**arr;//二维或者一维都随意  最好用可存放数字的类型存储 因连连看元素个数可能较多 英文字母可能不够用
			//且数组存放从arr[0][0]开始 到  arr[MaxR-1][MaxC-1] 为最后一个元素
			//存储方式任意 只要我调用GetEle函数  坐标如 0 0  返回的是第一行第一个元素即可；
	int MaxR;//(最大行)
	int MaxC;//（最大列）
public://所有其他错误在添加前一定要与我商量 最好每个数字代表一类错误
	   //
	   //要求EleType统一用一个类型 int double 什么的都可以
	   //Status 统一用一个类型
	LinkGame(EleType maxR, EleType maxC, int elenum, int numrange);//直接在构造函数中按照导入的最大行maxR 最大列maxC  初始化LinkGame
	Status GetEle(Pos x, Pos y, EleType *ele);// 若不存在元素 则Status返回 1；若存在此元素，则通过引用ele 返回元素的值 且Status 返回0
	Status Get_CRNum(Pos x1, Pos y1, Pos x2, Pos y2,Pos q);//输入两个坐标，和一个值q，使之返回与q相对应的另一个坐标
	Status Judge(Pos x1, Pos y1, Pos x2, Pos y2);//判断引入的两个元素是否可以删除 若可以删除 则返回0；若不可以删除 则返回1 ；若其他错误 可根据不同错误定义不同的值
	Status Delete(Pos x1, Pos y1, Pos x2, Pos y2);//删除此地址的两个元素 若成功 则返回0 其他错误 可根据不同错误定义不同的值
	Status Judge_If_Restar();//判断数组里是否存在两个符合清除条件的元素，如果不存在，则返回0，其他返回1
	void ReStar();//调用后将元素 之间随机互换 转换成有元素可以删除 若本身就有元素可以删除 则不操作；若矩阵现在有元素可以删除了，则返回0  若有错误 可根据不同错误定义不同的值
	Status GetScore(EleType *s);//返回分数的值 且返回0 若其他错误 可根据不同错误定义不同的值
	Status Print();
    EleType GetMaxR(){return MaxR;}//这是我加的用来获取MaxR的 不影响你用 不要删
    EleType GetMaxC(){return MaxC;}
    Status Supporter(Point &p1,Point &p2);//提示函数 用于为用户返回可提示的点；
};
#endif // LinkGame_H
