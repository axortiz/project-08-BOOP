#include <iostream>
#include <vector>

using namespace std;

void insert(vector <vector <int> > &vec, int value, int x, int y) {
    
    if (vec[x][y] == 0) {
        vec[x][y] = value;
    }
    else {
        cout << "Cannot insert here" << endl;
    }
}

int main () {
    int const ROW = 6;
    int const COL = 6;
    vector<vector<int> > vec;
    for (int i = 0; i < ROW; i++) {
        vector<int> v1;
        for (int j = 0; j < COL; j++) {
            v1.push_back(0);
        }
        vec.push_back(v1);
    }

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    insert(vec, 12, 4, 2);

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
    return 0;
}