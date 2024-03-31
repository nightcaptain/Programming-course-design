#include<bits\stdc++.h>

//数据的接收和存储
void init(int a[]) { // 传入数组
    string s;
    cin >> s; 
    len = s.length(); // s.length --> 计算字符串位数
    for(int i=1; i<=len; i++)     
    a[i] = s[len -i] - '0'; //将字符串s转换为数组a, 倒序存储
}

//进位、借位的处理.

// 加法进位: c[i] = a[i] + b[i]
 
code:    if(c[i] >= 10) {
            c[i] %= 10;
            ++c[i++];
         }
 
//减法借位: c[i] = a[i] - b[i]
 
code:    if(a[i] < b[i]) {
             --a[i+1];
             a[i] += 10;   
         } 
 
//乘法进位: c[i + j - 1] = a[i] * b[j] + x + c[i + j - 1];
          x = c[i + j - 1] / 10;
          c[i + j - 1] % 10;

