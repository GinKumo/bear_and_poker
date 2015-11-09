#include <iostream>
#include <vector>
using namespace std;


int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    vector <int>bid;
    int n=-1,m=-1,i;
    cin >> n;
    bid.reserve(n);
    for (i=0; i < n; ++i) {
        cin >> m;
        bid.push_back(m);
    }
    if (n == 1) {
        cout << "Yes" << endl;
        exit(0);
    }
    int g = bid[0];
    for (auto i: bid) {
        g = gcd(g,i);
    }
    for (i=0; i < bid.size(); ++i) {
        bid[i] /= g;
        bid[i] %= 3*2;
        //bid[i] %= 2;
    }
    //cout << "gcd:" << g << endl;
    cout << ((all_of(bid.begin(), bid.end(), [](int i){return i == 0 || i == 2 || i == 3 ;})) ? "Yes" : "No") << endl;
    //for (auto i: bid) {
    //    cout << i << endl;
    //}

    return 0;
}
