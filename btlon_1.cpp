#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

struct sp_st {
    char tensp[31];
    int gia;
    int soluong;
};

struct giohang_st {
    char tenkhachhang[31];
    char diachi[51];
    int sosanpham;
    sp_st dssp[31];
};

void taogiohang(giohang_st *&mybag);
void chonhang(giohang_st *&mybag);
void ingiohang(giohang_st *mybag);
void xoasanpham(giohang_st *&mybag);
void ghiFile(giohang_st *&mybag, char fileName[]);
void sapxep(giohang_st *&mybag);

void taogiohang(giohang_st *&mybag){
	printf("\nnhap ten khach hang:");fflush(stdin);gets(mybag->tenkhachhang);
	printf("\nnhap dia chi:");fflush(stdin);gets(mybag->diachi);
	mybag->sosanpham = 0;
}
void chonhang(giohang_st *&mybag){
	int flag = 1, i = 0;
    while (flag != 0){
    	printf("\nNhap ten san pham:");fflush(stdin);gets(mybag->dssp[i].tensp);
    	printf("\nNhap so luong: ");scanf("%d", &mybag->dssp[i].soluong);
    	printf("\nNhap gia:");scanf("%d", &mybag->dssp[i].gia);
    	++mybag->sosanpham;
    	printf("an 0 de ket thuc nhap. an 1 de tiep tuc nhap: ");
    	scanf("%d", &flag);
    	++i;
	}
}

void sapxep(giohang_st *&mybag){
	sp_st temp;
	int sosanpham;
	char tensp1[31];
	char tensp2[31]; 
	 for(int i=0; i < mybag->sosanpham-1; i++){
	 	strcpy(tensp1, (mybag->dssp[i].tensp ));
	 	for(int j=i+1; j < mybag->sosanpham; j++){
	 		strcpy(tensp2, (mybag->dssp[j].tensp ));
		   if(strcmp(strupr(tensp1), strupr(tensp2))>0) {
			 temp = (mybag->dssp[i]);
			(mybag->dssp[i]) = (mybag->dssp[j] );
			(mybag->dssp[j])= temp;
			} 
		}
	 }
		
}

void ingiohang(giohang_st *mybag){
	printf("Stt\t Ten san pham\t\t Soluong\t Gia\n");
	 for (int i = 0; i < mybag->sosanpham; i++){
	 	printf(" %d", i+1);
	 	printf("\t %s",  mybag->dssp[i].tensp );
	 	printf("\t\t  %d", mybag->dssp[i].soluong);
	 	printf("\t\t %d", mybag->dssp[i].gia);
	 	printf("\n");
	 }
}

void xoasanpham(giohang_st *&mybag){
	int index;
    int flag = 1;
    while (flag != 0){
    	printf("\nCan loai bo san pham thu may");
    	scanf("%d", &index);
    	if (index > mybag->sosanpham){
    		printf("ban can phai nhap thu tu dung voi danh sach\n");
		}else{
			for (int i = 0; i < mybag->sosanpham; i++) {
                mybag->dssp[index] = mybag->dssp[index + 1];
                --mybag->sosanpham;
            }
		}
		printf("\nan 0 de ket thuc chon. an 1 de tiep tuc xoa: ");
		scanf("%d", &flag);  	
	}
}
void ghiFile(giohang_st *&mybag, char fileName[]) {
	FILE *f;
    f = fopen ("card.txt","w");
    fprintf(f, "%5s%20s%10s%10s\n", "STT", "Ten san pham", "So luong", "Gia");
    for (int i = 0; i < mybag->sosanpham; i++){
    	fprintf(f, "%5d%20s%10d%10d\n", i+1, mybag->dssp[i].tensp, mybag->dssp[i].soluong, mybag->dssp[i].gia);
	}
	fclose (f);
}
int main(){
	giohang_st *mybag = new giohang_st;
	 char fileName[] = "card.txt";
	int choose;
	 while (choose !=6){
	 	printf("_______________________MENU______________________\n"); 
	 	printf("1.Tao gio hang\n2. Chon hang\n3. Xem chi tiet gio hang\n4. Loai bo mot mat hang\n5. Ghi toan bo noi dung gio hang vao tep cart.txt\n6. Thoat\n");
	 	printf("_________________________________________________\n");
		 printf("Nhap lua chon cua ban: "); 
	 	scanf("%d", &choose);
	 	switch (choose) {
            case 1: {
                taogiohang(mybag);
                break;
            }
            case 2: {
                chonhang(mybag);
                break;
            }
            case 3: {
		sapxep(mybag);
                ingiohang(mybag);
                break;
            }
            case 4: {
                 xoasanpham(mybag);
                break;
            }
            case 5: {
                ghiFile(mybag, fileName);
                printf("\nGhi thong tin gio hang vao file %s thanh cong!\n", fileName);
                break;
            }
            default:
		getch();
                break;
        }
	 }
	 return 0;
}
	
