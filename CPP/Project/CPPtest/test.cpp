#include<iostream>
#include"test.h"

void Stock::acquire(const std::string& co, long n, double pr)
{
	company = co;
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative."
			<< company << "shares set to 0.\n";
		shares = 0;
	}
	else shares = n;

	share_val = pr;
	set_tot();
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative."
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}

}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Number of shares sold can't be negative."
			<< "Transaction is aborted.\n";
	}
	else if(num>shares)
	{
		cout << "You can't sell more than you have!"
			<< "Trasaction is aborted\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();

}

void Stock::show()
{
	std::cout << "Company: " << company
		<< " Shares: " << shares << '\n'
		<< " Share price: $" << share_val
		<< " Total Worth: $" << total_val << '\n';
}



Stock::Stock(const std::string & co,long n,double pr)
{
	company = co;
	if (n < 0)
	{
		std::cerr << "Number of shares can't be negative."
			<< company << "shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::Stock()
{
	company = "No name";
	shares = 0.;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::~Stock()
{
	//std::cout << "End.\n";
}

const Stock& Stock::topval(const Stock S) const
{
	if (S.total_val > total_val)
		return S;
	else
		return *this;
}








