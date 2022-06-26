#include <bits/stdc++.h>
using namespace std;
struct item{
    int weight;
    int value;
    item(int w,int p){
        weight = w;
        value = p;
    }
};

bool cmp(item a, item b){
    double r1 = a.value/a.weight;
    double r2 = b.value/b.weight;
    return r1 > r2;
}

double solve(vector<item> items, int n, int W)
{
    sort(items.begin(),items.end(),cmp);

    int currWeight=0;
    double finalProfit=0;

    for(int i=0;i<n;i++){
        if(currWeight + items[i].weight <= W){
            currWeight += items[i].weight;
            finalProfit += items[i].value;
        }
        else{
            int remain = W - currWeight;
            finalProfit += (items[i].value/(double)items[i].weight) * remain;
        }
    }
    return finalProfit;
}

int main(){
    int n,W;
    cout<<"enter no of items:";
    cin>>n;
    cout<<"enter capacity of knapsack:";
    cin>>W;
    vector<item> items;
    for(int i=0;i<n;i++){
        int w,p;
        cin>> w >> p;
        items.push_back(item(w,p));
    }

    cout<<"max profit earned: "<< solve(items,n,W);
}