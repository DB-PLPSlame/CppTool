#include "ExtendedKalmanFilter_Test.h"
#include "ExtendedKalmanFilter_Mock.h"
#include "Stub_Test.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "gtest/stubext.h"

using namespace testing;
using namespace stub_ext;

// ASSERT_EQ����������������������������ǰ������
// EXPECT_EQ�����������������������ִ�е�ǰ������


int func()
{
	return 1;
}


TEST_F(ExtendedKalmanFilter_Test, stub1)
{
	ASSERT_TRUE(false);
	//ASSERT_EQ(4, 4);
	//EXPECT_TRUE(true);
	//EXPECT_EQ(4, 4);
	std::cout << "ִ�н���......" << std::endl;
}

// ʹ��VADDR()��ݵػ�ȡ�麯����ַ�����ڹ���ʵ�ֲ��õ�gcc/g++��ת��������ĿǰӦ��ֻ֧��gcc/g++������
TEST_F(ExtendedKalmanFilter_Test, stub2)
{
	StubExt st;
	st.set_lamda(&func, []() { return 100; });
	//st.set_lamda(VADDR(StubTest, Add), [](StubTest* filter, int a) { return 100; });
	st.set_lamda(ADDR(StubTest, NoChange), [](StubTest* filter, int a) { return 100; });
	st.set_lamda(ADDR(StubTest, Pass), [](StubTest* filter) { return true; });

	StubTest sb;
	EXPECT_EQ(100, func());
	EXPECT_EQ(true, sb.Pass());
	EXPECT_EQ(100, sb.NoChange(1));
	EXPECT_EQ(3, sb.Add(1, 2));
}
