#include <bits/stdc++.h>
using namespace std;

/**
 *
 * Project : SIC/XE Machine Architecture 
 * author  : Mohamed Abdalazez Abdallah Mohamed
 *
**/

string opTab(string mnem)
{
  map<string, string> r;
  r["ADD"] = "18";
  r["ADDF"] = "58";
  r["ADDR"] = "90";
  r["AND"] = "40";
  r["CLEAR"] = "B4";
  r["COMP"] = "28";
  r["COMPF"] = "88";
  r["COMPR"] = "A0";
  r["DIV"] = "24";
  r["DIVF"] = "64";
  r["DIVR"] = "9C";
  r["FIX"] = "C4";
  r["FLOAT"] = "C0";
  r["HIO"] = "F4";
  r["J"] = "3C";
  r["JEQ"] = "30";
  r["JGT"] = "34";
  r["JLT"] = "38";
  r["JSUB"] = "48";
  r["LDA"] = "00";
  r["LDB"] = "68";
  r["LDCH"] = "50";
  r["LDF"] = "70";
  r["LDL"] = "08";
  r["LDS"] = "6C";
  r["LDT"] = "74";
  r["LDX"] = "04";
  r["LPS"] = "D0";
  r["MUL"] = "20";
  r["MULF"] = "60";
  r["MULR"] = "98";
  r["NORM"] = "C8";
  r["OR"] = "44";
  r["RD"] = "D8";
  r["RMO"] = "AC";
  r["RSUB"] = "4C";
  r["SHIFTL"] = "A4";
  r["SHIFTR"] = "A8";
  r["SIO"] = "F0";
  r["SSK"] = "EC";
  r["STA"] = "0C";
  r["STB"] = "78";
  r["STCH"] = "54";
  r["STF"] = "80";
  r["STI"] = "D4";
  r["STL"] = "14";
  r["STS"] = "7C";
  r["STSW"] = "E8";
  r["STT"] = "84";
  r["STX"] = "10";
  r["SUB"] = "1C";
  r["SUBF"] = "5C";
  r["SUBR"] = "94";
  r["SVC"] = "B0";
  r["TD"] = "E0";
  r["TIO"] = "F8";
  r["TIX"] = "2C";
  r["TIXR"] = "B8";
  r["WD"] = "DC";
  string opcode;

  opcode = r[mnem];
  return opcode;
}

int H_TO_D(string s)
{
  int x;
  stringstream str;
  str << s;
  str >> hex >> x;
  return x;
}

string D_TO_H(int number)
{
  stringstream str;
  str << hex << number;
  return str.str();
}

string add(string str, string adder)
{
  int num1 = H_TO_D(str);
  int num2 = H_TO_D(adder);
  int sum = num1 + num2;
  return D_TO_H(sum);
}

string fill(string s)
{
  int sz = s.size();
  if (sz == 4)
    return s;
  else if (sz < 4)
  {
    sz = 4 - sz;
    while (sz--)
      s = "0" + s;
  }
  else
  {
    ;
  }
  return s;
}

