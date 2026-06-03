#include<stdio.h>
#include"header.h"

void menu_utama(){
    int pilihan;
    do
    {
        pilihan=0;
        printf("====menu====\n");
        printf("1.Tambah tugas\n");
        printf("2.Cari tugas\n");
        printf("3.Hapus tugas\n");
        printf("4.Lihat tugas paling mendesak\n");
        printf("5.Urutkan tugas berdasarkan bobot nilai\n");
        printf("pilih menu:");
        if (scanf("%d",&pilihan)!=1)
        { pilihan=0; }
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
        default:
            printf("input tidak valid!\n");
            break;
        }
    } while (pilihan!=0);
}

int main(){
    menu_utama();
    return 0;
}