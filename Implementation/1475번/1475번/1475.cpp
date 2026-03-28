#include<iostream>
#include<string>
int main()
{
	std::string input;
	std::cin >> input;
	int arr[10] = {0};
	int count = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		arr[input[i] - '0'] += 1;
		
	}
	int max = 0;
	for (int i = 0; i < 10; ++i)
	{
		
		if(max<arr[i])
		{

			if (i == 6 || i == 9)
			{
				if (arr[i] % 2 != 0)
				{
					max += (arr[i] / 2) + 1;
				}
				else if (arr[i] % 2 == 0)
				{

					max += arr[i] / 2;
				}
				else if (arr[i] == 1)
				{
					if (max < 1)
					{
						max = 1;
					}
					//6699입력시 오류 
				}
				continue;
			}	
		 max = arr[i];
				
		}

			
		
		
		
	}
	std::cout << max;



}

