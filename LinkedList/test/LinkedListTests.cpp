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

TEST_F(LinkedListShould, throwExceptionIfDeleteOnEmptyList)
{
    EXPECT_THROW(sut_.deleteFirst(), std::range_error);
    EXPECT_THROW(sut_.deleteLast(), std::range_error);
}

TEST_F(LinkedListShould, findNodeByKey)
{
    int someData = 2;
    int someOtherData = 5;
    ASSERT_FALSE(sut_.searchByKey(someData));
    sut_.insertLast(someData);
    ASSERT_TRUE(sut_.searchByKey(someData));
    sut_.insertFirst(someOtherData);
    ASSERT_TRUE(sut_.searchByKey(someData));
}

TEST_F(LinkedListShould, deleteNodeByKey)
{
    int someData = 2;
    int someOtherData = 5;
    int dataNotInList = 0;
    ASSERT_FALSE(sut_.deleteByKey(someData));
    ASSERT_TRUE(sut_.size() == 0);
    sut_.insertLast(someData);
    ASSERT_TRUE(sut_.deleteByKey(someData));
    ASSERT_TRUE(sut_.size() == 0);
    sut_.insertLast(someData);
    sut_.insertFirst(someOtherData);
    ASSERT_TRUE(sut_.deleteByKey(someData));
    ASSERT_TRUE(sut_.size() == 1);
    ASSERT_FALSE(sut_.deleteByKey(dataNotInList));
    ASSERT_TRUE(sut_.size() == 1);
}




