#include "header.h"

void menu_utama(){
    int pilihan;
    do
    {
        pilihan=0;
        printf("==== MENU ====\n");
        printf("1. Tambah Tugas\n");
        printf("2. Cari Tugas\n");
        printf("3. Hapus Tugas\n");
        printf("4. Lihat Tugas Paling Mendesak\n");
        printf("5. Urutkan Tugas Berdasarkan Bobot Nilai\n");
        printf("6. Keluar\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);
        while (getchar() != '\n'); 
        switch (pilihan)
        {
        case 1:
            tambah_tugas();
            break;
        case 2:
            cari_tugas();
            break;
        case 3:
            hapus_tugas();
            break;
        case 4:
            lihat_tugas_paling_mendesak();
            break;
        case 5:
            urutkan_tugas_berdasarkan_bobot_nilai();
            break;
        case 6:
            printf("Keluar Dari Program!\n");
            break;
        default:
            printf("Input Tidak Valid!\n");
            break;
        }
    } while (pilihan != 6);
}

int main(){
    menu_utama();
    return 0;
}