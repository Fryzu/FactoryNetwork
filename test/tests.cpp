#include <iostream>
#include <storage&product.h>
#include <gtest/gtest.h>

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(ProductTest, ConstructuctingAndId)
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

TEST(StorageTest, StorageStack)
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

TEST(StorageTest, StorageQueue)
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