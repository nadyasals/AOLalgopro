
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKINGS 100

// Struktur data pemesanan
typedef struct {
    char name[50];
    int roomNumber;
    char checkInDate[15];
    char checkOutDate[15];
} Booking;

Booking bookings[MAX_BOOKINGS];
int bookingCount = 0;

// ini tuh untuk nambah data pemesanan 
void addBooking() {
    if (bookingCount >= MAX_BOOKINGS) {
        printf("Booking penuh!\n");
        return;
    }
    printf("Nama Pemesan: ");
    scanf(" %[^\n]", bookings[bookingCount].name);
    printf("Nomor Kamar: ");
    scanf("%d", &bookings[bookingCount].roomNumber);
    printf("Tanggal Check-in (dd-mm-yyyy): ");
    scanf(" %[^\n]", bookings[bookingCount].checkInDate);
    printf("Tanggal Check-out (dd-mm-yyyy): ");
    scanf(" %[^\n]", bookings[bookingCount].checkOutDate);
    bookingCount++;
    printf("Booking berhasil ditambahkan!\n");
}

// lait data pemesanan yang telah kita lakukan 
void viewBookings() {
    if (bookingCount == 0) {
        printf("Tidak ada data pemesanan.\n");
        return;
    }
    int i,j;
    printf("\nData Pemesanan:\n");
    for (i = 0; i < bookingCount; i++) {
        printf("%d. Nama: %s, Kamar: %d, Check-in: %s, Check-out: %s\n",
               i + 1, bookings[i].name, bookings[i].roomNumber, bookings[i].checkInDate, bookings[i].checkOutDate);
    }
}

// mengurutkan data 
void sortBookings() {
	int i,j;
    for (i = 0; i < bookingCount - 1; i++) {
        for (j = 0; j < bookingCount - i - 1; j++) {
            if (strcmp(bookings[j].name, bookings[j + 1].name) > 0) {
                Booking temp = bookings[j];
                bookings[j] = bookings[j + 1];
                bookings[j + 1] = temp;
            }
        }
    }
    printf("Data berhasil diurutkan berdasarkan nama.\n");
}
// menulias data ke file di notepad
void writeToFile() {
    FILE *file = fopen("bookings.txt", "w");
    if (!file) {
        printf("Gagal membuka file untuk menulis.\n");
        return;
    }
    int i;
    for (i = 0; i < bookingCount; i++) {
        fprintf(file, "%s#%d#%s#%s\n",
                bookings[i].name,
                bookings[i].roomNumber,
                bookings[i].checkInDate,
                bookings[i].checkOutDate);
    }
    fclose(file);
    printf("Data berhasil disimpan ke file.\n");
}
// baca data dari file 
void readFromFile() {
    FILE *file = fopen("bookings.txt", "r");
    if (!file) {
        printf("File tidak ditemukan.\n");
        return;
    }
    bookingCount = 0;
    while (fscanf(file, " %[^\n] %d %[^\n] %[^\n]",
                  bookings[bookingCount].name,
                  &bookings[bookingCount].roomNumber,
                  bookings[bookingCount].checkInDate,
                  bookings[bookingCount].checkOutDate) != EOF) {
        bookingCount++;
    }
    fclose(file);
    printf("Data berhasil dibaca dari file.\n");
}

// ini untuk bikin laporan nya
void generateReport() {
    printf("\nLaporan Pemesanan:\n");
    printf("Jumlah total pemesanan: %d\n", bookingCount);
    viewBookings();
}
// Menghapus pemesanan berdasarkan nomor urut
void deleteBooking() {
    int index;
    printf("Masukkan nomor pemesanan yang ingin dihapus: ");
    scanf("%d", &index);
    
    if (index < 1 || index > bookingCount) {
        printf("Pemesanan tidak ditemukan.\n");
        return;
    }
    
    for (int i = index - 1; i < bookingCount - 1; i++) {
        bookings[i] = bookings[i + 1];
    }
    bookingCount--;
    printf("Pemesanan berhasil dihapus.\n");
}

// Menampilkan kamar yang tersedia
void showAvailableRooms() {
    int available[MAX_BOOKINGS] = {0};
    
    for (int i = 0; i < bookingCount; i++) {
        available[bookings[i].roomNumber - 1] = 1;
    }
    
    printf("Kamar yang tersedia:\n");
    for (int i = 0; i < MAX_BOOKINGS; i++) {
        if (!available[i]) {
            printf("Kamar %d tersedia.\n", i + 1);
        }
    }
}

// Update data pemesanan
void updateBooking() {
    int index;
    printf("Masukkan nomor pemesanan yang ingin diupdate: ");
    scanf("%d", &index);
    
    if (index < 1 || index > bookingCount) {
        printf("Pemesanan tidak ditemukan.\n");
        return;
    }
    
    printf("Masukkan nama baru: ");
    scanf(" %[^\n]", bookings[index - 1].name);
    printf("Masukkan nomor kamar baru: ");
    scanf("%d", &bookings[index - 1].roomNumber);
    printf("Masukkan tanggal check-in baru (dd-mm-yyyy): ");
    scanf(" %[^\n]", bookings[index - 1].checkInDate);
    printf("Masukkan tanggal check-out baru (dd-mm-yyyy): ");
    scanf(" %[^\n]", bookings[index - 1].checkOutDate);
    
    printf("Pemesanan berhasil diupdate.\n");
}

int main() {
    int choice;
    do {
        printf("\n=== Room Booking System ===\n");
        printf("1. Tambah Pemesanan\n");
        printf("2. Lihat Pemesanan\n");
        printf("3. Urutkan Pemesanan (Nama)\n");
        printf("4. Simpan Data ke File\n");
        printf("5. Baca Data dari File\n");
        printf("6. Buat Laporan\n");
        printf("7. Hapus Pemesanan\n");
        printf("8. Tampilkan Kamar Tersedia\n");
        printf("9. Update Pemesanan\n");
        printf("0. Keluar\n");
        printf("Pilih menu:\n ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBooking(); break;
            case 2: viewBookings(); break;
            case 3: sortBookings(); break;
            case 4: writeToFile(); break;
            case 5: readFromFile(); break;
            case 6: generateReport(); break;
            case 7: deleteBooking(); break;
            case 8: showAvailableRooms(); break;
            case 9: updateBooking(); break;
            case 0:  printf("Terima kasih telah menggunakan jasa Room Booking System kami Love  You\n");
                break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while (choice != 0);

    return 0;
}
