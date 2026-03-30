#include<iostream>
#include<string>
int main()
{
	int T;
	std::cin >> T;

	for (int j = 0; j < T; ++j)
	{
		int arr[26] = { 0 };
		bool im = true;
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
			arr[estr[i] - 'a'] -= 1;
		}
		for (int i = 0; i < 26; ++i)
		{
			if (arr[i]<0)
			{
				im = false;
				continue;
			}

		}
		if (im)
		{
			std::cout << "Possible" << '\n';
		}
		else
		{
			std::cout << "Impossible" << '\n';
		}
		
	}

}