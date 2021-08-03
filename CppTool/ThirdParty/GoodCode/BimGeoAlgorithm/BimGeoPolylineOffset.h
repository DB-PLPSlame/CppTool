#pragma once

#include "BimGeoPolyline.h"
#include <list>
#include <set>
#include <map>

/// @class CBimGeoPolylineOffset
/// @brief �����ƫ���㷨(�����������ʱ��)
/// @detail ����ε�ƫ������㷨 https://www.jianshu.com/p/8c7e7c1afcb6

class CBimGeoPolylineOffset
{
public:
	CBimGeoPolylineOffset();
	~CBimGeoPolylineOffset();
public:
	/// @brief �ǵȾ�ƫ��
	/// @param [in ] polyline ƫ��·��
	/// @param [in ] vecOffset ƫ�ƾ��루��·�����߶θ���һ�£�
	/// @return �ɹ���ʧ��
	bool DoIt(const CBimGeoPolyline& polyline, const std::vector<double>& vecOffset, const double& dTol);

	/// @brief �Ⱦ�ƫ��
	/// @param [in ] polyline ƫ��·��
	/// @param [in ] dOffset ƫ�ƾ���
	/// @return �ɹ���ʧ��
	bool DoIt(const CBimGeoPolyline& polyline, const double& dOffset, const double& dTol);

	/// @brief ��ȡƫ�ƺ�Ķ����
	const std::list<CBimGeoPolyline>& GetOffsetPolylines() const;
private:
	/// @brief �������
	void Clear();

	/// @brief ƫ��
	bool CalcOffsetImp(const CBimGeoPolyline& polyline, const std::vector<double>& vecOffset);

	/// @brief ��ȡ��Ч�Ķ���κ�ƫ�ƾ���
	CBimGeoPolyline GetValidPolyline(std::vector<double>& vecOffset, const CBimGeoPolyline& polyline) const;

	/// @brief ���˻�
	void BoundaryDegenerate();

	/// @brief ȥ���˻���
	void RemoveDegenerateBoundary();

	/// @brief ���㶥���ƫ������
	void CalcVertexOffsetVec(const int nPreIndex, const int nCurIndex, const int nNextIndex);

	/// @brief ���ɶ����
	void GeneratePolylines();

	/// @brief ������Ч�������
	void CalcValidPolylines(const CBimGeoPolyline& polyline, const std::set<int>& inValidSide);

	/// @brief ƫ��Բ���߶�
	void OffsetArc(CBimGeoPolyline& retPolyline, std::set<int>& inValidSide, const int nPreIndex, const int nIndex) const;

	/// @brief ƫ���߶�
	SGeoCurveInfo OffsetCurve(const gp_Pnt2d& ptS, const gp_Pnt2d& ptE, const double& dBulge,
		const double& dOffset, bool& bIsValid) const;
private:
	CBimGeoPolyline						m_orgPolyline;			//	ԭʼ�����
	std::vector<double>					m_vecOffset;			//	ƫ�ƾ���
	std::list<CBimGeoPolyline>			m_retPolylines;			//	���㷵�ص�����
	double								m_dTol;					//	���㾫��
	std::vector<gp_Vec2d>				m_vecOffsetVertex;		//	����ƫ�Ƶ�����
	std::set<int>						m_arcPointSet;			//	Բ���˵�ļ���
	std::set<int>						m_inValidVertex;		//	�����˻�
};

