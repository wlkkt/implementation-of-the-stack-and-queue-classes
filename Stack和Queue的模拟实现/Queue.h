#pragma once
#include<queue>
#include <stack>
#include<algorithm>
#include<vector>
#include<list>
#include <iostream>
using namespace std;


namespace bit
{
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

	//优先级队列(使用vector适配)
	template<class T,class Container = vector<T>>
	class priority_queue
	{
	public:
		//向上调整
		void adjust_up(size_t child)
		{
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				if (_con[child] > _con[parent])
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

		void adjust_down(size_t parent)
		{
		
			size_t child = parent * 2 + 1;
			//不到叶子就继续
			while (child < _con.size())
			{
				//找出最大的那个孩子
				if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				{
					++child;
				}
				if (_con[child] > _con[parent])
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

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(_con.size() - 1);
		}

		//删除堆顶元素
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
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