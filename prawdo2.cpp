#include <vector>
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <stdlib.h>
class Worker
{
private:
public:
    int id;
    Worker(int ID)
    {
        id=ID;
    };

};
class Link
{

public:
    double probability;
    Worker* pointer;

    Link(double p,Worker *worker)
    {
        probability=p;
        pointer=&worker;//ProductReceiver

    };

    Link(void)
    {
        probability=2;
    };

     void setProbability(void)
    {
        std::cout<<'\n'<<"podaj prawdopodobienstwo dla tego Linka (w przedziale od 0 do 1)";
        std::cin>>probability;
    };

};


class ProductSender
{
   private:
    int duration;

   public:


    std::vector<Link> connections;
    void addLink(Link& robotnik1);
};
/*
class ProductReceiver
{

};
*/



class LoadingRamp: public ProductSender
{
public:
    int id;
};

void ProductSender::addLink(Link& robotnik1)
{
  if (robotnik1.probability<=1 && robotnik1.probability>=0)
   {
        connections.push_back(robotnik1);

        for(int i=0;i<connections.size()-1;i++)
        {
            connections[i].probability=(1-robotnik1.probability)*connections[i].probability;
        }
   }
    else
    {
        double rozmiar=connections.size()+1; //nowy pracownik jeszcze nie zostal dodany a nowe prawdopodobienstwo powinno byc ilorazem 1/wszyscy_pracownicy

        robotnik1.probability=1/rozmiar;
        connections.push_back(robotnik1);

        for(int i=0;i<connections.size()-1;i++)
        {
            connections[i].probability=(1-robotnik1.probability)*connections[i].probability;
        }

    }
}

void usunLink(ProductSender & rampa1)
{
    double dodatkowe;
    int wskaznik=rampa1.connections.size()-1;
    dodatkowe=rampa1.connections[wskaznik].probability;

    rampa1.connections.pop_back();
    for(int i=0; i<rampa1.connections.size();i++)
    {
        rampa1.connections[i].probability=rampa1.connections[i].probability/(1-dodatkowe);
    }
}

void sendProduct(ProductSender& rampa1)
{
    double wskaznik_wyboru=std::rand()%100;
    double kwartyl=0;

    for(int i=0; i<rampa1.connections.size()-1;i++)
    {
        kwartyl=kwartyl+rampa1.connections[i].probability;
        if (wskaznik_wyboru<=kwartyl*100)
        {
           std::cout<<"Losuje liczbe od 0-100...  Wylosowano liczbe "<<wskaznik_wyboru<<" co oznacza, ze produkt trafi do robotnika numer "<<i+1;
           return ;
        }

    }
}

void wypisz(ProductSender& rampa1)
{
      for(int i=0; i<rampa1.connections.size();i++)
    {
        std::cout<<"Robotnik "<<i+1<<"  "<<rampa1.connections[i].probability<<'\n';
    }
}

int main()
{
    const int N=10;
    srand( time( NULL ) );


    ProductSender rampa1;

    Worker worker1(1);
    Link robotnik1(1, worker1);
    rampa1.connections.push_back(robotnik1);


    Worker worker2(2);
    Link robotnik2(0.5,worker2);
    rampa1.addLink(robotnik2);

    Worker worker3(3);
    Link robotnik3(0.5,worker3);
    rampa1.addLink(robotnik2);

    wypisz(rampa1);

    Worker worker4(4);
    Link robotnik4(0.4,worker4);

    std::cout<<"prawdopodobienstwo nowego pracownika(domyslne, przed ustaleniem) = "<<robotnik4.probability<<'\n';

    rampa1.addLink(robotnik4);


    std::cout<<"prawdopodobienstwo pracownika po dodaniu do wektora odbiorcow(na podstawie liczby dotychczasowych odbiorcow): "<<rampa1.connections[3].probability<<'\n';

    std::cout<<"preferencje rampy po przeskalowaniu: "<<'\n';

    wypisz(rampa1);

    std::cout<<"Po usunieciu ostatniego Robotnika: "<<'\n';//-----------------------------------------------

    usunLink(rampa1);

    wypisz(rampa1);

    sendProduct(rampa1);
//
    Link wezel;
    wezel.setProbability();



}
