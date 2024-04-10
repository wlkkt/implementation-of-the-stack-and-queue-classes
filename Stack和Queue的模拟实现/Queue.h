#pragma once
#include<queue>
#include <stack>
#include<algorithm>
#include<vector>
#include<list>
#include <string>
#include <iostream>
using namespace std;


namespace bit
{
	//基于deque实现的队列
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		//入队
		void push(const T& x)
		{
			_con.push_back(x);
		}

		//出队
		void pop()
		{
			_con.pop_front();
		}

		//求大小
		size_t size()
		{
			return _con.size();
		}

		//判空
		bool empty()
		{
			return _con.empty();
		}

		//获取队头
		const T& front()
		{
			return _con.front();
		}

		//获取队尾
		const T& back()
		{
			return _con.back();
		}

	private:
		Container _con;
	};

	//实现小堆逻辑的仿函数
	template<class T>
	class less
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	//实现大堆逻辑的仿函数
	template<class T>
	class greater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};


	//优先级队列(底层数据结构是vector,比较部分调用了仿函数)
	template<class T, class Container = vector<T>, class Compare = less<T>>//不传入指的大小堆实现逻辑则按默认实现小堆逻辑
	class priority_queue
	{
	public:

		//向上调整
		void adjust_up(size_t child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[child] > _con[parent]):求大堆逻辑：将孩子与父亲间大的向上移动
				//if (_con[parent] < _con[child]):求小堆逻辑：将孩子与父亲间小的向前移动
				if (com(_con[child],_con[parent]))//实现大堆还是小队基于使用的仿函数
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{ 
					break;
				}
			}
		}


		void push(const T& x)
		{
			_con.push_back(x);//直接调用现有的尾插函数
			adjust_up(_con.size() - 1);//向上调整建（大/小）堆
		}

		void adjust_down(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			//不到叶子就继续
			while (child < _con.size())
			{
				//找出最大的那个孩子
				//if (child + 1 < _con.size() && _con[child + 1] > _con[child])//大堆逻辑
				//if (child + 1 < _con.size() && _con[child + 1] > _con[child])//小堆逻辑
				if (child + 1 < _con.size() && com(_con[child + 1], _con[child]))
				{
					++child;
				}
				//if (_con[child] > _con[parent])//大堆逻辑
				//if (_con[child] < _con[parent])//小堆逻辑
				if (com(_con[child], _con[parent]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		//删除堆顶元素
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);//交换堆顶元素和最后一个元素
			_con.pop_back();//直接用现有的尾删函数
			adjust_down(0);//向下调整建（大/小）堆
		}

		//判空
		bool empty()
		{
			return _con.empty();
		}

		//获取堆中元素个数
		size_t size()
		{
			return _con.size;
		}

		//获取堆顶元素
		const T& top()
		{
			return _con[0];
		}

	private:
		Container _con;
	};	
}