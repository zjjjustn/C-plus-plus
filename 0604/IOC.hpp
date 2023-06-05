#pragma once
#include <string>
#include <map>
#include <iostream>
#include <functional>
class AddFactory;
class SubFactory;
class MulFactory;
class DivFactory;
class ModFactory;

using namespace std;
template <class T>
class IocContainer {
public:
	static IocContainer getInstance()
	{
		static IocContainer con;
		return con;
	}

	~IocContainer()
	{

	}
	//注册需要创建对象的构造函数，通过一个唯一的标识，以便于以后查找
	template<class Drived>
	void RegisterType(string strKey) {
		std::function<T* ()> function = [] {return new Drived();};
		RegisterType(strKey, function);
	}

	//根据唯一的标识去查找对应的构造函数
	T* Resolve(string strKey) {
		if (m_createMap.find(strKey) == m_createMap.end())
			return nullptr;
		std::function<T* ()> function = m_createMap[strKey];
		return function();
	}

	//创建智能指针
	std::shared_ptr<T> ResolveShared(string strKey) {
		T* ptr = Resolve(strKey);
		return std::shared_ptr<T>(ptr);
	}
private:
	void RegisterType(string strKey, std::function<T* ()> creator) {
		if (m_createMap.find(strKey) != m_createMap.end()) {
			throw std::invalid_argument("已经存在这个key了");
		}
		m_createMap.emplace(strKey, creator);
	}

private:
	map<string, std::function<T* ()>> m_createMap;

	IocContainer(void){

		RegisterType<AddFactory>("+"); //["+", [](){return new AddFactroy;}]
        RegisterType<SubFactory>("-");
    //["+", [](){return new AddFactroy;}],["-", [](){return new SubFactroy;}]
        RegisterType<MulFactory>("*");
        RegisterType<DivFactory>("/");
    //["+", [](){return new AddFactroy;}],["-", [](){return new SubFactroy;}]
    //["*", [](){return new MulFactroy;}],["/", [](){return new DivFactroy;}]
        RegisterType<ModFactory>("%");
	}
};