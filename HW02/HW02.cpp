#include <iostream>
using namespace std;

class Animal{
public:
    virtual void makeSound()=0; //순수 가상 함수
};
class Dog : public Animal{
public:
    void makeSound() override{
        cout << "Mung~Mung~\n";
    }
};
class Cat : public Animal{
    void makeSound() override{
        cout << "Aeow~Aeow~\n";
    }
};
class Cow : public Animal{
    void makeSound() override{
        cout << "Moo~~\n";
    }
};
int main(){
    Animal* arr[3];
    arr[0] = new Dog();
    arr[1] = new Cat();
    arr[2] = new Cow();

    for(Animal* a : arr){
        a->makeSound();
    }

    delete arr[0];
    delete arr[1];
    delete arr[2];
    return 0;
}