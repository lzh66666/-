//#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef float ElemType;
typedef int Status;
typedef ElemType* Triplet;

Status InitTriplet(Triplet &T,ElemType v1,ElemType v2,ElemType v3);// ������Ԫ�� 
Status DestroyTriplet(Triplet &T);//������Ԫ�� 
Status getElem(Triplet &T,Status i,ElemType &e);//ȡ��Ԫ���һ���� 
Status putElem(Triplet &T,Status i,ElemType &e);//����Ԫ���з�һ���� 
Status IsAscending(Triplet T);//�ж���Ԫ���Ƿ����� 
Status IsDescending(Triplet T);//�ж���Ԫ���Ƿ��� 
Status getMax(Triplet T,ElemType &e);//����Ԫ�������ֵ 
Status getMin(Triplet T,ElemType &e);//����Ԫ������Сֵ 




int main(int argc, char** argv) 
{
	Triplet T;
	ElemType v1,v2,v3,e;
	Status flag,i;
	
	//��ʼ����Ԫ�� 
	printf("������3�����ִ�������Ԫ����:\n");
	scanf("%f%f%f",&v1,&v2,&v3);
	flag=InitTriplet(T,v1,v2,v3);
	if(flag==OK)
	{
		printf("��Ԫ���ʼ���ɹ���Ԫ���ֵ�ֱ�Ϊ%4.2f %4.2f %4.2f\n",T[0],T[1],T[2]);
	}
		
	//�ж���Ԫ���Ƿ������� 
	if(IsAscending(T))
	{
        printf("����Ԫ������\n");
	} 
	
	//�ж���Ԫ���Ƿ��ǽ��� 
	if(IsDescending(T))
	{
		printf("����Ԫ�齵��\n");
	} 

	//ȡ��Ԫ���ֵ 
	printf("����������ȡ����Ԫ���еڼ���Ԫ�ص�ֵ\n");
	scanf("%d",&i); 
	flag=getElem(T,i,e);
	printf("��%d��Ԫ�ص�ֵΪ%4.2f\n",i,e);
	
	//����Ԫ���з�һ��ֵ
	printf("����������Ҫ�����λ�ú���ֵ:\n"); 
	scanf("%d%f",&i,&e);
	putElem(T,i,e);
	printf("�µ���Ԫ���ֵΪ:%4.2f %4.2f %4.2f\n",T[0],T[1],T[2]);
	
	//�����ֵ
	getMax(T,e);
	printf("����Ԫ���е����ֵΪ��%4.2f\n",e);
	//����Сֵ
	getMin(T,e);
	printf("����Ԫ���е����СֵΪ��%4.2f\n",e); 


	//������Ԫ�� 
	flag=DestroyTriplet(T); 
	if(flag==OK)
		printf("��Ԫ�����ٳɹ�\n");
	return 0;
}

//������Ԫ��
Status InitTriplet(Triplet &T,ElemType v1,ElemType v2,ElemType v3)
{
	T=(ElemType*)malloc(3*sizeof(ElemType));
	if(T==NULL)//�ж��Ƿ����ɹ� 
	exit(OVERFLOW);	
	T[0]=v1;
	T[1]=v2;
	T[2]=v3;
	return OK;
} 
//������Ԫ��
Status DestroyTriplet(Triplet &T)
{
	free(T);//���ͷ��ڴ� 
	T=NULL;
	return OK; 
}
//ȡ��Ԫ���һ����
Status getElem(Triplet &T,Status i,ElemType &e)
{
	if(i<1||i>3)
		return ERROR;
	else
		e=T[i-1];
	return OK;
} 
//����Ԫ���д��һ����
Status putElem(Triplet &T,Status i,ElemType &e)
{
	if(i<1||i>3)
		return ERROR;
	else
		T[i-1]=e;
	return OK;
} 
//�ж���Ԫ���Ƿ�����
Status IsAscending(Triplet T)
{
	return(T[0]<=T[1])&&(T[1]<=T[2]);
}
//�ж���Ԫ���Ƿ���
Status IsDescending(Triplet T)
{
	return(T[0]>=T[1])&&(T[1]>=T[2]);
} 
//�����ֵ
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
//����Сֵ
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
