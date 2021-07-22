#pragma once

#include "BimGeoAlgorithmDef.h"
#include "gp_Pnt.hxx"
#include "Bnd_Box.hxx"
#include "Bnd_Box2d.hxx"
#include <vector>
#include <list>

namespace BimGeoAlgorithmTool
{
	/// @brief �Ƿ����
	EXPORTGEOALGOAPI bool equal(const double& a, const double& b, const double& dTol = 0.0001);

	/// @brief �Ƿ�С��
	EXPORTGEOALGOAPI bool lessThan(const double& a, const double& b, const double& dTol = 0.0001);

	/// @brief �Ƿ�С�ڵ���
	EXPORTGEOALGOAPI bool lessEqualThan(const double& a, const double& b, const double& dTol = 0.0001);

	/// @brief �Ƿ����
	EXPORTGEOALGOAPI bool biggerThan(const double& a, const double& b, const double& dTol = 0.0001);

	/// @brief �Ƿ���ڵ���
	EXPORTGEOALGOAPI bool biggerEqualThan(const double& a, const double& b, const double& dTol = 0.0001);

	/// @brief ��������ȡ��
	EXPORTGEOALGOAPI double round(double r);

	/// @brief �Ƿ���Բ��
	EXPORTGEOALGOAPI bool IsArc(const double& dBulge, const double& dTol = 0.0001);

	/// @brief ��ȡ�߶ε����ĵ�
	EXPORTGEOALGOAPI gp_Pnt GetCurveMidPoint(const gp_Pnt& ptStart, const gp_Pnt& ptEnd, const double& dBulge);

	EXPORTGEOALGOAPI gp_Pnt2d GetCurveMidPoint(const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd, const double& dBulge);

	/// @brief ��ȡԲ��ĳһ�ε����ĵ�(�����뻡�߶�ͬ��)
	EXPORTGEOALGOAPI gp_Pnt2d GetArcMidPoint(const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd,
		const gp_Pnt2d& ptCenter, const double& dRadius, const bool IsAnticlockwise, const double& dTol = 0.0001);

	EXPORTGEOALGOAPI gp_Pnt2d GetArcMidPoint(const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd,
		const gp_Pnt2d& ptRefStart, const gp_Pnt2d& ptRefEnd, const double& dRefBulge, const double& dTol = 0.0001);

	EXPORTGEOALGOAPI gp_Pnt GetArcMidPoint(const gp_Pnt& ptStart, const gp_Pnt& ptEnd,
		const gp_Pnt& ptRefStart, const gp_Pnt& ptRefEnd, const double& dRefBulge, const double& dTol = 0.0001);

	/// @brief ��ȡԲ������Ϣ
	EXPORTGEOALGOAPI SGeoArcInfo GetArcInfo(const gp_Pnt& ptStart, const gp_Pnt& ptEnd, const double& dBulge);

	EXPORTGEOALGOAPI SGeoArcInfo GetArcInfo(const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd, const double& dBulge);

	/// @brief �жϵ��Ƿ�������
	EXPORTGEOALGOAPI bool IsOn(const gp_Pnt& pt, const gp_Pnt& ptStart, const gp_Pnt& ptEnd, const double& dBulge, const double& dTol = 0.0001);

	EXPORTGEOALGOAPI bool IsOn(const gp_Pnt2d& pt, const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd, const double& dBulge, const double& dTol = 0.0001);

	/// @brief ���㴹��
	/// @return ʧ����û�д���
	EXPORTGEOALGOAPI bool GetProjectPt(gp_Pnt& ptProject, const gp_Pnt& pt, const gp_Pnt& ptStart,
		const gp_Pnt& ptEnd, const double& dBulge, const double& dTol = 0.0001);

	EXPORTGEOALGOAPI bool GetProjectPt(gp_Pnt2d& ptProject, const gp_Pnt2d& pt, const gp_Pnt2d& ptStart,
		const gp_Pnt2d& ptEnd, const double& dBulge, const double& dTol = 0.0001);

