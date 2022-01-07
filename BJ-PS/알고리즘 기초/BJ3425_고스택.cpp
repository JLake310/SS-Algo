#include <bits/stdc++.h>

using namespace std;

#define MAXV 1000000000

enum OPERATION {NUM, POP, INV, DUP, SWP, ADD, SUB, MUL, DIV, MOD};

struct stOpr
{
    int instruction, num;
};

int getInstruction(char* s) {
    if (strcmp(s,"NUM")==0) return NUM;
    else if (strcmp(s,"POP")==0) return POP;
    else if (strcmp(s,"INV")==0) return INV;
    else if (strcmp(s,"DUP")==0) return DUP;
    else if (strcmp(s,"SWP")==0) return SWP;
    else if (strcmp(s,"ADD")==0) return ADD;
    else if (strcmp(s,"SUB")==0) return SUB;
    else if (strcmp(s,"MUL")==0) return MUL;
    else if (strcmp(s,"DIV")==0) return DIV;
    else if (strcmp(s,"MOD")==0) return MOD;

    return -1;
}

int main()
{
    char instruction[5];
    int num;
    long long a, b;
    while(true)
    {
        vector<stOpr> vMachine;
        while(true)
        {
            scanf("%s", instruction);
            if(strcmp(instruction,"QUIT")==0) return 0;
            else if(strcmp(instruction,"END")==0) break;
            else if(strcmp(instruction,"NUM")==0) scanf("%d", &num);

            vMachine.push_back((stOpr){getInstruction(instruction), num});
        }

        int n;
        scanf("%d", &n);

        while(n--)
        {
            scanf("%d", &num);

            stack<int> st;
            st.push(num);

            bool isError = false;
            for(stOpr opr: vMachine)
            {
                if(isError) break;

                switch(opr.instruction)
                {
                    case NUM:
                        st.push(opr.num);
                        break;

                    case POP:
                        if (st.empty()) isError = true;
                        else st.pop();
                        break;

                    case INV:
                        if (st.empty()) isError = true;
                        else
                        {
                            num = st.top();
                            st.pop();
                            st.push(-num);
                        }
                        break;

                    case DUP:
                        if (st.empty()) isError = true;
                        else st.push(st.top());
                        break;

                    case SWP:
                        if (st.size()<2) isError = true;
                        else
                        {
                            a = st.top();
                            st.pop();
                            b = st.top();
                            st.pop();
                            st.push(a);
                            st.push(b);
                        }
                        break;

                    case ADD:
                        if (st.size()<2) isError = true;
                        else
                        {
                            a = st.top();
                            st.pop();
                            b = st.top();
                            st.pop();
                            if(abs(a+b) > MAXV) isError = true;
                            else st.push((int)a+(int)b);
                        }
                        break;

                    case SUB:
                        if (st.size()<2) isError = true;
                        else
                        {
                            a = st.top();
                            st.pop();
                            b = st.top();
                            st.pop();
                            if(abs(b-a) > MAXV) isError = true;
                            else st.push((int)b-(int)a);
                        }
                        break;

                    case MUL:
                        if (st.size()<2) isError = true;
                        else
                        {
                            a = st.top();
                            st.pop();
                            b = st.top();
                            st.pop();
                            if(abs(a*b) > MAXV) isError = true;
                            else st.push((int)a*(int)b);
                        }
                        break;

                    case DIV:
                        if (st.size()<2) isError = true;
                        else
                        {
                            a = st.top();
                            st.pop();
                            b = st.top();
                            st.pop();
                            if(a==0) isError = true;
                            else
                            {
                                int minusCnt = (a<0) + (b<0);
                                st.push(abs(b)/abs(a)*(minusCnt==1? -1:1));
                            }
                        }
                        break;

                    case MOD:
                        if (st.size()<2) isError = true;
                        else
                        {
                            a = st.top();
                            st.pop();
                            b = st.top();
                            st.pop();
                            if(a==0) isError = true;
                            else st.push(b%a);
                        }
                        break;
                }
            }

            if(isError || st.size() != 1) printf("ERROR\n");
            else printf("%d\n", st.top());

        }

        printf("\n");
    }

    return 0;
}
