#include "Observer.h"

int testObserver()
{
	/*
	* ������Ҫ����˵�������ڴ�ʾ�������У�Viewһ����ע�ᵽDataModel��֮��DataModel����ʱ���Զ�������
	* �ڲ������д洢��View�������ע����View������Ҫ���ֶ�ȥdelete����ȥdelete View��������
	*/

	View* v1 = new TableView("TableView1");
	View* v2 = new TableView("TableView2");
	View* v3 = new TableView("TableView3");
	View* v4 = new TableView("TableView4");

	IntDataModel* model = new IntDataModel;
	model->addView(v1);
	model->addView(v2);
	model->addView(v3);
	model->addView(v4);

	model->notify();

	cout << "-------------\n" << endl;

	model->removeView(v1);

	model->notify();

	delete model;
	model = nullptr;

	return 0;
}
