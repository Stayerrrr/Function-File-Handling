#include <stdio.h>

void cek(int a){
    if (a % 2 == 0) {
        printf("Ini adalah bilangan genap \n");
    } else {
        printf("Ini adalah bilangan ganjil \n");
    }

}

void main () {
    int angka;
    
    printf("Masukkan angka: ");
    scanf("%d", &angka);
    cek(angka);
}