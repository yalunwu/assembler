
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
using namespace std;

string fillZeros(int size){
	string binFill;
	for(int i = 0;i<size;i++){
		binFill = binFill+string("0");
	}
	return binFill;
}


int main(){
	ifstream input("IS2.asm");
	ofstream output("output.asm");
	string temp,tempOP;
	while(getline(input,temp)){
		if(temp.size()!=0){
			cout<<temp<<endl;
			string delimiters = " ,";
			size_t current;
			size_t next = -1;
			string tempOut;
			do
			{
				current = next + 1;
				next = temp.find_first_of( delimiters, current );
				tempOP=temp.substr( current, next - current );
				bool onlyNum = true;
				for(unsigned int i = 0;i<tempOP.size();i++){
					if((tempOP[i] < '0' || tempOP[i] > '9' ) ){
						onlyNum = false;break;
					}						
				}
				//cout<<tempOP<<endl;
				if(onlyNum){
					//cout<<"onlyNum"<<endl;
					

					int DECNumber = stoi(tempOP);
					string bin;
					while (DECNumber>0){
						if(DECNumber%2==0){
							bin = bin+string("0");

						}else{
							bin = bin+string("1");

						}
						DECNumber = DECNumber/2;
					}
					//cout<<"number in BIN:"<<bin<<endl;
					if (bin.size()<=17)
					{
						int sizeDiff = 17-bin.size();

						bin = fillZeros(sizeDiff)+bin;
					}else{
						//errr too big should we drop?
						cout<<"errrrrrrrrr..... too big of a number"<<endl;
						return -3;
					}
					tempOP = bin;
					
					
				}else{
					//cout<<"using choice"<<endl;
					if (tempOP == "NOP") {
						tempOP="00000";
					} else if (tempOP =="MOV") {
						tempOP="00001";
					} else if (tempOP == "ADD") {
						tempOP="00010";
					} else if (tempOP == "ADDI") {
						tempOP="00011";
					} else if (tempOP == "INC") {
						tempOP="00100";
					} else if (tempOP == "MIN") {
						tempOP="00101";
					} else if (tempOP == "MINI") {
						tempOP="00110";
					} else if (tempOP == "DEC") {
						tempOP="00111";
					} else if (tempOP == "MUT") {
						tempOP="01000";
					} else if (tempOP == "MUTI") {
						tempOP="01001";
					} else if (tempOP == "DIV") {
						tempOP="01010";
					} else if (tempOP == "DIVI") {
						tempOP="01011";
					} else if (tempOP == "SLA") {
						tempOP="01100";
					} else if (tempOP == "SRA") {
						tempOP="01101";
					} else if (tempOP == "AND") {
						tempOP="01110";
					} else if (tempOP == "ANDI") {
						tempOP="01111";
					} else if (tempOP == "OR") {
						tempOP="10000";
					} else if (tempOP == "ORI") {
						tempOP="10001";
					} else if (tempOP == "NOR") {
						tempOP="10010";
					} else if (tempOP == "XOR") {
						tempOP="10011";
					} else if (tempOP == "LOD") {
						tempOP="10100";
					} else if (tempOP == "STE") {
						tempOP="10101";
					} else if (tempOP == "WRT") {
						tempOP="10110";
					} else if (tempOP == "SWP") {
						tempOP="10111";
					} else if (tempOP == "BRH") {
						tempOP="11000";
					} else if (tempOP == "BEQ") {
						tempOP="11001";
					} else if (tempOP == "BNE") {
						tempOP="11010";
					} else if (tempOP == "INT") {
						tempOP="11011";
					} else if (tempOP == "$R00") {
						tempOP="00000";
					} else if (tempOP == "$R01") {
						tempOP="00001";
					} else if (tempOP == "$R02") {
						tempOP="00010";
					} else if (tempOP == "$R03") {
						tempOP="00011";
					} else if (tempOP == "$R04") {
						tempOP="00100";
					} else if (tempOP == "$R05") {
						tempOP="00101";
					} else if (tempOP == "$R06") {
						tempOP="00110";
					} else if (tempOP == "$R07") {
						tempOP="00111";
					} else if (tempOP == "$R08") {
						tempOP="01000";
					} else if (tempOP == "$R09") {
						tempOP="01001";
					} else if (tempOP == "$R10") {
						tempOP="01010";
					} else if (tempOP == "$R11") {
						tempOP="01011";
					} else if (tempOP == "$R12") {
						tempOP="01100";
					} else if (tempOP == "$R13") {
						tempOP="01101";
					} else if (tempOP == "$R14") {
						tempOP="01110";
					} else if (tempOP == "$R15") {
						tempOP="01111";
					} else if (tempOP == "$R16") {
						tempOP="10000";
					} else if (tempOP == "$R17") {
						tempOP="10001";
					} else if (tempOP == "$R18") {
						tempOP="10010";
					} else if (tempOP == "$R19") {
						tempOP="10011";
					} else if (tempOP == "$R20") {
						tempOP="10100";
					} else if (tempOP == "$R21") {
						tempOP="10101";
					} else if (tempOP == "$R22") {
						tempOP="10110";
					} else if (tempOP == "$R23") {
						tempOP="10111";
					} else if (tempOP == "$R24") {
						tempOP="11000";
					} else if (tempOP == "$R25") {
						tempOP="11001";
					} else if (tempOP == "$R26") {
						tempOP="11010";
					} else if (tempOP == "$R27") {
						tempOP="11011";
					} else if (tempOP == "$R28") {
						tempOP="11100";
					} else if (tempOP == "$R29") {
						tempOP="11101";
					} else if (tempOP == "$R30") {
						tempOP="11110";
					} else if (tempOP == "$R31") {
						tempOP="11111";
					}else{
						cout<<"errrr cant parse it.... did u have a weird command?"<<endl<<tempOP<<endl;
						return -1;
					} 
				
					
				}
				//build the bits 
				//cout << tempOP<<endl;
				tempOut= tempOut+tempOP;	
			}while (next != string::npos);
			

			//check the size of the string

			if(tempOut.size()>32){
				cout<<"errrrr tooo long of a command "<<endl<<temp<<endl<<"size is:"<<tempOut.size()<<endl;
				return -2;
			}else{
				if (tempOut.size()<=32)
				{
					tempOut = tempOut+fillZeros(32-tempOut.size());
				}
			}
			cout<<tempOut<<endl<<"size is:"<<tempOut.size()<<endl;
			output<<tempOut<<endl;

		}
	}

	
	
	
	printf("it worked?\n");

	return 0;
}

