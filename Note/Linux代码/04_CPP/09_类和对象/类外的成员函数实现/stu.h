#ifndef __STU_H_
#define __STU_H_

#include <iostream>
using namespace std;
//�������
class Student{
public:
    Student(const string& name);
    void who(void);
private:
    string m_name;
};

#endif
