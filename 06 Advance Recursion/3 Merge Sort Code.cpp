void merge(int a[], int p, int q, int r){
int i=p, j=q+1, k=0;
int *temp=new int[r-p+1];
while(i <= q && j <= r){
if(a[i] < a[j]) temp[k++] = a[i++];
else temp[k++] = a[j++];
}
while(i <= q) temp[k++] = a[i++];
while(j <= r) temp[k++] = a[j++];
for(int i=r; i>=p; i--)
a[i] = temp[--k];
delete[] temp;
}

void merge_sort(int a[], int p, int r){
if(p < r){
int q=(p+r)/2;
merge_sort(a, p, q);
merge_sort(a, q+1, r);
merge(a, p, q, r);
}}

void mergeSort(int input[], int size){
merge_sort(input, 0, size-1);
}