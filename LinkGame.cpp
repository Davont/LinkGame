#include"LinkGame.h"
LinkGame::LinkGame(EleType maxR, EleType maxC, int elenum, int numrange)
{
	int *temp, row1 = 0, col1 = 0, *list, row2 = 0, col2 = 0;
	srand((unsigned)time(NULL));//初始化随机数发生器
	int i, j;
	Score = 0;
	arr = new int*[maxR];//实现动态分配二维数组
	for (int i = 0; i < maxC; i++)
	{
		arr[i] = new int[maxC];
	}
	MaxR = maxR;//赋值最大行
	MaxC = maxC;//赋值最大列
	temp = new int[maxR*maxC];
	list = new int[elenum];
	for (i = 0; i < maxR*maxC / 2; i++)
	{
		*(temp + i) = 1 + (int)numrange * rand() / (RAND_MAX + 1);//前一半个产生1-numrange的随机数
		*(temp + i + maxR*maxC / 2) = *(temp + i);//使得后一半依次等于前前一半
	}
	for (i = 0; i<elenum; i++)                    //产生并显示elenum个随机数
	{
		list[i] = temp[0 + rand() % (maxR*maxC / 2)];                //得到随机数
	}
	for (i = 0; i < MaxR; i++)
	{
		for (j = 0; j < MaxC; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (i = 0; i < elenum; i++)
	{
		do {
			row1 = (0 + rand() % maxR);
			col1 = (0 + rand() % maxC);
		} while (arr[row1][col1]);
		arr[row1][col1] = list[i];
		do{
			row2 = 0 + rand() % maxR;
			col2 = 0 + rand() % maxC;
		} while ((row2 == row1&&col2 == col1) || (arr[row2][col2]));
		arr[row2][col2] = list[i];


	}
}
Status LinkGame::GetEle(Pos x, Pos y, EleType *ele)
{
	if (x > MaxR || y > MaxC )//判断超出最大行或最大裂痕或为空的情况
		return 1;
	else//否则赋值给ele
	{
		*ele = arr[x-1][y-1];
		return 0;
	}
}
Status LinkGame::Get_CRNum(Pos x1, Pos y1, Pos x2, Pos y2, Pos q)
{
	if (q == x1) return y1;
	else if (q == y1) return x1;
	else if (q == x2) return y2;
	else if (q == y2) return x2;
	else cout << "Get_CRNum is wrong!" << endl;
	return 99;
}
Status LinkGame::Judge(Pos x1, Pos y1, Pos x2, Pos y2)
{
	int **list, i, j, *fir, *sec, *thir, *fort, num1 = 0, num2 = 0;
	list = new int*[MaxR + 2];//实现动态分配二维数组
	fir = new int[MaxR + 2];
	sec = new int[MaxR + 2];
	thir = new int[MaxR + 2];
	fort = new int[MaxR + 2];
	for (i = 0; i < MaxC + 2; i++)
	{
		fir[i] = -1;
		sec[i] = -1;
		thir[i] = -1;
		fort[i] = -1;
	}
	for (i = 0; i < MaxC + 2; i++)
	{
		list[i] = new int[MaxC + 2];
	}
	for (i = 0; i < MaxR + 2; i++)
	{
		for (j = 0; j < MaxC + 2; j++)
		{
			list[i][j] = 0;
		}
	}
	for (i = 1; i < MaxR + 1; i++)
	{
		for (j = 1; j < MaxC + 1; j++)
		{
			list[i][j] = arr[i - 1][j - 1];
		}
	}
	if ((arr[x1 - 1][y1 - 1] == arr[x2 - 1][y2 - 1]))//若两个值相等，则返回0
	{
		if (x1 == x2 || y1 == y2)
		{
			if (abs(y1 - y2) == 0 && abs(x1 - x2) == 0)
			{
				//cout << "your input is wrong!" << endl;
				return 1;
			}
			else if (abs(y1 - y2) == 1 || abs(x1 - x2) == 1)
				return 0;
			else if (abs(y1 - y2) > 1)
			{
				int f = 0;
				for (i = 0; i < abs(y1 - y2) - 1; i++)
				{

					if (arr[x1 - 1][min(y1, y2) + i] == NULL)
					{
						f++;
						continue;
					}
					else break;
				}
				if (f == (abs(y1 - y2) - 1))
					return 0;
			}
			else if (abs(x1 - x2) > 1)
			{
				int f = 0;
				for (i = 0; i < abs(x1 - x2) - 1; i++)
				{

					if (arr[min(x1, x2) + i][y1 - 1] == NULL)
					{
						f++;
						continue;
					}
					else break;
				}
				if (f == (abs(x1 - x2) - 1))
					return 0;
			}
		}
	}
	if (list[x1][y1] == list[x2][y2])
	{
		//横向扫描
		for (i = y1-1; i >= 0; i--)
		{
			if (list[x1][i] == NULL)
				list[x1][i] = -1;
			else break;
		}
		for (i = y1; i <= MaxC; i++)
		{
			if (list[x1][i + 1] == NULL)
				list[x1][i + 1] = -1;
			else break;
		}
		for (i = y2 - 1; i >= 0; i--)
		{
			if (list[x2][i] == NULL)
				list[x2][i] = -1;
			else break;
		}
		for (i = y2; i <= MaxC; i++)
		{
			if (list[x2][i + 1] == NULL)
				list[x2][i + 1] = -1;
			else break;
		}
		for (i = 0; i < MaxR + 2; i++)
		{
			if ((list[x1][i] == -1) || (i == y1))
			{
				fir[i] = i;
			}
			else fir[i] = -1;
		}
		for (i = 0; i < MaxR + 2; i++)
		{
			if ((list[x2][i] == -1) || (i == y2))
			{
				sec[i] = i;
			}
			else sec[i] = -1;
		}
		for (i = 0; i < MaxR + 2; i++)
		{
			if (fir[i] == sec[i] && (fir[i] != -1) && (sec[i] != -1))
			{
				int k = 0;
				for (j = 0; j < (max(x1, x2) - min(x1, x2) - 1); j++)
				{
					if (list[min(x1, x2) + j + 1][i] == NULL)
					{
						k++;
						continue;
					}
					else break;
				}
				if (k == (max(x1, x2) - min(x1, x2) - 1))
					return 0;
			}
			else continue;
		}
		//纵向扫描
		for (i = x1 - 1; i >= 0; i--)
		{
			if (list[i][y1] == NULL)
				list[i][y1] = -1;
			else break;
		}
		for (i = x1; i <= MaxC; i++)
		{
			if (list[i + 1][y1] == NULL)
				list[i + 1][y1] = -1;
			else break;
		}
		for (i = x2 - 1; i >= 0; i--)
		{
			if (list[i][y2] == NULL)
				list[i][y2] = -1;
			else break;
		}
		for (i = x2; i <= MaxC; i++)
		{
			if (list[i + 1][y2] == NULL)
				list[i + 1][y2] = -1;
			else break;
		}
		for (i = 0; i < MaxR + 2; i++)
		{
			if ((list[i][y1] == -1) || (i == x1))
			{
				thir[i] = i;
			}
			else thir[i] = -1;
		}
		for (i = 0; i < MaxR + 2; i++)
		{
			if ((list[i][y2] == -1) || (i == x2))
			{
				fort[i] = i;
			}
			else fort[i] = -1;
		}
		for (i = 0; i < MaxR + 2; i++)
		{
			if (thir[i] == fort[i] && (thir[i] != -1) && (fort[i] != -1))
			{
				int k = 0;
				for (j = 0; j < (max(y1, y2) - min(y1, y2) - 1); j++)
				{
					if (list[i][min(y1, y2) + j + 1] == NULL)
					{
						k++;
						continue;
					}
					else break;
				}
				if (k == (max(y1, y2) - min(y1, y2) - 1))
					return 0;
				else
				{
					//cout << "error2" << endl;
					continue;
				}
			}
			else continue;
		}
	}
	return 1;
	/*for (i = 0; i <MaxR+2; i++)
	{
	for (j = 0; j < MaxC+2; j++)
	{
	cout << list[i][j] << "\t";
	}
	cout << endl;
	}
	for (i = 0; i < MaxC+2; i++)
	{
	cout << fir[i] << " ";
	}
	cout << endl;
	for (i = 0; i < MaxC+2; i++)
	{
	cout << sec[i] << " ";
	}
	cout << endl;*///测试专用

}
Status LinkGame::Delete(Pos x1, Pos y1, Pos x2, Pos y2)
{
	if (!Judge(x1, y1, x2, y2))//如果删除成功，则另两个元素同时为空,分数加一
	{
		arr[x1-1][y1-1] = 0;
	    arr[x2-1][y2-1] = 0;
		Score++;
		return 0;
	}
	else//如果删除失败，则返回1
	{
		return 1;
	}
}
Status LinkGame::Judge_If_Restar()
{
	int i,j,p,q;
	for (i = 1; i <= MaxR; i++)
	{
		for (j = 1; j <=MaxC; j++)
		{
			for (p = 1; p <= MaxR; p++)
			{
				for (q = 1; q <= MaxC; q++)
					if (!Judge(i, j, p, q))
						continue;
					else return 1;
			}
		}
	}
	return 0;
}


void LinkGame::ReStar()
{
	int i = 0, j = 0, Row_number = 0,Col_number=0, *row, *col,*temp,number=0,t;
	row = new int[MaxR*MaxC];
	col = new int[MaxC*MaxR];
	temp = new int[MaxR*MaxC];
	srand((unsigned)time(NULL));//初始化随机数发生器


		for (i = 0; i < MaxR; i++)
		{
			for (j = 0; j < MaxC;j++)
			{
				if (!arr[i][j])
					continue;
				else
				{
					temp[number++] = arr[i][j];
					row[Row_number++] = i;
					col[Col_number++]=j;
					arr[i][j] = 999;
				}
			}
		}
		int x;int y;
		for (int i = 0; i < number;)
		{
			t = rand() % number;
			x = row[t];
			y = col[t];
			if (row[t] != 999)
			{
				arr[x][y] = temp[i];
				row[t] = 999;
				i++;
			}
			else continue;
		}
}
Status LinkGame::GetScore(EleType *s)
{
	if (Score)
	{
		*s = Score;
		return 0;
	}
	else return 1;
}
Status LinkGame::Print()
{
	int i, j;
	for (i = 0; i < MaxR; i++)
	{
		for (j = 0; j < MaxC; j++)
		{
			cout << arr[i][j] << "\t" ;
		}
		cout << endl;
	}
	return 0;
}
Status LinkGame::Supporter(Point &p1,Point &p2)
{
    vector<Point> exist;
    for(int i=0;i<MaxR;i++)
        for(int j=0;j<MaxC;j++)
        {
            if(arr[i][j])
            {
                exist.push_back(Point(i,j,arr[i][j]));
            }
        }
    for(unsigned i=0;i<exist.size();i++)
    for(unsigned j=0;j<exist.size();j++)
    {
        if(i!=j&&!Judge(exist[i].GetX()+1,exist[i].GetY()+1,exist[j].GetX()+1,exist[j].GetY()+1))
        {
            p1.ChangePosition(exist[i].GetX(),exist[i].GetY());
            p1.ChangeColor(exist[i].GetC());
            p2.ChangePosition(exist[j].GetX(),exist[j].GetY());
            p2.ChangeColor(exist[j].GetC());
            return 0;
        }
    }
    return 1;
}
