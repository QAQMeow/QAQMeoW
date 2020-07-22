#include<iostream>

namespace Meow_van
{	template<class T>
	class List
	{
	private:
		int length;
		T* head;     //第一个元素位置
	public:
		
		List();              //链表
		List(int n);     //顺序表 n:元素个数
		~List(void);
	
		int Length();    //表长
		void Insert();    //插入
		void Locate();    //位置
		void Get();       //获取
		void Delete();    //删除
		void Previous();  //前一个位置
		void Next();      //后一个位置
		
		void ClearList(); //重置线性表为空
		T* Head();     //第一个元素位置
		void END();       //最后一个位置
		void ShowList();
		void help();
	};
//方法实现
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
		std::cout << "模板类List，使用List<typename>创建列表\n"
			<<"默认创建链表，创建顺序表List<typename>(int n)\n";
	}

	template<class T>
	List<T>::~List()
	{
		
	}


}