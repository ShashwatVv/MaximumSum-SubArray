#include <bits/stdc++.h>
#include <tuple>

using namespace std;
tuple<int , int, int> MaxCrossSum(int *A, int low, int mid, int high)
{
    int lSum = INT_MIN;
    int sum = 0;
    int maxleft;
    for(int i =mid; i>= low; i--)
    {
        sum = sum+ A[i];
        if(sum>lSum)
        {
            lSum = sum;
            maxleft = i;
        }
    }
    int rSum = INT_MIN;
     sum = 0;
     int maxright;
     for(int j = mid+1; j<= high; j++)
     {
         sum = sum+ A[j];
         if(sum>rSum)
         {
             rSum = sum;
             maxright = j;
         }
     }
     tuple<int, int, int> tp(maxleft, maxright, lSum + rSum );
     return tp;
}
tuple<int, int, int> MaxSumSubArray(int* A, int low, int high)
{
    tuple<int, int, int> tp;
    if (low == high)
    {
        tp = make_tuple(low, high, A[low]);
        return tp;
    }
    else
    {
        int mid = (low+ high)/2;
        int left_low,left_upper,left_sum,right_low,right_upper,right_sum,cross_low,cross_upper,cross_sum;
        tie(left_low, left_upper, left_sum) = MaxSumSubArray(A, low, mid);
        tie(right_low, right_upper, right_sum)= MaxSumSubArray(A, mid+1, high);
        tie(cross_low, cross_upper, cross_sum) = MaxCrossSum(A, low, mid, high);

        if((left_sum >= right_sum) &&(left_sum >= cross_sum))
        {
            tp = make_tuple(left_low, left_upper, left_sum);
            return tp;
        }
        else if((right_sum >= left_sum) &&(right_sum >= cross_sum))
        {
            tp = make_tuple(right_low, right_upper, right_sum);
            return tp;
        }
        else
        {
            tp = make_tuple(cross_low, cross_upper, cross_sum);
            return tp;
        }

    }
}


int main()
{
    int A[10], lower, upper,sum;
    for(int i=0; i<10;i++)
    {
        cin>> A[i];
    }
    tie(lower, upper, sum) = MaxSumSubArray(A, 0, 9);
    cout<< "The Maximum Sum SubArray is:"<<endl;
    for(int j = lower; j<= upper; j++)
    {
        cout<<A[j]<<" ";
    }
    cout<<"\n the sum of Max SUm SubArray is:"<< sum<<endl;;
    return 0;
}
