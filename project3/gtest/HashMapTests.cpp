// HashMapTests.cpp
//
// ICS 45C Fall 2014
// Project #3: Maps and Legends
//
// Write unit tests for your HashMap class here.  I've provided one test already,
// though I've commented it out, because it won't compile until you've implemented
// three things: the HashMap constructor, the HashMap destructor, and HashMap's
// size() member function.

#include <gtest/gtest.h>
#include "HashMap.hpp"


TEST(TestHashMap, sizeOfNewlyCreatedHashMapIsZero)
{
    HashMap empty;
    ASSERT_EQ(0, empty.size());
}

TEST(TestHashMapCopyConstructor, copyHashMapHasSameData)
{
    HashMap first;
    first.add("Ford", "Tang");
    HashMap second = first;
    ASSERT_EQ(first.size(), second.size());
    ASSERT_EQ(first.contains("Ford"), second.contains("Ford"));
    ASSERT_EQ(first.value("Ford"), second.value("Ford"));
}

TEST(TestHashMapAssignmentOperator, assignmentShouldHaveSameData)
{   
    HashMap first;
    first.add("Ford", "Tang");
    HashMap second;
    second.add("Diana", "Chang");
    second.add("Bronx", "Alora");
    second = first;
    ASSERT_EQ(first.size(), second.size());
    ASSERT_EQ(first.contains("Ford"), second.contains("Ford"));
    ASSERT_EQ(first.value("Ford"), second.value("Ford"));
}

TEST(TestHashMapAdd, added10itemsShouldHave10items)
{
    HashMap Test;
    Test.add("Ford", "Tang");
    Test.add("Diana", "Chang");
    Test.add("Bronx", "Cat");
    Test.add("Alora", "Cat");
    Test.add("Bailey", "Cat");
    Test.add("Araceli", "Garcia");
    Test.add("Ray", "Chou");
    Test.add("Sam", "Guy");
    Test.add("Hua", "Man");
    Test.add("Michael", "Dude");
    Test.add("Ford", "Tang");
    ASSERT_EQ(10, Test.size());
}

TEST(TestHashMapRemove, addedItemThenRemoveItemHashMapShouldHave0items)
{
    HashMap Test;
    Test.add("Ford", "Tang");
    Test.remove("Ford");
    ASSERT_EQ(0, Test.size());
}

TEST(TestHashMapContains, addItemCheckContainsReturnTrue)
{
    HashMap Test;
    Test.add("Ford", "Tang");
    ASSERT_EQ(true, Test.contains("Ford"));
}

TEST(TestHashMapValue, valueShouldReturnTang)
{
    HashMap Test;
    Test.add("Ford", "Tang");
    ASSERT_EQ("Tang", Test.value("Ford"));
}

TEST(TestHashMapBucketCount, emptyShouldHaveSize0)
{
    HashMap Empty;
    ASSERT_EQ(0, Empty.bucketCount());
}

TEST(TestHashMapLoadFactor, 5Items10BucketsHalfLoad)
{
    HashMap Test;
    Test.add("Ford", "Tang");
    Test.add("Diana", "Chang");
    Test.add("Bronx", "Cat");
    Test.add("Alora", "Cat");
    Test.add("Bailey", "Cat");
    ASSERT_EQ(0.5, Test.loadFactor());
}

TEST(TestHashMapMaxBucketSize, emptyShouldHaveMax0)
{
    HashMap Empty;
    ASSERT_EQ(0, Empty.maxBucketSize());
}

TEST(TestHashMapClearBucket, clearedHashMapSizeis0)
{
    HashMap Test;
    Test.add("Ford", "Tang");
    Test.clearBucket();
    ASSERT_EQ(0, Test.size());
}
