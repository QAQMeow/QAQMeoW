#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
  
    vector<int> getNarcissisticNumbers(int n) {
        vector<int> A;
        vector<int> Num = {0,1,2,3,4,5,6,7,8,9};
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < Num.size(); j++)
            {
                s = Num[j];
            }
        }

        return A;

    }
};
int main()
{
    Solution S;
    vector<int> E = S.getNarcissisticNumbers(2);
    for (int i = 0; i < E.size(); i++)
    {
        cout << E[i] << ' ';
    }
    return 0;
}
