#include <stdio.h>

typedef struct {
    double value;
} Data;

int main() {
    Data data;
    data.value = 42.0;
    
    printf("Host: Initial value = %f\n", data.value);
    
    #pragma acc declare create(data)
    #pragma acc update device(data)
    
    #pragma acc parallel loop
    for (int i = 0; i < 100; i++) {
        #pragma acc atomic
        data.value += 0.1;
    }
    
    #pragma acc update host(data)
    
    printf("Host: Final value = %f\n", data.value);
    
    return 0;
}
