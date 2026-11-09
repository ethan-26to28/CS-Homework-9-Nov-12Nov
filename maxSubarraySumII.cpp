#include <iostream>
#include<vector>
#include <climits> 
using namespace std;

int main(){
    int n,a,b;
    long long G_sum,sum;
    cin>>n>>a>>b;
    vector<long long> list(n);
    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    G_sum=LLONG_MIN;
    for(int i=a;i<(b+1);i++){
        sum=0;
        for(int j=0;j<i;j++){sum=sum+list[j];}
        int k=0;
       if(sum>G_sum){
        G_sum=sum;
       }
        while(k<(n-i)){
            sum=sum-list[k]+list[(k+i)];
            if(sum>G_sum){
                G_sum=sum;
            }
            k++;
        }
        
    }

    cout<< G_sum;
    return 0;
}