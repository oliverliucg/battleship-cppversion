//
// Created by 刘小东 on 11/7/21.
//

#include "Coordinate.h"
#include "../Source/MyException.h"
#include "gtest/gtest.h"
namespace {
    TEST(CoordinateTest, DefaultConstructor) {
        const Coordinate c;
        EXPECT_EQ(0, c.getColumn());
        EXPECT_EQ(0, c.getRow());
    }
    TEST(CoordinateTest, ConstructorFromInt) {
        int row = 2, column = 10;
        const Coordinate c(row, column);
        EXPECT_EQ(column, c.getColumn());
        EXPECT_EQ(row, c.getRow());
    }
    TEST(CoordinateTest, ConstructorFromString) {
        std::string k = "A0";
        const Coordinate c(k);
        //Coordinate c(0, 0);
        EXPECT_EQ(0, c.getColumn());
        EXPECT_EQ(0, c.getRow());
        EXPECT_THROW({
             try{
                 Coordinate c("A0");
             }catch( const MyException& e )
             {
                 // and this tests that it has the correct message
                 EXPECT_STREQ( "Error: the length of string to build coordinate is not equal to 2\n", e.what() );
                 throw;
             }
         }, MyException);
    }
}  // namespace
