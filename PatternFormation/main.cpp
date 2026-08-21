#include <iostream>
using namespace std;

void print1 (int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void print2 (int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void print3 (int n){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void print4 (int n){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

void print5 (int n){
    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
}

void print6 (int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void print7 (int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(2*i)-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void print8 (int n){
    for(int i=1;i<=n;i++){
    	for(int a=n-i; a>0; a--){
    		cout<<" ";
		}
		for(int j=1;j<=(2*i)-1;j++){
		    cout<<"*";
		}
 	    for(int b=n-i; b>0; b--){
    		cout<<" ";
		}
        cout<<endl;
    }
}

void print9 (int n){
    for(int i=n;i>=1;i--){
    	for(int a=1; a<n-i+1; a++){
    		cout<<" ";
		}
		for(int j=1;j<=(2*i)-1;j++){
		    cout<<"*";
		}
 	    for(int b=1; b<n-i+1; b++){
    		cout<<" ";
		}
        cout<<endl;
    }
}

void print10 (int n){
    for(int i=1;i<=n;i++){
    	for(int a=n-i; a>0; a--){
    		cout<<" ";
		}
		for(int j=1;j<=(2*i)-1;j++){
		    cout<<"*";
		}
 	    for(int b=n-i; b>0; b--){
    		cout<<" ";
		}
        cout<<endl;
    }
        for(int i=n-1;i>=1;i--){
    	for(int a=1; a<n-i+1; a++){
    		cout<<" ";
		}
		for(int j=1;j<=(2*i)-1;j++){
		    cout<<"*";
		}
 	    for(int b=1; b<n-i+1; b++){
    		cout<<" ";
		}
        cout<<endl;
    }
}

void print11 (int n){
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
        for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    print11(n);
}