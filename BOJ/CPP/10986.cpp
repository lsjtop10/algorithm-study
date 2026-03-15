#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int m;
    
    
    cin >> n >> m;
    vector<long> sums(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        
        sums[i] = sums[i - 1] + input;
    }
    
    long cnt = 0;
    vector<long> numOfRest(m + 1,0);
    for (int i = 1; i <= n; i++) {
        int rest = sums[i] % m;

        if (rest == 0){
            cnt++;
        }

        numOfRest[rest]++;
    }

    for (auto it = numOfRest.begin(); it != numOfRest.end(); it++){
        auto val = *it;
        if (val > 1){
            cnt += (val * (val - 1)) / 2;    
        }
    }

    cout << cnt << "\n";
    
    return 0;
}
