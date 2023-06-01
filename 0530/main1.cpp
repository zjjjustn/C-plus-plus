#include <iostream>
#include <variant>

using namespace std;

using p_type = std::variant<int,string,double>;

struct PrintVisitor {
  void operator()(int i) { cout << "int: " << i << '\n'; }
  void operator()(double f) { cout << "float: " << f << '\n'; }
  void operator()(const std::string& s) { cout << "str: " << s << '\n'; }
};

p_type test(p_type &v)
{
    if(std::holds_alternative<int>(v))
    {
        //cout << std::get<int>(v) << endl;
        cout << v.index() << endl;
        cout << std::get<0>(v) << endl;
    }
    else if(std::holds_alternative<double>(v))
    {
        cout << v.index() << endl;
        cout << std::get<2>(v) << endl;
    }
    else if(std::holds_alternative<string>(v))
    {
        cout << v.index() << endl;
        cout << std::get<1>(v) << endl;
    }

    return v;
}

int main()
{
    auto func2 = [](auto &temp){
       cout << temp << endl;
    };
    std::variant<int,string,double> v;
    v = 1;
    std::visit(func2,v);
    std::visit(PrintVisitor(),v);
    v = "hello";
    std::visit(func2,v);
    std::visit(PrintVisitor(),v);
    v = 1.234;
    std::visit(func2,v);
    std::visit(PrintVisitor(),v);


    std::variant<int, double, string> value = 1.0;
       std::visit(
       [&](auto &&arg) {
        using T = std::decay_t<decltype(arg)>; // 类型退化，去掉类型中的const 以及 &
        if constexpr(std::is_same_v<T,int>) {
          cout << "int: " << arg << '\n';
        } else if constexpr(std::is_same_v<T,double>){
          cout<< "float: "<< arg <<'\n';
        } else if constexpr(std::is_same_v<T,std::string>){
          cout<< "str: "<< arg <<'\n';
        }
       }, value);

    return 0;
}