#include"Stack.h"
#include"Queue.h"

void test_stack1()
{
	//bit::stack<int,vector<int>> st;
	bit::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop(); 
	}
	cout << endl;

}

//����deque
void test_queue1()
{
	bit::queue<int> q;
	q.push(1);
	q.push(2);

	cout << q.front() << " ";
	q.pop();

	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void test_priority_queue()
{
	//Ĭ�ϴ�����ȼ��ߣ��ײ���һ�����

	bit::priority_queue<int> pq;//ʹ��ģ��ʵ�ֵ�priority_queue
	pq.push(2);
	pq.push(1);
	pq.push(3);
	pq.push(4);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	//vector<int> v = { 3,1,7,4,6,3 };
	////����
	//sort(v.begin(), v.end());
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	////����
	//sort(v.begin(), v.end());
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

}




int main()
{
	//test_stack1();
	//test_queue1();
	test_priority_queue();

	return 0;
}




//�º��� + ����ģ��
//template <class T>
//struct MyComparator
//{
//	bool operator()(const T& x, const T& y)
//	{
//		return x < y;
//	}
//};
//
//int main()
//{
//	MyComparator<int> cmp;
//	cout << cmp(1, 2) << endl;
//	cout << cmp.operator()(1, 2) << endl;
//	cout << MyComparator<int>()(1, 2) << endl;
//	cout << MyComparator<int>().operator()(1, 2) << endl;
//	return 0;
//}

