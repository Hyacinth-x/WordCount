/*----------------------------------------------------------------
 Copyright (C) 2021 pansy

 filename��test.c

 function������ͳ���ı��ļ�����Ӣ�ģ����ַ������ߵ�����

 history��
 number		date		author		discribe
 01			2021-5-5	pansy		�������ļ�	
----------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
@function ͳ���ļ����ַ���

@param file �ļ�λ��

@return �ɹ�����ͳ�����ݣ����򷵻�0
*/
int CountChar(char *file)
{   
	FILE *fp;//ָ���ļ���ָ��
	char a;//��ȡ���ַ�
	int CharCount=0;//�ַ���
	fp = fopen(file, "r");
	if((fp=fopen(file,"r"))==NULL)
	{
		printf("�ļ����ܴ�\n");
	}
	while (!feof(fp))
	{
		a=fgetc(fp);
		CharCount++;
	}
	fclose(fp);
	printf("�ַ���:%d\n",CharCount-1);
	return 0;
}
/*
@function ͳ���ļ��ĵ�����

@param file �ļ�λ��

@return �ɹ�����ͳ�����ݣ����򷵻�0
*/
int CountWords(char *file)
{  
	FILE *fp;//ָ���ļ���ָ��
    char words[5000];//�洢��ȡ��������
    char c;//��ȡ�����ַ�
    int LastWord = 0; //��־�ϸ��ַ���0�����ǿո�򶺺ţ�1�����ǿո�򶺺�
    int WordCount=0;//������Ŀ
    int i;//ѭ����������ȡ���ĵ�i���ַ�
    if((fp=fopen(file,"r"))==NULL)
	{
        printf("�ļ����ܴ�\n");
        exit(0);
    }
	while(fgets(words,1000,fp)!=NULL)
	{	
        for(i=0;i<strlen(words);i++)
		{
            c=words[i];
            if(c==' ' ||c==',')
			{
                if(LastWord==0)
				{
                    WordCount++;
                }
                LastWord=1;
            }
			else if(c!='\n'&&c!='\r')
			{
                LastWord=0;
            }
 
        } 
        if(LastWord==0)
            WordCount++;
        LastWord=1;
    }
    fclose(fp); 
		printf("��������%d\n",WordCount);
	return 0;
}	
int main(int argc, char* argv[])             
{
	CountChar("D:\\git\\learngit\\WordCount\\WordCount\\input.txt");
	CountWords("D:\\git\\learngit\\WordCount\\WordCount\\input.txt");
	getchar();
    return 0;
}
