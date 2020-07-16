#include <stdio.h>
int i,j,m,n,mat1[50][50];
int mat2[50][50],mat3[50][50];
int main()
{
printf("Jumlah Baris = ");scanf("%d",&m);
printf("Jumlah Kolom = ");scanf("%d",&n);
printf("Matriks 1 \n");
for (i=0; i<=m-1;i++)
for (j=0; j<=n-1;j++)
{
printf("Isi baris %d, kolom %d = ",i+1,j+1);
scanf("%d",&mat1[i][j]);
}
printf("Matriks 2 \n");
for (i=0; i<=m-1; i++)
for (j=0;j<=n-1;j++)
{
printf("Isi baris %d, kolom %d = ",i+1,j+1);
scanf("%d",&mat2[i][j]);
}
for (i=0;i<=m-1;i++)
for (j=0;j<=n-1;j++)
{
mat3[i][j]=mat1[i][j]+mat2[i][j];
}
printf("Hasil Penjumlahan Matriks \n");
for (i=0;i<=m-1;i++)
{
for (j=0;j<=n-1;j++)
printf("%d ",mat3[i][j]);
printf("\n");
}
return 0;
}
