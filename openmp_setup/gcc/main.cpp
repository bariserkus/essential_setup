#include <cstdio>
#include <omp.h>

int main() {

#pragma omp parallel for default(none)
    for (int i = 0; i < 5; i++) {
    //int x[]  = {0,0,0,0,0};
        int x = 0;
        int n = 100000;
        for (int j = 0; j < n; ++j){
            x += j*i;
        }
        printf("Thread No: %i, Sum : %i\n", omp_get_thread_num(), x);
    }
    return 0;
}
