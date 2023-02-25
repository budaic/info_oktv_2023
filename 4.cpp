#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    M=(N+1)/2;

    for(int z=0;z<K-1 && z<N;z++) {
        if(z%2==0) {
            cout << M+(K-z)/2 << " ";
        } else {
            cout << M-(K-z)/2 << " ";
        }
    }
    for(int z=K-1;z==K-1 && z<N;z++) {
        cout << M << " ";
    }
    for(int z=K;z<N;z++) {
        if(z%2==0) {
            cout << M-(z+1)/2 << " ";
        } else {
            cout << M+(z+1)/2 << " ";
        }
    }

    return 0;
}