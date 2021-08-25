#include<bits/stdc++.h>
using namespace std;

/*

Question: 
Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first
out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of
that type). They cannot select which specific animal they would like. Create the data structures to
maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
and dequeueCat. You may use the built-in Linked list data structure.


Approach:

1. Use 2 queues to maintain dogs and cats
2. a wrapper class to maintain the order in which these animals were enqueued

*/

class QueueEmptyException : public exception {
    const char* what() const throw() {
        return "Queue is Empty!";
    }
};

class Animal {
    public:
    string name;
    int order;
    string type;
};

class Dog : public Animal {
    public:
    Dog(string name) {
        this -> name = name;
        this -> type = "dog";
    }
};

class Cat : public Animal {
    public:
    Cat(string name) {
        this -> name = name;
        this -> type = "cat";
    }
};

class AnimalShelter {
    public:
    queue<Dog> dogs;
    queue<Cat> cats;
    static int order;
    
    // enqueue a dog
    void enqueue(Dog d) {
        d.order = order;
        dogs.push(d);
        order++;
    }
    // enqueue a cat
    void enqueue(Cat c) {
        c.order = order;
        cats.push(c);
        order++;
    }
    // dequeue Dog
    Dog dequeueDog() {
        if(dogs.empty()) {
            throw QueueEmptyException();
        }
        Dog temp = dogs.front();
        dogs.pop();
        return temp;
    }
    // dequeue Cat
    Cat dequeueCat() {
        if(cats.empty()) {
            throw QueueEmptyException();
        }
        Cat temp = cats.front();
        cats.pop();
        return temp;
    }

    // dequeue any
    Animal dequeueAny() {
        if(!dogs.empty() && !cats.empty()) {
            return ( dogs.front().order < cats.front().order ? (Animal)dequeueDog() : (Animal)dequeueCat() );
        }
        else if (dogs.empty())
            return (Animal)dequeueCat();
        else
            return (Animal)dequeueDog();
    }
};

// intialize the order to 0
int AnimalShelter::order = 0;

void printQueue(AnimalShelter a) {
    cout<<"Dogs"<<endl;
    while(!a.dogs.empty()) {
        cout<<a.dogs.front().name<<" "<<a.dogs.front().order<<"\t";
        a.dogs.pop();
    }
    cout<<endl;
    cout<<"Cats"<<endl;
    while(!a.cats.empty()) {
        cout<<a.cats.front().name<<" "<<a.cats.front().order<<"\t";
        a.cats.pop();
    }
    cout<<endl<<endl;
}

int main() {
    
    AnimalShelter a;
    a.enqueue(Dog("A"));
    a.enqueue(Dog("B"));
    a.enqueue(Dog("C"));
    a.enqueue(Dog("D"));
    a.enqueue(Cat("P"));
    a.enqueue(Cat("Q"));
    a.enqueue(Cat("R"));
    a.enqueue(Cat("S"));

    printQueue(a);


    try {
        a.dequeueAny();
        a.dequeueDog();
        a.dequeueCat();
        a.dequeueDog();
        a.dequeueDog();
        a.dequeueDog();
        a.dequeueDog();    
    }
    catch (QueueEmptyException e) {
        cout<<"Queue is Empty"<<endl;
    }
    

    printQueue(a);




    return 0;
}