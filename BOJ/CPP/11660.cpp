#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int size;
    int numOfQuery;

    cin >> size;
    cin >> numOfQuery;
    
    vector<vector<int>> sums(size + 1, vector<int>(size + 1, 0));

    for(int i = 1; i <= size; i++){
        for(int j = 1; j <= size; j++){
            int input;
            cin >> input;
            sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + input;
        }
    }

    for(int i = 0; i < numOfQuery; i++){
        int x1,y1;
        int x2,y2;

        cin >> x1 >> y1;
        cin >> x2 >> y2;

        cout << sums[x2][y2] - sums[x1 - 1][y2] - sums[x2][y1 - 1] + sums[x1 - 1][y1 - 1];
        cout << "\n";
    }
    
    
    
}
