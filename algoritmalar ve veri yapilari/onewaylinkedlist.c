#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	
	int val;
	struct node *next;  // npde *next; yol tarifi bir sonraki için
	
}node;// önemli olan buradaki ismi

node *bas = NULL; // ilk elemanýn saklanacýðý yer kesin tanýmla oluþturulmamýþ

void sonaekle(int x)
{
	//           (hangi tipe ait se yani = liðin önecesinde ne yazdýysan) 
	node *yeni = (node *) malloc(sizeof(node));
	//node *yeni = (node *)calloc(1,(sizeof(node)));
	yeni->val = x;
	yeni->next =NULL;
	
	//baþa ekleme
	if(bas == NULL)
	{
		bas = yeni;
	}
	else{
		node *g = bas; //düðümler arasý gezmek için
		while(g->next !=NULL)
		{
			g =  g->next; // bir sonraki düðüme gider
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
	node *q = bas ,*g = bas; // q gezginin kankasý
	if(bas == NULL) printf("eleman yok\n");
	while(g->next !=NULL)
	{
		q = g;
		g = g->next;
	}
	q->next =NULL;
}
void elemansil(int loc) // loc sýrasýndaki elemaný 
{
	node *g = bas,*q= bas;
	if(loc < 1 ){
		printf("gecersiz loc\n");
		return;
	}
   if(bas == NULL) // hiç eleman yoksa
   {
   	printf("Eleman yok\n");
   	
   }
   else{ // en az bir eleman var ise
   	if(loc == 1) // baþtan çýkar
   	{
   		bas = bas->next;
	}
	int count = 1;
	while(g->next != NULL && loc > count)
	{
		q = g; //  g nin bir öncesindeki deðeri tuttar
		g = g->next; // her zamank gibi
		count++; // gerekli lokasyona gitmesi için kaç adým çalýþmasý gerektiði while ýn
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
	if(bas ==NULL){ // hiç eleman yoksa
		bas = yeni;
	}
	else{
		if(loc == 1) // baþa ekleme
		{
			yeni->next = bas;
			bas = yeni;
			return; // bundan sonrasýna gerek yok
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
			g =  g->next; // bir sonraki düðüme gider
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