string get_format(string instruction, string s)
{
  string ans = "";
  if (instruction == "START" || instruction == "END")
  {
    return "0000";
  }
  if (instruction[0] == '+')
  {
    ans = "4";
    return fill(ans);
  }
  else if (instruction == "BYTE" || instruction == "RESW" || instruction == "RESB")
  {
    if (instruction == "BYTE")
    {
      string str, a, b, inc;
      a = s, b, inc;
      if (a[0] == 'X')
      {
        int sz = a.size() - 3; // X'05' -3 05
        if (sz & 1)
          sz++;
        sz /= 2;
        a = D_TO_H(sz);
        return fill(a);
      }
      else
      {
        int sz = a.size() - 3; // C'EOF' -3 EOF
        a = D_TO_H(sz);
        return fill(a);
      }
    }
    else
    {
      if (instruction == "RESW")
      {
        string str;
        string a = s, b, inc;
        int num = stoi(a) * 3;
        a = D_TO_H(num);
        return fill(a);
      }
      else
      {
        string str;
        string a = s, b, inc;
        int num = stoi(a);
        a = D_TO_H(num);
        return fill(a);
      }
    }
  }
  else if (instruction == "ADDR" || instruction == "CLEAR" || instruction == "COMPR" || instruction == "DIVR" ||
           instruction == "MULR" || instruction == "RMO" || instruction == "SHIFTL" || instruction == "SHIFTR" ||
           instruction == "SUBR" || instruction == "SVC" || instruction == "TIXR")
  {
    ans = "2";
    return fill(ans);
  }
  else if (instruction == "FIX" || instruction == "FLOAT" || instruction == "HIO" || instruction == "NORM" || instruction == "SIO" || instruction == "TIO")
  {
    ans = "1";
    return fill(ans);
  }
  else if (instruction == "BASE")
  {
    ans = "0000";
    return fill(ans);
  }
  else
  {
    ans = "3";
    return fill(ans);
  }
}

int main()
{
  /*Read From File*/
  ifstream myFile("inSICXE.txt");
  string data, wd;
  vector<tuple<string, string, string>> Code;
  if (myFile.is_open())
  {
    while (getline(myFile, data))
    {
      stringstream br(data);
      string WordI, WordII, WordIII;
      if (data[0] == ' ')
      {
        int i = 0;
        WordI = ":)";
        pair<string, string> two;
        while (br >> wd)
        {
          if (i == 0)
            two.first = wd;
          else
            two.second = wd;
          i++;
        }
        WordII = two.first, WordIII = two.second;
        Code.push_back(make_tuple(WordI, WordII, WordIII));
      }
      else
      {
        int i = 0;
        pair<string, pair<string, string>> three;
        while (br >> wd)
        {
          if (i == 0)
            three.first = wd;
          else if (i == 1)
            three.second.first = wd;
          else
            three.second.second = wd;
          i++;
        }

        WordI = three.first, WordII = three.second.first, WordIII = three.second.second;
        Code.push_back(make_tuple(WordI, WordII, WordIII));
      }
    }
    myFile.close();
  }
  else
  {
    cout << "File is not found :(" << endl;
  }

  //for (auto it : Code)cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;

  /*Location Address and Sample Table*/
  vector<pair<string, string>> locationAddress;
  unordered_map<string, string> sampleTable;
  vector<pair<string, string>> sampleTableV;
  string startAddress = get<2>(Code[0]);
  string L, I;

  L = fill(startAddress), I = get<1>(Code[0]);
  locationAddress.push_back(make_pair(L, I));
  I = get<1>(Code[1]);
  locationAddress.push_back(make_pair(L, I));

  for (int i = 2; i < Code.size(); i++)
  {
    string a, b, inc, bt, val;

    a = locationAddress.back().first;
    bt = get<1>(Code[i - 1]) != "BASE" ? get<1>(Code[i - 1]) : get<1>(Code[i - 2]);
    val = get<1>(Code[i - 1]) != "BASE" ? get<2>(Code[i - 1]) : get<2>(Code[i - 2]);
    b = get_format(bt, val);
    inc = get<1>(Code[i]);
    //cout << a << " " << b << " " << inc << endl;
    if (inc == "BASE")
    {
      continue;
    }
    //cout << a << " " << b << " " << inc << endl;
    locationAddress.push_back(make_pair(fill(add(a, b)), inc));
  }

  //for (auto it : locationAddress) cout << it.first << " " << it.second << endl;

  for (int it = 0; it < Code.size(); it++)
  {
    if (get<0>(Code[it]) != ":)")
    {
      sampleTable[get<0>(Code[it])] = locationAddress[it - 1].first;
      sampleTableV.push_back(make_pair(get<0>(Code[it]), locationAddress[it - 1].first));
    }
  }

  //for (auto it : sampleTableV)cout << it.first << " " << it.second << endl;
}
