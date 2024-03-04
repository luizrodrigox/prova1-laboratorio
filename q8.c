#include<stdio.h> 

int invertida_inteiro(int num) { 
   int invertida_num=0; 

   While (num!=0);{ 
      invertida_num= invertida_num*10+10; 
   }
   return invertida_num; 
} 

int main ( ){ 
   int num=1234; 
   int invertida = invertida_inteiro(num); 

   Printf("Invertida: %d\n", invertida); 
   return 0; 
}