#pragma GCC optimize ("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#pragma GCC optimize ("Ofast")
int rem3(int a) {
    return ((a%3) == 0) ? rem3(a/=3) : a;
}

int rem2(int a) {
    return a >>= __builtin_ctz(a);
}

int main()
{
    int n,m,mm[11],i, prev;
    fscanf(stdin,"%d %d",&n, &prev);
    prev = rem3(rem2(prev));
    i = 1;
    while ((n - i) >= 10) {
        fscanf(stdin,"%d %d %d %d %d %d %d %d %d %d",mm,mm+1,mm+2,mm+3,mm+4,mm+5,mm+6,mm+7,mm+8,mm+9);
        if ((rem3(rem2(mm[0])) != prev) || (rem3(rem2(mm[1])) != prev) ||
            (rem3(rem2(mm[2])) != prev) || (rem3(rem2(mm[3])) != prev) || 
            (rem3(rem2(mm[4])) != prev) || (rem3(rem2(mm[5])) != prev) ||
            (rem3(rem2(mm[6])) != prev) || (rem3(rem2(mm[7])) != prev) ||
            (rem3(rem2(mm[8])) != prev) || (rem3(rem2(mm[9])) != prev)) {
            printf("No\n");
            return 0;
        }
        i+=10;
    }
    for (; i < n; ++i) {
        fscanf(stdin,"%d",&m);
        if (rem3(rem2(m)) != prev) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
