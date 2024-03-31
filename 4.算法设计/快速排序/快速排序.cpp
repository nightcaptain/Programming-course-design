#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

//快排
void quickSort(int a[], int _l, int _r) {
    int l = _l;
    int r = _r;
    int flag = 0;
    if (l < r) {   //待排序的元素至少有两个的情况
        flag = a[l];  //待排序的第一个元素作为基准元素
        while (l != r) {   //从左右两边交替扫描，直到l = r

            while (r > l&& a[r] >= flag)
                r--;        //从右往左扫描，找到第一个比基准元素小的元素
            a[l] = a[r];  //找到这种元素a[r]后与a[l]交换

            while (l < r && a[l] <= flag)
                l++;         //从左往右扫描，找到第一个比基准元素大的元素
            a[r] = a[l];  //找到这种元素a[l]后，与a[r]交换

        }
        a[r] = flag;    //基准元素归位
        quickSort(a, _l, l - 1);  //对基准元素左边的元素进行递归排序
        quickSort(a, r + 1, _r);  //对基准元素右边的进行递归排序
    }
}
//主函数
int main() {
	
    int fl;//需要排序的数组的长度；
    cin>>fl;   
	int a[fl];
	
	for(int i=0;i<fl;i++)
	{
		cin>>a[i];
	}
    
    int len = 0;
    len = sizeof(a) / sizeof(int);
    cout << "数组长度：" << len << endl;

    cout << "排序之前：" << endl;
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    quickSort(a, 0, len - 1);

    cout << "\n排序之后：" <<endl;;
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
	return 0;
}

