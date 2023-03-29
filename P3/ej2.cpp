void indica_menor_mayor(int *a, int longitud, int **min, int **max){
    for (int i = 0; i < longitud; i++){
        if (*(a+i) > **max) *max = (a+i);
        else if (*(a+i) < **min) *min = (a+i);
    }

}

int main(){
    const int MAX = 21;
    int vector[MAX] = {0, 20, 10, 40, 30, -1};
    int usados = 6;

    int aux = 0;
    int *aux_min = &usados;
    int *aux_max = &aux;

    int **max = &aux_max, **min = &aux_min;

    indica_menor_mayor(vector, usados, min, max);
}