#include<bits/stdc++.h>
using namespace std;


int main(){

    int a, i = 0;
    string text, old, password1,password2,pass,name,password0,age,user,word,word1;

    string creds[2], cp[2];

    cout << " Security System " << endl;

    cout <<"__________________________"<< endl;
    cout<<"|     1.Register          |" << endl;
    cout<<"|     2.Login             |" << endl;
    cout<<"|     3.Change Password   |" << endl;
    cout<<"|_____4.End Program_______|" << endl << endl;


    do{
        cout<< endl<<endl;
        cout<<"Enter your Choice:-";
        cin>>a;

        switch(a)
        {
            case 1:{
                cout<<"________________________" <<endl<<endl;
                cout<<"|--------Register-------|"<<endl;
                cout<<"|_______________________|"<<endl;

                cout<<"Please enter username:-";
                cin>> name;
                cout<< endl;
                cout<<"Please enter the password:-";
                cin>> password0;
                cout<<endl;
                cout<<"Please enter your age:-";
                cin>>age;
                cout<<endl;


                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open()){
                    of1<<name<<"\n";
                    of1<<password0;
                    cout<<"Registration Successful" <<endl;
                }

                break;

            }

            case 2:{
                i = 0;
                cout<<"_______________________"<<endl<<endl;
                cout<<"|-----------Login------|" <<endl;
                cout<<"_______________________|"<<endl<<endl;

                ifstream of2;
                of2.open("file.txt");
                cout<<"Please enter the username:-";
                cin>>user;
                cout<<"Please enter the password:- ";
                cin>>pass;

                if(of2.is_open()){
                    while(!of2.eof()){
                        while(getline(of2,text)){
                            istringstream iss(text);
                            iss>>word;
                            creds[i] = word;
                            i++;
                        }
                        if(user == creds[0] && pass == creds[1]){
                            cout << "-- Login Successful--";
                            cout << endl<< endl;

                            cout<< "Details: " <<endl;
                            cout<<"Username:" + name<<endl;
                            cout<<"Password: "+ pass<<endl;
                            cout<<"Age: "+ age<<endl;
                        }

                        else{
                            cout<<endl<<endl;
                            cout<<"Incorrect Credentials"<<endl;
                            cout<<"| 1.Press Enter to login  |"<<endl;
                            cout<<"|  2. Press 0 to change the password  |"<< endl;

                            break;
                        }
                    }
                }

                break;
            }

            case 3:{

                i = 0;

                cout <<"------Change Password------"<< endl;
                ifstream of0;
                of0.open("file.txt");

                cout << "Please enter the old password:-";
                cin>>old;

                if(of0.is_open()){
                    while(!of0.eof()){
                        while(getline(of0,text)){
                            istringstream iss(text);
                            iss>>word1;
                            cp[i] = word1;
                            i++;
                        }

                        if(old==cp[1]){
                            of0.close();

                            ofstream of1;
                            of1.open("file.txt");
                            if(of1.is_open()){
                                cout << "Enter the new password:-";
                                cin>>password1;
                                cout << "Enter the password again:-";
                                cin>>password2;


                                if(password1 == password2){
                                    of1<<cp[0]<<"\n";
                                    of1<<password1;
                                    cout<<"Password Changed Successfully" <<endl;
                                }

                                else{
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Password do not match" << endl;
                                }
                            }
                            else{
                                cout << "Please Enter a valid Password" << endl;
                                break;
                            }
                        }
                    }
                }

            }

            case 4:
            {
                cout<<"_________Thankyou!__________"<<endl;
                break;
            }

            default: cout<<"Please enter a valid choice";

        }
    }
    while(a!=4);
    return 0;
}
