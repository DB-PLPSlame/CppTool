#include "ExtendedKalmanFilter_Test.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ExtendedKalmanFilter_Mock.h"

using namespace testing;
// https://rdc.hundsun.com/portal/article/781.html

// ASSERT_EQ����������������������������ǰ������
// EXPECT_EQ�����������������������ִ�е�ǰ������
/*
	ע����ʵ��ʹ��ʱ��Ӧ���������е����д��麯�����д�׮���������뱨��
		gmock ����C++��̬���ƽ��й�����ֻ���麯�����ܱ�mock

	���������˵����

	MOCK_METHOD#1(#2, #3(#4))
	#1��ʾ��Ҫmock�ķ������м�������
	#2����Ҫmock�ķ�������
	#3��ʾ��������ķ���ֵ����
	#4�������������Ĳ���

	ON_CALL(#1, #2(#3)).WillByDefault(Return(#4));
	#1��ʾmock����
	#2��ʾ�붨����Ǹ��������ơ�
	#3��ʾ���巽���Ĳ�����ֻ�е�����Ĳ���=#3��ֵʱ���Ż���Ч��Ҳ����_����ʾƥ���κβ������붼��Ч
	#4��ʾ����Ҫ�ķ���ֵ��

	EXPECT_CALL(#1, #2(#3))����������ͬON_CALL���������ж���Ĺ��ܣ�����:
	EXPECT_CALL(#1, #2(#3))

	// ����������4 �Σ�������ô�������4 ����ᱨ��
	.Times(4)

	// ��ʾ��һ�η���100���ڶ��ε��÷���150������ȫ������200���Դ����ơ�
	.WillOnce(Return(100)).WillOnce(Return(150)).WillRepeatedly(Return(200));

	// ʹ��helperAcc �����е�monitorAccount() �����滻����ǰ���Ǵ˺�����ԭ�����ķ���ֵ�Ͳ���һ��
	.WillRepeatedly(testing::Invoke(&helperAcc, &HelperThreadRCInvester::monitorAccount));

	// ����һ��
	EXPECT_CALL(#1, #2(#3)).Times(AtLeast(1));
 */

 // Code
bool test_Function(ExtendedKalmanFilter& ekf, int& add, int& NoChange)
{
	add = ekf.Add(1, 2);
	add += ekf.Add(1, 2);
	add += ekf.Add(1, 2);
	add += ekf.Add(1, 2);

	NoChange = ekf.NoChange(10);

	if (ekf.Pass())
	{
		return true;
	}
	return false;
}


TEST_F(ExtendedKalmanFilter_Test, mock2)
{
	ExtendedKalmanFilter_Mock ekf;

	//ON_CALL(ekf, NoChange(testing::_)).WillByDefault(testing::Return(100));
	EXPECT_CALL(ekf, NoChange(testing::_)).WillRepeatedly(testing::Return(100));

	EXPECT_CALL(ekf, Pass()).WillRepeatedly(testing::Invoke(&ekf, &ExtendedKalmanFilter_Mock::stub_Pass));

	EXPECT_CALL(ekf, Add(testing::_, testing::_))
		.Times(4)
		.WillOnce(testing::Return(1))
		.WillOnce(testing::Return(10))
		.WillRepeatedly(testing::Return(100));

	int add, noChange;
	EXPECT_EQ(true, test_Function(ekf, add, noChange));
	EXPECT_EQ(211, add);
	EXPECT_EQ(100, noChange);
}
