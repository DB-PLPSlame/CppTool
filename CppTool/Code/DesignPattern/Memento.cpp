/*
	����¼ģʽ���ڲ��ƻ���װ�Ե�ǰ���£�����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬�������Ժ�Ϳ��Խ��ö���ָ���ԭ�������״̬��
	����¼ģʽ����Ҫ����Ľ�ɫ�ࣺ
		1.Originator(������)�����𴴽�һ������¼Memento�����Լ�¼��ǰʱ��������ڲ�״̬������ʹ�ñ���¼�ָ��ڲ�״̬��Originator���Ը�����Ҫ����Memento�洢�Լ�����Щ�ڲ�״̬��
		2.Memento(����¼)������洢Originator������ڲ�״̬�������Է�ֹOriginator���������������ʱ���¼��
		  ����¼�������ӿڣ�Caretakerֻ�ܿ�������¼��խ�ӿڣ���ֻ�ܽ�����¼���ݸ���������Originatorȴ�ɿ�������¼�Ŀ�ӿڣ����������ʷ��ص���ǰ״̬����Ҫ���������ݡ�
		3.Caretaker(������):������¼Memento�����ܶ�Memento�����ݽ��з��ʻ��߲�����
 */

 /*
 * �ؼ����룺Memento�ࡢOriginator�ࡢCaretaker�ࣻOriginator�಻��Memento����ϣ�������Caretaker����ϡ�
 */
#include <iostream>
#include <unordered_map>
using namespace std;

//��Ҫ�������Ϣ
typedef struct
{
	int grade;
	string arm;
	string corps;
}GameValue;

//Memento��
class Memento
{
public:
	Memento() {}
	Memento(const GameValue& value) :m_gameValue(value) {}
	const GameValue& getValue() const
	{
		return m_gameValue;
	}
private:
	GameValue m_gameValue;
};

//Originator��
class Game
{
public:
	Game(const GameValue& value) :m_gameValue(value)
	{}
	void addGrade()  //�ȼ�����
	{
		m_gameValue.grade++;
	}
	void replaceArm(const string& arm)  //��������
	{
		m_gameValue.arm = arm;
	}
	void replaceCorps(const string& corps)  //��������
	{
		m_gameValue.corps = corps;
	}
	Memento saveValue()    //���浱ǰ��Ϣ
	{
		Memento memento(m_gameValue);
		return memento;
	}
	void load(const Memento& memento) //������Ϣ
	{
		m_gameValue = memento.getValue();
	}
	void showValue()
	{
		cout << "Grade: " << m_gameValue.grade << endl;
		cout << "Arm  : " << m_gameValue.arm.data() << endl;
		cout << "Corps: " << m_gameValue.corps.data() << endl;
	}
private:
	GameValue m_gameValue;
};

//Caretaker��
class Caretake
{
public:
	void save(const unsigned int& index, const Memento& memento)  //������Ϣ
	{
		m_memento[index] = memento;
	}
	const Memento& load(const unsigned int& index)            //���ѱ������Ϣ
	{
		return m_memento[index];
	}
private:
	std::unordered_map<unsigned int, Memento> m_memento;
};

int testMemento()
{
	GameValue v1 = { 0, "Ak", "3K" };
	Game game(v1);    //��ʼֵ
	game.addGrade();
	game.showValue();
	cout << "----------" << endl;
	Caretake care;
	care.save(1, game.saveValue());  //���浱ǰֵ
	game.addGrade();          //�޸ĵ�ǰֵ
	game.replaceArm("M16");
	game.replaceCorps("123");
	game.showValue();
	cout << "----------" << endl;
	game.load(care.load(1));   //�ָ���ʼֵ
	game.showValue();
	return 0;
}
