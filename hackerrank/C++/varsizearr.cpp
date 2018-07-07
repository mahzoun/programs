#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a[n];
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int tmp;
            cin >> tmp;
            a[i].push_back(tmp);
        }
    }
    for(int i = 0; i < q; i++){
        int h, w;
        cin >> h >> w;
        cout << a[h][w] << endl;
    }
    return 0;
}

