#include <cstdio>

int main() {
#pragma omp parallel for default(none)
    for (int i = 0; i < 10; i++) {
        printf("%i\n", i);
    }
    return 0;
}