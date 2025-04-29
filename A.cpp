#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, d, l;
    cin >> n >> d >> l;

    if((l-2)*d<(n-d-1)*2) cout << -1 << endl;
    else if(n==l) cout << -1 << endl;
    else{ 
        
        
        int left = d / 2, par=1, child=2;
        for(int i=0; i<left; i++){
            cout << par << " " << child << endl;
            par++; child++;
        }

    
        int right = left + (d%2);
        par = 1;
        for(int i=0; i<right; i++){
            cout << par << " " << child << endl;
            par = child;
            child++;
        }

        if(l>2) 
        {
            int rem = (n-d-1), leavesleft = l-2;
            vector<int> leaves(leavesleft);

            par = 1;
            for(int i=0; i<leavesleft; i++){
                cout << 1 << " " << child << endl;
                leaves[i] = child;
                child++;            
            }

            rem = rem - leavesleft;
            int index = 0;

            while(rem>0){
                cout << leaves[index] << " " << child << endl;
                leaves[index]=child;
                child++;
                index=(index+1)%leaves.size();
            }
        }
    }

  }
 return 0;
}