/* There are N children standing in a line with some rating value. You want to 
distribute a minimum number of candies to these children such that: Each child must 
have at least one candy. The children with higher ratings will have more candies than 
their neighbors. You need to write a program to calculate the minimum candies you 
must give. */

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> rating(n), candy(n, 1);

    for(int i=0; i<n; i++) cin >> rating[i];

    for(int i=1; i<n; i++){
        if(rating[i] > rating[i-1]){
            candy[i] = candy[i-1] + 1;
        }
    }

    for(int i=n-2; i>=0; i--){
        if(rating[i] > rating[i+1] && candy[i] <= candy[i+1]){
            candy[i] = candy[i+1] + 1;
        }
    }

    int total = 0;
    for(int C : candy){
        total += C;
    }

    cout << total;
    return 0;
}