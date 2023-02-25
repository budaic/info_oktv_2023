#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> utak_ki;
int Dora, Nora;

vector<bool> volt;
long long int min_hossz;
long long int ut_hossz;
vector<int> min_tav;
vector<vector<int>> jo_utak;
vector<int> ut;

void search(int hol) {
    if(hol==Nora) {
        if(ut_hossz==min_hossz) {
            jo_utak.push_back(ut);
        } else if(ut_hossz<min_hossz) {
            jo_utak.resize(0);
            jo_utak.push_back(ut);
            min_hossz=ut_hossz;
        }
        return;
    }
    if(ut_hossz>min_hossz) {
        return;
    }
    if(min_tav[hol]>ut_hossz) {
        min_tav[hol]=ut_hossz;
    } else if(min_tav[hol]>ut_hossz) {
        return;
    }
    for(auto x:utak_ki[hol]) {
        if(volt[x.first]==0) {
            volt[x.first]=1;
            ut.push_back(x.first);
            ut_hossz+=x.second;
            search(x.first);
            volt[x.first]=0;
            ut.pop_back();
            ut_hossz-=x.second;
        }
    }
}


int main() {

    cin >> N >> M;
    utak_ki.resize(N+1);
    int t1, t2, h;
    for(int i=0;i<M;i++) {
        cin >> t1 >> t2 >> h;
        utak_ki[t1].push_back(make_pair(t2, h));
        utak_ki[t2].push_back(make_pair(t1, h));
    }
    cin >> Dora >> Nora;

    volt.resize(N+1);
    min_hossz=1000000000000;
    jo_utak.resize(0);
    min_tav.resize(N+1);
    search(Dora);

    cout << jo_utak.size()*(jo_utak.size()-1) << "\n";


    return 0;
}