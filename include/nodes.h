#ifndef ND
#define ND

#include <vector>
#include <string>
#include <storage&product.h>

class ProductReceiver
{
    public:
        virtual void receiveProduct(Product*) = 0;
        virtual std::string showProductList(void) = 0;

};

class Link
{
    public:
        void setProbability(double);
        Link(double, const ProductReceiver*);
        double probability;

    private:
        const ProductReceiver* pointer;

};

class Storehouse : public ProductReceiver
{
    private:
        std::vector<Product*> ListOfProducts;
    public:
        Storehouse(int _id) : id(_id) {};
        int id;
        virtual void receiveProduct(Product*) override;
        virtual std::string showProductList(void) override;
};

class ProductSender
{
    private:
        int duration;
        std::vector<Link*> connections;

    public:
        ProductSender(int _duration) : duration(_duration) {};
        void addLinkRescaling(Link*);
        void addLink(Link*);
        std::string showConnectionsList(void);
        //void sendProduct(Product*);
        //virtual void nextRound(void) = 0;  
};

class Worker : public ProductReceiver, public ProductSender
{
    public:
        int id;

        Worker(int _id, int _duration, Storage* _storage) : 
        id(_id), ProductSender(_duration), storage(_storage) {};

        //receiver
        virtual void receiveProduct(Product*) override;
        virtual std::string showProductList(void) override;

        //sender

    private:
        Storage* storage;
};

/*
class LoadingRamp
{
public:
    int id;

    void nextRound() override;
    string getRaport() override;
private:


};



*/

#endif