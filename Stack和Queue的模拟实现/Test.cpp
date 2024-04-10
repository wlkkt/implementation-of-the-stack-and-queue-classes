#include"Stack.h"
#include"Queue.h"


 void test_stack()
{
	//bit::stack<int,vector<int>> st;
	//bit::stack<int,list<int>> st;
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
void test_queue()
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

//���ȼ�����
void test_priority_queue1()
{
	bit::priority_queue<int,vector<int>,bit::greater<int>> pq;//���int���͵����ݣ��ײ����ݽṹΪvector��ʵ�ִ�ѵ��߼�
	pq.push(2);
	pq.push(1);
	pq.push(3);
	pq.push(4);
	pq.push(5);
	pq.push(7);
	pq.push(8);
	pq.push(6);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}




//�����ȼ������з����Զ�������
class Date
{
public:
	friend ostream& operator<<(ostream& _cout, const Date& d);

	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}



//����ָ��Ƚϵķº���
class GreaterPDate
{
public:
	bool operator()(const Date* p1, const Date* p2)
	{
		return *p1 > *p2;
	}
};

void test_priority_queue2()
{
	////�����ȼ������д���Զ�������
	//bit::priority_queue<Date, vector<Date>, bit::greater<Date>> pq;

	//Date d1(2024, 4, 8);
	//pq.push(d1);//��������
	//pq.push(Date(2024, 4, 10));//��������
	//pq.push({ 2024, 2, 15 });//�������ʽ����ת��

	//while (!pq.empty())
	//{
	//	cout << pq.top() << " ";
	//	pq.pop();
	//}
	//cout << endl;

	//�����ȼ������д��ָ��
	bit::priority_queue<Date*, vector<Date*>, GreaterPDate> pqptr;//���ܶ���������Date*��������operator<
	pqptr.push(new Date(2024, 4, 14));//new��һ�����������͵��������󣬷��ص������ǵ�ַ����������ݴ���ĵ�ַ���н�����ÿ�ε�ֵ�ǲ�һ����
	pqptr.push(new Date(2024, 4, 11));
	pqptr.push(new Date(2024, 4, 15));

	while (!pqptr.empty())
	{
		cout << *(pqptr.top()) << " ";
		pqptr.pop();
	}
	cout << endl;
}

int main()
{
	//test_stack();
	//test_queue();
	//test_priority_queue1();
	test_priority_queue2();
	return 0;
}



//��Ʒ�Ƚ�
//struct Goods
//{
//	string _name; // ����
//	double _price; // �۸�
//	int _evaluate; // ����
//
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		, _price(price)
//		, _evaluate(evaluate)
//	{}
//};
//
//struct ComparePriceLess
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price < gr._price;
//	}
//};
//struct ComparePriceGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;
//	}
//};
//
//struct CompareEvaluateLess
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._evaluate < gr._evaluate;
//	}
//};
//struct CompareEvaluateGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._evaluate > gr._evaluate;
//	}
//};
//
//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2,
//	3 }, { "����", 1.5, 4 } };
//
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//	sort(v.begin(), v.end(), CompareEvaluateLess());
//	sort(v.begin(), v.end(), CompareEvaluateGreater());
//	return 0;
//}