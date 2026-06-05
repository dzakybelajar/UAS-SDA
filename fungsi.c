#include "header.h"

int banyak_tugas = 0;
Tugas *tugas[size_hash_table];

void tambah_tugas(){
    char nama_tugas[20];
    char nama_mapel[20];
    int bbt, tgl, bln, thn, deadline;

    printf("Masukkan nama tugas: ");
    fgets(nama_tugas, 20, stdin);
    nama_tugas[strcspn(nama_tugas,"\n")] = 0;
    printf("Masukkan nama mapel: ");
    fgets(nama_mapel, 20, stdin);
    nama_mapel[strcspn(nama_mapel,"\n")] = 0;
    printf("Masukkan bobot tugas dalam persen(tanpa tanda persen): ");
    scanf("%d", &bbt);
    printf("Masukkan deadline tugas!\n");
    printf("Tanggal(contoh: 3, 12): ");
    scanf("%d", &tgl);
    printf("Bulan(contoh: 2, 12): ");
    scanf("%d", &bln);
    printf("tahun: ");
    scanf("%d",&thn);
    deadline = thn*10000 + bln*100 + tgl;
    hash_table(nama_tugas, nama_mapel,deadline,bbt);
}

int hitung_indeks(char nama_tugas[]){
    int i = 0;
    int idx = 0;
    while (nama_tugas[i] != '\0')
    { idx += tolower(nama_tugas[i]); i++; }
    idx = idx % size_hash_table;
    return idx;
}

void hash_table(char nama_tugas[], char nama_mapel[], int ddline, int bbt){
    Tugas *newnode = (Tugas*) malloc(sizeof(Tugas));
    strcpy(newnode->nama_tugas, nama_tugas);
    strcpy(newnode->nama_mapel, nama_mapel);
    newnode->bobot = bbt;
    newnode->deadline = ddline;
     
    int indeks = hitung_indeks(nama_tugas);
    newnode->next = tugas[indeks];
    tugas[indeks] = newnode;
    banyak_tugas++; 
    printf("Tugas:%s\n", nama_tugas);
    printf("Mata pelajaran:%s\n", nama_mapel);
    printf("Berhasil ditambah!\n\n");
}

void cari_tugas(){
    char nt[20];
    int ketemu = 0;
    if (banyak_tugas == 0)
    { printf("Tidak ada tugas!\n\n"); return; }

    printf("Masukkan nama tugas: ");
    fgets(nt, 20, stdin);
    nt[strcspn(nt,"\n")] = 0;

    int indeks = hitung_indeks(nt);
    Tugas *temp1 = tugas[indeks];
    while (temp1 != NULL && strcasecmp(temp1->nama_tugas, nt) != 0)
    { temp1 = temp1->next; }
    if (temp1 != NULL && strcasecmp(temp1->nama_tugas, nt) == 0)
    { 
        int tgl = temp1->deadline % 100;
        int bln = ((temp1->deadline % 10000) - tgl) / 100;
        int thn = temp1->deadline / 10000;
        printf("Nama tugas: %s\n", temp1->nama_tugas);
        printf("Nama mata pelajaran: %s\n",temp1->nama_mapel);
        printf("Bobot: %d%%\n", temp1->bobot);
        printf("Deadline: %d-%d-%d\n\n", tgl, bln, thn);  
        ketemu = 1;
    }
    if (ketemu == 0)
    { printf("Tugas tidak ditemukan!\n\n"); }
}

void hapus_tugas(){
    char nt[20];
    int ketemu = 0;
    if (banyak_tugas == 0)
    { printf("Tidak ada tugas!\n\n"); return; }

    printf("Masukkan nama tugas:");
    fgets(nt, 20, stdin);
    nt[strcspn(nt,"\n")] = 0;

    int indeks = hitung_indeks(nt);  
    Tugas *temp1 = tugas[indeks];
    Tugas *temp2;
    while (temp1 != NULL && strcasecmp(temp1->nama_tugas, nt) != 0)
    { 
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if (temp1 != NULL && strcasecmp(temp1->nama_tugas, nt) == 0)
    {
        if (temp1 == tugas[indeks])
        {
            tugas[indeks] = temp1->next;
            free(temp1);
            ketemu = 1;
        }
        else
        {
            if (temp1->next == NULL)
            {
                temp2->next = NULL;
                free(temp1);
                ketemu = 1;
            }
            else
            {
                temp2->next = temp1->next;
                free(temp1);
                ketemu = 1;
            }
        }     
    }
    if (ketemu == 1)
    {  printf("Tugas berhasil dihapus!\n\n"); banyak_tugas--; }
    else
    { printf("Tugas tidak ditemukan!\n\n"); }
}

void tukar_tugas(Tugas **a, Tugas **b) {
    Tugas *temp = *a;
    *a = *b;
    *b = temp;
}

int partisi_bobot(Tugas **arr, int low, int high) {
    int pivot = arr[high]->bobot;
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j]->bobot >= pivot) {
            i++;
            tukar_tugas(&arr[i], &arr[j]);
        }
    }
    tukar_tugas(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort_bobot(Tugas **arr, int low, int high) {
    if (low < high) {
        int pi = partisi_bobot(arr, low, high);
        quick_sort_bobot(arr, low, pi - 1);
        quick_sort_bobot(arr, pi + 1, high);
    }
}

void urutkan_tugas_berdasarkan_bobot_nilai() {
    if (banyak_tugas == 0) {
        printf("Tidak ada tugas!\n\n");
        return;
    }
    
    Tugas *daftar[MAX_TUGAS];
    int count = 0;
    
    for (int i = 0; i < size_hash_table; i++) {
        Tugas *temp = tugas[i];
        while (temp != NULL) {
            daftar[count++] = temp;
            temp = temp->next;
        }
    }
    
    quick_sort_bobot(daftar, 0, count - 1);
    printf("\n=== Urutan tugas berdasarkan bobot tertinggi ===\n");
    for (int i = 0; i < count; i++) {
        int tgl = daftar[i]->deadline % 100;
        int bln = ((daftar[i]->deadline % 10000) - tgl) / 100;
        int thn = daftar[i]->deadline / 10000;
        printf("%d. %s - %s - bobot: %d%% - deadline: %d-%d-%d\n", i+1, 
               daftar[i]->nama_tugas, 
               daftar[i]->nama_mapel, 
               daftar[i]->bobot,
               tgl, bln, thn);
    }
    printf("\n");
}

void lihat_tugas_paling_mendesak(){
    printf("Fungsi lihat_tugas_paling_mendesak berhasil dipanggil!\n");
}
