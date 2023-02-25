#include <iostream>
#include <vector>

using namespace std;

unsigned int N, M;
vector<unsigned short int> kikotok;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    kikotok.resize(N);
    unsigned int kezd, veg;
    
    for(int i=0;i<M;i++) {
        cin >> kezd >> veg;
        kikotok[kezd-1]++;
        kikotok[veg-1]++;
        for(int j=kezd;j<veg-1;j++) {
            kikotok[j]+=2;
        }
    }

    unsigned int max_k=0, max_hely;
    for(int i=0;i<N;i++) {
        if(kikotok[i]>max_k) {
            max_k=kikotok[i];
            max_hely=i;
        } 
    }

    cout << max_hely+1 << " " << max_k << "\n";

    return 0;
}