#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using std::cout;
using std::vector;
using std::min;
using std::max;
using std::cout;
using std::cin;
using std::endl;

const int NumOfShape = 9;

struct Cell
{
	int col;
	int row;
	bool isNull;
	Cell()
	{
		isNull = true;
	}

	Cell(int x, int y)
	{
		col = x;
		row = y;
		isNull = false;
	}
};

struct ConnectedResult
{
	bool IsConnected;
	Cell InnerPointOne;
	Cell InnerPointTwo;

	ConnectedResult(bool connected, Cell point1 = Cell(), Cell point2 = Cell())
	{
		IsConnected = connected;
		InnerPointOne = point1;
		InnerPointTwo = point2;
	}
};

class LineUpArray {
public:
	LineUpArray(int m = 0, int n = 0);

	~LineUpArray();

	void initRadom();

	/** �ж�(fx,fy)(sx,sy)�����Ƿ���ͨ
	@return ��ͨ����true
	*/
	ConnectedResult isConectted(int col1, int row1, int col2, int row2);

	void print();

	void reset(int col, int row);

	int GetCellValue(int col, int row);

	bool isblank();

private:
	ConnectedResult ToOutUsedResult(ConnectedResult result);

	/** �Ƿ���x����ֱ����ͨ
	@param �������y��ͬ��fΪ��һ�����x��sΪ�ڶ������x
	@return ��ͨ����true
	*/
	bool isStraitXConnected(int y, int f, int s, bool checkValue = true);

	/** �Ƿ���y����ֱ����ͨ
	@param �������x��ͬ��fΪ��һ�����y��sΪ�ڶ������y
	@return ��ͨ����true
	*/
	bool isStraitYConnected(int x, int f, int s, bool checkValue = true);

	ConnectedResult isConecttedAlongX(int fx, int fy, int sx, int sy);

	ConnectedResult isConecttedAlongY(int fx, int fy, int sx, int sy);

	bool isFilledUp();

private:
	int w;
	int h;
	vector<vector<int> > vecMap;
};
