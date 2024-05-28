#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
 class Student{
     int admmno;
     char name[50];
     char gender;
     int std;
     float marks;
     float percentage;
  public:
     void getdata();
     void showdata();
    int getadmno(){return admmno;}
}s;
void Student::getdata(){
    cout<<"\n\nEnter Student Details....\n";
    cout<<"Enter Admission No. : "; cin>>admmno;
    cout<<"Enter Full Name : "; cin.ignore(); cin.getline(name,50);
    cout<<"Enter Gender(M/F) : "; cin>>gender;
    cout<<"Enter Standard : "; cin>>std;
    cout<<"Enter Total Marks(OUT OF 500) : "; cin>>marks;
    cout<<endl;
    percentage=(marks/500)*100;
}
void Student::showdata(){
    cout<<"\n\n.......Student Details......\n";
    cout<<"Admission No. : "<<admmno<<endl;
    cout<<"Full Name : "<<name<<endl;
    cout<<"Gender : "<<gender<<endl;
    cout<<"Standard : "<<std<<endl;
    cout<<"Total Marks : "<<marks<<endl;
    cout<<"Percentage : "<<percentage<<endl;
    cout<<endl;
}
void addData(){
   char ch;
   ofstream fout;
    fout.open("student.dat",ios::binary|ios::out|ios::app);
    s.getdata();
    fout.write((char*)&s,sizeof(s));
    cin.get(ch);
    fout.close();
    cout<<"\n\nData Successfully Saved to File ....\n";

}
void displayData(){
    ifstream fin;
    fin.open("student.dat",ios::in|ios::binary);
    while(fin.read((char*)&s,sizeof(s))){
        s.showdata();
    }
    fin.close();
    cout<<"\n\nData Reading from File Sucessfully Done....\n";
}
void searchData(){
    int n, flag=0;
    ifstream fin;
    fin.open("student.dat",ios::in|ios::binary);
    cout<<"Enter Admission Number you want to search : ";
    cin>>n;
    while(fin.read((char*)&s,sizeof(s))){
        if(n==s.getadmno()){
            cout<<"The Details of Admission No. "<<n<<" shown herewith:\n";
            s.showdata();
            flag++;
        }
    }
    fin.close();
    if(flag==0)
        cout<<"The Admission No. "<<n<<" not found....\n\n";
        cout<<"\n\nData Reading from File Sucessfully Done...\n";
}
void deleteData(){
    int n, flag=0;
    ifstream fin;
    ofstream fout,tout;
    fin.open("student.dat",ios::in|ios::binary);
    fout.open("temp.dat",ios::out|ios::app|ios::binary);
    tout.open("trash.dat",ios::out|ios::app|ios::binary);
    cout<<"Enter Admission Number you want to delete : ";
    cin>>n;
    while(fin.read((char*)&s,sizeof(s))){
        if(n==s.getadmno()){
            cout<<"The Admission No. "<<n<<" has been deleted....\n";
            s.showdata();
            tout.write((char*)&s,sizeof(s));
            flag++;
        }
        else{
            fout.write((char*)&s,sizeof(s));
        }
    }
    fin.close();
    fout.close();
    tout.close();
    if(flag==0)
        cout<<"The Admission No. "<<n<<" not found....\n\n";
    remove("student.dat");
    rename("temp.dat","student.dat");
    cout<<"\n\nData Successfully Deleted from File....\n";
}
void getTrash(){
    ifstream fin;
    fin.open("trash.dat",ios::in|ios::binary);
    while(fin.read((char*)&s,sizeof(s))){
        s.showdata();
    }
    fin.close();
    cout<<"\n\nData Reading from Trash File Sucessfully Done....\n";
}
void modifyData(){
    int n, flag=0, pos;
    fstream fio;
    fio.open("student.dat",ios::in|ios::out|ios::binary);
    cout<<"Enter Admission Number you want to Modify : ";
    cin>>n;
    while (fio.read((char*)&s,sizeof(s)))
    {
         pos=fio.tellg();
        if(n==s.getadmno()){
            cout<<"The Admission No. "<<n<<" will be modified....\n";
            s.showdata();
            cout<<"\n\nNow Enter the New Details....\n";
            s.getdata();
            fio.seekg(pos-sizeof(s));
            fio.write((char*)&s,sizeof(s));
            flag++;
        }
    }
    fio.close();
    if(flag==0)
        cout<<"The Admission No. "<<n<<" not found....\n\n";
    cout<<"\n\nData Successfully Modified in File....\n";
}
void studentManagement()
{
    int ch;
    do{
        system("clear");
        cout<<"   ............STUDENT MANAGEMENT SYSTEM.............\n";
        cout<<"=========================================================\n";
        cout<<"0. Exit from Student Management System\n";
        cout<<"1. Add Data to File\n";
        cout<<"2. Read Data from File\n";
        cout<<"3. Search Data from File\n";
        cout<<"4. Delete Data from File\n";
        cout<<"5. Get Deleted Records from Trash File\n";
        cout<<"6. Modify Data in File\n";
        cout<<"=========================================================\n";
        cout<<"Enter your Choice : ";
        cin>>ch;
        system("clear");
        switch(ch){
            case 0:
                cout<<"Exiting from Student Management System....\n";
                break;
            case 1:
                addData();
                break;
            case 2:
                displayData();
                break;
            case 3:
                searchData();
                break;
            case 4:
                deleteData();
                break;
            case 5:
                getTrash();
                break;
            case 6:
                modifyData();
                break;
            default:
                cout<<"Invalid choice....\n";
                break;
        }
        system("read");
    }while (ch);
}
int main()
{
    studentManagement();
    return 0;
}
    
    