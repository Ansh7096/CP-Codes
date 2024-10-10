// AG___
//There is a one percent chance, and sometimes that chance is good enough.
//But what matters is what you think about that one percent.

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
int qq(string s)
{
    cout << "? " << s << endl;
    cout.flush();
        int z;
        cin >> z;
        return z;
}
void sol()
{
        int n;
        cin >> n;
        cout.flush();
        if (n == 1) {
           
            if (qq("1")) 
                cout << "! 1" << endl;
             else 
                cout << "! 0" << endl;
                cout.flush();
            
            return;
        }

        string ans = "";
        if (qq("00")) 
            ans = "00";
        else if (qq("01")) 
            ans = "01";
        else if (qq("10")) 
            ans = "10";
        else {
            
            string s(n, '1');
            cout << "! " << s << endl;
            cout.flush();
            return;
        }

        bool z = false;  

      
        for (int i = 0; i < n - 2; i++) {
            string s1 = ans + "0";
            string s2 = ans + "1";
            
            if (!z) {
                if (qq(s1)) 
                    ans = s1;
                 else if (qq(s2)) 
                    ans = s2;
                 else 
                    z = true; 
                
            }

            if (z) {
                string s1 = "0" + ans;
                string s2 = "1" + ans;
                if (qq(s1)) 
                    ans = s1;
                 else 
                    ans = s2;
                
            }
        }

        cout << "! " << ans << endl;
        cout.flush();
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    //t = 1;
    cin>>t;
    while (t--)
    {
        sol();
    }
}