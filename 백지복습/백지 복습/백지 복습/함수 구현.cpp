#include<iostream>
#include<list>
int main()
{
	std::list<int> one;
	std::list<int>two;
	int N, K;
	std::cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		one.push_back(i);
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < K - 1; ++j)
		{
			int tmp = one.front();
			one.push_back(tmp);
			one.pop_front();
		}
		two.push_back(one.front());
		one.pop_front();
	}

	std::list<int>::iterator iter = two.begin();
	std::cout << "<";
	for (iter; iter != two.end(); ++iter)
	{
		std::cout << *iter;
		if (*iter != two.back())
		{
			std::cout << ", ";
		}
	}
	std::cout << ">";

}