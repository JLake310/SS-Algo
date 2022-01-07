#include <bits/stdc++.h>

using namespace std;

#define MAXN 10

int main()
{
    char S[MAXN], t;
    int K;
    string str, ans = "0";
    queue<string> q;

    scanf(" %s %d", S, &K);//char array로 입력받는다.
    str = S;//string으로 변환

    q.push(str);

    for(int i=0; i<K; i++)//layer를 늘려가면서 K번까지 진행
    {
        //각 layer에서 숫자가 중복된걸 연산할 필요가 없다.
        //중복 계산을 막기 위해 set 활용
        set<string> s;
        int qSize = q.size();

        //하나의 layer를 처리
        for(int j=0; j<qSize; j++)
        {
            str = q.front();
            q.pop();

            if(s.count(str)==1) continue;//이미 처리한 것이면 진행할 필요없음
            s.insert(str);

            for(int k=0; k<str.size()-1; k++)
            {
                for(int l=k+1; l<str.size(); l++)
                {
                    //첫번째 문자와 교환할 때, 첫번째 문자로 올 문자가 '0'이면 진행하면 안됨
                    if(k==0 && str[l]=='0') continue;

                    //k, l 문자를 교환
                    t = str[k];
                    str[k] = str[l];
                    str[l] = t;

                    q.push(str);

                    //다시 원복
                    t = str[k];
                    str[k] = str[l];
                    str[l] = t;
                }
            }
        }
    }

    //queue에 남아 있는 것중 가장 큰값을 ans에 담는다.
    while(!q.empty())
    {
        ans = max(ans, q.front());
        q.pop();
    }

    if(ans[0]=='0') printf("-1");//연산을 K번 할 수 없으면 -1을 출력한다
    else printf("%s", ans.c_str());    

    return 0;
}
