int main()
{
 ios::sync_with_stdio(false);
  cin.tie(0);
ll t;cin>>t;
while(t--){
 string s;
 cin>>s;
 string res="";
if(s.size()==1){
 cout<<char(s[0]+1)<<s[0]<<endl;
}
else{
 int f=0;


 for(int i=0;i<s.size();i++){
  res.push_back(s[i]);
  if(i+1<s.size()&&s[i]==s[i+1]&&f==0){
   res.push_back(char(s[i]+1));
   f=1;

  }


 }
 if(!f)res.push_back(char(s[s.size()-1]+1));
 cout<<res<<endl;
}
}