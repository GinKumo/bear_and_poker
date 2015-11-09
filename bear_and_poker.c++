#pragma GCC optimize ("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#pragma GCC optimize ("Ofast")
int rem3(int a) {
    return ((a%3) == 0) ? rem3(a/3) : a;
}

int rem2(int a) {
    return a >> __builtin_ctz(a);
}

int main()
{
    static int n=-1,m=-1,i, prev;
    fscanf(stdin,"%d",&n);
    prev = -1;
    for (i=0; i < n; ++i) {
        fscanf(stdin,"%d",&m);
        m = rem3(rem2(m));
        if (prev >= 0) {
            if (m != prev) {
                printf("No\n");fflush(stdout);
                return 0;
            }
        } else {
            prev = m;
        }
    }
    printf("Yes\n");fflush(stdout);
    return 0;
}
