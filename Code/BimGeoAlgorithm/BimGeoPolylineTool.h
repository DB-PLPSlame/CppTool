#pragma once

#include "BimGeoAlgorithmDef.h"
#include "gp_Pnt.hxx"
#include "Bnd_Box.hxx"
#include "Bnd_Box2d.hxx"
#include <vector>
#include <list>
#include <set>

class CBimGeoPolyline;
struct SBimGeoPolygonWithHole;
class CBimGeoOBB2d;

namespace BimGeoPolylineTool
{
	/// @brief �Ⱦ�ƫ�ƶ����
	/// @param [in ] polylines ƫ�ƺ�Ķ����
	/// @param [in ] orgPolyline ԭʼ�����(��ʱ��)
	/// @param [in ] dOffset ƫ�ƾ��� > 0 ��ƫ < 0 ��ƫ
	/// @return true �� false
	EXPORTGEOALGOAPI bool OffsetPolyline(std::list<CBimGeoPolyline>& polylines, const CBimGeoPolyline& orgPolyline,
		const double& dOffset, const double& dTol = 0.0001);

	/// @brief �ǵȾ�ƫ�ƶ����
	/// @param [in ] polylines ƫ�ƺ�Ķ����
	/// @param [in ] orgPolyline ԭʼ�����(��ʱ��)
	/// @param [in ] dOffset ƫ�ƾ��� > 0 ��ƫ < 0 ��ƫ
	/// @return true �� false
	EXPORTGEOALGOAPI bool OffsetPolyline(std::list<CBimGeoPolyline>& polylines, const CBimGeoPolyline& orgPolyline,
		const std::vector<double>& vecOffset, const double& dTol = 0.0001);

	/// @brief ����������εĹ�ϵ
	EXPORTGEOALGOAPI EPointWidthPolygonRel CalcPointWithPolygonRelation(const gp_Pnt2d& pt, const CBimGeoPolyline& polyline, const double& dTol = 0.0001);
	EXPORTGEOALGOAPI EPointWidthPolygonRel CalcPointWithPolygonRelation(const gp_Pnt& pt, const CBimGeoPolyline& polyline, const double& dTol = 0.0001);

	/// @brief ������������εĹ�ϵ
	EXPORTGEOALGOAPI EPolygonRel CalcTwoPolygonRelation(const CBimGeoPolyline& polylineA, const CBimGeoPolyline& polylineB, const double& dTol = 0.0001);

	/// @brief ��������ߵ��������
	/// @param [out] indexSet ��������ڱߵ��±� ����ʱ������
	/// @param [in ] pt ��
	/// @param [in ] polyline �����
	/// @param [in ] dTol ����
	/// @return �����
	EXPORTGEOALGOAPI gp_Pnt2d GetClosePt(std::set<int>& indexSet, const gp_Pnt2d& pt, const CBimGeoPolyline& polyline, const double& dTol = 0.0001);

	/// @brief ��������ߵ��������
	/// @param [out] indexSet ��������ڱߵ��±� ����ʱ������
	/// @param [in ] pt ��
	/// @param [in ] polyline �����
	/// @param [in ] filterIndexSet ���˵ı�
	/// @param [in ] dTol ����
	/// @return �����
	EXPORTGEOALGOAPI gp_Pnt2d GetClosePtExt(std::set<int>& indexSet, const gp_Pnt2d& pt,
		const CBimGeoPolyline& polyline, const std::set<int>& filterIndexSet, const double& dTol = 0.0001);

	/// @brief ��ȡ����ε�����(�����Ƿ�����)
	/// @return ����
	EXPORTGEOALGOAPI gp_Pnt2d GetCenterPt(const CBimGeoPolyline& polyline);

	/// @brief ���������ε����
	EXPORTGEOALGOAPI double GetArea(const gp_Pnt2d& pt1, const gp_Pnt2d& pt2, const gp_Pnt2d& pt3);
	EXPORTGEOALGOAPI double GetArea(const gp_Pnt& pt1, const gp_Pnt& pt2, const gp_Pnt& pt3);
	
	/// @brief ���������ε����
	/// @return ������
	EXPORTGEOALGOAPI double GetArea(const gp_Pnt& pt1, const gp_Pnt& pt2, const gp_Pnt& pt3,
		const gp_Vec& normal);

	/// @brief ��ȡƽ�б�
	EXPORTGEOALGOAPI std::list<std::set<int>> GetParallelSide(const CBimGeoPolyline& polyline);

	/// @brief �Ƿ��ཻ
	EXPORTGEOALGOAPI bool IsHasIntersect(const CBimGeoPolyline& polyline, const gp_Pnt2d& ptS, const gp_Pnt2d& ptE, const double& dBulge);

