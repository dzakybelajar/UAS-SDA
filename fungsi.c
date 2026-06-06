#include "header.h"

int banyak_tugas = 0;
int heap = 0;
Tugas *tugas[size_hash_table];
Tugas *arr_heap[MAX_TUGAS];

void tambah_tugas(){
    char nama_tugas[20];
    char nama_mapel[20];
    int bbt, tgl, bln, thn, deadline;

    printf("Masukkan Nama Tugas: ");
    fgets(nama_tugas, 20, stdin);
    nama_tugas[strcspn(nama_tugas,"\n")] = 0;
    printf("Masukkan Nama Mata Kuliah: ");
    fgets(nama_mapel, 20, stdin);
    nama_mapel[strcspn(nama_mapel,"\n")] = 0;
    printf("Masukkan Bobot Tugas Dalam Persen (tanpa tanda persen): ");
    scanf("%d", &bbt);
    printf("Masukkan Deadline Tugas!\n");
    printf("Tanggal: ");
    scanf("%d", &tgl);
    printf("Bulan: ");
    scanf("%d", &bln);
    printf("Tahun: ");
    scanf("%d", &thn);
    deadline = thn * 10000 + bln * 100 + tgl;
    hash_table(nama_tugas, nama_mapel, deadline, bbt);
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

    arr_heap[banyak_tugas] = newnode;
    up_heap(banyak_tugas);

    banyak_tugas++; 
    printf("Tugas:  %s\n", nama_tugas);
    printf("Mata Kuliah: %s\n", nama_mapel);
    printf("Berhasil Ditambah!\n\n");
}

void cari_tugas(){
    char nt[20];
    int ketemu = 0;
    if (banyak_tugas == 0)
    { printf("Tidak Ada Tugas!\n\n"); return; }

    printf("Masukkan Nama Tugas: ");
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
        printf("Nama Tugas: %s\n", temp1->nama_tugas);
        printf("Nama Mata Kuliah: %s\n",temp1->nama_mapel);
        printf("Bobot: %d%%\n", temp1->bobot);
        printf("Deadline: %d-%d-%d\n\n", tgl, bln, thn);  
        ketemu = 1;
    }
    if (ketemu == 0)
    { printf("Tugas Tidak Ditemukan!\n\n"); }
}

void hapus_tugas(){
    char nt[20];
    int ketemu = 0;
    if (banyak_tugas == 0)
    { printf("Tidak Ada Tugas!\n\n"); return; }

    printf("Masukkan Nama Tugas: ");
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
        hapus_di_heap(temp1);
        if (temp1 == tugas[indeks])
        {
            tugas[indeks] = temp1->next;
            free(temp1);
            ketemu = 1;
        }
        else
        {
            if (temp1->next == NULL) { temp2->next = NULL; }
            else { temp2->next = temp1->next; }
            free(temp1);
            ketemu = 1;
        }     
    }
    if (ketemu == 1)
    {  printf("Tugas Berhasil Dihapus!\n\n"); banyak_tugas--; }
    else
    { printf("Tugas Tidak Ditemukan!\n\n"); }
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
        printf("Tidak Ada Tugas!\n\n");
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
    printf("\n=== Urutan Tugas Berdasarkan Bobot Tertinggi ===\n");
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

void hapus_di_heap(Tugas *temp){
    int idx = -1;
    for (idx = 0; idx < banyak_tugas; idx++)
    { if (strcasecmp(arr_heap[idx]->nama_tugas, temp->nama_tugas) == 0){ break; } }

    if (idx != -1)
    {
        arr_heap[idx] = arr_heap[banyak_tugas - 1];
        arr_heap[banyak_tugas - 1] = NULL;
        if (idx != banyak_tugas - 1)
        { 
            up_heap(idx);
            min_heap(idx); 
        }
    }
}

void up_heap(int idx){
    if (banyak_tugas == 0)
    { return; }

    int parent = (idx - 1) / 2;
    Tugas *temp;
    while (idx > 0 && arr_heap[idx]->deadline < arr_heap[parent]->deadline)
    {
        temp = arr_heap[parent];
        arr_heap[parent] = arr_heap[idx];
        arr_heap[idx] = temp;
        idx = parent;
        parent = (parent - 1) / 2;
    }
}

void min_heap(int idx){
    int left_child = 2*idx + 1;
    int right_child = 2*idx + 2;
    int min = idx;
    int ada = 1;
    Tugas *temp;
   while (ada)
   {    
        if (left_child < banyak_tugas && arr_heap[left_child] != NULL) 
        {
            if (arr_heap[left_child]->deadline < arr_heap[min]->deadline) 
            { min = left_child; }
        }
        if (right_child < banyak_tugas && arr_heap[right_child] != NULL) 
        {
            if (arr_heap[right_child]->deadline < arr_heap[min]->deadline) 
            { min = right_child; }
        }
        if (min != idx) 
        {
            temp = arr_heap[idx];
            arr_heap[idx] = arr_heap[min];
            arr_heap[min] = temp;
            idx = min; 
            left_child = 2*idx + 1;
            right_child = 2*idx +2;
        } 
        else { ada = 0; }   
   }
}

void lihat_tugas_paling_mendesak(){
    if (banyak_tugas == 0)
    { printf("Tidak Ada Tugas!\n"); return; }

    int tgl = arr_heap[0]->deadline % 100;
    int bln = ((arr_heap[0]->deadline % 10000) - tgl) / 100;
    int thn = arr_heap[0]->deadline / 10000;
    printf("=== Tugas Yang Paling Mendesak ===\n");
    printf("Nama Tugas: %s\n", arr_heap[0]->nama_tugas);
    printf("Nama Mapel: %s\n", arr_heap[0]->nama_mapel);
    printf("Bobot: %d%%\n", arr_heap[0]->bobot);
    printf("Deadline: %d-%d-%d\n\n", tgl, bln, thn);
}
