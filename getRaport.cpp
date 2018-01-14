#include <iostream>
#include<sstream>
#include<string>
using namespace std;

void Simulation::getStructRaport
{
    ofstream plik;
    plik.open("struct-exit.txt",ios::out);
    stringstream ss;
    ss<<'\n\n'<<"== LOADING RAMPS ==";
    for (i:loadingRamps)
    {
        ss<<i.getStructRaport()<<'\n'
    }

    ss<<'\n\n'<<"== WORKERS ==";
    for (i:workers)
    {
        ss<<i.getStructRaport()<<'\n'
    }


    ss<<'\n\n'<<"== STOREHOUSES ==";
    for (i:storehouses)
    {
        ss<<i.getStructRaport()<<'\n'
    }
 plik<<ss;
 plik.close();
}

void Simulation::getSimRaport
{
    ofstream plik;
    plik.open("sim-exit.txt",ios::out);

    ss<<'\n\n'<<"== WORKERS ==";
    for (i:workers)
    {
        ss<<i.getSimRaport()<<'\n'
    }
     ss<<'\n\n'<<"== STOREHOUSES ==";
    for (i:storehouses)
    {
        ss<<i.getSimRaport()<<'\n'
    }

plik<<ss;
plik.close();
}


 string Worker::getSimRaport()
 {
     stringstream ss;
     ss<<"WORKER#"<<id<<'\n';

     if (queue.type()=="FIFO") //Jaki jest typ magazynu

     {

     }
     else
        if (queue.type()=="LIFO")
     {

     }


    return ss.str();
 }




 string Storehouse::getSimRaport
 {
     stringstream ss;
     ss<<"STOREHOUSE#"<<id<<'\n';

     return ss.str();
 }

string Storehouse::getStructRaport
{

}

string Worker::getStructRaport
{

}

string loadingRamp::getStructRaport
{

}


string Link::getStruct Raport
{

}



