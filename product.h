typedef struct
{
    char name[20];  //제품명
    int weight;     //중량
    int price;      //판매가격
    int star;       //별점
    int starnum;    //별점개수
} Fruit;

int selectMenu();                           //메뉴 선택
int createFruit(Fruit *f);                  //제품 추가
void readFruit(Fruit f);                    //제품 정보 출력
void listFruit(Fruit *f, int count);      //제품 목록 나열
int selectDataNo(Fruit *f, int count);      //제품 선택
int updateFruit(Fruit *f);                  //제품 정보 수정
int deleteFruit(Fruit *f);                  //제품 정보 삭제
