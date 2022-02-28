#include <iostream>
#include <fstream>
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
        void add();
        void edit();
        void rem();
        void recipt();
        void list();

};

void shopping :: menu(){
    menu_jump:
    int m_choice ;
    string usrnm;
    string pass;

    cout<<"\n\n\t\t____________________________________________\n";
    cout<<"\n\n\t\t           welcome to the mall              \n";
    cout<<"\n\n\t\t____________________________________________\n";
    cout<<"\n\t\t1) ADMINISTRATOR     \n\n";
    cout<<"\n\t\t2) BUYER             \n\n";
    cout<<"\n\t\t3) EXIT              \n\n";
    cout<<"\n\t\t please select your choice : ";
    cin>>m_choice;

    switch (m_choice)
    {
    case 1:
        cout<<"\tplease enter your email and pass : \n";
        cout<<"\tenter user email : ";
        cin>>usrnm;
        cout<<"\n\tenter pass : ";
        cin>>pass;
        if (usrnm == "aniket@gmail.com" && pass == "1234")
        {
            administrator();
        }
        else
        {
            cout<<"\t\tyour email and pass does'nt match \n";
        }
        break;
    case 2:
        buyer();
    
    case 3:
        exit(0);
    default:
        cout<<"\t\tplease select from given choices \n";
        break;
    }
    goto menu_jump;
}

void shopping :: administrator(){
    admin_jump:
    int ad_choice;
    cout<<"\n\n\t\t_____ADMINISTRATOR MENU_____\n";
    cout<<"\n\t\t1)      add a product       \n";
    cout<<"\n\t\t2)     modify a product     \n";
    cout<<"\n\t\t3)     remove a product     \n";
    cout<<"\n\t\t4)     back to main menu    \n";
    cout<<"\n\t\t enter your choice : ";
    cin>>ad_choice;
    switch (ad_choice)
    {
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
            cout<<"\n\n\t\tplease select from above only\n";
            break;
    }
    goto admin_jump;
}
void shopping :: buyer(){
    buyer_jump:
    int buy_choice;
    cout<<"\n\n\t\t________BUYER________";
    cout<<"\n\n\t\t1)   buy a prouct    ";
    cout<<"\n\n\t\t2) go back to menu   ";
    cout<<"\n\n\tenter your choice : ";
    cin>>buy_choice;

    switch (buy_choice)
    {
    case 1:
        recipt();
        break;
    
    case 2:
        menu();
        break;
    
    default:
        cout<<"\n\t\t please select from above choices \n";
        break;
    }

    goto buyer_jump;
}

void shopping :: add(){
    add_jump:
    int c, token = 0;
    float p, d;
    fstream data ;
    string n;
    cout<<"\n\t\t add new product  \n";
    cout<<"\n\t\t enter the product code : ";
    cin>>pcode;
    cout<<"\n\t\tenter product name : ";
    cin>>pname;
    cout<<"\n\t\t enter the price : ";
    cin>>price;
    cout<<"\n\t\t enter the discount : ";
    cin>>dis;

    data.open("records.txt", ios::in);
    if (!data)
    {
        data.open("records.txt" , ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while (!data.eof())
        {
            if (c == pcode)
            {
                token++ ;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

        if (token == 1)
        {
            cout<<"\n\t\tplease use other product code \n";
            goto add_jump;
        }
        else
        {
            data.open("records.txt", ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n";
            data.close();
        }
        
    }
    cout<<"\n\t\tproduct is added successfully \n";
    
}

void shopping :: edit(){
    int c, pkey, token = 0;
    float p, d;
    string n;
    fstream data, data1;

    cout<<"\n\t\t modifying the record \n";
    cout<<"\n\t\t enter the product code ";
    cin>>pkey;

    data.open("records.txt", ios::in);
    if (!data)
    {
        cout<<"\n\t\tthe records does'nt exist !\n";
    }
    else
    {
        data1.open("records1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;

        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout<<"\n\tenter the product code : ";
                cin>>c;
                cout<<"\n\tenter product name : ";
                cin>>n;
                cout<<"\n\tenter price : ";
                cin>>p;
                cout<<"\n\tenter discount : ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<" \n";
                token++;
                cout<<"\n\trecord modifyied \n";
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("records.txt");
        rename("records1.txt", "records.txt");

        if (token == 0)
        {
            cout<<"\n\t\tdata not present in records \n";
        }
        
    }
    
}

void shopping :: rem(){
    int pkey, c, token = 0;
    float p, d;
    string n;
    fstream data , data1;

    cout<<"\n\t\t   removing product    \n";
    cout<<"\n\t\tenter the product code : ";
    cin>>pkey;
    data.open("records.txt", ios::in);
    if (!data)
    {
        cout<<"the record does'nt exist \n";
    }
    else
    {
        data1.open("records1.txt", ios::app|ios::app);
        data>>pcode>>pname>>price>>dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout<<"\n\t\tthe product is successfully deleted \n";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("records.txt");
        rename("records1.txt", "records.txt");

        if (token==0)
        {
            cout<<"\n\t\tdata not present in records \n";
        }
        
    }
    
}

void shopping :: list(){
    fstream data;
    data.open("records.txt", ios::in);
    cout<<"\n\t\t_________________________________________\n";
    cout<<"\n\t\t            list of items                \n";
    cout<<"\n\t\t_________________________________________\n";
    cout<<"\n\t\tproductNo\tproductName\tprice\n";
    cout<<"\n\t\t_________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while (!data.eof())
    {
        cout<<"\n\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
    
}


void shopping :: recipt(){

    recipt_jump:

    fstream data;

    int arrc[100];
    int arrq[100];
    int c= 0;
    float ammount = 0;
    float discount = 0;
    float total = 0;
    char choice ;

    data.open("records.txt", ios::in);
    cout<<"\n\n\t\t\t\t RECIPT  \n";
    if (!data)
    {
        cout<<"\n\t\tfile does'nt exist !\n";
    }
    else
    {
        data.close();

        list();
        cout<<"\n\t\t_____________________________________\n";
        cout<<"\n\t\t    select the products you need     \n";
        cout<<"\n\t\t_____________________________________\n";
        do
        {
            cout<<"\n\t\tenter the code of the product ";
            cin>>arrc[c];
            cout<<"\n\t\tenter the product quantity ";
            cin>>arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout<<"\n\t\tduplicate product code please try again \n";
                    goto recipt_jump;
                }
            }
            c++;
            cout<<"\n\t\tdo you want to select another product ? y/n :";
            cin>>choice;
        } while (choice == 'y');
        

        cout<<"\n\t\t______________________RECIPT______________________\n";
        cout<<"\nproductCode\tproductName\tquantity\tprice\tammount\tammountWithDis\n";

        for (int i = 0; i < c; i++)
        {
            data.open("records.txt", ios::in);
            data>>pcode>>pname>>price>>dis;
            while (!data.eof())
            {
                if (pcode==arrc[i])
                {
                    ammount = price * arrq[i];
                    discount = ammount - (ammount*dis/100);
                    total += discount;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<ammount<<"\t\t"<<discount<<"\n";
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
        }
        

    }
    cout<<"\n\n\t\t____________________________________________\n";
    cout<<"\n\n\t\t total  :  "<<total<<"\t\n"; 
}

int main(){
    //create an object of your class and use it here
    shopping a;
    a.menu(); 
    return 0;
}   


