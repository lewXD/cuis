
#include<iostream>

using namespace std;

int main(){
	
	int tablero[9][9], fichas[]={16,16}, turno=1,a=11,b=0, aux=0;

	for (int i=0; i<9; i++){
		for (int j=0; j<9; j++){
			if ((i==0) || (j==0)) {tablero[i][j]=i+j;}
			if ((i!=0) && (j!=0)){
				switch (j){
					case 1:
						tablero[i][j] = i;
						tablero[8-i+1][j] = i;
						if ((i==4) || (i==5)) {tablero[i][j] = i-1;}
						break;
					case 2: 
					    tablero[i][j] = 3;
					    break;
					case 8:
						tablero[i][j] = -i;
						tablero[8-i+1][j] = -i;
						if ((i==4) || (i==5)) {tablero[8-i+1][j] = -i+1;}
						break;
					case 7:
						tablero[i][j] = -3;
					    break;
					default :
						tablero[i][j] = 0;
				}
			}
		}
	}
	
	while ((fichas[0]>0) && (fichas[1]>0)){
		
		cout<<"turno del jugador "<<turno<<endl<<endl;
		
		for (int i=0; i<9; i++){
		    for (int j=0; j<9; j++){
			    if ((i==0) || (j==0)) {if ((i==0) && (j==0)){cout<<" "<<tablero[i][j]<<"* ";} else {cout<<" "<<tablero[i][j]<<"*";}}
			    else {cout<<"  "<<tablero[i][j];}
		    }
		    cout<<endl;
	    }
	    
	    switch (turno){
	    	case 1:
	    		do{
	    			do{
				        do{
	    	                if (tablero[a/10][a%10]<=0) {cout<<"no hay una ficha tuya en esa casilla"<<endl;}
		                    cout<<"ficha a mover: ";cin>>a;
		                }
		                while(a%10<1 || a%10>8);
		            }
		            while(a/10<1 || a/10>8);
			    }
			    while(tablero[a/10][a%10]<=0);
			    break;
			default :
				do{
					do{
	     			    do{
	        	            if (tablero[a/10][a%10]>=0) {cout<<"no hay una ficha tuya en esa casilla"<<endl;}
		                    cout<<"ficha a mover: ";cin>>a;
	    	            }
    		            while(a%10<1 || a%10>8);
					}
					while(a/10<1 || a/10>8);
				}
			    while(tablero[a/10][a%10]>=0);	
		}

	    switch (tablero[a/10][a%10]){
	    	case 3:
	    		do{
	    			if (b>0) {cout<<"la ficha no puede ir ahi"<<endl;}
	    			cout<<"a donde: ";cin>>b;
				}
				while (b != a+1);
				break;
			case -3:
				do{
					if (b>0) {cout<<"la ficha no puede ir ahi"<<endl;}
	    			cout<<"a donde: ";cin>>b;
				}
				while (b != a-1);
				break;
			case 8:
			case -8:
				do{
	    			do{
		    		    do{
		    	    		if (b>0) {cout<<"la ficha no puede ir ahi"<<endl;}
		    	    		cout<<"a donde: ";cin>>b;
		    	    	}
		    	    	while (b/10 != a/10 && b%10 != a%10);
		        	}
		    		while (b%10<1 || b%10>8);
	    		}
	    		while (b/10<1 || b/10>8);
				break;
			case 7:
			case -7:
				do{
	    			do{
	    				do{
		        		    do{
		         	    		if (b>0) {cout<<"la ficha no puede ir ahi"<<endl;}
		         	    		cout<<"a donde: ";cin>>b;
		        	    	}
		        	    	while (b/10 != a/10+2 && b%10 != a%10+2);
		        	    }
			    		while (b/10 != a/10+1 && b/10 != a/10-1 && b%10 != a%10+1 && b%10 != a%10-1);
		        	}
		    		while (b%10<1 || b%10>8);
	    		}
	    		while (b/10<1 || b/10>8);
				break;
			case 6:
			case -6:
				do{
	    			do{
		    		    do{
		    	    		if (b>0) {cout<<"la ficha no puede ir ahi"<<endl;}
		    	    		cout<<"a donde: ";cin>>b;
		    	    	}
		    	    	while (b/10-a/10 != b%10-a%10 && a/10-b/10 != b%10-a%10 && b/10-a/10 != a%10-b%10);
		        	}
		    		while (b%10<1 || b%10>8);
	    		}
	    		while (b/10<1 || b/10>8);
				break;
			case 5:
			case -5:
				do{
	    			do{
		    		    do{
		    	    		if (b>0) {cout<<"la ficha no puede ir ahi"<<endl;}
		    	    		cout<<"a donde: ";cin>>b;
		    	    	}
		    	    	while ((b/10-a/10 != b%10-a%10 && a/10-b/10 != b%10-a%10 && b/10-a/10 != a%10-b%10) && (b/10 != a/10 && b%10 != a%10));
		        	}
		    		while (b%10<1 || b%10>8);
	    		}
	    		while (b/10<1 || b/10>8);
				break;
			case 4:
			case -4:
				do{
	    			do{
		    		    do{
		    	    		if (b>0) {cout<<"la ficha no puede ir ahi"<<endl;}
		    	    		cout<<"a donde: ";cin>>b;
		    	    	}
		    	    	while (b != a+1 && b != a-1 && b/10 != a/10+1 && b/10 != a/10-1 && b%10 != a%10+1 && b%10 != a%10-1);
		        	}
		    		while (b%10<1 || b%10>8);
	    		}
	    		while (b/10<1 || b/10>8);		
		}
		
	    cout<<endl;
	    
	    tablero[b/10][b%10] = tablero[a/10][a%10];
	    tablero[a/10][a%10] = 0;
	    
	    b=0;
	    a=0;
	    
	    switch (turno){
	    	case 1: turno=2; tablero[a/10][a%10] =-1;
	    	break;
	    	default : turno=1; tablero[a/10][a%10] =1;
		}
		
		system("cls");
	}
	
	return 0;
}
