#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int lineCounter = 0;

vector<string> getContent(string input)
{
    string delimiters = " ,\t";
    size_t current;
    size_t next = -1;
    string out, tempSub;
    int counter = 0;
    vector<string> content;


    do
    {
        current = next + 1;
        next = input.find_first_of( delimiters, current );
        tempSub = input.substr( current, next - current );
        if (tempSub.size() > 0)
        {
            counter++;
            //cout<<tempSub<<endl;
            content.push_back(tempSub);
        }


    }
    while (next != string::npos);
    return content;

}
string reg2bin(string input)
{
    if (input.size() > 4 || input.size() < 3)
    {
        cout << "error in reg2bin input size, size:" << input.size() << endl << "input is:" << input  << "in line "<<lineCounter<<endl;
        throw - 6;
    }
    if (input == "$R00")
    {
        input = "00000";
    }
    else if (input == "$R01")
    {
        input = "00001";
    }
    else if (input == "$R02")
    {
        input = "00010";
    }
    else if (input == "$R03")
    {
        input = "00011";
    }
    else if (input == "$R04")
    {
        input = "00100";
    }
    else if (input == "$R05")
    {
        input = "00101";
    }
    else if (input == "$R06")
    {
        input = "00110";
    }
    else if (input == "$R07")
    {
        input = "00111";
    }
    else if (input == "$R08")
    {
        input = "01000";
    }
    else if (input == "$R09")
    {
        input = "01001";
    }
    else if (input == "$R10")
    {
        input = "01010";
    }
    else if (input == "$R11")
    {
        input = "01011";
    }
    else if (input == "$R12")
    {
        input = "01100";
    }
    else if (input == "$R13")
    {
        input = "01101";
    }
    else if (input == "$R14")
    {
        input = "01110";
    }
    else if (input == "$R15")
    {
        input = "01111";
    }
    else if (input == "$R16")
    {
        input = "10000";
    }
    else if (input == "$R17")
    {
        input = "10001";
    }
    else if (input == "$R18")
    {
        input = "10010";
    }
    else if (input == "$R19")
    {
        input = "10011";
    }
    else if (input == "$R20")
    {
        input = "10100";
    }
    else if (input == "$R21")
    {
        input = "10101";
    }
    else if (input == "$R22")
    {
        input = "10110";
    }
    else if (input == "$R23")
    {
        input = "10111";
    }
    else if (input == "$R24")
    {
        input = "11000";
    }
    else if (input == "$R25")
    {
        input = "11001";
    }
    else if (input == "$R26")
    {
        input = "11010";
    }
    else if (input == "$R27")
    {
        input = "11011";
    }
    else if (input == "$R28")
    {
        input = "11100";
    }
    else if (input == "$R29")
    {
        input = "11101";
    }
    else if (input == "$R30")
    {
        input = "11110";
    }
    else if (input == "$R31")
    {
        input = "11111";
    }
    else
    {
        cout << "error input in reg2bin "<< "in line "<<lineCounter << endl;
        throw - 7;
    }
    return input;
}

string fillZeros(int size)
{
    string binFill;
    for (int i = 0; i < size; i++)
    {
        binFill = binFill + string("0");
    }
    return binFill;
}
string dec2bin(string input)
{
    int DECNumber = stoi(input);
    string bin;
    while (DECNumber > 0)
    {
        if (DECNumber % 2 == 0)
        {
            bin = bin + string("0");

        }
        else
        {
            bin = bin + string("1");

        }
        DECNumber = DECNumber / 2;
    }

    return bin;
}
string NOP(string OPCODE)
{
    string output = OPCODE;
    output = output + fillZeros(32 - output.size());
    return output;

}
string RegRegReg(string OPCODE, vector<string> input)
{
    //cout<<input.size()<<endl;
    if (input.size() > 4)
    {
        cout << "too many argument "<< "in line "<<lineCounter << endl;
        throw - 4;
    }
    else if (input.size() < 4)
    {
        cout << "not enough argument "<< "in line "<<lineCounter << endl;
        throw - 5;
    }
    string output = OPCODE + reg2bin(input[1]) + reg2bin(input[2]) + reg2bin(input[3]);
    output = output + fillZeros(32 - output.size());
    ///cout<<output.size()<<endl;
    return output;

}
string RegReg(string OPCODE, vector<string> input)
{
    //cout<<input.size()<<endl;
    if (input.size() > 3)
    {
        cout << "too many argument "<< "in line "<<lineCounter << endl;
        throw - 4;
    }
    else if (input.size() < 3)
    {
        cout << "not enough argument "<< "in line "<<lineCounter << endl;
        throw - 5;
    }
    string output = OPCODE + reg2bin(input[1]) + reg2bin(input[2]);
    output = output + fillZeros(32 - output.size());
    ///cout<<output.size()<<endl;
    return output;

}
string Reg(string OPCODE, vector<string> input)
{
    //cout<<input.size()<<endl;
    if (input.size() > 2)
    {
        cout << "too many argument "<< "in line "<<lineCounter << endl;
        throw - 4;
    }
    else if (input.size() < 2)
    {
        cout << "not enough argument "<< "in line "<<lineCounter << endl;
        throw - 5;
    }
    string output = OPCODE + reg2bin(input[1]);
    output = output + fillZeros(32 - output.size());
    ///cout<<output.size()<<endl;
    return output;

}


