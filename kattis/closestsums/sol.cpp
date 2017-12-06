#include <algorithm>
#include <unordered_map>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 101
#define RALL(x) x.rbegin(), x.rend()

int d8[9] = {-1, 0, 1, 0, -1, 1, 1, -1, -1};
int d4[5] = {-1, 0, 1, 0 , -1};
using namespace std;



int close_sum(int *a, int tar, int size) 
{
    int i = 0, j = size-1, diff, sum, closest = a[i] + a[j];

    while(i<j) {
        sum = a[i] + a[j];
        diff = sum - tar;   

        if(abs(closest - tar) > abs(diff))
            closest = sum;

        if(diff > 0) j--;
        else if(diff < 0) i++;
        else return tar;
    }

    return closest;
}

int a[1000], m, n, tc, tar, i, _n;


int main () {
    tc = 0;
    while(cin >> n) {
        _n = n, i = 0;
        while(_n--) {
            cin >> a[i++];
        }

        sort(a, a+n);
        printf("Case %d:\n", ++tc);
        cin >> m;
        while(m--) {
            cin >> tar;
            printf("Closest sum to %d is %d.\n", tar, close_sum(a, tar, n));
        }
    }
}