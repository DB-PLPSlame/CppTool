#pragma once

#include "BimGeoPolyline.h"
#include <list>

/// @class CBimGeoTwoPolygonBoolOper
/// @brief ��������β�������
/// @detail https://www.geeksforgeeks.org/weiler-atherton-polygon-clipping-algorithm/ weiler-atherton �㷨

class CBimGeoTwoPolygonBoolOper
{
public:
	CBimGeoTwoPolygonBoolOper();
	~CBimGeoTwoPolygonBoolOper();
public:
	/// @brief ִ��A��������B
	void DoIt(const CBimGeoPolyline* pPolygonA, const CBimGeoPolyline* pPolygonB,
		const EBooleanOperation eBooleanOper, const double& dTol);

	/// @brief ��ȡ������
	const std::list<SBimGeoPolygonWithHole>& GetPolygons() const;
private:
	/// @brief �������
	void Clear();

	/// @brief ����
	void CalcImp();

	/// @brief �ཻ�Ķ���εĲ�������
	void CalcWithIntersectPolygon();

	/// @brief ������������εĲ�������
	void CalcTwoPolygonBooleanOperData(std::list<SGeoCurveInfo>& curves, 
		const CBimGeoPolyline* pPolygonA, const CBimGeoPolyline* pPolygonB,
		const EBooleanOperation eCalcType) const;

	/// @brief �����ת����curve
	void PolylineToCurves(std::list<SGeoCurveInfo>& curves, const std::list<CBimGeoPolyline>& polies,
		const std::list<gp_Pnt2d>& breakPoints) const;

	/// @brief ����߶�
	void BreakCurves(std::list<SGeoCurveInfo>& curves, const SGeoCurveInfo& curve, const std::list<gp_Pnt2d>& breakPoints) const;

	/// @brief �Ƴ���Ч�Ķ����
	void RemoveOverlapPolygon(const CBimGeoPolyline* pRefPolygon);
private:
	std::list<SBimGeoPolygonWithHole>		m_retPolygon;		//	������
	const CBimGeoPolyline*					m_pPolygonA;		//	�����A
	const CBimGeoPolyline*					m_pPolygonB;		//	�����B
	double									m_dTol;				//	���㾫��
	EBooleanOperation						m_eBooleanOper;		//	������������
};

