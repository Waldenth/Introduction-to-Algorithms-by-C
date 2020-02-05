#include <stdio.h>
#include <stdlib.h>
#define INF 100000
//15.2�������˷�
int Matrix_Chain_Order(int p[],int n)//[p0,p1....pn]
//1�ž�������p0,����p1   n�ž�������pn-1����pn 
{
	int length=n+1;
	
	int **m;
	int **s;
	//m,s����: 	m[i][j]���i��j�ž�����˵���С���� 
	//		   	s[i][j]���m[i][j]��Ӧ�����ŷָ��	
	
	m=(int**)malloc(sizeof(int*)*(length));
	s=(int**)malloc(sizeof(int*)*(length));
	for(int i=0;i<=n;i++)
	{
		m[i]=(int *)malloc(sizeof(int )*length);
		s[i]=(int *)malloc(sizeof(int )*length);
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			m[i][j]=-1;
			s[i][j]=-1;
		}
	for(int i=1;i<=n;i++)
		m[i][i]=0;//i�ž���i�ž�������ļ��㵱ȻΪ0�� 
	for(int len=2;len<=n;len++)//len��Ŀǰ�����һ���������ĳ��� 
	{
		for(int i=1;i<=n-len+1;i++)
		{
			int j=i+len-1;//��i�ſ�ʼ��j�Ź��ɵľ����������ڳ���Ϊlen,����j�ı�ž���i+len-1	
			/*
			m[i][j]�ļ���ֻ������i��j����Щ����С��j-i+1 (����j-i+1������)�����������ż������ 
			*/
			m[i][j]=INF; 
			for(int k=i;k<=j-1;k++)//�ָ�㣬 ����������Ϊi...k�ź�k+1...j�� 
			{
				int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
					
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			printf("%d ",s[i][j]);
		}
		printf("\n");
	}
		
	return m[1][n];
}

int main()
{
	//printf("%d",INF);
	int p[7]={30,35,15,5,10,20,25};
	int w=Matrix_Chain_Order(p,6);
	printf("w=%d",w);
}




