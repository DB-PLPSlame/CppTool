#pragma once

#include "BimGeoAlgorithmDef.h"
#include <vector>
#include <list>
#include "gp_Pnt2d.hxx"
#include "Bnd_Box2d.hxx"
#include "gp_Trsf2d.hxx"

class EXPORTGEOALGOCLASS CBimGeoPolyline
{
public:
	CBimGeoPolyline();
	CBimGeoPolyline(const std::vector<gp_Pnt2d>& vecVertex, const std::vector<double>& vecBulge, const bool bIsClose);
	~CBimGeoPolyline();
public:
	/// @brief ��ȡ���
	gp_Pnt2d GetStartPoint() const;

	/// @brief ��ȡ�յ�
	gp_Pnt2d GetEndPoint() const;

	/// @brief ��ȡ����
	const std::vector<gp_Pnt2d>& GetVertexes() const;

	/// @brief ��ȡ͹��
	const std::vector<double>& GetBulges() const;

	/// @brief ���ö���
	void SetVertexes(const std::vector<gp_Pnt2d>& vecVertex);
	void SetVertex(const int nIndex, const gp_Pnt2d& pt);

	/// @brief ����͹��
	void SetBulges(const std::vector<double>& vecBulge);
	void SetBugle(const int nIndex, const double& dBulge);

	/// @brief ��Ӷ���
	void AddVertex(const gp_Pnt2d& pt, const double& dBulge);

	/// @brief ����ָ����������͹��
	void SetVertex(const int nIndex, const gp_Pnt2d& pt, const double& dBulge);

	/// @brief �Ƿ�պ�
	bool IsClose() const;

	/// @brief �����Ƿ�պ�
	void setClose(const bool bTrue);

	/// @brief ����
	gp_Vec Normal() const;

	/// @brief ��ȡ�߶εĸ���
	int GetCurveNumber() const;

	/// @brief ��ȡָ���߶�
	/// @param [out] ptS �߶����
	/// @param [out] ptE �߶��յ�
	/// @param [out] dBulge �߶�͹��
	/// @param [in ] nIndex �±� ��0��ʼ
	/// @retrun false �±�Խ��
	bool GetCurve(gp_Pnt2d& ptS, gp_Pnt2d& ptE, double& dBulge, const int nIndex) const;

	/// @brief �Ƴ�ĳ���˵�
	void RemoveVertex(const int nIndex);

	/// @brief ��ȡ���
	Bnd_Box2d GetBndBox() const;

	/// @brief ����
	void Reverse();

	/// @brief ����任
	void Transform(const gp_Trsf2d& transMat);

	/// @brief ����
	/// @param [in ] nNum ���ȷ����ĸ���
	void Sample(const int nNum = 9);
public:
	bool operator == (const CBimGeoPolyline& rhs) const;
private:
	std::vector<gp_Pnt2d>		m_vecVertex;
	std::vector<double>			m_vecBulge;
	bool						m_bIsClose;
};

/// @brief �����Ķ����
struct SBimGeoPolygonWithHole
{
	CBimGeoPolyline					orgPolygon;
	std::list<CBimGeoPolyline>		holes;
};