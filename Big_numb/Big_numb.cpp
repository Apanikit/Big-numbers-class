#include "Big_numb.h"

Big_numb::Big_numb(){
  sign = true;
  value.push_back(0);
}

Big_numb::Big_numb(std::string str_input){
  sign = true;
  *this = str_input;
}

Big_numb::Big_numb(long long int int_input){
  sign = true;
  *this = int_input;
}

Big_numb& Big_numb::operator =(Big_numb copy){
  value = copy.value;
  sign = copy.sign;
  return *this;
}

Big_numb& Big_numb::operator =(std::string str_input){
  value.clear();
  set_value(str_input);
  return *this;
}

Big_numb& Big_numb::operator =(long long int& int_input){
  value.clear();
  std::string str_input = std::to_string(int_input);
  set_value(str_input);
  return *this;
}

Big_numb Big_numb::operator +(const Big_numb& second) const{
  Big_numb res;
  if (sign && second.sign){
    res = plus(second);
    res.sign = true;
  }
  else if (!sign && !second.sign){
    res = plus(second);
    res.sign = false;
  }
  else{
    if (*this >= second){
      res = minus(second);
      res.sign = sign;
    }
    else{
      res = minus(second);
      res.sign = second.sign;
    }
  }
  return res;
}

Big_numb& Big_numb::operator +=(const Big_numb& second){
  *this = (*this + second);
  return *this;
}

Big_numb Big_numb::operator -(const Big_numb& second) const{
  Big_numb res;
  if (sign && second.sign){
    if (*this >= second){
      res = minus(second);
      res.sign = true;
    }
    else{
      res = minus(second);
      res.sign = false;
    }
  }
  else if (!sign && !second.sign){
    if (*this >= second){
      res = minus(second);
      res.sign = false;
    }
    else{
      res = minus(second);
      res.sign = true;
    }
  }
  else{
    if (sign){
      res = plus(second);
      res.sign = true;
    }
    else{
      res = plus(second);
      res.sign = false;
    }
  }
  return res;
}

Big_numb& Big_numb::operator -=(const Big_numb& second){
  *this = (*this - second);
  return *this;
}

Big_numb Big_numb::operator *(const Big_numb& second) const{
  Big_numb res;
  if (sign == second.sign){
    res = mult(second);
    res.sign = true;
  }
  else{
    res = mult(second);
    res.sign = false;
  }
  return res;
}

Big_numb& Big_numb::operator *=(const Big_numb& second){
  *this = (*this * second);
  return *this;
}

Big_numb Big_numb::operator /(const Big_numb& second) const{
  if (second == 0){
    exit(1);
  }
  
  Big_numb res;
  if (sign == second.sign){
    res = div(second);
    res.sign = true;
  }
  else{
    res = div(second);
    res.sign = false;
  }
  return res;
}

Big_numb& Big_numb::operator /=(const Big_numb& second){
  *this = (*this / second);
  return *this;
}

Big_numb& Big_numb::operator ++(){
  *this += 1;
  return (*this);
}

Big_numb Big_numb::operator ++(int crutch){
  Big_numb temp = *this;
  ++(*this);
  return temp;
}

Big_numb& Big_numb::operator --(){
  *this -= 1;
  return (*this);
}

Big_numb Big_numb::operator --(int crutch){
  Big_numb temp = *this;
  --(*this);
  return temp;
}

Big_numb& Big_numb::operator -(){
  if (sign){
    sign = false;
  }
  else{
    sign = true;
  }

  return *this;
}

bool Big_numb::operator <(const Big_numb& second) const{
  if (sign && second.sign){
    if (compare(second) == 0){
      return true;
    }
    else{
      return false;
    } 
  }
  else if (!sign && !second.sign){
    if (compare(second) == 2){
      return false;
    }
    else{
      return true;
    } 
  }
  else{
    if (!sign){
      return true;
    }
    else{
      return false;
    }
  }
}

