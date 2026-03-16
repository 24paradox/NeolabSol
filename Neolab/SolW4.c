//Q1
/*
#include <stdio.h>

int main(){
    int n, value;
    int count[1000] = {0};

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) == 1) {
            count[value]++;
        }
    }

    int first = 1;
    for (int i = 999; i >= 1; i--) {
        while (count[i] > 0) {
            if (!first) {
                printf(" ");
            }
            printf("%d", i);
            first = 0;
            count[i]--;
        }
    }

    return 0;
}
*/


//Q2
/*
#include <stdio.h>

int main(){
    int n,i,f=0;
    int c[21]={0};

    if(scanf("%d",&n)!=1) return 0;

    for(i=0;i<n;i++){
        int val;
        scanf("%d",&val);
        c[val]++;
    }

    for (i=1;i<21;i++){
        if(c[i]>1){
            if(f) printf(" ");
            printf("%d",i);
            f=1;
        }
    }

    if(!f) printf("-1");

    return 0;
}
*/


//Q3
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void countsort(char arr[][101], int n, int pos){
    char out[n][101];
    int c[256]={0};

    for (int i=0;i<n;i++){
        int charidx=(pos<strlen(arr[i]))?(unsigned char)arr[i][pos]:0;
        c[charidx]++;
    }

    for(int i=1;i<256;i++){
        c[i]+=c[i-1];
    }

    for (int i=n-1;i>=0;i--){
        int charidx = (pos<strlen(arr[i]))?(unsigned char)arr[i][pos]:0;
        strcpy(out[c[charidx]-1],arr[i]);
        c[charidx]--;
    }

    for (int i=0;i<n;i++){
        strcpy(arr[i],out[i]);
    }
}

void radixsort(char arr[][101], int n){
    int maxlen = 0;
    for (int i=0;i<n;i++){
        int len =strlen(arr[i]);
        if(len>maxlen)maxlen=len;
    }

    for(int pos=maxlen-1;pos>=0;pos--){
        countsort(arr,n,pos);
    }
}

int main(){
    int n;
    scanf("%d",&n);

    char fruits[n][101];
    for(int i=0;i<n;i++){
        scanf("%s",fruits[i]);
    }

    radixsort(fruits,n);

    for(int i=0;i<n;i++){
        printf("%s\n",fruits[i]);
    }

    return 0;
}
*/


//Q4
/*
#include <stdio.h>

void insertsort(int arr[], int n){
    int i,key,j;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    insertsort(arr,n);

    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        if(i<n-1){
            printf(" ");
        }
    }

    return 0;
}
*/


//Q5
/*
#include<stdio.h>

void selectsort(int arr[],int n){
    int i,j,min,temp;
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}

int main(){
    int n,k;
    scanf("%d",&n);

    int price[n];
    for(int i=0;i<n;i++){
        scanf("%d",&price[i]);
    }

    scanf("%d",&k);

    selectsort(price,n);

    printf("Sorted Order: ");
    for (int i=0;i<n;i++){
        printf("%d",price[i]);
        if(i<n-1){
            printf(" ");
        }
    }
    printf("\n");

    printf("The kth smallest price is: %d", price[k-1]);

    return 0;
}
*/


//Q6
/*
// You are using GCC
#include <stdio.h>

void selectionSort(int arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        int minIdx = i;
        for (int j = i + 1; j <= end; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    selectionSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
*/


//Q7
/*
// You are using GCC
#include <stdio.h>

void insertionSort(int arr[], int l, int r) {
    for (int i = l + 1; i < r; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j +1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    insertionSort(arr, 0, n);

    printArray(arr, n);
    return 0;
}
*/


//Q8
/*
// You are using GCC
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    float arr[100], buckets[100][100];
    int count[100] = {0};

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
        int idx = (int)(arr[i] * n);
        buckets[idx][count[idx]++] = arr[i];
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < count[i]; x++)
        {
            for (int y = 0; y < count[i] - x - 1; y++)
            {
                if (buckets[i][y] > buckets[i][y + 1])
                {
                    float temp = buckets[i][y];
                    buckets[i][y] = buckets[i][y + 1];
                    buckets[i][y+1] = temp;
                }
            }
        }

        for (int j = 0; j < count[i]; j++)
            arr[k++] = buckets[i][j];
    }

    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}
*/


