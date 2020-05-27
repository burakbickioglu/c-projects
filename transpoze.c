#include<stdio.h>
#include<stdlib.h>

struct degisken{
	int **matris,**transpose,satir,sutun,i,j,k,temp;
	FILE *filep;
	
};

void matrisyazdir(struct degisken deg){
	
	
	for(deg.i=0;deg.i<deg.satir;deg.i++)
	{
		for(deg.j=0;deg.j<deg.sutun;deg.j++){
		
			printf("%d\t",deg.matris[deg.i][deg.j]);
			fprintf(deg.filep,"%d\t",deg.matris[deg.i][deg.j]);
		}
		
		printf("\n");
		fprintf(deg.filep,"\n");
		
	}
	
}

void transpozeyazdir(struct degisken deg){
	
	for (deg.i = 0; deg.i < deg.sutun; ++deg.i)
        for (deg.j = 0; deg.j < deg.satir; ++deg.j) {
            printf("%d  ", deg.transpose[deg.i][deg.j]);
            fprintf(deg.filep,"%d  ", deg.transpose[deg.i][deg.j]);
			if (deg.j == deg.satir - 1){
                printf("\n");
                fprintf(deg.filep,"\n");
            }
        }
}



	

void matrissirala(struct degisken deg){
	
	for(deg.k = 0; deg.k < deg.satir; deg.k++){   
        for(deg.i = 0 ; deg.i < deg.sutun; deg.i++){
            for(deg.j = deg.i + 1; deg.j < deg.sutun; deg.j++){

        		if(deg.matris[deg.k][deg.i] > deg.matris[deg.k][deg.j]){

			        deg.temp = deg.matris[deg.k][deg.i];
			        deg.matris[deg.k][deg.i]   = deg.matris[deg.k][deg.j];
			        deg.matris[deg.k][deg.j] = deg.temp;

            	}
        	}
    	}
	}
}

void transpoze(struct degisken deg){
		// matrisin transpozunu aliyoruz
    for (deg.i = 0; deg.i < deg.satir; ++deg.i)
        for (deg.j = 0; deg.j < deg.sutun; ++deg.j) {
            deg.transpose[deg.j][deg.i] = deg.matris[deg.i][deg.j];
        }
	
}

int anafonk(struct degisken deg){
	
	deg.filep=fopen("kaprekar.txt","w");		
	printf("Satir sayisi: ");
	scanf("%d",&deg.satir);
	
	printf("Sutun sayisi: ");
	scanf("%d",&deg.sutun);
	
	
	deg.matris=(int **)malloc(deg.satir *sizeof(int *));
	deg.transpose=(int **)malloc(deg.sutun *sizeof(int *));
	
	printf("\n\n");
	
	// Matrise dinamik bellek olusturuyoruz
	for(deg.i=0;deg.i<deg.satir;deg.i++)
		deg.matris[deg.i]=(int *)malloc(deg.sutun *sizeof(int));

	// Transpoze matrisine dinamik bellek olusturuyoruz
	for(deg.i=0;deg.i<deg.sutun;deg.i++)
		deg.transpose[deg.i]=(int *)malloc(deg.satir *sizeof(int));
		
		
	// Matrise random atiyoruz
	for(deg.i=0;deg.i<deg.satir;deg.i++)
		for(deg.j=0;deg.j<deg.sutun;deg.j++)
			deg.matris[deg.i][deg.j]=5+rand()%40000;
			
	
	// Matrisin ilk halini yazdiriyoruz
	printf("Matrisin ilk hali:\n\n");
	fprintf(deg.filep,"Matrisin ilk hali:\n\n");
	matrisyazdir(deg);
	
	matrissirala(deg);
	
	
	// Matrisin siralanmis halini yazdiriyoruz
	printf("\nKucukten Buyuge Siralanmis Hali:\n");
    fprintf(deg.filep,"\nKucukten Buyuge Siralanmis Hali:\n");
    
	matrisyazdir(deg);
	
	// Matrisin transpozunu aldiriyoruz
	transpoze(deg);

    // Matrisin transpoze halini yazdiriyoruz
    printf("\nTranspose hali:\n");
    fprintf(deg.filep,"\nTranspose hali:\n");
    transpozeyazdir(deg);
    
    printf("\n\nYazdirma islemi tamam !");
    fprintf(deg.filep,"\n\nYazdirma islemi tamam !");
    
    printf("\n\nKAPREKAR KISMINI YAPAMADIM.");
    
}

int main()
{
	struct degisken deg;
	srand(time(NULL));
	
	anafonk(deg);
	
	
	
    return 0;
}
	
	
	
	
	
