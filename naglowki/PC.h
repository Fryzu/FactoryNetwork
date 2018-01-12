#ifndef PC_H
#define PC_H

#include <queue>

class Storage
{
private:
    std::queue<Product> stor_queue;//nazwa "queue" by³a zajêta dla STD


public:
    void push(Product const produkt){
        stor_queue.push(produkt);
    }
     void pop(){
         stor_queue.pop();
     }
}

class Product
{
private:

public:
    int id;
    bool state;

    TYPE method(TYPE)
};

class Storehouse:public ProductReceiver
{
private:
    std::vector<Product> ListOfProducts;
public:
    int id;

    virtual /*(void)?*/ receiveProduct(Product) override{};

    string getRaport(void){};


};

#endif LLW_H
