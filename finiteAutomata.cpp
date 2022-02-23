#include<iostream>
#include<string>
using namespace std;
int main()
{	int flg=0;
	string ST;
		cout<<"RE=(a+b)*bab\n";
	cout<<"\nEnter a pattern:- ";
	cin>>ST;
	int len=ST.length();
		for(int i=0;i<len-3;i++)
	{	cout<<"Input- "<<ST[i]<<"--> State 1 (start)"<<endl;
		if(ST[i]!='a'&& ST[i]!='b')
		{	cout<<"NOT IN LANGUAGE (Reason- invalid character)\n";
			flg=1;
			break;
		}
	}
	if(flg!=1)
	{
		if(ST[len-3]=='b'&&ST[len-2]=='a'&&ST[len-1]=='b')
		{	cout<<"Input- b--> State 2"<<endl;
			cout<<"Input- a--> State 3"<<endl;
			cout<<"Input- b--> State 4 (accepting)"<<endl;				
			cout<<endl<<"String accepted by language";
		}
		else		
			cout<<"NOT IN LANGUAGE (Reason- doesn't end with bab)";	
	}		
	return 0;	
}
