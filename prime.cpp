#include <bits/stdc++.h>
using namespace std;

const int Max = 100;

bool isPrime(int n) {
	int u = (int)sqrt(n);
    for (int i = 2; i < u; i++)
        if (n % i == 0) {
            return false;
        }
    return n > 1;
}

vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

int minPrime[Max + 1];
void Eratosthenes(){
    for (int i = 0; i <= Max; i++)
        minPrime[i] = 0;
    
    for (int i = 2; i * i <= Max; ++i) {
        if (minPrime[i] == 0) { //if i is prime
            for (int j = i * i; j <= Max; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= Max; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}
vector<int> factorize_Eratosthenes(int n) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}
void prime_doan(int L, int R) {
    vector<bool> isPrime(R - L + 1, true);  // x là số nguyên tố khi và chỉ khi isPrime[x - l] == true

    for (long long i = 2; i * i <= R; ++i) {
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
            isPrime[j - L] = false;
        }
    }

    if (1 >= L) {  // Xét riêng trường hợp số 1
        isPrime[1 - L] = false;
    }

    for (long long x = L; x <= R; ++x) {
        if (isPrime[x - L]) {
            cout << x << "\n";
        }
    }
}

int main() {
    clock_t start, end; 
    ios_base::sync_with_stdio(false); 
    start = clock();
    cout << isPrime((int)1e9 + 7) << endl;
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5); 
    // cout << "Thoi gian chay:" << end - start;


    
    
    
    return 0;
}