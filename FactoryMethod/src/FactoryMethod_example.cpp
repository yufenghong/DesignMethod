/*
 * @Author: hongyf
 * @Date: 2021-12-24 14:16:59
 * @LastEditors: hongyf
 * @LastEditTime: 2021-12-24 15:50:59
 * @Description: 请填写简介
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class A_basic {
   public:
    virtual void name() = 0;
};
class B_basic {
   public:
    virtual void name() = 0;
};
class A1_product : public A_basic {
   public:
    void name() {
        cout << "A1_product" << endl;
    }
};
class A2_product : public A_basic {
   public:
    void name() {
        cout << "A2_product" << endl;
    }
};
class B1_product : public B_basic {
   public:
    void name() {
        cout << "B1_product" << endl;
    }
};

template <class X_basic>
class interface_basic {
   public:
    virtual X_basic* CreateProduct() = 0;
};

template <class X_basic>
class factory {
   public:
    static factory<X_basic>& instance() {
        static factory<X_basic> instance;
        return instance;
    }

    void ProductRegister(interface_basic<X_basic>* interface, string key) {
        lib[key] = interface;
    }

    X_basic* getproduct(string key) {
        return lib[key]->CreateProduct();
    }

   private:
    map<string, interface_basic<X_basic>*> lib;
};

template <class X_basic, class X_product>
class interface : public interface_basic<X_basic> {
   public:
    interface(string product_key) {
        factory<X_basic>::instance().ProductRegister(this, product_key);
    }
    X_basic* CreateProduct() {
        return new X_product();
    }
};

int main() {
    interface<A_basic, A1_product> A1_interface("A1");
    interface<A_basic, A2_product> A2_interface("A2");

    A_basic* A1_pro = factory<A_basic>::instance().getproduct("A1");
    A_basic* A2_pro = factory<A_basic>::instance().getproduct("A2");
    A1_pro->name();
    A2_pro->name();

    return 0;
}