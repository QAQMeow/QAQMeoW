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
	
	typedef Node<Dtype> N; //Ĭ��Ϊint�ͣ����޸� ����Ӧ ����ҲҪ�޸�
	
	
	class List
	{
		protected:
			int length;
			N* head;     //��һ��Ԫ��λ��
			N* end;      //���һ��Ԫ��λ��
		public:
			
			List()
			{
				length = 0;
				head = NULL;
				end = head;
				
			};
		
			~List(void)
			{};
	
			int Length()    //��
			{
				return length;
			};
							
			N* Head()     //��һ��Ԫ��λ��
			{
				return head;
			};

			N* End()       //���һ��λ��
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
				std::cout << "��List��ʹ��List<typename>�����б�\n";
	
			};



		};


	//����
	
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
			int Full_Length; //��������鳤

		public:
			con_List(int n)
			{
				length = 0;
				Full_Length = n;
				N* A = new N[n+1];   //n������ ��n+1�����飬��һλ��βָ�루�����±�0����β��
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