string RegVal(string OPCODE, vector<string> input)
{
    if (input.size() > 3)
    {
        cout << "too many argument "<< "in line "<<lineCounter << endl;
        throw - 4;
    }
    else if (input.size() < 3)
    {
        cout << "not enough argument "<< "in line "<<lineCounter << endl;
        throw - 5;
    }
    //cout<< input[2]<<endl;
    string output = OPCODE + reg2bin(input[1]);
    try{
        int t = stoi(input[2]);
    }catch(const std::exception& x){
        cout<<"invalid input for a RegVal"<< "in line "<<lineCounter << endl;
    }
    if(stoi(input[2])>4194304){
        cout <<"value is too big"<< "in line "<<lineCounter << endl;
    }
    string numInBin = dec2bin(input[2]);

    output = output + fillZeros(32 - output.size() - numInBin.size()) + dec2bin(input[2]);
    output = output + fillZeros(32 - output.size());
    ///cout<<output.size()<<endl;
    return output;
}


int main(int argc, char *argv[])
{
    string fileName = "";

    if (argc > 2)
    {
        cout << "too many input "<< "in line "<<lineCounter << endl;
        return -1;

    }
    else if (argc == 2)
    {
        fileName = argv[1];
    }
    else
    {
        fileName = "IS2.asm";
    }
    //cout<<fileName<<endl; //shows the fileName
    ifstream input(fileName);
    ofstream output("output.asm");
    string line, tempOP;
    
    while (getline(input, line))
    {
        lineCounter++;
        if (line.size() != 0)
        {
            //cout<<line<<endl;
            string tempOut;
            //find the first keyword
            vector<string> listStr = getContent(line);
            tempOP = listStr[0];
            if (!(tempOP.size() >= 2 && tempOP.size() < 5))
            {
                cout << "woah weird command at line: " << lineCounter << endl << "exiting" << endl;
                return -2;
            }
            //cout<<tempOP<<endl;// show what command it is
            if (tempOP == "NOP")
            {
                tempOut = NOP("00000");
            }
            else if (tempOP == "MOV")
            {
                tempOut = RegReg("00001", listStr);
            }
            else if (tempOP == "ADD")
            {
                tempOut = RegReg("00010", listStr);
            }
            else if (tempOP == "ADDI")
            {
                tempOut = RegVal("00011", listStr);
            }
            else if (tempOP == "INC")
            {
                tempOut = Reg("00100", listStr);
            }
            else if (tempOP == "SUB")
            {
                tempOut = RegReg("00101", listStr);
            }
            else if (tempOP == "SUBI")
            {
                tempOut = RegVal("00110", listStr);
            }
            else if (tempOP == "DEC")
            {
                tempOut = Reg("00111", listStr);
            }
            else if (tempOP == "MUT")
            {
                tempOut = RegReg("01000", listStr);
            }
            else if (tempOP == "MUTI")
            {
                tempOut = RegVal("01001", listStr);
            }
            else if (tempOP == "DIV")
            {
                tempOut = RegReg("01010", listStr);
            }
            else if (tempOP == "DIVI")
            {
                tempOut = RegVal("01011", listStr);
            }
            else if (tempOP == "SLA")
            {
                tempOut = Reg("01100", listStr);
            }
            else if (tempOP == "SRA")
            {
                tempOut = Reg("01101", listStr);
            }
            else if (tempOP == "AND")
            {
                tempOut = RegReg("01110", listStr);
            }
            else if (tempOP == "ANDI")
            {
                tempOut = RegVal("01111", listStr);
            }
            else if (tempOP == "OR")
            {
                tempOut = RegReg("10000", listStr);
            }
            else if (tempOP == "ORI")
            {
                tempOut = RegVal("10001", listStr);
            }
            else if (tempOP == "NOR")
            {
                tempOut = RegReg("10010", listStr);
            }
            else if (tempOP == "NOT")
            {
                tempOut = Reg("10011", listStr);
            }
            else if (tempOP == "XOR")
            {
                tempOut = RegReg("10100", listStr);
            }
            else if (tempOP == "LOD")
            {
                tempOut = RegReg("10101", listStr);
            }
            else if (tempOP == "STE")
            {
                tempOut = RegReg("10110", listStr);
            }
            else if (tempOP == "WRT")
            {
                tempOut = RegVal("10111", listStr);
            }
            else if (tempOP == "SWP")
            {
                tempOut = RegReg("11000", listStr);
            }
            else if (tempOP == "BRH")
            {
                tempOut = Reg("11001", listStr);
            }
            else if (tempOP == "BEQ")
            {
                tempOut = RegRegReg("11010", listStr);;
            }
            else if (tempOP == "BNE")
            {
                tempOut = RegRegReg("11011", listStr);
            }
            else if (tempOP == "INT")
            {
                tempOut = NOP("11100");
            }
            else
            {
                cout << "errrrrrr...... not a valid command "<< "in line "<<lineCounter << endl;
            }

            output<<tempOut<<endl;




        }
    }




    printf("it worked?\n");

    return 0;
}

