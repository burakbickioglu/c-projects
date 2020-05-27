#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

    

	int toplampuan;
	char tekraroyna;

	int main() {		//mainmainmainmainmainmain
	
	srand(time(NULL));
	anamenu();



	return 0;
}






	int anamenu()
	{
		int anasecim;
		system("CLS");
		printf("	ANA MENU	\n");
		printf("	--------\n\n");
		printf("1. Sans oyunlari \n");
		printf("2. Cekilis istatistikleri \n");
		printf("3. Cikis\n\n");
		printf("(Toplam odulunuz: %d puan)Seciminizi giriniz: ",toplampuan);
		scanf("%d",&anasecim);

		switch(anasecim)
		{
			case 1:
				sansoyunlari();

				break;

			case 2:
				istatistikler();
				break;

			case 3:
				cikis();
				break;
			default:
				printf("Lutfen 1-3 arasi bir deger giriniz.");
				sleep(1);
				anamenu(); 
				break;
		}
	}







	int sansoyunlari()
	{
		int oyunsecim;
				system("CLS");
				printf("1-Sayisal Loto oynama \n");
				printf("2-Sans Topu oynama \n");
				printf("3-On Numara oynama \n");
				printf("4-Super Loto oynama \n");
				printf("5-Ana menu \n\n");
				printf("Toplam odulunuz(%d puan) Seciminiz: ",toplampuan);
				scanf("%d",&oyunsecim);
				switch(oyunsecim)
				{
					case 1:
						sayisalloto();
						break;

					case 2:
						sanstopu();
						break;

					case 3:
						onnumara();
						break;

					case 4:
						superloto();
						break;

					case 5:
						anamenu();
						break;
					
					default:
						printf("Lutfen 1-5 arasi bir deger giriniz.");
						sleep(1);
						sansoyunlari();
						break;
				}

	}
	
	
	
	
	int toplam_sayisal_puan;	
	int suanlik_sayisal_puan;
	int sayisallotoistatistik[2][49];
	
	int sayisalloto()
	{
		
		system("CLS");
		printf("		SAYISAL LOTO\n");
		printf("		------------\n\n");
		
		int sayisalkullanici[6],randomsayisal[6];
		int size=6;		//	dizi eleman sayisi
		int i,j,k,l;
		
		for(i=1;i<=48;i++)			//	Ýstatistik dizisinin ilk matrisine sirasiyla sayilari tanimliyoruz
		{
			sayisallotoistatistik[0][i]=i;
		}
		



		
		printf("Lutfen bosluk birakarak (1-49 arasi) 6 farkli deger giriniz.: ");
		
		
		for(i=0;i<6;i++)			//	kullanicidan 6 farkli deger aliyoruz.
		{
			scanf("%d",&sayisalkullanici[i]);
		}
		
		
		do
		{
				
			for(i=0;i<size;i++)
			{
			
				randomsayisal[i]=1+rand()%48;
				for(j=0;j<=i;j++)
				{
					for(k=0;k<=j;k++)
					{
						if(randomsayisal[j]==randomsayisal[k])
						{
							randomsayisal[j]=1+rand()%48;
						}
					}
				}		

			}
		}
		while(kontrol(randomsayisal, size) != 1);
		
		for(i=0;i<6;i++){					//		hangi sayidan kac kere ciktigini atiyoruz
			sayisallotoistatistik[1][randomsayisal[i]]++;
		}

		for(i=1;i<49;i++)
		{
			printf("%d-%d	",sayisallotoistatistik[0][i],sayisallotoistatistik[1][i]);
		}
		
		
		
		siralama(sayisalkullanici,6);		//	Kullanicinin girdigi sayilar siralanir
		
		siralama(randomsayisal,6);		//	Random sayilar siralanir
		
		
		printf("\n\n");
		printf("Girdiginiz sayilar: ");
	
		for(i=0;i<6;i++)
		{
		printf("%d ",sayisalkullanici[i]);
		}
		
		printf("\n");
		
		printf("Cekilis sonucu:	     ");
	
		for(i=0;i<6;i++)
		{
		printf("%d ",randomsayisal[i]);
		}
		
		printf("\n\n");
		
		
		
		int dogrusayisi=0;
		dogrusayisi=tutturulan(sayisalkullanici,randomsayisal,size);
		
		printf("%d sayiyi dogru tahmin ettiniz ! \n",dogrusayisi);
		
		if(dogrusayisi==6)
		{
			suanlik_sayisal_puan=256;
		}
		
		else if(dogrusayisi==5)
		{
			suanlik_sayisal_puan=128;
		}
		
		else if(dogrusayisi==4)
		{
			suanlik_sayisal_puan=64;
			
		}
		else if(dogrusayisi==3)
		{
			suanlik_sayisal_puan=32;
		}
		
		
		
		toplam_sayisal_puan+=suanlik_sayisal_puan;
		toplampuan+=suanlik_sayisal_puan; 
		
		printf("\nBu oyunda kazandiginiz puan: %d",suanlik_sayisal_puan);
		
		
		
		printf("\n");
		printf("Sayisal Loto'da kazandiginiz toplam puan: %d",toplam_sayisal_puan);
		
		printf("\n\n");
		
		suanlik_sayisal_puan=0;	
		
		printf("Yeni bir sayisal loto oyunu oynamak ister misiniz? (e/E/h/H) \n");
		scanf("%s",&tekraroyna);
		
		if(tekraroyna=='e' || tekraroyna=='E')
		{
			sayisalloto();
		}
		
		else if(tekraroyna=='h' || tekraroyna=='H')
		{
			sansoyunlari();
		}
		
		
		
	}
		
		
		
		
		
	
	int toplam_sanstopu_puan;	
	int suanlik_sanstopu_puan;
	int sanstopuistatistik[2][34];
	
	int sanstopu()
	{
		system("CLS");
		printf("		SANS TOPU\n");
		printf("		---------\n\n");
		
		int sanstopukullanici[6],randomsanstopu[6];
		int size=6;		//	dizi eleman sayisi
		int i,j,k,l;
		
		for(i=0;i<34;i++)
		{
			sanstopuistatistik[0][i]=i;
		}
		
		
		
		
		
		
		int artibir,artibirrandom;
		printf("Lutfen bosluk birakarak (1-34 arasi) 5 farkli deger giriniz.: ");
		
		
		for(i=0;i<5;i++)			//	kullanicidan 5 farkli deger aliyoruz.
		{
			scanf("%d",&sanstopukullanici[i]);
		}
		
		printf("Lutfen girdiginiz sayilardan farkli (1-14 araliginda) bir sayi giriniz: ");
		scanf("%d",&artibir);
		
		sanstopukullanici[5]=artibir;
		
		artibirrandom=1+rand()%14;
		
		randomsanstopu[5]=artibirrandom;
		
		
		
		do
		{
			for(i=0;i<size-1;i++)
			{
	
				randomsanstopu[i]=1+rand()%34;
				for(j=0;j<=i;j++)
				{
					for(k=0;k<=j;k++)
					{
						if(randomsanstopu[j]==randomsanstopu[k])
						{
							randomsanstopu[j]=1+rand()%34;
						}
					}
				}
				
			}
		}
		while(kontrol(randomsanstopu, size) != 1);
		
		for(i=0;i<5;i++){					//		hangi sayidan kac kere ciktigini atiyoruz
			sanstopuistatistik[1][randomsanstopu[i]]++;
		}

		for(i=1;i<49;i++)
		{
			printf("%d-%d	",sayisallotoistatistik[0][i],sayisallotoistatistik[1][i]);
		}
		

		
		siralama(sanstopukullanici,size-1);		//	Kullanicinin girdigi sayilar siralanir
		
		siralama(randomsanstopu,size-1);		//	Random sayilar siralanir
		
		
		printf("\n\n");
		printf("Girdiginiz sayilar: ");
		
		for(i=0;i<5;i++)
		{
		printf("%d ",sanstopukullanici[i]);
		}
		
		printf("		+		%d",sanstopukullanici[5]);
		
		printf("\n\n");
		
		printf("Cekilis sonucu:");
	
		
		
		for(i=0;i<5;i++)
		{
		printf("%d ",randomsanstopu[i]);
		}
		
		printf("		+		%d",randomsanstopu[5]);
		
		printf("\n\n");
		
		
		int dogrusayisi=0;
		dogrusayisi=tutturulan(sanstopukullanici,randomsanstopu,size);
		
		int dogruartibir=0;
		
		if(artibir==artibirrandom){
		dogruartibir=1;	}
		
			
		printf("%d sayiyi dogru tahmin ettiniz ! \n",dogrusayisi+dogruartibir);
		
		if(dogrusayisi==5 && dogruartibir==1)
		{
			suanlik_sanstopu_puan=256;
		}
		
		else if(dogrusayisi==5)
		{
			suanlik_sanstopu_puan=128;
		}
		
		else if(dogrusayisi==4 	&& dogruartibir==1)
		{
			suanlik_sanstopu_puan=64;
			
		}
		else if(dogrusayisi==4)
		{
			suanlik_sanstopu_puan=32;
		}
		
		else if(dogrusayisi==3 && dogruartibir==1)
		{
			suanlik_sanstopu_puan=16;
		}
		
		else if(dogrusayisi==3)
		{
			suanlik_sanstopu_puan=8;
		}
		
		else if(dogrusayisi==2 && dogruartibir==1)
		{
			suanlik_sanstopu_puan=4;
		}
		
		else if(dogrusayisi==1 || dogruartibir==1)
		{
			suanlik_sanstopu_puan=2;
		}
		
		
		toplam_sanstopu_puan+=suanlik_sanstopu_puan;
		toplampuan+=suanlik_sanstopu_puan; 
		
		printf("\nBu oyunda kazandiginiz puan: %d",suanlik_sanstopu_puan);
		
		
		
		printf("\n");
		printf("Sans Topu'nda kazandiginiz toplam puan: %d",toplam_sanstopu_puan);
		
		printf("\n\n");
		
		suanlik_sanstopu_puan=0;	
		
		printf("Yeni bir sayisal loto oyunu oynamak ister misiniz? (e/E/h/H) \n");
		scanf("%s",&tekraroyna);
		
		if(tekraroyna=='e' || tekraroyna=='E')
		{
			sanstopu();
		}
		
		else if(tekraroyna=='h' || tekraroyna=='H')
		{
			sansoyunlari();
		}
		
		
	}
	
	
	
	
	
	
	int toplam_onnumara_puan;	
	int suanlik_onnumara_puan;	
	int onnumaraistatistik[2][80];
	
	int onnumara()
	{
		system("CLS");
		printf("		ON NUMARA\n");
		printf("		---------\n\n");
		
		int onnumarakullanici[10],randomonnumara[22];
		int size=10,randomsize=22;
		int i,j,k,l;
		
		
		for(i=0;i<80;i++)
		{
			onnumaraistatistik[0][i]=i;
		}
		
		
		char onnumaratekrar;
		
		printf("Lutfen bosluk birakarak (1-80 arasi) 10 farkli deger giriniz.: ");
		
		
		for(i=0;i<size;i++)			//	kullanicidan 6 farkli deger aliyoruz.
		{
			scanf("%d",&onnumarakullanici[i]);
		}
		
		
		do
		{
			for(i=0;i<randomsize;i++)
			{
	
				randomonnumara[i]=1+rand()%80;
				for(j=0;j<=i;j++)
				{
					for(k=0;k<=j;k++)
					{
						if(randomonnumara[j]==randomonnumara[k])
						{
							randomonnumara[j]=1+rand()%80;
						}
					}
				}
				
			}
		}
		while(kontrol(randomonnumara, randomsize) != 1);
		
		
		for(i=0;i<22;i++){					//		hangi sayidan kac kere ciktigini atiyoruz
			onnumaraistatistik[1][randomonnumara[i]]++;
		}

		
		siralama(onnumarakullanici,size);		//	Kullanicinin girdigi sayilar siralanir
		
		siralama(randomonnumara,randomsize);		//	Random sayilar siralanir
		
		
		printf("\n\n");
		printf("Girdiginiz sayilar: ");
	
		for(i=0;i<size;i++)
		{
		printf("%d ",onnumarakullanici[i]);
		}
		
		printf("\n");
		
		printf("Cekilis sonucu:	     ");
	
		for(i=0;i<randomsize;i++)
		{
		printf("%d ",randomonnumara[i]);
		}
		
		printf("\n\n");
		
		
		
		int dogrusayisi=0;
		dogrusayisi=tutturulanonnumara(onnumarakullanici,randomonnumara);		//SIKINTIII
		
		printf("%d sayiyi dogru tahmin ettiniz ! \n",dogrusayisi);
		
		if(dogrusayisi==10)
		{
			suanlik_onnumara_puan=256;
		}
		
		else if(dogrusayisi==9)
		{
			suanlik_onnumara_puan=128;
		}
		
		else if(dogrusayisi==8)
		{
			suanlik_onnumara_puan=64;
			
		}
		
		else if(dogrusayisi==7)
		{
			suanlik_onnumara_puan=32;
		}
		
		else if(dogrusayisi==6)
		{
			suanlik_onnumara_puan=16;
		}
		
		else if(dogrusayisi>=0 && dogrusayisi<6)
		{
			suanlik_onnumara_puan=8;
		}
		
		
		
		
		toplam_onnumara_puan+=suanlik_onnumara_puan;
		toplampuan+=suanlik_onnumara_puan; 
		
		printf("\nBu oyunda kazandiginiz puan: %d",suanlik_onnumara_puan);
		
		
		
		printf("\n");
		printf("Sayisal Loto'da kazandiginiz toplam puan: %d",toplam_onnumara_puan);
		
		printf("\n\n");
		
		suanlik_onnumara_puan=0;	
		
		printf("Yeni bir On Numara oyunu oynamak ister misiniz? (e/E/h/H) \n");
		scanf("%s",&tekraroyna);
		
		if(tekraroyna=='e' || tekraroyna=='E')
		{
			onnumara();
		}
		
		else if(tekraroyna=='h' || tekraroyna=='H')
		{
			sansoyunlari();
		}
		
	}



	int toplam_superloto_puan;	
	int suanlik_superloto_puan;
	int superlotoistatistik[2][54];
	
	int superloto()
	{
		system("CLS");
		printf("		SUPER LOTO\n");
		printf("		------------\n\n");
		
		int superlotokullanici[6],randomsuperloto[6];
		int size=6;		//	dizi eleman sayisi
		int i,j,k,l;
		
		for(i=0;i<=54;i++)
		{
			superlotoistatistik[0][i]=i;
		}

		
		printf("Lutfen bosluk birakarak (1-54 arasi) 6 farkli deger giriniz.: ");
		
		
		for(i=0;i<6;i++)			//	kullanicidan 6 farkli deger aliyoruz.
		{
			scanf("%d",&superlotokullanici[i]);
		}
		
		
		do
		{
			for(i=0;i<size;i++)
			{
	
				randomsuperloto[i]=1+rand()%54;
				for(j=0;j<=i;j++)
				{
					for(k=0;k<=j;k++)
					{
						if(randomsuperloto[j]==randomsuperloto[k])
						{
							randomsuperloto[j]=1+rand()%54;
						}
					}
				}
				
			}
		}
		while(kontrol(randomsuperloto, size) != 1);
		

		for(i=0;i<6;i++)
		{					//		hangi sayidan kac kere ciktigini atiyoruz
			superlotoistatistik[1][randomsuperloto[i]]++;
		}
		
		siralama(superlotokullanici,6);		//	Kullanicinin girdigi sayilar siralanir
		
		siralama(randomsuperloto,6);		//	Random sayilar siralanir
		
		
		printf("\n\n");
		printf("Girdiginiz sayilar: ");
	
		for(i=0;i<6;i++)
		{
		printf("%d ",superlotokullanici[i]);
		}
		
		printf("\n");
		
		printf("Cekilis sonucu:	     ");
	
		for(i=0;i<6;i++)
		{
		printf("%d ",randomsuperloto[i]);
		}
		
		printf("\n\n");
		
		
		
		int dogrusayisi=0;
		dogrusayisi=tutturulan(superlotokullanici,randomsuperloto,size);
		
		printf("%d sayiyi dogru tahmin ettiniz ! \n",dogrusayisi);
		
		if(dogrusayisi==6)
		{
			suanlik_superloto_puan=256;
		}
		
		else if(dogrusayisi==5)
		{
			suanlik_superloto_puan=128;
		}
		
		else if(dogrusayisi==4)
		{
			suanlik_superloto_puan=64;
			
		}
		else if(dogrusayisi==3)
		{
			suanlik_superloto_puan=32;
		}
		
		
		
		
		toplam_superloto_puan+=suanlik_superloto_puan;
		toplampuan+=suanlik_superloto_puan; 
		
		printf("\nBu oyunda kazandiginiz puan: %d",suanlik_superloto_puan);
		
		
		
		printf("\n");
		printf("Super Loto'da kazandiginiz toplam puan: %d",toplam_superloto_puan);
		
		printf("\n\n");
		
		suanlik_superloto_puan=0;	
		
		printf("Yeni bir Super loto oyunu oynamak ister misiniz? (e/E/h/H) \n");
		scanf("%s",&tekraroyna);
		
		if(tekraroyna=='e' || tekraroyna=='E')
		{
			superloto();
		}
		
		else if(tekraroyna=='h' || tekraroyna=='H')
		{
			sansoyunlari();
		}
		
		
	}






	int kontrol (int dizi[], int size){
		
		int i, j;
		for (i=0; i<size; i++){
			for (j=0; j<size; j++){
				if (i!=j && dizi[i] == dizi[j])
					return 0;
			}
		}
		return 1;
		
	}




	void siralama(int dizi[],int size)
	{	
		int i,j;
		
		for(i=1;i<size;i++)
		{
			for(j=0;j<size-i;j++)
			{
				int temp=0;
				
				if(dizi[j]>dizi[j+1])
				{
					temp=dizi[j];			
					dizi[j]=dizi[j+1];
					dizi[j+1]=temp;
				}
				
			}
		}
		
	}
	
	
	
	void sayisallotoistatistiksiralama(int dizi[2][49],int size)
	{
		
		int i,j,temp;
		
		for(i=1;i<size;i++)
		{
			for(j=1;j<size-i;j++)
			{
				if(dizi[1][j+1] > dizi[1][j]){
					
					
					temp=dizi[0][j+1];
					dizi[0][j+1]=dizi[0][j];
					dizi[0][j]=temp;
					
					
					temp=dizi[1][j+1];			
					dizi[1][j+1]=dizi[1][j];
					dizi[1][j]=temp;
				}
			}
		}
	}




	void sanstopuistatistiksiralama(int dizi[2][34],int size)
	{
		
		int i,j,temp;
		
		for(i=1;i<size;i++)
		{
			for(j=1;j<size-i;j++)
			{
				if(dizi[1][j+1] > dizi[1][j]){
					
					
					temp=dizi[0][j+1];
					dizi[0][j+1]=dizi[0][j];
					dizi[0][j]=temp;
					
					
					temp=dizi[1][j+1];			
					dizi[1][j+1]=dizi[1][j];
					dizi[1][j]=temp;
				}
			}
		}
	}
		
	
	
	
	void onnumaraistatistiksiralama(int dizi[2][80],int size)
	{
		
		int i,j,temp;
		
		for(i=1;i<size;i++)
		{
			for(j=1;j<size-i;j++)
			{
				if(dizi[1][j+1] > dizi[1][j]){
					
					
					temp=dizi[0][j+1];
					dizi[0][j+1]=dizi[0][j];
					dizi[0][j]=temp;
					
					
					temp=dizi[1][j+1];			
					dizi[1][j+1]=dizi[1][j];
					dizi[1][j]=temp;
				}
			}
		}
	}
			
		
		
	
		void superlotoistatistiksiralama(int dizi[2][54],int size)
	{
		
		int i,j,temp;
		
		for(i=1;i<size;i++)
		{
			for(j=1;j<size-i;j++)
			{
				if(dizi[1][j+1] > dizi[1][j]){
					
					
					temp=dizi[0][j+1];
					dizi[0][j+1]=dizi[0][j];
					dizi[0][j]=temp;
					
					
					temp=dizi[1][j+1];			
					dizi[1][j+1]=dizi[1][j];
					dizi[1][j]=temp;
				}
			}
		}
	}
		
		
		
	
	
	
	
	
	
	
	int tutturulan(int dizi1[],int dizi2[],int size)
	{
		
		int i,j,tutturulan=0;
		
		for(i=0;i<size;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(dizi1[i]==dizi2[j])
				{
					tutturulan++;
				}
			}
		}
	
	return tutturulan;	
		
	}	
	
	
	
	int tutturulanonnumara(int dizi1[],int dizi2[])
	{
		

		int i,j,tutturulanonnumara=0;
		
		for(i=0;i<10;i++)
		{
			for(j=0;j<22;j++)
			{
				if(dizi1[i]==dizi2[j])
				{
					tutturulanonnumara++;
				}
			}
		}
	
	return tutturulanonnumara;	
		
	}	
	
	
	
	

	


	int istatistikler()
	{
		system("CLS");
		
		int i,j;
		
		//	SAYISAL LOTO ISTATISTIK
		
		sayisallotoistatistiksiralama(sayisallotoistatistik,48);
		
		
		
		printf("Sayisal Loto'da en cok cikmis sayilar:  	");
		
		
		
		for(i=1;i<=6;i++){
		
		printf("%d ",sayisallotoistatistik[0][i]);
		}
		
		
		
		
		//	SANS TOPU NUMARA ISTATISTIK
		
		sanstopuistatistiksiralama(sanstopuistatistik,33);
		
		
		
		printf("\nSans Topu'nda en cok cikmis sayilar:  	");
		
		for(i=1;i<=5;i++){
		
		
		printf("%d ",sanstopuistatistik[0][i]);
		}
	
	
	
		//	ON NUMARA ISTATISTIK
		
		onnumaraistatistiksiralama(onnumaraistatistik,79);
		
		
		printf("\nOn Numara'da en cok cikmis sayilar:  	   ");
		
		
		for(i=1;i<=10;i++){
		
		
		printf("%d ",onnumaraistatistik[0][i]);
		}
		
		
		//	SUPER LOTO ISTATISTIK 
		
		superlotoistatistiksiralama(superlotoistatistik,53);
		
		printf("\nSuper Loto'da en cok cikmis sayilar:  	");
		
		for(i=1;i<=6;i++){
		
		printf("%d ",superlotoistatistik[0][i]);
		}
		
		
		
		return 0;
	}




	





	int cikis()
	{
		char eminmisin;
		system("CLS");
		printf("Cikmak istediginize emin misiniz?(e/E/h/H)\n");
		scanf("%s",&eminmisin);
		

		if(eminmisin=='e' || eminmisin=='E')
		{
			return 0;
		}
		else if(eminmisin=='h' || eminmisin=='H')
		{
			anamenu();
		}

	}





