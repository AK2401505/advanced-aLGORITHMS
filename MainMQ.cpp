#inlcude<iostream>
using namespace std;

int main() {
Sorter s; int tmp[8];
int a[] = {64,25,12,22,11,90,45,34}; int n=8;
// mergeSort
copy(a,a+n,tmp); s.mergeSortAlgo(tmp,0,n-1);
cout<<"MS: "; for(int x:tmp) cout<<x<<" "; cout<<endl;
// quickSort
copy(a,a+n,tmp); s.quickSort(tmp,0,n-1);
cout<<"QS: "; for(int x:tmp) cout<<x<<" "; cout<<endl;
// worst-case for quickSort: sorted array
int sorted[] = {1,2,3,4,5,6,7,8};
copy(sorted,sorted+n,tmp); s.quickSort(tmp,0,n-1);
cout<<"QS sorted: "; for(int x:tmp) cout<<x<<" "; cout<<endl;
// quickSortM3 on same sorted array
copy(sorted,sorted+n,tmp); s.quickSortM3(tmp,0,n-1);
cout<<"QSM3 sorted: "; for(int x:tmp) cout<<x<<" "; cout<<endl;
return 0;
}
