#include <stdio.h>
#include "product.h"
#include "manager.h"
//#define EBUG

int main()
{
#ifdef EBUG
	printf("=>DEBUG MODE\n");
#endif
	Fruit fruit[20];
	int isload;
	int menu;
	int index = 0;
	int count = 0;
	isload = loadFruit(fruit, &index);
	if(isload == -1) printf("파일 없음 혹은 읽기 실패");
	else
	{
		count = index;
		printf("=> 로딩성공!\n");
	}

	while(1)
	{
		menu = selectMenu();
		if(menu == 0) break;
		if(menu == 1 || menu == 3 || menu == 4 || menu == 5 || menu == 6 || menu == 7 || menu == 8)
			if(count == 0) continue;
		if(menu == 1) listFruit(fruit, index);
		else if(menu == 2) count +=createFruit(&fruit[index++]);
		else if(menu == 3)
		{
			int no = selectDataNo(fruit,index);
			if(no >0) updateFruit(&fruit[no-1]);
		}
		else if(menu == 4)
		{
			int no = selectDataNo(fruit,index);
			if(no > 0)
			{
				int deleteok;
				printf("정말로 삭제하시겠습니까?(삭제:1) ");
				scanf("%d", &deleteok);
				if(deleteok == 1)
				{
					deleteFruit(&fruit[no-1]);
					count--;
				}
			}
		}
		else if(menu == 5)
		{
			int issave;
			issave = saveFruit(fruit,index);
			if(issave == -1)
			{
				printf("파일 저장 실패!\n");
				return -1;
			}
			else printf("저장됨!\n");
		}
		else if(menu == 6) searchFruitName(fruit,index);
		else if(menu == 7) searchPrice(fruit,index);
		else if(menu == 8) searchWeight(fruit,index);
	}
	printf("종료됨!\n");
	return 0;
}
