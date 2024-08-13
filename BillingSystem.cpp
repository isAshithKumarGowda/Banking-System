#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class shopping{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

    public:
        void menu();
        void administrator();
        void buyer();
        void edit();
        void add();
        void rem();
        void list();
        void receipt();

};

void shopping :: menu(){
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t__________________________________\n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t       Supermarket Main Menu      \n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t__________________________________\n";

    cout<<"\t\t\t\t|   1) Administrator   |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|   2) Buyer           |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|   3) Exit            |\n";
    cout<<"\t\t\t\tPlease select!\n";
    cin >>choice;

    switch (choice){
        case 1:
            cout<<"\t\t\t\tPlease Login \n";
            cout<<"\t\t\t\tEnter email \n";
            cin>>email;
            cout<<"\t\t\t\tPassword \n";
            cin>>password;

            if(email=="ashithkumargowda2005@gmailm.com"&&password=="Hello"){
                administrator();
            }
            else{
                cout<<"Invalid email/password\n";
            }
            break;

        case 2:
            buyer();
            break;
        case 3:
            exit (0);
        default:
            {
                cout<<"Please select from the giben options";
            }
    }
    goto m;
}
void shopping :: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\n\n\nAdministrator menu";
    cout<<"\n\n\t\t\t\t|______1) Add the product______|";
    cout<<"\n\n\t\t\t\t|                              |";
    cout<<"\n\n\t\t\t\t|______2) Modify the product___|";
    cout<<"\n\n\t\t\t\t|                              |";
    cout<<"\n\n\t\t\t\t|______3) Delete the product___|";
    cout<<"\n\n\t\t\t\t|                              |";
    cout<<"\n\n\t\t\t\t|______4) Back to main menu____|";

    cout<<"Please enter your choice\n";
    cin>>choice;

    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"Invalid choice!";
    }
goto m;
}

void shopping::buyer(){
    m:
    int choice;
    cout<<"\t\t\t\t Buyer \n";
    cout<<"                  \n";
    cout<<"\t\t\t\t1) Buy product\n";
    cout<<"                    \n";
    cout<<"\t\t\t\t2) Go back \n";
    cout<<"\t\t\t\t Enter your choice : ";

    cin>>choice;

    switch (choice){
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        case 3:
            cout<<"Invalid choice";
    }
    goto m;
}

void shopping ::add(){
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t\t Add new product";
    cout<<"\n\n\t\tProduct code of the product";
    cin>>pcode;
    cout<<"\n\n\t\tName of the product";
    cin>>pname;
    cout<<"\n\n\t\tPrice of the product";
    cin>>price;
    cout<<"\n\n\t\tDiscount on product";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while(!data.eof()){
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        if(token==1){
            cout<<"Product code exists!";
            goto m;
        }
        else{
            data.open("database.txt",ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }
    }
    cout<<"\n\n\t\tRecord inserted!";
}

void shopping ::edit(){
    fstream data ,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\tModify the record";
    cout<<"\n\n\t\tProduct code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\nFile doesn't exist! ";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pcode>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\n\t\tProduct new code :";
                cin>>c;
                cout<<"\n\n\t\tName of the product :";
                cin>>n;
                cout<<"\n\n\t\tPrice :";
                cin>>p;
                data1<<" "<<c<<" "<<n<<" "<<p <<" "<<d<<"\n";
                cout<<"\n\n\t\tRecord edited";
                token++;    
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\nRecord not found !";
        }
    }
}

void shopping ::rem(){
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t\t\t\tDelete product";
    cout<<"\n\n\t\t\t\tProduct code:";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File dosent exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t\t\t\tProduct deleted successfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n\t\t\t\tRecord not found";
        }
    }
}

void shopping::list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n\t\t\t\t___________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping::receipt(){
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dia=0;
    float total=0;

    cout<<"\n\n\t\t\t\tRECEPT \n";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\nEmpty database";
    }
    else{
        data.close();

        list();
        cout<<"\n_________________________________________\n";
        cout<<"\n                                         \n";
        cout<<"\n          Please place the order         \n";
        cout<<"\n                                         \n";
        cout<<"\n_________________________________________\n";
        do{
            m:
            cout<<"\n\nEnter Product code: ";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quantity: ";
            cin>>arrq[c];
            for(int i=0;i<=c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\n Duplicate product code.Please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\nDo you want to buy another product? if yes press y else n";
            cin>>choice;
        }while(choice=='y'||'Y');

        cout<<"\n\n\t\t\t\t_______________________RECEPT___________________________\n";
        cout<<"\nProduct No\t Product Name\t Product quantity\t Price\t Amount\t Amount after Discount\n";

        for(int i=0;i<=c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
            }
            data>>pcode>>pname>>price>>dis;

            
        }
        data.close();
    }
    cout<<"\n\n_______________________________________________________________";
    cout<<"Total Amount: "<<total;
}
int main(){
    shopping s;
    s.menu();
}