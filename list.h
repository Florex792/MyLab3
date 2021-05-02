#pragma once
#include<string>
#include<iostream>
#include<fstream>

class Animal {
private:
	std::string name;
	std::string type;
	std::string info;
public:
	Animal* next;
	Animal* prev;
	Animal() {
		next = NULL;
		prev = NULL;
	}
	Animal(std::string name, std::string type, std::string info) : name(name), type(type), info(info) {
		next = NULL;
		prev = NULL;
	}
	void SetName(std::string s) {
		this->name = s;
	}
	std::string GetName() {
		return this->name;
	}
	void SetType(std::string s) {
		this->type = s;
	}
	std::string GetType() {
		return this->type;
	}

	void SetInfo(std::string s) {
		this->info = s;
	}
	std::string GetInfo() {
		return this->info;
	}
	~Animal() {
	
	}
};

class List {
public:
	Animal* head;
	List(Animal ml){
		Animal* tmp = new Animal(ml);
		head = tmp;
	}


	void editInfo(int index, std::string value);

	Animal* findAnimalByName(std::string name);

	Animal* find(int index);

	void addAnimal(std::string name, std::string type, std::string info);

	void print();

	void printFile(std::string fileName);

	void del(int index);

	void free();


	~List() {
	}
};

