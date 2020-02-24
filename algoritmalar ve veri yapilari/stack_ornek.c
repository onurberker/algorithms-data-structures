#include<stdio.h>
#define s 1000
int kutu[s];
int oAnkiBoy=0;
int yedekkutu[s];
int yedekboy=0;


void push(int deger)
{
	kutu[oAnkiBoy]=deger;
	oAnkiBoy++;
}
int pop()
{
	if(oAnkiBoy != 0)
	{
		int temp;
		temp=kutu[oAnkiBoy-1];
		oAnkiBoy--;	
		return temp;
	}
	else printf("Icerde eleman yok...\n");
	return 114;
}
void yedekpush(int deger)
{
	yedekkutu[yedekboy]=deger;
	yedekboy++;
}
int yedekpop()
{
	if(yedekboy != 0)
	{
		int temp;
		temp=yedekkutu[yedekboy-1];
		yedekboy--;	
		return temp;
	}
	else printf("icerde nasip yok...\n");
	return 114;
}
void goster()
{
	int i;
	for(i=oAnkiBoy-1;i>=0;i--)
	{
		printf("%d\n",kutu[i]);
	}
}
void siraliekle(int x)
{
	int yedekpushmiktari = 0;
	while(1)
	{	
	if(oAnkiBoy==0)
	{
		push(x);
		break;
	}
	else 
	{
		int temp=pop();
		if(x > temp)
		{
			push(temp);
			push(x);
			break;
		}
		else
		{
			yedekpush(temp);
			yedekpushmiktari++;		
		}
	}
	
}
	int i;
	for(i = 0; i <yedekpushmiktari;i++)
	{
		/*int temp = yedekpop();
		push(temp);*/
	    push(yedekpop());
	}
		
	
}

main()
{
     int dizi[10] = {1,4,-12,3,71,2,10,13,-78,42};
	int i;
	for( i = 0; i< 10;i++ )
	siraliekle(dizi[i]);
      goster();	
}

