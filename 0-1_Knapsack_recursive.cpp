//knapsack recursive
#include <iostream>
using namespace std;

int Knapsack(int wt[], int val[], int W, int n) {
	
	if (n == 0 || W == 0)
		return 0;

	
	if (wt[n - 1] <= W) {
		return max(val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1),
		           Knapsack(wt, val, W, n - 1));
	}

	else if (wt[n - 1] > W) 
		return Knapsack(wt, val, W, n - 1); 
	else
		return -1; 
}

int main() {
	int n,W; 
    cin >> n;
	int val[n], wt[n];
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	
    cin >> W; // Knapsack capacity

	cout << Knapsack(wt, val, W, n) << endl;
	return 0;
}