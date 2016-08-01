#include "LineUp.h"

/************************************************************************/
/* 0 1 -------------m w
1
|
|
n
w
*/
/************************************************************************/
LineUpArray::LineUpArray(int m,int n, int shapes)
{
    if (m != 0 && n != 0)
    {
        w = m + 2;
        h = n + 2;
        for (int i = 0; i < w; ++i)
        {
            vector<int> vecRow(h, 0);
            vecMap.push_back(vecRow);
        }
    }
    else
    {
        w = 0;
        h = 0;
    }
    shapeNum = shapes;
}

LineUpArray::~LineUpArray()
{

}

void LineUpArray::InitRadom()
{
    srand(time(NULL));
    vector<int> ele;
    for (int i = 1; i <= shapeNum; ++i)
    {
        ele.push_back(i);
    }

    do
    {
        int cur = ele[rand() % shapeNum];
        do
        {
            int fx = rand() % (w - 2) + 1;
            int fy = rand() % (h - 2) + 1;
            if (vecMap[fx][fy] == 0)
            {
                vecMap[fx][fy] = cur;
                break;
            }
        } while (1);
        do
        {
            int sx = rand() % (w - 2) + 1;
            int sy = rand() % (h - 2) + 1;
            if (vecMap[sx][sy] == 0)
            {
                vecMap[sx][sy] = cur;
                break;
            }
        } while (1);
    } while (!isFilledUp());
}

void LineUpArray::InitWithArray(vector<vector<int>> arr)
{

}

/** 判断(fx,fy)(sx,sy)两点是否连通
@return 连通返回true
*/
ConnectedResult LineUpArray::IsConectted(int col1, int row1, int col2, int row2)
{
    const int fx = col1 + 1;
    const int fy = row1 + 1;
    const int sx = col2 + 1;
    const int sy = row2 + 1;
    if (vecMap[fx][fy] != vecMap[sx][sy])
    {
        return ConnectedResult(false);
    }

    if (fx == sx) // 同一列
    {
        if (isStraitYConnected(fx, fy, sy))
        {
            return ConnectedResult(true);
        }
        else
        {
            ConnectedResult connected = isConecttedAlongX(fx, fy, sx, sy);
            return ToOutUsedResult(connected);
        }
    }
    if (fy == sy) // 同一行
    {
        if (isStraitXConnected(fy, fx, sx))
        {
            return ConnectedResult(true);
        }
        else
        {
            ConnectedResult connected = isConecttedAlongY(fx, fy, sx, sy);
            return ToOutUsedResult(connected);
        }
    }

    ConnectedResult connectedResult = isConecttedAlongX(fx, fy, sx, sy);
    if (connectedResult.IsConnected)
    {
        return ToOutUsedResult(connectedResult);
    }
    connectedResult = isConecttedAlongY(fx, fy, sx, sy);
    if (connectedResult.IsConnected)
    {
        return ToOutUsedResult(connectedResult);
    }

    return ConnectedResult(false);
}

void LineUpArray::Print()
{
    cout << "  ";
    for (int i = 1; i < w - 1; ++i)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int y = 1; y < h - 1; ++y)
    {
        cout << y << " ";
        for (int x = 1; x < w - 1; ++x)
        {
            cout << vecMap[x][y] << " ";
        }
        cout << y << endl;
    }
    cout << "  ";
    for (int i = 1; i < w - 1; ++i)
    {
        cout << i << " ";
    }
    cout << endl;
}

void LineUpArray::Reset(int col, int row)
{
    vecMap[col + 1][row + 1] = 0;
}

int LineUpArray::GetCellValue(int col, int row)
{
    return vecMap[col + 1][row + 1];
}

bool LineUpArray::IsBlank()
{
    for (vector<vector<int> >::iterator itRow = vecMap.begin();
        itRow != vecMap.end(); ++itRow)
    {
        for (vector<int>::iterator it = itRow->begin(); it != itRow->end(); ++it)
        {
            if (*it)
            {
                return false;
            }
        }
    }
    return true;
}

ConnectedResult LineUpArray::ToOutUsedResult(ConnectedResult result)
{
    ConnectedResult r = result;
    if (r.InnerPointOne.isNull)
    {
        r.InnerPointOne.col = result.InnerPointOne.col + 1;
        r.InnerPointOne.row = result.InnerPointOne.row + 1;
    }

    if (r.InnerPointTwo.isNull)
    {
        r.InnerPointTwo.col = result.InnerPointTwo.col + 1;
        r.InnerPointTwo.row = result.InnerPointTwo.row + 1;
    }

    return r;
}

/** 是否在x方向直线连通
@param 两个点的y相同，f为第一个点的x，s为第二个点的x
@return 连通返回true
*/
bool LineUpArray::isStraitXConnected(int y, int f, int s, bool checkValue)
{
    int l = min(f, s);
    int g = max(f, s);

    bool startEqualsEnd = false;

    if (checkValue)
    {
        startEqualsEnd = vecMap[l][y] == vecMap[g][y];
    }
    else
    {
        startEqualsEnd = vecMap[l][y] * vecMap[g][y] == 0;
    }

    while (++l < g)
    {
        if (vecMap[l][y] != 0)
        {
            return false;
        }
    }
    return startEqualsEnd;
}

