#include<bits/stdc++.h>
using namespace std;

int main()
{
	char a1[5005],b1[5005];//用字符存储数字
	int a[5005],b[5005],c[5005];//c[i] 用来储存每位相减的结果
	int la,lb,x;
	int as=0,bs=0;//记录减数和被减数的具体数值
	bool flag=0;
	
//对a,b,c数组进行初始化
	memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
   
//输入被减数和减数
    scanf("%s %s",&a1,&b1);
    
    la=strlen(a1);
    lb=strlen(b1);
    x=max(la,lb);
    x++;

// 将被减数放入a数组
	for(int i=1; i<=la; i++)
	{
		a[i] = a1[la -i] - '0';
	}    
// 将减数放入b数组
	for(int i=1; i<=lb; i++)
	{
		b[i] = b1[lb -i] - '0';
	}

//判断减数和被减数的关系并进行顺序调换
	if(la<lb) flag=1;
	else if(la==lb)
	{
		if(strcmp(a1,b1)<0) flag=1;
	}
	
	if(flag == 0)
	{
		for(int i=1;i<=x;i++)
		{
			if(a[i]<b[i])
			{
				c[i]=10+a[i]-b[i];
				a[i+1]--;
			}
			else
			{
				c[i]=a[i]-b[i];
			}
		}	
	}
	else
	{
		for(int i=1;i<=x;i++)
		{
			if(b[i]<a[i])
			{
				c[i]=10+b[i]-a[i];
				b[i+1]--;
			}
			else
			{
				c[i]=b[i]-a[i];
			}
		}
	}
	
//删除前导0
	while(c[x] == 0 && x!=1)
	{
		x--;
	}
	
	if(flag == 1) cout<<"-";
	for(int i=x;i>=1;i--)
	{
		cout<<c[i];
	}
	return 0;
}