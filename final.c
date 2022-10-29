#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sales {
    int tanggal;
    int bulan;
    int tahun;
    char namaPembeli[20];
    char jenisBarang[20];
    char namaBarang[20];
    int jumlah;
    int harga;
    long long int total;
} penjualan, temp;

struct produk {
    int kode;
    int jumlah;
} tempp;

void swap(int num1, int num2, struct sales arr[]){
    temp.tanggal = arr[num1].tanggal;
    temp.bulan = arr[num1].bulan;
    temp.tahun = arr[num1].tahun;
    strcpy(temp.namaPembeli, arr[num1].namaPembeli);
    strcpy(temp.jenisBarang, arr[num1].jenisBarang);
    strcpy(temp.namaBarang, arr[num1].namaBarang);
    temp.jumlah = arr[num1].jumlah;
    temp.harga = arr[num1].harga;
    temp.total = arr[num1].total;
    arr[num1].tanggal = arr[num2].tanggal;
    arr[num1].bulan = arr[num2].bulan;
    arr[num1].tahun = arr[num2].tahun;
    strcpy(arr[num1].namaPembeli, arr[num2].namaPembeli);
    strcpy(arr[num1].jenisBarang, arr[num2].jenisBarang);
    strcpy(arr[num1].namaBarang, arr[num2].namaBarang);
    arr[num1].jumlah = arr[num2].jumlah;
    arr[num1].harga = arr[num2].harga;
    arr[num1].total = arr[num2].total;
    arr[num2].tanggal = temp.tanggal;
    arr[num2].bulan = temp.bulan;
    arr[num2].tahun = temp.tahun;
    strcpy(arr[num2].namaPembeli, temp.namaPembeli);
    strcpy(arr[num2].jenisBarang, temp.jenisBarang);
    strcpy(arr[num2].namaBarang, temp.namaBarang);
    arr[num2].jumlah = temp.jumlah;
    arr[num2].harga = temp.harga;
    arr[num2].total = temp.total;
}
//menu 2
void bubbleSort(struct sales test[], int panjang){
    for (int i = 0; i < panjang-1; i++){
        for (int j = 1; j < panjang-i; j++){
            if(test[j-1].tahun > test[j].tahun){
                swap(j-1, j, test);
            } else if(test[j-1].tahun == test[j].tahun){
                if(test[j-1].bulan > test[j].bulan){
                    swap(j-1, j, test);
                } else if(test[j-1].bulan == test[j].bulan){
                    if(test[j-1].tanggal > test[j].tanggal){
                        swap(j-1, j, test);
                    }
                }
            }
        }
    }
}
//menu 3
void bubbleSort2(struct sales test[], int panjang){
    for (int i = 0; i < panjang-1; i++){
        for (int j = 1; j < panjang-i; j++){
            if(test[j-1].jumlah < test[j].jumlah){
                swap(j-1, j, test);
            }
        }
    }
}

void QuickSort(struct produk arr[], int left, int right){
    // int temp;
    if (left < right){
        int middle = arr[(left + right) / 2].jumlah;
        int i = left - 1;
        int j = right + 1;

        while(1){
            while (arr[++i].jumlah > middle && i < right) ;//Find elements smaller than the middle value from the left
            while (arr[--j].jumlah < middle && j > 0) ;//Find elements larger than the middle value from the right

            if (i >= j)
            break;

            tempp.jumlah = arr[i].jumlah;
            tempp.kode = arr[i].kode;
            arr[i].jumlah = arr[j].jumlah;
            arr[i].kode = arr[j].kode;
            arr[j].jumlah = tempp.jumlah;
            arr[j].kode = tempp.kode;
        }
        QuickSort(arr, left, i - 1);
        QuickSort(arr, j + 1, right);
    }
}

