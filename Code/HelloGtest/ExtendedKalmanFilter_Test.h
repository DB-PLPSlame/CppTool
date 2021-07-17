#pragma once
#include "gtest/gtest.h"
#include <iostream>
#include "ExtendedKalmanFilter.h"


class ExtendedKalmanFilter_Test: public testing::Test
{
protected:
	// ���������������ǰ��ִ��
	static void SetUpTestCase()
	{
		std::cout << "SetUpTestCase" << std::endl;
	}
	static void TearDownTestCase()
	{
		std::cout << "TearDownTestCase" << std::endl;
	}

	// ÿ��������������ǰ��ִ��
	virtual void SetUp()
	{
		std::cout << "SetUp" << std::endl;
	}
	virtual void TearDown()
	{
		std::cout << "TearDown" << std::endl;
	}

private:

};

bool test_Function(ExtendedKalmanFilter& ekf, int& add, int& NoChange);