//Q9
/*
// You are using GCC
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[100];
    int count[51];
    int i;

    for (i = 0; i <= 50; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        count[arr[i]]++;
    }

    int maxFreq = -1;
    int result = -1;

    for (i = 0; i <= 50; i++)
    {
        if (count[i] > maxFreq)
        {
            maxFreq = count[i];
            result = i;
        }
    }

    printf("%d", result);

    return 0;
}
*/


//Q10
/*
// You are using GCC
#include <stdio.h>

void radixSort(int a[], int n)
{
    int out[100], c[10], m = a[0];
    for (int i = 1; i < n; i++) if (a[i] > m) m = a[i];

    for (int e = 1; m / e > 0; e *= 10)
    {
        for (int i = 0; i < 10; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[(a[i] / e) % 10]++;
        for (int i = 1; i < 10; i++) c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            int d = (a[i] / e) % 10;
            out[--c[d]] = a[i];
        }
        for (int i = 0; i < n; i++) a[i] = out[i];
    }
}

int main()
{
    int n, a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    radixSort(a, n);

    int res = -1;
    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || a[i] != a[i - 1]) && (i == n - 1 || a[i] != a[i + 1]))
        {
            res = a[i];
            break;
        }
    }

    printf("%d", res);
    return 0;
}
*/


//Q11
/*
#include<stdio.h>
#include<stdlib.h>

struct Node{
    long long val;
    struct Node *next;
};

int main(){
    int n,i;
    scanf("%d",&n);
    
    struct Node **buckets = malloc(n*sizeof(struct Node*));
    for (i=0;i<n;i++){
        buckets[i]=NULL;
    }
    
    long long *arr = malloc(n* sizeof(long long)), min =1e18, max=0;
    
    for (i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        if(arr[i]<min) min = arr[i];
        if(arr[i]>max) max = arr[i];
    }
    
    for (i=0; i<n; i++){
        int idx=(max==min)? 0 : (int)((double)(arr[i]-min)/(max-min+1)*n);
        struct Node *newN=malloc(sizeof(struct Node)), **curr = &buckets[idx];
        newN->val = arr[i];
        while(*curr && (*curr)->val < arr[i]) curr = &((*curr)->next);
        newN->next =*curr;
        *curr = newN;
    }
    
    printf("sorted barcode numbers:\n");
    for(i=0;i<n;i++){
        for (struct Node *b =buckets[i]; b; b=b->next){
            printf("%lld\n", b->val);
        }
    }
    return 0;
}
*/


//Q12
/*
#include <stdio.h>
#include <stdlib.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    radixSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }

    free(arr);
    return 0;
}
*/


//Q13
/*
#include <stdio.h>
int main(){
    int n,k,val,cc=0;
    int c[101]={0};
    
    scanf("%d",&n);
    
    for (int i=0; i<n; i++){
        scanf("%d",&val);
        c[val]++;
    }
    
    scanf("%d",&k);
    
    for (int i=0;i<=100;i++){
        cc+=c[i];
        if(cc>=k){
            printf("Kth smallest element is %d\n", i);
            break;
        }
    }
    
    return 0;
}
*/


//Q14
/*
#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

void selectionSort(struct Date arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].year < arr[min_idx].year) {
                min_idx = j;
            } else if (arr[j].year == arr[min_idx].year) {
                if (arr[j].month < arr[min_idx].month) {
                    min_idx = j;
                } else if (arr[j].month == arr[min_idx].month) {
                    if (arr[j].day < arr[min_idx].day) {
                        min_idx = j;
                    }
                }
            }
        }
        struct Date temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Date dates[20];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &dates[i].day, &dates[i].month, &dates[i].year);
    }

    selectionSort(dates, n);

    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", dates[i].day, dates[i].month, dates[i].year);
    }

    return 0;
}
*/


//Q15
/*
#include <stdio.h>

int main() {
    int n, count = 0;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            count++;
            j--;
        }
        arr[j + 1] = key;
    }

    printf("%d\n", count);

    return 0;
}
*/