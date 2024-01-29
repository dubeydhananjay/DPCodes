#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
    void nsl(vector<int>& heights, vector<int>& v, stack<pair<int,int>>& s, int size, int pseudoIndex) {

        for(int i = 0; i < size; i++) {
            if(s.size() == 0) {
                v.push_back(pseudoIndex);
            }
            else if(s.size() > 0 && s.top().first >= heights[i]) {
                while(s.size() > 0 && s.top().first >= heights[i]) {
                    s.pop();
                }
                if(s.size() == 0) {
                    v.push_back(pseudoIndex);
                }
                else {
                    v.push_back(s.top().second);
                }
            }
            else {
                 v.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }
    }

    void nsr(vector<int>& heights, vector<int>& v, stack<pair<int,int>>& s, int size, int pseudoIndex) {
      
        for(int i = size - 1; i >= 0; i--) {
            if(s.size() == 0) {
                v.push_back(pseudoIndex);
            }
            else if(s.size() > 0 && s.top().first >= heights[i]) {
                while(s.size() > 0 && s.top().first >= heights[i]) {
                    s.pop();
                }
                if(s.size() == 0) {
                    v.push_back(pseudoIndex);
                }
                else {
                    v.push_back(s.top().second);
                }
            }
            else {
                 v.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }
        reverse(v.begin(),v.end());
    }

    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> left;
        vector<int> right;
        stack<pair<int,int>> s;
        nsl(heights,left, s, size, -1);
        while(!s.empty()) {
            s.pop();
        }
        nsr(heights,right, s, size, size);
        int mx = INT_MIN;
        for(int i = 0; i < size; i++) {
            int n = (right[i] - left[i] - 1) * heights[i];
            mx = max(mx,n);
        }
        return mx;
    }
