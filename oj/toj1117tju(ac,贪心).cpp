/*tju1117,̰�ģ�ģ��ac
   2006.8.7*/
#include<stdio.h>
#include<string.h>
int main()
{
  int m, n, i, j, count, total, cases;
  int pips[3000], round[3000];
  scanf("%d %d", &m, &n);
  cases = 1;
  while(m || n)
  {
    memset(round, 0, sizeof(round));
    for(i=1; i<=n; i++)
    {
        scanf("%d", &pips[i]);
        round[pips[i]] = 1;
    }
    total = m*n;
    count = 1;
    for(i=1; i<=total && count<=n; i++)
    {
        if(round[i] == 1) pips[count++] = i;
    }
    count=0;
    for(i=1; i<=n; i++)
    {
        j = 1;
        while(j<m-1)
        {
          count++;
          if(count>total) break; /*���紦��*/
          if(round[count] == 0)
          {
            round[count] = 1;
            j++;
          }
        } /*whileѭ������*/
        for(j=pips[i]+1; j<=total; j++)
        {
          if(round[j] == 0)
          {
            round[j] = 1;
            break;
          }
        }
        if(j == total+1)
        {
          printf("Case %d: %d\n", cases++, n-i+1);
          break;
        }
    }
    if(i == n+1) printf("Case %d: 0\n", cases++);
    scanf("%d %d", &m, &n);
  }
  return 0;
}
