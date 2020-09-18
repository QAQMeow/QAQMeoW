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
				std::cout << s;
				while (s != t)
				{
					std::cout << s->a;
					s++;
				}
			};
			void help()
			{
				std::cout << "类List，使用List<typename>创建列表\n";
	
			};



		};


	//链表
	
	class linked_List :public List 
	{
		public:
			linked_List()
			{
				length = 0;
				head = new(N);
				head->next = NULL;
				head->pre = NULL;
				end = head;
				std::cout << head<<'\n';
			};

		
	};

	class con_List : public List
	{
		protected:
			int Full_Length; //分配的数组长

		public:
			con_List(int n)
			{
				length = 0;
				Full_Length = n;
				N* A = new N[n+1];   //n个数据 建n+1的数组，留一位做尾指针（数组下标0做结尾）
				end = A;
				
				//head->next = NULL;
				//head->pre = NULL;
				head = end;

			};
			void Insert(Dtype data)
			{
				
				head ++;
				head->a = data;
			}
			void cShowList()
			{	
				N* S = head;
				while (S > end)
				{
					std::cout << S->a<<'\n';
					S--;
				}
			};
	};
}