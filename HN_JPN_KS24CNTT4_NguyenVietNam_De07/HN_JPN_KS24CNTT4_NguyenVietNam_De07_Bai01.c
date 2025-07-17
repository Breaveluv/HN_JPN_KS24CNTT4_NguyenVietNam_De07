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

OrderManagement* addOderManagement(OrderManagement* head) {
 
    Order* oder = (Order*)malloc(sizeof(Order));

    printf("Moi ban nhap id: ");
    scanf("%d", &oder->id);

    printf("Moi ban nhap ten khach hang: ");
    getchar(); 
    fgets(oder->cumstumer, 100, stdin);
    oder->cumstumer[strcspn(oder->cumstumer, "\n")] = 0; 

    printf("Moi ban nhap status (0: Dang xu ly, 1: Da giao): ");
    scanf("%d", &oder->status);

    printf("Moi ban nhap total: ");
    getchar(); 
    fgets(oder->total, 100, stdin);
    oder->total[strcspn(oder->total, "\n")] = 0; 

    OrderManagement* newNode = createOrderManagement(oder);

    if (head == NULL) {
      
        head = newNode;
    } else {
        
        OrderManagement* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Them don hang thanh cong!\n");
    return head; 
}
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
OrderManagement* deleteOrderManagement(OrderManagement* head, int id) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return NULL;
    }

    OrderManagement* temp = head;

    
    while (temp != NULL && temp->order->id != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Khong tim thay don hang voi ID: %d\n", id);
        return head;
    }

    
    if (temp == head) {
        head = temp->next;
    }
    if (temp->next != NULL) { 
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) { 
        temp->prev->next = temp->next;
    }

    free(temp->order); 
    free(temp);        
    printf("Da xoa don hang co ID: %d\n", id);

    return head;
}


void updateOrderManagement(OrderManagement* head, int id) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    OrderManagement* temp = head;
    while (temp != NULL && temp->order->id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim thay don hang voi ID: %d\n", id);
        return;
    }

    printf("--- Cap nhat thong tin cho don hang ID: %d ---\n", id);
    printf("Ten khach hang hien tai: %s\n", temp->order->cumstumer);
    printf("Total hien tai: %s\n", temp->order->total);

    printf("Moi ban nhap ten khach hang moi: ");
    getchar(); 
    fgets(temp->order->cumstumer, 100, stdin);
    temp->order->cumstumer[strcspn(temp->order->cumstumer, "\n")] = 0;


    printf("Moi ban nhap so tien moi: ");
    fgets(temp->order->total, 100, stdin);
    temp->order->total[strcspn(temp->order->total, "\n")] = 0;

    printf("Cap nhat thanh cong!\n");
}


void searchOrderManagement(OrderManagement* head, int id) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    
    OrderManagement* temp = head;
    while (temp != NULL) {
        if (temp->order->id == id) {
            printf("\n--- Tim thay don hang ---\n");
            printf("ID: %d\n", temp->order->id);
            printf("Status: %d (%s)\n", temp->order->status, temp->order->status == 0 ? "Dang xu ly" : "Da giao");
            printf("Customer: %s\n", temp->order->cumstumer);
            printf("Total: %s\n", temp->order->total);
            return;
        }
        temp = temp->next;
    }
    printf("Khong tim thay don hang voi ID: %d\n", id);
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
                 node = addOderManagement(node);
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