bool Big_numb::operator <=(const Big_numb& second) const{
  if (sign && second.sign){
    if (!(compare(second) == 2)){
      return true;
    }
    else{
      return false;
    }
  }
  else if (!sign && !second.sign){
    if (!(compare(second) == 0)){
      return true;
    }
    else{
      return false;
    } 
  }
  else{
    if (!sign){
      return true;
    }
    else{
      return false;
    }
  }
}

bool Big_numb::operator ==(const Big_numb& second) const{
  if (sign == second.sign){
    if (compare(second) == 1){
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  } 
}

bool Big_numb::operator !=(const Big_numb& second) const{
  if (sign == second.sign){
    if (compare(second) == 1){
      return false;
    }
    else{
      return true;
    }
  }
  else{
    return true;
  }
}

bool Big_numb::operator >(const Big_numb& second) const{
  if (sign && second.sign){
    if (compare(second) == 2){
      return true;
    }
    else{
      return false;
    } 
  }
  if (!sign && !second.sign){
    if (compare(second) == 0){
      return true;
    }
    else{
      return false;
    }
  }
  else{
    if (sign){
      return true;
    }
    else{
      return false;
    }
  } 
}

bool Big_numb::operator >=(const Big_numb& second) const{
  if (sign && second.sign){
    if (!(compare(second) == 0)){
      return true;
    }
    else{
      return false;
    }
  }
  else if (!sign && !second.sign){
    if (!(compare(second) == 2)){
      return true;
    }
    else{
      return false;
    } 
  }
  else{
    if (sign){
      return true;
    }
    else{
      return false;
    }
  }
}

std::string Big_numb::to_str(){
  std::string res;

  if (!sign){
    res += "-";
  }

  res += std::to_string(value[0]);
  for (int i = 1; i < value.size(); i++){
    for (int j = 0; j < 8 - std::to_string(value[i]).size(); j++ ){
      res += "0";
    }
    res += std::to_string(value[i]);
  }
  return res;
}

void Big_numb::set_value(std::string input){
  int size = input.size();
  int actual_start = 0;
  for (int i = 0; i < size; i++ ){
    if (input[i] == '0'){
      actual_start++;
    }
    else if ((input[i] == '-') && (i == 0)){
      actual_start++;
      sign = false;
    }
    else if ((input[i] == '+') && (i == 0)){
      actual_start++;
      sign = true;
    }
    else{
      break;
    }
  }

  if (actual_start == size){
    input = "0";
    size = input.size();
  }
  else{
    input = input.substr(actual_start, size - actual_start);
    size = input.size();
    check(input);
  }

  int vect_size = size / 8;
  if (size % 8 > 0){
    vect_size++;
  }

  for (int i = 0; i < vect_size; i++){
    if (size % 8 > 0){
      value.push_back(atoi(input.substr(0, (size % 8)).c_str()));
      input = input.substr(size % 8);
      size = input.size() % 8;
    }
    else{
      value.push_back(atoi(input.substr(0, 8).c_str()));
      input = input.substr(8);
    }
  }
}

Big_numb Big_numb::plus(const Big_numb& second) const{
  if (value.size() >= second.value.size()){
    Big_numb res;
    res.value.clear();
    res.value = value;

    for (int i = 0; i < second.value.size(); i++ ){
      res.value[res.value.size() - (1 + i)] += second.value[second.value.size() - (1 + i)];
    }

    res.normalize();
    return res;
  }
  else{
    Big_numb res;
    res.value.clear();
    res.value = second.value;

    for (int i = 0; i < value.size(); i++ ){
      res.value[res.value.size() - (1 + i)] += value[value.size() - (1 + i)];
    }

    res.normalize();
    return res;
  }
}

Big_numb Big_numb::minus(const Big_numb& second) const{
  if (*this >= second){
    Big_numb res;
    res.value.clear();
    res.value = value;

    for (int i = 0; i < second.value.size(); i++ ){
      if (res.value[res.value.size() - (1 + i)] < second.value[second.value.size() - (1 + i)]){
        res.value[res.value.size() - (1 + i)] += 100000000;
        for (int j = 1; j < res.value.size(); j++){
          if (res.value[res.value.size() - (1 + i + j)] != 0){
            res.value[res.value.size() - (1 + i + j)]--;
            break;
          }
          else{
            res.value[res.value.size() - (1 + i + j)] = 99999999;
          }
        }
      }
      res.value[res.value.size() - (1 + i)] -= second.value[second.value.size() - (1 + i)];
    }

    res.normalize();
    return res;
  }
  else{
    Big_numb res;
    res.value.clear();
    res.value = second.value;

    for (int i = 0; i < value.size(); i++ ){
      if (res.value[res.value.size() - (1 + i)] < value[value.size() - (1 + i)]){
        res.value[res.value.size() - (1 + i)] += 100000000;
        for (int j = 1; j < res.value.size(); j++){
          if (res.value[res.value.size() - (1 + i + j)] != 0){
            res.value[res.value.size() - (1 + i + j)]--;
            break;
          }
          else{
            res.value[res.value.size() - (1 + i + j)] = 99999999;
          }
        }
      }
      res.value[res.value.size() - (1 + i)] -= value[value.size() - (1 + i)];
    }

    res.normalize();
    return res;
  }
}

Big_numb Big_numb::mult(const Big_numb& second) const{
  Big_numb res;
  Big_numb temp;

  for (int i = 0; i < second.value.size(); i++){
    temp.value.clear();
    for (int j = 0; j < value.size(); j++){
      temp.value.push_back(value[j] * second.value[i]);
    }
    for (int j = 0; j < second.value.size() - (i + 1); j++){
      temp.value.push_back(0);
    }
    temp.normalize();
    res += temp;
  }

  res.normalize();
  return res;
}

Big_numb Big_numb::div(const Big_numb& second) const{
  Big_numb this_module = *this;
  this_module.sign = true;
  Big_numb second_module = second;
  second_module.sign = true;
  Big_numb res;
  Big_numb copy = this_module;

  if (this_module >= second_module){
    Big_numb size;
    Big_numb temp = second_module;

    while(true){
      temp *= 10;
      if (temp <= this_module){
        size++;
      }
      else{
        break;
      }
    }

    for (Big_numb i = size; i > -1; i--){
      res *= 10;
      Big_numb base = second_module;
      base.sign = true;
      int add = 0;

      for (Big_numb j = 0; j < i; j++){
        base *= 10;
      }
      temp = base;

      while(true){
        if (temp <= copy){
          add++;
          temp += base;
        }
        else{
          break;
        }
      }
      res += add;
      copy -= (temp - base);
    }
  }

  return res;
}

void Big_numb::normalize(){
  int number_size = value.size();
  for (int i = 0; i < number_size; i++){
    int temp = 0;
    if (value[number_size-(i+1)] / 100000000 > 0){
      temp = value[number_size-(i+1)] / 100000000;
      value[number_size-(i+1)] = value[number_size-(i+1)] % 100000000;
    }
    if (temp > 0){
      if (i == (number_size - 1)){
        auto iter = value.cbegin(); 
        value.insert(iter + 0, temp);
      }
      else{
        value[number_size-(i+2)] += temp;
      }
    }
  }

  for (int i = 0; i < value.size(); i++){
    if (value[i] == 0){
      value.erase(value.begin());
    }
    else{
      break;
    }
  }
}

int Big_numb::compare(const Big_numb& second) const{
  if (value.size() == second.value.size()){
    for (int i = 0; i < value.size(); i++){
      if (value[i] > second.value[i]){
        return 2;
      }
      else if (value[i] < second.value[i]){
        return 0;
      }
    }
    return 1;
  }
  else if (value.size() > second.value.size()){
    return 2;
  }
  else{
    return 0;
  }
}

void Big_numb::check(std::string input){
  int temp = 0;
  if (!sign){
    temp++;
  }
  for (int i = temp; i < input.size(); i++){
    for (int j = 0; j < 10; j++){
      if (input[i] == char(j + 48)){
        break;
      }
      if (j == 9){ 
        exit(1);
      }
    }
  }
}

std::ostream& operator<<(std::ostream& os, Big_numb numb){
  os << numb.to_str();

  return os; 
}

std::istream& operator>>(std::istream& is, Big_numb& numb){
  std::string str;
  is >> str;
  numb = str;

  return is; 
}