#ifndef STAR_H
#define STAR_H

#include "destroy.h"
#include "vertical.h"
#include "horizontal.h"
#include "nineblock.h"

class Star:public Destroy
{
public:
    Star();
    virtual ~Star();
    virtual int condition(Blank *a[10][10], Blank *focus);
    virtual void spawn(Blank *a[10][10], Blank *focus, int mode);
    virtual void eliminate(Blank *a[10][10], Blank *focus);
};

#endif // STAR_H
