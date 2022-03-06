void quick_sort(int a[], int start, int end){
if(start >= end) return;
int p=start, l=start, r=end;
while(l < r){
while(p < r){
if(a[p] <= a[r]) --r;
else{
a[r] = (a[p]+a[r]) - (a[p]=a[r]);
++l, p = r;
break;
}}
while(l < p){
if(a[l] <= a[p]) ++l;
else{
a[p] = (a[l]+a[p]) - (a[l]=a[p]);
--r, p = l;
break;
}}}
if(p-start > 1) quick_sort(a, start, p-1);
if(end-p > 1) quick_sort(a, p+1, end);
}

void quickSort(int input[], int size) {
quick_sort(input, 0, size-1);
}