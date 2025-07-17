#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Order {
    int id;
    char customer[100];
    int status;
    char total[100];
} Order;

typedef struct OrderNode {
    Order order;
    struct OrderNode *next;
    struct OrderNode *prev;
} OrderNode;

OrderNode *head = NULL; 
OrderNode *history = NULL; 

OrderNode *createNode(Order order) {
    OrderNode *newNode = (OrderNode *)malloc(sizeof(OrderNode));
    newNode->order = order;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addOrder() {
    Order order;
    printf("Nhap ID: ");
    scanf("%d", &order.id);
    getchar();
    printf("Nhap ten khach hang: ");
    fgets(order.customer, sizeof(order.customer), stdin);
    order.customer[strcspn(order.customer, "\n")] = 0;

    printf("Nhap trang thai (0: chua giao, 1: da giao): ");
    scanf("%d", &order.status);
    getchar();
    printf("Nhap tong tien: ");
    fgets(order.total, sizeof(order.total), stdin);
    order.total[strcspn(order.total, "\n")] = 0;

    OrderNode *newNode = createNode(order);
    if (head == NULL) {
        head = newNode;
    } else {
        OrderNode *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("==> Them don hang thanh cong!\n");
}

void displayOrders() {
    if (!head) {
        printf("Danh sach don hang rong!\n");
        return;
    }
    OrderNode *temp = head;
    printf("=== Danh sach don hang ===\n");
    while (temp) {
        printf("ID: %d\n", temp->order.id);
        printf("Khach hang: %s\n", temp->order.customer);
        printf("Trang thai: %s\n", temp->order.status == 0 ? "Chua giao" : "Da giao");
        printf("Tong tien: %s\n", temp->order.total);
        printf("---------------------------\n");
        temp = temp->next;
    }
}

void deleteOrder(int id) {
    OrderNode *temp = head;
    while (temp && temp->order.id != id) temp = temp->next;
    if (!temp) {
        printf("Khong tim thay don hang!\n");
        return;
    }

    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;

    free(temp);
    printf("==> Xoa don hang thanh cong!\n");
}

void updateOrder(int id) {
    OrderNode *temp = head;
    while (temp && temp->order.id != id) temp = temp->next;
    if (!temp) {
        printf("Khong tim thay don hang!\n");
        return;
    }

    getchar();
    printf("Nhap ten khach hang moi: ");
    fgets(temp->order.customer, sizeof(temp->order.customer), stdin);
    temp->order.customer[strcspn(temp->order.customer, "\n")] = 0;

    printf("Nhap tong tien moi: ");
    fgets(temp->order.total, sizeof(temp->order.total), stdin);
    temp->order.total[strcspn(temp->order.total, "\n")] = 0;

    printf("==> Cap nhat thanh cong!\n");
}

void markDelivered(int id) {
    OrderNode *temp = head;
    while (temp && temp->order.id != id) temp = temp->next;
    if (!temp) {
        printf("Khong tim thay don hang!\n");
        return;
    }

   
    temp->order.status = 1;

   
    OrderNode *newNode = createNode(temp->order);
    newNode->next = history;
    if (history) history->prev = newNode;
    history = newNode;

   
    if (temp->prev) {
        temp->prev->next = temp->next;
    }
    else head = temp->next;
    if (temp->next){
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("==> Don hang da duoc danh dau la da giao!\n");
}

void sortOrders() {
    for (OrderNode *i = head; i != NULL; i = i->next) {
        for (OrderNode *j = i->next; j != NULL; j = j->next) {
            if (atoi(i->order.total) > atoi(j->order.total)) {
                Order temp = i->order;
                i->order = j->order;
                j->order = temp;
            }
        }
    }
    printf("==> Sap xep thanh cong!\n");
}

void searchOrder(int id) {
    OrderNode *temp = head;
    int found = 0;
    while (temp) {
        if ((id != -1 && temp->order.id == id) ||
            (name && strstr(temp->order.customer, name))) {
            printf("ID: %d\n", temp->order.id);
            printf("Khach hang: %s\n", temp->order.customer);
            printf("Trang thai: %s\n", temp->order.status == 0 ? "Chua giao" : "Da giao");
            printf("Tong tien: %s\n", temp->order.total);
            printf("---------------------------\n");
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) printf("Khong tim thay don hang!\n");
}

int main() {
    int choice;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Them don hang\n");
        printf("2. Hien thi don hang\n");
        printf("3. Xoa don hang\n");
        printf("4. Cap nhat don hang\n");
        printf("5. Danh dau da giao\n");
        printf("6. Sap xep don hang theo tong tien\n");
        printf("7. Tim kiem don hang\n");
        printf("8. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        int id;
        char name[100];
        switch (choice) {
            case 1: addOrder(); break;
            case 2: displayOrders(); break;
            case 3:
                printf("Nhap ID can xoa: ");
                scanf("%d", &id);
                deleteOrder(id);
                break;
            case 4:
                printf("Nhap ID can cap nhat: ");
                scanf("%d", &id);
                updateOrder(id);
                break;
            case 5:
                printf("Nhap ID can danh dau da giao: ");
                scanf("%d", &id);
                markDelivered(id);
                break;
            case 6: 
                sortOrders();
                break;
            case 7:
                printf("Nhap ID : ");
                scanf("%d", &id);
               
                 searchOrder(id);
                break;
            case 8: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}
