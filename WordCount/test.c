/*----------------------------------------------------------------
 Copyright (C) 2021 pansy

 filename：test.c

 function：程序统计文本文件（纯英文）的字符数或者单词数

 history：
 number		date		author		discribe
 01			2021-5-5	pansy		创建该文件	
----------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
@function 统计文件的字符数

@param file 文件位置

@return 成功返回统计数据，否则返回0
*/
int CountChar(char *file)
{   
	FILE *fp;//指向文件的指针
	char a;//读取的字符
	int CharCount=0;//字符数
	fp = fopen(file, "r");
	if((fp=fopen(file,"r"))==NULL)
	{
		printf("文件不能打开\n");
	}
	while (!feof(fp))
	{
		a=fgetc(fp);
		CharCount++;
	}
	fclose(fp);
	printf("字符数:%d\n",CharCount-1);
	return 0;
}
/*
@function 统计文件的单词数

@param file 文件位置

@return 成功返回统计数据，否则返回0
*/
int CountWords(char *file)
{  
	FILE *fp;//指向文件的指针
    char words[5000];//存储读取到的内容
    char c;//读取到的字符
    int LastWord = 0; //标志上个字符，0代表不是空格或逗号，1代表是空格或逗号
    int WordCount=0;//单词数目
    int i;//循环变量，读取到的第i个字符
    if((fp=fopen(file,"r"))==NULL)
	{
        printf("文件不能打开\n");
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
		printf("单词数：%d\n",WordCount);
	return 0;
}	
int main(int argc, char* argv[])             
{
	CountChar("D:\\git\\learngit\\WordCount\\WordCount\\input.txt");
	CountWords("D:\\git\\learngit\\WordCount\\WordCount\\input.txt");
	getchar();
    return 0;
}
