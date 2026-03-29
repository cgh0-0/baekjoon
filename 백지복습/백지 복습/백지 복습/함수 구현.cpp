#include<iostream>
void insert(int idx, int num, int arr[], int& len)
{
	for (int i = len; idx <= i; --i)
	{
		arr[i + 1] = arr[i];
	}
	arr[idx] = num;
	++len;
}
void erase(int idx, int arr[], int& len)
{

}
int main()
{

}