#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev, *next;
} node;


node* create(int n);
void print(node *head);
void count(node *head);
void search(node *head);
node* insert_at_Begin(node *head);
node* insert_at_End(node *head);
node* insert_at_Middle(node *head);
node* delete_at_Begin(node *head);
node* delete_at_End(node *head);
node* delete_at_Middle(node *head);

int main() {
    node *head = NULL;
    int no, op;

    do {
        printf("\n************ DCLL OPERATIONS *************");
        printf("\n1. Create\n2. Print\n3. Count\n4. Search");
        printf("\n5. Insert at Begin\n6. Insert at Middle\n7. Insert at End");
        printf("\n8. Delete from Begin\n9. Delete from Middle\n10. Delete from End");
        printf("\n11. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("\nEnter size of linked list: ");
                scanf("%d", &no);
                head = create(no);
                break;
            case 2:
                print(head);
                break;
            case 3:
                count(head);
                break;
            case 4:
                search(head);
                break;
            case 5:
                head = insert_at_Begin(head);
                break;
            case 6:
                head = insert_at_Middle(head);
                break;
            case 7:
                head = insert_at_End(head);
                break;
            case 8:
                head = delete_at_Begin(head);
                break;
            case 9:
                head = delete_at_Middle(head);
                break;
            case 10:
                head = delete_at_End(head);
                break;
            case 11:
                printf("\nGood Bye.. Thanks for using our Application!!!\n");
                break;
            default:
                printf("\nPlease select a valid option!!!");
        }
    } while (op != 11);

    return 0;
}


node* create(int n) {
    node *head = NULL, *temp, *p;
    int i, x;

    for (i = 1; i <= n; i++) {
        printf("\nEnter data: ");
        scanf("%d", &x);
        temp = (node*)malloc(sizeof(node));
        temp->data = x;

        if (head == NULL) {
            head = temp;
            head->next = head->prev = head;
        } else {
            p = head->prev; 
            p->next = temp;
            temp->prev = p;
            temp->next = head;
            head->prev = temp;
        }
    }

    printf("\nDoubly Circular Linked List created successfully.");
    return head;
}

void print(node *head) {
    if (head == NULL) {
        printf("\nDoubly Circular Linked List is Empty!!!");
        return;
    }

    node *p = head;
    printf("\nDCLL Nodes: ");
    do {
        printf("%d <-> ", p->data);
        p = p->next;
    } while (p != head);
    printf("HEAD\n");
}

void count(node *head) {
    if (head == NULL) {
        printf("\nNo of Nodes: 0");
        return;
    }

    int count = 0;
    node *p = head;

    do {
        count++;
        p = p->next;
    } while (p != head);

    printf("\nNo of Nodes: %d", count);
}

void search(node *head) {
    if (head == NULL) {
        printf("\nDoubly Circular Linked List is Empty!!!");
        return;
    }

    int key, flag = 0;
    printf("\nEnter key element to search: ");
    scanf("%d", &key);

    node *p = head;
    do {
        if (key == p->data) {
            flag = 1;
            break;
        }
        p = p->next;
    } while (p != head);

    if (flag)
        printf("\nElement is found!!!");
    else
        printf("\nElement is not found!!!");
}

node* insert_at_Begin(node *head) {
    node *temp, *last;
    int x;
    printf("\nEnter data: ");
    scanf("%d", &x);

    temp = (node*)malloc(sizeof(node));
    temp->data = x;

    if (head == NULL) {
        temp->next = temp->prev = temp;
        head = temp;
    } else {
        last = head->prev;
        temp->next = head;
        temp->prev = last;
        last->next = temp;
        head->prev = temp;
        head = temp;
    }

    printf("\nNode inserted at Beginning successfully!!!");
    return head;
}

node* insert_at_End(node *head) {
    node *temp, *last;
    int x;
    printf("\nEnter data: ");
    scanf("%d", &x);

    temp = (node*)malloc(sizeof(node));
    temp->data = x;

    if (head == NULL) {
        temp->next = temp->prev = temp;
        head = temp;
    } else {
        last = head->prev;
        temp->next = head;
        temp->prev = last;
        last->next = temp;
        head->prev = temp;
    }

    printf("\nNode inserted at End successfully!!!");
    return head;
}

node* insert_at_Middle(node *head) {
    if (head == NULL) {
        printf("\nDoubly Circular Linked List is Empty!!!");
        return head;
    }

    node *temp, *p = head;
    int x, i, loc;

    printf("\nEnter data: ");
    scanf("%d", &x);
    printf("\nEnter location for insertion: ");
    scanf("%d", &loc);

    temp = (node*)malloc(sizeof(node));
    temp->data = x;

    for (i = 1; i < loc - 1; i++) {
        p = p->next;
        if (p == head) {
            printf("\nInvalid location!");
            return head;
        }
    }

    temp->next = p->next;
    temp->prev = p;
    p->next->prev = temp;
    p->next = temp;

    printf("\nNode inserted at Middle successfully!!!");
    return head;
}

node* delete_at_Begin(node *head) {
    if (head == NULL) {
        printf("\nDoubly Circular Linked List is Empty!!! Deletion is not possible.");
        return head;
    }

    node *temp = head;

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        node *last = head->prev;
        head = head->next;
        head->prev = last;
        last->next = head;
        free(temp);
    }

    printf("\nNode deleted from Beginning successfully!!!");
    return head;
}

node* delete_at_End(node *head) {
    if (head == NULL) {
        printf("\nDoubly Circular Linked List is Empty!!! Deletion is not possible.");
        return head;
    }

    node *last = head->prev;

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        last->prev->next = head;
        head->prev = last->prev;
        free(last);
    }

    printf("\nNode deleted from End successfully!!!");
    return head;
}

node* delete_at_Middle(node *head) {
    if (head == NULL) {
        printf("\nDoubly Circular Linked List is Empty!!! Deletion is not possible.");
        return head;
    }

    node *p = head;
    int i, loc;

    printf("\nEnter location for deletion: ");
    scanf("%d", &loc);

    for (i = 1; i < loc; i++) {
        p = p->next;
        if (p == head) {
            printf("\nInvalid location!");
            return head;
        }
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;

    if (p == head)
        head = p->next;

    free(p);
    printf("\nNode deleted from Middle successfully!!!");
    return head;
}
