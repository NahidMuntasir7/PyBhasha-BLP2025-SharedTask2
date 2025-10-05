// // appifylab : Problem A - just a begining
// # include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int t; cin >> t; // number of test cases

//     while (t--) {
//         string st; cin >> st;  // read input string

//         // convert input string into lowercase
//         for (auto &c: st) {
//             c = tolower(c);
//         }

//         // if input string equals yes, the result is YES, otherwise NO
//         (st == "yes") ? cout << "YES\n" : cout << "NO\n";
//     }

//     return 0;
// }

////////////////PR 2 /////////////////////
// appifylab : Problem A - A
// #include <bits/stdc++.h>
// using namespace std;

// void solve() {
//     int n; cin >> n;    // size of the array

//     // read input array
//     vector<int> arr(n);
//     for (auto &x : arr) cin >> x;

//     // convert even -> 1, odd -> 0
//     for (int i = 0; i < n; i++) {
//         arr[i] = (arr[i] % 2 == 0) ? 1 : 0;
//     }

//     // find position of the last leading zero (if any)
//     int initial_zero = -1;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] == 0) {
//             initial_zero = i;
//         } else {
//             break;
//         }
//     }

//     // Build answer string from remaining elements
//     string ans;
//     for (int i = initial_zero + 1; i < n; i++) {
//         ans += char(arr[i] + '0');
//     }

//     cout << ans << "\n";
// }

// int32_t main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int t; 
//     cin >> t;  // number of test cases

//     for (int i = 1; i <= t; i++) {
//         cout << "Case " << i << ": ";
//         solve();
//     }

//     return 0;
// }

//////////////////////////////////////////////////////////////////////////////////////////////////
// PR 3: Problem B /////////////////////   

// PR 3: Problem B 
// -----------------------------------
// Task: Compute (A * B - C * D) % MOD for large integers A, B, C, D.
// Since A, B, C, D can be very large, we use modular multiplication
// to avoid overflow issues during calculations.

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7; 

// Modular multiplication function using the "Russian peasant method".
// Safely computes (a * b) % m without causing overflow.
long long multiplication(long long a, long long b, long long m) {
    long long res = 0;
    a %= m; 
    while (b) {
        if (b % 2) 
            res = (res + a) % m; 
        a = (2 * a) % m;          
        b >>= 1;                 
    }
    return res;
}

void solve() {
    long long a, b, c, d; 
    cin >> a >> b >> c >> d;

    // compute (A * B) % mod and (C * D) % mod 
    long long x = multiplication(a, b, mod);
    long long y = multiplication(c, d, mod);

    // subtraction under modulo: add mod to avoid negative values
    long long result = (x - y + mod) % mod;

    cout << result << "\n";
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;  // number of test cases

    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}