	/// @brief ��ȡ�����
	/// @return ʧ�ܷ���ԭ��
	EXPORTGEOALGOAPI gp_Pnt GetClosePoint(const gp_Pnt& pt, const gp_Pnt& ptStart, const gp_Pnt& ptEnd, const double& dBulge, const double& dTol = 0.0001);

	EXPORTGEOALGOAPI gp_Pnt2d GetClosePoint(const gp_Pnt2d& pt, const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd, const double& dBulge, const double& dTol = 0.0001);

	/// @brief ��ȡ���ϵĲ���
	/// @return ʧ�ܷ���-1 
	EXPORTGEOALGOAPI double GetParamOnCurve(const gp_Pnt& pt, const gp_Pnt& ptStart, const gp_Pnt& ptEnd, const double& dBulge, const double& dTol = 0.0001);

	EXPORTGEOALGOAPI double GetParamOnCurve(const gp_Pnt2d& pt, const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd, const double& dBulge, const double& dTol = 0.0001);

	/// @brief ͨ��������ȡ���ϵĵ�
	/// @return ʧ�ܷ���ԭ�� 
	EXPORTGEOALGOAPI gp_Pnt GetPtOnCurveByParam(const double& param, const gp_Pnt& ptStart, const gp_Pnt& ptEnd, const double& dBulge, const double& dTol = 0.0001);

	EXPORTGEOALGOAPI gp_Pnt2d GetPtOnCurveByParam(const double& param, const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd, const double& dBulge, const double& dTol = 0.0001);

	/// @brief �󽻵�(��ά)
	EXPORTGEOALGOAPI void CalcIntersect(std::vector<gp_Pnt>& vecIntersectPt, const gp_Pnt& ptS, const gp_Pnt& ptE, const double& dBulge,
		const gp_Pnt& ptSRef, const gp_Pnt& ptERef, const double& dBulgeRef, const double& dTol = 0.0001);

	EXPORTGEOALGOAPI void CalcIntersect(std::vector<gp_Pnt2d>& vecIntersectPt, const gp_Pnt2d& ptS, const gp_Pnt2d& ptE, const double& dBulge,
		const gp_Pnt2d& ptSRef, const gp_Pnt2d& ptERef, const double& dBulgeRef, const double& dTol = 0.0001);

	/// @brief ��ֱ�ߵĽ���
	EXPORTGEOALGOAPI void CalcLineIntersect(std::vector<gp_Pnt2d>& vecIntersectPt, const gp_Pnt2d& ptS, const gp_Dir2d& dir,
		const gp_Pnt2d& ptRefS, const gp_Dir2d& dirRef, const double& dTol = 0.0001);

	/// @brief ������ӳ��ߵĽ���
	EXPORTGEOALGOAPI void CalcIntersectWithExtend(std::vector<gp_Pnt2d>& vecIntersectPt, const gp_Pnt2d& ptS, const gp_Pnt2d& ptE, const double& dBulge,
		const gp_Pnt2d& ptSRef, const gp_Pnt2d& ptERef, const double& dBulgeRef, const double& dTol = 0.0001);

	/// @brief �ж��Ƿ�ƽ��
	/// @param [in ] ptStart �߶�1�����
	/// @param [in ] ptEnd �߶�1���յ�
	/// @param [in ] dBulge �߶�1��͹��
	/// @param [in ] ptRefStart �߶�2�����
	/// @param [in ] ptRefEnd �߶�2���յ�
	/// @param [in ] dRefBulge �߶�2��͹��
	/// @param [in ] dTol ���� ԼΪ1��
	EXPORTGEOALGOAPI bool IsParallel(const gp_Pnt& ptStart, const gp_Pnt& ptEnd, const double& dBulge,
		const gp_Pnt& ptRefStart, const gp_Pnt& ptRefEnd, const double& dRefBulge, const double& dTol = 0.017);

