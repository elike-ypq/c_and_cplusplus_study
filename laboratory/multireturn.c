#include<stdio.h>
#include <stdlib.h>//头文件，因为用到了srand函数
#include <time.h> //用到了time函数 
#define N 10
#define M 10 //数组大小
//生成一个随机整数0~99
void my_random(int [N][M]);
//找出一个数，并记录该数的行和列
int find_num1_1(int [N][M],int ,int *);
int *find_num1_2(int [N][M],int );
int find_num2(int [N][M],int , int (*)[2]);
int same_num(int [N][N],int );
//打印输出
void my_print(int [N][M]);
int main()
{
	int s,n;
	int a[N][M];
	int *c;
	int (*cc)[2];

	c=(int *)malloc(2*sizeof(int));
	my_random(a);
	my_print(a);
	puts("Please input a number that you want to find in the array");
	scanf("%d",&s);
	n=same_num(a,s);
	cc=(int (*)[2])malloc(n*2*sizeof(int));
	if(find_num2(a,s,cc)!=0)
		while(n--)
			printf("number is in the (%d,%d)\n",cc[n][0],cc[n][1]);
	else
		printf("can't find it\n");
	free(cc);
	//if(find_num1_1(a,s,c)==1)
	if((c=find_num1_2(a,s))!=NULL)
		printf("number is in the (%d,%d)\n",c[0],c[1]);
	else
		printf("can't find it\n");
	free(c);
	return 0;
}
int find_num2(int a[N][M],int s, int (*c)[2])
{
	int i,j,n=0;
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			if(a[i][j]==s)
			{
				c[n][0]=i,c[n][1]=j;
				n++;
			}
	return n;
}
int same_num(int a[N][N],int s)
{
	int i,j,n=0;
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			if(a[i][j]==s)
				++n;
	return n;
}
int *find_num1_2(int a[N][M],int s)
{
	int *co;
	int i,j;

	co=(int *)malloc(2*sizeof(int));
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			if(a[i][j]==s)
			{
				co[0]=i;co[1]=j;
				return co;
			}
	free(co);
	co=NULL;
	return co;
}
void my_print(int a[N][M])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			printf("%4d",a[i][j]);
		putchar('\n');
	}
}
int find_num1_1(int a[N][M],int s,int *c)
{
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			if(a[i][j]==s)
			{
				c[0]=i;c[1]=j;
				return 1;
			}
	return 0;
}
void my_random(int a[N][M])
{
	int i,j;

	srand((unsigned) time(NULL)); //用时间做种子，每次产生随机数不一样
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			a[i][j] = rand() % 100;
}   
