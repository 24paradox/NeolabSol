//Q.1.
/*
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

void display(struct node* head, const char* msg){
    printf("%s\n",msg);
    struct node* temp = head;
    int pos =1;
    while (temp!=NULL){
        printf("node %d : %d\n", pos++, temp->data);
        temp=temp->next;
    }
}

int main(){
    int n,val,p;
    struct node *head = NULL, *tail = NULL;
    scanf("%d", &n);
    
    for (int i=0;i<n;i++){
        scanf("%d",&val);
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data=val;
        newnode->next=NULL;
        newnode->prev=tail;
        if (head==NULL){
            head = newnode;
            tail = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    scanf("%d",&p);
    display(head, "Data entered in the list:");
    
    if (p<1||p>n){
        printf("Invalid position. Try again.\n");
    }else{
        struct node* temp=head;
        for (int i=1;i<p;i++){
            temp=temp->next;
        }
        
        if(temp->prev !=NULL){
            temp->prev->next = temp->next;
        }else{
            head=temp->next;
        }
        
        if(temp->next!=NULL){
            temp->next->prev=temp->prev;
        }
        
        free(temp);
        display(head,"After deletion the new list:");
    }
    return 0;
}
*/

//Q.2.
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

void update(struct Node* head, int index, int newPrice) {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        if (count == index) {
            temp->data = newPrice;
            return;
        }
        temp = temp->next;
        count++;
    }
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, price, index, newPrice;
    struct Node* head = NULL;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &price);
        append(&head, price);
    }

    scanf("%d %d", &index, &newPrice);

    update(head, index, newPrice);
    display(head);

    return 0;
}
*/

//Q.3.
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = new_node;
    new_node->prev = last;
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        return;
    }
    
    if (*head_ref == temp) {
        *head_ref = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    free(temp);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, val, m, r;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    
    scanf("%d", &m);
    insertEnd(&head, m);
    
    printList(head);
    
    scanf("%d", &r);
    deleteNode(&head, r);
    
    printList(head);
    
    return 0;
}
*/

//Q.3.
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = new_node;
    new_node->prev = last;
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        return;
    }
    
    if (*head_ref == temp) {
        *head_ref = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    free(temp);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, val, m, r;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    
    scanf("%d", &m);
    insertEnd(&head, m);
    
    printList(head);
    
    scanf("%d", &r);
    deleteNode(&head, r);
    
    printList(head);
    
    return 0;
}
*/

//Q.4.
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

void removeLast(struct Node** head) {
    if (*head == NULL) return;
    
    struct Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->prev->next = NULL;
    free(temp);
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    struct Node* head = NULL;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }

    removeLast(&head);
    display(head);

    return 0;
}
*/

//Q.5.
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

int findMax(struct Node* head) {
    if (head == NULL) return -1;
    int max = head->data;
    struct Node* temp = head->next;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

int main() {
    int n, score;
    struct Node* head = NULL;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &score) == 1) {
            insert(&head, score);
        }
    }

    printf("%d", findMax(head));

    return 0;
}
*/

//Q.6.
/*
// You are using GCC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    int id;
    char name[21];
    struct Contact* prev;
    struct Contact* next;
} Contact;

void deleteContact(Contact** head, int deleteID) {
    Contact* temp = *head;

    while (temp != NULL && temp->id != deleteID) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Contact *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        Contact* newContact = (Contact*)malloc(sizeof(Contact));
        scanf("%d %20s", &newContact->id, newContact->name);
        newContact->prev = tail;
        newContact->next = NULL;
        if (tail) {
            tail->next = newContact;
        } else {
            head = newContact;
        }
        tail = newContact;
    }

    int deleteID;
    scanf("%d", &deleteID);

    deleteContact(&head, deleteID);

    Contact* temp = head;
    while (temp != NULL) {
        printf("%d %s\n", temp->id, temp->name);
        temp = temp->next;
    }
    
    return 0;
}
*/

//Q.7.
/*
// You are using GCC
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int carriage;
    struct Node* prev;
    struct Node* next;
} Node;

void insertAfter(Node* head, int target, int newCarriage) {
    Node* temp = head;
    while (temp != NULL && temp->carriage != target) {
        temp = temp->next;
    }
    
    if (temp == NULL) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->carriage = newCarriage;

    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    Node *head = NULL, *last = NULL;

    for (int i = 0; i < n; i++) {
        int c;
        scanf("%d", &c);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->carriage = c;
        newNode->next = NULL;
        newNode->prev = last;
        if (last != NULL) {
            last->next = newNode;
        } else {
            head = newNode;
        }
        last = newNode;
    }

    int target, newCarriage;
    scanf("%d %d", &target, &newCarriage);

    insertAfter(head, target, newCarriage);

    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->carriage);
        temp = temp->next;
    }
    
    return 0;
}
*/

