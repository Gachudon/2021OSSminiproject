#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"
#include "manager.h"


int loadFruit(Fruit *f,int *count)
{
	int i = 0;
	FILE* pp;
	pp = fopen("product.txt","rt");
	if(pp == NULL)
	{
		return -1;
	}
	while(1)
	{
		fscanf(pp, "%s %d %d %d %d",f[i].name, &f[i].weight, &f[i].price, &f[i].star, &f[i].starnum);
		if(feof(pp)) break;
		i++;
	}
	*count = i;
	fclose(pp);
	return 0;
}

int saveFruit(Fruit *f, int count)
{
	FILE *fd = fopen("product.txt","wt");
	if(fd == NULL)
	{
		return -1;
	}
	for(int i = 0; i<count ; i++)
	{
		if(f[i].weight == -1) continue;
		else fprintf(fd, "%s %d %d %d %d\n",f[i].name, f[i].weight, f[i].price, f[i].star, f[i].starnum);
	}
	fclose(fd);
	return 1;
}

void searchFruitName(Fruit *f, int count)
{
	char search[20];
	printf("제품명검색: ");
	scanf("%s",search);
	for(int i = 0; i<count;i++)
	{
		if(strcmp(search,f[i].name) == 0)
		{
			printf("\nNo Name Price Weight Star The number of Stars\n");
			printf("=============================================\n");
			printf("%2d ", i+1);
			readFruit(f[i]);
			break;
		}
	}
}

void searchPrice(Fruit *f, int count)
{
	int search;
	printf("가격검색: ");
	scanf("%d",&search);
	for(int i = 0; i<count;i++)
	{
		if(search == f[i].price)
		{
			printf("\nNo Name Price Weight Star The number of Stars\n");
			printf("=============================================\n");
			printf("%2d ", i+1);
			readFruit(f[i]);
			break;
		}
	}	
}

void searchWeight(Fruit *f,int count)
{
	int search;
	printf("무게검색: ");
	scanf("%d", &search);
	for(int i = 0;i <count; i++)
	{
		if(f[i].weight == search)
		{
			printf("\nNo Name Price Weight Star The number of Stars\n");
			printf("=============================================\n");
			printf("%2d ", i+1);
			readFruit(f[i]);
			break;
		}
	}

}
