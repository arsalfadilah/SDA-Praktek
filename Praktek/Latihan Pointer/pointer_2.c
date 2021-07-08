#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mahasiswa{
	int nim; //menampung integer nim mahasiswa
	char nama[30]; //menampung karakter nama mahasiswa
	struct mahasiswa *next; //menampung alamat data selanjutnya
}*head, *tail, *current;
//head => pointer yang menyimpan alamat data pertama
//tail => pointer yang menyimpan alamat data terakhir
//current => pointer yang digunakan sebagai temporary variabel

void pushHead(int nim, char nama[]){
    //alokasi memory untuk data baru
	current = (struct mahasiswa*)malloc(sizeof(struct mahasiswa));
	current->nim = nim; //assign data ke dalam struct
	strcpy(current->nama, nama); //copy nilai variabel parameter nama ke current->nama

	if(head == NULL){ //jika nilai head adalah null, maka set head = tail = current
		head = tail = current; //set nilai head = tail = current
	}
	else{ //jika nilai head tidak null, maka
		current->next = head; //set nilai current->next = head
		head = current; //kemudian set nilai head = current
	}
}

void pushTail(int nim, char nama[]){
	current = (struct mahasiswa*)malloc(sizeof(struct mahasiswa)); //alokasi memory untuk data baru
	current->nim = nim;//assign data ke dalam struct
	strcpy(current->nama, nama); //copy nilai variabel parameter nama ke current->nama

	if(head == NULL){ //jika nilai head adalah null, maka set head = tail = current
		head = tail = current; //set nilai head = tail = current
	}
	else{ //jika nilai head tidak null, maka
		tail->next = current; //set nilai tail->next = current
		tail = current; //kemudian set nilai tail = current
	}
	tail->next = NULL; //kemudian set nilai tail menjadi null
}

void popHead(){
	current=head; //set nilai current sebagai head
	if(head==NULL){ //jika head bernilai null
		printf("No data"); //tampilkan info tidak ada data
	}else if(head==tail){ //jika nilai head = tail
		head=tail=NULL; //set nilai head = tail = null
		free(current); //hapus nilai current (head)
	}else{ //jika nilai head bukan null dan bukan tail
		head=head->next; //set nilai head menjadi data selanjutnya dari head
		free(current);// hapus nilai current (head)
	}
}

void popTail(){
	if(head==NULL){ //jika nilai head = null
		printf("No data"); //tampilkan info tidak ada data
	}else if(head==tail){ //jika nilai head = tail
		head=tail=NULL; //set nilai head = tail = null
		free(current); //hapus nilai current
	}else{ //jika nilai head bukan null dan bukan tail
		struct mahasiswa *temp=head; //buat variabel penampung baru dan assign/beri nilai mulai dari head
		while(temp->next!=tail){ //looping untuk mencari posisi 1 data sebelum tail
			temp=temp->next; //set nilai temp menjadi 1 data setelahnya
		}
		current=tail; //set nilai current menjadi tail
		tail=temp; //set nilai tail menjadi 1 data sebelum tail (hasil looping)
		free(current); //hapus nilai current
		tail->next=NULL; //set nilai setelah next menjadi null/pointer next punya tail diset null
	}
}

void print(){
	current = head; //set current sebagai head
	while(current != NULL){ //looping selama current bukan null
		printf("%s -> %d\n",current->nama,current->nim); //tampilkan nilai nama dan nim
		current = current->next; //set current menjadi nilai setelahnya
	}
}

int main(){
    int jumlah, i, nim;
    char nama[15], hapustambah, pilihan, lagi;
    awal:
    system("clear");
    printf("Masukkan Jumlah Data: "); scanf("%d", &jumlah);
    for(i=1; i<=jumlah; i++){
        printf("Masukkan data ke %d: \n", i);
        printf("Nama: "); scanf("%s", nama);
        printf("NIM: "); scanf("%d", &nim);
        if(i == 1){
            pushHead(nim, nama);
        } else{
            printf("Masukkan data ke Depan atau Belakang? (d untuk depan, b untuk belakang): ");
            scanf("%s", &pilihan);
            if(pilihan == 'd'){
                pushHead(nim, nama);
            } else{
                pushTail(nim, nama);
            }
        }
    }
    print();
    printf("Mau Menghapus atau Menambah Data? (y untuk nambah, n untuk hapus) ");
    scanf("%s", &hapustambah);
    if(hapustambah == 'y'){
        printf("Nama: "); scanf("%s", nama);
        printf("NIM: "); scanf("%d", &nim);
        printf("Masukkan data ke Depan atau Belakang? (d untuk depan, b untuk belakang): ");
        scanf("%s", &pilihan);
        if(pilihan == 'd'){
            pushHead(nim, nama);
        } else{
            pushTail(nim, nama);
        }
    } else{
        printf("Hapus Depan atau Belakang? (d untuk depan, b untuk belakang) ");
        scanf("%s", &pilihan);
        if(pilihan == 'd'){
            popHead();
        } else{
            popTail();
        }
    }

    print();
    printf("Mau Menambah Data? (y untuk nambah, n untuk tidak) ");
    scanf("%s", &lagi);
    if(lagi == 'y'){
        goto awal;
    } else{
        goto akhir;
    }
    akhir:
	getchar();
	return 0;
}
