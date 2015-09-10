#include "vmap.h"

Vmap::Vmap()
{
    data.resize(40);
    for (int i = 0; i < 40; ++i) data.at(i).resize(40,0);
}
