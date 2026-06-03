#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Tugas
{
    int id_tugas;
    char nama_tugas[30];
    char nama_mapel[30];
    int bobot;
    int deadline;
    Tugas *next;
}Tugas;

Tugas tugas[20];

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
        scanf("%d",&pilihan);
        while(getchar()!="\n");
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
            break;
        }
    } while (pilihan!=0);
    
}
