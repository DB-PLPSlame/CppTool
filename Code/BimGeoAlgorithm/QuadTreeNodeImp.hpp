#include "QuadTreeNode.h"
#include "BimGeoAlgorithmTool.h"

template <typename T>
QuadTreeNode<T>::QuadTreeNode(const double& dX, const double& dY, const double& dWidth, const double& dHeight,
	const int nLevel, const int nMaxLevel, const QuadType eQuadType, QuadTreeNode* pParent) :
	m_dX(dX)
	, m_dY(dY)
	, m_dWidth(dWidth)
	, m_dHeight(dHeight)
	, m_nlevel(nLevel)
	, m_nMaxLevel(nMaxLevel)
	, m_eQuadType(eQuadType)
	, m_Pparent(pParent)
	, m_upRightNode(nullptr)
	, m_upLeftNode(nullptr)
	, m_bottomLeftNode(nullptr)
	, m_bottomRightNode(nullptr)
{
}

template <typename T>
QuadTreeNode<T>::~QuadTreeNode()
{
	if (nullptr != m_upRightNode)
	{
		delete m_upRightNode;
		m_upRightNode = nullptr;
	}

	if (nullptr != m_upLeftNode)
	{
		delete m_upLeftNode;
		m_upLeftNode = nullptr;
	}

	if (nullptr != m_bottomLeftNode)
	{
		delete m_bottomLeftNode;
		m_bottomLeftNode = nullptr;
	}

	if (nullptr != m_bottomRightNode)
	{
		delete m_bottomRightNode;
		m_bottomRightNode = nullptr;
	}

	if (m_nlevel == m_nMaxLevel)
	{
		return;
	}

	//�������Ҷ�ӽڵ㣬�������ӽڵ�
	m_Pparent = nullptr;
}

template <typename T>
bool QuadTreeNode<T>::IsIntersect(const double& dX, const double& dY, const double& dW, const double& dH, const T *object) const
{
	if (BimGeoAlgorithmTool::lessThan(dX + dW, object->dX)
		|| BimGeoAlgorithmTool::lessThan(object->dX + object->dW, dX)
		|| BimGeoAlgorithmTool::lessThan(dY + dH, object->dY)
		|| BimGeoAlgorithmTool::lessThan(object->dY + object->dH, dY))
	{
		return false;
	}

	return true;
}

template <typename T>
bool QuadTreeNode<T>::IsIntersect(const double& dX, const double& dY, const double& dW, const double& dH, const QuadTreeNode<T> *quadTreeNode) const
{
	if (dX + dW < quadTreeNode->m_dX
		|| quadTreeNode->m_dX + quadTreeNode->m_dWidth < dX
		|| dY + dH <quadTreeNode->m_dY
		|| quadTreeNode->m_dY + quadTreeNode->m_dHeight < dY)
	{
		return false;
	}

	return true;
}

template <typename T>
void QuadTreeNode<T>::InsertObject(T *object)
{
	//�����Ҷ�ӽڵ㣬�����Ҷ�ӽڵ�
	if (m_nlevel == m_nMaxLevel)
	{
		m_objects.emplace_back(object);

		return;
	}

	//��Ҷ�ӽڵ㣬����²�ڵ���԰����ö�����ݹ鹹���ӽڵ㲢�������,�߹����߲���
	if (IsContain(m_dX + m_dWidth / 2, m_dY, m_dWidth / 2, m_dHeight / 2, object))
	{
		if (!m_upRightNode) //�����ظ��������ǵ�ԭ���Ľڵ�
		{
			m_upRightNode = new QuadTreeNode(m_dX + m_dWidth / 2, m_dY, m_dWidth / 2, m_dHeight / 2, m_nlevel + 1, m_nMaxLevel, UP_RIGHT, this);//���û���ӽڵ�ʹ����ӽڵ㣬parent�ڵ��ǵ�ǰ�ڵ�
		}

		m_upRightNode->InsertObject(object);
		return;
	}
	else if (IsContain(m_dX, m_dY, m_dWidth / 2, m_dHeight / 2, object))
	{
		if (!m_upLeftNode)
		{
			m_upLeftNode = new QuadTreeNode(m_dX, m_dY, m_dWidth / 2, m_dHeight / 2, m_nlevel + 1, m_nMaxLevel, UP_LEFT, this);
		}

		m_upLeftNode->InsertObject(object);
		return;
	}
	else if (IsContain(m_dX, m_dY + m_dHeight / 2, m_dWidth / 2, m_dHeight / 2, object))
	{
		if (!m_bottomLeftNode)
		{
			m_bottomLeftNode = new QuadTreeNode(m_dX, m_dY + m_dHeight / 2, m_dWidth / 2, m_dHeight / 2, m_nlevel + 1, m_nMaxLevel, BOTTOM_LEFT, this);
		}
			
		m_bottomLeftNode->InsertObject(object);
		return;
	}
	else if (IsContain(m_dX + m_dWidth / 2, m_dY + m_dHeight / 2, m_dWidth / 2, m_dHeight / 2, object))
	{
		if (!m_bottomRightNode)
		{
			m_bottomRightNode = new QuadTreeNode(m_dX + m_dWidth / 2, m_dY + m_dHeight / 2, m_dWidth / 2, m_dHeight / 2, m_nlevel + 1, m_nMaxLevel, BOTTOM_RIGHT, this);
		}

		m_bottomRightNode->InsertObject(object);
		return;
	}
	//�²�ڵ㲻����ȫ�����Ķ�������뵽��ǰ��Ҷ�ӽڵ�
	//����ж�Ҳ����ʡȥ
	if (IsContain(m_dX, m_dY, m_dWidth, m_dHeight, object))
	{
		m_objects.emplace_back(object);
	}
}

