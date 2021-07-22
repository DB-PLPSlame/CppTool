#pragma once

#ifdef BIMGEOALGOR_MODULE
#define EXPORTGEOALGOCLASS __declspec(dllexport)
#define EXPORTGEOALGOAPI __declspec(dllexport)
#else
#define EXPORTGEOALGOCLASS __declspec(dllimport)
#define EXPORTGEOALGOAPI __declspec(dllimport)
#endif

// check if c++11 is supported
#if __cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1900)
#define GEO_CXX11_IS_SUPPORTED
#endif

#include "gp_Pnt2d.hxx"
#include "gp_Pnt.hxx"

/// @brief ����ι�ϵ
enum EPointWidthPolygonRel
{
	eOnPolygon = 0,		//	�ڶ������
	eInPolygon,			//	�ڶ������
	eOutPolygon			//	�ڶ������
};

/// @brief ����ι�ϵ
enum EPolygonRel
{
	eIntersect = 0,			//	�ཻ
	eTagent,				//	����
	eOuter,					//	����
	eAInB,					//	A��B��
	eAInBWithTagent,		//	A��B�ڲ������ص�
	eBInA,					//	B��A��
	eBInAWithTagent,		//	A��B�ڲ������ص�
	eOverlap				//	�ص�
};

/// @brief ��������εĲ�������
enum EBooleanOperation
{
	ePolygonIntersect = 0,			//	����
	ePolygonUnion,					//	����
	ePolygonSubTract				//	�
};

/// @brief �߶���Ϣ
struct SGeoCurveInfo
{
	SGeoCurveInfo() : dBulge(0.) {}
	gp_Pnt2d		ptS;				//	���
	gp_Pnt2d		ptE;				//	�յ�
	double			dBulge;				//	͹��
};

/// @brief �߶���Ϣ
struct SGeoCurveInfo3D
{
	SGeoCurveInfo3D() : dBulge(0.) {}
	gp_Pnt			ptS;				//	���
	gp_Pnt			ptE;				//	�յ�
	double			dBulge;				//	͹��
};

/// @brief Բ����Ϣ
struct SGeoArcInfo
{
	gp_Pnt2d		ptCenter;				//	Բ��
	double			dRadius;				//	�뾶
	bool			bIsAntiClockwise;		//	��ʱ��
};

/// @brief ������
struct SGeoTriangle
{
	gp_Pnt2d		pt1;
	gp_Pnt2d		pt2;
	gp_Pnt2d		pt3;
};

/// @brief ��Χ(һά����)
struct SGeoRange
{
	SGeoRange()
	{

	}

	SGeoRange(const double& dmin, const double& dmax)
	{
		dMin = std::min(dmin, dmax);
		dMax = std::max(dmin, dmax);
	}
	double dMin;
	double dMax;
};

/// @brief ������ȵĵ�
class EXPORTGEOALGOCLASS CEqualPointKey
{
public:
	CEqualPointKey(const gp_Pnt2d& pt);
	~CEqualPointKey();
public:
	bool operator < (const CEqualPointKey& rhs) const;

	const gp_Pnt2d& GetPt() const;
public:
	static double s_tol;
private:
	gp_Pnt2d	m_pt;
};