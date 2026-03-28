#include<iostream>
#include<string>
int main()
{
	std::string input;
	std::cin >> input;
	int arr[9] = {0};
	int count = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		arr[input[i] - '1'] += 1;
		
	}
	int max = 0;
	for (int i = 0; i < 10; ++i)
	{
		
		if(max<arr[i])
		{
			max = arr[i];
		}
		else if ((i == 5 || i == 8)&&max<arr[i])
		{
			if (arr[i] % 2 != 0)
			{
					max = (arr[i] / 2) +1;
			}
			else if (arr[i] % 2 == 0)
			{

					max = arr[i] / 2;
			}
			else if (arr[i] == 1)
			{
				if (max < 1)
				{
					max = 1;
				}
				
			}
				
		}

			
		
		
		
	}
	std::cout << max;



}

