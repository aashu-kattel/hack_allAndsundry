#include <stdio.h>
#include <string.h>

static void display(int intArray[], int length){
   int i=0;
   printf("Array : [");
   for(i = 0; i < length; i++) {
      /* display value of element at index i. */
      printf(" %d ", intArray[i]);
   }
   printf(" ]\n ");   
}

int main() {
   int i = 0;
   /* Declare an array */
   int intArray[8];

   // initialize elements of array n to 0          
   for ( i = 0; i < 8; i++ ) {
      intArray[ i ] = 0; // set elements to default value of 0;
   }
   printf("Array with default data.");

   /* Display elements of an array.*/
   display(intArray,8);     

   /* Operation : Insertion 
   Add elements in the array */
   for(i = 0; i < 8; i++) {
      /* place value of i at index i. */
      printf("Adding %d at index %d\n",i,i);
      intArray[i] = i;
   }
   printf("\n");
   printf("Array after adding data. ");
   display(intArray,8);

   /* Operation : Insertion 
   Element at any location can be updated directly */
   int index = 5;
   intArray[index] = 10;

   printf("Array after updating element at index %d.\n",index);
   display(intArray,8);

   /* Operation : Search using index
   Search an element using index.*/
   printf("Data at index %d:%d\n" ,index,intArray[index]);

   /* Operation : Search using value
   Search an element using value.*/
   int value = 4;
   for(i = 0; i < 8; i++) {
      if(intArray[i] == value ){
         printf("value %d Found at index %d \n", intArray[i],i);
         break;
      }
   }
   return 0;
}
