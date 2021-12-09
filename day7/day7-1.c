
#include <stdio.h>
#include <stdlib.h>

// #define NBR_I 10
#define NBR_I 1000

// int mode(int a[],int n) {
//    int maxValue = 0, maxCount = 0, i, j;

//    for (i = 0; i < n; ++i) {
//       int count = 0;
      
//       for (j = 0; j < n; ++j) {
//          if (a[j] == a[i])
//          ++count;
//       }
      
//       if (count > maxCount) {
//          maxCount = count;
//          maxValue = a[i];
//       }
//    }

//    return maxValue;
// }

void swap(int *p,int *q) {
   int t;
   
   t=*p; 
   *p=*q; 
   *q=t;
}

void sort(int a[],int n) { 
   int i,j,temp;

   for(i = 0;i < n-1;i++) {
      for(j = 0;j < n-i-1;j++) {
         if(a[j] > a[j+1])
            swap(&a[j],&a[j+1]);
      }
   }
}

int	main(void)
{
	int nbr[NBR_I];
	int i,j;
	int modus;
	int median;
	int fuel;

	FILE	*ptr = fopen("file.txt","r");

    if (ptr == NULL)
    {
        printf("ptr:no such file.\n");
        return 0;
    }
	for (i = 0; i < NBR_I; i++)
	{
		fscanf(ptr, "%d,", &nbr[i]);
	}
	fuel = 0;
	// modus = mode(nbr, NBR_I);
	sort(nbr, NBR_I);
	int n = NBR_I;

	n = (n+1) / 2 - 1;

	modus = nbr[n];
	for (i = 0; i < NBR_I; i++)
	{
		if (nbr[i] > modus)
			fuel += nbr[i] - modus;
		else if (nbr[i] < modus)
			fuel += modus - nbr[i];
	}
	printf("fuel = %d\n", fuel);
	return (0);
}
