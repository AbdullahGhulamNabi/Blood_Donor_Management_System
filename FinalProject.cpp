#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct donor{
	string name;
	string id;
	string phone; 
	string address;
	string blood_group;
	string date;
}; 

int enter_data();  
void search();
void update();
void delete_data();
    
	char choice;
    donor d[100];
    
int main(){

	cout<<"\t\t******************* --------------------------------- *******************************\n\n";
	cout<<"\t\t*******************| Blood Donation Management System |******************************\n\n";
	cout<<"\t\t******************* --------------------------------- *******************************\n\n";
while(true){
	
	cout<<"\t\t\tPress A: To   Add a doner's record\n";
	cout<<"\t\t\tPress B: To Search a doner's record\n";
	cout<<"\t\t\tPress C: To Delete a donor's record\n";
	cout<<"\t\t\tPress D: To Update a donor's record\n";
	cout<<endl<<endl;
cout<<"\tYour choice :";	
cin>>choice;	
cout<<endl;
cin.ignore();
system ("cls");
if(choice == 'A' || choice=='a'){
    enter_data();
	cout<<"Do you want to end?(if yes press Y otherwise press N): ";
	cin>>choice;
	if(choice=='y'||choice=='Y'){
		break;
	}
}
    
 if(choice == 'B' || choice== 'b'){
	search();
	cout<<"Do you want to end?(if yes press Y otherwise press N): ";
	cin>>choice;
	if(choice=='y'||choice=='Y'){
		break;
	}	
} 


 if(choice == 'C'|| choice== 'c'){
 	
	delete_data();
	remove("bds_donor_data.txt");

    rename("temp.txt","bds_donor_data.txt");
    cout<<"Data deleted succesfully!"<<endl<<endl;
	cout<<"Do you want to end?(if yes press Y otherwise press N): ";
	cin>>choice;
	if(choice=='y'||choice=='Y'){
		break;
	}

}
	


 if(choice == 'D'|| choice== 'd'){
	update();
	cout<<"Do you want to end?(if yes press Y otherwise press N): ";
	cin>>choice;
	if(choice=='y'||choice=='Y'){
		break;
	}
}

}
return (0);	
}

int enter_data(){
	
	donor d[100];
		int count=0;
	while(true){
	    for(int i=0;i<100;i++){
  	    cout<<"Enter the id of donor  : ";
        getline(cin,d[i].id);
   	    cout<<"\n";
  	    cout<<"Enter the name of donor : ";
  	    getline(cin,d[i].name);
  	    cout<<"\n";
  	    cout<<"Enter the address of donor  : ";
  	    getline(cin,d[i].address);
  	    cout<<"\n";
  	    cout<<"Enter the phone number of donor  : ";
        getline(cin,d[i].phone);
  	    cout<<"\n";
  	    cout<<"Enter the blood group of donor  : ";
  	    getline(cin,d[i].blood_group);
  	    cout<<"\n";
  	    cout<<"Enter the date Donor Visited(DD/MM/YYYY)"<<" : ";
  	    getline(cin,d[i].date);
  	    cout<<"\n";  
  	    
             count++;
         ofstream write;
         write.open("bds_donor_data.txt" ,ios :: app | ios::out);
         write<<d[i].id<<endl<<d[i].name<<endl<<d[i].address<<endl<<d[i].phone<<endl<<d[i].blood_group<<endl<<d[i].date<<endl;
         write.close(); 
         cout<<"If you want to enter more donor press Y otherwise press N :" ;
         cin>>choice; 
		 cout<<endl;	
         cin.ignore();
	        if(choice=='N'|| choice=='n'){	
 	        return 0;
            }
             system("cls");
        }    
    }
		 cout<<"The total number of donor entered are :"<<count<<endl<<endl;	
}

