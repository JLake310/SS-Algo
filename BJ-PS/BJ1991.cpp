#include <bits/stdc++.h>

using namespace std;

#define MAXN 26

struct stNode
{
    char left;
    char right;
};

stNode Data[MAXN+1];

// 전위 순회
// root - left - right
void preOrder(char node)
{
    if(node == '.') return;

    printf("%c", node);
    preOrder(Data[node-'A'].left);
    preOrder(Data[node-'A'].right);
}

// 중위 순회
// left - root - right
void inOrder(char node)
{
    if(node == '.') return;

    inOrder(Data[node-'A'].left);
    printf("%c", node);
    inOrder(Data[node-'A'].right);
}

// 후위 순회
// left - right - root
void postOrder(char node)
{ 
    if(node == '.') return;

    postOrder(Data[node-'A'].left);
    postOrder(Data[node-'A'].right);
    printf("%c", node);
}

int main()
{
    int n;
    scanf("%d", &n);

    char node, left, right;
    for(int i = 0; i < n; i++)
    {
        scanf(" %c %c %c", &node, &left, &right);
        Data[node-'A'].left = left;
        Data[node-'A'].right = right;
    }

    preOrder('A');
    printf("\n");

    inOrder('A');
    printf("\n");

    postOrder('A');

    return 0;
}