//Q.8.
/*
// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int patientID;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->patientID = id;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int id) {
    struct Node* newNode = createNode(id);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->patientID);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, id;
    struct Node* head = NULL;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        append(&head, id);
    }
    deleteAtBeginning(&head);
    display(head);

    return 0;
}
*/

//Q.9.
/*
// You are using GCC
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void printDLL(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteNode(struct Node** head, struct Node* node) {
    if (*head == NULL || node == NULL) return;

    if (*head == node) {
        *head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    if (node->prev != NULL) {
        node->prev->next = node->next;
    }

    free(node);
}

void deleteNodesWithGreaterRight(struct Node** head) {
    if (*head == NULL) return;

    struct Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    int maxRight = curr->data;
    struct Node* prevNode = curr->prev;
    curr = prevNode;

    while (curr != NULL) {
        prevNode = curr->prev;
        if (curr->data < maxRight) {
            deleteNode(head, curr);
        } else {
            maxRight = curr->data;
        }
        curr = prevNode;
    }
}
*/

//Q.10.
/*
// You are using GCC
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

int countPairs(struct Node* head, int X) {
    if (head == NULL) return 0;
    
    struct Node* left = head;
    struct Node* right = head;
    
    while (right->next != NULL)
        right = right->next;

    int count = 0;
    
    while (left != NULL && right != NULL && left != right && right->next != left) {
        int sum = left->data + right->data;
        if (sum == X) {
            count++;
            left = left->next;
            right = right->prev;
        } else if (sum < X) {
            left = left->next;
        } else {
            right = right->prev;
        }
    }

    return count;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
*/

//Q.11.
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head != NULL) {
        (*head)->prev = newNode;
        newNode->next = *head;
    }
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, value;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    struct Node* headBeginning = NULL;
    struct Node* headEnd = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        insertAtBeginning(&headBeginning, arr[i]);
        insertAtEnd(&headEnd, arr[i]);
    }

    display(headBeginning);
    display(headEnd);

    return 0;
}
*/

//Q.12.
/*
// You are using GCC
struct LinkedList {
    struct Node* head;
    int size;
};

void initializeLinkedList(struct LinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

void addNode(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->previous = temp;
    }
    list->size++;
}

void display(struct LinkedList* list) {
    struct Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void middle(struct LinkedList* list) {
    if (list->head == NULL) return;
    struct Node* slow = list->head;
    struct Node* fast = list->head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (list->size % 2 != 0) {
        printf("%d\n", slow->data);
    } else {
        printf("%d %d\n", slow->previous->data, slow->data);
    }
}
*/

//Q.13.
/*
// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = (*head);
    if ((*head) != NULL) {
        (*head)->prev = newNode;
    }
    (*head) = newNode;
}

void removeDuplicates(struct Node* head) {
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            if (ptr1->data == ptr2->data) {
                dup = ptr2;
                ptr2->prev->next = ptr2->next;
                if (ptr2->next != NULL) {
                    ptr2->next->prev = ptr2->prev;
                }
                ptr2 = ptr2->next;
                free(dup);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    struct Node* head = NULL;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &val) == 1) {
            insertFront(&head, val);
        }
    }
    removeDuplicates(head);
    display(head);
    return 0;
}
*/

//Q.14.
/*
// You are using GCC
struct DoublyLinkedList {
    struct Node* head;
    struct Node* tail;
};

void insertNode(struct DoublyLinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = newNode;
    }
    list->tail = newNode;
    if (list->head == NULL) {
        list->head = newNode;
    }
}

void insertAtMiddle(struct DoublyLinkedList* list, int data, int position) {
    int count = 0;
    struct Node* temp = list->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (position < 1 || position > count + 1) {
        printf("Invalid position\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = list->head;
        newNode->prev = NULL;
        if (list->head != NULL) {
            list->head->prev = newNode;
        }
        list->head = newNode;
        if (list->tail == NULL) {
            list->tail = newNode;
        }
    } else {
        struct Node* curr = list->head;
        for (int i = 1; i < position - 1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        if (curr->next != NULL) {
            curr->next->prev = newNode;
        } else {
            list->tail = newNode;
        }
        curr->next = newNode;
    }
}

void displayList(struct DoublyLinkedList* list) {
    struct Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
*/

//Q.15.
/*
// You are using GCC
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;
    if (tail != NULL) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == NULL) {
        head = newNode;
    }
}

void printForward() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printBackward() {
    struct Node* temp = tail;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int isPalindrome() {
    if (head == NULL) return 1;
    struct Node* left = head;
    struct Node* right = tail;
    while (left != right && left->prev != right) {
        if (left->data != right->data) {
            return 0;
        }
        left = left->next;
        right = right->prev;
    }
    return 1;
}
*/