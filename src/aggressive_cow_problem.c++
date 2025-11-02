/*There is a new barn with N stalls and C cows. The stalls are located on a 
straight line at positions x1, xN (0 <= xi <= 1,000,000,000). We want to assign the 
cows to the stalls, such that the minimum distance between any two of them is as 
large as possible. What is the largest minimum distance?*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &arr, int N, int C, int minAllowedDist){
    int cows=1, laststallpos=arr[0];

    for(int i=1; i<N; i++){
        if(arr[i]-laststallpos >= minAllowedDist){
            cows++;
            laststallpos=arr[i];
        }
        if(cows==C){
            return true;
        }
    }
    return false;
}

int getDistance(vector<int> &arr, int N, int C){
    sort(arr.begin(), arr.end());

    int st=1, end=arr[N-1]-arr[0], ans=-1;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(isPossible(arr, N, C, mid)){
            ans=mid;
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr={1,2,8,4,9};
    int N=5, C=3;

    cout << getDistance(arr,N,C) << endl;
    return 0;
}