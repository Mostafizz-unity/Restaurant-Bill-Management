#include<bits/stdc++.h>
using namespace std;
//1
class Restaurant{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
protected:
    double total_tax;
public:

    void showTotaltax(double tax)
    {
        total_tax=0;
        total_tax+=tax;
    }
};
class RT: public Restaurant
{
protected:
    double total_tax;
public:
    void showTotaltax(double tax)
    {
        total_tax+=tax;
        cout<<total_tax<<endl;
    }
};


int main()
{
    //2
    //input
    RT r;
    int n;
    cin>>n;
    Restaurant rt[n];
    for(int i=0;i<n;i++)
    {
        string names;
        int codes,prices;
        cin>>codes;
        cin.ignore();
        getline(cin,names);
        cin>>prices;


        rt[i].food_item_codes[i]=codes;
        rt[i].food_item_names[i]=names;
        rt[i].food_item_prices[i]=prices;
    }
    //3
    //Menu Card
    Flag:
    cout<<"                             MAKE BILL"<<endl;
    cout<<"                  -----------------------------------"<<endl;
    cout<<"Item Code"<<"                   "<<"Item Name"<<"                        "<<"Item Price"<<endl;
    for(int i=0;i<n;i++)
    {
        if(i==0) cout<<rt[i].food_item_codes[i]<<"                   "<<rt[i].food_item_names[i]<<"      "<<"                   "<<rt[i].food_item_prices[i]<<endl;
        else if(i==1||i==2||i==6) cout<<rt[i].food_item_codes[i]<<"                   "<<rt[i].food_item_names[i]<<" "<<"                   "<<rt[i].food_item_prices[i]<<endl;
        else if(i==4) cout<<rt[i].food_item_codes[i]<<"                   "<<rt[i].food_item_names[i]<<"    "<<"                   "<<rt[i].food_item_prices[i]<<endl;
        else if(i==5||i==10) cout<<rt[i].food_item_codes[i]<<"                   "<<rt[i].food_item_names[i]<<"  "<<"                   "<<rt[i].food_item_prices[i]<<endl;
        else if(i==7||i==8||i==11) cout<<rt[i].food_item_codes[i]<<"                   "<<rt[i].food_item_names[i]<<"     "<<"                   "<<rt[i].food_item_prices[i]<<endl;
        else cout<<rt[i].food_item_codes[i]<<"                   "<<rt[i].food_item_names[i]<<"                   "<<rt[i].food_item_prices[i]<<endl;
    }
    //4
    //Order item
    int table,items,code[12],quantity[101];double tax=0,sum=0;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"Enter Table No : ";cin>>table;
    cout<<"Enter Number of Items : ";cin>>items;
    for(int i=1;i<=items;i++)
    {
        cout<<"Enter Item "<<i<<" Code : ";cin>>code[i];
        cout<<"Enter Item "<<i<<" Quantity : ";cin>>quantity[i];
    }
    //6
    //BILL
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"                                         BILL SUMMARY"<<endl;
    cout<<"                             _____________________________________"<<endl;
    cout<<"Table No. : "<<table<<endl;
    cout<<"Item Code                  "<<"Item Name           "<<"      "<<"Item Price          "<<"Item Quantity   "<<"Total Price"<<endl;
    for(int i=1;i<=items;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            //5
            if(code[i]==rt[j].food_item_codes[j]){
                    cout<<rt[j].food_item_codes[j]<<"                   "<<rt[j].food_item_names[j]<<"                  "<<rt[j].food_item_prices[j]<<"                 "<<quantity[i]<<"           "<<rt[j].food_item_prices[j]*quantity[i]<<endl;
                    sum+=rt[j].food_item_prices[j]*quantity[i];
                }
            else count++;
        }
        //8
        if(count==12){
            cout<<""<<endl;
            cout<<""<<endl;
            cout<<" This code is not valid, Please try again "<<endl;
            cout<<""<<endl;
            cout<<""<<endl;
            goto Flag;
        }
    }
    tax=(double)sum/20;
    sum+=tax;
    cout<<"TAX"<<"                                                                                          "<<fixed<<setprecision(2)<<tax<<endl;
    cout<<"___________________________________________________________________________________________________________________"<<endl;
    cout<<"NET TOTAL                                                                                    "<<sum<<" Taka"<<endl;
    //7
    //Total Tax
    //cout<<"TOTAL TAX :";r.showTotaltax(tax);
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    goto Flag;
    return 0;
}
