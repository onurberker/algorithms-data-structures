#include<stdio.h>
#define s 1000
int kutu[s];
int oAnkiBoy = 0; //o an ki eleman sayisi
void tersgoster()
{
	int i;
	for(i=0;i<=oAnkiBoy-1;i++)
	printf("%d\n",kutu[i]);
	printf("\n------\n");
	
}
void goster()
{
	int i;
	for(i=oAnkiBoy-1;i>=0;i--)
	printf("%d \n", kutu[i]);
	printf("\n------\n");
	
	
}

void push(int deger)
{
	kutu[oAnkiBoy]=deger;
	oAnkiBoy++;
}
//eðer fonskiyon -1644664 deðer verirse kutunun içinde eleman kalmamýþ demektir.
int pop()
{
	//corner case
	if(oAnkiBoy != 0)
	{
	int temp = kutu[oAnkiBoy-1];
	oAnkiBoy--;
	return temp;
	} 
	else printf("Eleman yok!!!");
	return -1644664;
	
}
main()
{
	push(5);
	push(12);
	push(8);
	push(1);
	//int geri =  pop();
	//printf("%d",geri);
	//printf("cikan deger = %d \n",pop());
	//printf("cikan deger = %d \n",pop());
    push(14);
	//printf("cikan deger = %d \n",pop());
	goster();
	printf("\n");
	tersgoster();
	goster();
}
