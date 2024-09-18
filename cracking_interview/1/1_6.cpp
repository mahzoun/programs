#include <iostream>
using namespace std;
const int N = 5;
void rotate(unsigned int image[][N], int N){
    // i, j => j, N - i - 1
    // j, N - i - 1 => N - i - 1, N - j - 1
    // N - i - 1, N - j - 1 => N - j - 1, i 
    // N - j - 1, i => i , j
    for(int i = 0; i < N / 2; i++){
        for(int j = i; j < N - i - 1; j++){
            unsigned int temp = image[i][j];
            image[i][j] = image[j][N - i - 1];
            image[j][N - i - 1] = image[N - i - 1][N - j - 1];
            image[N - i - 1][N - j - 1] = image[ N - j - 1][i];
            image[N - j - 1][i] = temp;
        }
    }
}

void display(unsigned int image[][N], int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            cout << image[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

int main() {
    unsigned int image[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            image[i][j] = i*N + j;
    display(image, N);
    rotate(image, N);
    display(image, N);
    return 0;
}