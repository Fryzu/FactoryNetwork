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
        virtual void push(const Product*) = 0;
        virtual const Product* pop() = 0;
        virtual std::string showProductList() = 0;
};

class StorageStack : public Storage
{
    public:
        virtual void push(const Product*) override;
        virtual const Product* pop() override;
        virtual std::string showProductList() override;

    private:
        std::stack<const Product*> _stack;
};

class StorageQueue : public Storage
{
    public:
        virtual void push(const Product*) override;
        virtual const Product* pop() override;
        virtual std::string showProductList() override;

    private:
        std::queue<const Product*> _queue;
};

#endif