//#include<bits/stdc++.h>
#include<iostream>
#include<list>
#include<string>
int main()
{
	std::string frist;
	std::cin >> frist;
	std::list<char> second;
	std::list<char>::iterator it = second.end();
	for (int i = 0; i < frist.length(); ++i)
	{
		second.push_back(frist[i]);
		
	}
	--it;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char a;
		std::cin >> a;
		switch(a)
		{
		case 'L':
			if (*it != second.front())
			{
				--it;
			}
			break;
		case 'D':
			if (it != second.end())
			{
				++it;
			}
			break;
		case 'B':
			if (*it != second.front())
			{
				/*auto iter = it;
				for (iter; iter != second.end(); ++iter)
				{
					char nxt = *(++iter);
					*iter = nxt;
				}
				second.pop_back();*/
				auto iter = it;
				--it;
				second.erase(iter);
				
			}
			break;
		case 'P':
			char b;
			std::cin >> b;
			second.insert(it,b);
			

		}
	}
	std::list<char>::iterator a = second.begin();
	for (a; a != second.end(); ++a)
	{
		std::cout << (char)*a;
	}
}