#include <vector>
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
class Robotnik
{

public:

    float prob;

    Robotnik(float p)
    {
        prob=p;
    };
    Robotnik(void)
    {
        prob=2;
    }

};

class Rampa
{
public:
    std::vector<Robotnik> robotnicy;
    friend void dodajRobotnika(Rampa& rampa1, Robotnik& robotnik1);//przyjazn na wypadek pozniejszych komplikacji z private
};

void dodajRobotnika(Rampa& rampa1, Robotnik& robotnik1)
{
  if (robotnik1.prob<=1 && robotnik1.prob>=0)
   {
        rampa1.robotnicy.push_back(robotnik1);

        for(int i=0;i<rampa1.robotnicy.size()-1;i++)
        {
            rampa1.robotnicy[i].prob=(1-robotnik1.prob)*rampa1.robotnicy[i].prob;
        }
   }
    else
    {
        float rozmiar=rampa1.robotnicy.size()+1; //nowy pracownik jeszcze nie zostal dodany a nowe prawdopodobienstwo powinno byc ilorazem 1/wszyscy_pracownicy

        robotnik1.prob=1/rozmiar;
        rampa1.robotnicy.push_back(robotnik1);

        for(int i=0;i<rampa1.robotnicy.size()-1;i++)
        {
            rampa1.robotnicy[i].prob=(1-robotnik1.prob)*rampa1.robotnicy[i].prob;
        }

    }
}

void wybor_odbiorcy(Rampa& rampa1)
{
    float wskaznik_wyboru=std::rand()%100;
    float kwartyl=0;

    for(int i=0; i<rampa1.robotnicy.size()-1;i++)
    {
        kwartyl=kwartyl+rampa1.robotnicy[i].prob;
        if (wskaznik_wyboru<=kwartyl*100)
        {
           std::cout<<"Losuje liczbe od 0-100...  Wylosowano liczbe "<<wskaznik_wyboru<<" co oznacza, ze produkt trafi do robotnika numer "<<i+1;
           return ;
        }

    }
}

int main()
{
    const int N=10;
    srand( time( NULL ) );


    Rampa rampa1;
    Robotnik robotnik1(1);
    rampa1.robotnicy.push_back(robotnik1);



    Robotnik robotnik2(0.5);
    dodajRobotnika(rampa1,robotnik2);

 Robotnik robotnik3(0.5);
    dodajRobotnika(rampa1,robotnik2);

     for(int i=0; i<rampa1.robotnicy.size();i++)
    {
        std::cout<<"Robotnik "<<i+1<<"  "<<rampa1.robotnicy[i].prob<<'\n';
    }

    Robotnik robotnik4;

    std::cout<<"prawdopodobienstwo nowego pracownika(domyslne, przed ustaleniem) = "<<robotnik4.prob<<'\n';

    dodajRobotnika(rampa1, robotnik4);


    std::cout<<"prawdopodobienstwo pracownika po dodaniu do wektora odbiorcow(na podstawie liczby dotychczasowych odbiorcow): "<<rampa1.robotnicy[3].prob<<'\n';

    std::cout<<"preferencje rampy po przeskalowaniu: "<<'\n';

    for(int i=0; i<rampa1.robotnicy.size();i++)
    {
        std::cout<<"Robotnik "<<i+1<<"  "<<rampa1.robotnicy[i].prob<<'\n';
    }

   wybor_odbiorcy(rampa1);

}
