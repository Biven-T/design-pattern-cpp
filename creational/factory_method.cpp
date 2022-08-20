#include <iostream>
#include <string>

//抽象食物类
class Food
{
public:
    virtual ~Food() {}
    virtual std::string FoodName() const = 0;
};

//具体的面包食物
class Bread : public Food
{
public:
    std::string FoodName() const override
    {
        return "面包";
    }
};

//具体的馒头食物
class Mantou : public Food
{
public:
    std::string FoodName() const override
    {
        return "馒头";
    }
};

//创造者
class Creator
{
public:
    virtual ~Creator() {}
    virtual Food *FactoryMethod() const = 0;
    std::string MakeFood() const
    {
        Food *food = this->FactoryMethod();
        std::string result = "完成" + food->FoodName();
        delete food;
        return result;
    }
};

//具体的面包工厂
class BreadCreator : public Creator
{
public:
    Food *FactoryMethod() const override
    {
        std::cout << "制作面包的流程......" << std::endl;
        return new Bread();
    }
};

//具体的馒头工厂
class MantouCreator : public Creator
{
public:
    Food *FactoryMethod() const override
    {
        std::cout << "制作馒头的流程......" << std::endl;
        return new Mantou();
    }
};

void ClientCode(const Creator &factory)
{
    std::cout << factory.MakeFood() << std::endl;
}

int main()
{
    Creator *c = nullptr;

    std::cout << "面包工厂:" << std::endl;
    c = new BreadCreator();
    ClientCode(*c);
    std::cout << std::endl;
    delete c;

    std::cout << "馒头工厂:" << std::endl;
    c = new MantouCreator();
    ClientCode(*c);
    std::cout << std::endl;
    delete c;
    return 0;
}