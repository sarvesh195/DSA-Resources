#include<iostream>
using namespace std;
bool binarysearch(int arr[], int s, int e, int k){
    if(s > e){
        return false;
    }
    int mid = s+(e-s)/2;

    if (arr[mid] == k){
        return true;
    }

    if(arr[mid]<k){
        return binarysearch(arr, mid+1, e, k);
    }
    else{
        return binarysearch(arr, s, mid-1, k);
    }
}

int main() {

int arr[6]= {1, 2, 7, 10, 16, 20};
int n = 6;
int key = 56 ;
cout <<"present"<< binarysearch(arr, 0, 5, 56);
return 0;

}
