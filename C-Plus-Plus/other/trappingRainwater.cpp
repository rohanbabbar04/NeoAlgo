/* C++ program to solve Trapping Rainwater problem.An array of non-negative integers are given which
represent an elevation height each of width 1, the
goal is to compute total water trapped after raining*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height){
    	int n = height.size();
    	int left = 0 , right = n-1;
    	// Initialize output
    	int res = 0;
    	// Maximum element on left and right
        int max_left = 0, max_right = 0;

        while(left <= right){

        	if(height[left] <= height[right]){

        		if(height[left] >= max_left)
        			// Update max in left
        			max_left = height[left];
        		else
        			// Water trapped on current index is max - current height
        			res += max_left - height[left];
        		left++;
        	}
        	else{

        		if(height[right] >= max_right)
        			// Update max in right
        			max_right = height[right];
        		else
        			res += max_right - height[right];
        		right--;
        	}
        	return res;
    }
};

int main(){
	int n, val;
	vector<int> height;
	cin >> n;
	while(n--){
		cin >> val;
		height.push_back(val);
	}
	Solution sol;
	int result = sol.trap(height);
	cout << result;
}

/*

Input -

n = 5
arr[n] = {2,3,1,0,5}

Sample Output -

Maximum water that can be accumulated is 5

Explanation -

Two units of water can be stored at indexe 2 and 
3 units at index 3

Time Complexity : O(n)
Space Complexity : O(1) 

*/