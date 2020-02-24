#include<stdio.h>
#include<stdlib.h>
// sonanekle(x) + sondancikar() = stack
// sonaekle(x) + bsatancikar() = queue
typedef struct node{
	
	int val;
	struct node *next,*prev;	
}node;
node *bas =NULL,*son=NULL;
void bassongoster()
{
	node *g=bas;
	node *q=son;
	node *yedek=bas;
	int count=0;
	while(yedek!=NULL) // eleman sayýsýný buylduk
	{
		yedek=yedek->next;
		count++;
	}
	if(count == 0)
	{
		printf("Eleman yok\n");
		return;
	}
	//printf("%d",count);
	int kalan = count % 2; // tek mi diye kontrol ettik
	count=count/2; // yarýsý kadar gitmeli
	// çünkü her seferinde 2 eleman yazdýrdýðýmýz için
	
	while(count>0)
	{
		printf("%d -- ",g->val);
		g=g->next;
		printf("%d -- ",q->val);
		q=q->prev;
		count--;	
	}
	if(kalan == 1) // tek sayýda eleman var ise
	{
	 printf("%d",g->val);
	}
}
void sonaekle(int x) 
{
	node *yeni =(node*)malloc(sizeof(node));
	yeni->val = x;
	yeni->next =NULL;
	yeni->prev =NULL;
	if(bas ==NULL)
	{
		bas = yeni;
		son = yeni;
	}
	else{
		son->next = yeni;
		yeni->prev = son;
		son = yeni;		
	}
}
void basaekle(int x)
{
	node *yeni =(node*)malloc(sizeof(node));
	yeni->val = x;
	yeni->next =NULL;
	yeni->prev =NULL;
	if(bas == NULL)
	{
	  bas = yeni;
	  son = yeni;	
	}
	else{
		yeni->next = bas;
		bas->prev = yeni;
		bas = yeni;
	} 
}
void elemanekle(int x ,int loc)
{
	node *yeni =(node*)malloc(sizeof(node));
	yeni->val = x;
	yeni->next =NULL;
	yeni->prev =NULL;
	if(loc < 1){ // yanlýþ yer
		printf("loc yanlis\n");
		return;
	}
	if(bas == NULL) // hiç eleman yoksa
	{
		bas = yeni;
		son = yeni;
	}
	else{
		if(loc == 1) // baþa ekle
		{
			yeni->next =bas;
			bas->prev = yeni;
			bas = yeni;
			return;
			
		}
		int count = 1;
		node *g = bas, *q=bas;
		 while(g!=NULL && loc > count)
		 {
		    	q = g;
		 	 g = g->next;
		 	 count ++;
		 }
		 if(g == NULL) // sona eklenecek
		 {
		 	q->next = yeni;
		 	yeni->prev = q;
		 	son = yeni;
		 }
		 else{
		 q->next = yeni;
		 g->prev = yeni;
		 yeni->prev = q;
		 yeni->next = g;	
		 }
		
		
	}
}
void bastancikar()
{
	if(bas == NULL)
	{
		printf("eleman yok...\n");
		
	}
	else{
		bas = bas->next;
		bas->prev = NULL;
	}
}
void sondancikar()
{
	if(son == NULL)
	{
		printf("eleman yok\n");
	}
	else{
		son = son->prev;
		son->next = NULL;
	}
}
void elemansil(int loc)
{
	if(loc < 1){
	printf("yanlis konum\n");
	return;
	}
	if(bas == NULL)
	{
		printf("eleman yok\n");
		return;
	}
	else{
		if(loc == 1) // bastan cikar
		{
			bas = bas->next;
			bas->prev = NULL;
			return;
		}
		int count = 1;
		node *g =  bas ,*q=bas;
		while(g->next !=NULL && loc > count)
		{
			q=g;
			g=g->next;
			count++;
		}
		if(g->next == NULL)  // sona geldiyse
		{
		    son = son->prev;
		    son->next = NULL;
		}
		else{ // ortada bir yerdeyse
		q->next = g->next;
		q->next->prev=q;
	      free(g);
		}
			
	}
}
void sekle(int x)
{
	node *yeni =(node*)malloc(sizeof(node));
	yeni->val = x;
	yeni->next =NULL;
	yeni->prev =NULL;
	if(bas == NULL)
	{
		bas = yeni;
		son = yeni;
		
	}
	else{
		if(bas->val > yeni->val)
		{
			yeni->next = bas;
			bas->prev = yeni;
			bas= yeni;
			
		}
		node *g = bas ,*q= bas;
		while(g != NULL && g->val <= yeni->val)
		{
			q= g;
			g = g->next;
		}
		if(g == NULL) // sona geldiyse
		{
			son->next = yeni;
			yeni->prev = son;
			son = yeni;
		}
		else{
		q->next = yeni;
		yeni->next = g;
		g->prev = yeni;
		yeni->prev = q;	
		}
		
		
		
	}
}
void bastangoster()
{
	node *g = bas;
	if(bas == NULL) printf("eleman yok\n");
	while(g !=NULL)
	{
		printf("(%d) -- ",g->val);
		g = g->next;
	}
	printf("\n");
}

void sondangoster()
{
	node *g = son;
	while(g!=NULL)
	{
		printf("(%d)-- ", g->val);
		g = g->prev;
	}
	printf("\n");
}
main()
{
	int i =0;
   /*	for(i = 0; i<10;i++)
	sonaekle(i);
	bastangoster();
	sondangoster();
	basaekle(77);
	bastangoster();
	elemanekle(99,13);
	
	bastangoster();
	bastancikar();
	bastangoster();
	sondancikar();
	bastangoster();
	
	elemansil(11);
	bastangoster(); */
	
	int dizi[10] = {1,14,-9,7,2,-42,10,21,8,12};
	for(i = 0; i< 9 ;i++)
	sekle(dizi[i]);
	//sekle(dizi[i]);
	
	bastangoster();
	bassongoster();

}
