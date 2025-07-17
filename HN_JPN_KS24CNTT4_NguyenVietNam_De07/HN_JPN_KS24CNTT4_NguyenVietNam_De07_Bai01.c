#include <stdio.h>
#include <stdlib.h>
typedef struct Order {
    int id;
    char cumstumer[100];
    int status;
    char total[100];
}Order;
typedef struct orderHistory {
    Order *order;
    struct orderHistory *next;
}oderHistory;
typedef struct OrderManagement {
    Order *order;
    struct OrderManagement *next;
    struct OrderManagement *prev;
}OrderManagement;

OrderManagement *createOrderManagement(Order *oder) {

    OrderManagement *orderManagement=(OrderManagement *)malloc(sizeof(OrderManagement));
    orderManagement->order=oder;
    orderManagement->prev=NULL;
    orderManagement->next=NULL;
    return orderManagement;
}
void displayOrderManagement(OrderManagement *head) {
if (head == NULL) {
    printf("Danh sach rong ");
    return ;
}
    OrderManagement *temp=head;
    while (temp != NULL) {
        printf("ID: %d\n",temp->order->id);
        printf("Cumstumer: %s\n",temp->order->cumstumer);
        printf("Status: %d\n",temp->order->status);
        printf("Total: %s\n",temp->order->total);
        temp=temp->next;

        printf("\n");

    }
    printf("AGGG\n");
}
void addOderManagement(OrderManagement *head) {
    Order *oder =(OrderManagement *)malloc(sizeof(OrderManagement));
    printf("Moi ban nhap id");
    scanf("%d",&oder->id);
    printf("Moi ban nhap cumstumer");
    getchar();
    fgets(oder->cumstumer,100,stdin);
    printf("Moi ban nhap status");
    scanf("%d",&oder->status);
    printf("Moi ban nhap total");
    getchar();
    fgets(oder->total,100,stdin);
    OrderManagement *temp=createOrderManagement(oder);

}

void deleteOrderManagement(OrderManagement *head,int position) {
    if (head == NULL) {
        printf("Danh sach rong ");
        return ;
    }
    OrderManagement *temp=head;
    OrderManagement *prev=NULL;
    while (temp != NULL && temp->order->id != position) {
                prev=temp;
        temp=temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim thay ");
        return ;

    }
    if (temp == head) {
        head=head->next;
        free(temp);
    }
    prev->next=temp->next;
    free(temp);
    return ;

}
void updateOrderManagement(OrderManagement *head , int pos) {
    if (head == NULL) {
        printf("Danh sach rong ");
        return ;
    }
    OrderManagement *temp=head;
    while (temp != NULL && temp->order->id != pos) {
        temp=temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim thay ");
        return ;
    }

    printf("Cumstumer : %s \n",temp->order->cumstumer);
    printf("Total : %d \n",temp->order->total);
    printf("Moi ban nhap ten khach hang moi");
    gets(temp->order->cumstumer);
    printf("\n Moi ban nhap so tien moi");
    gets(temp->order->total);

}
void AscendingOrder(OrderManagement *head) {

  for (int i = 0; i < head->order->status; i++) {
      for (int j = 0; j < head->order->status; j++) {

      }

    }

}
void markOder(OrderManagement *head) {

}
void searchOrderManagement(OrderManagement *head, int id) {
    if (head == NULL) {
        printf("Danh sach rong ");
        return ;
    }
    OrderManagement *temp=head;
    if (temp->order->id == id) {
        printf("ID: %d\n",temp->order->id);
        printf("Status: %d\n",temp->order->status);
        printf("Cumstumer: %s\n",temp->order->cumstumer);
        printf("Total: %s\n",temp->order->total);

    }
}


int main() {
    int choice;
    OrderManagement *node=NULL;
    oderHistory *head=NULL;
    do {
        printf("\n-------- ORDER MANAGER --------\n");
        printf("1.Them don vi hang moi\n");
        printf("2.Hien thi danh sach don hang\n");
        printf("3.Xoa don hang (theo id)\n");
        printf("4.Cap nhap thong tin don hang\n");
        printf("5.Danh dau don hang da giao\n");
        printf("6.Sap xep don hang theo tong ten\n");
        printf("7.Tim kiem don hang\n");
        printf("8.Thoat chuong trinh\n");
        printf("Moi ban nhap lua chon : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addOderManagement(node);
                break;
            case 2:
                displayOrderManagement(node);
                break;
            case 3:
                int pos;
                printf("Moi ban nhap vi tri muon xoa ");
                scanf("%d", &pos);
                deleteOrderManagement(node,pos);
                break;
            case 4:
                int id;
                printf("Moi ban nhap vi tri muon thay doi thong tin ");
                scanf("%d", &id);
                updateOrderManagement(node,id);
                break;
            case 5:

                break;
            case 6:
                AscendingOrder(node);
                break;
            case 7:
                int search;
                printf("Moi ban nhap id muon tim");
                scanf("%d", &search);
                searchOrderManagement(node,search);
                break;
            case 8:
                printf("Thoat chuong trinh \n");
                break;

            default:
                printf("Moi ban nhap lai \n");
        }
    }while (choice !=8);
    return 0;
}
