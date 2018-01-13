#include <nodes.h>
#include <sstream>

void Storehouse::receiveProduct(Product* _product)
{
    ListOfProducts.push_back(_product);
}

std::string Storehouse::showProductList(void)
{
    std::stringstream tmp;

    for (auto i : ListOfProducts)
    {
        tmp << i->id << ",";
    }

    return tmp.str();
}

void Worker::receiveProduct(Product* _product)
{
    storage->push(_product);
}

std::string Worker::showProductList(void)
{
    return storage->showProductList();
}

std::string ProductSender::showConnectionsList(void)
{
    std::stringstream tmp;

    for (auto i : connections)
    {
        tmp << i->probability << ",";
    }

    return tmp.str();
}

void ProductSender::addLink(Link* _link)
{
    connections.push_back(_link);
}

//Piotrek ufam Ci!!!
void ProductSender::addLinkRescaling(Link* _link)
{
    if (_link->probability <= 1 && _link->probability >= 0)
    {
        connections.push_back(_link);

        for (auto& i : connections)
        {
            i->probability = (1 - _link->probability) * i->probability;
        }
    }
    else
    {
        double rozmiar = connections.size() + 1; //nowy pracownik jeszcze nie zostal dodany a nowe prawdopodobienstwo powinno byc ilorazem 1/wszyscy_pracownicy

        _link->probability = 1 / rozmiar;
        connections.push_back(_link);

        for (auto& i : connections)
        {
            i->probability = (1 - _link->probability) * i->probability;
        }
    }
}

Link::Link(double _probability, const ProductReceiver* _receiver)
{
    probability = _probability;
    pointer = _receiver;
}

void Link::setProbability(double _probability)
{
    probability = _probability;
}   