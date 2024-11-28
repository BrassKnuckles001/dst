#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* create(int n);
void print(node *p);
void count(node *p);
void search(node *p);
node* insert_at_Begin(node *head);
node* insert_at_End(node *head);
node* insert_at_Middle(node *head);
node* delete_at_Begin(node *head);
node* delete_at_End(node *head);
node* delete_at_Middle(node *head);

int main() {
    node *Head = NULL;
    int no, op;

    do {
        printf("\n************ SLL OPERATIONS *************");
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
                Head = create(no);
                break;
            case 2:
                print(Head);
                break;
            case 3:
                count(Head);
                break;
            case 4:
                search(Head);
                break;
            case 5:
                Head = insert_at_Begin(Head);
                break;
            case 6:
                Head = insert_at_Middle(Head);
                break;
            case 7:
                Head = insert_at_End(Head);
                break;
            case 8:
                Head = delete_at_Begin(Head);
                break;
            case 9:
                Head = delete_at_Middle(Head);
                break;
            case 10:
                Head = delete_at_End(Head);
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
    node *head, *p;
    int i, x;

    printf("\nEnter data: ");
    scanf("%d", &x);
    head = (node*)malloc(sizeof(node));
    head->data = x;
    head->next = NULL;
    p = head;

    for (i = 2; i <= n; i++) {
        printf("\nEnter data: ");
        scanf("%d", &x);
        p->next = (node*)malloc(sizeof(node));
        p = p->next;
        p->data = x;
        p->next = NULL;
    }

    printf("\nLinked list created successfully.");
    return head;
}

void print(node *p) {
    if (p == NULL) {
        printf("\nLinked List is Empty!!!");
        return;
    }

    printf("\nSLL Nodes: ");
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void count(node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    printf("\nNo of Nodes: %d", count);
}

void search(node *p) {
    int key, flag = 0;
    printf("\nEnter key element to search: ");
    scanf("%d", &key);

    while (p != NULL) {
        if (key == p->data) {
            flag = 1;
            break;
        }
        p = p->next;
    }

    if (flag)
        printf("\nElement is found!!!");
    else
        printf("\nElement is not found!!!");
}

node* insert_at_Begin(node *head) {
    node *q;
    int x;
    printf("\nEnter data: ");
    scanf("%d", &x);

    q = (node*)malloc(sizeof(node));
    q->data = x;
    q->next = head;
    head = q;

    printf("\nNode inserted at Beginning successfully!!!");
    return head;
}

node* insert_at_End(node *head) {
    node *q, *p;
    int x;
    printf("\nEnter data: ");
    scanf("%d", &x);

    q = (node*)malloc(sizeof(node));
    q->data = x;
    q->next = NULL;

    if (head == NULL) {
        head = q;
    } else {
        p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = q;
    }

    printf("\nNode inserted at End successfully!!!");
    return head;
}

node* insert_at_Middle(node *head) {
    node *q, *p;
    int x, i, loc;

    printf("\nEnter data: ");
    scanf("%d", &x);
    printf("\nEnter location for insertion: ");
    scanf("%d", &loc);

    q = (node*)malloc(sizeof(node));
    q->data = x;

    if (loc == 1) {
        q->next = head;
        head = q;
    } else {
        p = head;
        for (i = 1; i < loc - 1; i++) {
            if (p == NULL) {
                printf("\nInvalid location!");
                return head;
            }
            p = p->next;
        }
        q->next = p->next;
        p->next = q;
    }

    printf("\nNode inserted at Middle successfully!!!");
    return head;
}

node* delete_at_Begin(node *head) {
    node *q;

    if (head == NULL) {
        printf("\nLinked List is Empty!!! Deletion is not possible.");
        return head;
    }

    q = head;
    head = head->next;
    free(q);

    printf("\nNode deleted from Beginning successfully!!!");
    return head;
}

node* delete_at_End(node *head) {
    node *q, *p;

    if (head == NULL) {
        printf("\nLinked List is Empty!!! Deletion is not possible.");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    p = head;
    while (p->next->next != NULL) {
        p = p->next;
    }

    q = p->next;
    p->next = NULL;
    free(q);

    printf("\nNode deleted from End successfully!!!");
    return head;
}

node* delete_at_Middle(node *head) {
    node *q, *p;
    int i, loc;

    if (head == NULL) {
        printf("\nLinked List is Empty!!! Deletion is not possible.");
        return head;
    }

    printf("\nEnter location for deletion: ");
    scanf("%d", &loc);

    if (loc == 1) {
        q = head;
        head = head->next;
        free(q);
        return head;
    }

    p = head;
    for (i = 1; i < loc - 1; i++) {
        if (p == NULL || p->next == NULL) {
            printf("\nInvalid location!");
            return head;
        }
        p = p->next;
    }

    q = p->next;
    if (q == NULL) {
        printf("\nInvalid location!");
        return head;
    }

    p->next = q->next;
    free(q);

    printf("\nNode deleted from Middle successfully!!!");
    return head;
}
