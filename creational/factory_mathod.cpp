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

//抽象工厂类
class FoodFactory
{
public:
    virtual ~FoodFactory() {}
    virtual Food *prepare() const = 0;
    std::string MakeFood() const
    {
        Food *food = this->prepare();
        std::string result = "完成" + food->FoodName();
        delete food;
        return result;
    }
};

//具体的面包工厂
class BreadFactory : public FoodFactory
{
    Food *prepare() const override
    {
        std::cout << "制作面包的流程......" << std::endl;
        return new Bread();
    }
};

//具体的馒头工厂
class MantouFactory : public FoodFactory
{
    Food *prepare() const override
    {
        std::cout << "制作馒头的流程......" << std::endl;
        return new Mantou();
    }
};

void FoodClient(const FoodFactory &factory)
{
    std::cout << factory.MakeFood() << std::endl;
}

int main()
{
    FoodFactory *factory = nullptr;

    std::cout << "面包工厂:" << std::endl;
    factory = new BreadFactory();
    FoodClient(*factory);
    std::cout << std::endl;
    delete factory;

    std::cout << "馒头工厂:" << std::endl;
    factory = new MantouFactory();
    FoodClient(*factory);
    std::cout << std::endl;
    delete factory;

    return 0;
}