#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	
	int val;
	struct node *next;  // npde *next; yol tarifi bir sonraki i�in
	
}node;// �nemli olan buradaki ismi

node *bas = NULL; // ilk eleman�n saklanac��� yer kesin tan�mla olu�turulmam��

void sonaekle(int x)
{
	//           (hangi tipe ait se yani = li�in �necesinde ne yazd�ysan) 
	node *yeni = (node *) malloc(sizeof(node));
	//node *yeni = (node *)calloc(1,(sizeof(node)));
	yeni->val = x;
	yeni->next =NULL;
	
	//ba�a ekleme
	if(bas == NULL)
	{
		bas = yeni;
	}
	else{
		node *g = bas; //d���mler aras� gezmek i�in
		while(g->next !=NULL)
		{
			g =  g->next; // bir sonraki d���me gider
		}
		g->next = yeni;
	}
}
void basaekle(int x)
{
	node *yeni =(node*)malloc(sizeof(node));
	yeni->val =x;
	yeni->next =NULL;
	
	if(bas ==NULL)
	{
		bas = yeni;
		
	}
	else{
		yeni->next = bas;
		bas = yeni;
	}
}
void bastancikar()
{
	if(bas == NULL)
	printf("Elaman yok\n");
	else{
		bas = bas->next;
	}
	
}
void sondancikar()
{
	node *q = bas ,*g = bas; // q gezginin kankas�
	if(bas == NULL) printf("eleman yok\n");
	while(g->next !=NULL)
	{
		q = g;
		g = g->next;
	}
	q->next =NULL;
}
void elemansil(int loc) // loc s�ras�ndaki eleman� 
{
	node *g = bas,*q= bas;
	if(loc < 1 ){
		printf("gecersiz loc\n");
		return;
	}
   if(bas == NULL) // hi� eleman yoksa
   {
   	printf("Eleman yok\n");
   	
   }
   else{ // en az bir eleman var ise
   	if(loc == 1) // ba�tan ��kar
   	{
   		bas = bas->next;
	}
	int count = 1;
	while(g->next != NULL && loc > count)
	{
		q = g; //  g nin bir �ncesindeki de�eri tuttar
		g = g->next; // her zamank gibi
		count++; // gerekli lokasyona gitmesi i�in ka� ad�m �al��mas� gerekti�i while �n
	}
	q->next = g->next;
   } 	
}

void reverse()
{
	node *reverse = (node *) malloc(sizeof(node));
	if(bas == NULL) return NULL;
	
	reverse->next = NULL;
	reverse->val = bas->val;
	bas=bas->next;
	while(bas!=NULL)
	{
		node *item =(node *) malloc(sizeof(node));
		item->val = bas->val;
		item->next = reverse;
		reverse= item;
		bas= bas->next;
	}
	bas = reverse;
	goster();
}


void elemanekle(int x,int loc)
{
	node *yeni = (node*)malloc(sizeof(node));
	yeni->val = x;
	yeni->next = NULL;
	node *g = bas,*q=bas;
	if(loc < 1) {
		printf("gecersiz loc\n");
		return;
	}
	if(bas ==NULL){ // hi� eleman yoksa
		bas = yeni;
	}
	else{
		if(loc == 1) // ba�a ekleme
		{
			yeni->next = bas;
			bas = yeni;
			return; // bundan sonras�na gerek yok
		}
		int count = 1;
		while(g !=NULL &&  loc > count)
		{
			q= g;
			g=g->next;
			count++;
			
		}
		q->next = yeni;
		yeni->next = g;
	}
}
void goster()
{
	node *g = bas;
	
	while(g !=NULL)
		{
			printf("%d -- ",g->val);
			g =  g->next; // bir sonraki d���me gider
		}
		printf("\n");
}
main()
{
	int i;
  /*for(i = 1; i<=10;i ++)
  sonaekle(i);
  goster();*/
  
  basaekle(4);
  basaekle(3);
  basaekle(2);
  basaekle(1);
  basaekle(0);
  goster();
  bastancikar();
  goster();
  sondancikar();
  goster();
  sonaekle(8);
  basaekle(7);
  
  goster();
  elemansil(3899889);
  goster();
  
  reverse();
  
  elemanekle(25,12);
  goster();
 
   

}
