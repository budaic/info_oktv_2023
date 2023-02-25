#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<long long int, long long int> > erok;
int N, M;
vector<long long int> szukseges_ero;
vector<int> eddig; // ha az i.edik szukseges erot nem tudod megverni, de elotte mindenkit, akkor hanyat vertel meg?
vector<int> czgladik;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int erokell, erokap;
    for(int i=0;i<N;i++) {
        cin >> erokell >> erokap;
        erok.emplace(make_pair(-erokell, erokap));
    }

    int cz;
    for(int i=0;i<M;i++) {
        cin >> cz;
        czgladik.push_back(cz);
    }

    int eddig_vert=0;
    long long int current_boost=erok.top().second;
    szukseges_ero.push_back(-erok.top().first);
    eddig.push_back(eddig_vert);
    erok.pop();
    while(erok.size()!=0) {
        eddig_vert++;
        if(-erok.top().first-current_boost>szukseges_ero.back() && current_boost<-erok.top().first) {
            szukseges_ero.push_back(-erok.top().first-current_boost);
            eddig.push_back(eddig_vert);
        }
        current_boost+=erok.top().second;
        erok.pop();
    }

    // ellenorzes
    /*
    for(int i=0;i<szukseges_ero.size();i++) {
        cout << szukseges_ero[i] << " " << eddig[i] << "\n";
    }
    */

    
    int start, end;
    bool nincs_meg;
    for(auto x:czgladik) {
        if(x>szukseges_ero.back()) {
            cout << eddig.back()+1 << " ";
            continue;
        } else if(x<*szukseges_ero.begin()) {
            cout << 0 << " ";
            continue;
        }
        start=0;
        end=szukseges_ero.size()-1;
        nincs_meg=1;
        while(nincs_meg) {
            if(x>=szukseges_ero[(start+end)/2]) {
                start=(start+end)/2;
            } else {
                end=(start+end)/2;
            }
            if(end-start<=1) {
                nincs_meg=0;
            }
        }
        cout << eddig[end] << " ";
    }
    
    /*
    int c=1;
    for(auto x:czgladik) {
        if(x>szukseges_ero.back()) {
            cout << eddig.back()+1 << " ";
            continue;
        } else if(x<*szukseges_ero.begin()) {
            cout << 0 << " ";
            continue;
        }
        for(c=1;c<szukseges_ero.size()-1;c++) {
            if(x<szukseges_ero[c]) {
                break;
            }
        }
        cout << eddig[c] << " ";
    }
    */





    return 0;
}