#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* create(int n);
void print(node *last);
void count(node *last);
void search(node *last);
node* insert_at_Begin(node *last);
node* insert_at_End(node *last);
node* insert_at_Middle(node *last);
node* delete_at_Begin(node *last);
node* delete_at_End(node *last);
node* delete_at_Middle(node *last);

int main() {
    node *last = NULL;
    int no, op;

    do {
        printf("\n************ CLL OPERATIONS *************");
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
                last = create(no);
                break;
            case 2:
                print(last);
                break;
            case 3:
                count(last);
                break;
            case 4:
                search(last);
                break;
            case 5:
                last = insert_at_Begin(last);
                break;
            case 6:
                last = insert_at_Middle(last);
                break;
            case 7:
                last = insert_at_End(last);
                break;
            case 8:
                last = delete_at_Begin(last);
                break;
            case 9:
                last = delete_at_Middle(last);
                break;
            case 10:
                last = delete_at_End(last);
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
    node *last = NULL, *temp, *p;
    int i, x;

    for (i = 1; i <= n; i++) {
        printf("\nEnter data: ");
        scanf("%d", &x);
        temp = (node*)malloc(sizeof(node));
        temp->data = x;

        if (last == NULL) {
            temp->next = temp; 
            last = temp;
        } else {
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
    }

    printf("\nCircular Linked List created successfully.");
    return last;
}

void print(node *last) {
    if (last == NULL) {
        printf("\nCircular Linked List is Empty!!!");
        return;
    }

    node *p = last->next;
    printf("\nCLL Nodes: ");
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != last->next);
    printf("(Back to start)\n");
}

void count(node *last) {
    if (last == NULL) {
        printf("\nNo of Nodes: 0");
        return;
    }

    int count = 0;
    node *p = last->next;

    do {
        count++;
        p = p->next;
    } while (p != last->next);

    printf("\nNo of Nodes: %d", count);
}

void search(node *last) {
    if (last == NULL) {
        printf("\nCircular Linked List is Empty!!!");
        return;
    }

    int key, flag = 0;
    printf("\nEnter key element to search: ");
    scanf("%d", &key);

    node *p = last->next;
    do {
        if (key == p->data) {
            flag = 1;
            break;
        }
        p = p->next;
    } while (p != last->next);

    if (flag)
        printf("\nElement is found!!!");
    else
        printf("\nElement is not found!!!");
}

node* insert_at_Begin(node *last) {
    node *temp;
    int x;
    printf("\nEnter data: ");
    scanf("%d", &x);

    temp = (node*)malloc(sizeof(node));
    temp->data = x;

    if (last == NULL) {
        temp->next = temp; 
        last = temp;
    } else {
        temp->next = last->next;
        last->next = temp;
    }

    printf("\nNode inserted at Beginning successfully!!!");
    return last;
}

node* insert_at_End(node *last) {
    node *temp;
    int x;
    printf("\nEnter data: ");
    scanf("%d", &x);

    temp = (node*)malloc(sizeof(node));
    temp->data = x;

    if (last == NULL) {
        temp->next = temp; 
        last = temp;
    } else {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }

    printf("\nNode inserted at End successfully!!!");
    return last;
}

node* insert_at_Middle(node *last) {
    if (last == NULL) {
        printf("\nCircular Linked List is Empty!!!");
        return last;
    }

    node *temp, *p = last->next;
    int x, i, loc;

    printf("\nEnter data: ");
    scanf("%d", &x);
    printf("\nEnter location for insertion: ");
    scanf("%d", &loc);

    temp = (node*)malloc(sizeof(node));
    temp->data = x;

    for (i = 1; i < loc - 1; i++) {
        if (p == last) {
            printf("\nInvalid location!");
            return last;
        }
        p = p->next;
    }

    temp->next = p->next;
    p->next = temp;

    if (p == last)
        last = temp;

    printf("\nNode inserted at Middle successfully!!!");
    return last;
}

node* delete_at_Begin(node *last) {
    if (last == NULL) {
        printf("\nCircular Linked List is Empty!!! Deletion is not possible.");
        return last;
    }

    node *temp = last->next;

    if (last == last->next) { 
        free(last);
        last = NULL;
    } else {
        last->next = temp->next;
        free(temp);
    }

    printf("\nNode deleted from Beginning successfully!!!");
    return last;
}

node* delete_at_End(node *last) {
    if (last == NULL) {
        printf("\nCircular Linked List is Empty!!! Deletion is not possible.");
        return last;
    }

    node *p = last->next;

    if (last == last->next) { 
        free(last);
        last = NULL;
    } else {
        while (p->next != last) {
            p = p->next;
        }
        p->next = last->next;
        free(last);
        last = p;
    }

    printf("\nNode deleted from End successfully!!!");
    return last;
}

node* delete_at_Middle(node *last) {
    if (last == NULL) {
        printf("\nCircular Linked List is Empty!!! Deletion is not possible.");
        return last;
    }

    node *p = last->next, *temp;
    int i, loc;

    printf("\nEnter location for deletion: ");
    scanf("%d", &loc);

    if (loc == 1) {
        return delete_at_Begin(last);
    }

    for (i = 1; i < loc - 1; i++) {
        if (p->next == last->next) {
            printf("\nInvalid location!");
            return last;
        }
        p = p->next;
    }

    temp = p->next;
    p->next = temp->next;

    if (temp == last)
        last = p;

    free(temp);
    printf("\nNode deleted from Middle successfully!!!");
    return last;
}
