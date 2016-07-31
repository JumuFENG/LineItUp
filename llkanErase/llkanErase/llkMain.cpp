#include <map>
#include <memory>
#include "LineUp.h"

using std::shared_ptr;
using std::string;
using std::wstring;

void main()
{
    LineUpArray cmp(8, 7);
    cmp.initRadom();
    do
    {
        cmp.print();
        int fx, fy, sx, sy;
        cout << "please enter coord of two points:(fx,fy),(sx,sy)" << endl;
        cin >> fx;
        cin >> fy;
        cin >> sx;
        cin >> sy;
        if (cmp.isConectted(fx, fy, sx, sy).IsConnected)
        {
            cmp.reset(fx, fy);
            cmp.reset(sx, sy);
        }
    } while (!cmp.isblank());
    cmp.print();
}
