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

	/** 判断(fx,fy)(sx,sy)两点是否连通
	@return 连通返回true
	*/
	ConnectedResult isConectted(int col1, int row1, int col2, int row2);

	void print();

	void reset(int col, int row);

	int GetCellValue(int col, int row);

	bool isblank();

private:
	ConnectedResult ToOutUsedResult(ConnectedResult result);

	/** 是否在x方向直线连通
	@param 两个点的y相同，f为第一个点的x，s为第二个点的x
	@return 连通返回true
	*/
	bool isStraitXConnected(int y, int f, int s, bool checkValue = true);

	/** 是否在y方向直线连通
	@param 两个点的x相同，f为第一个点的y，s为第二个点的y
	@return 连通返回true
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
