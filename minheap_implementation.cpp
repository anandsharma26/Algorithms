#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y);
class MinHeap{
    int *harr;
    int capacity;
    int heap_size;
    public:
    MinHeap(int a[],int size); 
    void buildheap();
    void minheapify(int i);
    int extractmin();
    int getmin(){return harr[0];}
    void replace(int x){harr[0]=x;minheapify(0);}
    };
    
    MinHeap::MinHeap(int a[],int size){heap_size=size;harr=a;}
    void MinHeap::buildheap(){
        int i=(heap_size-1)/2;
        while(i>=0){
            minheapify(i);
            i--;
        }
    }
    void MinHeap::minheapify(int i){
        int smallest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(heap_size>0&&harr[l]<harr[i]){smallest=l;}
        if(heap_size>0&&harr[r]<harr[i]){smallest=r;}
        if(smallest!=i){
            swap(&harr[i],&harr[smallest]);
            minheapify(smallest);
        }
    }
    int MinHeap::extractmin(){
        if(heap_size==0)return INT_MAX;
        int root=harr[0];
        if(heap_size>1){
            harr[0]=harr[heap_size-1];
            minheapify(0);
        }
        heap_size--;
        return root;
    }
    void swap(int *x,int *y){int temp=*x;*x=*y;*y=temp;}
    

int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	int k,n;
	cin>>k>>n;
	int *arr=new int[k];
	vector<int>res;
	MinHeap mh(arr,k);
	int count=0;
	for(int i=0;i<n;i++){
	    int stream_inp;
	    cin>>stream_inp;
	    if(count<k-1){res.push_back(-1);arr[count]=stream_inp;count++;}
	    else {
	        if(count==k-1){arr[count]=stream_inp;mh.buildheap();
	                        res.push_back(mh.getmin());}
	        else{
	            if(stream_inp>mh.getmin()){mh.replace(stream_inp);
	                res.push_back(mh.getmin());
	            }
	        }
	        count++;
	        
	    }
	    
	    
	   
	}
	for(int i=0;i<res.size();i++)cout<<res[i]<<" ";cout<<endl;
	
	delete[] arr;
	}
	
	
	
	return 0;
}