	EXPORTGEOALGOAPI bool IsParallel(const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd, const double& dBulge,
		const gp_Pnt2d& ptRefStart, const gp_Pnt2d& ptRefEnd, const double& dRefBulge, const double& dTol = 0.017);

	/// @brief �Ƿ����ߵ����
	/// @param [in ] pt ��
	/// @param [in ] ptStart �߶����
	/// @param [in ] ptEnd �߶��յ�
	/// @param [in ] dBulge �߶�͹��
	/// @param [in ] dTol �߶����
	/// @return 0 ���߶���� 1 ���߶��ұ� 2 ���ӳ����� 3 ���߶���
	EXPORTGEOALGOAPI int IsLeftOfCurve(const gp_Pnt& pt, const gp_Pnt& ptStart, const gp_Pnt& ptEnd,
		const double& dBulge, const double& dTol = 0.0001);

	EXPORTGEOALGOAPI int IsLeftOfCurve(const gp_Pnt2d& pt, const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd,
		const double& dBulge, const double& dTol = 0.0001);

	/// @brief ���߶εķ�����
	EXPORTGEOALGOAPI gp_Vec GetNormal(const gp_Pnt& ptStart, const gp_Pnt& ptEnd, const double& dBulge);

	/// @brief ��ȡ�߶������
	EXPORTGEOALGOAPI void GetCurveBoxPoints(std::vector<gp_Pnt2d>& points, const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd, const double& dBulge);
	EXPORTGEOALGOAPI void GetCurveBoxPoints(std::vector<gp_Pnt>& points, const gp_Pnt& ptStart, const gp_Pnt& ptEnd, const double& dBulge);

	/// @brief ��ȡ�߶εİ�Χ��
	EXPORTGEOALGOAPI Bnd_Box GetCurveBndBox(const gp_Pnt& ptStart, const gp_Pnt& ptEnd, const double& dBulge);

	EXPORTGEOALGOAPI Bnd_Box2d GetCurveBndBox(const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd, const double& dBulge);

	/// @brief ��ȡ�߶γ���
	EXPORTGEOALGOAPI double GetCurveLength(const gp_Pnt& ptStart, const gp_Pnt& ptEnd, const double& dBulge);

	EXPORTGEOALGOAPI double GetCurveLength(const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd, const double& dBulge);

	/// @brief �Ƴ���
	EXPORTGEOALGOAPI void RemovePoint(std::list<SGeoCurveInfo>& curves, const double& dTol = 0.0001);

	/// @brief ���
	EXPORTGEOALGOAPI void BreakCurves(std::list<SGeoCurveInfo>& curves, const double& dTol = 0.0001);

	/// @brief ���ο��ߴ��
	EXPORTGEOALGOAPI void BreakCurves(std::list<SGeoCurveInfo>& curves, const std::list<SGeoCurveInfo>& refCurves, const double& dTol = 0.0001);

	/// @brief ���ݵ����߶�
	/// @param [in ] curve ���ϵ��߶�
	/// @param [in ] pts ����߶εĵ�(�����߶���)
	/// @param [in ] dTol ����
	/// @param [in ] bIsSort �Ƿ�����㼯��
	/// @return ��Ϻ�����߶� ��ʱ��û�д�Ϲ�ϵ
	EXPORTGEOALGOAPI std::vector<SGeoCurveInfo> BreakCurveByPoint(const SGeoCurveInfo& curve,
		const std::vector<gp_Pnt2d>& pts, const double& dTol = 0.0001,
		bool bIsSort = true);

	/// @brief ���㻡�ߵ�͹�ȣ�����յ��ǰ�Բ�ķ���
	/// @param [in ] ptS Բ�����
	/// @param [in ] ptE Բ���յ�
	/// @param [in ] ptCenter Բ��
	/// @param [in ] dRadius �뾶
	/// @param [in ] IsAnticlockwise �Ƿ�ʱ��ʱ��
	/// @param [in ] dTol ����
	/// @return ͹��
	EXPORTGEOALGOAPI double CalcArcBulge(const gp_Pnt2d& ptS, const gp_Pnt2d& ptE, const gp_Pnt2d& ptCenter,
		const double& dRadius, const bool IsAnticlockwise, const double& dTol = 0.0001);

