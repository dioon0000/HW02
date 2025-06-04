#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//======================================================================================================
//�ʼ� ���
class Animal{
public:
    virtual void makeSound()=0; //���� ���� �Լ�
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
//�������
class Zoo {
private:
    Animal* animals[10] = { nullptr, }; // ���� ��ü�� �����ϴ� ������ �迭 ���� �� �ʱ�ȭ
    int idx = 0;
public:
    // TODO: ������ �������� �߰��ϴ� �Լ�
    // - Animal ��ü�� �����͸� �޾� ������ �迭�� �����մϴ�.
    // - ���� �����̶� ���� �� �߰��� �� �ֽ��ϴ�.
    // - �Է� �Ű�����: Animal* (�߰��� ���� ��ü)
    // - ��ȯ��: ����
    void addAnimal(Animal* animal) {
        if(idx < 10)
            animals[idx++] = animal;
    }

    // TODO: �������� �ִ� ��� ������ �ൿ�� �����ϴ� �Լ�
    // - ��� ���� ��ü�� ���� ���������� �Ҹ��� ���� �����̴� ������ �����մϴ�.
    // - �Է� �Ű�����: ����
    // - ��ȯ��: ����
    void performActions() {
        for(int i=0; i<idx; ++i)
            animals[i]->makeSound();
    }

    // TODO: Zoo �Ҹ���
    // - Zoo ��ü�� �Ҹ�� ��, ���� ���Ϳ� ����� ��� ���� ��ü�� �޸𸮸� �����մϴ�.
    // - �޸� ������ �����ϱ� ���� ���� �Ҵ�� Animal ��ü�� `delete` �մϴ�.
    // - �Է� �Ű�����: ����
    // - ��ȯ��: ����
    ~Zoo() {
        for(int i=0; i<idx; ++i)
            delete animals[i];
    }
};
// TODO: ���� ������ �����ϴ� �Լ�
// - 0, 1, 2 �� �ϳ��� ������ �����Ͽ� ���� Dog, Cat, Cow ��ü �� �ϳ��� �������� �����մϴ�.
// - ������ ��ü�� Animal Ÿ���� �����ͷ� ��ȯ�˴ϴ�.
// - �Է� �Ű�����: ����
// - ��ȯ��: Animal* (������ ���� ��ü�� ������)
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
    //�ʼ����
    Animal* animal[3]; //������ �迭 ����
    //�� Ŭ������ �ڷ��� ������ �����ϰ� �迭�� ����
    Dog dog;
    Cat cat;
    Cow cow;
    animal[0] = &dog;
    animal[1] = &cat;
    animal[2] = &cow;
    cout << "�ʼ����: Animal�迭 ��ȸ�ϸ� �� ������ �����Ҹ� ���\n";
    cout << "========================================================================================================\n";
    //Animal �迭�� ��ȸ�ϸ鼭 ������ �����Ҹ��� ��
    for(Animal* a : animal){
        a->makeSound();
    }
    cout << "========================================================================================================\n";
    cout << "�������: ���� ������ 5���� ������ Zoo Ŭ������ ������� animals ������ �迭�� ���� �� �����Ҹ� ���\n";
    //�������
    srand(time(0)); //������ ����� �ֱ� ���� �κ�
    Zoo zoo;
    //5������ ���� ���� ����
    for(int i=0; i<5; ++i)
        zoo.addAnimal(createRandomAnimal());
    //Zoo Ŭ������ ������� animals�� ����� �������� �����Ҹ� ���
    zoo.performActions();
    return 0;
}