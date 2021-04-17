#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"

int selectMenu()
{
        int menu;
        printf("\n***product***\n");
        printf("1. 조회\n");
        printf("2. 추가\n");
        printf("3. 수정\n");
        printf("4. 삭제\n");
        printf("5. 파일저장\n");
        printf("6. 품명 검색\n");
        printf("7. 가격 검색\n");
        printf("8. 중량 검색\n");
        printf("0. 종료\n\n");
        printf("=> 원하는 메뉴는? ");
        scanf("%d%*c",&menu);
        return menu;
}

int createFruit(Fruit *f)
{
	printf("품명은?: ");
	scanf("%s", f->name);
	printf("중량은.?: ");
	scanf("%d", &f->weight);
	printf("가격은?: ");
	scanf("%d", &f->price);
	printf("별점은?: ");
	scanf("%d", &f->star);
	printf("별점 개수는?: ");
	scanf("%d", &f->starnum);
	return 1;
}

void readFruit(Fruit f)
{
	printf("%s %d %d %d %d\n",f.name,f.price,f.weight,f.star,f.starnum);	
}

void listFruit(Fruit *f, int count)
{
	int i = 0;
	printf("\nNo Name Price Weight Star The number of Stars\n");
	printf("=============================================\n");
	for(i = 0 ; i<count; i++)
	{
		if(f[i].price == -1) continue;
		printf("%2d ", i+1);
		readFruit(f[i]);
	}
}

int selectDataNo(Fruit *f, int count)
{
	int no;
	listFruit(f,count);
	printf("\n번호는? (취소:0)?");
	scanf("%d",&no);
	return no;
}

int updateFruit(Fruit *f)
{
	printf("품명은?: ");
	scanf("%s", f->name);
	printf("중량은.?: ");
	scanf("%d", &f->weight);
	printf("가격은?: ");
	scanf("%d", &f->price);
	printf("별점은?: ");
	scanf("%d", &f->star);
	printf("별점 개수는?: ");
	scanf("%d", &f->starnum);
	return 1;
}

int deleteFruit(Fruit *f)
{
	if(f->price == -1) return -1;
	f->weight = -1;
	f->price = -1;
	f->star = -1;
	f->starnum = -1;
	printf("=> 삭제됨!\n");
	return 1;
}

