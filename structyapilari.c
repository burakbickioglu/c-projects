#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct saat{
	char saat[20];
};

struct araba{
	char plaka[15];
	char model[15];
	char renk[15];
};

void AracEkle(struct araba aracekle[])
{
	struct saat guncelsaat;
	printf("Saati giriniz(ss:dk:sn): ");
	gets(guncelsaat.saat);

	int i;
	for(i=0;i<5;i++){
		printf("%d.aracin plakasini giriniz: ",(i+1));
		gets(aracekle[i].plaka);

		printf("%d.aracin modelini giriniz: ",(i+1));
		gets(aracekle[i].model);

		printf("%d.aracin rengini giriniz: ",(i+1));
		gets(aracekle[i].renk);

		printf("\n");

	}
}

void AraclariListele(struct araba aracgoster[])
{
	struct saat guncelsaat;
	int i;
    printf("ARACLARIN LISTESI\n");
    printf("-----------------\n");
	for(i=0;i<5;i++){

		printf("%d.aracin plakasi: %s\n",(i+1),aracgoster[i].plaka);
		printf("%d.aracin modeli: %s\n",(i+1),aracgoster[i].model);
		printf("%d.aracin rengi: %s\n",(i+1),aracgoster[i].renk);
		printf("%d.aracin giris saati: %s\n",(i+1),guncelsaat.saat);
        printf("\n");
	}
}
int main(int argc, char *argv[]) {

	struct araba arabalar[1000];
	AracEkle(arabalar);
	AraclariListele(arabalar);
	return 0;
}
