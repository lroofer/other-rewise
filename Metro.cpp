#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>> stations;
vector<vector<int>> gr;
int sumi = 0;

bool similar(vector<int> a, vector<int> b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    while (i != a.size() && j != b.size()){
        if(a[i] == b[j]) return true;
        if(a[i] > b[j]){
            if (j != b.size()) j++;
            else return false;
        } else{
            if (i != a.size()) i++;
            else return false;
        }
    }
    return false;
}

void dfs(int v, int t)
{

}
void getWay(int a, int b){
    if (similar(stations[a], stations[b])) return;
    // граф, в котором мы стоим в фективном лементе, из которого есть путь в stations[a] вершин, нужно попасть в фективный элемент, который пересекается с stations[b] путями
    int fect_a = gr.size() - 2;
    int fect_b = gr.size() - 1;
    gr[fect_a] = stations[a];
    for(int i = 0; i < stations[b].size(); ++i) gr[stations[b][i]].push_back(fect_b);
    dfs(fect_a, fect_b);
}

/*int main(){
    //test
    cout << similar({0}, {2, 1}) << endl;
}*/
int main() {
    int n, m;
    cin >> n >> m;
    stations.resize(n + 1);
    gr.assign(m + 2, vector<int>(m + 2));
    for (int i = 0; i < m; ++i){
        int p;
        cin >> p;
        for (int j = 0; j < p; ++j){
            int num;
            cin >> num;
            stations[num].push_back(i);
            if (stations[num].size() > 1) {
                int other = stations[num][stations[num].size() - 2];
                gr[other][i] = 1;
                gr[i][other] = 1;
            }
        }
    }
    int a, b;
    cin >> a >> b;
    getWay(a, b);
    cout << sumi << "\n";
    return 0;
}
