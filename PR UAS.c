#include <stdio.h>
#include <string.h>

struct biodata{
    char uname[100], pass[100], nama[100], alamat[100], tel[100], idline[100];
} a;

FILE *fp;
FILE *fp2;
char cari[100];
void tulis();
void tambah();
void ubah();
void hapus();
void lihat();
main()
{
	system("cls");
	int pilih;
	printf("===M E N U===\n\n");
	printf("1. Tulis \n");
	printf("2. Tambah \n");
	printf("3. Ubah \n");
	printf("4. Hapus \n");
	printf("5. Lihat \n");
	printf("6. EXIT\n");
	printf("Pilih Menu: "); scanf("%d",&pilih);

	switch(pilih)
	{
		case 1:{ tulis();
			break;
		}
		case 2:{ tambah();
			break;
		}
		case 3:{ ubah();
			break;
		}
		case 4:{ hapus();
			break;
		}
		case 5:{ lihat();
            break;
		}
		case 6:{ printf("\nTERIMA KASIH!!!\n "); break;
		}
		default:{ getchar();
		    printf("\nPilihan Tidak Ada!!!!!!!!\n"); getchar(); main();
	}
	return 0;
	}
}

void tulis()
{
	system("cls");
	fp=fopen("tugas uas.dat","w");
	getchar();
	printf("Username   : "); gets(a.uname);
	printf("Password   : "); gets(a.pass);
	printf("Nama       : "); gets(a.nama);
	printf("Alamat     : "); gets(a.alamat);
	printf("No HP      : "); gets(a.tel);
	printf("Id Line    : "); gets(a.idline);

	fwrite(&a, sizeof(a), 1, fp);
	fclose(fp);
	main();
}
void tambah()
{
    system("cls");
    fp=fopen("tugas uas.dat","ab");
    getchar();
	printf("Username   : "); gets(a.uname);
	printf("Password   : "); gets(a.pass);
	printf("Nama       : "); gets(a.nama);
	printf("Alamat     : "); gets(a.alamat);
	printf("No HP      : "); gets(a.tel);
	printf("Id Line    : "); gets(a.idline);

	fwrite(&a, sizeof(a), 1, fp);
	fclose(fp);
	main();
}

void ubah()
{
	char edit[50];
	FILE *fp;
	fp = fopen("tugas uas.dat","rb+");
	printf("EDIT USER\n");
	getchar();
	printf("Data yang ingin di edit [NAMA]: "); gets(edit);
	while(fread(&a,sizeof(a),1,fp)==1){
		if(strcmp(edit,a.nama)==0){
			printf("Username : %s\n",a.uname);
			printf("Password : %s\n", a.pass);
			printf("Nama     : %s\n", a.nama);
			printf("Alamat   : %s\n", a.alamat);
			printf("No HP    : %s\n", a.tel);
			printf("Id Line  : %s\n", a.idline);
			printf("\n");

			fseek(fp, (long)-sizeof(a), SEEK_CUR);
			printf("EDIT\n");
			printf("Username   : "); gets(a.uname);
			printf("Password   : "); gets(a.pass);
			printf("Nama       : "); gets(a.nama);
			printf("Alamat     : "); gets(a.alamat);
			printf("No HP      : "); gets(a.tel);
			printf("Id Line    : "); gets(a.idline);
			fwrite(&a,sizeof(a),1,fp);
			fseek(fp, 0, SEEK_CUR);
		}
	}
	fclose(fp);
	printf("Tekan ENTER untuk kembali ke menu"); getchar();
    system ("cls");
	main();
}

void hapus()
{
	fp= fopen("tugas uas.dat", "rb");
	fp2= fopen("tugas uas2.dat", "wb");
	getchar();
	printf("Silahkan masukkan username yang akan dihapus: ");
	gets(cari);
	while (fread(&a,sizeof (a),1, fp)==1)
	{
		if (strcmp(a.uname, cari)!=0)
		{
			fwrite(&a, sizeof(a), 1, fp2);
		}
	}

	fclose(fp);
	fclose(fp2);
	remove("tugas uas.dat");
	rename("tugas uas2.dat","tugas uas.dat");
main();
}

void lihat()
{
    system("cls");
	fp = fopen("tugas uas.dat","rb");
	printf("\nLIST Biodata\n");
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		printf("Username : %s\n", a.uname);
		printf("Password : %s\n", a.pass);
		printf("Nama     : %s\n", a.nama);
		printf("Alamat   : %s\n", a.alamat);
		printf("No telp  : %s\n", a.tel);
		printf("Id Line  : %s\n", a.idline);
		printf("\n");
	}
	fclose(fp);
	printf("Tekan ENTER untuk kembali ke menu"); getch();
	system ("cls");
	main();
}
