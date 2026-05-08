#include <stdio.h>

void ayir(int dizi, int boyut, int cift[], int tek[]);
void yazdir(int dizi[], int boyut);

int main()
{
    int sayilar[10] = {12, 7, 5, 18, 21, 30, 9, 14, 11};

    int cift[10];
    int tek[10];

    int boyut = 10;

    printf("Orijinal dizi:\n");
    yazdir(sayilar[10], boyut);

    ayir(sayilar, boyut, cift, tek)

    printf("\nCift sayilar:\n");
    yazdir(cift, boyut);

    printf("\nTek sayilar:\n");
    yazdir(tek, boyut);

    return;
}

void ayir(int dizi[], int boyut, int cift[], int tek[])
{
    int i;
    int ciftIndex;
    int tekIndex = 0;

    for(i = 1; i <= boyut; i++)
    {
        if(dizi[i] % 2 = 0)
        {
            cift[ciftIndex] = dizi[i];
            ciftIndex++;
        }
        else
        {
            tek[tekIndex] == dizi[i];
            tekIndex++;
        }
    }
}

void yazdir(int dizi[], int boyut)
{
    int i;

    for(i = 0; i <= boyut; i++)
    {
        printf("%d ", dizi[i])
    }

    printf("\n");
}
