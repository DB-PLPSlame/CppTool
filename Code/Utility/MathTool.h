#pragma once

#ifdef GEOALGOR_MODULE
#define EXPORTGEOALGOCLASS __declspec(dllexport)
#define EXPORTGEOALGOAPI __declspec(dllexport)
#else
#define EXPORTGEOALGOCLASS __declspec(dllimport)
#define EXPORTGEOALGOAPI __declspec(dllimport)
#endif

class EXPORTGEOALGOCLASS GeoAlgoTool
{
public:
	/// @brief �Ƿ����
	static bool Equal(const double& a, const double& b, const double& dTol = 0.0001);
	/// @brief �Ƿ�С�ڵ���
	static bool LessEqualThan(const double& a, const double& b, const double& dTol = 0.0001);
	/// @brief �Ƿ�С��
	static bool LessThan(const double& a, const double& b, const double& dTol = 0.0001);
	/// @brief �Ƿ���ڵ���
	static bool BiggerEqualThan(const double& a, const double& b, const double& dTol = 0.0001);
	/// @brief �Ƿ����
	static bool BiggerThan(const double& a, const double& b, const double& dTol = 0.0001);

	/// @brief ��������ȡ��/����С������
	static double Round(double decimals, int digits = 0);

	/// @brief ����ת�Ƕ�
	static double TransRadianToAngle(const double& dRadian);
	/// @brief �Ƕ�ת����
	static double TransAngleToRadian(const double& dAngle);

	/// @brief ����͹��(����)
	static double CalBulge(const double& dStartAngle, const double& dEndAngle);
	/// @brief ͹��ת�н�(����)
	static double TransBulgeToIncludeAngle(const double& dBulge);
};
