#include <gtest/gtest.h>
#include "vector.cpp"

using namespace std ;

TEST(Vec, constructor)
{
    //arrange
    Vec<string> v() ;
    Vec<string> v1(10) ;
    Vec<string> v2(20, "val") ; 
    //act

    //assert
    //ASSERT_EQ(v.size2(), 0) ;
    //ASSERT_EQ(v.capacity2(), 20) ; 
    ASSERT_EQ(v1.size2(), 0) ;
    ASSERT_EQ(v1.capacity2(), 10) ; 
    ASSERT_EQ(v2.size2(), 20) ;
    ASSERT_EQ(v2.capacity2(), 40) ; 
}

TEST(Vec, push_back)
{
    //arrange
    Vec<int> v(10) ; 
    //act
    int num = 100 ;
    for(int i = 0 ; i < num ; ++i)
    {
        v.push_back(i) ;
    }

    //assert
    //ASSERT_EQ(v.capacity2(), 100) ; 
    ASSERT_EQ(v.size2(), num) ; 
    EXPECT_EQ(v[0], 0) ;
    EXPECT_EQ(v[num/2], num/2) ;
    EXPECT_EQ(v[num-1], num-1) ;
    
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv) ;
    return RUN_ALL_TESTS() ;
}