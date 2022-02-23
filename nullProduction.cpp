#include <iostream>
using namespace std;
string S="ABAC";
string A="aA/^";
string B="bB/^";
string C="c";
string n="";
int nullable(string b)
{
	int i;
	int r=0;
	for (i=0;i<b.length();i++)
	{
	if (b[i]=='^')
		{
		 	r++; 
		}
	}
	if(r==0)
	return 0;
	else 
	return 1;
}
void remove_from_S()
{
	int i=0,j=0,k=0;
	cout<<"S->"<<S<<"/ ";
	int h[S.length()];
	for (i=0;i<S.length();i++)
	{
		h[i]=0; 
	}
	for(j=0;j<n.length();j++)
	{
		for (i=0;i<S.length();i++)
		{
			if(n[j]==S[i])
			{
				h[i]=1;
				for (k=0;k<S.length();k++)
				{
					if(k==i)
					{ 
						continue;
					}
					else
					{ 
						cout<<S[k]; 
					}
				}
			cout<<"/ ";} 
		}
	}
		
	for(i=0;i<S.length();i++)
	{
		if(h[i]==1)
		
{ 
			continue; 
		}
		else
		{
			if(S[i]=='/' or S[i]=='^')
			{ 
				continue;
			}
			else
			{ 
				cout<<S[i]; 
			} 
		}
	}
	cout<<"\n";
}
void remove_from_A()
{
	int i=0,j=0,k=0;
	cout<<"A->";
	for (i=0;i<A.length();i++)
	{
		if(A[i]=='/' or A[i]=='^')
		{ 
			continue;
		}
		else
		{ 
			cout<<A[i]; 
		} 
	}
	cout<<"/ ";
	for(j=0;j<n.length();j++)
	{
		for (i=0;i<A.length();i++)
		{
			if(n[j]==A[i])
			{
				for (k=0;k<A.length();k++)
				{
					if(k==i)
					{ 
						continue; 
					}
					else
					{
						if(A[k]=='/' or A[k]=='^')
						{
						 	continue;
						}
						else
						{ 
							cout<<A[k]; 
						}
					}
				} 
			}
		} 
	}
	cout<<"\n";
}
void remove_from_B()
{
	int i=0,j=0,k=0;
	cout<<"B->";
	for (i=0;i<B.length();i++)
	{
		if(B[i]=='/' or B[i]=='^')
		{ 
			continue;
		}
		else
		{ 
			cout<<B[i]; 
		} 
	}
	cout<<"/ ";
	for(j=0;j<n.length();j++)
	{
		for (i=0;i<B.length();i++)
		{
			if(n[j]==B[i])
			{
				for (k=0;k<B.length();k++)
				{
				if(k==i)
				{ 
					continue; 
				}
				else{if(B[k]=='/' or B[k]=='^'){ continue;}
				else{ cout<<B[k]; 
				}
				}
				}
			}
		}
	}
	cout<<"\n";\
}
void remove_from_C()
{
	int i=0,j=0,k=0;
	cout<<"B->";
	for (i=0;i<C.length();i++)
	{
		if(C[i]=='/' or C[i]=='^'){ continue;}
		else{ cout<<C[i]; } 
	}
	for(j=0;j<n.length();j++)
	{
		for (i=0;i<C.length();i++)
		{
			if(n[j]==C[i]){
			for (k=0;k<C.length();k++)
			{
				if(k==i){ continue;}
				else{if(C[k]=='/' or C[k]=='^'){continue;}
				else{ cout<<C[k]; 
				}
				}
			}
			}
		} 
	}
	cout<<"\n";
}
int main(){
	cout<<"removal of null production\n";
	cout<<"S->"<<S<<"\n";
	cout<<"A->"<<A<<"\n";
	cout<<"B->"<<B<<"\n";
	cout<<"C->"<<C<<"\n";
	cout<<"the nullable products are \n";
	if(nullable(S))
	{
		cout<<"S\t";
		n=n+"S";
	}
	if (nullable(A))
	{ 	cout<<"A\t";
		n=n+"A";
	}
	if (nullable(B))
	{ 	cout<<"B\t";
		n=n+"B";
	}
	if (nullable(C))
	{ 
		cout<<"C\t"; 
		n=n+"C";
	}
	cout<<"\n";
	cout<<"productions after removing the null production\n";
	remove_from_S();
	remove_from_A();
	remove_from_B();
	remove_from_C();
}

