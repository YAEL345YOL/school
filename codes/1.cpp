#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define pb push_back
#define lsb(x) (x & -x) 
#define sp(x) fixed<<setprecision(x)
#define all(x) x.begin(),x.end()
#define fore(it,i,f) for(auto it=i;it<f;++it)

typedef long long ll;
typedef unsigned long long ull;

double mediana(vector<double>&elements,ll n){
    if(n%2 == 0){
        ll e1 = (n / 2) - 1;
        ll e2 = e1 + 1;

        return (elements[e1] + elements[e2]) / 2;
    }
    return elements[n / 2];
}

double media(vector<double>&elements,ll n){
    double sum = 0;
    for(auto&element:elements){
        sum += element;
    }
    return (double) sum / n;
}

double mediaGeometria(vector<double>&elements,ll n){
    double product = 1;
    for(auto&element:elements){
        product *= element;
    }
    return pow(product,(double) 1.0 / n);
}

double mediaArmonica(vector<double>&elements,ll n){
    double sum = 0;
    for(auto&element:elements){
        sum += 1 / element;
    }
    return (double) n / sum;
}

vector<double> moda(vector<double>&elements,ll n){
    unordered_map<double, ll>frec;
    vector<double>res;

    for(auto&element:elements){
        ++frec[element];
    }

    ll m = 1;

    for(auto&par:frec){
        m = max(m, par.second);
    }

    if(m == 1) return {};

    for(auto&par:frec){
        if(par.second == m){
            res.pb(par.first);
        }
    }

    return res;
}

int main(){
    cin.tie(0)->sync_with_stdio(0),cout.tie(0);
    
    ll n;
    cin>>n;

    vector<double>elements(n);

    fore(i,0,n){
        cin>>elements[i];
    }

    sort(all(elements));

    cout<<"Elementos ordenados: "<<nl;

    for(auto&element:elements){
        cout<<element<<nl;
    }

    cout<<"Media: "<<media(elements, n)<<nl;
    cout<<"Mediana: "<<mediana(elements, n)<<nl;
    
    cout<<"Moda: ";

    vector<double>m = moda(elements, n);

    if(m.empty()) cout<<"No hay";
    else{
        for(auto&element:m){
            cout<<element<<" ";
        }
    }

    cout<<nl;

    cout<<"Media Geometrica: "<<mediaGeometria(elements, n)<<nl;
    cout<<"Media Armonica (H): "<<mediaArmonica(elements, n)<<nl;

    return 0;
}
