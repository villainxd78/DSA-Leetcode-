class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
        vector<int>nsl(n);
        vector<int>nsr(n);
        nsl[0]=-1;
        st.push(0);
        for(int i = 1;i<n;i++){
          int curr = heights[i];
          while(!st.empty() && curr<heights[st.top()]){
            st.pop();
          }
          if(st.empty()){
            nsl[i]=-1;
          }else{
            nsl[i]=st.top();
          }
          st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }

        n = heights.size();
        st.push(n-1);
        nsr[n-1]=n;
        for(int i= n-2;i>=0;i--){
            int curr = heights[i];
            while(!st.empty() && curr<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nsr[i]=n;
            }
            else{
                nsr[i]= st.top();
            }
            st.push(i);
        }
        int maxarea = 0;
        for(int i = 0;i<n;i++){
            int ht = heights[i];
            int width = nsr[i]-nsl[i]-1;
            int area = ht* width;
            maxarea = max(maxarea,area);
        }

        return maxarea;
    }
};