void search(){

 donor d[100];
	bool flag=true;
    ifstream read;
    read.open("bds_donor_data.txt");
    cout<<"Enter the Blood group to be searched:";
    string blood;
    cin>>blood;
    cout<<endl;
    while(read){
        for(int i=0;i<100;i++){     
  	         getline(read,d[i].id);
			 getline(read,d[i].name);
			 getline(read,d[i].address);
			 getline(read,d[i].phone);
			 getline(read,d[i].blood_group);
			 getline(read,d[i].date);
            if (blood==d[i].blood_group){	
             cout<<"ID : "<<d[i].id<<endl<<"Name : "<<d[i].name<<endl<<"Address : "<<d[i].address<<endl<<"Phone No.: "<<d[i].phone<<endl<<"Blood Group: "<<d[i].blood_group<<endl<<"Date: "<<d[i].date;
			 cout<<endl<<endl;
			 flag=false;
	         }  
		}
			 if(flag==true){
			 	cout<<"Donor with required blood group is not present."<<endl<<endl;
			 } 
    }
    cin.ignore();
    read.close();
}

void delete_data(){
	donor d[100];
		ifstream read;
		read.open("bds_donor_data.txt",ios::in);
		ofstream write;
		write.open("temp.txt",ios::app | ios::out);
		
	cout<<"Enter the name of Donor you want to delete the record of:";
	string name;
	getline(cin,name);
	while(read){
	    for(int i=0;i<100;i++){
	    	 getline(read,d[i].id);
			 getline(read,d[i].name);
			 getline(read,d[i].address);
			 getline(read,d[i].phone);
			 getline(read,d[i].blood_group);
			 getline(read,d[i].date);
		    if(name!=d[i].name){
		    	
		  write<<d[i].id;
		  write<<endl;
		  write<<d[i].name;
		  write<<endl;
		  write<<d[i].address;
		  write<<endl;
		  write<<d[i].phone;
		  write<<endl;
		  write<<d[i].blood_group;
		  write<<endl;
		  write<<d[i].date;
		  write<<endl;
		}
	}
  write.close();
  }

}




void update(){

	donor d[100];
	ifstream read;
	read.open("bds_donor_data.txt");
	ofstream write;
	write.open("temp.txt");
	cout<<"Enter the ID of donor whose Data you want to update :";
	string id;
	cin>>id;
	
	int i=0;
  while(read){
			     if(id==d[i].id){
			cout<<"Enter the updated data for donor: "<<endl<<endl;
			      	cout<<"Enter New ID :";
			     	 getline(read,d[i].id);
			     	cout<<"Enter New Name :";
			     	 getline(read,d[i].name);
			     	cout<<"Enter New Address :";
			     	 getline(read,d[i].address);
			     	cout<<"Enter New Phone NO.:";
			     	 getline(read,d[i].phone);
			     	cout<<"Enter New BLood Group :";
			     	 getline(read,d[i].blood_group);
			     	cout<<"Enter New Date :";
			     	 getline(read,d[i].date);
          write<<d[i].id;
		  write<<endl;
		  write<<d[i].name;
		  write<<endl;
		  write<<d[i].address;
		  write<<endl;
		  write<<d[i].phone;
		  write<<endl;
		  write<<d[i].blood_group;
		  write<<endl;
		  write<<d[i].date<<endl;
			     	
			     }
			     	
		else{
             getline(read,d[i].id);
	         getline(read,d[i].name);
             getline(read,d[i].address);
	         getline(read,d[i].phone);
             getline(read,d[i].blood_group);
	         getline(read,d[i].date);
			
			//cin.ignore();
	 	write<<d[i].id;
		  write<<endl;
		  write<<d[i].name;
		  write<<endl;
		  write<<d[i].address;
		  write<<endl;
		  write<<d[i].phone;
		  write<<endl;
		  write<<d[i].blood_group;
		  write<<endl;
		  write<<d[i].date<<endl;	
		
	i++;
		  
		}
    } 	
    remove("bds_donor_data.txt");
    rename("temp.txt","bds_donor_data.txt" );
    
    cout<<"Record has been updated succesfully"<<endl;

}





