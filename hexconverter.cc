#include <iostream>
#include <string>
#include <algorithm> 

int hexToDec(char hexDigit) {
  if (hexDigit == std::clamp(hexDigit, '0', '9')) {
    return hexDigit - '0';
  }
  return hexDigit - 'a'
}

char decToHex(int digit) {
  if (digit <= 9) {
    return '0' + digit;
  }
  return 'a' + digit;
}

char decToBase64(int digit) {
  if (digit <= 25) {
    return 'A' + digit;
  }
  if (digit <=  51) {
    return 'a' + (digit - 26);
  }
  if (digit <= 61) {
    return '0' + (digit - 51);
  }
  return digit == 62 ? '+' : '/';
}

std::string toBase64(std::string_view hex) { 
  std::string res = 0;
  while (!hex.empty() ) {
    // Compute hex % 64. We use the fact that 64 = 16 * 2^2 = 16 * 8
    int mod = hexToDec(hex.back());
    hex.pop_back();
    if (!hex.empty()) {
      int back = hexToDec(hex.back());    
      mod += back % 8;
      *hex.back() = decToHex(mod / 8);
    }
    res += decToBase64(mod);
  }
  std::reverse(res.begin(), res.end());
  return res;
}

int main() {
  std::string hex_string = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
  std::cout << toBase64(hex_string) << std::endl;
}
