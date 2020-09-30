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
				while (s > t)
				{
					std::cout << s->a<<' ' ;
					s++;
				}
			};
			void help()
			{
				std::cout << "List��\n";
	
			};



		};


	//����
	
	class linked_List :public List 
	{
		public:
			linked_List()
			{
				length = 0;
				head = new(N); //ͷ�ڵ� ��������
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
						std::cout << "���ҳɹ� \n";
						break;
					}
			
				}
				if (s == end->next)
				{
					s = head;
					std::cout << "����ʧ��\n"; //����ʧ�ܣ�����ͷ�ڵ�
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
					std::cout << "δ�ҵ��ýڵ�\n";
				}

			}

			void Delet(Dtype data)
			{
				N* Node = GetItem(data);
				if (Node == head)
				{
					std::cout << "δ�ҵ�������\n";
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
			int Full_Length; //��������鳤
			N* tair; //�����������һ��λ��
			N* list; //��Ϊ�����б�����
		public:
			con_List(int n)
			{
				length = 0;
				Full_Length = n;
				N* A = new N[n+1];   //n������ ��n+1�����飬��һλ��βָ��
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
					std::cout <<data<< "����ʧ��\n";
			}

			N* GetItem(Dtype data)
			{
				N* s = head;
				int l = 0;
				while (s < end)
				{
					if (s->a == data)
					{
						std::cout << "����ѯ���� \"" << data << "\" ���б�λ���� " << l << "\n";
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
					std::cout << "δ�ҵ�������\n";
					return end-1;
				}
				else
					return s;
			}
			N* End()       //���һ��λ��
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