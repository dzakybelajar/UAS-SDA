#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<ctype.h>

#define size_hash_table 13
#define MAX_TUGAS 100

typedef struct Tugas {
    char nama_tugas[20];
    char nama_mapel[20];
    float bobot;
    int deadline;
    struct Tugas *next;
} Tugas;

void menu_utama();
void tambah_tugas();
void cari_tugas();
void hapus_tugas();
void hash_table(char nama_tugas[], char nama_mapel[], int ddline, float bbt);
int hitung_indeks(char nama_tugas[]);
void lihat_tugas_paling_mendesak();
void up_heap(int idx);
void min_heap(int idx);
void hapus_di_heap(Tugas *temp);
void urutkan_tugas_berdasarkan_bobot_nilai();
void tukar_tugas(Tugas **a, Tugas **b);
int partisi_bobot(Tugas **arr, int low, int high);
void quick_sort_bobot(Tugas **arr, int low, int high);

#endif