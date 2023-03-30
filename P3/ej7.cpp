#include <iostream>
using namespace std;

const int MAX = 21;

void multiplos (int *v, int util, int **ptr){
    int j = 0;

    for (int i = 0; i < util; i++){
        if (*(v+i) % 3 == 0){
            *(ptr+j) = (v+i);
            j++;
        }
    }

    *(ptr+j) = 0;
}

int main(){
    int v[MAX];
    int *ptrs[MAX];

    for (int i = 0; i < MAX; i++) v[i] = i+1;

    multiplos(v, MAX, ptrs);

    int pos = 0;
    while (ptrs[pos] != 0){
        cout << *(ptrs[pos]) << ", ";
        pos++;
    }
}
