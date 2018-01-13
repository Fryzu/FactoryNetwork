#include <iostream>
#include <storage&product.h>
#include <nodes.h>
#include <link.h>
#include <gtest/gtest.h>

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
    ProductReceiver *testReceiver = new Storehouse();
    Link testLink(0.6, testReceiver);

    EXPECT_EQ(testLink.probability, 0.6);

    testLink.setProbability(0.2);

    EXPECT_EQ(testLink.probability, 0.2);
}