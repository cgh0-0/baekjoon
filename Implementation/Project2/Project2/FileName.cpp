#include<iostream>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num)
{
	dat[unused] = num;//일단 배열의 빈칸에 값을 넣어준다
	pre[unused] = addr;//이 노드의 이전 노드는 원래 이 노드자리에 있던 노드다
	nxt[unused] = nxt[addr];//이 노드의 다음노드는 내 이전 노드의 원래 다음값이다.

	if (nxt[addr] != -1)
	{
		pre[nxt[addr]] = unused;
	}
	nxt[addr] = unused;
	++unused;

		//이게 뭔지 모르겠음
	//이것도 뭔지 모르겠음 
}

void erase(int addr) 
{
	
	if (nxt[addr] != -1)
	{
		pre[nxt[addr]] = pre[addr];
		
	}
	nxt[pre[addr]] = nxt[addr];
	
}

void traverse() {
	int cur = nxt[0];
	while (cur != -1) {
		cout << dat[cur] << ' ';
		cur = nxt[cur];
	}
	cout << "\n\n";
}

void insert_test() {
	cout << "****** insert_test *****\n";
	insert(0, 10); // 10(address=1)
	traverse();
	insert(0, 30); // 30(address=2) 10
	traverse();
	insert(2, 40); // 30 40(address=3) 10
	traverse();
	insert(1, 20); // 30 40 10 20(address=4)
	traverse();
	insert(4, 70); // 30 40 10 20 70(address=5)
	traverse();
}

void erase_test() {
	cout << "****** erase_test *****\n";
	erase(1); // 30 40 20 70
	traverse();
	erase(2); // 40 20 70
	traverse();
	erase(4); // 40 70
	traverse();
	erase(5); // 40
	traverse();
}

int main(void) {
	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);
	insert_test();
	erase_test();
}