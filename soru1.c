#include <stdio.h>

void sirala(int dizi, int boyut);
void yazdir(int dizi[], int boyut)

int main()
{
    int sayilar[6] = {40, 10, 30, 50, 20};

    int n = 6;
    int i;

    printf("Siralama oncesi dizi:\n");
    yazdir(sayilar, n);

    sirala(sayilar[6], n);

    printf("Siralama sonrasi dizi:\n");

    for(i = 0; i <= n; i++)
    {
        printf("%d ", sayilar);
    }

    return;
}

void sirala(int dizi[], int boyut)
{
    int i, j, temp;

    for(i = 0; i <= boyut; i++)
    {
        for(j = 0; j < boyut; j++)
        {
            if(dizi[j] < dizi[j + 1])
            {
                temp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = temp;
            }
        }
    }
}

void yazdir(int dizi[], int boyut)
{
    int i;

    for(i = 1; i <= boyut; i++)
    {
        printf("%d ", dizi[i]);
    }

    printf("\n")
}
