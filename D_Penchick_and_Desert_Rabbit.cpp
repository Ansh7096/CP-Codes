#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void sol()
{
   int n;
   cin >> n;
   vector<int> v(n);
   for (int i = 0; i < n; i++)
   {
      cin >> v[i];
   }

   vector<int> ans(n);

   // Left-to-right pass (forward jumps: ai > aj)
   stack<int> s;
   for (int i = 0; i < n; i++)
   {
      while (!s.empty() && v[s.top()] < v[i])
      {
         ans[s.top()] = max(ans[s.top()], v[i]);
         s.pop();
      }
      s.push(i);
   }

   // For the remaining elements in the stack, they can only reach themselves
   while (!s.empty())
   {
      ans[s.top()] = max(ans[s.top()], v[s.top()]);
      s.pop();
   }

   // Right-to-left pass (backward jumps: ai < aj)
   for (int i = n - 1; i >= 0; i--)
   {
      while (!s.empty() && v[s.top()] < v[i])
      {
         ans[s.top()] = max(ans[s.top()], v[i]);
         s.pop();
      }
      s.push(i);
   }

   // For the remaining elements in the stack, they can only reach themselves
   while (!s.empty())
   {
      ans[s.top()] = max(ans[s.top()], v[s.top()]);
      s.pop();
   }

   // Output the results for this test case
   for (int i = 0; i < n; i++)
   {
      cout << ans[i] << " ";
   }
   cout << endl;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int t;
   cin >> t;
   while (t--)
   {
      sol();
   }
   return 0;
}
