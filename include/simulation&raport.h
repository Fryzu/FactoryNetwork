#include <nodes.h>

enum raportType 
{
    structure,
    simulation
};

class Simulation
{
    private:
        std::vector<Storehouse*> storehouses;
        std::vector<Worker*> workers;
        std::vector<LoadingRamp*> loadingRamps;

        //int stringToInt(const std::tring &);
        //void processLoadingRamp(std::string& );
        //void processWorkers(std::string& );
        //void processStorehouses(std::string& );
        //void processLinks(std::string& );
        //void processLine(std::string& );
        //void interpretateFile(std::string&);

    public:
        //void simulate(std::string);
        //string generateRaport(std::string);
        //Simulation(string &);    //Konstruktor!!!!//
        void addStorehouse(Storehouse*);
        void addWorker(Worker*);
        void addLoadingRamp(LoadingRamp*);


    friend class Raport;
};

class Raport 
{
    private:
        //raportType type;
    
    public:
        //std::string content;
        //Raport(const Simulation*, raportType);

        std::string createStructRaport(const Simulation*);

};