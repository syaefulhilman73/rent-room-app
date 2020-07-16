#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user{
	char uname[100], pass[100], nama[100], alamat[100], tel[100];
	int log1,log2,log3;
}reg,mas;

struct mesage{
	char pesan[100];
}mes[100];

struct log{
	char uname[100], pass[100];
}a;

char uss[100], pws[100];
int i;
char cari[100], app1, app2, app3;
FILE *fp, *fp2, *pesan, *pak;
void check();
void logi();
void pelanggan();
void admin();
void paket();
void tulpes();
void bapes();
void menuadmin();
void mana();
void regi();
void edus();
void listpelanggan();
void hapus();
void acc();
void approve();

int pilih;
int main()
{getchar();
	system("cls");
	printf("Daskom Insurance Corp\n");
	printf("Menu: \n");
	printf("1. Pengunjung\n");
	printf("2. Pelanggan\n");
	printf("3. Admin\n");
	printf("4. Exit\n");
	printf("Pilih Menu (1/2/3/4): ");
	scanf("%d",&pilih);getchar();
	switch(pilih)
	{
		case 1: system("cls");
				printf("\nAnda Masuk sebagai Pengunjung\n");
				printf("\nDaskom Insurance adalah sebuah laboratorium di Telkom University");
				printf("\nyang menyediakan beberapa layanan asuransi, walaupun masih dalam");
				printf("\nlingkungan kampus, kami sudah bekerja secara proffesional dan   ");
				printf("\nkami bukanlah asuransi abal abal seperti di insert investigasi  "); getchar();
				break;
		case 2: logi();
				break;
		case 3: admin();
				break;
		case 4: system("pause"); break;
		default:printf("Pilihan Tidak Ada"); getchar(); break;
	}
	if (pilih!=4)
	{
		main();
	}

	return 0;
}

void logi()
{
	int pilih;
	system("cls");
	fp = fopen("user.dat","rb+");
	printf("Silahkan Login dengan menggunakan akun anda\n");
	getchar();
	printf("Username: "); gets(uss);
	printf("Password: "); gets(pws);
	while(fread(&reg, sizeof(reg), 1, fp)==1)
	{
		if(strcmp(uss, reg.uname)==0 && strcmp(pws, reg.pass)==0)
		{
			system("cls");
			printf("\nAnda telah berhasil masuk sebagai pelanggan\n");
			printf("Silahkan Tekan ENTER untuk melanjutkan"); getchar();
			pelanggan();
			break;
		}
	}
	if(strcmp(uss, reg.uname)==0 && strcmp(pws, reg.pass)!=0)
	{
		printf("\nUsername atau Password Salah...");
	}
	fclose(fp);
	printf("\n");
	system("pause");
}

void pelanggan()
{
	int pilih;
	system("cls");
	printf("Menu: \n");
	printf("1. Lihat pilihan packet\n");
	printf("2. Kirim pesan ke admin\n");
	printf("3. Check approve");
	printf("4. Logout");
	printf("\nPilih Menu: "); scanf("%d",&pilih);getchar();
	switch(pilih)
	{
		case 1:{ paket();
			break;
		}
		case 2:{ tulpes();
			break;
		}
		case 3: { check();
			break;
		}
		case 4: {

			break;
		}
		default: printf("Pilihan tidak tersedia"); getch();
	}
	if (pilih!=4)
		pelanggan();
}

void check()
{
	int p;
	system("cls");
	printf("- CHECK ASURANSI -\n\n");
	printf("1. Asuransi Pendidikan\n");
	printf("2. Asuransi Jiwa dan Kesehatan\n");
	printf("3. Asuransi Kendaraan\n\n");
	printf("Ingin Check Approval Asuransi Mana  : "); scanf("%d", &p); getchar();
	if (p==1)
	{
		if (reg.log1==0)
			printf("\nAnda Belum Memilih Asuransi Ini...");
		else if (reg.log1==1)
			printf("\nTunggu Admin Memproses Asuransi Ini...");
		else if (reg.log1==2)
			printf("\nAsuransi Pendidikan Anda Disetujui...");
		else if (reg.log1==3)
			printf("\nAsuransi Pendidikan Anda Ditolak...");
	}
	else if (p==2)
	{
		if (reg.log2==0)
			printf("\nAnda Belum Memilih Asuransi Ini...");
		else if (reg.log2==1)
			printf("\nTunggu Admin Memproses Asuransi Ini...");
		else if (reg.log2==2)
			printf("\nAsuransi Jiwa dan Kesehatan Anda Disetujui...");
		else if (reg.log2==3)
			printf("\nAsuransi Jiwa dan Kesehatan Anda Ditolak...");
	}
	else if (p==3)
	{
		if (reg.log3==0)
			printf("\nAnda Belum Memilih Asuransi Ini...");
		else if (reg.log3==1)
			printf("\nTunggu Admin Memproses Asuransi Ini...");
		else if (reg.log3==2)
			printf("\nAsuransi Kendaraan Anda Disetujui...");
		else if (reg.log3==3)
			printf("\nAsuransi Kendaraan Anda Ditolak...");
	}
	printf("\n\n");
	system("pause");
}

