#ifndef LLW_H
#define LLW_H

class Link
{
public:
     void setProbability(double);

private:
    ProductReceiver* pointer;
    double probability;




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


#endif LLW_H

