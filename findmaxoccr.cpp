#include<iostream>
using namespace std;
char maxoccr(string s){
    int ar[26]={0};
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        int index=0;
        index=ch-'a';
        ar[index]++;
    }
    int ans=0;
    char res;
    for(int i=0;i<26;i++){
        int max=-1;
        if(ar[i]>max){
            ans=i;
            max=ar[i];
        }
    }
    
    return 'a'+ans;
}
int main()
{
    string s[20];
    cout<<"enter string "<<endl;
    cin>>s;
    cout<<"the maximun occured char is "<<maxoccr(s);
}