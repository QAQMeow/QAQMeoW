#include<iostream>

namespace Meow_van
{	template<class T>
	class List
	{
	private:
		int length;
		T* head;     //��һ��Ԫ��λ��
	public:
		
		List();              //����
		List(int n);     //˳��� n:Ԫ�ظ���
		~List(void);
	
		int Length();    //��
		void Insert();    //����
		void Locate();    //λ��
		void Get();       //��ȡ
		void Delete();    //ɾ��
		void Previous();  //ǰһ��λ��
		void Next();      //��һ��λ��
		
		void ClearList(); //�������Ա�Ϊ��
		T* Head();     //��һ��Ԫ��λ��
		void END();       //���һ��λ��
		void ShowList();
		void help();
	};
//����ʵ��
	template<class T>
	List<T>::List(int n)
	{
		length = 0;
		T l[n];
		head = &l;

	}

	template<class T>
	List<T>::List()
	{
		length = 0;
		head = new(T);

	}
	template<class T>
	int List<T>::Length()
	{
		return length;
	}


	template<typename T>
	T* List<T>::Head()
	{
		//return head;
	}


	template<class T>
	void List<T>::help()
	{
		std::cout << "ģ����List��ʹ��List<typename>�����б�\n"
			<<"Ĭ�ϴ�����������˳���List<typename>(int n)\n";
	}

	template<class T>
	List<T>::~List()
	{
		
	}


}