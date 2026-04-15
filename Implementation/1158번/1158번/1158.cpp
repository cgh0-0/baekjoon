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
	std::list<int>::iterator it = one.begin();
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < K - 1; ++j)
		{
			if (it == one.end())
			{
				it = one.begin();
			}
			++it;
			if (it == one.end())
			{
				it = one.begin();
			}
		}
		two.push_back(*it);
		it=one.erase(it);
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