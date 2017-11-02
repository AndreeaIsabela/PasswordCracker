
#include "stdafx.h"

std::string pass ;
int nrOfThreads=6;

std::string toLower(std::string pass)
{
	std::string newPass = "";
	for (auto i = 0; i <pass.size(); ++i)
	{
		if (pass[i] >= 'A'&&pass[i] <= 'Z')
			newPass += (char)(pass[i] + 32);
		else
			newPass += pass[i];
	}
	return newPass;
}

std::string str_tolower(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(),
		[]( char c)
	{
		if (!(c >= '0' && c <= '9'))
			return (char)(c+32); 
		return c;
	} 
	);
	return s;
}

class Test
{
public:
	void operator()( int intervalCounter )
	{
		auto begin = 10'000'000 + intervalCounter*(89'999'999 / nrOfThreads);
		
		auto end = 10'000'000 + (intervalCounter + 1)*(89'999'999 / nrOfThreads);
		if (intervalCounter == nrOfThreads-1)
			end = 99'999'999;

		for (auto i=begin; i <= end; ++i) 
		{
			if (pass == sha256(std::to_string(i)))
			{
				std::cout << "Your password is: " << i;
				return;
			}
		}
	}

};

int main(int argc, char *argv[])
{
	pass = toLower("7B8B88888920C3DAF103FC48EE2550E370A80AE99B7DB42C25F56CA33282D110");
	
	int i;
	std::vector<std::thread> v;
	for (i = 0; i < nrOfThreads; ++i)
	{
		v.push_back(std::thread(Test(), i));
	}
	
	for (auto &it : v)
	{
		it.join();
	}
	

	//password:24169915
	return 0;
}
//#include<iostream>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
//
//int main()
//{
//	
//	string name = "ana";
//	string copy;
//	for_each(name.rbegin(),name.rend(),copy.begin()
//
//
//
//
//	return 0;
//}