#ifndef SP
#define SP

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
};

class Product
{
private:

public:
    int id;
    bool state;

    TYPE method(TYPE)
};

#endif