#include <string>

std::string xor(std::string_view a, std::string_view b) {
  auto ait = a.begin();
  auto bit = b.begin();
  std::string res;
  while (ait != a.end() && bit != b.end()) {
    res.push_back((*ait) ^ (*bit));
    ait++; bit++;
  }
}

int main() {
  std::string a = "1c0111001f010100061a024b53535009181c";
  std::string b = "686974207468652062756c6c277320657965";
  std::cout << xor(a, b) << std::endl;
}
