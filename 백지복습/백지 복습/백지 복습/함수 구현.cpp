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
		// 2nd string loop: Check while decrementing
		for (int i = 0; i < estr.size(); ++i)
		{
			arr[estr[i] - 'a'] -= 1; // Subtract the count

			// If it becomes negative, it means 'estr' has more of this alphabet
			if (arr[estr[i] - 'a'] < 0)
			{
				im = false;
				break; // Exit the loop early
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