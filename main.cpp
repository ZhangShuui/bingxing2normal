#include <iostream>
#include <time.h>
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

    while(n<100000){
        int counter=0;
        int start=clock(),end=clock(),freq=CLOCKS_PER_SEC;
        while(end-start<10){
            countAll(n);
            counter++;
            end=clock();
        }
        float seconds=float (end-start)/float (freq);
        cout<<n<<","<<counter<<","<<seconds<<","<<seconds/double (counter)<<endl;
        n*=2;
    }

    return 0;
}
