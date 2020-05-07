#include <iostream>

class Hoge {

public:
  int value { 0 };
  
  explicit Hoge(int value) : value(value) { std::cout << "hoge " << value << " constructed\n"; }
  ~Hoge() { std::cout << "hoge " << value << " destructed\n"; }

  Hoge(Hoge &&other)
  {
    std::cout << "hoge " << value << " move constructed " << other.value << "\n";
    this->value = other.value;
  }    

  Hoge(Hoge &other) //　コピーコンストラクタがないとなぜかCreateHoge3() のreturnでエラーになるので、とりあえず書いておく
  {
    std::cout << "hoge " << value << " copy constructed " << other.value << "\n";
    this->value = other.value;
  }
    

  Hoge &operator=(Hoge &&other)
  {
    std::cout << "hoge " << value << " moved " << other.value << " by copy\n";
    this->value = other.value;
    return *this;
  }
};

// この関数の戻り値の代入時にMoveコンストラクタが動いて欲しい
Hoge CreateHoge3(int value) // Hoge&& にしなくていい。おのずと右辺値になる
{
  Hoge hoge(value);
  return hoge; // 普通にリターンするだけ
}
      

int main()
{
  Hoge h(0);
  std::cout << h.value << "\n";

  h = CreateHoge3(100);
  std::cout << h.value << "\n";

  Hoge r(std::move(h));
  std::cout << r.value << "\n";
}


// こっちの場合はコピーコンストラクタもムーヴコンストラクタも動かない
// 最適化が原因
// int main()
// {
//   Hoge h(CreateHoge3(100));
//   std::cout << h.value << "\n";
// }	 
    
