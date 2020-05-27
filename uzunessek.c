#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	srand(time(NULL)); 
	
	int dizi[10],diziCift[10],diziTek[10];
	
	int *diziPtr=&dizi;
	int *diziCptr=&diziCift;
	int *diziTptr=&diziTek;
	int i;
	
	printf("Random dizideki elemanlar\n\n");
	for(i=0;i<10;i++){
		*(diziPtr+i)=1+rand()%100;
		printf("%d. sayi= %d\n",i+1,*(diziPtr+i));
	}	
	printf("\n\n\n\n");
	tekmiciftmi(diziPtr,diziTptr,diziCptr);
	return 0;
}

void tekmiciftmi(int *dizi,int *tek,int *cift){
	
	int i;
	for(i=0;i<10;i++)
	{
		if(*(dizi+i)%2==0)
		{	
			*(cift+i)=*(dizi+i);
			printf("%d sayisi cifttir.\n",*(dizi+i));
		}
			
		else
		{
			*(tek+i)=*(dizi+i);
			printf("%d sayisi tektir.\n",*(dizi+i));
		}		
	}	
}
