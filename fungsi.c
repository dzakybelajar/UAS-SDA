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
