#pragma once
#include <string>
#include <vector>
#include <cstdlib>

class Big_numb{
public:
  Big_numb();
  Big_numb(std::string str_input);
  Big_numb(long long int int_input);
  
  Big_numb& operator =(Big_numb copy);
  Big_numb& operator =(std::string str_input);
  Big_numb& operator =(long long int& int_input);
  
  Big_numb operator +(const Big_numb& second) const;
  Big_numb& operator +=(const Big_numb& second);
  
  Big_numb operator -(const Big_numb& second) const;
  Big_numb& operator -=(const Big_numb& second);

  Big_numb operator *(const Big_numb& second) const;
  Big_numb& operator *=(const Big_numb& second);

  Big_numb operator /(const Big_numb& second) const;
  Big_numb& operator /=(const Big_numb& second);

  Big_numb& operator ++();
  Big_numb operator ++(int crutch);

  Big_numb& operator --();
  Big_numb operator --(int crutch);

  Big_numb& operator -();

  bool operator <(const Big_numb& second) const;
  bool operator <=(const Big_numb& second) const;
  bool operator ==(const Big_numb& second) const;
  bool operator !=(const Big_numb& second) const;
  bool operator >(const Big_numb& second) const;
  bool operator >=(const Big_numb& second) const;

  std::string to_str();

private:
  std::vector<long long int> value;
  bool sign;

  void set_value(std::string input);

  Big_numb plus(const Big_numb& second) const;
  Big_numb minus(const Big_numb& second) const;
  Big_numb mult(const Big_numb& second) const;
  Big_numb div(const Big_numb& second) const;

  void normalize();

  int compare(const Big_numb& second) const;

  void check(std::string input);

};

std::ostream& operator<<(std::ostream& os, Big_numb numb);
std::istream& operator>>(std::istream& is, Big_numb& numb);