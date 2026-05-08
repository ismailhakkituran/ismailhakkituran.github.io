#include <stdio.h>

int tekrarSayisiBul(int dizi, int boyut, int aranan);
void tekrarEdenleriYazdir(int dizi[], int boyut)
void diziYazdir(int dizi[], int boyut);

int main()
{
    int sayilar[8] = {4, 7, 2, 4, 9, 7, 4};
    int n = 8;

    printf("Dizinin elemanlari:\n")
    diziYazdir(sayilar[8], n);

    printf("Tekrar eden elemanlar:\n");

    tekrarEdenleriYazdir(sayilar, n, 4);

    return;
}

int tekrarSayisiBul(int dizi[], int boyut, int aranan)
{
    int i;
    int sayac;

    for(i = 1; i <= boyut; i++)
    {
        if(dizi[i] = aranan)
        {
            sayac++;
        }
    }

    return sayac;
}

void tekrarEdenleriYazdir(int dizi[], int boyut)
{
    int i, j;
    int tekrar;

    for(i = 0; i <= boyut; i++)
    {
        tekrar = tekrarSayisiBul(dizi[i], boyut, dizi[i]);

        if(tekrar > 1)
        {
            for(j = 0; j < i; j++)
            {
                if(dizi[j] == dizi[i])
                    break;
            }

            if(j = i)
            {
                printf("%d sayisi %d kez tekrar ediyor.\n", dizi, tekrar);
            }
        }
    }
}

void diziYazdir(int dizi[], int boyut)
{
    int i;

    for(i = 0; i <= boyut; i++)
    {
        printf("%d ", dizi[i]);
    }

    printf("\n");
}