	/// @brief ��ȡ����
	EXPORTGEOALGOAPI void GetIntersect(std::vector<gp_Pnt2d>& intersectPts, const CBimGeoPolyline& polyline,
		const gp_Pnt2d& ptS, const gp_Pnt2d& ptE, const double& dBulge, const double& dTol = 0.0001);

	/// @briref �������������
	/// @param [in ] curves �߶�
	/// @param [in ] dTol ����
	/// @param [in ] IsVectorCurve �Ƿ��������߶�
	/// @param [in ] dAngleTol �ǶȾ���
	/// @return �������
	EXPORTGEOALGOAPI std::list<CBimGeoPolyline> SearchMaxPolygonWithBreakCurve(const std::list<SGeoCurveInfo>& curves, const double& dTol = 0.0001, 
		const bool IsVectorCurve = false, const double& dAngleTol = 0.01);

	EXPORTGEOALGOAPI std::list<CBimGeoPolyline> SearchMaxPolygonWithNoBreakCurve(const std::list<SGeoCurveInfo>& curves, const double& dTol = 0.0001, 
		const bool IsVectorCurve = false, const double& dAngleTol = 0.01);

	/// @brief ������С�������
	EXPORTGEOALGOAPI std::list<CBimGeoPolyline> SearchMinPolygonWithBreakCurve(const std::list<SGeoCurveInfo>& curves, const double& dTol = 0.0001, 
		const bool IsVectorCurve = false, const double& dAngleTol = 0.01);

	EXPORTGEOALGOAPI std::list<CBimGeoPolyline> SearchMinPolygonWithNoBreakCurve(const std::list<SGeoCurveInfo>& curves, const double& dTol = 0.0001, 
		const bool IsVectorCurve = false, const double& dAngleTol = 0.01);

	/// @brief �ϲ�����εĹ��߱�
	EXPORTGEOALGOAPI void MergePolylineSide(CBimGeoPolyline& polyline, const double& dTol = 0.0001);

	/// @brief ȥ����
	EXPORTGEOALGOAPI void RemovePoint(CBimGeoPolyline& polyline, const double& dTol = 0.0001);

	/// @brief ������Ƿ��Խ�
	EXPORTGEOALGOAPI bool IsSelfIntersect(const CBimGeoPolyline& polyline, const double& dTol = 0.0001);

	/// @brief ��������յ��ȡ�����ĳһ��
	EXPORTGEOALGOAPI void InterceptPolyline(std::list<CBimGeoPolyline>& retPolies, const CBimGeoPolyline& polyline,
		const gp_Pnt2d& ptS, const gp_Pnt2d& ptE, const double& dTol = 0.0001);

	/// @brief ����εĲ�������
	EXPORTGEOALGOAPI void TwoPolygonBooleanOperation(std::list<SBimGeoPolygonWithHole>& retPolygons, const CBimGeoPolyline* pPolylineA,
		const CBimGeoPolyline* pPolylineB, const EBooleanOperation eCalcType, const double& dTol = 0.0001);

	/// @brief �����������
	EXPORTGEOALGOAPI double GetPolygonArea(const CBimGeoPolyline& polygon);

#ifdef GEO_CXX11_IS_SUPPORTED // C++ 11 ��׼
	/// @brief �ʷ�������(��֧�ֻ���)
	EXPORTGEOALGOAPI void Triangle(std::list<SGeoTriangle>& triangles, const CBimGeoPolyline& polygon, const std::list<CBimGeoPolyline>& holes);
#endif

	/// @brief ��ȡ����������ڲ���(��������û���ص���)
	EXPORTGEOALGOAPI gp_Pnt2d GetInnerPoint(const CBimGeoPolyline& polygon, const std::vector<const CBimGeoPolyline*>& holes);

	/// @brief ��ȡ����������ڲ���(�������ο������ص���)
	/// @param [in ] polygon �����
	/// @param [in ] holes ������
	/// @param [in ] bIsXAxisPrior �Ƿ�X������
	EXPORTGEOALGOAPI gp_Pnt2d GetInnerPointExt(const CBimGeoPolyline& polygon, 
		const std::vector<const CBimGeoPolyline*>& holes, const bool bIsXAxisPrior = true);

	/// @brief ��������͹��
	/// @param [out] polygon ͹��������
	/// @param [in ] inputCurves ��
	/// @param [in ] dTol ����
	EXPORTGEOALGOAPI bool CalculateCurvesConvexHull(CBimGeoPolyline& polygon,
		const std::list<SGeoCurveInfo>& inputCurves, const double& dTol = 0.0001);

	/// @brief ����պ϶���ε���С���ΰ�Χ
	/// @param [out] minAreaObb ��С�������
	/// @param [in ] polygon �����
	/// @param [in ] dTol ����
	/// return true �ɹ�; false ʧ��
	EXPORTGEOALGOAPI bool CalculatePolygonMinAreaObb(CBimGeoOBB2d& minAreaObb, const CBimGeoPolyline& polygon, const double& dTol = 0.0001);
};

