//© Дмитрий Утямишев, 2011

#ifndef VMAP_H
#define VMAP_H
using namespace std;
#include <vector>

class Vmap
{
public:
    Vmap();

    int Emp(int x, int y)
    {
        if (data.at(x).at(y) == 1) return 1;
        else return 0;
    }

    int Bar(int x, int y)
    {
        if (data.at(x).at(y) == 2) return 1;
        else return 0;
    }

    void Set(int x, int y, int state)
    {
        data[x][y] = state;
    }

    void Clr (int x, int y)
    {
        data[x][y] = 0;
    }

private:

    vector < vector <int> > data;
};

#endif // VMAP_H
