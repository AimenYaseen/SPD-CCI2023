#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	deque<int> window;

    // initializes left or right pointer
    int l = 0, r = 0;

    // continue until right reaches at end
    while(r < n)
    {
    // remove values from queue back if it is smaller than current pos and queue is not empty
    while(!window.empty() && arr[r] > arr[window.back()])
        window.pop_back();

    // here we get the greater value so push it
    window.push_back(r);

    // let's suppose we have 9, 5 in queue right now
    // 9 is the last windows max.
    // 5 is the current window max
    // 9 didn't pop because it is > 5.
    // so, we check if l pointer > queue top index which is 9
    // if it is then we pop from front
    if(l > window.front())
        window.pop_front();

    // this condition will not executed only for first k iterations
    // because we have to find the first max.
    // after that we just need to check last element of window
    // as we checked previous already
    if(r >= k - 1)
    {
        cout << arr[window.front()] << " ";
        l++;
    }
    r++;
    }
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
