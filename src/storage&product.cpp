#include <storage&product.h>
#include <sstream>

int Product::count = 0;

Product::Product(int _id)
{
    id = _id;
    Product::count = _id + 1; //zapewnia ciągłość id
    state = false;
}

void StorageStack::push(Product* produkt)
{
    _stack.push(produkt);
}

Product* StorageStack::pop()
{
    auto tmp = _stack.top();
    _stack.pop();

    return tmp;
}

std::string StorageStack::showProductList()
{
    std::stringstream tmp;

    std::stack<Product*> tmpStack = _stack;

    while(tmpStack.empty() == false)
    {
        tmp << tmpStack.top()->id << ",";
        tmpStack.pop();
    }

    return tmp.str();
}

std::string StorageQueue::showProductList()
{
    std::stringstream tmp;

    std::queue<Product*> tmpQueue = _queue;

    while(tmpQueue.empty() == false)
    {
        tmp << tmpQueue.front()->id << ",";
        tmpQueue.pop();
    }

    return tmp.str();
}

void StorageQueue::push(Product* produkt)
{
    _queue.push(produkt);
}

Product* StorageQueue::pop()
{
    auto tmp = _queue.front();
    _queue.pop();

    return tmp;
}