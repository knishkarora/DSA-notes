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

void print12 (int n){
	int start = 1;
    for(int i=n;i>0;i--){
        for(int j=1;j<=n-i+1;j++){
            cout<<start;
            start = 1 - start;
        }
        cout<<endl;
    }
}

void print13 (int n){
    for(int i=1;i<=n;i++ ){
    	for(int a=1; a<=i; a++){
    		cout<<a;
		}
		for(int j=2*(n-i);j>0;j--){
		    cout<<" ";
		}
 	    for(int b=i; b>=1; b--){
    		cout<<b;
		}
        cout<<endl;
    }
}

void print14 (int n){
	int start = 1;
    for(int i=n;i>0;i--){
        for(int j=1;j<=n-i+1;j++){
            cout<<start;
            start++;
        }
        cout<<endl;
    }
}

void print15 (int n){
    for(int i=0;i<n;i++){
        for(char ch='A';ch <='A' + i; ch++){
            cout<<ch;
        }
        cout<<endl;
    }
}

void print16 (int n){
    for(int i=n-1;i>=0;i--){
        for(char ch='A';ch <='A' + i; ch++){
            cout<<ch;
        }
        cout<<endl;
    }
}

void print17 (int n){
    char ch = 'A';
    for(int i=1; i<=n; i++){
        for(int j=1;j<=i; j++){
            cout<<ch;
        }
        ch = 'A' + i;
        cout<<endl;
    }
}

void print18 (int n){
    for(int i=1;i<=n;i++){
    	char ch = 'A';
    	for(int a=n-i; a>0; a--){
    		cout<<" ";
		}
		for(int j=1;j<=(2*i)-1;j++){
			if(j<=i){
				ch = 'A' + (j-1);
			}else{ 
				ch--;
			}
            cout<<ch;
		}
 	    for(int b=n-i; b>0; b--){
    		cout<<" ";
		}
        cout<<endl;
    }
}

void print19 (int n){
	for(int i=1;i<=n;i++){
		char start = 'A' + (n-i);
		for(int j=n;j>=n-i+1;j--){
			cout<<start;
			start++;
			
		}
        cout<<endl;
	}
}

void print20 (int n){
	for(int i=1;i<2*n;i++){
		int stars = i;
		int spaces = 2*(n-i);
		if(i>n){
			stars = 2*n-i;
			spaces = 2*(i-n);
		}
		for(int j=1;j<=stars;j++){
			cout<<"*";
		}
		for(int a=1; a<=spaces; a++){
			cout<<" ";
		}
		for(int b=1; b<=stars; b++){
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
    print20(n);
}