#include "Sim&Receiver.h";
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

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
    int id = stringToInt(idStr);

    line.erase(0, firstSpacePos+19);

    int deliveryInterval = stringToInt(line);

   // cout << "id: " << id << ", delivery-interval: " << deliveryInterval << endl;

   loadingRamps.push_back(new loadingRamp());



}
void Simulation::processWorkers(string& line)
{
    line.erase(0,10);
    int firstSpacePros=line.find(' ');
    string idStr=line.substr(0,firstSpacePros);
    int id=stringToInt(idStr);


    line.erase(0,firstSpacePros+17);

    firstSpacePros=line.find(' ');
    string _procestime=line.substr(0,firstSpacePros);
    int procestime=stringToInt(_procestime);

    line.erase(0,firstSpacePros+12);

    string queue_type=line;

   // cout<<"id: "<<id<<", processing-time: "<<procestime<<", queue-type: "<<queue_type<<endl;
    workers.push_back(new Worker());



}
void Simulation:: processStorehouses(string& line)
{
line.erase(0,14);
string _id=line;
int id=stringToInt(line);
//cout<<"id: "<<id<<endl;

storehouses.push_back(new Storehouse());

}
void Simulation:: processLinks(string& line)
{
    line.erase(0,9);
    int firstSpacePros=line.find('-');
    string _srctype=line.substr(0,firstSpacePros);
    line.erase(0,firstSpacePros+1);

    firstSpacePros=line.find(' ');
    string _src=line.substr(0,firstSpacePros);
    int src=stringToInt(_src);



    line.erase(0,firstSpacePros+6);

    firstSpacePros=line.find('-');
    string _desttype=line.substr(0,firstSpacePros);

    line.erase(0,firstSpacePros+1);
    firstSpacePros=line.find(' ');
    string _dest=line.substr(0,firstSpacePros);
    int dest=stringToInt(_dest);


    line.erase(0,firstSpacePros+3);








    string _p1=line.substr(0,1);
    int p1=stringToInt(_p1);
    line.erase(0,2);


    string _p2=line;
    int p2=stringToInt(_p2);
    float p=p1+ p2*0.1;



//std:: cout<<"src: "<<_srctype<<"- "<<src<<"  dest: "<<_desttype<<"- "<<dest<<" probability: "<<p<<endl;
}

void Simulation:: processLine(string& line)
{
    if(line.find("LOADING_RAMP") == 0)
    {
        processLoadingRamp(line);
        //cout << "loading ramp" << endl;
    }
    else if(line.find("WORKER") == 0)
    {
        processWorkers(line);
    }
    else if(line.find("STOREHOUSE")==0)
    {
        processStorehouses(line);
    }
    else if(line.find("LINK")==0)
    {
        processLinks(line);
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

        processLine(line);

        //cout << line << endl;
    }

    Simulation::Simulation(string & name)
    {
        interpretateFile(name);
    }

}



