#ifndef PC_H
#define PC_H

class ProductSender
{

private:
    int duration;
    std::vector<Link> connections;

public:
    void sendProduct(Product &,*Link);
    void addLink(Link);
    virtual void nextRound(void)=0;
    virtual string getRaport(void)=0;
};

#endif LLW_H
