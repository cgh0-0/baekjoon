#include<iostream>
#include<string>
int main()
{
	std::string str;
	std::string rts;
	std::cin >> str;
	std::cin >> rts;
	int count = 0;
	int arr[26] = { 0 };
	for (int i = 0; i < str.size(); ++i)
	{
		arr[str[i] - 'a'] += 1;
	}
	for (int i = 0; i < rts.size(); ++i)
	{
		arr[rts[i] - 'a'] -= 1;
		if (arr[i] < 0)
		{
			count += arr[i] * (-1);
		}
		else if (arr[i] > 0)
		{
			count += arr[i];
		}

	}
	std::cout << count;
}