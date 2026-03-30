#include<iostream>
#include<string>
int main()
{
	int T;
	std::cin >> T;
	
	for(int j=0;j<T;++j)
	{
		int arr[26] = { 0 };
		int karr[26] = { 0 };
		std::string str;
		std::string estr;
		std::cin >> str;
		std::cin >> estr;
		if (str.size() != estr.size())
		{
			std::cout << "Impossible" << '\n';
			continue;
		}
		for (int i = 0; i < str.size(); ++i)
		{
			arr[str[i] - 'a'] += 1;
		}
		for (int i = 0; i < estr.size(); ++i)
		{
			karr[estr[i] - 'a'] += 1;
		}
		for (int i = 0; i < estr.size(); ++i)
		{
			if (arr[i] != karr[i])
			{
				std::cout << "Impossible" << '\n';
				break;
			}
			
		}
		std::cout << "Possible" << '\n';
	}

}