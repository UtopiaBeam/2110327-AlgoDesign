// AUTHOR: Rodchananat Khunakornophat
#include <cstdio>
#include <algorithm>
int fw[2000002], n, tmp;
long long ans=0;
void add(int x){
    while (x <= 2000001)
        fw[x]++, x+=x&-x;
}
int sum(int x){
    int sum=0;
    while (x)
        sum += fw[x], x-=x&-x;
    return sum;
}
int main(){
    scanf("%d", &n);
    for (int i=0; i<n; ++i){
        scanf("%d", &tmp);
        tmp += 1000001;
        ans += i-sum(tmp);
        add(tmp);
    }
    printf("%lld", ans);
    return 0;
}