#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int banyak_tugas=0;
int id=0;

Tugas *tugas[size_hash_table]; 

void tambah_tugas(){
    char nama_tugas[20];
    char nama_mapel[20];
    int bbt, tgl, bln, deadline;
    printf("masukkan nama tugas:");
    fgets(nama_tugas,20,stdin);
    printf("masukkan nama mapel:");
    fgets(nama_mapel,20,stdin);
    printf("masukkan bobot tugas dalam persen(tanpa tanda persen):");
    scanf("%d",&bbt);
    printf("masukkan deadline tugas!\n");
    printf("tanggal(contoh: 3, 12):");
    scanf("%d",&tgl);
    printf("bulan(contoh: 2, 12):");
    scanf("%d",&bln);
    deadline = bln*100 + tgl;
    id++;
    hash_table(nama_tugas,nama_mapel,deadline,bbt);
}

void cari_tugas(){
    printf("Fungsi cari_tugas berhasil dipanggil!\n");
}

void hash_table(char nama_tugas[],char nama_mapel[],int ddline,int bbt){
    int indeks;
    indeks = id % size_hash_table;
    while (tugas[indeks]!=NULL)
    { tugas[indeks]=tugas[indeks]->next; }
    tugas[indeks]->id_tugas = id;
    strcpy(tugas[indeks]->nama_tugas,nama_tugas);
    strcpy(tugas[indeks]->nama_mapel,nama_mapel);
    tugas[indeks]->bobot=bbt;
    tugas[indeks]->deadline=ddline;
}

void hapus_tugas(){
    printf("Fungsi hapus_tugas berhasil dipanggil!\n");
}

void lihat_tugas_paling_mendesak(){
    printf("Fungsi lihat_tugas_paling_mendesak berhasil dipanggil!\n");
}

void urutkan_tugas_berdasarkan_bobot_nilai(){
    printf("Fungsi urutkan_tugas_berdasarkan_bobot_nilai berhasil dipanggil!\n");
}