#include<iostream>

namespace Meow_van
{	
	typedef int Dtype;


	template<typename datatype>
	struct Node
	{
		Node* next;
		Node* pre;
		datatype a;    
	
	};
	
	typedef Node<Dtype> N; //默认为int型，可修改 ，相应 部分也要修改
	
	
	class List
	{
		protected:
			int length;
			N* head;     //第一个元素位置
			N* end;      //最后一个元素位置
			
		public:
			
			List()
			{
				length = 0;
				head = NULL;
				end = head;
				
			};
		
			~List(void)
			{};
	
			int Length()    //表长
			{
				return length;
			};
							
			N* Head()     //第一个元素位置
			{
				return head;
			};

			N* End()       //最后一个位置
			{
				return end;
			};
			void ShowList()
			{
				N* s = head;
				N* t = end;
				while (s > t)
				{
					std::cout << s->a<<' ' ;
					s++;
				}
			};
			void help()
			{
				std::cout << "List类\n";
	
			};



		};


	//链表
	
	class linked_List :public List 
	{
		public:
			linked_List()
			{
				length = 0;
				head = new(N); //头节点 不存数据
				head->a = -99999;
				head->next = NULL;
				head->pre = NULL;
				end = head;
				
			};
			
			void Insert(Dtype data)
			{
				length += 1;
				N* node = new(N);
				node->a = data;
				end->next = node;
				node->pre = end;
				node->next = NULL;
				end = node;
			}

			N* GetItem(Dtype data)
			{
				N* s = head->next;
				
				for (s; s != end->next; s = s->next)
				{
					if (s->a == data)
					{	
						std::cout << "查找成功 \n";
						break;
					}
			
				}
				if (s == end->next)
				{
					s = head;
					std::cout << "查找失败\n"; //查找失败，返回头节点
				}
				return s;
			}
			
			void Delet(N* Node)
			{
				N* s = head->next;
				for (s; s != end->next; s = s->next)
				{
					if (s == Node)
					{
						s->pre->next = s->next;
						s->next->pre = s->pre;
						free(s);
					}
				}
				if (s == end->next)
				{
					std::cout << "未找到该节点\n";
				}

			}

			void Delet(Dtype data)
			{
				N* Node = GetItem(data);
				if (Node == head)
				{
					std::cout << "未找到该数据\n";
				}
				else
				{
					Node->pre->next = Node->next;
					Node->next->pre = Node->pre;
					free(Node);
				}

			}

			void ShowList()
			{
				N* s = head->next;
				N* t = end->next;
				while (s != t)
				{
					std::cout << s->a << ' ';
					s = s->next;
				}
			};
	};

	class con_List : public List
	{
		protected:
			int Full_Length; //分配的数组长
			N* tair; //分配数组最后一个位置
			N* list; //作为整个列表的入口
		public:
			con_List(int n)
			{
				length = 0;
				Full_Length = n;
				N* A = new N[n+1];   //n个数据 建n+1的数组，留一位做尾指针
				head = A;
				tair = &A[n];
				end = head;
				list = head;

			};
			void Insert(Dtype data)
			{
				if (end < tair)
				{
						end->a = data;
						length += 1;
						end++;
				}
				else
					std::cout <<data<< "插入失败\n";
			}

			N* GetItem(Dtype data)
			{
				N* s = head;
				int l = 0;
				while (s < end)
				{
					if (s->a == data)
					{
						std::cout << "所查询数据 \"" << data << "\" 在列表位置是 " << l << "\n";
						break;
					}
					else
					{
						l++;
						s++;
					}
				}
				if (s == end)
				{
					std::cout << "未找到该数据\n";
					return end-1;
				}
				else
					return s;
			}
			N* End()       //最后一个位置
			{
				;
				return end-1;
			}

			void ShowList()
			{	
				N* S = head;
				while (S < end)
				{
					std::cout << S->a<<' ';
					S++;
				}
				std::cout << '\n';
			};
	};
}