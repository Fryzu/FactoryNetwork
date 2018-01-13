#ifndef LI
#define LI

#include <nodes.h>

class Link
{
public:
    void setProbability(double);
    Link(double, const ProductReceiver*);
    double probability;

private:
    const ProductReceiver* pointer;
};

#endif