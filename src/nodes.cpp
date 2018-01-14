#include <nodes.h>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>

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

//Piotrek ufam Ci!!!
void ProductSender::sendProduct(Product* _product)
{
    srand( time( NULL ) );

    double wskaznik_wyboru = std::rand()%100;
    double kwartyl = 0;

    for(auto& i : connections)
    {
        kwartyl = kwartyl + i->probability;
        if (wskaznik_wyboru <= kwartyl*100)
        {
            i->send(_product);

            return;
        }
    }
}

void ProductSender::addLink(Link* _link)
{
    connections.push_back(_link);
}


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

void LoadingRamp::nextRound(int _time)
{
    int _duration = this->getDuration();
    bool _isEmpty = this->isEmpty();

    if ((_time % _duration == 0) and (_isEmpty == false))
    {
        this->sendProduct(new Product());
    }
}

void Worker::nextRound(int _time)
{
    int _duration = this->getDuration();
    bool _isEmpty = this->isEmpty();
    bool _isEmptyStorage = storage->isEmpty();

    if ((_time % _duration == 0) and (_isEmpty == false) and (_isEmptyStorage == false))
    {
        Product* toSend = storage->pop();
        this->sendProduct(toSend);
    }
}

Link::Link(double _probability, ProductReceiver* _receiver)
{
    probability = _probability;
    pointer = _receiver;
}

void Link::setProbability(double _probability)
{
    probability = _probability;
}   

void Link::send(Product* _product)
{
    pointer->receiveProduct(_product);
}