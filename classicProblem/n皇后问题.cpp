#include<iostream>
using namespace std;
 
int attacked(int *array,int position){ 
   int flag=-1; 
   float step; 
   if(position==1) return flag; 
   for(step=1.00;step<position;step++){ 
if(*(array+(int)step)==*(array+position)||step==position) return
1; 
if(((*(array+(int)step)-*(array+position))/(step-position))==1||((*
(array+(int)step)-*(array+position))/(step-position))==-1){ 
flag=1; 
break; 
} 
} 
return flag; 
} 
int main( ){ 
int countSum,queenSum,printCount,*queenArray,queenPosition=0; 
int tempArray[20]={6666,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
countSum=1; 
queenArray=tempArray; 
printf("input you queenSum here:"); 
scanf("%d",&queenSum); 
fflush(stdin); 
if(queenSum<4){ 
printf("the %d queen's sum is 0\n",queenSum); 
return 0; 
} 
for(;;){ 
if(countSum<queenSum){ 
if(countSum==1&&*(queenArray+countSum)==1) countSum++; 
if(attacked(queenArray,countSum)==1){ 
if(*(queenArray+countSum)>=queenSum){ 
  if(*(queenArray+countSum-1)<queenSum){ 
++*(queenArray+(--countSum)); 
*(queenArray+countSum+1)=0; 
} 
else{ 
*(queenArray+countSum--)=0; 
if(*(queenArray+countSum)<queenSum) ++*(queenArray+countSum); 
else{ 
if(countSum==1&&*(queenArray+countSum)==queenSum) break; 
*(queenArray+countSum--)=0; 
++*(queenArray+countSum); 
} 
} 
} 
else 
++*(queenArray+countSum); 
} 
else 
++*(queenArray+(++countSum)); 
} 
else{ 
if(attacked(queenArray,countSum)==1){ 
if(*(queenArray+countSum)>=queenSum){ 
   if(*(queenArray+countSum-1)<queenSum){ 
++*(queenArray+(--countSum)); 
*(queenArray+countSum+1)=0; 
continue; 
} 
else{ 
*(queenArray+countSum--)=0; 
if(*(queenArray+countSum)<queenSum) ++*(queenArray+countSum); 
else{ 
*(queenArray+countSum--)=0; 
++*(queenArray+countSum); 
} 
continue; 
} 
} 
else { 
++*(queenArray+countSum); 
continue; 
} 
} 
queenPosition++; 
for(printCount=1;printCount<=queenSum;printCount++) 
printf("%3d%",*(queenArray+printCount)); 
if(printCount>=queenSum) printf("\n"); 
   if(*(queenArray+countSum)>=queenSum){ 
      ++*(queenArray+(--countSum)); //the "++" priority is different
 //from turbo C 
  *(queenArray+countSum+1)=0; 
   } 
   ++*(queenArray+countSum); 
 } 
   } 
   printf("the %d queen's sum is %d\n",queenSum,queenPosition); 
   
   system("pause");
}
