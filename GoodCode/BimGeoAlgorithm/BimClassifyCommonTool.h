#pragma once
#include "BimData/IBimDbEntity.h"
#include "BimClassifyEntityDef.h"
#include "BimGeoAlgorithm/BimGeoAlgorithmDef.h"
#include "Bnd_Box.hxx"
#include "BimData/BimDataDef.h"
#include "Bnd_Box2d.hxx"
#include <list>

namespace BimClassifyCommonTool
{
	/// @brief gp_Pnt2dת��gp_Pnt
	gp_Pnt TransPt(const gp_Pnt2d& pt);
	/// @brief SBimPointת��gp_Pnt
	gp_Pnt TransPt(const SBimPoint& pt);
	/// @brief SBimPointת��gp_Pnt2d
	gp_Pnt2d TransPt2d(const SBimPoint& pt);
	/// @brief gp_Pntת��SBimPoint
	SBimPoint TransBimPt(const gp_Pnt& pt);
	/// @brief gp_Pntת��SBimPoint
	SBimPoint TransBimPt(const gp_Pnt2d& pt);
	/// @brief SBimBoxת��Bnd_Box
	Bnd_Box TransBndBox(const SBimBox& box);
	/// @brief SBimBoxת��Bnd_Box2d
	Bnd_Box2d TransBndBox2d(const SBimBox& box);
	/// @brief Bnd_Boxת��SBimBox
	SBimBox TransBimBox(const Bnd_Box& box);
	/// @brief Bnd_Box2dת��SBimBox
	SBimBox TransBimBox(const Bnd_Box2d& box);
	/// @brief �ж�Box�Ƿ��ཻ
	bool IsBoxIntersect(const SBimBox& box1, const SBimBox& box2, const double& dTol = 1e-3);
	/// @brief ��ȡbox���е�
	void GetBoxCenter(const SBimBox& box, SBimPoint& ptCenter);
	/// @brief ���Ƿ���box��
	bool IsPtInBox(const SBimPoint& pt, const SBimBox& box);
	/// @brief SGeoCurveInfoת��SBimCurve
	bool TransBimCurve(const SGeoCurveInfo& geoCurve, SBimCurve& curve);	
	/// @brief ת��ArchCurve����
	bool TransArchCurveToCurve(const SArchCurveData& archCurve, SBimCurve& curve);
	/// @brief ת��ArchCurve����
	bool TransArchCurveToGeoCurve(const SArchCurveData& curveData,
		SGeoCurveInfo& curveInfo);
	bool TransArchCurveToGeoCurve(const SArchCurveData& curveData,
		SGeoCurveInfo3D& curveInfo);
	/// @brief ��ȡ�ı���������
	bool GetTextEntData(const IBimDbEntity* pEnt, SArchTextData& data);
	/// @brief ��ȡ���Զ�������
	bool GetCurveEntData(const IBimDbEntity* pEnt,
		std::list<SArchCurveData>& sideData);
};

