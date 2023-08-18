
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include<map>
#include<conio.h>

using namespace std;

class info {
private:
    string cname, aboutus, oname;
    long double money, n;

public:
    friend class products;

    void companyinfo() {
        cout << "============================================================================================================" << endl;
        cout<<"                                   INDUSTRY MANAGEMENT SYSTEM"<<endl;
        cout << "============================================================================================================" << endl<<endl;
        cout << "                                |  Company Name: ";

        getline(cin,cname);


        cout << "                                |  Owner Name: ";


         getline(cin,oname);


        cout << "                                |  Invested Money(in BDT): ";
        cin >> money;
        cout << "                                |  About us: ";
        cin.ignore();
        getline(cin, aboutus);

        cout << "Press 1 to get a license" << endl<<endl;
        cin >> n;

        if (n == 1) {
            cout << "============================================================================================================" << endl;
            cout << "                   Bangladesh Business Association" << endl << endl;
            cout << "   The company named \"" << cname<< "\" is provided with a license to conduct all dealings and business" << endl
                 << "   inside and outside of the country." << endl << endl << endl
                 << oname << "                                                                        " << "Abdul kalam" << endl
                 << "Signature of Owner" << "                                              " << "               Signature of business minister" << endl;
            cout << "=============================================================================================================" << endl;
        }
    }
};

class products {
private:
    string pname, raw;
   long double price, n, quantity, c,sum=0;
vector<string>p;

public:
    friend class factory;
    friend class sell;

    void product(info &t) {


        cout << "                                |  Product Name: ";
        cin >> pname;
        p.push_back(pname);
        cout << "                                |  Number of raw materials: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << endl << "                                |  Name of raw material no. " << i + 1 << ": ";
            cin.ignore();
            getline(cin, raw);

            cout << "                                |  Quantity of raw materials: ";
            cin >> quantity;

            cout << "                                |  Unit" << endl << "                                   1. Kg" << endl << "                                   2. Gram" << endl << "                                   3. Litre" << endl;
            cin >> c;
            if (c == 2) {
                quantity /= 1000;
            }

            cout << "                                |  Price of raw material no. " << i + 1 << " (Per kg/gram/litre in BDT): ";
            cin >> price;

            sum += price * quantity;
        }
        t.money -= sum;
        if(t.money<0)
            {cout<<"                                Not enough invested money remained"<<endl;
        exit(0);}
    }
};

class factory {
  long long  int t,num ;


    double elec ;

public:
    friend class sell;
void number()
{
    cout<<"                                |  How many pieces you want to produce : ";
    cin>>num;
}


    void machine() {
       cout<<"Machine 1 : ";
            for(int i=0;i<=80;i++)
            {
                cout<<"|";
                Sleep(5);
            }
            cout<<endl<<endl;
cout<<"Machine 2 : ";
            for(int i=0;i<=80;i++)
            {
                cout<<"|";
                Sleep(5);

                }

                  cout<<endl<<endl;
cout<<"Machine 3 : ";
            for(int i=0;i<=80;i++)
            {
                cout<<"|";
                Sleep(5);

                }

                  cout<<endl<<endl;
cout<<"Machine 4 : ";
            for(int i=0;i<=80;i++)
            {
                cout<<"|";
                Sleep(5);

                }

                  cout<<endl<<endl;
cout<<"Machine 5 : ";
            for(int i=0;i<=80;i++)
            {
                cout<<"|";
                Sleep(5);

                }

             cout<<endl<<endl;
             cout<<"Packaging : ";
                  for(int i=0;i<=80;i++)
            {
                cout<<"|";
                Sleep(5);

                }


               elec=10.117*num;

        }


    void status(products &q) {
      cout<<endl<<"                                   Production complete "<<endl<<"                                   Tap 1 to see production status"<<endl;
    cin>>t;
    if(t==1)
    {
cout << "============================================================================================================" << endl;

        cout<<"                                       Name of Product : "<<q.pname<<endl;
    cout<<"                                       Number of production : "<<num<<" pieces "<<q.pname<<endl;
       cout<<"                                       Electricity used : "<<elec<<" Units"<<endl;
       cout<<"                                       Electricity cost : "<<elec*10<<" BDT"<<endl;
       cout<<"                                       Production cost : "<<q.sum*num<<" BDT"<<endl;
       cout<<"                                       Total cost : "<<elec*10+q.sum*num<<" BDT"<<endl;  ;

    }}
};