int main(){
    int flag = 1;

    printf("---------- Groceries Sales Program ----------\n\n");
    while(flag == 1){
        int pilihan;
        printf("Pilih Menu :\n");
        printf("1. Tambah Data Penjualan\n");
        printf("2. Tampilkan Data Penjualan Berdasarkan Tanggal\n");
        printf("3. Tampilkan Data Penjualan Berdasarkan Jumlah Terjual\n");
        printf("4. Tampilkan Data Akumulasi Penjualan\n");
        printf("5. Keluar\n");
        printf("Masukkan Menu Pilihan Anda [1 / 2 / 3 / 4 / 5] : ");
        scanf("%d", &pilihan);
        if(pilihan == 1){
            FILE *fptr;
            if ((fptr = fopen("sales.txt", "a")) == NULL) {
                printf("Error!\n");
            }

            int pilihBarang, pilihJenis;
            printf("Masukkan tanggal [dd mm yyyy] : ");
            scanf("%d %d %d", &penjualan.tanggal, &penjualan.bulan, &penjualan.tahun);
            printf("Masukkan nama pembeli : ");
            scanf("%s", penjualan.namaPembeli);
            printf("Jenis :\n1. Sayur\n2. Buah\n3. Daging\n4. Rempah\n5. Minuman\n");
            printf("Masukkan nomor jenis produk yang ingin dibeli : ");
            scanf("%d", &pilihJenis);
            if(pilihJenis == 1){
                printf("Produk :\n1. Bayam\n2. Kol\n3. Kangkung\n4. Wortel\n5. Jamur\n");
                printf("Masukkan nomor produk yang ingin dibeli : ");
                scanf("%d", &pilihBarang);

                strcpy(penjualan.jenisBarang, "Sayur");
                if(pilihBarang == 1){
                    strcpy(penjualan.namaBarang, "Bayam");
                    penjualan.harga = 6000;
                } else if(pilihBarang == 2){
                    strcpy(penjualan.namaBarang, "Kol");
                    penjualan.harga = 7000;
                } else if(pilihBarang == 3){
                    strcpy(penjualan.namaBarang, "Kangkung");
                    penjualan.harga = 2500;
                } else if(pilihBarang == 4){
                    strcpy(penjualan.namaBarang, "Wortel");
                    penjualan.harga = 8000;
                } else if(pilihBarang == 5){
                    strcpy(penjualan.namaBarang, "Jamur");
                    penjualan.harga = 25000;
                }
            } else if(pilihJenis == 2){
                printf("Produk :\n1. Apel\n2. Jeruk\n3. Mangga\n4. Pepaya\n5. Semangka\n");
                printf("Masukkan nomor produk yang ingin dibeli : ");
                scanf("%d", &pilihBarang);

                strcpy(penjualan.jenisBarang, "Buah");
                if(pilihBarang == 1){
                    strcpy(penjualan.namaBarang, "Apel");
                    penjualan.harga = 20000;
                } else if(pilihBarang == 2){
                    strcpy(penjualan.namaBarang, "Jeruk");
                    penjualan.harga = 25000;
                } else if(pilihBarang == 3){
                    strcpy(penjualan.namaBarang, "Mangga");
                    penjualan.harga = 18000;
                } else if(pilihBarang == 4){
                    strcpy(penjualan.namaBarang, "Pepaya");
                    penjualan.harga = 12000;
                } else if(pilihBarang == 5){
                    strcpy(penjualan.namaBarang, "Semangka");
                    penjualan.harga = 30000;
                }
            } else if(pilihJenis == 3){
                printf("Produk :\n1. Ayam\n2. Sapi\n3. Kambing\n4. Babi\n5. Ikan\n");
                printf("Masukkan nomor produk yang ingin dibeli : ");
                scanf("%d", &pilihBarang);

                strcpy(penjualan.jenisBarang, "Daging");
                if(pilihBarang == 1){
                    strcpy(penjualan.namaBarang, "Ayam");
                    penjualan.harga = 30000;
                } else if(pilihBarang == 2){
                    strcpy(penjualan.namaBarang, "Sapi");
                    penjualan.harga = 120000;
                } else if(pilihBarang == 3){
                    strcpy(penjualan.namaBarang, "Kambing");
                    penjualan.harga = 135000;
                } else if(pilihBarang == 4){
                    strcpy(penjualan.namaBarang, "Babi");
                    penjualan.harga = 115000;
                } else if(pilihBarang == 5){
                    strcpy(penjualan.namaBarang, "Ikan");
                    penjualan.harga = 60000;
                }
            } else if(pilihJenis == 4){
                printf("Produk :\n1. Gula\n2. Garam\n3. Merica\n4. Lada\n5. Micin\n");
                printf("Masukkan nomor produk yang ingin dibeli : ");
                scanf("%d", &pilihBarang);

                strcpy(penjualan.jenisBarang, "Rempah");
                if(pilihBarang == 1){
                    strcpy(penjualan.namaBarang, "Gula");
                    penjualan.harga = 12000;
                } else if(pilihBarang == 2){
                    strcpy(penjualan.namaBarang, "Garam");
                    penjualan.harga = 5000;
                } else if(pilihBarang == 3){
                    strcpy(penjualan.namaBarang, "Merica");
                    penjualan.harga = 2000;
                } else if(pilihBarang == 4){
                    strcpy(penjualan.namaBarang, "Lada");
                    penjualan.harga = 2000;
                } else if(pilihBarang == 5){
                    strcpy(penjualan.namaBarang, "Micin");
                    penjualan.harga = 9000;
                }
            } else if(pilihJenis == 5){
                printf("Produk :\n1. Teh\n2. Kopi\n3. Susu\n4. Air\n5. Sirup\n");
                printf("Masukkan nomor produk yang ingin dibeli : ");
                scanf("%d", &pilihBarang);

                strcpy(penjualan.jenisBarang, "Minuman");
                if(pilihBarang == 1){
                    strcpy(penjualan.namaBarang, "Teh");
                    penjualan.harga = 13000;
                } else if(pilihBarang == 2){
                    strcpy(penjualan.namaBarang, "Kopi");
                    penjualan.harga = 20000;
                } else if(pilihBarang == 3){
                    strcpy(penjualan.namaBarang, "Susu");
                    penjualan.harga = 20000;
                } else if(pilihBarang == 4){
                    strcpy(penjualan.namaBarang, "Air");
                    penjualan.harga = 6000;
                } else if(pilihBarang == 5){
                    strcpy(penjualan.namaBarang, "Sirup");
                    penjualan.harga = 15000;
                }
            }
            printf("Masukkan jumlah barang : ");
            scanf("%d", &penjualan.jumlah);
            penjualan.total = penjualan.jumlah * penjualan.harga;

            if(fprintf(fptr, "%d %d %d %s %s %s %d %lld\n", penjualan.tanggal, penjualan.bulan, penjualan.tahun, penjualan.namaPembeli, penjualan.jenisBarang, penjualan.namaBarang, penjualan.jumlah, penjualan.total)){
                printf("\n-- Data Berhasil Ditambahkan --\n\n");
            } else {
                printf("\n-- Data Gagal Ditambahkan --\n\n");
            }

            fclose(fptr);
        } else if(pilihan == 2){
            struct sales jual[1000];
            int count = 0;
            FILE *fptr;
            if ((fptr = fopen("sales.txt", "r")) == NULL) {
                printf("Error!\n");
            }

            while(!(feof(fptr))){
                fscanf(fptr, "%d %d %d %s %s %s %d %lld\n", &jual[count].tanggal, &jual[count].bulan, &jual[count].tahun, jual[count].namaPembeli, jual[count].jenisBarang, jual[count].namaBarang, &jual[count].jumlah, &jual[count].total);
                count++;
            }

            bubbleSort(jual, count);
            printf("\nTanggal\t\tNama\tJenis\t\tProduk\t\tJumlah\tTotal Bayar\n");
            for (int i = 0; i < count; i++){
                if(strcmp(jual[i].namaBarang, "Kangkung") == 0 || strcmp(jual[i].namaBarang, "Semangka") == 0){
                    printf("%d/%d/%d\t%s\t%s\t\t%s\t%d\t%lld\n", jual[i].tanggal, jual[i].bulan, jual[i].tahun, jual[i].namaPembeli, jual[i].jenisBarang, jual[i].namaBarang, jual[i].jumlah, jual[i].total);
                } else {
                    printf("%d/%d/%d\t%s\t%s\t\t%s\t\t%d\t%lld\n", jual[i].tanggal, jual[i].bulan, jual[i].tahun, jual[i].namaPembeli, jual[i].jenisBarang, jual[i].namaBarang, jual[i].jumlah, jual[i].total);
                }
            }
            printf("\n");

            fclose(fptr);
        } else if(pilihan == 3){
            struct sales jual[1000];
            int count = 0;
            FILE *fptr;
            if ((fptr = fopen("sales.txt", "r")) == NULL) {
                printf("Error!\n");
            }

            while(!(feof(fptr))){
                fscanf(fptr, "%d %d %d %s %s %s %d %lld\n", &jual[count].tanggal, &jual[count].bulan, &jual[count].tahun, jual[count].namaPembeli, jual[count].jenisBarang, jual[count].namaBarang, &jual[count].jumlah, &jual[count].total);
                count++;
            }

            bubbleSort2(jual, count);
            printf("\nTanggal\t\tNama\tJenis\t\tProduk\t\tJumlah\tTotal Bayar\n");
            for (int i = 0; i < count; i++){
                if(strcmp(jual[i].namaBarang, "Kangkung") == 0 || strcmp(jual[i].namaBarang, "Semangka") == 0){
                    printf("%d/%d/%d\t%s\t%s\t\t%s\t%d\t%lld\n", jual[i].tanggal, jual[i].bulan, jual[i].tahun, jual[i].namaPembeli, jual[i].jenisBarang, jual[i].namaBarang, jual[i].jumlah, jual[i].total);
                } else {
                    printf("%d/%d/%d\t%s\t%s\t\t%s\t\t%d\t%lld\n", jual[i].tanggal, jual[i].bulan, jual[i].tahun, jual[i].namaPembeli, jual[i].jenisBarang, jual[i].namaBarang, jual[i].jumlah, jual[i].total);
                }
            }
            printf("\n");

            fclose(fptr);
        } else if(pilihan == 4){
            struct sales jual[1000];
            struct produk jumlah[25];
            int count = 0;
            FILE *fptr;
            if ((fptr = fopen("sales.txt", "r")) == NULL) {
                printf("Error!\n");
            }

            while(!(feof(fptr))){
                fscanf(fptr, "%d %d %d %s %s %s %d %lld\n", &jual[count].tanggal, &jual[count].bulan, &jual[count].tahun, jual[count].namaPembeli, jual[count].jenisBarang, jual[count].namaBarang, &jual[count].jumlah, &jual[count].total);
                count++;
            }

            for (int i = 0; i < 25; i++){
                jumlah[i].jumlah = 0;
                jumlah[i].kode = i+1;
            }

            for (int i = 0; i < count; i++){
                if((strcmp(jual[i].namaBarang, "Bayam")) == 0){
                    jumlah[0].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Kol")) == 0){
                    jumlah[1].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Kangkung")) == 0){
                    jumlah[2].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Wortel")) == 0){
                    jumlah[3].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Jamur")) == 0){
                    jumlah[4].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Apel")) == 0){
                    jumlah[5].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Jeruk")) == 0){
                    jumlah[6].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Mangga")) == 0){
                    jumlah[7].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Pepaya")) == 0){
                    jumlah[8].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Semangka")) == 0){
                    jumlah[9].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Ayam")) == 0){
                    jumlah[10].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Sapi")) == 0){
                    jumlah[11].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Kambing")) == 0){
                    jumlah[12].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Babi")) == 0){
                    jumlah[13].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Ikan")) == 0){
                    jumlah[14].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Gula")) == 0){
                    jumlah[15].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Garam")) == 0){
                    jumlah[16].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Merica")) == 0){
                    jumlah[17].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Lada")) == 0){
                    jumlah[18].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Micin")) == 0){
                    jumlah[19].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Teh")) == 0){
                    jumlah[20].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Kopi")) == 0){
                    jumlah[21].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Susu")) == 0){
                    jumlah[22].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Air")) == 0){
                    jumlah[23].jumlah += jual[i].jumlah;
                } else if((strcmp(jual[i].namaBarang, "Sirup")) == 0){
                    jumlah[24].jumlah += jual[i].jumlah;
                }
            }
            // printf("%d %d %d %d %d\n", jumlah[0].jumlah, jumlah[1].jumlah, jumlah[2].jumlah, jumlah[3].jumlah, jumlah[4].jumlah);
            
            QuickSort(jumlah, 0, 24);
            printf("\nProduk\t\tJenis\t\tJumlah Terjual\tTotal Transaksi\n");
            for (int i = 0; i < 25; i++){
                if(jumlah[i].kode == 1){
                    printf("Bayam\t\tSayur\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*6000);
                } else if(jumlah[i].kode == 2){
                    printf("Kol\t\tSayur\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*7000);
                } else if(jumlah[i].kode == 3){
                    printf("Kangkung\tSayur\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*2500);
                } else if(jumlah[i].kode == 4){
                    printf("Wortel\t\tSayur\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*8000);
                } else if(jumlah[i].kode == 5){
                    printf("Jamur\t\tSayur\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*25000);
                } else if(jumlah[i].kode == 6){
                    printf("Apel\t\tBuah\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*20000);
                } else if(jumlah[i].kode == 7){
                    printf("Jeruk\t\tBuah\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*25000);
                } else if(jumlah[i].kode == 8){
                    printf("Mangga\t\tBuah\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*18000);
                } else if(jumlah[i].kode == 9){
                    printf("Pepaya\t\tBuah\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*12000);
                } else if(jumlah[i].kode == 10){
                    printf("Semangka\tBuah\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*30000);
                } else if(jumlah[i].kode == 11){
                    printf("Ayam\t\tDaging\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*30000);
                } else if(jumlah[i].kode == 12){
                    printf("Sapi\t\tDaging\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*120000);
                } else if(jumlah[i].kode == 13){
                    printf("Kambing\t\tDaging\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*135000);
                } else if(jumlah[i].kode == 14){
                    printf("Babi\t\tDaging\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*115000);
                } else if(jumlah[i].kode == 15){
                    printf("Ikan\t\tDaging\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*60000);
                } else if(jumlah[i].kode == 16){
                    printf("Gula\t\tRempah\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*12000);
                } else if(jumlah[i].kode == 17){
                    printf("Garam\t\tRempah\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*5000);
                } else if(jumlah[i].kode == 18){
                    printf("Merica\t\tRempah\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*2000);
                } else if(jumlah[i].kode == 19){
                    printf("Lada\t\tRempah\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*2000);
                } else if(jumlah[i].kode == 20){
                    printf("Micin\t\tRempah\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*9000);
                } else if(jumlah[i].kode == 21){
                    printf("Teh\t\tMinuman\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*13000);
                } else if(jumlah[i].kode == 22){
                    printf("Kopi\t\tMinuman\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*20000);
                } else if(jumlah[i].kode == 23){
                    printf("Susu\t\tMinuman\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*20000);
                } else if(jumlah[i].kode == 24){
                    printf("Air\t\tMinuman\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*6000);
                } else if(jumlah[i].kode == 25){
                    printf("Sirup\t\tMinuman\t\t%d\t\t%d\n", jumlah[i].jumlah, jumlah[i].jumlah*15000);
                }
            }
            printf("\n");

            fclose(fptr);
        } else if(pilihan == 5){
            printf("\n--- Terima Kasih ! ---\n\n");
            flag = 0;
        }
    }

    return 0;
}
