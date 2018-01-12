class Simulation ////
{
private:
    std::vector<Storehouse> storehouses;
    std::vector<Worker>workers;
    std::vector<LoadingRamp>loadingRamps;

public:
    void simulate(std::string);
    void interpretateFile(std::string);
    string generateRaport(std::string);
    Simulation()    //Konstruktor!!!!//

};

class ProductReceiver
{
public:
   virtual receiveProduct(Product)=0;
   virtual ~ProductReceiver()=default;

};
