#include <link.h>

Link::Link(double _probability, const ProductReceiver* _receiver)
{
    probability = _probability;
    pointer = _receiver;
}

void Link::setProbability(double _probability)
{
    probability = _probability;
}