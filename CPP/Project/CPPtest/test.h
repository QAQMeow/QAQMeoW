
#ifndef STOCKOO_H_
#define STOCKOO_H_

#include<iostream>
#include<cstring>
#include<vector>

class Stock
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot()
	{
		total_val = shares * share_val;
	}
public:
	Stock(const std::string& co,long n,double pr);
	Stock();
	~Stock();
	void acquire(const std::string& co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const Stock& topval(const Stock S) const;
	void show();
};


#endif // !STOCKOO_H_