	EXPORTGEOALGOAPI double CalcArcBulge(const gp_Pnt2d& ptS, const gp_Pnt2d& ptE, const gp_Pnt2d& ptRefStart,
		const gp_Pnt2d& ptRefEnd, const double& dRefBulge, const double& dTol = 0.0001);

	EXPORTGEOALGOAPI double CalcArcBulge(const gp_Pnt2d& ptS, const gp_Pnt2d& ptE, const gp_Pnt2d& ptMid);

	/// @brief �����߶��������ϵĵ�
	/// @param [in ] ptS ���
	/// @param [in ] ptE �յ�
	/// @param [in ] dBulge ͹��
	/// @param [in ] vecIntersectPt �㼯��
	/// @param [in ] bIsCalcClosePt �Ƿ���������
	EXPORTGEOALGOAPI std::vector<gp_Pnt2d> SortByCurve(const gp_Pnt2d& ptS, const gp_Pnt2d& ptE, const double& dBulge,
		const std::vector<gp_Pnt2d>& vecIntersectPt, bool bIsCalcClosePt = true);

	EXPORTGEOALGOAPI std::vector<gp_Pnt2d> SortByCurve(const SGeoCurveInfo& curve, const std::vector<gp_Pnt2d>& vecIntersectPt,
		bool bIsCalcClosePt = true);

	EXPORTGEOALGOAPI std::vector<gp_Pnt> SortByCurve(const gp_Pnt& ptS, const gp_Pnt& ptE,
		const std::vector<gp_Pnt>& vecIntersectPt);

	/// @brief ȥ���غ�
	/// @param [in ] curves �߶μ���
	/// @param [in ] dTol ���㾫��
	/// @param [in ] IsVectorCurve �Ƿ���ʸ���߶�
	EXPORTGEOALGOAPI void RemoveOverlap(std::list<SGeoCurveInfo>& curves, const double& dTol = 0.0001, const bool IsVectorCurve = false);

	/// @brief ���ο���ȥ���غ�(�����������غϺ͸���)(ȥ�ؿ��ܻ����С����)
	EXPORTGEOALGOAPI void RemoveOverlap(std::list<SGeoCurveInfo>& curves, const std::list<SGeoCurveInfo>& refCurves,
		const double& dTol = 0.0001, const bool IsVectorCurve = false);

	/// @brief ���߶μ���ص�����
	EXPORTGEOALGOAPI std::list<SGeoCurveInfo> CalcTwoCurveOverlap(const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd, const double& dBulge,
		const gp_Pnt2d& ptRefStart, const gp_Pnt2d& ptRefEnd, const double& dRefBulge, const double& dTol = 0.0001, const double& dAngleTol = 0.0001);

	EXPORTGEOALGOAPI std::list<SGeoCurveInfo> CalcTwoCurveOverlap(const SGeoCurveInfo& curve, const SGeoCurveInfo& curveRef,
		const double& dTol = 0.0001, const double& dAngleTol = 0.0001);

	/// @brief ���ӽ���ͬ�ĵ�
	/// @param [out] curves �߶�
	/// @param [in ] dTol ����
	/// @param [in ] bIsMerge �Ƿ�ϲ���ͬ�ĵ�(false ����һ����)
	/// @param [in ] bIsIsolated �Ƿ�ֻ������߶�
	EXPORTGEOALGOAPI void ConnectEqualPoint(std::list<SGeoCurveInfo>& curves, const double& dTol = 0.0001,
		const bool bIsMerge = false, const bool bIsIsolated = false);

