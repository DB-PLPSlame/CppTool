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


/// @class QuadTreeNode
/// @brief object �ĸ�ʽ�� {double dX, dY, dW, dH}

template <typename T>
class QuadTreeNode
{

public:
	QuadTreeNode(const double& dX, const double& dY, const double& dWidth, const double& dHeight,
		const int nLevel, const int nMaxLevel, const QuadType eQuadType, QuadTreeNode* pParent);
	~QuadTreeNode();
public:
	void InsertObject(T *object); //�������
	std::list<T *> GetObjectsAt(const double& dX, const double& dY, const double& dW, const double& dH); //��ѯ����,���һƬ������Ķ��������˴�ֻ������ȫ������
	void RemoveObjectsAt(const double& dX, const double& dY, const double& dW, const double& dH); //ɾ������ɾ��һƬ������Ķ���ͽڵ㣬�˴�ֻ������ȫ������
private:
	bool IsContain(const double& dX, const double& dY, const double& dW, const double& dH, const T* object) const;
	bool IsContain(const double& dX, const double& dY, const double& dW, const double& dH, const QuadTreeNode<T>* quadTreeNode) const;
	bool IsIntersect(const double& dX, const double& dY, const double& dW, const double& dH, const T* object) const;
	bool IsIntersect(const double& dX, const double& dY, const double& dW, const double& dH, const QuadTreeNode<T>* quadTreeNode) const;
private:
	std::list<T *>		m_objects;				//	�ڵ����ݶ���
	QuadTreeNode*		m_Pparent;				//	���ڵ�
	QuadTreeNode*		m_upRightNode;			//	���Ͻڵ�
	QuadTreeNode*		m_upLeftNode;			//	���Ͻڵ�
	QuadTreeNode*		m_bottomLeftNode;		//	���½ڵ�
	QuadTreeNode*		m_bottomRightNode;		//	���½ڵ�
	double				m_dX;					//	����x����
	double				m_dY;					//	����y����
	double				m_dWidth;				//	���
	double				m_dHeight;				//	�߶�
	QuadType			m_eQuadType;			//	�ڵ�����
	int					m_nlevel;				//	��ǰ���
	int					m_nMaxLevel;			//	������
};

#include "QuadTreeNodeImp.hpp"
