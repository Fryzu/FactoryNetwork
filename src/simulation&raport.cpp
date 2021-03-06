#include <iostream>
#include <fstream>
#include <sstream>

#include <simulation&raport.h>

using namespace std;

void Simulation::addLoadingRamp(LoadingRamp* toAdd)
{
    loadingRamps.push_back(toAdd);
}

void Simulation::addStorehouse(Storehouse* toAdd)
{
    storehouses.push_back(toAdd);
}

void Simulation::addWorker(Worker* toAdd)
{
    workers.push_back(toAdd);
}

Raport::Raport(const Simulation* _simulation, raportType _raportType)
{
    if (_raportType == structure)
    {
        type = _raportType;
        stringstream ss;

        ss << "==========================" << std::endl;
        ss << "=====STRUCTURE=RAPORT=====" << std::endl;
        ss << "==========================" << std::endl;

        ss << createStructRaport(_simulation);

        content = ss.str();
    }

    if (_raportType == simulation)
    {

    }
}

std::string Raport::createStructRaport(const Simulation* _simulation)
{
    //ofstream plik;
    //plik.open("struct-exit.txt",ios::out);
    stringstream ss;

    ss << "== LOADING RAMPS ==" << "\n\n";
    for (auto i : _simulation->loadingRamps)
    {
        ss << "LOADING RAMP #" << i->id << std::endl;
        ss << "Delivery interval: " << i->getDuration() << std::endl;

        //receivers
        ss << "Receivers: \n";
        std::string _receivers = i->showConnectionsList();
        if (_receivers == "")
        {
            ss << "none";
        }
        else
        {
            ss << _receivers;
        }
        ss << "\n";
    }

    ss << "== WORKERS ==" << "\n\n";
    for (auto i : _simulation->workers)
    {
        ss << "WORKER #" << i->id << std::endl;
        ss << "Processing time: " << i->getDuration() << std::endl;
        
        //storage type
        ss << i->getStorageType() << std::endl;

        //receivers
        ss << "Receivers: \n";
        std::string _receivers = i->showConnectionsList();
        if (_receivers == "")
        {
            ss << "none";
        }
        else
        {
            ss << _receivers;
        }
        ss << "\n";
    }

    ss << "== STOREHOUSES ==" << "\n\n";
    for (auto i : _simulation->storehouses)
    {
        ss << "STOREHOUSE #" << i->id << std::endl;
    }
    //plik<<ss;
    //plik.close();

    return ss.str();
}

/*
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
*/

/*BĘDZIEMY POWOLI DOŁĄCZAĆ RÓŻNE FUNKCJONALNOŚCI, 
  ALE NAJPIERW RAPORTOWANIE PONIEWAŻ BĘDZIE POTRZEBNE DO TESTÓW

int Simulation:: stringToInt(const string& str)
{
    stringstream ss(str);
    int result;

    ss >> result;

    return result;
}

void Simulation::processLoadingRamp(string& line)
{
    line.erase(0, 16);
    int firstSpacePos = line.find(' ');

    string idStr = line.substr(0, firstSpacePos);
    int id = stringToInt(idStr); // id

    line.erase(0, firstSpacePos+19);

    int deliveryInterval = stringToInt(line);//duration


   loadingRamps.push_back(new loadingRamp());



}
void Simulation::processWorkers(string& line)
{
    line.erase(0,10);
    int firstSpacePros=line.find(' ');
    string idStr=line.substr(0,firstSpacePros);
    int id=stringToInt(idStr);//id


    line.erase(0,firstSpacePros+17);

    firstSpacePros=line.find(' ');
    string _procestime=line.substr(0,firstSpacePros);
    int procestime=stringToInt(_procestime);//duration

    line.erase(0,firstSpacePros+12);

    string queue_type=line;//FIFO/FILO



    workers.push_back(new Worker());



}
void Simulation:: processStorehouses(string& line)
{
line.erase(0,14);
string _id=line;
int id=stringToInt(line);


storehouses.push_back(new Storehouse());

}
void Simulation:: processLinks(string& line)
{
    line.erase(0,9);
    int firstSpacePros=line.find('-');
    string _srctype=line.substr(0,firstSpacePros);//Typ w�a�ciciela
    line.erase(0,firstSpacePros+1);

    firstSpacePros=line.find(' ');
    string _src=line.substr(0,firstSpacePros);
    int src=stringToInt(_src);//id w�a�ciciela



    line.erase(0,firstSpacePros+6);

    firstSpacePros=line.find('-');
    string _desttype=line.substr(0,firstSpacePros);//Typ odbiorcy

    line.erase(0,firstSpacePros+1);
    firstSpacePros=line.find(' ');
    string _dest=line.substr(0,firstSpacePros);
    int dest=stringToInt(_dest); // id odbiorcy


    line.erase(0,firstSpacePros+3);








    string _p1=line.substr(0,1);
    int p1=stringToInt(_p1);
    line.erase(0,2);


    string _p2=line;
    int p2=stringToInt(_p2);
    float p=p1+ p2*0.1; //probability

    int a;
    int b;


    if(_srctype=="ramp")
    {
        for(auto i :loadingRamps)
        {
            if(loadingRamps[i].id==src)
            {
                a=i;
            }
        }

        if(_desttype=="worker")
        {
            for(auto i :workers)
        {
            if(workers[i].id==dest)
            {
                b=i;
            }
        }

            loadingRamps[a].connections.push_back(new Link(workers[b],p));

        }

    else
    if(_srctype=="worker")

    {
        for(auto i :workers)
        {
            if(workers[i].id==src)
            {
                a=i;
            }
        }
        if(_desttype=="worker")
        {
            for(auto i :workers)
        {
            if(workers[i].id==dest)
            {
                b=i;
            }
        }

            workers[a].connections.push_back(new Link(workers[b],p));
        }
        else
            if(_desttype=="store")
            {
                for(auto i :storehouses)
        {
            if(storehouses[i].id==dest)
            {
                b=i;
            }
        }

            workers[a].connections.push_back(new Link(p,storehouses[b]));

            }



    }


}


void Simulation:: processLine(string& line)
{
    if(line.find("LOADING_RAMP") == 0)
    {
        processLoadingRamp(line);

    }
    else if(line.find("WORKER") == 0)
    {
        processWorkers(line);
    }
    else if(line.find("STOREHOUSE")==0)
    {
        processStorehouses(line);
    }



}

void  Simulation::interpretateFile(string &name)
{
    std::fstream plik;
    plik.open(name, std::ios::in);

    while(!plik.eof())
    {
        string line;
        getline(plik, line);

        processLine(line); // Pierwsze przej�cie po pliku, dodajemy Nody



    }
    plik.close();
    plik.open(name, std::ios::in);

    while(!plik.eof())
    {
        string line;
        getline(plik, line);
        processLinks(string&line); //Drugie przej�cie po pliku, dodajemy linki


    Simulation::Simulation(string & name)
    {
        interpretateFile(name);
    }

}*/