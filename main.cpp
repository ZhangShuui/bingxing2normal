#include <iostream>
#include <windows.h>
using  namespace std;
int a[100000];
int sum=0;
void countAll(int n){
    sum=0;
    for (int i = 0; i < n; ++i) {
        sum+=a[i];
    }
}
int main() {
    for (int i = 0; i < 100000; ++i) {
        a[i]=i;
    }
    int n=2;
    long long freq,start,end;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    while(n<100000){
        int counter=0;
        QueryPerformanceCounter((LARGE_INTEGER*)&start);
        QueryPerformanceCounter((LARGE_INTEGER*)&end);
        while(end-start<100000){
            countAll(n);
            counter++;
            QueryPerformanceCounter((LARGE_INTEGER*)&end);
        }
        float seconds=float (end-start)/float (freq);
        cout<<n<<","<<counter<<","<<seconds<<","<<seconds/double (counter)<<endl;
        n*=2;
    }
    return 0;
}
