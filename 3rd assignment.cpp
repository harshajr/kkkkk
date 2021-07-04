1st ans)
#include <bits/stdc++.h>


bool isSubset(int arr1[], int arr2[],
			int m, int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (arr2[i] == arr1[j])
				break;
		}
		if (j == m)
			return 0;
	}

	
	return 1;
}
int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, arr2, m, n))
		printf("arr2[] is subset of arr1[] ");
	else
		printf("arr2[] is not a subset of arr1[]");

	getchar();
	return 0;
}




2nd ans)
#include <bits/stdc++.h>
using namespace std;
bool find3Numbers(int A[], int arr_size, int sum)
{
	int l, r;
	for (int i = 0; i < arr_size - 2; i++)
	{

		for (int j = i + 1; j < arr_size - 1; j++)
		{

			for (int k = j + 1; k < arr_size; k++)
			{
				if (A[i] + A[j] + A[k] == sum)
				{
					cout << "Triplet is " << A[i] <<
						", " << A[j] << ", " << A[k];
					return true;
				}
			}
		}
	}

}
int main()
{
	int A[] = { 1, 4, 45, 6, 10, 8 };
	int sum = 22;
	int arr_size = sizeof(A) / sizeof(A[0]);
	find3Numbers(A, arr_size, sum);
	return 0;
}

3rd ans)

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // minimum load accepted is atleast the maximum weight
        //maximum load accepted can be the sum of all the weights and everything can be shipped in a single day
        int low = 0 , high = 0;
        for(auto w: weights){
            low = max(low,w);
            high += w;
        }
        while(low<=high){
            int mid = low+(high-low)/2; //current maximum capacity of the ship. 
            int curr_wt=0, days_needed = 1; //you need atleast a day to ship things
            for(auto w:weights){
                if(w + curr_wt > mid) {
                    days_needed++;
                    curr_wt = 0;
                }
                curr_wt += w;
            }
            if(days_needed>days) //you are not able to ship all the weights within 'days' days with 'mid' as the maximum capacity. Hence the maximum capacity has to be increased.
            {
                low = mid+1; 
            }
            else {
                high = mid-1; 
                //Well there might be a possibility of reducing the maximum capacity 
            }
        }
        return low;
    }
};