/** 是否在y方向直线连通
@param 两个点的x相同，f为第一个点的y，s为第二个点的y
@return 连通返回true
*/
bool LineUpArray::isStraitYConnected(int x, int f, int s, bool checkValue)
{
    int l = min(f, s);
    int g = max(f, s);

    bool startEqualsEnd = false;
    if (checkValue)
    {
        startEqualsEnd = vecMap[x][l] == vecMap[x][g];
    }
    else
    {
        startEqualsEnd = vecMap[x][l] * vecMap[x][g] == 0;
    }

    while (++l < g)
    {
        if (vecMap[x][l] != 0)
        {
            return false;
        }
    }
    return startEqualsEnd;
}

ConnectedResult LineUpArray::isConecttedAlongX(int fx, int fy, int sx, int sy)
{
    int fminX = 0, fmaxX = 0;
    for (int i = fx - 1, j = fx + 1; i >= 0 || j < w; --i, ++j)
    {
        if (fminX == 0 && i >= 0)
        {
            if (vecMap[i][fy] != 0)
            {
                fminX = i;
            }
        }
        if (fmaxX == 0 && j < w)
        {
            if (vecMap[j][fy] != 0)
            {
                fmaxX = j;
            }
        }
        if (fminX != 0 && fmaxX != 0)
        {
            break;
        }
    }
    fmaxX = (fmaxX == 0 ? w : fmaxX);
    int sminX = 0, smaxX = 0;
    for (int i = sx - 1, j = sx + 1; i >= fminX || j < fmaxX; --i, ++j)
    {
        if (sminX == 0 && i >= fminX)
        {
            if (vecMap[i][sy] != 0)
            {
                sminX = i;
            }
        }
        if (smaxX == 0 && j < fmaxX)
        {
            if (vecMap[j][sy] != 0)
            {
                smaxX = j;
            }
        }
        if (sminX != 0 && smaxX != 0)
        {
            break;
        }
    }
    smaxX = (smaxX == 0 ? w : smaxX);
    int minX = max(fminX, sminX);
    int maxX = min(fmaxX, smaxX);

    if (minX >= maxX)
    {
        return ConnectedResult(false);
    }
    for (int k = minX; k < maxX; ++k)
    {
        if (isStraitYConnected(k, fy, sy, false))
        {
            return ConnectedResult(true, Cell(k, fy), Cell(k, sy));
        }
    }
    return ConnectedResult(false);
}

ConnectedResult LineUpArray::isConecttedAlongY(int fx, int fy, int sx, int sy)
{
    int fminY = 0, fmaxY = 0;
    for (int i = fy - 1, j = fy + 1; i >= 0 || j < h; --i, ++j)
    {
        if (fminY == 0 && i >= 0)
        {
            if (vecMap[fx][i] != 0)
            {
                fminY = i;
            }
        }
        if (fmaxY == 0 && j < h)
        {
            if (vecMap[fx][j] != 0)
            {
                fmaxY = j;
            }
        }
        if (fminY != 0 && fmaxY != 0)
        {
            break;
        }
    }
    fmaxY = (fmaxY == 0 ? h : fmaxY);
    int sminY = 0, smaxY = 0;
    for (int i = sy - 1, j = sy + 1; i >= fminY || j < fmaxY; --i, ++j)
    {
        if (sminY == 0 && i >= fminY)
        {
            if (vecMap[sx][i] != 0)
            {
                sminY = i;
            }
        }
        if (smaxY == 0 && j < fmaxY)
        {
            if (vecMap[sx][j] != 0)
            {
                smaxY = j;
            }
        }
        if (sminY != 0 && smaxY != 0)
        {
            break;
        }
    }
    smaxY = (smaxY == 0 ? h : smaxY);
    int minY = max(fminY, sminY);
    int maxY = min(fmaxY, smaxY);
    if (minY >= maxY)
    {
        return ConnectedResult(false);
    }
    for (int k = minY; k < maxY; ++k)
    {
        if (isStraitXConnected(k, fx, sx))
        {
            return ConnectedResult(true, Cell(fx, k), Cell(sx, k));
        }
    }
    return ConnectedResult(false);
}

bool LineUpArray::isFilledUp()
{
    int zeroNum = 0;
    for (vector<vector<int> >::iterator itRow = vecMap.begin() + 1;
        itRow != vecMap.end() - 1; ++itRow)
    {
        for (vector<int>::iterator itCol = itRow->begin() + 1;
            itCol != itRow->end() - 1; ++itCol)
        {
            if (*itCol == 0)
            {
                zeroNum++;
                if (zeroNum > 1)
                {
                    return false;
                }
            }
        }
    }

    if (zeroNum == 1)
    {
        return (w*h) % 2 == 1;
    }

    return true;
}
