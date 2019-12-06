#define _CRT_SECURE_NO_WARNINGS 1
#pragma  once

#include<stdio.h>
#include<stdlib.h>
#include"contect.h"
#include<memory.h>


int main()
{

	FILE* fpIn = fopen("D:\\软件工具\\fff.jpeg", "rb");
	if (NULL == fpIn)
	{
		printf("open file1 fail\n");
		return 0;
	}

	FILE* fpOut = fopen("D:\\fff.jpeg","wb");
	if (NULL == fpOut)
	{
		printf("open file2 fail\n");
		fclose(fpIn);
		return 0;
	}
	char buf[128];
	size_t count = 0;
	while (!feof(fpIn))
	{
		count=fread(buf, sizeof(char),128, fpIn);
		fwrite(buf, sizeof(char),count,fpOut);
	}
	fclose(fpIn);
	fclose(fpOut);


	system("pause");
	return 0;
}

#if 0
int main(int argc,char *argv[])
{
	FILE * fpIn = fopen("test.cpp", "r");
	if (NULL == fpIn)
	{
		printf("open file1 fail\n");
		system("pause");
		return -1;
	}
	FILE * fpOut = fopen("D:\\test2.txt", "w");
	if (NULL == fpOut)
	{
		printf("open feile2 fail\n");
		fclose(fpIn);
		system("pause");
		return -1;
	}
	char buffer[128];
	memset(buffer, 0, sizeof(buffer));
	char *ret =fgets(buffer,128,fpIn);
//	printf("buffer=%s\n", buffer);
	while (ret != NULL)
	{
		fputs(buffer, fpOut);
		memset(buffer, 0, sizeof(buffer));
		ret = fgets(buffer,128,fpIn);
	}

	fclose(fpIn);
	fclose(fpOut);
	system("pause");
	return 0;
}

#endif
#if 0
int main()
{
	FILE * fpIn = fopen("D:\\测试文件\\test1.txt", "r");
	if (NULL == fpIn)
	{
		printf("open file1 fail\n");
		system("pause");
		return -1;
	}
	FILE * fpOut = fopen("D:\\test.txt", "w");
	if (NULL == fpOut)
	{
		printf("open feile2 fail\n");
		fclose(fpIn);
		system("pause");
		return -1;
	}
	char ch = fgetc(fpIn);
	while (ch != EOF)
	{
		fputc(ch, fpOut);
		ch = fgetc(fpIn);
	}

	fclose(fpIn);
	fclose(fpOut);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int arr[10];
	int n = sizeof(arr) / sizeof(arr[0]);
	FILE  * fp1 = fopen("D:\\测试文件\\test1.txt", "r");
	//FILE  * fp2 = fopen("D:\\test2,txt", "r");
	if (NULL == fp1)
	{
		printf("open file fail\n");
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		fscanf(fp1, "%d", &arr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}

	fclose(fp1);
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	FILE* fp = fopen("D:\\测试文件\\test2.txt", "a");
	if (NULL == fp)
	{
		printf("open file fail\n");
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		fprintf(fp, "%d ", arr[i]);
	}


	fclose(fp);
	system("pause");
	return 0;
}
#endif



