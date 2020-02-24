#include<stdio.h>
#define s 10000
int liste[s];
int boy = 0;
void kaynak2(int n,int x) //n= kaynak yapmaya calistigimiz sayi, x=konum
{
	if(x <= 0) 
	{
		printf("gecersiz konum...\n");
		return;
	}
	if(x >= boy)
	{
		ekle(n);
	}
	else
	{
		int i;
		int sayac=0;
		for(i=1;i<x;i++)
		{
			ekle(cikar());
			sayac++;
			
		}
		ekle(n);
		int j;
		for (j=1;j<boy-sayac;j++)
		{
			ekle(cikar());
		}
	}
	
}

void shifting(int n) // kaydýrma miktarý
{
	int i;
	for(i = 0; i< n ;i++)
	{
		/*int temp = cikar();
		ekle(temp); */
		ekle(cikar());
	
	}	
}
void kaynak(int x,int location) // x=kaynak yapýlacak sayý.
{								// location kaynak yapýlacak sýra.
	if(location<=0)
	{
		printf("Hatali konum.\n");
	}
	else
	{
		if(location>boy)
		{
			ekle(x);
		}
		else
		{
			shifting(location-1);
			ekle(x);
			shifting(boy-location);	
		}
		
	}
}	
void ekle(int x)
{
	liste[boy] = x;
	boy++;
}
int cikar()
{
	if(boy != 0)
	{
		int temp = liste[0];
	    int	i = 0;
		 for(i = 0; i<boy-1;i++ )
		 {
		 	liste[i] = liste[i+1];
		 } 
		 boy--;
		 return temp;
	}
	else
	{
		printf("kuyruk bos\n");
	}
	return -64964;
}
void goster()
{
	int i ;
	for(i = 0; i< boy ;i++)
	{
		printf("%d - ",liste[i]);
	}
}

main()
{
	int i;
	for(i = 1; i<=10;i++)
	{
		ekle(i);
	}	
	goster();
	kaynak2(99,1);
	//kaynak(99,7);
	printf("\n");
	goster();
	
}
