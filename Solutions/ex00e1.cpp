// AUTHOR: Rodchananat Khunakornophat
#include <cstdio>
using namespace std;


int main(){
    int hh, mm, d;
    scanf("%d %d %d", &hh, &mm, &d);
    mm += d;
    hh += mm/60; mm %= 60;
    hh %= 24;
    printf("%02d %02d", hh?:0, mm);
    return 0;
}