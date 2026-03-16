//Q1
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void insertAfterFirst(struct Node* head, int val) {
    if (head == NULL) return;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head->next;
    head->next = newNode;
}

int main() {
    int n, val, m;
    struct Node* head = NULL;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertAtBeginning(&head, val);
    }

    scanf("%d", &m);
    
    if (head != NULL) {
        insertAfterFirst(head, m);
    } else {
        insertAtBeginning(&head, m);
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
*/


//Q2
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    struct Node* head = NULL;
    int val;

    while (scanf("%d", &val) && val != -1) {
        insert(&head, val);
    }

    printf("%d", countNodes(head));

    return 0;
}
*/


//Q3
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertFront(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void findMiddle(struct Node* head) {
    if (head == NULL) return;

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle Element: %d", slow->data);
}

int main() {
    int n, val;
    struct Node* head = NULL;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertFront(&head, val);
    }

    printList(head);
    findMiddle(head);

    return 0;
}
*/


//Q4
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertFront(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteAfter(struct Node* head, int x) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != x) {
        temp = temp->next;
    }
    if (temp != NULL && temp->next != NULL) {
        struct Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete);
    }
}

int main() {
    int n, val, x;
    struct Node* head = NULL;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertFront(&head, val);
    }
    scanf("%d", &x);

    printf("Original Linked List: ");
    printList(head);

    deleteAfter(head, x);

    printf("After deleting node after %d: ", x);
    printList(head);

    return 0;
}
*/


//Q5
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

void insertEnd(struct Node** head, char val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, index;
    char val, newChar;
    struct Node* head = NULL;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf(" %c", &val);
        insertEnd(&head, val);
    }

    scanf("%d", &index);
    scanf(" %c", &newChar);

    struct Node* temp = head;
    int currIndex = 0;
    while (temp != NULL && currIndex < index) {
        temp = temp->next;
        currIndex++;
    }

    if (temp == NULL || index < 0) {
        printf("Invalid index\n");
    } else {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = newChar;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Updated list: ");
    printList(head);

    return 0;
}
*/


//Q6
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[101];
    struct Node* next;
};

struct Node* createNode(char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, char* name) {
    struct Node* newNode = createNode(name);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findMiddle(struct Node* head) {
    int len = getLength(head);
    int mid = len / 2;   
    for (int i = 0; i < mid; i++) {
        head = head->next;
    }
    return head;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Node* head = NULL;
    char name[101];

    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        append(&head, name);
    }

    struct Node* middle = findMiddle(head);
    if (middle != NULL) {
        printf("%s\n", middle->name);
    }

    return 0;
}
*/


//Q7
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int marks;
    struct Node* next;
};

struct Node* createNode(int marks) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->marks = marks;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    if (n < 2) {
        printf("Not enough students\n");
        return 0;
    }

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        struct Node* newNode = createNode(m);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }

    printf("%d\n", temp->marks + temp->next->marks);

    return 0;
}
*/


//Q8
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[21];
    struct Node* next;
} Node;

Node* createNode(char name[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    Node* head = NULL;
    Node* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        char name[21];
        scanf("%s", name);
        Node* newNode = createNode(name);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (tail != NULL) {
        printf("%s\n", tail->name);
    }

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
*/


//Q9
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[21];
    int qty;
    struct Node* next;
} Node;

Node* create(char* n, int q) {
    Node* t = (Node*)malloc(sizeof(Node));
    strcpy(t->name, n);
    t->qty = q;
    t->next = NULL;
    return t;
}

void append(Node** head, char* n, int q) {
    Node* t = create(n, q);
    if (!*head) {
        *head = t;
    } else {
        Node* p = *head;
        while (p->next) p = p->next;
        p->next = t;
    }
}

void removeItem(Node** head, char* n) {
    Node *p = *head, *prev = NULL;
    while (p && strcmp(p->name, n) != 0) {
        prev = p;
        p = p->next;
    }
    if (!p) return;
    if (!prev) *head = p->next;
    else prev->next = p->next;
    free(p);
}

void printList(Node* head) {
    if (!head) {
        printf("No items in stock\n");
        return;
    }
    while (head) {
        printf("%s %d\n", head->name, head->qty);
        head = head->next;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        char name[21];
        int q;
        scanf("%s %d", name, &q);
        append(&head, name, q);
    }
    char sold[21];
    scanf("%s", sold);
    removeItem(&head, sold);
    printList(head);
    return 0;
}
*/


//Q10
/*
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


//Q11
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void sortList(struct Node* head) {
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;
    if (head == NULL) return;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, val;
    struct Node* head = NULL;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(&head, val);
    }
    sortList(head);
    display(head);
    return 0;
}
*/


//Q12
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void skipMdeleteN(struct Node* head, int M, int N) {
    struct Node *curr = head, *t;
    int count;

    while (curr) {
        for (count = 1; count < M && curr != NULL; count++)
            curr = curr->next;

        if (curr == NULL) return;

        t = curr->next;
        for (count = 1; count <= N && t != NULL; count++) {
            struct Node* temp = t;
            t = t->next;
            free(temp);
        }
        
        curr->next = t;
        curr = t;
    }
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf("->");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int M, N, val;
    struct Node* head = NULL;

    if (scanf("%d %d", &M, &N) != 2) return 0;

    while (scanf("%d", &val) && val != -1) {
        insert(&head, val);
    }

    skipMdeleteN(head, M, N);
    display(head);

    return 0;
}
*/


//Q13
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void insertAtPosition(struct Node** head, int pos, int val) {
    if (pos == 1) {
        insertAtBeginning(head, val);
        return;
    }
    struct Node* newNode = createNode(val);
    struct Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
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
    struct Node* head = NULL;
    int choice, val, pos;

    while (1) {
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            scanf("%d", &val);
            insertAtBeginning(&head, val);
        } else if (choice == 2) {
            scanf("%d", &val);
            insertAtEnd(&head, val);
        } else if (choice == 3) {
            scanf("%d %d", &pos, &val);
            insertAtPosition(&head, pos, val);
        } else if (choice == 4) {
            display(head);
        } else if (choice == 5) {
            printf("Exiting\n");
            break;
        } else {
            printf("Wrong choice\n");
        }
    }
    return 0;
}
*/


//Q14
/*
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
*/


//Q15
/*
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void deleteLast(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    struct Node* head = NULL;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        append(&head, val);
    }
    deleteLast(&head);
    display(head);
    return 0;
}
*/