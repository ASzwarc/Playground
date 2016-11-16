#include "LinkedList.hpp"
#include "gtest/gtest.h"

class LinkedListShould : public ::testing::Test
{
protected:
    virtual void SetUp()
    {}
    
    LinkedList<int> sut_;
};


TEST_F(LinkedListShould, BeIntiallyEmpty)
{
    ASSERT_TRUE(sut_.size() == 0);
}

TEST_F(LinkedListShould, insertAndDeleteNodeAtTheBeginning)
{
    int dataToAdd = 1;
    sut_.insertFirst(dataToAdd);
    ASSERT_EQ(sut_.size(), 1);
    int deletedData = sut_.deleteFirst();
    ASSERT_EQ(dataToAdd, deletedData);
    ASSERT_TRUE(sut_.size() == 0);
}

TEST_F(LinkedListShould, insertAndDeleteNodeAtTheEnd)
{
    int dataToAdd = 2;
    sut_.insertLast(dataToAdd);
    ASSERT_EQ(sut_.size(), 1);
    int deletedData = sut_.deleteLast();
    ASSERT_EQ(dataToAdd, deletedData);
    ASSERT_TRUE(sut_.size() == 0);
}




