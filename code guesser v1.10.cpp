// Color 4 is red , color 2 is green

#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void println(){
	cout<<"----------------------------------"<<endl;
}

void gameDesign(){
	println(); 
	cout<<"|          Code Guesser          |"<<endl;
	println();
}

void score(){
	println(); 
	cout<<"|             Score              |"<<endl;
	println();
}
int main(){
	system("color f");
	char name[2][30];
	int turns[2];
	int points[2] = {0};
	int count = 0;
	int choice;
	gameDesign();
	cout<<" Player 1 \n input your name : ";
	cin.getline(name[0],30);
	cout<<" Player 2 \n input your name : ";
	cin.getline(name[1],30);
	system("pause");
	system("cls");
	
	cout<<" Rules "<<endl
		<<" 1. Green color means it's user's turn to input"<<endl
		<<" 2. Red   color means it's user's turn to guess"<<endl
		<<" 3. One player enters a secret code, the other player isn't allowed to see the code"<<endl<<" ";
		system("pause");
		system("cls");	
	
	do{
		gameDesign();
		cout<<"1. Play"<<endl
			<<"2. Show score"<<endl
			<<"3. Exit"<<endl
			<<"Choice : ";
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:
					fflush(stdin);
					for(int i=0;i<2;i++){
					UP:
					system("cls");
					gameDesign();	
					int a1;
					int code;
					
					
					int guess;
					system("color 2");
					if(count%2 == 0){
						cout<<name[0]<<" Enter a secret code : ";
					}else{
						cout<<name[1]<<" Enter a secret code : ";	
					}
					
					cin>>code;
					
	//	a1 = atoi(code);
	//  cout<<endl<<a1<<endl;
					if(code>999 || code<0){
						cout<<"Error input a code between 0 and 999 "<<endl;
						
						goto UP;
					}
					else{
							
						system("pause");
						system("cls");
						system("color 4");
				
					int turn = 0;
					int j;
					do{
						UP1:
							
							gameDesign();
						j=0;
						if(count%2 != 0){
							cout<<name[0]<<" Guess the secret code : "<<endl<<"Enter -1 to abort : ";
						
						}else{
							cout<<name[1]<<" Guess the secret code : "<<endl<<"Enter -1 to abort : ";	
						}
						
						cin>>guess;
						
						if(guess>999 || guess<-1){
						cout<<"Error input a code between 0 and 999 "<<endl;
						system("color 4");
						
						//cout<<endl<<endl<<code<<"BRUH"<<endl<<code1<<endl;
						goto UP1;
					}
						
						if(guess==-1){
							cout<<"The secret code : "<<code<<endl;
						//	(count%2 != 0)? points[0]++:points[1]++;
						turn = 99999;
						//	turns[0] =turns[1] =0; 
						//	count++;
							j=3;
							goto endOfWhile;
						}
					/*	if(guess == code[0]){
							j++;
						}
						if(guess[1] == code[1]){
							j++;
						}
						if(guess[2] == code[2]){
							j++;
						}*/
						
						if(code == guess){
							j=3;
						}
						else
						{
							int c,g;
							c = code;
							g = guess;
							int c1,g1;
							
							for(int i=0;i<3;i++){
							c1 = c%10;
							g1 = g%10;
							if(c1 == g1){
								j++;
							}
							c /= 10;
							g /= 10;
							}
							
						}
							
						
						turn++;
						endOfWhile:
						(turn>=99999)? cout<<"": cout<<"Correct digits : "<<j<<endl
							<<"No of turns    : "<<turn<<endl;
					
					}
					while( j != 3/*strcmp(code,guess) != 0*/);					
				
						if(count%2 != 0){
						turns[0] = turn;
					}else{
						turns[1] = turn; 
					}
					
					cout<<" ";	
					}
					
						
					count++;	
					system("pause");
				system("color f");
				   system("cls");
				}
				if(turns[0] == turns[1]){
					cout<<"Draw! No one gets a point!"<<endl;
					system("pause");
					system("cls");
				}else{
						
					if(turns[0]<turns[1]){
						points[0]++;
					}
					else{
						points[1]++;
					}
				}
					
				   break;
				   
			case 2:
				score();
				cout<<endl<<"|             "<<points[0]<<" : "<<points[1]<<"              |"<<endl<<endl;
				println();			
				system("pause");
				system("cls");	
				   break; 
			case 3:
				score();
				if(points[0]==points[1]){
					cout<<"Draw"<<endl;
				}
				else{
					(points[0]>points[1])?cout<<name[0]<<" "<<"wins with a lead of "<<points[0]-points[1]<<" points":cout<<name[1]<<" wins with a lead of "<<points[1]-points[0]<<" points";
				cout<<endl;	
				}
				   break;
			default:
					cout<<"Error! Please choose one of the above options"<<endl;
					system("pause");
					system("cls");
					break;	   				
		}	
	}
	while(choice != 3);
	
return 0;
}
