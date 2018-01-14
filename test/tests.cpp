#include <iostream>
#include <storage&product.h>
#include <nodes.h>
#include <gtest/gtest.h>
#include <simulation&raport.h>

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Product, ConstructuctingAndId)
{
    EXPECT_EQ(Product::count, 0);
    Product tmp3;
    EXPECT_EQ(tmp3.id, 0);

    Product tmp(3);
    EXPECT_EQ(Product::count, 4);

    EXPECT_EQ(tmp.id, 3);
    EXPECT_EQ(tmp.state, false);

    Product tmp2;
    EXPECT_EQ(tmp2.id, 4);
    EXPECT_EQ(tmp2.state, false);
    EXPECT_EQ(Product::count, 5);
}

TEST(Storage, StorageStack)
{
    Product* testProduct1 = new Product(1);
    Product* testProduct2 = new Product(2);
    Product* testProduct3 = new Product(3);

    Storage* testStack = new StorageStack();
    testStack->push(testProduct1);
    testStack->push(testProduct2);
    testStack->push(testProduct3);

    EXPECT_EQ(testStack->showProductList(), "3,2,1,");
}

TEST(Storage, StorageQueue)
{
    Product* testProduct1 = new Product(1);
    Product* testProduct2 = new Product(2);
    Product* testProduct3 = new Product(3);

    Storage* testQueue = new StorageQueue();
    testQueue->push(testProduct1);
    testQueue->push(testProduct2);
    testQueue->push(testProduct3);

    EXPECT_EQ(testQueue->showProductList(), "1,2,3,");
}

TEST(Link, ConstructingAndSettingProbability)
{
    ProductReceiver *testReceiver = new Storehouse(0);
    Link testLink(0.6, testReceiver);

    EXPECT_EQ(testLink.probability, 0.6);

    testLink.setProbability(0.2);

    EXPECT_EQ(testLink.probability, 0.2);
}

TEST(Storehouse, ReceivingProduct)
{
    Storehouse testReceiver(0);
    Product* testProduct1 = new Product(1);
    Product* testProduct2 = new Product(2);

    testReceiver.receiveProduct(testProduct1);
    testReceiver.receiveProduct(testProduct2);

    EXPECT_EQ(testReceiver.showProductList(), "1,2,");
}

TEST(Worker, ReceivingProduct)
{
    Storage* testQueue = new StorageQueue();
    Storage* testStack = new StorageStack();

    Worker testWorker1(0, 1, testQueue);
    Worker testWorker2(0, 1, testStack);

    Product* testProduct1 = new Product(1);
    Product* testProduct2 = new Product(2);
    Product* testProduct3 = new Product(3);

    testWorker1.receiveProduct(testProduct1);
    testWorker1.receiveProduct(testProduct2); 
    testWorker1.receiveProduct(testProduct3);

    testWorker2.receiveProduct(testProduct1);
    testWorker2.receiveProduct(testProduct2); 
    testWorker2.receiveProduct(testProduct3);

    EXPECT_EQ(testWorker1.showProductList(), "1,2,3,");
    EXPECT_EQ(testWorker2.showProductList(), "3,2,1,");        
}

TEST(ProductSender, AddingLinkAndRescaling)
{
    auto testStorehouse = new Storehouse(1);

    Link* testLink1 = new Link(0.2, testStorehouse);
    Link* testLink2 = new Link(0.3, testStorehouse);
    Link* testLink3 = new Link(0.5, testStorehouse);
    Link* testLink4 = new Link(0.5, testStorehouse);

    Worker testWorker1(0, 1, NULL);

    testWorker1.addLink(testLink1);
    testWorker1.addLink(testLink2);
    testWorker1.addLink(testLink3);

    EXPECT_EQ(testWorker1.showConnectionsList(), "- storehouse #1 (p = 0.2)\n- storehouse #1 (p = 0.3)\n- storehouse #1 (p = 0.5)\n");

    testWorker1.addLinkRescaling(testLink4);
    EXPECT_EQ(testWorker1.showConnectionsList(), "- storehouse #1 (p = 0.1)\n- storehouse #1 (p = 0.15)\n- storehouse #1 (p = 0.25)\n- storehouse #1 (p = 0.5)\n");
}

TEST(ProductSender, Sending)
{
    Storehouse* testStorehouse = new Storehouse(0);
    Product* testProduct1 = new Product(6);

    LoadingRamp testLoadingRamp(0, 1);
    testLoadingRamp.addLink(new Link(0.6, testStorehouse));
    testLoadingRamp.addLink(new Link(0.4, testStorehouse));
    testLoadingRamp.sendProduct(testProduct1);

    EXPECT_EQ(testStorehouse->showProductList(), "6,");
}

TEST(LoadingRamp, nextRound)
{
    Product zero(0); //zeruje licznik
    Storehouse* testStorehouse = new Storehouse(0);

    LoadingRamp testLoadingRamp(0, 2);
    testLoadingRamp.addLink(new Link(1, testStorehouse));

    //Iterujemy po turach
    EXPECT_EQ(testStorehouse->showProductList(), ""); //pusty
    testLoadingRamp.nextRound(0);
    EXPECT_EQ(testStorehouse->showProductList(), "1,");
    testLoadingRamp.nextRound(1);
    EXPECT_EQ(testStorehouse->showProductList(), "1,");
    testLoadingRamp.nextRound(2);
    EXPECT_EQ(testStorehouse->showProductList(), "1,2,");
}

TEST(Worker, nextRound)
{
    Storehouse* testStorehouse = new Storehouse(0);

    StorageStack* testStorage = new StorageStack();
    Worker testWorker(0, 2, testStorage);
    testWorker.addLink(new Link(1, testStorehouse));

    testStorage->push(new Product(16));

    //Iterujemy po turach
    EXPECT_EQ(testStorehouse->showProductList(), ""); //pusty
    testWorker.nextRound(0);
    EXPECT_EQ(testStorehouse->showProductList(), "16,");
    testWorker.nextRound(2);
    EXPECT_EQ(testStorehouse->showProductList(), "16,");
}

TEST(Raport, createStructRaport)
{
    //Przygotowanie symulacji testowej
    Simulation* testSimulation = new Simulation;

    auto testStorehouse = new Storehouse(1);
    testSimulation->addStorehouse(testStorehouse);

    auto testLoadingRamp = new LoadingRamp(1, 2);
    testLoadingRamp->addLink(new Link(1, testStorehouse));
    testSimulation->addLoadingRamp(testLoadingRamp);

    testSimulation->addWorker(new Worker(1, 1, new StorageQueue()));

    Raport testRaport;
    std::cout << testRaport.createStructRaport(testSimulation);
}
