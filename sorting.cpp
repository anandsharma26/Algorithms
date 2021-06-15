#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void selection_sort(int arr[],int n){
    int  min_ind;
    for(int i=0;i<n-1;i++){
        min_ind=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_ind]){min_ind=j;}
        }
        swap(&arr[min_ind],&arr[i]);
    }
}
void insertion_sort(int arr[],int n){
    int key;
    int i;
    for(i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j] >key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int arr1[n1];
    int arr2[n2];
    for(int i=0;i<n1;i++){arr1[i]=arr[l+i];}
    for(int j=0;j<n2;j++){arr2[j]=arr[m+j+1];}
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(arr1[i]<=arr2[j]){arr[k]=arr1[i];i++;}
        else {arr[k]=arr2[j];j++;}
        k++;
    }
    while(i<n1){arr[k]=arr1[i];i++;k++;}
    while(j<n2){arr[k]=arr2[j];j++,k++;}
    

}
void mergesort(int arr[],int p,int r){
    if(p>=r){return;}
    int q=p+(r-p)/2;
    mergesort(arr,p,q);
    mergesort(arr,q+1,r);
    merge(arr,p,q,r);
}
int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    //selection_sort(arr,n);
    //insertion_sort(arr,n);
    //mergesort(arr,0,n-1);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;
}
