#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main(){
	int a, i=0;
	string text, old, password1, password2, pass, name, password0, age,user, word,word1;
	string cred[2],cp[2];
	
	cout<<"        Security System  "<<endl;
	
	cout<<"__________________________________"<<endl<<endl;
	cout<<"|          1. Register           |"<<endl;
	cout<<"|          2. Login              |"<<endl;
	cout<<"|          3. Change password    |"<<endl;
	cout<<"|__________4. End Program________|"<<endl;
	
	do{
		cout<<endl<<endl;
		cout<<"Select the choice:  ";
		cin>>a;
		switch(a){
			case 1:{
				cout<<"________________"<<endl<<endl;
				cout<<"----Register----"<<endl;
				cout<<"________________"<<endl<<endl;
				cout<<"Please enter the username: ";
				cin>>name;
				cout<<"Please enter the password: ";
				cin>>password0;
				cout<<"Please enter your age: ";
				cin>>age;
				
				ofstream of1;
				of1.open("file.txt");
				if(of1.is_open()){
					of1<<name<<endl;
					of1<<password0;
					cout<<"Registration successful"<<endl;
				}
				break;
			}
			case 2:{
				i=0;
				
				cout<<"________________"<<endl<<endl;
				cout<<"------Login-----"<<endl;
				cout<<"________________"<<endl<<endl;
				
				ifstream of2;
				of2.open("file.txt");
				cout<<"Please enter the username: ";
				cin>>user; 
				cout<<"Please enter the password: ";
				cin>>pass;
				
				if(of2.is_open())
				{
					while(!of2.eof())
					{
						while(getline(of2,text)){
							istringstream iss(text); //used to stream the string using abstraction operator
							iss>>word;
							cred[i]=word;
							i++;
						}
						if(user==cred[0] && pass==cred[1]){
							cout<<"-----Login successful-----";
							cout<<endl<<endl;
							
							cout<<" Details: "<<endl;
							cout<<"Username: "+name<<endl;
							cout<<"Password: "+pass<<endl;
							cout<<"Age: "+age<<endl;
						}
						else{
							cout<<endl<<endl;
							cout<<"Incorrect Credentials"<<endl;
							cout<<"|     	   1. Press 2 to login    		 |"<<endl;
							cout<<"|     2. Press 3 to change password       |"<<endl;
							break;
						}
					}
				}
				break;
			}
			case 3:{
				i=0;
				
				cout<<"__________________________"<<endl<<endl;
				cout<<"------Change password-----"<<endl;
				cout<<"__________________________"<<endl<<endl;
				
				ifstream of0;
				of0.open("file.txt");
				cout<<"Enter the old password: ";
				cin>>old;
				
				if(of0.is_open()){
					while(of0.eof()){
						while(getline(of0,text)){
							istringstream iss(text);
							iss>>word1;
							cp[i]=word1;
							i++;
						}
						if(old==cp[1]){
							of0.close();
							ofstream of1;
							if(of1.is_open()){
								cout<<"Enter your new password: ";
								cin>>password1;
								cout<<"Enter your password again: ";
								cout<<password2;
								if(password1==password2){
									of1<<cp[0]<<endl;
									of1<<password1;
									cout<<"Password changed successfully"<<endl;
								}
								else{
									of1<<cp[0]<<endl;
									of1<<old;
									cout<<"Password do not match"<<endl;
								}
							}
						}
						else{
							cout<<"Please enter a valid password"<<endl;
							break; 
						}
					}
				}
				break;
			}
			case 4:{
				cout<<"__________________________"<<endl<<endl;
				cout<<"------Security System-----"<<endl;
				cout<<"------Thank you-----"<<endl;
				cout<<"__________________________"<<endl<<endl;
				break;
			}
			default:
				cout<<"Enter a valid choice";
				
		}
	}
	while(a!=4);
	return 0;
}
