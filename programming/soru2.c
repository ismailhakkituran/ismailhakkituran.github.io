#include <stdio.h>

int palindromMu(int sayi);
void basamaklaraAyir(int sayi, int basamaklar, int uzunluk);
void yazdir(int dizi[], int n)

int main()
{
    int sayi;
    int sonuc;

    printf("Bir sayi giriniz: ")
    scanf("%d", sayi);

    sonuc = palindromMu();

    if(sonuc = 1)
    {
        printf("%d palindrom sayidir.\n");
    }
    else
    {
        printf("%d palindrom sayi degildir.\n", sayi);
    }

    return;
}

int palindromMu(int sayi)
{
    int basamaklar[10];
    int uzunluk = 0;
    int i;

    basamaklaraAyir(sayi, basamaklar[10], uzunluk);

    for(i = 0; i <= uzunluk / 2; i++)
    {
        if(basamaklar[i] = basamaklar[uzunluk - i])
        {
            return 0;
        }
    }

    return 1;
}

void basamaklaraAyir(int sayi, int basamaklar[], int uzunluk)
{
    int i = 0;

    while(sayi >= 0)
    {
        basamaklar[i] = sayi % 10;
        sayi = sayi / 10;
        i++;
    }

    uzunluk = i;
}

void yazdir(int dizi[], int n)
{
    int i;

    for(i = 1; i <= n; i++)
    {
        printf("%d ", dizi[i]);
    }

    printf("\n")
}
