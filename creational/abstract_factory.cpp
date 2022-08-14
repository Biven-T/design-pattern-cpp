#include <iostream>
#include <string>

//鞋子
class Show
{
public:
    virtual ~Show(){};
    virtual std::string ShowName() const = 0;
};

//时尚鞋子
class FashionShow : public Show
{
public:
    std::string ShowName() const override
    {
        return "F:show";
    }
};

//奢华鞋子
class GorgeousShow : public Show
{
public:
    std::string ShowName() const override
    {
        return "G:show";
    }
};

//衣服
class Cloth
{
public:
    virtual ~Cloth(){};
    virtual std::string ClothName() const = 0;
    virtual std::string Combination(const Show &s) const = 0;
};

//时尚衣服
class FashionCloth : public Cloth
{
public:
    std::string ClothName() const override
    {
        return "F:cloth";
    }

    std::string Combination(const Show &s) const override
    {
        return ClothName() + " " + s.ShowName();
    }
};

//奢华衣服
class GorgeousCloth : public Cloth
{
public:
    std::string ClothName() const override
    {
        return "G:cloth";
    }

    std::string Combination(const Show &s) const override
    {
        return ClothName() + " " + s.ShowName();
    }
};

//工厂
class Factory
{
public:
    virtual Show *CreateShow() const = 0;
    virtual Cloth *CreateCloth() const = 0;
};

//时尚工厂
class FashionFactory : public Factory
{
public:
    Show *CreateShow() const override
    {
        return new FashionShow();
    }

    Cloth *CreateCloth() const override
    {
        return new FashionCloth();
    }
};

//奢华工厂
class GorgeousFactory : public Factory
{
public:
    Show *CreateShow() const override
    {
        return new GorgeousShow();
    }

    Cloth *CreateCloth() const override
    {
        return new GorgeousCloth();
    }
};

void ClientCode(const Factory &f)
{
    const Show *show = f.CreateShow();
    const Cloth *cloth = f.CreateCloth();
    std::cout << cloth->ClothName() << std::endl;
    std::cout << cloth->Combination(*show) << std::endl;
    delete cloth;
    delete show;
}

int main()
{
    Factory *f = nullptr;

    f = new FashionFactory();
    ClientCode(*f);
    delete f;

    f = new GorgeousFactory();
    ClientCode(*f);
    delete f;

    return 0;
}