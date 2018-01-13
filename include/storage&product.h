#ifndef SP
#define SP

#include <deque>
#include <stack>
#include <queue>
#include <string>

class Product
{
    
public:
    static int count;  //działa średnio i czasami, ale działa

    int id;
    bool state;

    Product(int = count);
};

class Storage
{    
    public:
        virtual void push(Product*) = 0;
        virtual Product* pop() = 0;
        virtual std::string showProductList() = 0;
        virtual bool isEmpty() = 0;
};

class StorageStack : public Storage
{
    public:
        virtual void push(Product*) override;
        virtual Product* pop() override;
        virtual std::string showProductList() override;

        virtual bool isEmpty() override {return _stack.empty();};

    private:
        std::stack<Product*> _stack;
};

class StorageQueue : public Storage
{
    public:
        virtual void push(Product*) override;
        virtual Product* pop() override;
        virtual std::string showProductList() override;

        virtual bool isEmpty() override {return _queue.empty();};

    private:
        std::queue<Product*> _queue;
};

#endif