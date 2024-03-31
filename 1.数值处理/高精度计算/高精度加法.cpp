#include<bits/stdc++.h>
using namespace std;

int main()
{
	char a1[5005],b1[5005];//用字符存储数字
	int a[5005],b[5005],c[5005];//c[i] 用来储存每位相加的结果
	int la,lb,lc=1,x;
	
//对a,b,c数组进行初始化
	memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
   
//输入两个加数    
    scanf("%s %s",&a1,&b1);
    
    la=strlen(a1);
    lb=strlen(b1);
    x=max(la,lb);
    x++;

// 将加数放进a数组    
    for(int i=1; i<=la; i++)
	{
		a[i] = a1[la -i] - '0';
	}    
	
// 将另一个加数放进b数组
	for(int i=1; i<=lb; i++)
	{
		b[i] = b1[lb -i] - '0';
	}
	

	for(int i=1;i<=x;i++)
	{
		c[i]+=a[i]+b[i];
		if(c[i]>=10)
		{
			c[i]%=10;
			c[i+1]+=1;
		}
	}
	
	if(c[x] == 0) x--;
	for(int i=x;i>=1;i--)
	{
		cout<<c[i];
	}	
	return 0;

}