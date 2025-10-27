#include <iostream>
using namespace std;

// (a) Transpose
void transpose(int a[20][3], int b[20][3]) {
    int n = a[0][2];
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = n;
    int k = 1;
    for (int i = 0; i < a[0][1]; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j][1] == i) {
                b[k][0] = a[j][1];
                b[k][1] = a[j][0];
                b[k][2] = a[j][2];
                k++;
            }
        }
    }
}

// (b) Addition
void add(int a[20][3], int b[20][3], int c[40][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible";
        return;
    }
    int i = 1, j = 1, k = 1;
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        } else if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++; k++;
        } else {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++; k++;
        }
    }
    while (i <= a[0][2]) {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++; k++;
    }
    c[0][2] = k - 1;
}

// (c) Multiplication
void multiply(int a[20][3], int b[20][3], int c[50][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Multiplication not possible";
        return;
    }
    int p = a[0][0], q = a[0][1], r = b[0][1];
    c[0][0] = p;
    c[0][1] = r;
    int k = 1;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            int sum = 0;
            for (int x = 1; x <= a[0][2]; x++) {
                for (int y = 1; y <= b[0][2]; y++) {
                    if (a[x][0] == i && b[y][1] == j && a[x][1] == b[y][0])
                        sum += a[x][2] * b[y][2];
                }
            }
            if (sum != 0) {
                c[k][0] = i;
                c[k][1] = j;
                c[k][2] = sum;
                k++;
            }
        }
    }
    c[0][2] = k - 1;
}

int main() {
    // Example input can be added here if needed
    return 0;
}
