// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


void fun(int x,stack<int>& s){
    if(s.empty() or s.top() <= x){
        s.push(x);
        return;
    }
    stack<int> aux;
    while(!s.empty() and s.top() > x){
        aux.push(s.top());
        s.pop();
        
    }
    
    s.push(x);
    while(!aux.empty()){
        s.push(aux.top());
        aux.pop();
    }
}

void SortedStack :: sort()
{
    if(s.empty()) return;
    
    int x = s.top();
    s.pop();
    sort();
    fun(x,s);
}