class employee {
private:
    vector<string>name;
    vector<string>id;
    vector<string>contact;
    vector<string>post;
    map<string, int> salaryByPost;
    map<string,string>performanceRating;

 int j,day;
public:
    void data() {
    string ename;
    string eid;
    string econtact;
    string epost;

    while(1)
        {cout << "                                |  Employee name: ";
       getline(cin, ename);
       getline(cin, ename);
        name.push_back(ename);

        cout << "                                |  Employee id: ";
        getline(cin, eid);
        id.push_back(eid);

        cout << "                                |  Post: ";
        getline(cin, epost);
        post.push_back(epost);

        cout << "                                |  Contact: ";
        getline(cin, econtact);
        contact.push_back(econtact);

        cout << endl<<"                                   Do you want to add more employees (y/n)? ";
        char ch;
        cin >> ch;

        if (ch == 'n')
            break;

        }
}

void display() {
    cout << "                                |  Showing all Employee data  |" << endl << endl;
    for (int i = 0; i < name.size(); i++) {
        cout << "============================================================================================================" << endl;
        cout << "                                |  Employee name: " << name[i] << endl;
        cout << "                                |  Employee id: " << id[i] << endl;
        cout << "                                |  Post: " << post[i] << endl;
         cout << "                                |  Salary (Per month): " << salaryByPost[post[i]] << " BDT" << endl;
        cout << "                                |  Contact: " << contact[i] << endl;
        cout<<"                                |  Performance Rating : "<<performanceRating[id[i]] <<endl;
  cout << "============================================================================================================" << endl;
    }
}

void removeEmployeeById() {
    string empId;
    cout << "                                   Enter the ID of the employee you want to remove: ";
    cin.ignore();
    getline(cin, empId);

    bool found = false;
    for (size_t i = 0; i < id.size(); i++) {
        if (id[i] == empId) {
            found = true;
            name.erase(name.begin() + i);
            id.erase(id.begin() + i);
            post.erase(post.begin() + i);
            contact.erase(contact.begin() + i);
            cout << "                                   Employee with ID: " << empId << " has been removed successfully." << endl;
            break;
        }
    }

    if (!found) {
        cout <<endl<< "                                   Employee with ID: " << empId << " not found." << endl;
    }
}
void setSalaryByPost() {
        string epost;
        int salary;

        cout << "                                |  Enter the post for which you want to set the salary: ";
        cin.ignore();
        getline(cin, epost);

        cout << "                                |  Enter the salary for " << epost <<"(in BDT) : ";
        cin >> salary;
cout<<"                                   Salary set successful"<<endl;
        salaryByPost[epost] = salary;
    }
    void addPerformanceRatingById() {
        cout << "Enter the Employee ID to add performance rating: ";
        string empId;
        cin.ignore();
        getline(cin, empId);

        bool found = false;
        for (size_t i = 0; i < id.size(); i++) {
            if (id[i] == empId) {
                found = true;
                cout << "Enter the performance rating for " << name[i] << " (Press * for each star): ";
                string rating;
                cin>>rating;
               performanceRating[empId] = rating;
                cout << "Performance rating added for Employee with ID: " << empId << endl;
                break;
            }
        }
        if (!found) {
            cout << "Employee with ID: " << empId << " not found." << endl;
        }
    }
};
    class sell
    {long  double l,k,taka,u=0,h=0,y=0;double x=0;int j;
public:
friend class report;

int getj()
{
    j=1;
    return j;
}
    void show(products &t,factory &e)
    {
        cout <<"***********************************SELLING SECTION*****************************"<<endl<<endl;

    for(int i=0;i<t.p.size();i++)
        {

cout <<"                                    Product number : "<<"[ "<<j<<" ]"<<endl<<endl;
  cout << "============================================================================================================" << endl;
        cout<<"            Product name : "<<t.p[i];
        cout<<"                          Stock available : "<<e.num<<" Pieces"<<endl;

          cout << "============================================================================================================" << endl;
        }
        cout<<"                         Press 1 to sell this product or 0 to skip selling"<<endl;
        cin>>l;

if(l==0)
{

    e.elec=0;
   taka=0;
k=0;

    goto m1;

}


        if(l==1)
        {
            cout<<"                                   Number of sell products: "<<endl;
            cin>>k;

            if(k>e.num)
            {
                cout<<"Excess of stock"<<endl;
                exit(0);
            }
            e.num-=k;
            u+=k;
            cout<<"                                   Set the selling price (Per piece in BDT ) : "<<endl;
            cin>>taka;
m1:
              cout << "============================================================================================================" << endl;
            cout<<"                                   SELLING REPORT OF PRODUCT NO. : "<<"[ "<<j<<" ]"<<endl<<endl;
            cout<<"                                   Total selling price : "<<k*taka<<" BDT"<<endl<<endl;
            h+=k*taka;
cout<<"                                   Production cost :"<<e.elec*10+(t.sum*k)<<" BDT"<<endl<<endl;
x+=e.elec*10+(t.sum*k);
cout<<"                                   Profit : "<<k*taka-(e.elec*10+(t.sum*k))<<" BDT"<<endl;
  cout << "============================================================================================================" << endl;
y+=k*taka-(e.elec*10+(t.sum*k));
j++;
        }

         else return;

    }
};

