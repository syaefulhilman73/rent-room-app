#include <stdio.h>
int a[100];
int i,j,n,min,temp;
void main ()
{
    printf("NAMA: Rifqi Naufal Julian \n");
 printf("NIM: 1101164225\n");
 printf("==INPUT==\n");
printf("Banyak data : ");
scanf("%d",&n);
for (i=0;i<=n-1;i++)
{
printf("Data ke-%d : ",i+1);
scanf("%d",&a[i]);
}
//proses selection sort
for (i=0;i<=n-2;i++)
{
min=i;
for (j=i;j<=n-1;j++)
if (a[j]>a[min])
min=j;
temp=a[min];
a[min]=a[i];
a[i]=temp;
}
printf("==OUTPUT==\n");
//menampilkan hasil sorting
for (i=0;i<=n-1;i++)
{
printf("%d",a[i]);
printf(" ");
}
}
