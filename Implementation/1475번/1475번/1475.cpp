#include<iostream>
#include<string>
int main()
{
	std::string input;
	std::cin >> input;
	int arr[10] = { 0 };
	int count = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		arr[input[i] - '1'] += 1;
	}
	for (int i = 1; i < 10; ++i)
	{
		if (i==6 && i == 9)
		{

		}
		else
		{
			if (arr[i]>1)
			{
				count += arr[i];
			}
		}
	}



}

