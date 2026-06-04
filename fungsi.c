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
    nama_tugas[strcspn(nama_tugas,"\n")]=0;
    printf("masukkan nama mapel:");
    fgets(nama_mapel,20,stdin);
    nama_mapel[strcspn(nama_mapel,"\n")]=0;
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
    char nt[20];
    int ketemu=0;
    if (banyak_tugas==0)
    { printf("tidak ada tugas!\n"); return; }

    printf("masukkan nama tugas:");
    fgets(nt,20,stdin);
    nt[strcspn(nt,"\n")]=0;

    for (int i = 0; i < size_hash_table; i++)
    {   
        Tugas *temp1=tugas[i];
        Tugas *temp2=temp1;
        while (temp1!=NULL && strcasecmp(temp1->nama_tugas,nt)!=0)
        { temp1=temp1->next; }

        if (temp1!=NULL && strcasecmp(temp1->nama_tugas,nt)==0)
        { 
            int tgl=temp1->deadline%100;
            int bln=temp1->deadline/100;
            printf("nama tugas: %s",temp1->nama_tugas);
            printf("nama mata pelajaran: %s",temp1->nama_mapel);
            printf("bobot: %d persen",temp1->bobot);
            printf("deadline: %d-%d",tgl,bln);  
            ketemu=1;
            break;
        }
    }

    if (ketemu==0)
    { printf("tugas tidak ditemukan!\n"); }
}

void hash_table(char nama_tugas[],char nama_mapel[],int ddline,int bbt){
    Tugas *newnode=(Tugas*) malloc(sizeof(Tugas));
    newnode->id_tugas = id;
    strcpy(newnode->nama_tugas,nama_tugas);
    strcpy(newnode->nama_mapel,nama_mapel);
    newnode->bobot=bbt;
    newnode->deadline=ddline;
     
    int indeks;
    indeks = id % size_hash_table;
    newnode->next = tugas[indeks];
    tugas[indeks] = newnode;
    banyak_tugas++; 
    printf("tugas:%s\n",nama_tugas);
    printf("mata pelajaran:%s\n",nama_mapel);
    printf("id tugas:%d\n",newnode->id_tugas);
    printf("berhasil ditambah!\n");
}

void hapus_tugas(){
    char nt[20];
    int ketemu=0;
    if (banyak_tugas==0)
    { printf("tidak ada tugas!\n"); return; }

    printf("masukkan nama tugas:");
    fgets(nt,20,stdin);
    nt[strcspn(nt,"\n")]=0;

    for (int i = 0; i < size_hash_table; i++)
    {   
        Tugas *temp1=tugas[i];
        Tugas *temp2=temp1;
        while (temp1!=NULL && strcasecmp(temp1->nama_tugas,nt)!=0)
        { 
            temp2=temp1;
            temp1=temp1->next;
        }
        if (temp1!=NULL && strcasecmp(temp1->nama_tugas,nt)==0)
        {
            if (temp1==tugas[i])
            {
                tugas[i]=temp1->next;
                free(temp1);
                ketemu=1;
                break;
            }
            else
            {
                if (temp1->next==NULL)
                {
                    temp2->next=NULL;
                    free(temp1);
                    ketemu=1;
                    break;
                }
                else
                {
                    temp2->next=temp1->next;
                    free(temp1);
                    ketemu=1;
                    break;
                }
            }     
        }
    }
    if (ketemu==1)
    {  printf("tugas berhasil dihapus!\n"); banyak_tugas--; }
    else
    { printf("tugas tidak ditemukan!\n"); }
}

void lihat_tugas_paling_mendesak(){
    printf("Fungsi lihat_tugas_paling_mendesak berhasil dipanggil!\n");
}

void urutkan_tugas_berdasarkan_bobot_nilai(){
    printf("Fungsi urutkan_tugas_berdasarkan_bobot_nilai berhasil dipanggil!\n");
}