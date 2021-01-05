#include <iostream>
#include <vector>

using namespace std;

vector <int> leftq;
vector <vector<int>> Q;
vector<int> row;
vector <int> line;
int w, k, h, n, u, m;

ostream& operator << (ostream& out, vector<int>& line){
    for(int i = 0; i < line.size(); ++i) out << line[i] << " ";
    return out;
}

bool getLine(int g, int norm, int f = 0){
    if (norm <= g) {
        //cout << line << endl;
        return true;
    }
    if (f == line.size()) return false; // compare count of right with (norm - g)
    for (int i = f; i < line.size(); ++i){
        int l = 0, r = 0;
        //cout << "Leftq: " << leftq << endl <<  "Q[f]: " << Q[f] << endl << "Line: "<< line << endl;
        while (leftq.size() > l && Q[i].size() > r){
            if (leftq[l] == Q[i][r]){
                line[i] = leftq[l];
                leftq.erase(leftq.begin() + l);
                Q[i].erase(Q[i].begin() + r);
                vector<int> backup_l = leftq;
                vector<int> backup_r = Q[i];
                if (getLine(g + 1, norm, i + 1)) return true;
                leftq = backup_l;
                Q[i] = backup_r;
                continue;
            }
            if (leftq[l] > Q[i][r]) {
                r++;
                continue;
            }
            l++;
        }
        return getLine(g, norm, f + 1);
    }
}
int main(){
    cin >> w >> k >> h >> n >> u >> m;
    for (int i = 1; i < m + 1; ++i) row.push_back(i);
    Q.assign(h, row);
    for (int i = 0; i < h; ++i){
        leftq = row;
        line.resize(n);
        if (i != h - 1) getLine(0, w);
        getLine(0, u);
        cout << line << endl;
    }
}
