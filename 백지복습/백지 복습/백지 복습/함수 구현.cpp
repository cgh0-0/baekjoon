#include<iostream>
#include<string>
int main()
{
	std::string input;
	std::cin >> input;
	int arr[10] = { 0 };
	for (int i = 0; i < input.size(); ++i)
	{
		arr[input[i] - '0'] += 1;
	}
	arr[6] += arr[9];
	arr[6] = (arr[6] + 1) / 2;//만약 2로 안나눠지고 .5로 떨어지면 올림 해줘야 되어서 +1
	arr[9] = 0;
	int max = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	std::cout << max;
}