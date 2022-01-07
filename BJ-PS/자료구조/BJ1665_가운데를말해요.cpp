#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int> maxheap, minheap;

    int N;
    scanf("%d", &N);

    for(int i=0, num; i<N; i++)
    {
        scanf("%d", &num);
        if(maxheap.size() > minheap.size()) minheap.push(-num);
        else maxheap.push(num);

        if(maxheap.size()>0 && minheap.size()>0)
        {
            //maxheap이 더 큰 경우 minheap과 교환
            if(maxheap.top() > -minheap.top())
            {
                int maxtop = maxheap.top();
                int mintop = -minheap.top();
                maxheap.pop();
                minheap.pop();
                maxheap.push(mintop);
                minheap.push(-maxtop);
            }
        }
        printf("%d\n", maxheap.top());
    }

    return 0;
}
