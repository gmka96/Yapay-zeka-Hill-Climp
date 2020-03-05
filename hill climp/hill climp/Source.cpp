#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
int tahta[8][8] = {
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
};
int tahta2[8][8], sat = 0, sut = 0, adim = 0, satAtla = 0, sonuncu = 0;
void kopyala()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			tahta2[i][j] = tahta[i][j];

}
void olustur()
{
	int deger = 0;
	srand(time(NULL));
	deger = 0 + rand() % 8;
	for (int i = 0; i<8; i++)
	{
		deger = 0 + rand() % 8;
		tahta[i][deger] = 178;
	}
}
void yazdir(int sec) {

	if (sec == 0)
	{
		for (int i = 0; i<8; i++)
		{
			printf("\n\n");
			for (int j = 0; j<8; j++)
			{
				if (tahta[i][j] == 178)
					printf("%c\t", tahta[i][j]);
				else
					printf("%d\t", tahta[i][j]);
			}
		}
	}
	printf("\n\n");
	if (sec == 1)
	{
		for (int i = 0; i<8; i++)
		{
			printf("\n\n");
			for (int j = 0; j<8; j++)
			{
				if (tahta2[i][j] == 178)
					printf("%c\t", tahta2[i][j]);
				else
					printf("%d\t", tahta2[i][j]);
			}
		}
	}

}
void hesapla() {
	//taradan gelen deðerler hesaplanacak
}
void tara()
{


	for (int i = 0; i < 8; i++)
	{

		tahta2[adim][i] = 178;
		tahta2[adim][i - 1] = 0;
		for (int t = 0; t < 8; t++)
		{
			if (tahta2[adim - 1][t] == 178)
				sonuncu++;
		}



		if (sonuncu == 0)
			tahta2[adim - 1][7] = 178;



		Sleep(350);
		yazdir(1);
		//hesapla(); olmalý
	}


	sonuncu = 0;
	tahta2[sat][sut] = 178;
	adim++;
	sat++;
	sut = -1;

}
void degistir()
{
	for (sat = 0; sat < 8; sat++)
		for (sut = 0; sut < 8; sut++)
		{
			if (tahta2[sat][sut] == 178)
			{
				tahta2[sat][sut] = 0;
				tara();

			}


		}
	tahta2[7][7] = 0;




}


int main()
{

	system("color 0b");
	olustur();
	kopyala();
	yazdir(0);
	degistir();
	yazdir(1);

}