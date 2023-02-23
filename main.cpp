#include <bits/stdc++.h>
using namespace std;

// unordered_map<string,string> admin;
struct p
{
    int p_id;
    float price;
    float amount;
    string p_name;

    // bool operator==(const p &t){
    //     return (this->p_id==t.p_id);
    // }
};

// class mycmp{
//     public:
//     size_t operator() (const p& t)const{
//         return t.p_id;
//     }
// };

unordered_map<int, p> container;

class sMart
{
    string c_name, c_pas, c_id, c_email;
    string p_name;
    int p_id;
    float price;
    float amount;

public:
    void menu();
    void buyer();
    void admin();
    void show();
    void add();
    void remove();
    void edit(vector<pair<int,float>> &v);
    void edit();
    void recipt();
};

void sMart::menu()
{
    // getchar();
    cout << "\t\t\t\t\tInput your name please" << endl;
    cin>>c_name;

    cout << "\t\t\t\t\tInput your email id" << endl;
    cin>>c_email;
    cout << "\t\t\t\t\tInput your coustomer id" << endl;
    cin>>c_id;

    cout << "\t\t\t\t\tInput your passward" << endl;
    cin>>c_pas;

    cout << "\t\t\t\t\tchoose 1 if you are admin" << endl;
    cout << "\t\t\t\t\tchoose 2 if you are coustmer" << endl;
    cout << "\t\t\t\t\tchoose 3 to return" << endl;

    int ch;
    cout << "\t\t\t\t\tInput your choice" << endl;
    cin >> ch;

    switch (ch)
    {
    case 1:
        if (c_id == "0101" && c_pas == "SUpr^&8976")
        {
            admin();
        }
        else
        {
            cout << "\t\t\t\t\tyou are not admin" << endl;
            cout<<endl<<endl;
            menu();
        }
        break;

    case 2:
        buyer();

        break;
    case 3:
        return;
        break;

    default:
        cout << "plese select from given action" << endl;
        break;
    }
}

void sMart::admin()
{
    cout << "\t\t\t\t\t Admin menu" << endl;
    cout << "\t\t\t\t\t choose 1 to add a product" << endl;
    cout << "\t\t\t\t\t choose 2 to edit a product" << endl;
    cout << "\t\t\t\t\t choose 3 to remove a product" << endl;
    cout << "\t\t\t\t\t choose 4 to go back to main menu" << endl;

    int ch;
    cout << "\t\t\t\t\tInput your choice" << endl;
    cin >> ch;

    switch (ch)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;
    case 3:
        remove();
        break;

    case 4:
        return;
        break;
    default:
        cout << "plese select from given action" << endl;
        admin();
        break;
    }
}

void sMart::buyer()
{
    cout << "\t\t\t\t\t Buyer menu" << endl;
    cout << "\t\t\t\t\t choose 1 to view" << endl;
    cout << "\t\t\t\t\t choose 2 to go back" << endl;

    int ch;
    cout << "\t\t\t\t\tInput your choice" << endl;
    cin >> ch;

    switch (ch)
    {
    case 1:
        recipt();
        break;

    case 2:
        return;
        break;
    default:
        cout << "plese select from given action" << endl;
        buyer();
        break;
    }
}

void sMart::add()
{
    int n;
    cout << "\t\t\t\t\tinput number of products you want to add" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string p_name;
        int p_id;
        float price;
        float amount;
        // getchar();
        cout << "\t\t\t\t\tinput product name" << endl;
        cin>>p_name;
        cout << "\t\t\t\t\tinput product id" << endl;
        cin >> p_id;
        cout << "\t\t\t\t\tinput product prince" << endl;
        cin >> price;
        cout << "\t\t\t\t\tinput product amount" << endl;
        cin >> amount;

        if (container.find(p_id) == container.end())
        {
            container[p_id] = {p_id, price, amount, p_name};
        }
        else
        {
            cout << "\t\t\t\t\tproduct already exist" << endl;
        }
    }

    ofstream f("item.txt");

    for (auto s : container)
    {
        f << s.second.p_id<<" "<< s.second.price<<" " << s.second.amount <<" "<< s.second.p_name<<" "<<endl;
    }
    f.close();
}

