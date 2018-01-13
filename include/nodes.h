#ifndef ND
#define ND

#include <vector>
#include <string>
#include <storage&product.h>

class ProductReceiver
{
    public:
        virtual void receiveProduct(Product*) = 0;
        //virtual ~ProductReceiver() = default;

};

class Storehouse : public ProductReceiver
{
    private:
        //std::vector<Product*> ListOfProducts;
    public:
        //int id;
        virtual void receiveProduct(Product*) override;

        //string getRaport(void){};
};

/*class ProductSender
{
private:
    int duration;
    //std::vector<Link> connections;

public:
    void sendProduct(Product*);
    void addLink(Link);
    virtual void nextRound(void) = 0;
    virtual std::string getRaport(void) = 0;
};

class ProductReceiver
{
public:
   virtual receiveProduct(Product)=0;
   virtual ~ProductReceiver()=default;

};

class LoadingRamp
{
public:
    int id;

    void nextRound() override;
    string getRaport() override;
private:


};

class Worker
{
public:
    int id;

    Worker(Storage*)  //??????//
    void  receiveProduct(Product) override;
    void nextRound(void) override;
    string getRaport(void) override;



private:
    Storage* storage;




};

*/

#endif