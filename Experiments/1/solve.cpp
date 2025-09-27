#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
using namespace std;

const int MAXM = 100000;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<bitset<MAXM+1>> people(n);
    
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int item;
            scanf("%d", &item);
            people[i].set(item);
        }
    }
    
    int q;
    scanf("%d", &q);
    
    unordered_map<long long, int> cache;
    
    while (q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        long long key = (long long)a * (m + 1) + b;
        if (cache.count(key)) {
            printf("%d\n", cache[key]);
            continue;
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (people[i].test(a) && people[i].test(b)) {
                count++;
            }
        }
        
        cache[key] = count;
        printf("%d\n", count);
    }
    
    return 0;
}