
#include<iostream>
#include<string>
#include<list>
int main()
{
	std::string frist;
	std::cin >> frist;
	std::list<char> second;

	for (int i = 0; i < frist.length(); ++i)
	{
		second.push_back(frist[i]);

	}
	std::list<char>::iterator it = second.end();
	--it;
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char a;
		std::cin >> a;
		switch (a)
		{
		case 'L':
			if (it != second.begin())
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
				if (it == second.end())
				{
					--it;
				}
				auto iter = it;
				--iter;
				second.erase(iter);
				
			}
			break;
		case 'P':
			char b;
			std::cin >> b;
			second.insert(it, b);
			break;

		}
		std::cout << "cursor statement:";
		if (it==second.end())
		{
			std::cout << "nullptr" << std::endl;
		}
		else
		{
			std::cout << *it << std::endl;
		}


	}
	std::list<char>::iterator a = second.begin();
	for (a; a != second.end(); ++a)
	{
		std::cout << (char)*a;
	}
}
