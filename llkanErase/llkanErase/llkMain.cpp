#include <map>
#include <memory>
#include "LineUp.h"

using std::shared_ptr;
using std::string;
using std::wstring;

void main()
{
    LineUpArray cmp(8, 7);
    cmp.InitRadom();
    do
    {
        cmp.Print();
        int fx, fy, sx, sy;
        cout << "please enter coord of two points:(fx,fy),(sx,sy)" << endl;
        cin >> fx;
        cin >> fy;
        cin >> sx;
        cin >> sy;
        if (cmp.IsConectted(fx, fy, sx, sy).IsConnected)
        {
            cmp.Reset(fx, fy);
            cmp.Reset(sx, sy);
        }
    } while (!cmp.IsBlank());
    cmp.Print();
}
