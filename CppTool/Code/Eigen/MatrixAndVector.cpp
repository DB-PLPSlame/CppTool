#include "MatrixAndVector.h"
#include "Eigen/Dense"
#include <iostream>
using namespace std;
using namespace Eigen;


void MatrixInit()
{
    cout << __FUNCTION__ << endl;
    // ������ֵ
    Matrix3f  m1;
    m1 << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;

    cout << m1 << endl;

    // �ֿ����ֵ�������������ϲ�����
    int rows = 5, cols = 5;
    MatrixXf m(rows, cols);
    m << (Matrix3f() << 1, 2, 3, 4, 5, 6, 7, 8, 9).finished(),
        MatrixXf::Zero(3, cols - 3),
        MatrixXf::Zero(rows - 3, 3),
        MatrixXf::Identity(rows - 3, cols - 3); //   Zero()��Identity() �ֱ���0����͵�λ����
    cout << m << endl;

    // �������
    MatrixXf A = MatrixXf::Random(3, 2);
    cout << A << endl;
    A = MatrixXf::Zero(3, 3);
    cout << A << endl;
    A = MatrixXf::Identity(3, 3);
    cout << A << endl;
    A = MatrixXf::Constant(rows, cols, 1); //��������
    cout << A << endl;
}

void MatrixOperations()
{
    cout << __FUNCTION__ << endl;
    MatrixXf m1;
    m1 = MatrixXf::Random(3, 3);
    cout << m1 << endl;
    cout << m1.transpose() << endl; //ת��
    cout << m1.conjugate() << endl; //����
    cout << m1.adjoint() << endl; //����ת�ã��������


    MatrixXd m2(2, 2);
    m2 << 1, 2, 3, 4;
    cout << m2 << endl;
    cout << m2.sum() << endl;//����Ԫ�����
    cout << m2.prod() << endl;//����Ԫ�س˻�
    cout << m2.mean() << endl;//����Ԫ����ƽ��
    cout << m2.minCoeff() << endl;//����Ԫ������Сֵ
    cout << m2.maxCoeff() << endl;//����Ԫ�������ֵ
    cout << m2.trace() << endl;//��
}

void MatrixBlockOperactions()
{
    cout << __FUNCTION__ << endl;

    Eigen::MatrixXf matrix(4, 4);
    matrix << 1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16;

    //����Ŀ������
    //��ʾ���شӾ���ģ�i��j����ʼ��ÿ��ȡP��Ԫ�أ�ÿ��ȡq��Ԫ�أ�ԭ���󲻱�
    cout << matrix.block(1, 1, 2, 2) << endl;
    //ԭ�����е�(i, j)��ʼ����ȡһ��p��q�е��Ӿ��󣬷��ظ��Ӿ�����ɵ���ʱ �������ԭ�����Ԫ�ز���
    cout << matrix.block<2, 2>(1, 1) << endl;

    //��ȡ�����е�ĳ��ĳ��
    cout << matrix.row(3) << endl;
    cout << matrix.col(3) << endl;
}


void TestMatrix()
{
    MatrixInit();
    MatrixOperations();
    MatrixBlockOperactions();
}

void TestVector()
{
    Vector3d v1(1, 2, 3);
    Vector3d v2(4, 5, 6);
    Vector3d v;
    double dot_value, norm_value;
    dot_value = v1.dot(v2);//��ˣ��õ����Ǳ���
    v = v1.cross(v2);//��ˣ��õ���������
    cout << dot_value << endl;
    cout << v << endl;
    norm_value = v1.norm();//��ģ
    cout << norm_value << endl;

    Eigen::ArrayXf v3(6);
    v3 << 1, 2, 3, 4, 5, 6;
    v3.head(3);//��ȡ������ǰn��Ԫ��
    v3.tail(3);//��ȡ����β����n��Ԫ��
    v3.segment(3, 3);//��ȡ�������ĵ�i��Ԫ�ؿ�ʼ��n��Ԫ��
    cout << v3.segment(3, 3) << endl;
}
