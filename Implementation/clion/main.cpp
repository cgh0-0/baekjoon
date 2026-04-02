#include<bits/stdc++.h>
using namespace std;
/*정의: 포인터(동적 할당) 대신 배열 인덱스(dat, pre, nxt)를 주소로 활용해, 메모리 할당 시간을 대폭 줄인 코딩 테스트 전용 연결 리스트.

원리: unused는 '다음에 채울 빈 칸의 인덱스'로 계속 증가만 하며, 삽입/삭제 시 배열 데이터를 직접 옮기는 게 아니라 앞뒤 노드의 양팔(pre, nxt 값)이 가리키는 방향만 덮어씌워 논리적으로 연결을 맺고 끊는다.

실수 포인트 (패턴명: -1 허공 잡기 & unused 착각 패턴): 맨 끝 노드를 조작할 때 배열 인덱스 [ ] 안에 -1이 들어가면 메모리 에러가 터지므로 항상 if (nxt[addr] != -1) 방패를 세워야 하며, 노드를 지웠다고 해서 --unused를 해버리면 멀쩡히 살아있는 다음 데이터를 덮어씌우는 치명적 에러가 발생한다.

addr의 정의
addr은 'address(주소)'의 약자로, **'새로운 노드를 어느 노드 바로 뒤에 끼워 넣을 것인가?'**를 결정하는 기준점(앞 노드)의 인덱스 번호입니다.
즉, addr번 칸 뒤에 새 노드를 새치기시키라는 뜻입니다.
*/
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