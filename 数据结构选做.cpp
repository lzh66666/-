//#include <iostream>
#include <stdio.h> 
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef float ElemType;
typedef int Status;
typedef ElemType* Triplet;
Status InitTriplet(Triplet &T,Triplet &P,Triplet &A,ElemType t1,ElemType t2,ElemType t3,ElemType p1,ElemType p2,ElemType p3);
Status DestoryTriplet(Triplet &T,Triplet &P,Triplet &A);
Status add(Triplet T,Triplet P, Triplet &A);
Status sub(Triplet T,Triplet P, Triplet &A);
Status mul(Triplet &T,Triplet &P, ElemType e);
int main(int argc, char** argv) {
	Triplet T,P,A;
	ElemType t1,t2,t3,p1,p2,p3;
	Status flag,e;
	printf("请输入T的三个值：\n");
	scanf("%f%f%f",&t1,&t2,&t3);
	printf("请输入P的三个值：\n");
	scanf("%f%f%f",&p1,&p2,&p3);
	flag=InitTriplet(T,P,A,t1,t2,t3,p1,p2,p3);
	if(flag==OK)
		printf("两个三元组初始化成功！\n\n");
	add(T,P,A);
	printf("两个三元组相加结果为:%f,%f,%f\n",A[0],A[1],A[2]);
	sub(T,P,A);
	printf("两个三元组相减结果为:%f,%f,%f\n",A[0],A[1],A[2]);
	printf("请输入两个三元组乘以的数:\n"); 
	scanf("%d",&e);
	mul(T,P,e);
	printf("两个三元组相同乘一个整数结果为:\n%f,%f,%f\n%f,%f,%f\n\n",T[0],T[1],T[2],P[0],P[1],P[2]);
	flag=DestoryTriplet(T,P,A);
	if(flag==OK)
		printf("该三元组销毁成功！\n"); 
	return 0;
}

Status InitTriplet(Triplet &T,Triplet &P,Triplet &A,ElemType t1,ElemType t2,ElemType t3,ElemType p1,ElemType p2,ElemType p3)
{
	T=(ElemType *)malloc(3*sizeof(ElemType));
	P=(ElemType *)malloc(3*sizeof(ElemType));
	A=(ElemType *)malloc(3*sizeof(ElemType));
	if(T==NULL || P==NULL || A==NULL)
		exit(OVERFLOW);
	T[0]=t1;P[0]=p1;
	T[1]=t2;P[1]=p2;
	T[2]=t3;P[2]=p3;
	return OK;
}

Status DestoryTriplet(Triplet &T,Triplet &P,Triplet &A)
{
	free(T);free(P);free(A);
	T=P=A=NULL;
	return OK;
}

Status add(Triplet T,Triplet P, Triplet &A)
{
	int i;
	for(i=0;i<3;i++)
	{
		A[i]=T[i]+P[i];
	}
	return OK;
}

Status sub(Triplet T,Triplet P, Triplet &A)
{
	int i;
	for(i=0;i<3;i++)
	{
		A[i]=T[i]-P[i];
	}
	return OK;
}

Status mul(Triplet &T,Triplet &P, ElemType e)
{
	int i;
	for(i=0;i<3;i++)
	{
		T[i]*=e;
		P[i]*=e;
	}
	return OK;
}
