

//1+1验证


/*
  Name: 
  Copyright: 
  Author: 
  Date: 28-08-07 10:02
  Description: 
*/


#include<iostream>
//#include<windows>
using namespace std;

int primetable[1000000]; //素数表 

void prime()  //素数表产生器 
{
    int temp[100000];     //临时数组 
    int size=100000;          //临时素数的最大值 
    for(int i=0;i<size;i++)
    {
        temp[i]=i;
    }
    for(int i=2;i*i<size;i++)  //求素数 
    {
        for(int k=i*i;k<size;k+=i)
        {
            temp[k] = 0;
        }
    }
    int j=0;
    for(int i=2;i<size;i++)
    {
        if(temp[i]!=0)
        {
            primetable[j++] = temp[i]; //临时素数写入素数表 
        }
    }
} 



int Goldbach(int num1,int num2)//歌德巴赫猜想 
{
    //cout<<"*********   0"<<endl;
    for(int aimnum=num1;aimnum<=num2;aimnum++)
    {
        if((aimnum%2)==0)//对区间的偶数进行操作 
        {
            //cout<<"*********   1"<<endl;
            int left=0, right; //区间游标 ，左边从0开始 
            for(int i=0;;i++)  //求区间内最大的素数 ,即求区间的右游标 
            {
                //cout<<"*********   2"<<endl;
                if(primetable[i]>=aimnum){ 
                    right = i-1;  //右游标 
                    break;
                }
            }
            while(left<=right)//用逼近法求验证歌德巴赫猜想 
            {
                //cout<<"*********   3"<<endl;
                if((primetable[left]+primetable[right])==aimnum)//歌德巴赫猜想成立 
                {
                    cout<<aimnum<<" = "<<primetable[left]<<" + "<<primetable[right]<<endl;
                    break;
                }
                
                //如果区间内的两素数和小于待求偶数则坐游标移动 ，如果大于则右游标移动 
                else if((primetable[left]+primetable[right])<aimnum)left++; 
                
                else if((primetable[left]+primetable[right])>aimnum)right--;
            }
        }
    }
    return 0;
}


int main()
{
    int min_num,max_num;//待输入的2个自然数 
    cout<<"input two number:";
    
    cin>>min_num>>max_num;
    
    if(max_num<min_num)//确保min_num<max_num 
    {
        swap(max_num,min_num);
    } 
    
    prime();//产生素数表 
    
    Goldbach(min_num,max_num);//验证歌德巴赫猜想 
    
    system("pause"); 
    
    return 1;
} 
