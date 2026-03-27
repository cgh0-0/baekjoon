#include<iostream>
#include<string>
int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
	{
		std::string str;
		std::cin >> str;
		std::string stre;
		std::cin >> stre;
		int abc[26] = { 0 };
		int def[26] = { 0 };
		bool possible = false;
		for (int i = 0; i < str.size(); ++i)
		{
			abc[str[i] - 'a'] += 1;
		}
		for (int i = 0; i < stre.size(); ++i)
		{
			def[stre[i] - 'a'] += 1;

		}
		for (int i = 0; i < 26; ++i)
		{
			if (abc[i] == def[i])
			{
				possible = true;
			}
			else
			{
				possible = false;
				break;
			}
		}

		if (possible)
		{
			std::cout << "Possible" << '\n';
		}
		else
		{
			std::cout << "Impossible" << '\n';
		}

	};
}