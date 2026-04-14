#include<iostream>
#include<string>
#include<list>
int main()
{
	std::string s;
	std::cin >> s;
	std::list<char> li;
	for (int i = 0; i < s.size(); ++i)
	{
		li.push_back(s[i]);
	}
	
	int M;
	std::cin >> M;
	std::list<char>::iterator cursor = li.end();
	for (int i = 0; i < M; ++i)
	{
		char e;
		std::cin >> e;
		switch(e)
		{
		case 'L':
			if(cursor!=li.begin())
			{
				--cursor;
			}

			break;
		case 'D':
		
			if (cursor != li.end())
			{
				++cursor;
			}


			break;
		case 'B':

			if (cursor != li.begin())
			{
				auto a = cursor;
				--a;
				li.erase(a);
			}



			break;
		case 'P':
			char a;
			std::cin >> a;
			li.insert(cursor, a);
			
			break;
		}
		

	}
	for (auto iter = li.begin(); iter != li.end(); ++iter)
	{

		std::cout << (char)*iter;
	}


}