//Cube a variable using call-by-reference with a pointer argument

#include <stdio.h>

void cubeByReference(int *nPtr);    //prototype

int main() {
    int number = 5;
    cubeByReference(&number);

    return 0;
}

void cubeByReference(int *nPtr) {
    *nPtr = *nPtr * *nPtr * *nPtr;
}
/*
cube a variable using call-by-value

int main() {
    int number = 5;
    number = cubeByValue(number);

    return 0;
}

int cubeByValue(int n) {
    return n*n*n;
}

*/