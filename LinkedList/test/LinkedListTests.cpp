#include "LinkedList.hpp"
#include "gtest/gtest.h"

class LinkedListShould : public ::testing::Test
{
protected:
    virtual void SetUp()
    {}
    
    LinkedList<int> sut_;
    int someData_ {1};
    int someOtherData_ {2};
};


TEST_F(LinkedListShould, BeIntiallyEmpty)
{
    ASSERT_TRUE(sut_.size() == 0);
}

TEST_F(LinkedListShould, insertAndDeleteNodeAtTheBeginning)
{
    sut_.insertFirst(someData_);
    ASSERT_EQ(sut_.size(), 1);
    int deletedData = sut_.deleteFirst();
    ASSERT_EQ(someData_, deletedData);
    ASSERT_TRUE(sut_.size() == 0);
}

TEST_F(LinkedListShould, insertAndDeleteNodeAtTheEnd)
{
    sut_.insertLast(someData_);
    ASSERT_EQ(sut_.size(), 1);
    int deletedData = sut_.deleteLast();
    ASSERT_EQ(someData_, deletedData);
    ASSERT_TRUE(sut_.size() == 0);
}

TEST_F(LinkedListShould, throwExceptionIfDeleteOnEmptyList)
{
    EXPECT_THROW(sut_.deleteFirst(), std::range_error);
    EXPECT_THROW(sut_.deleteLast(), std::range_error);
}

TEST_F(LinkedListShould, returnFalseIfFindOnEmptyList)
{
    ASSERT_FALSE(sut_.searchByKey(someData_));
}

TEST_F(LinkedListShould, returnTrueIfNodeFoundInList)
{
    sut_.insertLast(someData_);
    ASSERT_TRUE(sut_.searchByKey(someData_));
}

TEST_F(LinkedListShould, returnFalseIfNodeNotFoundInNonEmptyList)
{
    int dataToFound {10};
    sut_.insertLast(someData_);
    sut_.insertLast(someOtherData_);
    ASSERT_FALSE(sut_.searchByKey(dataToFound));
}

TEST_F(LinkedListShould, returnFalseIfDeleteOnEmptyList)
{
    ASSERT_FALSE(sut_.deleteByKey(someData_));
    ASSERT_TRUE(sut_.size() == 0);
}

TEST_F(LinkedListShould, returnTrueIfDeletedRequestedNode)
{
    sut_.insertLast(someData_);
    ASSERT_TRUE(sut_.deleteByKey(someData_));
    ASSERT_TRUE(sut_.size() == 0);
}

TEST_F(LinkedListShould, returnFalseIfRequestedNodeIsNotInList)
{
    int dataNotInList {10};
    sut_.insertLast(someData_);
    sut_.insertFirst(someOtherData_);
    ASSERT_FALSE(sut_.deleteByKey(dataNotInList));
    ASSERT_EQ(sut_.size(), 2);
}