template <typename T>
std::list<T *> QuadTreeNode<T>::GetObjectsAt(const double& dX, const double& dY, const double& dW, const double& dH)
{
	std::list<T *> resObjects;
	//�����ǰ�ڵ���ȫ���������ѵ�ǰ�ڵ��Ķ���ŵ��б�ĩβ,������Ҳ��
	if (IsIntersect(dX, dY, dW, dH, this))
	{
		typename std::list<T *>::iterator itObject = m_objects.begin();
		for (; itObject != m_objects.end(); ++itObject)
		{
			if (IsIntersect(dX, dY, dW, dH, *itObject))
			{
				resObjects.emplace_back(*itObject);
			}
		}

		//���һ��
		if (m_nlevel == m_nMaxLevel)
		{
			return resObjects;
		}
	}
	else
	{
		return resObjects;
	}

	//������²�ڵ�Ͱ��²�ڵ�����Ķ���ӽ���
	if (m_upRightNode)
	{
		std::list<T *> upRightChild = m_upRightNode->GetObjectsAt(dX, dY, dW, dH);
		resObjects.insert(resObjects.end(), upRightChild.begin(), upRightChild.end());
	}
	if (m_upLeftNode)
	{
		std::list<T *> upLeftChild = m_upLeftNode->GetObjectsAt(dX, dY, dW, dH);
		resObjects.insert(resObjects.end(), upLeftChild.begin(), upLeftChild.end());
	}
	if (m_bottomLeftNode)
	{
		std::list<T *> bottomLeftChild = m_bottomLeftNode->GetObjectsAt(dX, dY, dW, dH);
		resObjects.insert(resObjects.end(), bottomLeftChild.begin(), bottomLeftChild.end());
	}
	if (m_bottomRightNode)
	{
		std::list<T *> bottomRightChild = m_bottomRightNode->GetObjectsAt(dX, dY, dW, dH);
		resObjects.insert(resObjects.end(), bottomRightChild.begin(), bottomRightChild.end());
	}

	return resObjects;
}

template <typename T>
void QuadTreeNode<T>::RemoveObjectsAt(const double& dX, const double& dY, const double& dW, const double& dH)
{
	//�������ڵ㱻������ɾ������ڵ�Ķ���
	//����ж���Ҫ�ǶԸ��ڵ������ã������ӽڵ�ʵ�����ϲ㶼�����ж�
	if (IsIntersect(dX, dY, dW, dH, this))
	{
		//������ڵ��Ķ���
		m_objects.clear();
		//���һ��
		if (m_nlevel == m_nMaxLevel)
		{
			return;
		}

	}
	//������ӽڵ��ұ������������ӽڵ㣬ע������Ұָ��
	//��ʵֻҪ�ϲ㱻�����ˣ��²�϶������������뻹��Ľ�
	if (m_upRightNode && IsContain(dX, dY, dW, dH, m_upRightNode))
	{
		m_upRightNode->RemoveObjectsAt(dX, dY, dW, dH);
		delete m_upRightNode;
		m_upRightNode = nullptr;

	}
	if (m_upLeftNode && IsContain(dX, dY, dW, dH, m_upLeftNode))
	{
		m_upLeftNode->RemoveObjectsAt(dX, dY, dW, dH);
		delete m_upLeftNode;
		m_upLeftNode = nullptr;

	}
	if (m_bottomLeftNode && IsContain(dX, dY, dW, dH, m_bottomLeftNode))
	{
		m_bottomLeftNode->RemoveObjectsAt(dX, dY, dW, dH);
		delete m_bottomLeftNode;
		m_bottomLeftNode = nullptr;

	}
	if (m_bottomRightNode && IsContain(dX, dY, dW, dH, m_bottomRightNode))
	{
		m_bottomRightNode->RemoveObjectsAt(dX, dY, dW, dH);
		delete m_bottomRightNode;
		m_bottomRightNode = nullptr;
	}
}

template<typename T>
inline bool QuadTreeNode<T>::IsContain(const double& dX, const double& dY, const double& dW, const double& dH, const T* object) const
{
	if (BimGeoAlgorithmTool::lessEqualThan(dX, object->dX)
		&& BimGeoAlgorithmTool::lessEqualThan(object->dX + object->dW, dX + dW)
		&& BimGeoAlgorithmTool::lessEqualThan(dY, object->dY)
		&& BimGeoAlgorithmTool::lessEqualThan(object->dY + object->dH, dY + dH))
	{
		return true;
	}

	return false;

}

template<typename T>
inline bool QuadTreeNode<T>::IsContain(const double& dX, const double& dY, const double& dW, const double& dH, const QuadTreeNode<T>* quadTreeNode) const
{
	if (quadTreeNode->m_dX >= dX
		&& quadTreeNode->m_dX + quadTreeNode->m_dWidth <= dX + dW
		&& quadTreeNode->m_dY >= dY
		&& quadTreeNode->m_dY + quadTreeNode->m_dHeight <= dY + dH)
	{
		return true;
	}

	return false;

}
