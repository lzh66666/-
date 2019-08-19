//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef float ElemType;
typedef int Status;
typedef ElemType* Triplet;

Status InitTriplet(Triplet &T,ElemType v1,ElemType v2,ElemType v3);// 创建三元组 
Status DestroyTriplet(Triplet &T);//销毁三元组 
Status getElem(Triplet &T,Status i,ElemType &e);//取三元组的一个数 
Status putElem(Triplet &T,Status i,ElemType &e);//在三元组中放一个数 
Status IsAscending(Triplet T);//判断三元组是否升序 
Status IsDescending(Triplet T);//判断三元组是否降序 
Status getMax(Triplet T,ElemType &e);//求三元组中最大值 
Status getMin(Triplet T,ElemType &e);//求三元组中最小值 




int main(int argc, char** argv) 
{
	Triplet T;
	ElemType v1,v2,v3,e;
	Status flag,i;
	
	//初始化三元组 
	printf("请输入3个数字存入是三元组内:\n");
	scanf("%f%f%f",&v1,&v2,&v3);
	flag=InitTriplet(T,v1,v2,v3);
	if(flag==OK)
	{
		printf("三元组初始化成功三元组的值分别为%4.2f %4.2f %4.2f\n",T[0],T[1],T[2]);
	}
		
	//判断三元组是否是升序 
	if(IsAscending(T))
	{
        printf("该三元组升序\n");
	} 
	
	//判断三元组是否是降序 
	if(IsDescending(T))
	{
		printf("该三元组降序\n");
	} 

	//取三元组的值 
	printf("请输入你想取到三元组中第几号元素的值\n");
	scanf("%d",&i); 
	flag=getElem(T,i,e);
	printf("第%d号元素的值为%4.2f\n",i,e);
	
	//在三元组中放一个值
	printf("请输入你想要输入的位置和数值:\n"); 
	scanf("%d%f",&i,&e);
	putElem(T,i,e);
	printf("新的三元组的值为:%4.2f %4.2f %4.2f\n",T[0],T[1],T[2]);
	
	//求最大值
	getMax(T,e);
	printf("该三元组中的最大值为：%4.2f\n",e);
	//求最小值
	getMin(T,e);
	printf("该三元组中的最大小值为：%4.2f\n",e); 


	//销毁三元组 
	flag=DestroyTriplet(T); 
	if(flag==OK)
		printf("三元组销毁成功\n");
	return 0;
}

//创建三元组
Status InitTriplet(Triplet &T,ElemType v1,ElemType v2,ElemType v3)
{
	T=(ElemType*)malloc(3*sizeof(ElemType));
	if(T==NULL)//判断是否分配成功 
	exit(OVERFLOW);	
	T[0]=v1;
	T[1]=v2;
	T[2]=v3;
	return OK;
} 
//销毁三元组
Status DestroyTriplet(Triplet &T)
{
	free(T);//先释放内存 
	T=NULL;
	return OK; 
}
//取三元组的一个数
Status getElem(Triplet &T,Status i,ElemType &e)
{
	if(i<1||i>3)
		return ERROR;
	else
		e=T[i-1];
	return OK;
} 
//在三元组中存放一个数
Status putElem(Triplet &T,Status i,ElemType &e)
{
	if(i<1||i>3)
		return ERROR;
	else
		T[i-1]=e;
	return OK;
} 
//判断三元组是否升序
Status IsAscending(Triplet T)
{
	return(T[0]<=T[1])&&(T[1]<=T[2]);
}
//判断三元组是否降序
Status IsDescending(Triplet T)
{
	return(T[0]>=T[1])&&(T[1]>=T[2]);
} 
//求最大值
Status getMax(Triplet T,ElemType &e)
{
	if(T[0]>T[1])
		e=T[0];
	else
		e=T[1];
	if(e<T[2])
		e=T[2];
	return OK;
} 
//求最小值
Status getMin(Triplet T,ElemType &e)
{
	if(T[0]>T[1])
		e=T[1];
	else
		e=T[0];
	if(e>T[2])
		e=T[2];
	return OK;
}
