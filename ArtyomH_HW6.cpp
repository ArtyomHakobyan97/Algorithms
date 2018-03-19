#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

int D[1000][1000];
vector<int> v1;
//	vector<int> v2; decided to do it with only one vector v1

int A[1000];
int M, N;



/////////////////  UPGRADED VERSION OF RECURSIVE KNAPSACK	//////////////////
int D_rec(int i, int j,  int st, vector<int> v)
{
	if(i == 0 || j == 0)
		return 0;
	if(D[i][j] != -1)
		return D[i][j];
	if(j-A[i+st] > 0)
	{
		int res = max(D_rec(i-1, j, st, v), D_rec(i-1, j-A[i+st]+A[i+st], st, v));	// i+st to use values from  middle (index st) of array A
		D[i][j] = res;
		v.push_back(res);	//////////// saves values < desired number in vector  v1.
		return res;
	}
	
	int res = D_rec(i-1, j, st, v);
	D[i][j] = res;
	return res;
}


// upgraded,  original from geeksforgeeks
// this one returns the closest value from below to the desired sum number
int findpair(vector<int> arr, int sum)
{
    std::sort(arr.begin(), arr.end());
    int i = 0;
    int j = arr.size()-1;
	int closest = 0;
    while( i < j){
        while((arr[i] + arr[j]) <= sum && i < j)
        {
			int temp = arr[i] + arr[j];
			if(closest < temp)
				closest = temp;
            if(temp == sum)
                cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
            i++;
        }
        j--;
        while((arr[i] + arr[j]) >= sum && i < j)
        {
            if((arr[i] + arr[j]) == sum)
                cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
            j--;
        }
    }
	return closest;
}


///////////////// THE MAIN PART	///////////////////////////
int knapsack(int capacity, int desired, int lengthA)
{
	int mid = lengthA/2;
	
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= M; ++j)
		{
			D[i][j] = -1;
		}
	}
	
	
///////////// FILL first half	/////
	D_rec(capacity, desired, 0, v1);

	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= M; ++j)
		{
			D[i][j] = -1;
		}
	}

////////// FILL second half		/////
	D_rec(capacity, desired, mid, v1);	
	
	std::sort(v1.begin(), v1.end());
	//std::sort(v2.begin(), v2.end());
	
	
	int ans = findpair(v1, desired);
	
	return ans;
	
}