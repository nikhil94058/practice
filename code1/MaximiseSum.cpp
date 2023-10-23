#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    vector<int> nums;
	    int n;
	    cin>>n;
	    
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        nums.push_back(x);
	    }
	    
	   // vector<int> leftmax(n,-1);
	   // vector<int> rightmax(n,-1);
	    
	   // int x = INT_MIN;
	    
	   // for(int i=1;i<nums.size();i++)
	   // {
	   //    x = max(x,nums[i-1]);
	   //    leftmax[i] = x;
	   // }
	     
	   //  x = INT_MAX;
	   // for(int i=nums.size()-2;i>=0;i--)
	   // {
	   //    x = max(x,nums[i+1]);
	   //    rightmax[i] = x;
	   // }
	    
	   // for(int i=1;i<nums.size()-1;i++)
	   // {
	   //     if(nums[i]<leftmax[i] && nums[i]<rightmax[i])
	   //     {
	   //        nums[i] = min(leftmax[i],rightmax[i]);  
	   //     }
	   // }
	    
	   // long long sum = 0;
	   // for(int i=0;i<nums.size();i++)
	   // {
	   //     sum = sum + nums[i];
	   // }
	   // cout<<sum<<endl;
	   
	    vector<int> leftmax(n);
	    vector<int> rightmax(n);
	    
	    leftmax[0] = nums[0] ;
	    rightmax[n-1] = nums[n-1];
	    
	    for(int i=1;i<nums.size();i++)
	    {
	        leftmax[i] = max( leftmax[i-1] ,nums[i]);
	      
	    }
	     
	    
	    for(int i=nums.size()-2;i>=0;i--)
	    {
	       rightmax[i] = max(rightmax[i+1],nums[i]);
	   
	    }
	    
	    for(int i=0;i<nums.size();i++)
	    {
	       
	           nums[i] = min(leftmax[i],rightmax[i]);  
	        
	    }
	    
	    long long sum = 0;
	    for(int i=0;i<nums.size();i++)
	    {
	        sum = sum + nums[i];
	    }
	    cout<<sum<<endl;
	   
	    
	}
	return 0;
}