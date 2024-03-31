#include<bits/stdc++.h>
//#include<STACK_SIM.h>
using namespace std;

const int N = 1000010;
int stk[N],tt = 0;//创建数组栈

//用结构体可以更好的模拟c++里的stack数据结构
struct STACK_SIM
{

//把数据x压入栈
	void push(int x)
	{
   	 	stk[++tt] = x;
	}

//把栈顶数据弹出栈
	void pop()
	{
	    tt--;
	}

//读取栈顶元素
	int top()
	{
	    return stk[tt];
	}

//判断栈为空
	bool empty()
	{
	    return tt == 0;
	}
};

int main()
{
	string op;//表示操作
    STACK_SIM a;
    while(cin>>op)
    {
        if(op=="stop")//停止操作，退出
            break;
        if(op=="push")//压入x元素
        {
            int x;
            scanf("%d",&x);
            a.push(x);
            
            printf("Stack:");
            for(int i=1;i<tt+1;i++)
			{
				cout<<stk[i];
			}
			cout<<endl<<endl;
        }
        if(op=="pop")//弹出栈顶元素
        {
            if(!a.empty()) a.pop();//若非空则弹出
            else printf("Empty!\n");
            
            printf("Stack:");
            for(int i=1;i<tt+1;i++)
			{
				cout<<stk[i];
			}
			cout<<endl<<endl;
        }
        if(op=="top")//查询栈顶元素
        {
            if(!a.empty())printf("%d\n",a.top());
            else printf("Empty!\n");
            
            printf("Stack:");
            for(int i=1;i<tt+1;i++)
			{
				cout<<stk[i];
			}
			cout<<endl<<endl;
        }
    }
    return 0;
}

