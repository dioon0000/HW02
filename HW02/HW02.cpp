#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//======================================================================================================
//필수 기능
class Animal{
public:
    virtual void makeSound()=0; //순수 가상 함수
    ~Animal(){};
};
class Dog: public Animal{
public:
    void makeSound() override{
        cout << "Mung- Mung-\n";
    }
};
class Cat: public Animal{
    void makeSound() override{
        cout << "Aeow- Aeow-\n";
    }
};
class Cow: public Animal{
    void makeSound() override{
        cout << "Moo-\n";
    }
};
//======================================================================================================
//도전기능
class Zoo {
private:
    Animal* animals[10] = { nullptr, }; // 동물 객체를 저장하는 포인터 배열 선언 및 초기화
    int idx = 0;
public:
    // TODO: 동물을 동물원에 추가하는 함수
    // - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
    // - 같은 동물이라도 여러 번 추가될 수 있습니다.
    // - 입력 매개변수: Animal* (추가할 동물 객체)
    // - 반환값: 없음
    void addAnimal(Animal* animal) {
        if(idx < 10)
            animals[idx++] = animal;
    }

    // TODO: 동물원에 있는 모든 동물의 행동을 수행하는 함수
    // - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    void performActions() {
        for(int i=0; i<idx; ++i)
            animals[i]->makeSound();
    }

    // TODO: Zoo 소멸자
    // - Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
    // - 메모리 누수를 방지하기 위해 동적 할당된 Animal 객체를 `delete` 합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    ~Zoo() {
        for(int i=0; i<idx; ++i)
            delete animals[i];
    }
};
// TODO: 랜덤 동물을 생성하는 함수
// - 0, 1, 2 중 하나의 난수를 생성하여 각각 Dog, Cat, Cow 객체 중 하나를 동적으로 생성합니다.
// - 생성된 객체는 Animal 타입의 포인터로 반환됩니다.
// - 입력 매개변수: 없음
// - 반환값: Animal* (생성된 동물 객체의 포인터)
Animal* createRandomAnimal(){
    int x = rand()%3;
    switch(x){
    case 0: return new Dog();
    case 1: return new Cat();
    case 2: return new Cow();
    default: return nullptr;
    }
}

int main(){
    //필수기능
    Animal* animal[3]; //포인터 배열 선언
    //각 클래스의 자료형 변수를 선언하고 배열에 저장
    Dog dog;
    Cat cat;
    Cow cow;
    animal[0] = &dog;
    animal[1] = &cat;
    animal[2] = &cow;
    cout << "필수기능: Animal배열 순회하며 각 동물의 울음소리 출력\n";
    cout << "========================================================================================================\n";
    //Animal 배열을 순회하면서 동물의 울음소리를 냄
    for(Animal* a : animal){
        a->makeSound();
    }
    cout << "========================================================================================================\n";
    cout << "도전기능: 랜덤 동물을 5마리 생성해 Zoo 클래스의 멤버변수 animals 포인터 배열에 넣은 뒤 울음소리 출력\n";
    //도전기능
    srand(time(0)); //난수를 만들어 주기 위한 부분
    Zoo zoo;
    //5마리의 동물 랜덤 생성
    for(int i=0; i<5; ++i)
        zoo.addAnimal(createRandomAnimal());
    //Zoo 클래스의 멤버변수 animals의 저장된 동물들의 울음소리 출력
    zoo.performActions();
    return 0;
}