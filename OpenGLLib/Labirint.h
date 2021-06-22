#pragma once  //����� , ����� ���� ����������� ������ ���� ��� 
#include<stdio.h>
#include<stdlib.h>
struct walls* readfromfile(const char* fname );
struct walls
{
	int kolstrok;
	int kolstolb;
	bool** p; // ��������� ,��� ���������� ����� �� ����� �������� ����� ������ ������ ��������� 
};


struct walls* readfromfile(const char* fname) // ���������� ��������� �� walls
{
	FILE *fp = fopen(fname,"r");
	if (fp == NULL)
		return 0;
	struct walls *sten=(struct walls*)malloc(sizeof(struct walls));//��������� �� �����
	fscanf(fp, "%d %d", &sten->kolstrok,&sten->kolstolb);
	sten->p=(bool**)malloc(sizeof(bool*)*sten->kolstrok);//�� ��������� ���������� ��������� // ��������� ������ ��� ��������� �� ����� ������ 
	for (int i = 0; i < sten->kolstrok; i++)     //*(sten).kolstrok
	{
		sten->p[i] = (bool *)malloc(sizeof(bool)*sten->kolstolb);
	}
	for (int i = 0; i < sten->kolstrok;i++)    // ������� �� �������
	{
		for (int j = 0; j < sten->kolstolb; j++) // �� ��������� � c������� 
		{
			fscanf(fp, "%d", &sten->p[i][j]);
		}                                          
	}
	fclose(fp);
	return(sten);
}


