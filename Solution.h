#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>

using namespace std;


class Solution
{
public:
	vector<vector<int>>	getComb(int *vals, int n, int S)
	{
		vector<vector<int>> result; vector<int> singleComb;
		if(n == 0 || S == 0) return result;

		AllocateMemory(S + 1);

		//Initialize DP Array
		resultArr[0].push_back(singleComb);

		//Run DP Array
		for(int i = 0; i < n; ++i) {
			for(int s = 0; s <= S; ++s) {
				if(s >= vals[i])
					combineResult(resultArr[s], resultArr[s-vals[i]], vals[i]);
			}
		}

		result = resultArr[S];
		FreeMemory();
		return result;
	}

private:
	vector<vector<int>>	*resultArr;

	void AllocateMemory(int n)
	{
		resultArr = new vector<vector<int>>[n];
	}

	void FreeMemory()
	{
		delete [] resultArr;
	}

	void combineResult(vector<vector<int>> &dest, const vector<vector<int>> &src, int number)
	{
		int size = src.size();
		vector<int> singleRes;
		for(int i = 0; i < size; ++i) {
			singleRes = src[i];
			singleRes.push_back(number);
			dest.push_back(singleRes);
		}
	}
};

#endif // SOLUTION_H
