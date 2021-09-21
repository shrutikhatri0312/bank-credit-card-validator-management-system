#include<iostream>
#include<vector>

using namespace std;
class accounts{
    public:
    string name;
    string address;
    long int phn_no;
    int ifsc_code;
    long long int card_num;  
    int balance;
    void printdetails(){
        cout<<"ACCOUNT DETAILS\n";
        cout<<"NAME :\t"<<name;
        cout<<"\nADDRESS :\t"<<address; 
        cout<<"\nPHONE NUMBER :\t"<<phn_no;
        cout<<"\nIFSC_CODE :\t"<<ifsc_code;
        cout<<"\nBALANCE :\t"<<balance;
    }
    int withdraw(){
        int m;
        cout<<"ENTER AMOUNT TO WITHDRAW :\t";
        cin>>m;
        if(m>balance)
            {
                cout<<"--------------------------------------INSUFFICIENT BALANCE--------------------------------------";
                return 0;
            }
        else 
        balance-=m;
        return balance; 
    }
    int deposit(){
        cout<<"ENTER THE AMOUNT TO DEPOSIT :\t";
        int d;
        cin>>d;
        balance+=d;
        return balance;
    }
};

class admin{
    public:
    string username;
    string password; 
    admin(){
        username="shruti";
        password="0312";
    }
    bool loginadmin(){
        string user,pass;
        cout<<"ENTER USERNAME :\t";
        cin>>user;
        cout<<"ENTER PASSWORD :\t";
        cin>>pass;
        if(username==user){
            if(password==pass)
            {
                cout<<"ACCESS GRANTED...........";
                return true;
            }
            else{
                    cout<<"INVALID PASSWORD!!!!!!!!!!!\a\a";
                    return false;
                }
            }
        cout<<"NO SUCH USERNAME!!!!!!!!!!!!\a\a";
        return false;
    }
    void addacc(vector<accounts> a){
        accounts n;
        cout<<"ENTER ACCOUNT DETAILS :\nNAME:\t";
        cin>>n.name;
        cout<<"ADDRESS :\t";
        cin>>n.address;
        cout<<"IFSC CODE :\t";
        cin>>n.ifsc_code;
        cout<<"PHONE NUMBER :\t";
        cin>>n.phn_no;
        cout<<"CARD NUMBER :\t";
        cin>>n.card_num;
        cout<<"BALANCE :\t";
        cin>>n.balance;
        a.push_back(n);
    }
    void search(vector<accounts> a){
        long long int c;
        cout<<"ENTER CARD NUMBER TO SEARCH :\t";
        cin>>c;
        for(int i=0;i<a.size();i++)
        {
            if(a[i].card_num==c)
                {
                    cout<<"--------------------------FOUND-------------------------------\n";
                    a[i].printdetails();
                    return ;
                }
        }
        cout<<"-----------------------NOT FOUND-----------------------------";
    }
    int totalacc(vector<accounts> a){
        return a.size();
    }

    void checkcardvalidity(){
        long long int a,b,c;
        int sum=0,rem,rem1,d,sum1=0,n,i=0;
        cout<<"ENTER CARD NUMBER(16-DIGIT) :\t";
        cin>>c;
        a=b=c;
        while(a>10)
        {
            rem=a%10;
            a=a/10;
            rem1=2*(a%10);
            if(rem1>9)
            {   while(rem1>9)
                {
                    d=rem1%10;
                    rem1=rem1/10;
                    sum1+=d;
                }
                sum1+=rem1;
            }
            else
                sum1=rem1;
            a=a/10;
            sum+=rem+sum1;
        }
        n=sum%10;
        if(n==0)
        {    
            int t;
            while(c>0)
            {
                t=c%10;
                c=c/10;
            }
            if(t==4)
            printf("VISA CARD\n");
            else if(t==5)
                printf("MASTERCARD\n");
                    else if(t==6)
                        printf("AMERICAN EXPRESS CARD\n");
                    else
                        printf("UNIDENTIFIED CARD TYPE\n");
       printf("------------------------THE CARD IS VALID-----------------------------");
       return ;
        }
        else
        printf("---------------------------------------INVALID CARD----------------------------------------\a\a");
        return ;
    }

};


int main(){
    int choice,w;
    admin a;  
    vector<accounts> acc;
    for(int i=0;i<4;i++){//default accounts
        accounts ac;
        ac.name="aabbcc"+i;
        ac.address="xyz block street "+i;
        ac.phn_no=98756+i;
        ac.ifsc_code=1234+i;
        ac.card_num=4111111111111111+i;
        ac.balance=1000+2000*i;
        acc.push_back(ac);
    }
    cout<<"***************************************************************************************************************************\n";
    cout<<"****************************************BANK CREDIT CARD VALIDATION CENTER ************************************************\n";
    cout<<"***************************************************************************************************************************\n\n";
    cout<<"\t\t\t\t\t\tLOGIN PORTAL\n1.ADMIN\n2.CLIENT\n";
    cin>>choice;
    if(choice==1)
        {          
            if(a.loginadmin())
            {
                do{                
                    cout<<"\nENTER WORK TO DO(PRESS 0 TO EXIT) :\n1.ADD ACCOUNT\t2.SEARCH ACCOUNT\t3.TOTAL NUMBER OF ACCOUNT\t4.CHECK CARD VALIDITY\n";
                    cin>>w;
                    switch(w){
                        case 1:{
                            a.addacc(acc);
                            break;
                        }
                        case 2:{
                            a.search(acc);
                            break;
                        }
                        case 3:{
                            cout<<"NUMBER OF ACCOUNTS :\t"<<a.totalacc(acc);
                            break;
                        }
                        case 4:{
                            a.checkcardvalidity();
                            break;
                        }
                        case 0:{
                            break;
                        }
                        default :
                            cout<<"!!!!!!!!!!!!!INVALID INPUT!!!!!!!!!!!\a\a\a" ;
                    }
                }while(w);
            }         
        }

    else if(choice==2){
        string n;
        cout<<"ENTER ACCOUNT HOLDER'S NAME :\t";
        cin>>n;
        int i;
        for(i=0;i<acc.size();i++)
        {
            if(acc[i].name==n)
                break;
        }
        if(i==acc.size())
            return 0;
        do{                
            cout<<"\nENTER WORK TO DO(PRESS 0 TO EXIT) :\n1.DEPOSIT\t2.WITHDRAW\n";
            cin>>w;
            switch(w){
                case 1:{
                    int d=acc[i].deposit();
                        cout<<"TOTAL BALANCE :\t"<<d;
                    break;
                }
                case 2:{
                    int d=acc[i].withdraw();
                    if(d)
                        cout<<"BALANCE LEFT :\t"<<d;
                    break;
                }
                case 0:
                    break;
                default :
                    cout<<"------------------------------------INVALID INPUT------------------------------------";
            }
    }while(w);
   
    
        return 0;
    }
}
