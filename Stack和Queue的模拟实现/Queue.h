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
		//���
		void push(const T& x)
		{
			_con.push_back(x);
		}

		//����
		void pop()
		{
			_con.pop_front();
		}

		//���С
		size_t size()
		{
			return _con.size();
		}

		//�п�
		bool empty()
		{
			return _con.empty();
		}

		//��ȡ��ͷ
		const T& front()
		{
			return _con.front();
		}

		//��ȡ��β
		const T& back()
		{
			return _con.back();
		}

	private:
		Container _con;
	};

	//���ȼ�����(ʹ��vector����)
	template<class T,class Container = vector<T>>
	class priority_queue
	{
	public:
		//���ϵ���
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
			//����Ҷ�Ӿͼ���
			while (child < _con.size())
			{
				//�ҳ������Ǹ�����
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

		//ɾ���Ѷ�Ԫ��
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		//�п�
		bool empty()
		{
			return _con.empty();
		}

		//��ȡ����Ԫ�ظ���
		size_t size()
		{
			return _con.size;
		}

		//��ȡ�Ѷ�Ԫ��
		const T& top()
		{
			return _con[0];
		}


	private:
		Container _con;
	
	
	};











}