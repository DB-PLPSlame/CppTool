#include "TestEKF.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MyEKF.h"

// ASSERT_EQ����������������������������ǰ�ĺ���


TEST_F(TestEKF, plus4)
{
	EXPECT_EQ(8, 8);
	EXPECT_TRUE(true);
	std::cout << "ִ�н���......" << std::endl;
}

TEST_F(TestEKF, plus5)
{
	ASSERT_EQ(8, 18);
	EXPECT_TRUE(0);
	std::cout << "ִ�н���......" << std::endl;
}

TEST_F(TestEKF, mius5)
{
	EXPECT_EQ(8, 1);
	EXPECT_TRUE(0);
}

TEST_F(TestEKF, mius6)
{
	MyEKF turtle;
	//EXPECT_CALL(turtle, Add()).Times(5).WillOnce(Return(100))
		//.WillOnce(Return(150));
	ASSERT_EQ(8, 8);
	EXPECT_TRUE(true);
}
