#include "Common.h"
#include "Eigen/Dense"
#include <iostream>
using namespace std;
using namespace Eigen;


void LeastSquareMethod()
{
    //�Է���Ax=b
    MatrixXf A = MatrixXf::Random(3, 2);
    VectorXf b = VectorXf::Random(3);
    std::cout << "Here is the matrix A:\n" << A << std::endl;
    std::cout << "Here is the right hand side b:\n" << b << std::endl;
    
    /*
      �ܽ�
        ������AΪ��̬����ʱ��ͨ��������ʽ���ʱЧ�����á�
        SVD�ֽⷽ����׼ȷ�����������ٶ�������������ⷽ�������ٶȿ죬��׼ȷ�ȵͣ�QR�ֽ�������֮�䡣
     */
    cout << "********** normal equations ********************" << endl;
    // Ax = b is equivalent to solving the normal equation ATAx = ATb
    cout << "The solution using normal equations is:\n" << (A.transpose() * A).ldlt().solve(A.transpose() * b) << endl;

    cout << "********** SVD decomposition ********************" << endl;
    //jacobiSvd ��ʽ:Slow (but fast for small matrices)
    cout << "The solution using the SVD decomposition is:\n" << A.bdcSvd(ComputeThinU | ComputeThinV).solve(b) << endl;

    cout << "********** QR decomposition ********************" << endl;
    //colPivHouseholderQr����:fast
    cout << "The solution using the QR decomposition is:\n" << A.colPivHouseholderQr().solve(b) << endl;
}
