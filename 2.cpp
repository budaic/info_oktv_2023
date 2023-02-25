#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> kulonbsegek;
vector<int> vegek;
int N;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> N;
    int t_most, t_elozo=0;
    for(int i=0;i<N;i++) {
        cin >> t_most;
        kulonbsegek.emplace(t_elozo-t_most);
        t_elozo=t_most;
    }

    int jelenlegi_szam=0, jelenlegi_count=1;
    int db=1;
    vegek.push_back(1);
    while(kulonbsegek.size()!=0) {
        jelenlegi_szam=kulonbsegek.top();
        kulonbsegek.pop();
        jelenlegi_count=1;
        while(kulonbsegek.size()!=0 && kulonbsegek.top()==jelenlegi_szam) {
            jelenlegi_count++;
            kulonbsegek.pop();
        }
        vegek.push_back(vegek[db-1]+jelenlegi_count);
        db++;
    }

    cout << db << "\n";
    for(auto x:vegek) {
        cout << x << " ";
    }



    return 0;
}