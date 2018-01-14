#ifndef SP
#define SP

#include <deque>
#include <stack>
#include <queue>
#include <string>

enum storageType
{
    queue,
    stack
};

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
        virtual storageType getType() = 0;
};

class StorageStack : public Storage
{
    public:
        storageType type;
        StorageStack() {type = stack;};
        virtual void push(Product*) override;
        virtual Product* pop() override;
        virtual std::string showProductList() override;

        virtual bool isEmpty() override {return _stack.empty();};
        virtual storageType getType() override {return type;};

    private:
        std::stack<Product*> _stack;
};  

class StorageQueue : public Storage
{
    public:
        storageType type;
        StorageQueue() {type = queue;};
        virtual void push(Product*) override;
        virtual Product* pop() override;
        virtual std::string showProductList() override;

        virtual bool isEmpty() override {return _queue.empty();};
        virtual storageType getType() override {return type;};

    private:
        std::queue<Product*> _queue;
};

#endif