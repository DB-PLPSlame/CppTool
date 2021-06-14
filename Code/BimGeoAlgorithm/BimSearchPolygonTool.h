#pragma once

#include <list>
#include <map>
#include <set>
#include "gp_Pnt2d.hxx"
#include "BimGeoPolyline.h"

enum ESearchType
{
	eMaxPolygon	=	0,	//	���������
	eMinPolygon,		//	��С�������
};

/// @brief ������ȵĽǶ�
class CEqualAngleKey
{
public:
	CEqualAngleKey(const double& dAngle);
	~CEqualAngleKey();
public:
	bool operator < (const CEqualAngleKey& rhs) const;

	const double& GetAngle() const;
	operator double() const;
public:
	static double s_tol;
private:
	double	m_dAngle;
};

/// @class CBimSearchPolygonTool
/// @brief ��������ι���
/// @detail ���ڼнǱ仯���ƵĶ�����Զ������������㷨 https://wenku.baidu.com/view/508fc5a45fbfc77da269b1c1.html

class CBimSearchPolygonTool
{
public:
	CBimSearchPolygonTool();
	~CBimSearchPolygonTool();
public:
	/// @brief ִ������
	/// @param [in ] curves �߶�
	/// @param [in ] dTol ���㾫��
	/// @param [in ] IsBreak �Ƿ���
	/// @param [in ] IsVectorCurve �Ƿ���ʸ���߶�
	void DoIt(const std::list<SGeoCurveInfo>& curves, const double& dTol, 
		const ESearchType eType, const bool IsBreak = true, const bool IsVectorCurve = false, const double& dAngleTol = 0.01);

	/// @brief ��ȡ���������
	const std::list<CBimGeoPolyline>& GetMaxPolygon() const;

	/// @brief ��ȡ��С�������
	const std::list<CBimGeoPolyline>& GetMinPolygon() const;
private:
	/// @brief ���
	void Clear();

	/// @ͳ�Ƶ���ߵ���Ϣ
	void TotalPointWithCurveRel();

	/// @brief �����������
	void SearchPolygon();

	/// @brief �����������
	void SearchPolygonImp(const SGeoCurveInfo* pCurve);

	/// @brief ȥ����Ч�ķ������
	void RemoveInValidPolygon();

	/// @brief ��ȡ�߽��
	const gp_Pnt2d* GetBoundaryPoint();

	/// @brief ��ȡ�߽�
	const SGeoCurveInfo* GetBoundary();

	/// @brief �ҷ������
	void SearchPolygon(CBimGeoPolyline& polygon, const SGeoCurveInfo* pCurve, std::set<const SGeoCurveInfo*>& useCurve) const;

	/// @brief ��ȡ�Ƕ�
	double GetAngle(const SGeoCurveInfo* pCurve) const;

	/// @brief ��ȡ��һ���߶�
	const SGeoCurveInfo* GetNextCurve(double& dRetAngle, double& dCurAngle2, const SGeoCurveInfo*& pFirstCurve, const std::list<const SGeoCurveInfo*>& curves,
		const double& dCurAngle, const double& dRefAngle, const SGeoCurveInfo* pRefCurve) const;

	/// @brief �޸ı߽�
	void ModifyBoundary(const CBimGeoPolyline& polyline, const std::set<const SGeoCurveInfo*>& useCurve);

	/// @brief �Ƿ���Ч
	bool IsValidPolyline(const CBimGeoPolyline& polyline) const;

	/// @brief �Ƿ���
	bool IsReverse(const SGeoCurveInfo* pCurve, const SGeoCurveInfo* pRefCurve) const;

	/// @brief ȥ������
	void RemoveIndependentCurve();

	/// @brief �ϲ�����
	void MergeCollinear(std::list<CBimGeoPolyline>& polylines) const;
private:
	typedef std::map<int, std::list<SGeoCurveInfo*>> MAPBOUNDARY;
	typedef std::map<CEqualPointKey, std::list<SGeoCurveInfo*>> POINTWITHCURVEMAP;

	std::list<SGeoCurveInfo>		m_curves;				//	�߶εļ���
	std::list<CBimGeoPolyline>		m_maxPolygon;			//	���������
	std::list<CBimGeoPolyline>		m_minPolygon;			//	��С��ն�ȡ
	POINTWITHCURVEMAP				m_mapPointWithCurve;	//	����ߵ���Ϣ
	std::map<CEqualPointKey, int>	m_mapBoundaryPoint;		//	�߽��
	MAPBOUNDARY						m_mapBoundary;			//	�߽��
	double							m_dTol;					//	���㾫��
	double							m_dAngleTol;			//	����ǶȾ���
	ESearchType						m_eSearchType;			//	���ҷ����������
	bool							m_bIsVectorCurve;		//	�Ƿ���ʸ���߶�
};