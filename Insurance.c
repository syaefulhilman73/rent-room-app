#include <stdio.h>
#include <string.h>

struct user{
	char uname[100], pass[100], nama[100], alamat[100], tel[100];
}reg,mas;

struct asur{
	char uname[50],pass[50];
}a;

char dicari[20];

FILE *fp;
FILE *fp2;
/*
void pelanggan(int pilih)
{

	{


		switch(pilih)
		{
			case 1: {

				break;
			}
		}
	}
	else printf("Login GAGAL");
}*/
void regi()
{
    system("cls");
	fp=fopen("user.dat","ab");
	getchar();
	printf("Ragistrasi Pelanggan\n");
	printf("Username: ");
	gets(reg.uname);
	printf("Password: ");
	gets(reg.pass);
	printf("Nama: ");
	gets(reg.nama);
	printf("Alamat: ");
	gets(reg.alamat);
	printf("No HP: ");
	gets(reg.tel);

	fwrite(&reg, sizeof(reg), 1, fp);

	fclose(fp); getchar();

	main();
}
void pelanggan (int pilih)
{
    system("cls");
	printf(" 1. Asuransi Pendidikan\n 2. Asuransi Jiwa\n 3. Asuransi Kendaraan\n 4. Asuransi Kesehatan\n");
	printf("Masukan nomor pilihan asuransi: "); scanf("%d", &pilih);

	switch (pilih)
	{
		case 1: printf("Daskom Education Insurance\n ");
                printf("==Perlindungan pencari nafkah==\n");
                printf("Penghasilan bisa saja berhenti, namun apakah Biaya hidup keluarga bisa berhenti ?");
                printf("Lahir, rejeki dan meninggal sudah ditentukan Tuhan, kita tidak bisa memastikan suami/kepala rumah tangga/pencari nafkah meninggal di masa pensiun, setelah anak-anak sudah mandiri bekerja, kita harus memahami jalan manusia bukan jalan Tuhan. Bagaimana jika Tuhan memanggil pencari nafkah di saat anak-anak masih sekolah ? Di saat keluarga sedang membutuhkan biaya besar. Tentunya kita tidak boleh menyalahkan Tuhan jika hal ini terjadi, karena Tuhan sudah memberikan manusia pikiran untuk bertindak bijak dalam mengelola semua risiko ini dengan baik.");break;
		case 2: printf("asuransi jiwa unit link Allianz dibandingkan dengan asuransi berjangka atau termlife, asuransi jiwa unit link Allianz memiliki rider atau manfaat tambahan yang jauh lebih komplet. Dan salah satu rider atau manfaat tambahan yang menjadi fitur unggulan di Allianz adalah rider penyakit kritis CI100, yang merupakan rider asuransi penyakit kritis yang mengcover 100 kondisi penyakit kritis dari tahap awal");break;
		case 3: printf("");break;
		case 4: printf("");break;
	}
	main();
}
void logi(int pilih)
{
    system("cls");
	fp=fopen("user.dat","rb");
	getchar();
	printf("Username: ");
	gets(mas.uname);
	printf("Password: ");
	gets(mas.pass);

	while(fread(&reg, sizeof(reg), 1, fp)==1)
	{
		if(strcmp(mas.uname, reg.uname)==0 && strcmp(mas.pass, reg.pass)==0)
		{
			printf("\nAnda telah berhasil masuk sebagai pelanggan\n\n");
			printf("Menu: \n");
			printf("1. Lihat pilihan packet\n");
			printf("2. Kirim pesan ke admin\n");
			printf("Pilih Menu: "); scanf("%d",&pilih);
		}
	}
	pelanggan(pilih);
}
void man(int pilih)
{
    system("cls");
	printf("\nUser Management\n\n");
	printf("1. Create user\n");
	printf("2. Delete user\n");
	printf("3. Edit user\n");
	printf("Pilih Menu: "); scanf("%d",&pilih);

	switch(pilih)
	{
	    system("cls");
		case 1:{ regi(); main();
		break;
		}

		case 2:
{
    system("cls");
fp = fopen("user.dat", "rb");
fp2 = fopen("user2.dat", "wb");
printf("Silahkan masukkan nama menu asuransi yang akan dihapus: "); gets(dicari);
while(fread(&reg,sizeof(reg),1, fp)==1)
{
if(strcmp(reg.uname,dicari)!=0)
{
fwrite(&reg,sizeof(reg),1,fp2);
}
}
fclose(fp);
fclose(fp2);
remove("user.dat");
rename("user2.dat","user.dat");
}main();break;
		case 3:
	{
	    system("cls");
			fp = fopen("user.dat", "rb");
			fp2 = fopen("user2.dat", "wb");
			printf("Silahkan masukkan nama menu asuransi yang akan diubah: "); gets(dicari);
while(fread(&reg,sizeof(reg),1, fp)==1)
{
if(strcmp(reg.uname,dicari)!=0)
{
fwrite(&reg,sizeof(reg),1,fp2);
}
else printf("Username: "); getchar();
	gets(reg.uname);
	printf("Password: ");
	gets(reg.pass);
	printf("Nama: ");
	gets(reg.nama);
	printf("Alamat: ");
	gets(reg.alamat);
	printf("No HP: ");
	gets(reg.tel);

	fwrite(&reg, sizeof(reg), 1, fp2);
}
fclose(fp);
fclose(fp2);
remove("user.dat");
rename("user2.dat","user.dat");
//return 0;
}main();break;
}
}
void admin(int pilih)
{
    system("cls");
	printf("Silahkan login terlebih dahulu\n");
	printf("===============================\n");
	printf("Username: "); scanf("%s",a.uname);
	printf("Password: "); scanf("%s",a.pass);

	if (strcmp(a.uname,"admin")==0 && strcmp(a.pass,"daskomins")==0)
	{
	    system("cls");
		printf("\nLogin Berhasil\n");
		printf("Menu: \n");
		printf("1. User management\n");
		printf("2. Lihat pesan\n");
		printf("Pilih Menu: "); scanf("%d",&pilih);

		switch(pilih)
		{
			case 1:{ man(pilih);main();
				break;
			}
		}

	}
}



main() {
    system("cls");
	int pilih;
	printf("Daskom Insurance Corp\n");
	printf("Menu: \n");
	printf("1. Pengunjung\n");
	printf("2. Pelanggan\n");
	printf("3. Admin\n");
	printf("4. Exit\n");
	printf("Pilih Menu (1/2/3/4): ");
	scanf("%d",&pilih);

	switch(pilih)
	{
		case 1:{	printf("\nAnda Masuk sebagai Pengunjung\n");
					printf("\nDaskom Insurance adalah sebuah laboratorium di Telkom University");
					printf("\nyang menyediakan beberapa layanan asuransi, walaupun masih dalam");
					printf("\nlingkungan kampus, kami sudah bekerja secara proffesional dan   ");
					printf("\nkami bukanlah asuransi abal abal seperti di insert investigasi  ");



				}break; getchar();

		case 2:{	logi(pilih); main();

					break;
				}

		case 3:{	admin(pilih); main();
			break;
		}
	}
}
