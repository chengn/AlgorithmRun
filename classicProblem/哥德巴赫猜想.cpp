

//1+1��֤


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

int primetable[1000000]; //������ 

void prime()  //����������� 
{
    int temp[100000];     //��ʱ���� 
    int size=100000;          //��ʱ���������ֵ 
    for(int i=0;i<size;i++)
    {
        temp[i]=i;
    }
    for(int i=2;i*i<size;i++)  //������ 
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
            primetable[j++] = temp[i]; //��ʱ����д�������� 
        }
    }
} 



int Goldbach(int num1,int num2)//��°ͺղ��� 
{
    //cout<<"*********   0"<<endl;
    for(int aimnum=num1;aimnum<=num2;aimnum++)
    {
        if((aimnum%2)==0)//�������ż�����в��� 
        {
            //cout<<"*********   1"<<endl;
            int left=0, right; //�����α� ����ߴ�0��ʼ 
            for(int i=0;;i++)  //���������������� ,������������α� 
            {
                //cout<<"*********   2"<<endl;
                if(primetable[i]>=aimnum){ 
                    right = i-1;  //���α� 
                    break;
                }
            }
            while(left<=right)//�ñƽ�������֤��°ͺղ��� 
            {
                //cout<<"*********   3"<<endl;
                if((primetable[left]+primetable[right])==aimnum)//��°ͺղ������ 
                {
                    cout<<aimnum<<" = "<<primetable[left]<<" + "<<primetable[right]<<endl;
                    break;
                }
                
                //��������ڵ���������С�ڴ���ż�������α��ƶ� ��������������α��ƶ� 
                else if((primetable[left]+primetable[right])<aimnum)left++; 
                
                else if((primetable[left]+primetable[right])>aimnum)right--;
            }
        }
    }
    return 0;
}


int main()
{
    int min_num,max_num;//�������2����Ȼ�� 
    cout<<"input two number:";
    
    cin>>min_num>>max_num;
    
    if(max_num<min_num)//ȷ��min_num<max_num 
    {
        swap(max_num,min_num);
    } 
    
    prime();//���������� 
    
    Goldbach(min_num,max_num);//��֤��°ͺղ��� 
    
    system("pause"); 
    
    return 1;
} 