void paket()
{
	int pilih2;
	system("cls");
	printf("Silahkan pilih menu asuransi yang diinginkan:\n");
	printf("1. Asuransi Pendidikan\n");
	printf("2. Asuransi Kesehatan dan Jiwa\n");
	printf("3. Asuransi Kendaraan\n");
	printf("4. Kembali\n");
	printf("\nPilih Menu: "); scanf("%d",&pilih2);getchar();
	fseek(fp, -sizeof(reg), SEEK_CUR);
	switch(pilih2)
	{
		case 1: printf("Anda memilih Asuransi Pendidikan");
				reg.log1=1;
				break;
		case 2: printf("Anda memilih Asuransi Jiwa dan Kesehatan");
				reg.log2=1;
				break;
		case 3: printf("Anda memilih Asuransi Kendaraan");
			    reg.log3=1;
				break;
		case 4: break;
		default: printf("Pilihan Tidak Ada"); break;
	}
	fwrite(&reg, sizeof(reg), 1, fp);
	fclose(fp);
	fp = fopen("user.dat","rb+");
	while(fread(&reg, sizeof(reg), 1, fp)==1)
	{
		if(strcmp(uss, reg.uname)==0 && strcmp(pws, reg.pass)==0)
		{
			break;
		}
	}
	system("pause");
	if (pilih2!=4)
		paket();
}

void tulpes()
{
	pesan=fopen("pesan.dat","ab");
	getchar();
	printf("SIlahken ketikan pesan:\n "); gets(mes[i].pesan);
	fwrite(&mes[i], sizeof(mes[i]), 1, pesan);
	fclose(pesan);
	fclose(fp);
}

void admin()
{
	int pilih;
	system("cls");
	printf("Silahkan login terlebih dahulu\n");
	printf("Username: "); scanf("%s",a.uname);
	printf("Password: "); scanf("%s",a.pass);
	if (strcmp(a.uname,"admin")==0 && strcmp(a.pass,"admin")==0)
	{
		system("cls");
		printf("Login Sebagai Admin Berhasil\n");
		printf("silahkan tekan ENTER untuk melanjutkan");
		getch();
		menuadmin();

	}
}

void menuadmin()
{
	int pilih;
	getchar();
	system("cls");
	printf("Menu: \n");
	printf("1. User management\n");
	printf("2. Lihat pesan\n");
	printf("3. approve\n");
	printf("Pilih Menu: "); scanf("%d",&pilih);getchar();
	switch(pilih)
	{
		case 1:{ mana();
			break;
		}
		case 2:{ bapes();
			break;
		}
		case 3:{ approve();
			break;
		}
	}
}
void approve()
{
	printf("Masukkan nama user yang ingin di approve : ");
	gets(cari);
	fp=fopen("user.dat","rb+");
	while(fread(&reg, sizeof(reg), 1, fp)==1)
	{
		if(strcmp(cari,reg.uname)==0)
		{
			fseek(fp, -sizeof(reg), SEEK_CUR);
			printf("\nUser Ditemukan!!");
			printf("\nUsername   : %s\n",reg.uname);
			printf("\nPassword   : %s\n",reg.pass);
			printf("\nNama       : %s\n",reg.nama);
			printf("\nAlamat     : %s\n",reg.alamat);
			printf("\nNo HP      : %s\n",reg.tel);
			if (reg.log1==1)
			{
				printf("\nPersetujuan asuransi pendidikan apakah mau di approve?(y/n) ");scanf("%c", &app1);getchar();
				if (app1=='y')
					reg.log1 = 2;
				else
					reg.log1 = 3;
			}
			if (reg.log2==1)
			{
				printf("\nPersetujuan asuransi jiwa dan kesehatan apakah mau di approve?(y/n) ");scanf("%c", &app2);getchar();
				if (app2=='y')
					reg.log2 = 2;
				else
					reg.log2 = 3;
			}
			if (reg.log3==1)
			{
				printf("\nPersetujuan asuransi kendaraan apakah mau di approve?(y/n) ");scanf("%c", &app3);getchar();
				if (app3=='y')
					reg.log3 = 2;
				else
					reg.log3 = 3;
			}
			fwrite(&reg, sizeof(reg), 1, fp);
			break;
		}
	}
	if (strcmp(cari,reg.uname)!=0)
	{
		printf("\nUsername Tidak Ditemukan");
	}
	fclose(fp);
	system("pause");
}
void mana()
{
	system("cls");
	int pilih;
	printf("\nUser Management\n\n");
	printf("1. Create user\n");
	printf("2. Edit user\n");
	printf("3. Delete user\n");
	printf("4. Liat user\n");
	printf("Pilih Menu: "); scanf("%d",&pilih);

	switch(pilih)
	{
		case 1:{ regi();
			break;
		}
		case 2:{ edus();
			break;
		}
		case 3:{ hapus();
			break;
		}
		case 4:{ listpelanggan();
			break;
		}
	}
}