class report
{ long double res,per;
public:
    friend class sell;
    void reportshow(sell &g)
    {cout<<endl<<endl<<endl<<endl;
         cout << "                           ==============================================" << endl;
        cout << "                                            SALES REPORT                " << endl;
        cout << "                           ==============================================" << endl<<endl;
        cout<<"                           Total sold products : "<<g.u<<" Pieces"<<endl;
        cout<<"                           Total cost : "<<g.x<<" BDT"<<endl;
        cout<<"                           Total Income : "<<g.h<<" BDT"<<endl;
        cout<<"                           Total profit : "<<g.y<<" BDT"<<endl;
        res=(g.h-g.x)/g.h;
        per=res*100;
        if(g.u==0)per=0;
        cout<<"                           Percentage of profit: "<<per<<"%"<<endl;
    }
};




int main() {
  long long   int  m, v,i=0;


    info a;
    vector<products>b;
   vector< factory> c;
    employee d;
        sell s;
    report r;




        a.companyinfo();
        l3:
        cout << "                                   1. Production" << endl << "                                   2. Employee management" <<endl<<"                                   3. Sell products"<< endl;
        cin >> v;

        if (v == 1) {

            products bb;
            bb.product(a);
            factory cc;

                        b.push_back(bb);

            cout << "                                   Press 1 to go to the factory section" << endl;
            cin >> m;
            if (m == 1) {
                cc.number();
                system("cls");

                int x;
                cout << "                                   Press 1 to start all machines" << endl;
                cin >> x;
                if (x == 1) {
                    system("cls");
                    cout << "                                |  Machines are running  |" << endl<<endl;
                Level:
                    cc.machine();
                }
                 for (;i<b.size();i++)
                cc.status(b[i]);
                c.push_back(cc);
                cout <<endl<< "                                   Press 0 to go to management section" << endl;
                int t;
                cin >> t;

                    if(t==0)
                    goto l3;

            }
        }

        l2:
        if (v == 2) {
            int b;
            cout << "                                   1. Show all employee data" << endl << "                                   2. Add employee" << endl << "                                   3. Remove employee" << endl << "                                   4. Set salary" << endl
                 <<"                                   5. Add performance rating"<< endl;
            cin >> b;
            if (b == 2) {
                d.data();
                goto l2;
            }
if(b==1)
{
    d.display();
    goto l2;

}
if(b==3)
{
    d.removeEmployeeById();

    goto l2;

}
if (b == 4) {
                d.setSalaryByPost();
                goto l2;
            }
           if(b==5)
            {d.addPerformanceRatingById();
            goto l2;}


        }

        if(v==3)
        { s.getj();
        for (int i=0;i<b.size();i++)
          s.show(b[i],c[i]);
          for(int i=0;i<4;i++)
          {
              Sleep(1000);
          }
          system("cls");

    cout<<endl<<endl<<endl;

    cout<<"                                                LOADING SELLING REPORT";

    for(int i=0;i<4;i++ )
    {
       cout<<".";
            Sleep(1000);
    }
    system("cls");

r.reportshow(s);
char ch;
cout<<endl<<endl<<"                                                Press space bar to go back"<<endl;
ch=_getch();
if(ch==' ')
    goto l3;

         }
         getch();
    return 0;
}




