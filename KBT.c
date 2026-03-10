#include <stdio.h> // Untuk input/output standar seperti printf dan scanf
#include <string.h> // Untuk operasi string seperti strcpy
#include <stdlib.h> // Untuk fungsi umum seperti exit

// Struktur untuk menyimpan data tiket
typedef struct {
    char nama[50];      // Nama penumpang
    char tujuan[50];    // Tujuan perjalanan
    char tanggal[20];   // Tanggal keberangkatan (format DD-MM-YYYY)
    char jam[10];       // Jam keberangkatan (format HH:MM)
    char kelas_bus[15]; // Kelas bus (Executive/Ekonomi)
    int nomor_bangku;   // Nomor bangku yang dipilih
    double harga_tiket; // Harga tiket (diasumsikan harga dasar)
} Tiket;

// Fungsi untuk membersihkan buffer input (penting setelah scanf %d)
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fungsi utama program
int main() {
    // 1. Deklarasi variabel untuk menyimpan data tiket
    Tiket tiket_penumpang;
    int pilihan_kelas; // Untuk menyimpan pilihan kelas bus (1 atau 2)
    int bangku_max;    // Batas nomor bangku berdasarkan kelas
    double harga_dasar_executive = 150000.0; // Contoh harga executive
    double harga_dasar_ekonomi = 80000.0;    // Contoh harga ekonomi

    printf("===========================================\n");
    printf("  SELAMAT DATANG DI SISTEM TIKET KBT \n");
    printf("===========================================\n\n");

    // 2. Meminta input nama user
    printf("Masukkan Nama Anda: ");
    fgets(tiket_penumpang.nama, sizeof(tiket_penumpang.nama), stdin);
    tiket_penumpang.nama[strcspn(tiket_penumpang.nama, "\n")] = 0; // Menghilangkan newline character

    // 3. Meminta input tujuan
    printf("Masukkan Tujuan Perjalanan Anda: ");
    fgets(tiket_penumpang.tujuan, sizeof(tiket_penumpang.tujuan), stdin);
    tiket_penumpang.tujuan[strcspn(tiket_penumpang.tujuan, "\n")] = 0; // Menghilangkan newline character

    // 4. Meminta input tanggal dan jam
    // Menggunakan format sederhana DD-MM-YYYY dan HH:MM
    printf("Masukkan Tanggal Keberangkatan (DD-MM-YYYY): ");
    fgets(tiket_penumpang.tanggal, sizeof(tiket_penumpang.tanggal), stdin);
    tiket_penumpang.tanggal[strcspn(tiket_penumpang.tanggal, "\n")] = 0;

    printf("Masukkan Jam Keberangkatan (HH:MM): ");
    fgets(tiket_penumpang.jam, sizeof(tiket_penumpang.jam), stdin);
    tiket_penumpang.jam[strcspn(tiket_penumpang.jam, "\n")] = 0;

    // 5. Meminta user untuk memilih kelas bus (Executive atau Ekonomi)
    do {
        printf("\n== Pilihan Kelas Bus ==\n");
        printf("1. Executive\n");
        printf("2. Ekonomi\n");
        printf("Pilih kelas bus (1/2): ");
        if (scanf("%d", &pilihan_kelas) != 1) { // Membaca input, memeriksa apakah berhasil membaca integer
            printf("Input tidak valid. Harap masukkan angka 1 atau 2.\n");
            clear_input_buffer(); // Membersihkan buffer input setelah input salah
            pilihan_kelas = 0; // Reset pilihan agar loop berulang
        } else if (pilihan_kelas < 1 || pilihan_kelas > 2) {
            printf("Pilihan tidak ada. Harap masukkan 1 untuk Executive atau 2 untuk Ekonomi.\n");
            clear_input_buffer();
        }
    } while (pilihan_kelas < 1 || pilihan_kelas > 2); // Loop akan terus berjalan selama pilihan tidak valid

    clear_input_buffer(); // Membersihkan buffer setelah scanf

    // Menentukan kelas bus dan harga tiket berdasarkan pilihan
    if (pilihan_kelas == 1) {
        strcpy(tiket_penumpang.kelas_bus, "Executive");
        bangku_max = 11;
        tiket_penumpang.harga_tiket = harga_dasar_executive;
    } else {
        strcpy(tiket_penumpang.kelas_bus, "Ekonomi");
        bangku_max = 15;
        tiket_penumpang.harga_tiket = harga_dasar_ekonomi;
    }

    // 6. Meminta user untuk memilih nomor bangku
    do {
        printf("\n== Pilihan Nomor Bangku ==\n");
        printf("Anda memilih kelas %s. Tersedia bangku 1 sampai %d.\n", tiket_penumpang.kelas_bus, bangku_max);
        printf("Pilih nomor bangku (1-%d): ", bangku_max);
        if (scanf("%d", &tiket_penumpang.nomor_bangku) != 1) { // Membaca input, memeriksa apakah berhasil membaca integer
            printf("Input tidak valid. Harap masukkan angka.\n");
            clear_input_buffer();
            tiket_penumpang.nomor_bangku = 0; // Reset agar loop berulang
        } else if (tiket_penumpang.nomor_bangku < 1 || tiket_penumpang.nomor_bangku > bangku_max) {
            printf("Nomor bangku tidak tersedia. Harap pilih antara 1 dan %d.\n", bangku_max);
            clear_input_buffer();
        }
    } while (tiket_penumpang.nomor_bangku < 1 || tiket_penumpang.nomor_bangku > bangku_max); // Loop akan terus berjalan selama nomor bangku tidak valid

    clear_input_buffer(); // Membersihkan buffer setelah scanf

    // 7. Menampilkan semua inputan sebagai tiket
    printf("\n===========================================\n");
    printf("           TIKET KOPERASI BINTANG TAPANULI         \n");
    printf("===========================================\n");
    printf(" Nama Penumpang   : %s\n", tiket_penumpang.nama);
    printf(" Tujuan           : %s\n", tiket_penumpang.tujuan);
    printf(" Tanggal          : %s\n", tiket_penumpang.tanggal);
    printf(" Jam              : %s\n", tiket_penumpang.jam);
    printf(" Kelas Bus        : %s\n", tiket_penumpang.kelas_bus);
    printf(" Nomor Bangku     : %d\n", tiket_penumpang.nomor_bangku);
    printf(" Harga Tiket      : Rp %.2f\n", tiket_penumpang.harga_tiket);
    printf("===========================================\n");
    printf(" Selamat Jalan! \n");
    printf("===========================================\n");

    return 0; // Menandakan program berakhir dengan sukses
}