void sMart::edit(){
    int id;
    cout<<"\t\t\t\t\tinput item id whose value you want to change"<<endl;

    cin>>id;

    if(container.find(id)==container.end()){
        cout<<"\t\t\t\t\tNO such item exit"<<endl;
    }
    else{
        cout<<"\t\t\t\t\t Previous values are:"<<endl;
        cout<<"\t\t\t\t\titem id:"<<container[id].p_id<<endl;
        cout<<"\t\t\t\t\titem name:"<<container[id].p_name<<endl;
        cout<<"\t\t\t\t\titem prince:"<<container[id].price<<endl;
        cout<<"\t\t\t\t\titem amount:"<<container[id].amount<<endl;


        cout<<"\t\t\t\t\tinput new price"<<endl;
        cin>>container[id].price;
        cout<<"\t\t\t\t\tinput new amount"<<endl;
        cin>>container[id].amount;

    }

    ofstream f("item.txt");

    for (auto s : container)
    {
        f << s.second.p_id<<" "<< s.second.price<<" " << s.second.amount <<" "<< s.second.p_name<<" "<<endl;
    }
    f.close();

}

void sMart::edit(vector<pair<int,float>> &a){

    for(auto x:a){
            container[x.first].amount-=x.second;
        }
    ofstream f("item.txt");

    for (auto s : container)
    {
        f << s.second.p_id<<" "<< s.second.price<<" " << s.second.amount <<" "<< s.second.p_name<<" "<<endl;
    }
    f.close();

}

void sMart::remove(){
    int id;
    cout<<"\t\t\t\t\tinput item id whose value you want to remove"<<endl;

    cin>>id;

    if(container.find(id)==container.end()){
        cout<<"\t\t\t\t\tNO such item exit"<<endl;
    }
    else{
        container.erase(id);

    }

    ofstream f("item.txt");

    for (auto s : container)
    {
        f << s.second.p_id<<" "<< s.second.price <<" "<< s.second.amount<<" " << s.second.p_name<<" "<<endl;
    }
    f.close();

}

void sMart::show(){
    cout<<endl;
    for(auto s:container){
        cout<<"\t\t\t\t\t"<<s.second.p_id<<endl;
        cout<<"\t\t\t\t\t"<<s.second.p_name<<endl;
        cout<<"\t\t\t\t\t"<<s.second.price<<endl;
        cout<<"\t\t\t\t\t"<<s.second.amount<<endl;
        cout<<endl;
    }
}

void sMart::recipt(){
    vector<pair<int,float>> by_p;
    float total=0;
    int id;
    float amnt;
    if(container.empty()){
        cout<<"\t\t\t\t\tEmpty database"<<endl;
    }
    else{
        cout<<"\t\t\t\t\tHere is the list of available items to buy:"<<endl;
        show();
        char ch;
        by_p.clear();
        do{
            cout<<"\t\t\t\t\tEnter product id and amount you want to buy"<<endl;
            cin>>id>>amnt;
            if(container.find(id)!=container.end()){
                by_p.push_back({id,amnt});
            }
            cout<<"\t\t\t\t\tPress 'y' to buy added items 'n' to continue adding"<<endl;
            cin>>ch;
        }while(ch=='n');
    }

    cout<<endl<<endl;
    cout<<"\t\t\t\t\t RECIPT"<<endl;
    for(auto x:by_p){
        float pr=container[x.first].price;
        total+=pr*x.second;
    }
    
    cout<<"\t\t\t\t\tTotal amount payable is: "<<total<<endl;
    edit(by_p);
}

int main()
{
    cout << endl
         << endl
         << endl
         << endl
         << endl;
    cout << "\t\t\t\t\t\t\t\t\tWELCOME TO OUR SUPER MART" << endl;
    cout << endl
         << endl
         << endl;
    {
        string p_name;
        int p_id;
        float price;
        float amount;   
        ifstream f;
        f.open("item.txt");

        if (f.is_open())
        {
            while (!f.eof())
            {
                f >> p_id >> price >> amount >> p_name;
                // cout<<p_id<<endl;
                container[p_id] = {p_id, price, amount, p_name};
            }
            sMart ob;
            ob.menu();
        }
        else
        {
            cout << "\t\t\t\t\tfile not opened" << endl;
        }
        f.close();
    }
    return 0;
}