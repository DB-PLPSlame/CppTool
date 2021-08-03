#pragma once

#include "BimGeoAlgorithmDef.h"
#include <list>

//�Ĳ�������ö��
enum QuadType
{
	ROOT,         //��
	UP_RIGHT,     //���ޢ�
	UP_LEFT,      //���ޢ�
	BOTTOM_LEFT,  //���ޢ�
	BOTTOM_RIGHT  //���ޢ�
};


/// @class QuadTreeNodeWithOBB
/// @brief object �ĸ�ʽ�� {double dCenterX, dCenterY, dW, dH, dAngle(������ʱ��Ļ���)}

template <typename T>
class QuadTreeNodeWithOBB
{

public:
	QuadTreeNodeWithOBB(const double& dLeftX, const double& dLeftY, const double& dWidth, const double& dHeight,
		const int nLevel, const int nMaxLevel, const QuadType eQuadType, QuadTreeNodeWithOBB* pParent);
	~QuadTreeNodeWithOBB();
public:
	void InsertObject(T *object); //�������
	std::list<T *> GetObjectsAt(const double& dCenterX, const double& dCenterY, const double& dW, const double& dH, const double& dAngle); //��ѯ����,���һƬ������Ķ��������˴�ֻ������ȫ������
	void RemoveObjectsAt(const double& dLeftX, const double& dLeftY, const double& dW, const double& dH); //ɾ������ɾ��һƬ������Ķ���ͽڵ㣬�˴�ֻ������ȫ������
private:
	bool IsContain(const double& dLeftX, const double& dLeftY, const double& dW, const double& dH, const T* object) const;
	bool IsContain(const double& dLeftX, const double& dLeftY, const double& dW, const double& dH, const QuadTreeNodeWithOBB<T>* quadTreeNode) const;
	bool IsIntersect(const double& dCenterX, const double& dCenterY, const double& dW, const double& dH, const double& dAngle, const T* object) const;
	bool IsIntersect(const double& dCenterX, const double& dCenterY, const double& dW, const double& dH, const double& dAngle, const QuadTreeNodeWithOBB<T>* quadTreeNode) const;
	bool IsIntersect(const double& dLeftX, const double& dLeftY, const double& dW, const double& dH, const QuadTreeNodeWithOBB<T>* quadTreeNode) const;
private:
	std::list<T *>				m_objects;				//	�ڵ����ݶ���
	QuadTreeNodeWithOBB*		m_Pparent;				//	���ڵ�
	QuadTreeNodeWithOBB*		m_upRightNode;			//	���Ͻڵ�
	QuadTreeNodeWithOBB*		m_upLeftNode;			//	���Ͻڵ�
	QuadTreeNodeWithOBB*		m_bottomLeftNode;		//	���½ڵ�
	QuadTreeNodeWithOBB*		m_bottomRightNode;		//	���½ڵ�
	double						m_dX;					//	����x����
	double						m_dY;					//	����y����
	double						m_dWidth;				//	���
	double						m_dHeight;				//	�߶�
	QuadType					m_eQuadType;			//	�ڵ�����
	int							m_nlevel;				//	��ǰ���
	int							m_nMaxLevel;			//	������
};

#include "QuadTreeNodeWithOBBImp.hpp"
