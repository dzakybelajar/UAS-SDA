#include "header.h"

void menu_utama(){
    int pilihan;
    do
    {
        pilihan=0;
        printf("==== MENU ====\n");
        printf("1. Tambah tugas\n");
        printf("2. Cari tugas\n");
        printf("3. Hapus tugas\n");
        printf("4. Lihat tugas paling mendesak\n");
        printf("5. Urutkan tugas berdasarkan bobot nilai\n");
        printf("6. Keluar\n");
        printf("Pilih menu: ");
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
            printf("keluar dari program!\n");
            break;
        default:
            printf("input tidak valid!\n");
            break;
        }
    } while (pilihan != 6);
}

int main(){
    menu_utama();
    return 0;
}