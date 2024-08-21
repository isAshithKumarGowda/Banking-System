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
    cout<<"\t\t\t\tPlease select: ";
    cin >>choice;
    cout<<endl;

    switch (choice){
        case 1:
            cout<<"\t\t\t\tPlease Login \n";
            cout<<"\t\t\t\tEnter email \n";
            cin>>email;
            cout<<"\t\t\t\tPassword \n";
            cin>>password;

            if(email=="ashithkumargowda2005@gmail.com"&&password=="Hello"){
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
    cout<<"\n\n\t\t\t\t|______4) Back to main menu____|\n";

    cout<<"\t\t\t\tPlease enter your choice: ";
    cin>>choice;
    cout<<endl;
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
            exit (0);
        case 2:
            menu();
            break;
        default :
            cout<<"Invalid choice";
    }
    goto m;
}
void shopping ::add(){

    m:
    fstream data;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t\t Add new product";
    cout<<"\n\n\t\tProduct code of the product: ";
    cin>>pcode;
    cout<<"\n\n\t\tName of the product: ";
    cin>>pname;
    cout<<"\n\n\t\tPrice of the product: ";
    cin>>price;
    cout<<"\n\n\t\tDiscount on product: ";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        int token=0;

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
void shopping::edit() {
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\n\t\tModify the record";
    cout << "\n\n\t\tProduct code :";
    cin >> pkey;
    
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\nFile doesn't exist!";
    } 
    else {
        data1.open("database1.txt", ios::app);
        
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\n\n\t\tProduct new code :";
                cin >> c;
                cout << "\n\n\t\tName of the product :";
                cin >> n;
                cout << "\n\n\t\tPrice :";
                cin >> p;
                cout << "\n\n\t\tDiscount :";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\tRecord edited";
                token++;
            } 
            else {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis; // Read the next record
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0) {
            cout << "\n\nRecord not found!";
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
    cout<<"\t\t\t\tProNo\t\tName\t\tPrice\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<"\t\t\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
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

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\nEmpty database";
    }
    else{
        data.close();

        list();
        cout<<"\n\t\t\t\t_________________________________________\n";
        cout<<"\n                                         \n";
        cout<<"\n\t\t\t\t          Please place the order         \n";
        cout<<"\n                                         \n";
        cout<<"\n\t\t\t\t_________________________________________\n";
        do{
            m:
            cout<<"\n\n\t\t\t\tEnter Product code: ";
            cin>>arrc[c];
            cout<<"\n\n\t\t\t\tEnter the product quantity: ";
            cin>>arrq[c];
            c++;
            cout<<"\n\n\t\t\t\tDo you want to buy another product? if yes press y else n : ";
            cin>>choice;
        }while(choice=='y');

        cout<<"\n\n\t\t___________________________________________RECEPT_______________________________________________\n";
        cout<<"\n\t\tProduct code\t Product Name\t Product quantity\t Price\t Amount\t Amount after Discount\n";
        for(int i=0;i<c;i++){
        data.open("database.txt",ios::in);
        int proDis;
        // for(int i=0;i<c;i++){
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    proDis=amount-(amount*dis/100);
                    total=total+proDis;
                    cout<<"\n\t\t"<<pcode<<"\t\t "<<pname<<"\t "<<arrq[i]<<"\t\t\t "<<price<<"\t "<<amount<<"\t "<<proDis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        // }
        data.close();
    }
    cout<<"\n\n\t\t________________________________________________________________________________________________";
    cout<<"\n\n\t\tTotal Amount: "<<total;
}
}
int main(){
    shopping s;
    s.menu();
}
