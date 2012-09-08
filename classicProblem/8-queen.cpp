


#include <stdio.h> 
#include <conio.h> 
//#include <math.h> 
#include <stdlib.h> 


#define QUEENS 8 

//!��¼�����ŵ�ȫ�ֱ���? 
int iCount = 0; 

//!��¼�ʺ��ڸ����ϵķ���λ�õ�ȫ������? 
int Site[QUEENS]; 

//!�ݹ����ĺ���? 
int Queen(int n); 

//!���һ����? 
int Output(); 

//!�жϵ�n���ʺ����ȥ֮��,�Ƿ��г�ͻ? 
int IsValid(int n); 

/*----------------------------Main:������?----------------------------*/ 
int main() 
{ 
    Queen(0); 
    getch(); 
     return 0;
} 

/*-----------------Queen:�ݹ���õ�n���ʺ�,����ĺ���!----------------*/ 
int Queen(int n) 
{ 
    int i;
  if(n == QUEENS) 
  { 
    Output(); 
    return 0; 
   }        
   //!n��û��8,�ڵ�n�еĸ�������������̽? 
   for(i = 1 ; i <= QUEENS ; i++) 
   { 
         //!�ڸ��еĵ�i���Ϸ��ûʺ�? 
         Site[n] = i; 

         //!�������û�г�ͻ,�Ϳ�ʼ��һ�е���̽? 
         if(IsValid(n)) 
               Queen(n + 1); 
   } 
} 

/*------IsValid:�жϵ�n���ʺ����ȥ֮��,�Ƿ�Ϸ�,���Ƿ��޳�ͻ?------*/ 
int IsValid(int n) 
{ 
     int i; 

     //!����n���ʺ��λ��������ǰ��n-1���ʺ��λ�ñȽ�? 
     for(i = 0 ; i < n ; i++) 
     { 
           //!�����ʺ���ͬһ����,����0? 
           if(Site[i] == Site[n]) 
                 return 0; 

           //!�����ʺ���ͬһ�Խ�����,����0? 
           if(abs(Site[i] - Site[n]) == (n - i)) 
                 return 0;
     } 

     //!û�г�ͻ,����1? 
     return 1; 
} 

/*------------Output:���һ����,��һ��û�г�ͻ�ķ��÷���?------------*/ 
int Output() 
{ 
     int i; 

     //!������? 
     printf("No.%-5d" , ++iCount); 

     //!��������������ϵĻʺ��λ��,�����ڵ�����? 
     for(i = 0 ; i < QUEENS ; i++) 
           printf("%d " , Site[i]); 

     printf("\n"); 
}
