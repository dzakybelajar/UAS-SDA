#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"header.h"

typedef struct Tugas
{
    int id_tugas;
    char nama_tugas[20];
    char nama_mapel[20];
    int bobot;
    int deadline;
    struct Tugas *next;
}Tugas;

Tugas tugas[size_hash_table]; 

void tambah_tugas() {
    printf("Fungsi tambah_tugas berhasil dipanggil!\n");
}

void cari_tugas() {
    printf("Fungsi cari_tugas berhasil dipanggil!\n");
}

void hash_table() {
    // Kosongin dulu gapapa
}

void hapus_tugas() {
    printf("Fungsi hapus_tugas berhasil dipanggil!\n");
}

void lihat_tugas_paling_mendesak() {
    printf("Fungsi lihat_tugas_paling_mendesak berhasil dipanggil!\n");
}

void urutkan_tugas_berdasarkan_bobot_nilai() {
    printf("Fungsi urutkan_tugas_berdasarkan_bobot_nilai berhasil dipanggil!\n");
}