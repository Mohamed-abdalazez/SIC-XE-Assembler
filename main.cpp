#include <bits/stdc++.h>
using namespace std;

/**
 *
 * Project : SIC/XE Machine Architecture 
 * author  : Mohamed Abdalazez Abdallah Mohamed
 *
**/

int Base = 0;
string B = "", lastAddress;

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

int Format(string mnem)
{
  map<string, int> r;
  r["ADD"] = 3;
  r["ADDF"] = 3;
  r["ADDR"] = 2;
  r["AND"] = 3;
  r["CLEAR"] = 2;
  r["COMP"] = 3;
  r["COMPF"] = 3;
  r["COMPR"] = 2;
  r["DIV"] = 3;
  r["DIVF"] = 3;
  r["DIVR"] = 2;
  r["FIX"] = 1;
  r["FLOAT"] = 1;
  r["HIO"] = 1;
  r["J"] = 3;
  r["JEQ"] = 3;
  r["JGT"] = 3;
  r["JLT"] = 3;
  r["JSUB"] = 3;
  r["LDA"] = 3;
  r["LDB"] = 3;
  r["LDCH"] = 3;
  r["LDF"] = 3;
  r["LDL"] = 3;
  r["LDS"] = 3;
  r["LDT"] = 3;
  r["LDX"] = 3;
  r["LPS"] = 3;
  r["MUL"] = 3;
  r["MULF"] = 3;
  r["MULR"] = 2;
  r["NORM"] = 1;
  r["OR"] = 3;
  r["RD"] = 3;
  r["RMO"] = 2;
  r["RSUB"] = 3;
  r["SHIFTL"] = 2;
  r["SHIFTR"] = 2;
  r["SIO"] = 1;
  r["SSK"] = 3;
  r["STA"] = 3;
  r["STB"] = 3;
  r["STCH"] = 3;
  r["STF"] = 3;
  r["STI"] = 3;
  r["STL"] = 3;
  r["STS"] = 3;
  r["STSW"] = 3;
  r["STT"] = 3;
  r["STX"] = 3;
  r["SUB"] = 3;
  r["SUBF"] = 3;
  r["SUBR"] = 2;
  r["SVC"] = 2;
  r["TD"] = 3;
  r["TIO"] = 1;
  r["TIX"] = 3;
  r["TIXR"] = 2;
  r["WD"] = 3;

  bool f = false;
  for (auto it : r)
    if (it.first == mnem)
      f = true;

  int format;
  format = f ? r[mnem] : -1;
  return format;
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

string HexToBin(string hex)
{
  int i = 0;
  while (hex[i])
  {
    switch (hex[i])
    {
    case '0':
      return "0000";
      break;
    case '1':
      return "0001";
      break;
    case '2':
      return "0010";
      break;
    case '3':
      return "0011";
      break;
    case '4':
      return "0100";
      break;
    case '5':
      return "0101";
      break;
    case '6':
      return "0110";
      break;
    case '7':
      return "0111";
      break;
    case '8':
      return "1000";
      break;
    case '9':
      return "1001";
      break;
    case 'A':
    case 'a':
      return "1010";
      break;
    case 'B':
    case 'b':
      return "1011";
      break;
    case 'C':
    case 'c':
      return "1100";
      break;
    case 'D':
    case 'd':
      return "1101";
      break;
    case 'E':
    case 'e':
      return "1110";
      break;
    case 'F':
    case 'f':
      return "1111";
      break;
    default:
      return "-1";
    }
    i++;
  }
  return "-1";
}

string string_to_hex(string input)
{
  static const char hex_digits[] = "0123456789ABCDEF";

  std::string output;
  output.reserve(input.length() * 2);
  for (unsigned char c : input)
  {
    output.push_back(hex_digits[c >> 4]);
    output.push_back(hex_digits[c & 15]);
  }
  return output;
}

string add(string str, string adder)
{
  int num1 = H_TO_D(str);
  int num2 = H_TO_D(adder);
  int sum = num1 + num2;
  return D_TO_H(sum);
}

string sub(string str, string adder)
{
  int num1 = H_TO_D(str);
  int num2 = H_TO_D(adder);
  int sum = num1 - num2;
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

bool ifIndexed(string s)
{
  int n = s.size();
  return s[n - 2] == ',' ? true : false;
}

bool ifImmediate(string s) // #
{
  return s[0] == '#' ? true : false;
}

bool ifIndirect(string s) // @
{
  return s[0] == '@' ? true : false;
}

bool isNumber(string s)
{
  bool num = true;
  for (auto it : s)
    if (!isdigit(it))
      num = false;
  return num ? true : false;
}

string getNumberOfRegister(char reg)
{
  if (reg == 'A')
    return "0";
  if (reg == 'X')
    return "1";
  if (reg == 'L')
    return "2";
  if (reg == 'B')
    return "3";
  if (reg == 'S')
    return "4";
  if (reg == 'T')
    return "5";
  if (reg == 'F')
    return "6";
  return "-1";
}

string Setnixbpe(string mnem, string ref, string nixbpe)
{
  //string nixbpe = "000000";
  if (mnem[0] == '+')
  {
    //set nixbpe
    nixbpe[5] = '1';
    if (ifImmediate(ref))
      nixbpe[1] = '1';
    else if (ifIndirect(ref))
      nixbpe[0] = '1';
    else
      nixbpe[0] = '1', nixbpe[1] = '1';
    if (ifIndexed(ref))
      nixbpe[2] = '1';
    return nixbpe;
  }
  else
  {
    if (ifImmediate(ref))
      nixbpe[1] = '1';
    else if (ifIndirect(ref))
      nixbpe[0] = '1';
    else
      nixbpe[0] = '1', nixbpe[1] = '1';
    if (ifIndexed(ref))
      nixbpe[2] = '1';
    return nixbpe;
  }
}

string getFirstPartOb(string nixbpe, string ins, string opCode)
{
  string objectCode = "", temp = "", opCode_1 = "";
  objectCode = opCode[0];
  opCode_1 = opCode[1];
  //cout << opCode_1 << endl;
  temp = HexToBin(opCode_1);
  temp.pop_back(), temp.pop_back();
  temp += nixbpe[0], temp += nixbpe[1];
  //cout << temp << endl;
  int tempNum = stoi(temp, 0, 2);
  objectCode += D_TO_H(tempNum);
  temp = "";
  temp += nixbpe[2], temp += nixbpe[3], temp += nixbpe[4], temp += nixbpe[5];
  tempNum = stoi(temp, 0, 2);
  objectCode += D_TO_H(tempNum);
  return objectCode;
}

int main()
{
  /*Read From File*/
  ifstream myFile("inSICXE.txt");
  string data, wd;
  vector<tuple<string, string, string>> Code;
  deque<int> Base_indices;
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
  map<string, string> MapLocationAddress;

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
      Base = i;
      B = get<2>(Code[i]);
      continue;
    }
    //cout << a << " " << b << " " << inc << endl;
    locationAddress.push_back(make_pair(fill(add(a, b)), inc));
    lastAddress = add(a, b);
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

  /*Object Code*/

  vector<tuple<string, string, string>> locInstRef, O;
  vector<pair<string, string>> objectCode;

  int pc = 0;

  for (int i = 0, j = 0; i < locationAddress.size(); i++)
  {
    if (get<1>(Code[i]) == "BASE")
    {
      continue;
    }
    locInstRef.push_back(make_tuple(locationAddress[j].first, get<1>(Code[i]), get<2>(Code[i])));
    j++;
  }

  //for (auto it : locInstRef)cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;

  for (int it = 0; it < locInstRef.size(); it++)
  {
    string ins = "", nixbpe = "000000", ObCode = "";
    for (auto i : get<1>(locInstRef[it]))
      if (i != '+')
        ins += i;
    nixbpe = Setnixbpe(get<1>(locInstRef[it]), get<2>(locInstRef[it]), nixbpe);
    if (get<1>(locInstRef[it])[0] == '+')
    {
      string without = "";
      for (auto it : get<2>(locInstRef[it]))
      {
        if (it != '@' && it != '#')
          without += it;
      }
      ObCode += getFirstPartOb(nixbpe, ins, opTab(ins));
      if (isNumber(without))
      {
        string value = D_TO_H(stoi(without));
        int sz = value.size();
        sz = 5 - sz;
        while (sz--)
        {
          value = '0' + value;
        }
        ObCode += value;
      }
      else
      {
        string value = sampleTable[without];
        int sz = value.size();
        sz = 5 - sz;
        while (sz--)
        {
          value = '0' + value;
        }
        ObCode += value;
      }

      //objectCode.push_back(make_pair(get<1>(locInstRef[it]), ObCode));
      O.push_back({get<0>(locInstRef[it]), get<1>(locInstRef[it]), ObCode});
    }
    else
    {
      if (Format(get<1>(locInstRef[it])) == -1)
      {
        if (get<1>(locInstRef[it]) == "RESW" || get<1>(locInstRef[it]) == "RESB")
        {
          ObCode = "no object code";
          //objectCode.push_back(make_pair(get<1>(locInstRef[it]), ObCode));
          O.push_back({get<0>(locInstRef[it]), get<1>(locInstRef[it]), ObCode});
        }
        else if (get<1>(locInstRef[it]) == "BYTE")
        {
          if (get<2>(locInstRef[it])[0] == 'X')
          {
            for (int i = 2; i < get<2>(locInstRef[it]).size() - 1; i++)
              ObCode += get<2>(locInstRef[it])[i];
            objectCode.push_back(make_pair(get<1>(locInstRef[it]), ObCode));
            O.push_back({get<0>(locInstRef[it]), get<1>(locInstRef[it]), ObCode});
          }
          else
          {

            for (int i = 2; i < get<2>(locInstRef[it]).size() - 1; i++)
            {
              string ascii = "";
              ascii += get<2>(locInstRef[it])[i];
              ObCode += string_to_hex(ascii);
            }
            //objectCode.push_back(make_pair(get<1>(locInstRef[it]), ObCode));
            O.push_back({get<0>(locInstRef[it]), get<1>(locInstRef[it]), ObCode});
          }
        }
      }
      else if (Format(get<1>(locInstRef[it])) == 2)
      {
        ObCode += opTab(get<1>(locInstRef[it]));
        for (auto it : get<2>(locInstRef[it]))
        {
          if (it != ',')
            ObCode += getNumberOfRegister(it);
        }
        int sz = ObCode.size();
        sz = 4 - sz;
        while (sz--)
          ObCode += '0';
        //objectCode.push_back(make_pair(get<1>(locInstRef[it]), ObCode));
        O.push_back({get<0>(locInstRef[it]), get<1>(locInstRef[it]), ObCode});
      }
      else if (Format(get<1>(locInstRef[it])) == 1)
      {
        // later on
        ;
      }
      else
      {
        string without = "";
        for (auto it : get<2>(locInstRef[it]))
        {
          if (it != '@' && it != '#' && it != ',')
            without += it;
          if (it == ',')
            break;
        }

        ObCode += getFirstPartOb(nixbpe, ins, opTab(ins));
        if (isNumber(without))
        {
          ObCode.pop_back();
          int sz = 4 - without.size();
          while (sz--)
          {
            without = '0' + without;
          }
          ObCode += without;
          //objectCode.push_back(make_pair(get<1>(locInstRef[it]), ObCode));
          O.push_back({get<0>(locInstRef[it]), get<1>(locInstRef[it]), ObCode});
        }
        else
        {
          ObCode = "";
          string TA = "", PC = "", disp = "";
          TA = sampleTable[without];
          PC = (it > Base ? get<0>(locInstRef[it]) : get<0>(locInstRef[it + 1]));

          long long ta = H_TO_D(TA);
          long long pc = H_TO_D(PC);
          long long dis = ta - pc;

          if (dis >= -2048 && dis <= 2047)
          {
            disp = D_TO_H(dis);
            nixbpe[4] = '1';
            nixbpe = Setnixbpe(get<1>(locInstRef[it]), get<2>(locInstRef[it]), nixbpe);
          }
          else
          {
            disp = sub(TA, sampleTable[B]);
            nixbpe[3] = '1';
            nixbpe = Setnixbpe(get<1>(locInstRef[it]), get<2>(locInstRef[it]), nixbpe);
          }

          ObCode += getFirstPartOb(nixbpe, ins, opTab(ins));
          int SZ = 3 - disp.size();
          if (3 > disp.size())
            while (SZ--)
              disp = '0' + disp;
          if (disp[0] == disp[1] && disp[1] == 'f')
          {
            string temp = "";
            temp = disp[disp.size() - 1] + temp;
            temp = disp[disp.size() - 2] + temp;
            temp = disp[disp.size() - 3] + temp;
            disp = temp;
          }
          ObCode += disp;
          //objectCode.push_back(make_pair(get<1>(locInstRef[it]), ObCode));
          O.push_back({get<0>(locInstRef[it]), get<1>(locInstRef[it]), ObCode});
        }
      }
    }
  }

  //for (auto it : objectCode){cout << it.first << " " << it.second << endl;}
  //for (auto it : O) cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;

  /*Head Text End (HTE) Record*/

  //Head Record
  string lengthAllProgram, nameOfProgram, headRecord = "";
  lengthAllProgram = sub(get<0>(O[O.size() - 1]), startAddress);
  nameOfProgram = get<0>(Code[0]);
  headRecord = "H   " + nameOfProgram + "   " + startAddress + "   " + lengthAllProgram;

  //Text Record
  vector<string> Ts;
  deque<string> loc;
  string textRecord = "", obj = "";
  for (int i = 0; i < O.size(); i++)
  {
    loc.push_back(get<0>(O[i]));
    if (i == O.size() - 1)
    {
      //cout << loc.front() << " " << lastAddress << endl;
      obj += get<2>(O[i]); // no goto else
      textRecord = "T   " + loc.front() + "   " + sub(lastAddress, loc.front()) + "   " + obj;
      Ts.push_back(textRecord);
      textRecord = "", obj = "";
      loc.clear();
    }
    if (get<1>(O[i]) == "RESW" || get<1>(O[i]) == "RESB")
    {
      textRecord = "T   " + loc.front() + "   " + sub(loc.back(), loc.front()) + "   " + obj;
      if (sub(loc.back(), loc.front()) != "0")
        Ts.push_back(textRecord);
      textRecord = "", obj = "";
      loc.clear();
    }
    else
    {
      obj += get<2>(O[i]);
    }
  }
  // End Record
  string End = "E   ";
  End += nameOfProgram;

  // print HTE Record
  cout << headRecord << endl;
  for (auto it : Ts)
    cout << it << endl;
  cout << End << endl;
  return 0;
}
