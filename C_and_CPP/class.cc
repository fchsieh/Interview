#include <bits/stdc++.h>
using namespace std;

class Animal {
   protected:
    void protectedMethod() { cout << "protectedMethod" << endl; }

   private:
    string secret = "I am a secret of Animal";

   public:
    string name;
    int age;
    Animal(string name, int age) : name(name), age(age) {}

    void eat() { cout << "Animal is eating" << endl; }
    // demo of virtual function
    virtual void print() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    // demo of friend class and friend function
    friend class Cat;
    friend void printSecret(Animal animal);
};

// declare friend function outside class
void printSecret(Animal animal) {
    cout << "Friend function using private var: " << animal.secret << endl;
}

// Deriving from Animal
class Dog : public Animal {
   public:
    Dog(string name, int age) : Animal(name, age) {}
    // Overriding virtual function
    void print() { cout << "Overriding print" << endl; }
    void eat() { cout << "Dog is eating" << endl; }
};

class Cat : public Animal {
   public:
    Cat(string name, int age) : Animal(name, age) {}
    void print_secret() { cout << secret << endl; }
    void access_protected_method() { protectedMethod(); }
};

int main() {
    Animal* dog;
    Dog d = Dog("Dog", 10);
    dog = &d;  // point to derived class

    cout << "==== Demo of a virtual function ====" << endl;
    // virtual function, binded at runtime -> Overriding print
    dog->print();
    // non-virtual function, binded at compile time -> Not overriding
    dog->eat();

    cout << "==== Demo of a friend class ====" << endl;
    Cat c = Cat("Cat", 5);
    c.print_secret();  // cat can access private member of animal

    cout << "==== Demo of a friend function ====" << endl;
    printSecret(c);  // friend function can access private member of animal

    cout << "==== Demo of a protected method ====" << endl;
    // c.protectedMethod();  error: cannot directly access protected member
    c.access_protected_method();  // but can access via a public method

    return 0;
}