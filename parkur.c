#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct degiskens{
	
	int hp,parkurmt,engelsayisi,engel,i,asalkontrol;
	FILE *filep;
};

int random(int min,int max){		// random deger fonksiyonu
	srand(time(NULL));
	return (min+rand()%(max-min+1));
}

int engelmetre(struct degiskens deg){	// engelin kacinci metrede cikacagini belirleyen fonksiyon
	
	for(;;)	{			
		deg.engel+= 5 + rand()%(deg.parkurmt-deg.engel-deg.i*5); 
		if(deg.engel<deg.parkurmt)
			break;
	}
	return deg.engel;		
}

int asalkontrol(struct degiskens deg){
	
	int kucuk,i;
	
	if(deg.engel>deg.hp)
		kucuk=deg.engel;
	
	else
		kucuk=deg.hp;
	
	deg.asalkontrol=0;
	for(i=2;i<=kucuk;i++){
		if((deg.engel % i == 0) && (deg.hp % i == 0))
			deg.asalkontrol=1;		// sayilar aralarinda asal degillerse 1 donecek
	}	
	return deg.asalkontrol;
}

void dongu(struct degiskens deg){
	
	deg.filep=fopen("log.txt","w");		// log.txt dosyasi aciliyor
	deg.hp=100;
	deg.parkurmt=random(50,100);		// parkurun kac mt olacagi belirleniyor
	deg.engelsayisi=random(2,5);
	
	printf("engel sayisi: = %d\n",deg.engelsayisi);
	fprintf(deg.filep,"Engel sayisi = %d\n",deg.engelsayisi);
	
	printf("Parkur uzunlugu = %d metre\n",deg.parkurmt);
	fprintf(deg.filep,"Parkur uzunlugu = %d metre\n",deg.parkurmt);
	
	printf("Yarisma Basladi !!! \n");
	fprintf(deg.filep,"Yarisma Basladi !!! \n");
	
	printf("Yarismaci HP = %d\n\n",deg.hp);
	fprintf(deg.filep,"Yarismaci HP = %d\n\n",deg.hp);
	
	for(deg.i=deg.engelsayisi;deg.i>0;deg.i--)
	{
		
		deg.engel=engelmetre(deg);		// Engelin kacinci metrede cikacagi random fonksiyonla cekiliyor
		
		printf("Yarismaci %d. metreye kadar bir engelle karsilasmadi.\n",deg.engel);
		fprintf(deg.filep,"Yarismaci %d. metreye kadar bir engelle karsilasmadi.\n",deg.engel);
		
		printf("%d. metrede bir engel var. ",deg.engel);
		fprintf(deg.filep,"%d. metrede bir engel var. ",deg.engel);
		
		deg.asalkontrol=asalkontrol(deg);
		
		if(deg.asalkontrol==1)
		{
			printf("%d ve %d aralarinda asal degildir.\n",deg.hp,deg.engel);
			fprintf(deg.filep,"%d ve %d aralarinda asal degildir.\n",deg.hp,deg.engel);
		}
		
		else if(deg.asalkontrol==0)
		{
			printf("%d ve %d aralarinda asaldir.\n",deg.hp,deg.engel);
			fprintf(deg.filep,"%d ve %d aralarinda asaldir.\n",deg.hp,deg.engel);
			deg.hp-=deg.engel;
		}
		
		printf("Yarismaci HP = %d\n\n",deg.hp);
		fprintf(deg.filep,"Yarismaci HP = %d\n\n",deg.hp);
		
		if(deg.hp<=0)
		{
			printf("Uzgunum !!! Yarismayi tamamlayamadin.");
			fprintf(deg.filep,"Uzgunum !!! Yarismayi tamamlayamadin.");
			return 0;
		}
	}
	printf("Tebrikler !!! Yarismayi %d HP ile bitirdiniz.",deg.hp);
	fprintf(deg.filep,"Tebrikler !!! Yarismayi %d HP ile bitirdiniz.",deg.hp);
}

int main() {
	struct degiskens deg;				// struct yapisindan degiskenler cekiliyor
	dongu(deg);		// ana dongu fonksiyonunu calistiriyoruz	
	return 0;
}
