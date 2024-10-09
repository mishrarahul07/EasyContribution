// https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/0
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

int locpivot(char v[9], int s, int e)
{
    char piv = v[s];
    int i = s+1;
    int j = e;
    while(i<=j && i<=e && j>=s)
    {
        if(int(v[i])>int(piv) && int(v[j])<int(piv))
        {
            char temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
        if(int(v[i])<=int(piv))
        {
            i++;
        }
        if(int(v[j])>=int(piv))
        {
            j--;
        }
    }
    char temp = v[s];
    v[s] = v[j];
    v[j] = temp;
    return j;
}
void quicksort(char v[9], int s, int e)
{
    if(s<e)
    {
       int p = locpivot(v, s, e);
        quicksort(v, s, p-1);
        quicksort(v, p+1, e);
    }
}



//User function template for C++
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    quicksort(nuts, 0, n-1);
	    quicksort(bolts, 0, n-1);
	}

};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