void regi()
{
	system("cls");
	fp=fopen("user.dat","ab");
	getchar();
	printf("Username   : "); gets(reg.uname);
	printf("Password   : "); gets(reg.pass);
	printf("Nama       : "); gets(reg.nama);
	printf("Alamat     : "); gets(reg.alamat);
	printf("No HP      : "); gets(reg.tel);
	reg.log1 = 0;
	reg.log2 = 0;
	reg.log3 = 0;
	fwrite(&reg, sizeof(reg), 1, fp);
	fclose(fp);
	main();
}

void edus()
{
	char edit[50];
	FILE *fp;
	fp = fopen("user.dat","rb+");
	printf("EDIT USER\n");
	getchar();
	printf("Data yang ingin di edit [NAMA}: "); gets(edit);
	while(fread(&reg,sizeof(reg),1,fp)==1){
		if(strcmp(edit,reg.nama)==0){
			printf("Username : %s\n",reg.uname);
			printf("Password : %s\n", reg.pass);
			printf("Nama     : %s\n", reg.nama);
			printf("Alamat   : %s\n", reg.alamat);
			printf("No HP    : %s\n", reg.tel);
			printf("\n");

			fseek(fp, (long)-sizeof(reg), SEEK_CUR);
			printf("EDIT\n");
			printf("Username   : "); gets(reg.uname);
			printf("Password   : "); gets(reg.pass);
			printf("Nama       : "); gets(reg.nama);
			printf("Alamat     : "); gets(reg.alamat);
			printf("No HP      : "); gets(reg.tel);
			fwrite(&reg,sizeof(reg),1,fp);
			fseek(fp, 0L, SEEK_CUR);
		}
	}
	fclose(fp);
	printf("Tekan ENTER untuk kembali ke management user"); getchar();
    system ("cls");
	mana();
}

void hapus()
{
	fp= fopen("user.dat", "rb");
	fp2= fopen("user2.dat", "wb");
	getchar();
	printf("Silahkan masukkan username yang akan dihapus: ");
	gets(cari);
	while (fread(&reg,sizeof (reg),1, fp)==1)
	{
		if (strcmp(reg.uname, cari)!=0)
		{
			fwrite(&reg, sizeof(reg), 1, fp2);
		}
	}

	fclose(fp);
	fclose(fp2);
	remove("user.dat");
	rename("user2.dat","user.dat");

}

void listpelanggan()
{
	fp = fopen("user.dat","rb");
	printf("LIST Pelanggan\n");
	while(fread(&reg,sizeof(reg),1,fp)==1)
	{
		printf("Username : %s\n",reg.uname);
		printf("Password : %s\n", reg.pass);
		printf("Nama     : %s\n", reg.nama);
		printf("Alamat   : %s\n", reg.alamat);
		printf("No telp  : %s\n", reg.tel);
		printf("\n");
	}
	fclose(fp);
	printf("Tekan ENTER untuk kembali ke user management"); getch();
	system ("cls");
	mana();
}

void bapes()
{
	pesan=fopen("pesan.dat","rb");
	while(fread(&mes[i], sizeof(mes[i]), 1, pesan)==1)
	{
		printf("Pesan dari user: \n %s", mes[i].pesan);
	}

	fclose(pesan);

}
