#include "Eigen/Dense"
#include <iostream>
#include "Pose.h"
using namespace std;
using namespace Eigen;

using Pose2d = Eigen::Isometry2d;
using Pose3d = Eigen::Isometry3d;


//https://blog.csdn.net/xhtchina/article/details/111489117
//https://blog.csdn.net/wangxiao7474/article/details/103612669?spm=1001.2014.3001.5501
//http://t.zoukankan.com/winslam-p-12765822.html

void testPose3d()
{
    Pose3d pose;
    pose.setIdentity();

    // ����q1rotation_matrix������ת
    Quaterniond quaternion(1, 0, 0, 0);
    pose.rotate(quaternion);

    // ��ƽ���������t
    Vector3d t(3, 4, 5);
    /* 
        pretranslate(t)��ʾ����ά�ռ�����v������ת����R��ֱ�Ӽ��ϸ�ƽ����t����Rv+t��
        ��translate(t)��Ҫ��tҲ������ת��������Rv+Rt��
    */
    pose.pretranslate(t);

    cout << pose.matrix() << endl;
    cout << pose.translation() << endl;
}
