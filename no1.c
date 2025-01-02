#include <stdio.h>
#include <string.h>

// Fungsi untuk mengenkripsi string menggunakan Caesar Cipher
// yang variabel hans itu untuk indeks yang berbasis nol
int i;
void encryptString(char str[], int shift) {
    for (i = 0; str[i] != '\0'; i++) {
        char hans = str[i];
        if (hans >= 'A' && hans <= 'Z') {
            // Memproses huruf besar
            str[i] = 'A' + (hans - 'A' + shift) % 26;
        } else if (hans >= 'a' && hans <= 'z') {
            // Memproses huruf kecil
            str[i] = 'a' + (hans - 'a' + shift) % 26;
        }
        // ini untuk Karakter non-alfabet 
    }
}

int main() {
    char input[101];
    int shift;
    printf("===================Caesar Cipher=================\n");
    printf("Masukkan string (panjang 5-100 karakter): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    int length = strlen(input);
    if (length < 5 || length > 100) {
        printf("Panjang string harus antara 5 hingga 100 karakter.\n");
        return 1;
    }
    printf("Masukkan nilai shift (bilangan bulat positif): ");
    scanf("%d", &shift);
    if (shift < 0) {
        printf("Nilai shift harus positif.\n");
        return 1;
    }

    //  ini untuk Mengenkripsi stringnya
    encryptString(input, shift);

    // ini untuk  enkripsi
    printf("String terenkripsi: %s\n", input);

    return 0;
}
