#include <iostream>
using namespace std;
string S="Aa/A";
string A="B/b";
string B="a";
int main()
{
	cout<<"removal of unit production\n";
	cout<<"S->"<<S<<"\n";
	cout<<"A->"<<A<<"\n";
	cout<<"B->"<<B<<"\n";
	int i,j; string s=""; 
	string a=""; 
	string b="";
	S="/"+S+"/";
	A="/"+A+"/";
	B="/"+B+"/";
	for (i=0;i<B.length();i++)
	{
		if(B[i]=='A' or B[i]=='B' or B[i]=='S'){
		if(B[i-1]=='/' and B[i+1]=='/'){
			if(B[i]=='S'){B=B+S; }
			if(B[i]=='A'){B=B+A;}
			if(B[i]=='B'){ B=B+B;}
		}
		}
		else{ continue; }
	}
	for(i=1;i<B.length()-1;i++)
	{
		if(B[i]=='A' or B[i]=='B' or B[i]=='S')
		{
	 		if(B[i-1]=='/' and B[i+1]=='/') 
			 { continue; }
		}
		if(B[i]=='/' and B[i+1]=='/')
		{ 
			i++;
		}
		b=b+B[i]; 
	}
	for (i=0;i<A.length();i++)
	{
		if(A[i]=='A' or A[i]=='B' or A[i]=='S')
		{
			if(A[i-1]=='/' and A[i+1]=='/')
			{ 
				if(A[i]=='S'){ A=A+S; }
				if(A[i]=='A'){ A=A+a;}
				if(A[i]=='B'){ A=A+b;} 
			}
		}
		else
		{
			continue; 
		}
	}
	for(i=1;i<A.length();i++)
	{
		if(A[i]=='A' or A[i]=='B' or A[i]=='S'){
		if(A[i-1]=='/' and A[i+1]=='/') { i++; continue; }}
		if(A[i]=='/' and A[i+1]=='/'){ i++;}
		a=a+A[i]; 
	}
	for (i=0;i<S.length();i++)
	{
		if(S[i]=='A' or S[i]=='B' or S[i]=='S'){
		if(S[i-1]=='/' and S[i+1]=='/')
		{ if(S[i]=='S')
		{
			S=S+S; 
		}
		if(S[i]=='A'){ S=S+a;}
		if(S[i]=='B'){ S=S+b;} }
		}
		else{continue;}
	}
	for(i=1;i<S.length();i++)
	{
		if(S[i]=='A' or S[i]=='B' or S[i]=='S')
		{
	 		if(S[i-1]=='/' and S[i+1]=='/')
			 { 
			 	i+=1;
	 			continue; 
			}
		}
		if(S[i]=='/' and S[i+1]=='/')
		{ 
			i++;
		}
		s=s+S[i]; 
	}
	cout<<"\n";
	cout<<"productions after removing the unit production\n";
	cout<<"S->"<<s<<"\n";
	cout<<"A->"<<a<<"\n";
	cout<<"B->"<<b<<"\n"; 
}
