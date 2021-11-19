#include "MyList.h"


void MyList::insert(int pos, int data)
{
    if (pos < 0 || pos > cnt_)
        pos = cnt_; //���뵽β��

    const auto insert = new Node(data);

    if (0 == pos)
    {
        insert->next_ = head_;
        head_ = insert;
    }
    else
    {
        auto position = head_;
        for (auto i = 1; i < pos; i++)
            position = position->next_;

        insert->next_ = position->next_;
        position->next_ = insert;
    }
    cnt_++;
}

void MyList::remove(int pos)
{
    if (pos < 0 || pos >= cnt_)
    {
        printf("���겻�Ϸ���ɾ���ڵ�ʧ��\n");
        return;
    }
    if (0 == pos)
    {
        auto remove = head_;
        head_ = head_->next_;
        delete remove;
        remove = nullptr;
    }
    else
    {
        auto previous = head_;
        for (auto i = 1; i < pos; i++)
            previous = previous->next_;

        auto remove = previous->next_;
        previous->next_ = previous->next_->next_;
        delete remove;
        remove = nullptr;
    }
    cnt_--;
}

void MyList::travel() const
{
    Node* p = head_;
    printf("�����е�Ԫ���У�");
    while (p != nullptr)
    {
        printf("%d ", p->data_);
        p = p->next_;
    }
    printf("\n");
}

void MyList::reverse()
{
    Node* one = nullptr;
    Node* two = head_;

    while (two) {
        auto temp = two->next_;
        two->next_ = one;
        one = two;

        two = temp;
    }

    head_ = one;
}


void testMyList()
{
    //�����������ҽ��г�ʼ��
    MyList list;

    //�����½ڵ㣬���ҽ��б���
    list.push_head(11);
    list.travel();		//11
    list.push_head(22);
    list.travel();		//22 11
    list.push_head(33);
    list.travel();		//33 22 11
    printf("---------------\n");

    printf("�����нڵ�ĸ����ǣ�%d\n", list.size());
    printf("%s\n", list.empty() ? "����Ϊ��" : "����Ϊ��");
    printf("--------------------\n");

    list.travel();		//33 22 11
    list.insert(-2, 44);
    list.travel();		//33 22 11 44
    list.insert(0, 55);
    list.travel();		//55 33 22 11 44
    list.insert(2, 66);
    list.travel();		//55 33 66 22 11 44
    list.insert(6, 77);
    list.travel();		//77�����
    printf("------------------\n");

    list.remove(-2);	//ɾ��ʧ��
    list.remove(0);
    list.travel();		//33 66 22 11 44 77
    list.remove(1);
    list.travel();		//33 22 11 44 77
    list.remove(5);		//ɾ��ʧ��
    list.travel();		//33 22 11 44 77
    list.remove(4);
    list.travel();		//33 22 11 44
    printf("-------------------\n");

    list.reverse();
    list.travel();

    list.clear();
    list.travel();
}