	/// @brief ��������
	/// @param [out] vecVertex ������Ķ���
	/// @param [in ] ptStart ���
	/// @param [in ] ptEnd �յ�
	/// @param [in ] dBulge ͹��
	/// @param [in ] nNum ��������
	EXPORTGEOALGOAPI void ArcSample(std::vector<gp_Pnt2d>& vecVertex, const gp_Pnt2d& ptStart, const gp_Pnt2d& ptEnd,
		const double& dBulge, const int nNum);

	/// @brief ���� A �� B
	/// @param [in ] dTol ���С�� dTol ������
	EXPORTGEOALGOAPI std::list<SGeoRange> RangeUnion(const SGeoRange & rangeA, const SGeoRange& rangeB, const double& dTol = 0.001);
	EXPORTGEOALGOAPI std::list<SGeoRange> RangeUnion(const std::list<SGeoRange>& ranges, const double & dTol = 0.001);

	/// @brief ���� A �� B
	/// @param [in ] dTol ���С�� dTol ������
	EXPORTGEOALGOAPI bool RangeIntersect(SGeoRange & interRange, const SGeoRange & rangeA, const SGeoRange & rangeB, const double & dTol = 0.001);
	EXPORTGEOALGOAPI std::list<SGeoRange> RangeIntersect(const SGeoRange & rangeA, const std::list<SGeoRange>& rangeBs, const double & dTol = 0.001);
	EXPORTGEOALGOAPI std::list<SGeoRange> RangeIntersect(const std::list<SGeoRange>& rangeAs, const std::list<SGeoRange>& rangeBs, const double & dTol = 0.001);

	/// @brief � A - B
	/// @param [in ] dTol ���С�� dTol ������
	EXPORTGEOALGOAPI std::list<SGeoRange> RangeSubtract(const SGeoRange & rangeA, const SGeoRange& rangeB, const double& dTol = 0.001);
	EXPORTGEOALGOAPI std::list<SGeoRange> RangeSubtract(const SGeoRange & rangeA, const std::list<SGeoRange>& rangeBs, const double & dTol = 0.001);
	EXPORTGEOALGOAPI std::list<SGeoRange> RangeSubtract(const std::list<SGeoRange>& rangeAs, const std::list<SGeoRange>& rangeBs, const double & dTol = 0.001);

	/// @brief ȥ��
	/// @param [in ] dTol ����ߵĳ���
	EXPORTGEOALGOAPI std::list<SGeoRange> RangeFilter(const std::list<SGeoRange>& ranges, const double & dTol = 0.001);

	/// @brief OBB��Χ���Ƿ��ཻ
	/// @param [in ] ptCenter OBB�����ĵ�
	/// @param [in ] dWidth OBB�Ŀ��
	/// @param [in ] dHeight OBB�ĸ߶�
	/// @param [in ] dAngle OBB�ĽǶ�(��ʱ����X��Ļ���)
	/// @param [in ] ptRefCenter �ο�OBB�����ĵ�
	/// @param [in ] dRefWidth �ο�OBB�Ŀ��
	/// @param [in ] dRefHeight �ο�OBB�ĸ߶�
	/// @param [in ] dRefAngle �ο�OBB�ĽǶ�(��ʱ����X��Ļ���)
	/// @param [in ] dTol ���㾫��
	EXPORTGEOALGOAPI bool IsOutWithOBB(const gp_Pnt2d& ptCenter, const double& dWidth, const double& dHeight, const double& dAngle,
		const gp_Pnt2d& ptRefCenter, const double& dRefWidth, const double& dRefHeight,
		const double& dRefAngle, const double& dTol = 0.0001);

	/// @brief OBB��Χ��ת����AABB��Χ��
	/// @param [in ] ptCenter OBB�����ĵ�
	/// @param [in ] dWidth OBB�Ŀ��
	/// @param [in ] dHeight OBB�ĸ߶�
	/// @param [in ] dAngle OBB�ĽǶ�(��ʱ����X��Ļ���)
	EXPORTGEOALGOAPI Bnd_Box OBBToAABB(const gp_Pnt2d& ptCenter, const double& dWidth, const double& dHeight, const double& dAngle);
};

