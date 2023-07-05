
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    vector<long long> prefix_sum(n);
    prefix_sum[0] = vec[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + vec[i];
    }
    
    while (q--) {
        int x;
        cin >> x;
        
        long long answer = 0;
        
        if (n == 1) {
            answer = vec[0];
        } else if (x == 1) {
            answer = prefix_sum[0];
        } else if (x == 2) {
            answer = max(vec[0] + vec[1], vec[1]);
        } else {
            answer = prefix_sum[x-2];
            answer += max(vec[x-1] + vec[x-2], vec[x-1]);
        }
        
        cout << answer << endl;
    }
    
    return 0;
}
