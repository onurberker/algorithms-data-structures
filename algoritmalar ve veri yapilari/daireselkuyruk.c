//dairesel kuyruk circular queue
#include<stdio.h>
#define s 5 // kuyruk kapasitesi
int kuyruk[s];
int bas=-1;
int son = -1;
int elemans = 0;
void ekle(int x)
{
	if ((bas == 0 && son == s-1)||(son == (bas-1)%(s-1))) 
    { 
        printf("\nQueue is Full"); 
        return; 
    } 
	else if (bas == -1) /* Insert First Element */
    { 
        bas = son = 0; 
        kuyruk[son] = x; 
    } 
  
    else if (son == s-1 && bas != 0) 
    { 
        son = 0; 
        kuyruk[son] = x; 
    } 
  
    else
    { 
        son++; 
        kuyruk[son] = x; 
    } 
	
}



int cikar()
{ 
    if (bas == -1) 
    { 
        printf("\nQueue is Empty"); 
        return -94499; 
    } 
  
    int temp = kuyruk[bas]; 
    kuyruk[bas] = -1; 
    
    /*else*/ if (bas == s-1) 
        bas = 0; 
    else
        bas++; 
  
    return temp; 
}
void goster()
{
	int i;
if (bas == -1) 
    { 
        printf("\nQueue is Empty"); 
        return; 
    } 
    printf("\nElements in Circular Queue are: "); 
    if (son >= bas) 
    { 
        for ( i = bas; i <= son; i++) 
            printf("%d ",kuyruk[i]); 
    } 
    else
    { 
        for ( i = bas; i < s; i++) 
            printf("%d ", kuyruk[i]); 
  
        for ( i = 0; i <= son; i++) 
            printf("%d ", kuyruk[i]); 
    }
	printf("\nBas = %d\n", bas);
	printf("\nSon = %d\n", son); 
	printf("\n-----------\n");
}

main()
{
	int i;
for(i = 1; i <= 5 ; i++)
 {
   ekle(i);
 }
	
	goster();
		
}
