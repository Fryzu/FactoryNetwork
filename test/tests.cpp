#include <iostream>
#include <date.h>
#include <gtest/gtest.h>

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(DateTest, StartingValue)
{
    Date testDate1;
    Date testDate2;

    EXPECT_EQ(0, testDate1.getUnixDays());
}

//TESTY BARTKA

TEST(DateTest, OperatorAssign)
{
    Date testDate1(1997, 5, 18);
    Date testDate2 = testDate1;

    EXPECT_EQ(testDate1.getUnixDays(), testDate2.getUnixDays()); 
}

TEST(DateTest, OperatorPlus)
{
    Date testDate1(1997, 5, 18);

    int testValue = 10;
    int expectedResult = testValue + testDate1.getUnixDays();
    
    testDate1 = testValue + testDate1;

    EXPECT_EQ(expectedResult, testDate1.getUnixDays()); 
}

TEST(DateTest, OperatorOutStream)
{
    Date testDate1(1997, 5, 18);
    std::ostringstream os;
    os << testDate1;
    std::stringstream unixDays; 
    unixDays << testDate1.getUnixDays();

    EXPECT_EQ(unixDays.str(), os.str());
}

TEST(DateTest, ComputerDateFormatter)
{
    Date testDate1(1997, 5, 18);
    Date testDate2(1970, 1, 1);
    Date testDate3(2016, 12, 30);

    ComputerDateFormatter formatter;

    EXPECT_EQ("1997-5-18", formatter.format(testDate1));
    EXPECT_EQ("1970-1-1", formatter.format(testDate2));
    EXPECT_EQ("2016-12-30", formatter.format(testDate3));
}

TEST(DateTest, GermanDateFormatter)
{
    Date testDate1(1997, 5, 18);
    Date testDate2(1970, 1, 1);
    Date testDate3(2016, 12, 30);

    GermanDateFormatter formatter;

    EXPECT_EQ("18.05.1997", formatter.format(testDate1));
    EXPECT_EQ("01.01.1970", formatter.format(testDate2));
    EXPECT_EQ("30.12.2016", formatter.format(testDate3));  
}
//MrauMrauChan

TEST(DateTest,OperatorMinus)
{
		EXPECT_EQ(Date(1997,6,1)-1,Date(1997,5,31));
		EXPECT_EQ(Date(1997,1,1)-1,Date(1996,12,31));
		EXPECT_EQ(Date(1997,12,1)-1,Date(1997,11,30));
	
}

TEST(DateTest,Konstruktory)
{
	EXPECT_EQ(Date(1997,5,20),Date(1997,5,20));
	EXPECT_EQ(Date(),Date(0));

}

TEST(DateTest,OperatorRozny)
{
	EXPECT_NE(Date(1996,6,31),Date(1997,6,31));
	EXPECT_NE(Date(1997,6,31),Date(1997,4,31));
	EXPECT_NE(Date(1997,6,30),Date(1997,6,31));
	EXPECT_NE(Date(232323),Date(1997,6,31));

}

