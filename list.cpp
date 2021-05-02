#include"list.h"


Animal* List::find(int index) {
	Animal* finded = NULL, * tmp = head;
	int i = 0;
	while (tmp != NULL) {
		if (i == index) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
		i++;
	}
	return finded;
}

void List::addAnimal(std::string name, std::string type, std::string info){

	Animal* tmp = new Animal(name, type, info);
	tmp->next = head;
	tmp->prev = NULL;
	head->prev = tmp;

	head = tmp;
}

void List::print() {
	Animal* tmp = head;
	while (tmp != NULL) {
		std::cout << "Animal " << tmp->GetName() << '\n';
		std::cout << "is "<< tmp->GetType() << '\n';
		std::cout << "info: "<< tmp->GetInfo() << '\n';
		tmp = tmp->next;
	}
}

void  List::printFile(std::string fileName) {
	std::ofstream out(fileName);
	if (out.is_open())
	{
		Animal* tmp = head;
		while (tmp != NULL) {
			out << tmp->GetName() << '\n' << tmp->GetType() << '\n' << tmp->GetInfo() << '\n';
			tmp = tmp->next;
		}
	}
	else {
		std::cout << "Can't open file " << fileName << '\n';
	}
	out.close();
}

void List::del(int index) {

	Animal* finded = find(index);
	if (!finded)
		return;

	if (finded->prev) {
		finded->prev->next = finded->next;
	}
	if (finded->next) {
		finded->next->prev = finded->prev;
	}
	delete finded;

}

void List::free() {
	Animal* tmp = head;
	while (tmp != NULL) {
		Animal* p = tmp;
		tmp = tmp->next;
		delete p;
	}
}

void List::editInfo(int index, std::string value) {
	Animal* finded = find(index);
	if (!finded) {
		std::cout << "can't find index: " << index << '\n';
		return;
	}
	finded->SetInfo(value);
	
}
Animal* List::findAnimalByName(std::string name) {
	Animal* finded = NULL, * tmp = head;
	while (tmp != NULL) {
		if (tmp->GetName() == name) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
	}
	return finded;
}