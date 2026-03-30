#include<iostream>
//1강 문제 2 합이 100인 서로 ㅏㄷ른 위치의 두 원소가 존재하는가
//다른 배열을 만들어서 대응하는 수가 있는지 확인하는걸 생각못함
int fun2(int arr[], int len)
{
	int exist[101];
	for (int i = 0; i < len; ++i)
	{
		if (exist[100-arr[i]]==1)
		{
			return 1;
		}
		exist[arr[i]] = 1;
	}
	return 0;
}
int main()
{
	int arr[3] = { 1,52,48 };
	

	int arr2[2] = { 50,42 };

	int arr4[4] = { 4,13,63,87 };

	int a = fun2(arr, 3);
	int b = fun2(arr2, 2);
	int c = fun2(arr4, 4);
	std::cout << a << '\n' << b << '\n' << c;
}