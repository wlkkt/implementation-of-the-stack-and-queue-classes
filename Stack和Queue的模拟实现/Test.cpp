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

//尝试deque
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

//优先级队列
void test_priority_queue1()
{
	bit::priority_queue<int,vector<int>,bit::greater<int>> pq;//存放int类型的数据，底层数据结构为vector，实现大堆的逻辑
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




//向优先级队列中放入自定义数据
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



//处理指针比较的仿函数
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
	////向优先级队列中存放自定义数据
	//bit::priority_queue<Date, vector<Date>, bit::greater<Date>> pq;

	//Date d1(2024, 4, 8);
	//pq.push(d1);//有名对象
	//pq.push(Date(2024, 4, 10));//匿名对象
	//pq.push({ 2024, 2, 15 });//多参数隐式类型转换

	//while (!pq.empty())
	//{
	//	cout << pq.top() << " ";
	//	pq.pop();
	//}
	//cout << endl;

	//向优先级队列中存放指针
	bit::priority_queue<Date*, vector<Date*>, GreaterPDate> pqptr;//不能对内置类型Date*进行重载operator<
	pqptr.push(new Date(2024, 4, 14));//new了一个日期类类型的匿名对象，返回的类型是地址，如果仅根据传入的地址进行建堆则每次的值是不一样的
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



//商品比较
//struct Goods
//{
//	string _name; // 名字
//	double _price; // 价格
//	int _evaluate; // 评价
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
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2,
//	3 }, { "菠萝", 1.5, 4 } };
//
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//	sort(v.begin(), v.end(), CompareEvaluateLess());
//	sort(v.begin(), v.end(), CompareEvaluateGreater());
//	return 0;
//}