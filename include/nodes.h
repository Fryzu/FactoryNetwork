#ifndef ND
#define ND

#include <vector>
#include <string>
#include <storage&product.h>

enum nodeType 
{
    storehouse,
    loadingRamp,
    worker
};

class ProductReceiver
{
    public:
        nodeType type;

        virtual void receiveProduct(Product*) = 0;
        virtual std::string showProductList(void) = 0;
        virtual int getId() = 0;
};

class Link
{
    public:
        Link(double, ProductReceiver*);
        void setProbability(double);
        double probability;
        void send(Product*);
        ProductReceiver* pointer;

};

class Storehouse : public ProductReceiver
{
    private:
        std::vector<Product*> ListOfProducts;
    public:
        int id;

        Storehouse(int _id) : id(_id) {type = storehouse;};
        virtual void receiveProduct(Product*) override;
        virtual std::string showProductList(void) override;

        virtual int getId() override {return id;};
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
        void sendProduct(Product*);
        virtual void nextRound(int) = 0; 

        int getDuration() {return duration;};
        bool isEmpty() {return connections.empty();}; 
};

class Worker : public ProductReceiver, public ProductSender
{
    public:
        int id;

        Worker(int _id, int _duration, Storage* _storage) : 
        id(_id), ProductSender(_duration), storage(_storage) {type = worker;};

        //receiver
        virtual void receiveProduct(Product*) override;
        virtual std::string showProductList(void) override;
        virtual int getId() override {return id;};

        //sender
        virtual void nextRound(int) override;

    private:
        Storage* storage;
};

class LoadingRamp : public ProductSender
{
    public:
        int id;
        nodeType type;

        LoadingRamp(int _id, int _duration) : 
        id(_id), ProductSender(_duration) {type = loadingRamp;};
        virtual void nextRound(int) override;

};

#endif