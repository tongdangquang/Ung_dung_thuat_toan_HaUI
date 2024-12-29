#include <iostream>

using namespace std;

int x[100], k = 6, n = 7;
int c1 = 0, c2 = 0;

char S[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

// thuat toan A3: pp sing
void view_config(int x[], int k) {
    for (int i = 1; i <= k; i++) 
        cout << S[x[i] - 1] << " ";
    cout << endl;
}

void next_config(int x[], int k, int i) {
    x[i] += 1;
    i++;
    while (i <= k) {
        x[i] = x[i - 1] + 1;
        i++;
    }
}

void list_configs(int k, int n) {
    int i, x[k + 1] = {0};
    for (i = 1; i <= k; i++) x[i] = i;
    do
    {
        view_config(x, k);
        i = k;
        while (i > 0 && x[i] == n - k + i) i--;
        if (i > 0) next_config(x, k, i);
        c1++;
    } while (i > 0);
}

// thuat toan A4: pp quay lui

void show(int x[]) {
    for (int i = 1; i <= k; i++) 
        cout << S[x[i] - 1] << " ";
    cout << endl;
}

void Try(int i) {
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        if (i == k) {
            c2++;
            show(x);
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    cout << "Phuong phap sinh" << endl;
    list_configs(6, 7);
    cout << "So cach lay: " << c1 << endl;

    cout << "Phuong phap sinh" << endl;
    Try(1);
    cout << "So cach lay: " << c2 << endl;
}