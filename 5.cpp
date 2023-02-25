#include <iostream>
#include <vector>

using namespace std;

vector<int> aladar_lepesei;

int B, C;

int main() {
    cin >> B >> C;

    aladar_lepesei.resize(C, 0);
    for(int i=0;i<B;i++) {
        aladar_lepesei[i]=1;
    }

    long long int osszeg=0;
    while(aladar_lepesei.back()==0) {
        osszeg=0;
        for(int i=0;i<C;i++) {
            if(aladar_lepesei[i]==0) {
                aladar_lepesei[i]=osszeg%1000000007;
                break;
            } else {
                osszeg+=aladar_lepesei[i];
                aladar_lepesei[i]=osszeg%1000000007;
            }
        }
    }
    cout << osszeg%1000000007 << endl;

    return 0;
}