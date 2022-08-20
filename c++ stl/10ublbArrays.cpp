#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);
			freopen("error.txt","w",stderr);
	#endif
	/**
	 * There are basically two functions 
	 * 1. upper_bound()
	 * 2. lower_bound()
	 **/

	/**
	 * NOTE:
	 * upper_bound and lower_bound work only when the data is sorted 
	 * So before you apply them to a range make sure that the range is sorted
	 * 
	 * In particular for arrays and vectors, We use std::sort() function before
	 * applying std::lower_bound() and std::upper_bound() algorithms
	 * 
	 * However,for sets and maps we do not need to explicitly sort the elements
	 * as they are already sorted.
	 **/

	/**
	 * lower_bound(first,last,x)
	 * 
	 * This function gives the iterator pointing to the first element which is 
	 * greater than or equal to `x` in the range [first, last)
	 * 
	 * if all the elements in the range [first, last) are < `x`, then it returns 
	 * the last iterator
	 **/

	/**
	 * upper_bound(first,last,x)
	 * 
	 * This function gives the iterator pointing to the first element which is
	 * greater than `x` in the range [first,last)
	 * 
	 * If all the elements int the range [first,last) are <= `x`, the it returns
	 * the last iterator
	 **/
	int n;
	cin >> n; // 6

	int *arr =  new int[n];
	for(int i=0;i<n;i++) cin >> arr[i]; // 4 5 5 25 7 8

	sort(arr,arr+n); // This step is a must 4 5 5 7 8 25 

	auto i = lower_bound(arr,arr+n,4); // we are at 4 
	
	cout << *i << endl;

	auto j = lower_bound(arr,arr+n,6); // we are at 7 now

	cout << *j << endl;

	auto k = lower_bound(arr,arr+n,26); // we are at the end now

	if(k == arr+n)
	{
		/**
		 * Since all elements in the range were less than 26
		 **/
		cout << "Not found" << endl;
	}

	auto l = upper_bound(arr,arr+n,5); // 5 is present but we are at 7

	cout << *l << endl;

	auto m = upper_bound(arr,arr+n,25); // we are arr+n

	if(m == arr+n)
	{
		/**
		 * We are at end because no element was greater than 25
		 **/
		cout << "Yes, We are at last" << endl;
	}
	return 0;
}
