/*이번에 배운 것들:

스택 vs 힙 — 큰 배열은 스택에 올리면 Segfault
new는 초기화 안 됨 — ()를 붙여야 0으로 초기화
배열 인덱스 음수 접근 — 범위 체크 필수
문제 조건을 꼼꼼히 읽기 — 중복 없음 조건이 로직에 영향을 줌*/


#include<iostream>
#include<vector>
int main()
{
	int count = 0;
	int n;
	std::cin >> n;
	std::vector<int>input(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> input[i];
	}
	int x;
	std::cin >> x;

	int* pint= new int[2000001]();
	for (int i = 0; i < n; ++i)
	{
		if(x>input[i])//이게 핵심 이 조건문을 안넣었을때 이 조건을 만족 못하면 음수 인덱스에 접근함
		{
			if (pint[x - input[i]] ==1 )//중복 없으므로 0또는 1만 존재
			{
				++count;
			}
		}
		pint[input[i]] += 1;
	}
	std::cout << count;
	delete[] pint;
}