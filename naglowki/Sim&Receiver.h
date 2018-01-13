class Simulation ////
{
private:
    std::vector<Storehouse> storehouses;
    std::vector<Worker>workers;
    std::vector<LoadingRamp>loadingRamps;

    int stringToInt(const std::tring &);
    void processLoadingRamp(std::string& );
    void processWorkers(std::string& );
    void processStorehouses(std::string& );
    void processLinks(std::string& );
    void processLine(std::string& );



public:
    void simulate(std::string);
    void interpretateFile(std::string);
    string generateRaport(std::string);
    Simulation(string &);    //Konstruktor!!!!//

};

class ProductReceiver
{
public:
   virtual receiveProduct(Product)=0;
   virtual ~ProductReceiver()=default;

};
