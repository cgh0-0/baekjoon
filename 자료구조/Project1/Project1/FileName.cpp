#include <iostream>
#include<string>

using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num)
{
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1)
    {
        pre[nxt[addr]] = unused;

    }
    nxt[addr] = unused;

    ++unused;
}

void erase(int addr)
{
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1)
    {
        pre[nxt[addr]] = pre[addr];
    }




}


int main(void)
{
    std::string h;
    std::cin >> h;
    for (int i = 0; i < h.length(); ++i)
    {
        insert(i, h[i]);
    }
    int* cursor = &nxt[h.length()];//마지막 +1노드 가르킴




    int m;
    std::cin >> m;
    while (m--)
    {
        char a;
        std::cin >> a;
        if (a == 'L' && cursor != &nxt[h.length() + unused - 2])
        {
            --cursor;
        }
        else if (a == 'D' && cursor != &nxt[h.length() - 1])
        {
            ++cursor;
        }
        else if (a == 'B' && cursor != &nxt[h.length() + unused - 2])
        {
            int* pint = cursor;
            --pint;
            int idx = 0;
            for (int i = 0; i <= h.length() - 1 + unused; ++i)
            {
                if (pint == &nxt[i])
                {
                    idx = i;
                    break;
                }
            }
            erase(idx);
        }
        else if (a == 'P')
        {
            char data;
            std::cin >> data;
            int* pint = cursor;
            int idx = 0;
            for (int i = 0; i <= h.length() - 1 + unused; ++i)
            {
                if (pint == &nxt[i])
                {
                    idx = i;
                    break;
                }
            }
            insert(idx, data);

        }
    }
    for (int i = 0; i < h.length() - 1 + unused; ++i)
    {
        std::cout << dat[i] << '\n';
    }
}