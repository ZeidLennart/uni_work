
# credits for this File to the person uploading there notes in the Following drive (can't see who this was)
# https://drive.google.com/drive/folders/1IiEusjO5yOX8rqK1Lm6IzAVDChe9ytxl


# 08.04.2024

### Inheritance:
- base class doesn't know about child class
- child class always knows about base class
- reduces code
- more expressive code 
- base class -> child class (inherits from base) -> grand child class (inherits from child)
- **protected** vs **private** inheritance
- normally the **public** inheritance is being used

### Static Binding:
- storing values is called serialization) and restoring is called deserialization after device was being off
## Virtual function:
-  are dynamically bound
- **late binding** moves decision to call a function to runtime
- use `virtual` keyword
- all children will be also virtual

`g++ -std=c++20 -Wall -pedantic -Wextra -Wshadow -Wfatal-errors` - reports errors


### Inclusion polymorphism

### Overriding a function

Pure virtual functions = abstract functions:

# 09.04.2024

**standard constructor** - is called without arguments

list initialization is NOT initializer list

list initizalisation should be prefered way

should be preferred initialization by constructor

`int i();` is not allowed

avoid zero initialization

```
{
	 int i {99};
}
// i is being destroyed after block ends
int i;
cout << i << endl;

```

will print an undefined value

if something works on your machine, nothing guarantees that it will work the same way on another


```
int x;

{
	 int i {99};
}
int i;
cout << i << endl;
```

x is a **global** variable

`object.o` - is not an exe, but an object file

lifetime of global variable corresponds to lifetime of program

If linker finds a function with declaration but without a definition `int useGlobe();`, it will search through code and find function with the same name in object file and use its definition

# 15.04.2024

`extern double variable` - only declares the variable using keyword `extern` to define it later somewhere else

**one definition rule** of C++ - have as much declarations as you want, but only one definition

zero initialization is build automatically for static variables

context sensitive grammar in C++

automatic conversion is not allowed in list initialization

# 16.04.2024 - self study

A dynamic object is created with the `new` operator

a dynamic object **will not** be deleted automatically, so assign a pointer to it and use `delete` operator for deletion

**It is strongly recommended not to use dynamically created objects.**

list initialization = uniform initialization

![[Bildschirmfoto 2024-04-16 um 14.08.29.png]]

# 17.04.2024

### Hidden function:

`void func() const {}`
### Pure virtual function:

- Funktion ohne Implementierung

- `virtual void func()=0;`

- eine Klasse mit mind. einer virt. Funktion sei virtuelle Klasse

- pure virtuelle Funktion muss in einer Kind-Klasse definiert werden, damit Code kompiliert
### Converting Konstruktor:

___
### QUIZ:
1) 1
2) 3
3) 1
4) 4 ?
5) 4
6) 1 - expliziter conversion constructor impliziter Aufruf
7) 4
8) 1

___
#### 4 kinds of polymorphism:
- **coercion** polymorphism:
	- Coercion polymorphism deals with type conversion, e.g. converting an int into a double when necessary
- **overloading** polymorphism:
	- when func overloading is being implemented
- **inclusion** pol.:
	- Public inheritance in combination with late binding and passing arguments by reference or as pointer
- **parametric** pol.

**A destructor has no arguments.**

example of a proper **inheritance**:
```
class Weapon{
 public:
	 Weapon(int damage, int lev): damage{damage}, minimum_level{lev} {}
 protected:
	 int damage;
	 int minimum_level;
};

class RangedWeapon: public Weapon{
    public:
        RangedWeapon(int x, int y, int z): Weapon(x, y), range {z} {}
    private:
        int range;
};
```

the Object-Oriented Paradigm extends the ADT(abstract data type) by introducing **inheritance and late binding**.

# 29.04.2024

move semantics 

Liskov substitution principle

**sub objects**: a class has objects of another class in it

```
class C{
A a;
B b;
};
```

first will be created A, then B, and at last C: ABC
Destruction: ~C~B~A

there can be multiple base classes:
```
class F: public D, public E{

};
class G: public F {

};
```
Construction: DE F G
Destruction: ~G ~F ~E~D

```
class H {};
class I{
	H h;
};
class J{};
class K: public I{
	J j;
};
```
DON'T RELY ON THIS ORDER
Construction: HI JK
Destruction: ~K~J  ~I~H

### function call operator

```
11 bool ascending(const string& a,const string& b) 
12 { 
13 return (a < b); 
14 }

```

```
sort(v.begin(),v.end(),fp);
```

The ascending() function can also be passed to the std::sort<>() algorithm of the STL. This allows the elements of a std::vector<> to be sorted in alphabetically ascending order, as demonstrated in line 44. What is passed to the sort<>() algorithm is only the name of this function – without the following pair of parentheses. But what does ascending mean without parentheses? It is a pointer pointing to the function ascending(). **Only when this pointer is followed by the pair of parentheses**, the so-called **function call operator**, the function is actually called

### function as a parameter

```
#include <iostream>
using namespace std;

void HelloWorld(){
	cout<<"Hello World"<<endl;
}

void AnyText(string txt){
	cout<<txt<<endl;
}

auto func = HelloWorld;
void(*func1)() = HelloWorld;
void func2(void(*function)()){
	function();
}

void anyText(void(*function)(string), string txt){ 
	function(txt);
}
//you could also give any name to parameter of void(*function)(string).

int main(){
	func();
	func1();
	func2(HelloWorld);
	anyText(AnyText, "my text");
	return 0;
}
```

**Function pointer types** - allow declaring function pointer variables that can point to any compatible function – at runtime. This corresponds to dynamic binding or late binding of virtual member functions – only without receiver object.

![[Bildschirmfoto 2024-05-06 um 12.32.12.png]]

If a pointer to a comparison function had to be declared repeatedly, this would be cumbersome and error-prone. Writing declarations repeatedly, as in the printAndSort() function, reduces software quality

**Never** write code that directly accesses or manipulates a vtbl or the pointer to it. The resulting program would be not portable and would have potentially disastrous effects.

# 06.05.2024

`virtual ~UrnOR() = default` - **move semantic** is **disabled** because of virtual destructor

`uint` = `typedef` of `unsigned int`

"operators are functions in disguise"

check - uncheck access to element `[]`

`explicit` functions

ayota algorithm library to quick initialize vectors

convert to Java using interfaces

an exemplar for Urn has internal state that occupies memory.

# 07.05.2024

- inheritance compromises modularity
- as long as you draw relationships btw classes modularity is no longer a thing
- inclusion with polymorphism opens the door for dangerous code
- reimplementation of member functions in child classes might be dangerous
- therefore in some domains of software it's restricted to use inclusion polymorphism
- `explicit` class => you need to explicitly define Constructor
- **Legacy casts** are not commonly used
- casts are indespensible when it comes to gui/OOP though they are source of many problems
- **static casts** can be used for downcasts: from base pointer/reference to dynamic pointer/reference 

___

- When a member function is declared as `static`, it is bound to the class rather than to an instance of the class.  
  The functions can be declared as virtual in derived classes, but this does not overwrite the static function. This just hides it. 

- Only non-static member functions can be declared as virtual in C++. Free functions and static member functions cannot be virtual because they are not associated with any particular instance of the class

- A virtual member function in C++ can only be overridden by another virtual member function in derived classes.

- When a virtual function is inherited by a derived class, the function can be declared as virtual again in the derived class. This does not change anything, and is sometimes even recommended to clarify that the function is virtual.

- Inclusion polymorphism, also known as subtype polymorphism or dynamic polymorphism, occurs when an object of a derived class is treated as an object of its base class, and the appropriate version of a method is determined at runtime based on the actual type of the object rather than the declared type of the variable or parameter.

- Overloading polymorphism, also known as ad-hoc polymorphism, occurs when a function or operator has multiple definitions with different sets of parameters or arguments, and the appropriate definition to use is determined at compile time based on the types and number of arguments passed to the function or operator. This can occur without inheritance, and is often used in object-oriented programming to provide different versions of a method for different types of arguments.  

- Even during inheritance, it does not always occur, as the inherited functions could be overidden or hide the function from the base-class, which is not overloading.

# 08.05.2024 Tut

### Stack
- Stack: Speicherbereich in der lokale Variablen und Funktionsaufrufe gespeichert werden
- STACK OVERFLOW: zu viele Daten im Stack gespeichert
- Variablen werden in der Reihenfolge ihres Auftretens erstellt und im umgekehreter Reihenfolge geloescht
### Heap
- Speicherbereich für dynamische Speichernutzung
- Zugriff ist lngsammer
- Speicherbereich, der für dynamische Speicherzuweisung verwendet wird -> Objekte und Daten gespeichert, deren Größe zur Kompilierzeit nicht bekannt ist oder die länger als deren scope bestehen bleiben müssen.
- Speicherverwaltung muss von Programmierer:in gesteuert werden (durch explizites Anfordern + Freigeben von Speicher)
- Memory leaks treten auf, wenn Speicher, der im Heap reserviert wurde, nicht ordnungsgemäß freigegeben wird
- ![[Bildschirmfoto 2024-05-08 um 13.33.58.png]]

### Vtable
- vtable is Datenstruktur mit Pointer
- jeder Exemplar der Klasse hält einen Pointer in vtable
- Wirdautomatischerzeugt,sollteeineKlassemindestenseinevirtuelle Funktion be
- ![[Bildschirmfoto 2024-05-08 um 13.36.08.png]]

### Typecasts
- ![[Bildschirmfoto 2024-05-08 um 13.37.29.png]]
- `static_cast` - sicherste Form der Cast, da zum Compilierungszeit überprüft wird
- `dynamic_cast`:
- `const_cast`:
	- man kann temporär einfügen oder entfernen const Eigemschaft
- `reintepret_cast:
	- bitconversion zwischen zwei typen
	- agressiv und gefährlich
	- Unportabilität und undefiniertes Verhalten sind wahrscheinlich



`this` - Pointer auf Objekt

### Kontrollfragen

1) 4
2) 4
3) 4
4) 2
5) 3
6) 1
7) 4
8) 1

___
### Abstract classes
In [programming](https://www.simplilearn.com/pgp-full-stack-web-development-certification-training-course?source=GhPreviewCoursepages "programming"), an **abstract class** in [C++](https://www.simplilearn.com/c-plus-plus-programming-for-beginners-article "C++") **has at least one pure virtual function** by definition. In other words, a [function](https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-functions "function") that has no definition. The abstract class's **descendants must define the pure virtual function; otherwise, the subclass would become an abstract class in its own right**.

Abstract classes are **used to express broad concepts** from which more concrete [classes](https://www.simplilearn.com/tutorials/cpp-tutorial/classes-in-cpp "classes") can be derived. **An abstract class type object cannot be created**. To abstract class types, however, you can use [pointers](https://www.simplilearn.com/tutorials/cpp-tutorial/pointers-in-cpp "pointers") and [references](https://www.simplilearn.com/tutorials/cpp-tutorial/call-by-value-and-call-by-reference-in-cpp "references"). Declare at least one pure virtual member feature when creating an abstract class. The pure specifier (= 0) syntax is used to declare a virtual function.
### Coercion polymorphism
(also known as implicit type conversion) is a type of polymorphism **in which values of one data type are automatically and implicitly converted to another data type** when needed, such as when passing arguments to a function or assigning a value to a variable.
### Parametric polymorphism
,also known as **generic** polymorphism, **allows functions and data types to be written in a generic way that can work with a wide range of data types, without specifying the actual type in the function or datatype**. For example, a generic function that takes a type parameter T can be used with any data type, such as integers, strings, or custom classes, by specifying the appropriate type when the function is called.

### The resolution of different types of polymorphism
, such as parametric, inclusion, and coercion polymorphism, **can interact with each other and lead to conflicts that cannot be resolved or unexpected behavior if not carefully managed**. 
**For example**, if a function has overloaded versions for different types and also takes a parameter that can be implicitly converted to different types, the compiler may have to choose between multiple possible matches, leading to ambiguity or unexpected behavior. This may result in an error issued by the compiler or worse - undefined behavior.


# 13.05.2024

- an object of the same class can always access private members of another exemplar of the same class
- using dynamic casts might under some conditions lead to runtime errors
- using functional and static casts is though recommended 
- `reinterpret_cast<>()` supports any conversion between types, but can't remove constness
- anything can be represented as a bit string
- `using uint_t = unsigned short int` will turn `uint_t` to unsigned short int
- `one << (loop - 1)` - bitwise shift last
- `one << loop - 1` - bitwise shift first
- in signed types a `1` as MSB means sign `-`  : `1` = `-`, `0` = `+`
- `register` is a keyword in c++

# 29.05.2024 Tutorium
- **smart pointer**
	- dient der Rescourcenverwaltung
	- löscht dynamische Objekte korrekt
- **Aufgaben**:
	- 1 4)
	- 2 4)
	- 3 1) copy constructor 2) Doppelte Freigabe von dynamische Rescourcen 3) Big 3, 5 , Smart Pointer
	- 4 2) Liskov Subst.: miteinander zusammenhängende Obj. zugegriffen werden.
	- 5  4) `typeid`?
	- 6 1)
	- 7 3)
	- 8 1)
- `typeid(int).name()=="int"` - VERY WRONG, das die Ausgabe os-spezifisch ist
- `long` ist MINDESTENS so lange wie `int`

# 05.06.2024
- you can spawn children and parent windows with fltk. You should close al of them to terminate the program
- there is an order of **cycling** through widgets
- **standard button** receives key **event** first (for example *return* button). It can be emphasized graphically. 
- gui program should be useful without a mouse

# 12.06.2024

- `n -> func() ` = `(*n).func()` where n is a *pointer* (arrow makes compiler transform code into dereference?)
```CPP
A a;
A * b = &a;
b -> func();
```

```CPP
A *a = new A();
a -> func();
delete a;
```

- accelerator key brings directly to action you want. So you don't need event bundle
- generic = general solution/general problem (largely independent on language)
- ### Observer:
	- also called public subscriber
	- you have data but there might be different renderings of it (for example 1 data on graph and table)
	- interaction between subject (data) and its observer
	- observer observes only one object, knows it and reports changes
	- observer can die as well as object
	- 
# Self Study
- ## Virtual function:
	- https://www.geeksforgeeks.org/virtual-function-cpp/
	- non-virtual function binded at compile time
	- virtual one binded at runtime
	- `virtual` keyword is set in base class
	- allows to override a function in a derived class

- The copy constructor is used to create a new object as a copy of an existing object of the same class. It is a special constructor that takes a reference to an object of the same class as its argument, and creates a new object by copying the values of the member variables of the argument object.

- It looks like an assignment but its is not since the context revolves around creating an object which requires a constructor. It calls the constructor and combines it with an initialization.

- **virtual function** table uses function pointer to implement late binding:
	- virtual functions are being implemented with vtable cause c++ standard doesn't define it
	- The virtual table only contains entries for virtual member functions declared in a class,
	- Virtual tables are used whenever virtual functions are called
	- compiler constructs a `vtable` for eery class that contains at least 1 virt. function 
- name of the function as parameter without () is a pointer of this function
- Declaring a variable as `static` actually makes it invisible outside of the current scope
- Cardelli & Wegner differentiate between parametric, inclusion, overloading(ad-hoc) and coercion polymorphism.

## Constructers and destructors
- if a constructor can be called without arguments => it's a **standard constructor**
-  **standard constructor** is being generated by compiler automatically if no other manually was defined
- **zero initialization**:
	- initialization to 0 or 0 effect
	-  "When declaring a variable of fundamental type, initialization with an empty list has exactly this effect. It initializes the variable with a value that is 0 or has the meaning of zero. For example, int i { }; defines i and initializes it to 0."
- **global** and **static** variables have lifetime equal to that of program
- **global** variable:
	- defined outside a block
	- usually defined at the beginning
	- defined and initialized before any main() statement
- **static variable**:
	- defined in a block
- `extern`:
	- no memory is allocated
	- declared globally
	- example: `extern int global;`
- **dynamic objects**:
	- should be deleted
	- memory will not be released automatically
	- not recommended
	- example: `int p = new int(); delete int;`
- **copy constructer**:
	- generated automatically when a copy of exemplar of the same class needs to be constructed
	- if an objects has dynamic resource, suitable copy constructor should be either defined or forbidden
	- example: `RationalNumber a {2, 3); RationalNumber b {a};`
- **explicit**: ?
	- a constructor can be explicit
	- avoids automatic **implicit conversion**
	- example: 

```CPP
class Demo{
    public:
        explicit Demo(int n){
            demo1 = n;
        }
        int getDemo(){
            return demo1;
        }
    private:
        int demo1;
```
- **initializer_list**:
	- is used to initialize data members of a class
	- a special header file is needed
```CPP
	10 class Person 
	11 { 
	12 public: 
	13 Person(string surname,initializer_list firstnames = { }) 
	14 : m_surname { surname }, 
	15 m_firstnames { firstnames } 
	16 {}
```
- **delegating constructor**:
	- must appear alone
	- allows to avoid copying the same code when two constructers are implemented for different number of arguments
	- rest of the variables should be defined in definition of the constructor, list initialization can't be used
	- example:
```CPP
class Delegator

{
	private:
		string name;
		string surname;
		int height;
	public:
		Delegator(string n, string s): name {n}, surname {s} {cout<< name << " "<<surname << endl;}
		Delegator(string n, string s, int h): Delegator(n,s) {height = h; cout<< name << " "<<surname<< " "<<height << endl;}
		~Delegator(){}
};

int main(){
	Delegator d("name", "surname", 14);
	return 0;
}
```
- **virtual destructor**:
	- constructors are always called in top level from base class, destructor in reverse order:
		- `Base::Base() Derived::Derived() Derived::~Derived() Base::~Base()`
	- `Base * actuallyDerivedPointer { new Derived };` - this code will lead to *absence* of Derived destructor if to a base destructor wasn't  assigned `virtual` keyword
	- https://www.youtube.com/watch?v=jELbKhGkEi0
- ## virtual function table :
	- uses function pointer to implement late binding:
	- virtual functions are being implemented with vtable cause c++ standard doesn't define it
	- The virtual table only contains entries for virtual member functions declared in a class,
	- Virtual tables are used whenever virtual functions are called
	- compiler constructs a `vtable` for eery class that contains at least 1 virt. function 
- ## final:
	- **final class**:
		- `final` forbids overriding virtual functions i n sub-classes
		- example:  `class NotABaseClass final {};` (*empty class*, that can't be used as a base class)
		- class will be *non-inheritable*
		- for programmer itself to stop him from using as a base class
		- avoids ambiguity
	- **final function**:
		- example: `public: std::intmax_t numerator() const final {...}`
		- being applied to *member functions*
		- this function *can't be overriden* by sub class 
		- The final specifier *is not a keyword*. Therefore, it is legal to define a class named final as final. With the goal in mind of writing programs that are easy to read and maintain, the use of final in any way other than as a final specifier should be strictly avoided.
	- ## Static members: ?
		- exist independently from exemplars of their class
		- are bound to their class
		- declaration of member must contain `inline` or `const` (then better `constexpr`)
		- without `inline` must be initialized outside of a class mostly
		- choice between `inline` or `const` depends on specific case
		- static *member function* can't be `const` and is always early bound
	- ## Using:
		- `using` declaration *makes method of base class accessible* if they were blocked by private or protected inheritance 
		- is used to declare *aliases* : `using integer = signed long long;`
		- is used to import identifiers from *namespaces* : `using namespace std`
		- example:
			- doe to private inheritance the constructor of A became private in B
```CPP
class A{
	public:
		A(){
		cout<<"A"<<endl;
		}
	protected:
		void print(){
			cout<<"hello"<<endl;
		}
};
class B : private A{
	public:
		using A::print; //exact function name should be specified
};
int main(){
	B a;
	a.print();
	return 0;
}
```


- ## Default:
	- once a *user-defined* constructer is specified, a *standard* constructor won't be generated
	- use `default` to enforce presence of *standard constructor*: 

```CPP
7 class Person 
8 { 
9 public: 
10 Person(string name):m_name(name) 
11 {} 
12 Person() = default; 
13 private: 
14 string m_name; 
15 };
```
- example 
- ## Delete: ?
	-  is opposite to `default`
	- all member functions that can be *defaultet* , can also be *deleted*
- ## `[[nodiscard]]` Class: ?
	- compiler will warn if class isn't used
- ## Object with Dynamic Resource:
	- acquire only when needed
	- release immediately after being used
	- `mutable` specifier allows to modify data members of const objects
	- 
- ## Static member function:
	- `static` *member function* can be *accessed using the class name* and the scope resolution operator `::`, **without** creating an instance of the class
	- they are *changeable*
	- Static members of a class are not associated with the instances of a class, but the class itself.
	- A *static member* function can only directly access *static data members* and other *static member functions* of the class, and any *free function outside* of the class.
- ## `[[nodiscard]] ` for classes:
	- compiler will warn if temporary of a class wasn't used
	- doesn't make every member function `[[nodiscard]]`
```CPP
#include <iostream>
using namespace std;
class [[nodiscard]] A{
	public:
		void hey(){
			cout<<"hey"<<endl;
		}
		[[nodiscard]] int tw(){
			return 12;
		}
		int th(){
			return 13;
		}
	};
int main(){
	A a;
	int tw = a.tw();
	a.tw();
	a.th();
	cout<<"b4 class"<<endl;
	A {};
}
```
result:
```
nodisclass.cpp:21:5: warning: ignoring return value of function declared with 'nodiscard' attribute [-Wunused-result]
    a.tw();
    ^~~~
nodisclass.cpp:24:5: warning: ignoring return value of function declared with 'nodiscard' attribute [-Wunused-result]
    A {};
    ^ ~~
2 warnings generated.
```
- ## rvalue and lvale:
	- https://www.geeksforgeeks.org/lvalues-references-and-rvalues-references-in-c-with-examples/
	- lvalue:
		- can be used as alias to an object
		- refers to the memory location
		- lvale reference: `int a = 10; int& ref = a`
		- used in *pass-by-reference* semantic
	- rvalue:
		- refers to the data
		- rvalue reference: `int&& rref = 20` can be specified as `const`
		- used in *move constructor* and *move-assignment*
- ## copy constructor:
	- must be passed as reference
	- copies values from passed argument of same class
	- can modify them
	- isn't necessary to create copy constructor manually
	 - example:
```CPP
class Copy //copy semantics
{
private:
int value;
string name;
public:
	Copy(int v, string n): value {v}, name{n} {};
	Copy(Copy const & c): value{c.value}, name{"copied from " + c.name} {};
	void print(){
		cout<<name<<" : "<<value<<endl;
	}
	~Copy(){};
};
```
- ## move constructor: ! ? (p.72 (91 pdf))
	- https://www.geeksforgeeks.org/move-constructors-in-c-with-examples/
	- page 72 (96 in pdf)
	- enables the resources owned by an rvalue object to be moved into another object, typically an lvalue, without copying
	- 
- ## Liskov Substitution Principle:
	- **SOLID** = Single Responsibility Principle, Open/Closed Principle, Liskov Substitution Principle, Interface Segregation Principle, Dependency Inversion
	- The principle defines that objects of a superclass shall be replaceable with objects of its subclasses without breaking the application
	- overriden method of subclass should accepts same input arguments as in the base class
	- objects of subclass should behave in the same way as in superclass to not break the program
	- https://www.youtube.com/watch?v=dJQMqNOC4Pc
	- make more general base classes
- ## Objects with dynamic Resource:
	- pass variable to a class as a reference
	- doesn't make a copy when it doesn't make sense
	- **mutable** specifier:
		- allows object to be modified even if object is *const*
		- only available for member variables
	- use `using` declaration:
		- to create an *alias*:
			- `using Class = NoDynamicResource` - an alias to  `NoDynamicResource`
	- 
	- 
```CPP
class A
{
	private:
		int value;
	public:
		A(int &v) //pass by reference
		{
			value = v + 11;
			v = value;
			cout<<value<<endl;
		}
};

int main()
{
	int val = 10;
	B b {val};
	cout<<val<<endl;
} //output: 21 21
```
- ## Rule of Big Three:
	- *the rule of three*
	- **if** a class defines any of these **3** member functions: *destructor*, *copy constructor*, *copy assignment operator*; then it should define **all three of them**
	- recommends, how to write a class that manages *external resources* (like *dynamically allocated memory*)
	- https://www.youtube.com/watch?v=9w-bp6mxxwY
	- `private: *int data`: has a destructor an copy ass. operator (`Class b = a`) -> will just point to memory location of a's `data` member-> needs a deep copy constructor
	- deep copy: `Class(const Class& other) {data = new int(*other.data));`
```CPP
#include <iostream>
using namespace std;
class A{ //NO COPY CONSTRUCTOR FOR DEEP COPY, NO COPY ASSIGNMENT OPERATOR
	protected:
		int *data;
		string name; 
	public:
		A(){
			data = new int();
		};
		A(int i, string n){
			data = new int(i);
			name = n;
		}
		void setData(int i){
			*data = i;
		}
		void setName(string n){
			name = n;
		}
			virtual void callData(){
			cout<<"A "<<name<<" : "<<*data<<" : "<<data<<endl;
		}
		virtual ~A(){ //virt because base class
			if (data!=nullptr){
				data = nullptr;
			}
			delete data;
		}
};
class B: public A{
	public: //RIGHTWAY! Additional copy constructor defined!
		using A::A;
		void callData() override{
			cout<<"B "<<name<<" : "<<*data<<" : "<<data<<endl;
		}
		B(const B& other) //copy constructor
		{
			data = new int(*other.data);
		}
		B& operator = (const B& other){ //copy assignment operator
			if(this != &other){
				*data = *other.data;
				name = other.name;
			}
			return *this;
		}
};
int main(){
	{
	cout<<"wrong way!"<<endl;
	A a {10, "Alice"}; //Alice is created
	a.callData();
	A b = a; //Mike (yet Alice) is declared and copies data from Alice
	b.setName("Mike"); //Mike is given his own name
	a.setData(20); //value of Alice is changed
	a.callData();
	b.callData();
	}
	{
	cout<<"right way!"<<endl;
	B a = {10, "Alice"};
	a.callData();
	B b = a;
	b.setName("Mike");
	a.setData(20);
	a.callData();
	b.callData();
	}
	{
	cout<<"assignment"<<endl;
	B a = {10, "Alice"};
	cout<<"a created"<<endl;
	B b;
	cout<<"b declared"<<endl;
	b.callData();
	b = a;
	cout<<"b defined"<<endl;
	a.callData();
	b.callData();
	}
}
```
OUTPUT:
```
wrong way!
A Alice : 10 : 0x156606160
A Alice : 20 : 0x156606160
A Mike : 20 : 0x156606160
right way!
B Alice : 10 : 0x156605ff0
B Alice : 20 : 0x156605ff0
B Mike : 10 : 0x156605f90
assignment
a created
b declared
B  : 0 : 0x15a6060e0
b defined
B Alice : 10 : 0x15a6060d0
B Alice : 10 : 0x15a6060e0
```
- ## Rule of Big Five:
	- adds *move constructor* and move *assignment operator* to the big 3
- **Move constructor**:
```CPP
A(A&& other)
{
	data = other.data;
	name = other.name;
	other.data = nullptr;
}
```
- **Move assignment constructor**:
```CPP
A& operator = ( A&& other)
{
	if (this != &other){
		name = other.name;
		data = other.data;
		other.data = nullptr;
	}
	return *this;
}
```
- ## Multiple inheritance:
	- don't call a function or variable of the same name that both parents have
```CPP
struct A
{
	int data;
	A(int i):data{i} {}
	void callData()
	{
		cout<< data <<endl;
	}
	void hello(){
		cout<<"hello"<<endl;
	}
};
struct B
{
	char data;
	B(char c):data{c} {}
	void callData()
	{
		cout<< data <<endl;
	}
	void hello(){
		cout<<"hello"<<endl;
	}
	void helloB(){
		cout<<"hello B"<<endl;
	}
};
struct C: A, B{
	C(A a, B b): A(a), B(b){}
};
struct D: C
{
	D(C c): C(c) {}
};
int main(){
	A a (12);
	B b ('d');
	C c {a, b};
	c.helloB();
	c.B::callData();
	cout<<c.A::data<<endl;
	c.hello(); //will throw error
	c.callData(); //will throw error
	cout<<c.data<<endl; //will throw error
	D d(c);
	d.C::B::callData(); //legal
	d.B::callData(); //legal as well
}
```
- ## Aggregation:
	- When class C *aggregates* class B and class A, it means that the object of class C **contains objects of class B and class A as members**. In other words, the objects of class B and class A are part of the implementation of class C, but class C **does not** inherit from either class.
	- example: `struct B {A a;}`
- ## Losing late binding: (p 92 (108))
	- can occure when:
		- calling virtual function in constructor or destructor:
			- Within the constructor or destructor of a base class, calls to virtual functions are resolved to the base class version, even if the object being constructed or destructed is of a derived class.
			- for example, it will be called while executing base constructor by a derived class
			- ![[Bildschirmfoto 2024-06-16 um 11.30.50.png]]
		- objects slicing:
			- When a derived class object is assigned to a base class object (not a reference or pointer), the derived part of the object is "sliced off," and only the base class part is retained. This results in the loss of any derived class-specific information and the inability to call overridden virtual functions in the derived class.
			- ![[Bildschirmfoto 2024-06-16 um 11.30.17.png]]
		- non-virtual functions:
			- If a function is not declared as `virtual` in the base class, it will not exhibit late binding behavior. Instead, it will be resolved at compile time based on the type of the pointer or reference, resulting in early binding (static binding).
			- ![[Bildschirmfoto 2024-06-16 um 11.31.19.png]]
		- Accessing Through Non-Polymorphic Pointers or References:
			- Late binding only works when accessing objects through pointers or references. If an object is accessed directly, early binding occurs.
			- ![[Bildschirmfoto 2024-06-16 um 11.32.07.png]]
	- **Use** the `virtual` keyword for functions in the base class that should exhibit polymorphic behavior.
	- **Access** objects through base class pointers or references.
	- **Avoid** object slicing by not assigning derived objects to base class objects.
	- **Be aware** of the limitations of virtual function calls within constructors and destructors.
- ## virtual base class:
	- Virtual base classes eliminate the occurrence of multiple sub objects of the same class![[Bildschirmfoto 2024-06-16 um 11.44.53.png]]
	- 
	- `class D: public virtual Z` or `class E: virtual public Z` => every sub class of `Z` will aggregate only one sub object of `Z`
	- **Any** class that can become the **most derived class** must call a constructor **of the virtual base class**
	-  **Never** write code that depends on the order of object initialization or object destruction
	- planning is important:
		- 1 extreme:
			- specify every base class as `virtual`
		- 2 extreme:
			- forbid multiple inheritance
		- when using multiple inheritance and virtual base classes, each descendant class must call an appropriate constructor of the virtual base class
```CPP
struct A
{
	A()
	{
		cout<<"A"<<endl;
	}
	~A()
	{
		cout<<"~A"<<endl;
	}
};
struct B : virtual A
{
	B()
	{
		cout<<"B"<<endl;
	}
	~B()
	{
		cout<<"~B"<<endl;
	}
};
struct C : virtual A
{
	C()
	{
		cout<<"C"<<endl;
	}
	~C()
	{
		cout<<"~C"<<endl;
	}
};
struct D: B, C
{
	D()
	{
		cout<<"D"<<endl;
	}
	~D()
	{
		cout<<"~D"<<endl;
	}
};
int main()
{
	D d;
	return 0;
}
/*
if non of them is specified virtual or only "B: virtual A":
result: A B A C D ~D ~C ~A ~B ~A

if only "C: virtual A":
A A B C D ~D ~C ~B ~A ~A

if both "B: virtual A" and "C: virtual A":
A B C D ~D ~C ~B ~A
```
- ## Cast operators:
	- **casts** = conversions between data types
	- **cast operators** = a way to perform cast manually
	- casts come into play when conversion is unsupported/forbidden
	- ### traditional and functional casts:
		- traditional cast: `auto usi { (unsigned short int) 5 };`
		- traditional cast creates a *temporary object* of type `unsigned short int`. It **does not** convert the `int` literal 5 to a `unsigned short int` literal 5, which is actually **impossible**
		- traditional cast can remove constness
		- `is_same_v<decltype(usi),short unsigned int>` checks if type of first parameter is equal to type of second parameter
		- template meta-function `std::is_same_v<>`of the type support library
		- `decltype` can be applied to a variable or expression and **returns the type of the variable or value to which the expression would evaluate**. decltype does this without evaluating the variable or the expression
```CPP
void m1(){
int i = 5;
auto usi = (unsigned short int)i;
cout<<usi<<endl;
cout << boolalpha << is_same_v<decltype(usi),short unsigned int> << endl;
}
void m2(){
int usi = 5;
usi = (unsigned short int)usi;
cout<<usi<<endl;
cout << boolalpha << is_same_v<decltype(usi),short unsigned int> << endl;
}
int main(){
m1();
m2();
return 0;
} //result: 5 true 5 false
``` 
- -
	- ### functional cast:
		- `auto ssi = short(i);`
		- similar to syntax of function call
		- only works for *elementary type names* -> no `short signed int(i)`
		- Initializing a reference to a derived class with an object of a base class is not legal
	- ### up-/downcasting (p 116 (133)):
		- upcasting:
			- is the process of converting a pointer or reference from a derived class to one of its base classes. This is generally safe and does not require explicit casting because every derived class object is also a base class object
			- `Derived derived; Base* base = &derived; // Upcasting base->show(); // Calls Derived::show() because of virtual function`
		- downcasting:
			- is the process of converting a pointer or reference from a base class to a derived class. This is less safe because the base class might not actually point to an object of the derived class. Therefore, explicit casting is required, and runtime checks are often used to ensure safety
			- `Base* base = new Derived(); //Upcasting Derived* derived = dynamic_cast<Derived*>(base); //Downcasting`
	- ### static_cast<>():
		- is a modern cast
		- converts at compile time
		- supports conversion between int, enum and float also
		- `auto i = static_cast<int>('j');`
	- ### const_cast<>():
		- https://www.youtube.com/watch?v=2_-BS9UI0po
		- removes constness from objects (only purpose)
		- can not change the type
		- affects only the object => must **always** be a reference or a pointer to the argument type
		- `const_cast<Base&>(obj)`
		- should not be applied to temporary objects or const objects => leads to undefined behavior
	- ### dynamic_cast<>():
		- https://www.geeksforgeeks.org/dynamic-_cast-in-cpp/
		- bound to inclusion polymorphism
		- is used for both upcasting and downcasting in inclusion polymorphism, allowing for safe type conversions at runtime
		- If a `dynamic_cast` cannot return the desired object, it returns a **null pointer**
		- . If the cast fails and the target is a reference, then it throws a **`std::bad_cast` exception**
		- To work on **dynamic_cast** there must be one virtual function in the base class
		- requires vtbl pointer of object
		- can't remove constness
		- checks validity of cast at runtime
		- it would be possible to apply const_cast<>() immediately to the result returned by dynamic_cast<>()
		- **don't** use if not needed
	- ### reinterpret_cast<>():
		- supports any conversions
		- can't remove constness
		- does not create a new value
		- **is not portable**
		- **dangerous**: compiler checks only for const correctness
		- Conversions that can be performed by `reinterpret_cast` are based on reinterpreting the binary representations of the types. In **most cases** results in code are **system-specific**, and thus non-portable
		- `reinterpret_cast` converts any pointer type to any other pointer type, even of unrelated classes! The operation result is a simple binary copy of the value from one pointer to the other. There are no checks involved.
- ## Type identification:
	- define a new class or create object for it (*meta-programming*) is not possible in C++
	- C++ provides a runtime type identification mechanism (*RTTI*). It allows you to identify the dynamic type of an object at runtime and to perform type-safe downcasting using `dynamic_cast`.
	- ### dynamic type:
		- **typeid(type)** is used for dynamic type or runtime type information of object
		- `const type_info& ta = typeid(a);`
		- `ta.name()` to retrieve name
		- `typeid() == typeid()` and `is_same_v<>` **cannot** be used interchangeably. `typeid()` would ignore const and volatile
- ## Exceptions:
	- It is more desirable to inform the program about the specific error situation and give it a chance to fix the error and try again or to perform another appropriate action – if possible
	- dynamic_cast<> fails -> bad_cast exception
	- if there is no function that catches specific exception, it will be catched by general exception handler
	- An exception should generally be caught as a reference to const: `catch (const overflow_error& e)`. Because:
		- it should not modify the exception object
		- true type/dynamic type of the exception should be preserved
		- Catching by reference to const avoids the overhead of copying the exception object
		- If the catch handler were to catch the exception by value, a new exemplar would be created with the specified type. After that, it would be impossible to recover the true type of the original exception exemplar
	- you can specify multiple catch handlers
	- The std::out_of_range exception inherits from std::logic_error, which is itself a child of std::exception.
	- It's generally recommended that destructors should **not throw** exceptions unless there's no reasonable way to handle the cleanup failure within the destructor itself. Therefore destructors are implicitly specified as `noexcept(true)`.
	- ### stack-unwinding:
		- any fully constructed object is being automatically destroyed when exception is thrown, function call stack is being reset. This is *stack unwinding*
		- Stack unwinding refers to the automatic deallocation of local variables and objects as a program exits a function or scope, ensuring efficient memory management
		- If during stack unwinding a destructor throws an exception and that exception is not handled, the `terminate()` function is called
		- a try block must specify a compound statement
		- *Stack unwinding aims at leaving the program in a well-defined state as far as possible in an automated way*. In particular this means that the the function call stack is reset to the function that catches the exception and that all objects are destroyed that were previously fully constructed
		- any state change that can't be preserved by undone unwinding should be reversed manually by catch handler
		- Ideally, a try block behaves like a database transaction either it succeeds completely, and the state changes it makes are preserved, or, if only a portion fails, the entire transaction fails and is rolled back
		- catch handler should **at least**:
			- finish program in defined way
			- return dynamic resources
			- provide error report
		- ### incomplete objects: ?
			- to avoid:
				- object should not directly own dynamic resource if destructor can throw error after acquiring this resource
		- Since a destructor should never throw an exception it is implicitly specified as `noexcept(true)`
		-  It is recommended not to use any explicit exception specification
	- ## Smart pointers:
		- are wrappers around real raw pointers
		- use `#include <memory>`
		- **unique_ptr**:
			- https://www.youtube.com/watch?v=UOB7-B2MfwA
			- is a scoped pointer
			- exclusive ownership
			- `unique_ptr` is a smart pointer that owns and manages another object through a pointer.
			-  When the `unique_ptr` goes out of scope it disposes of the managed object.
			- this pointer will be deleted when it gets out of scope
			- you can't copy a unique pointer. If you do though, you will have two un. pointers pointing to same block of memory 
			- `std::unique_ptr<Class> obj(new Class())`
			- preferred way:  `std::unique_ptr<Class> = std::make_unique<Class>()`:
				- exception safety features
				- avoids dangling pointer with memory leak
			- stack allocated object
		- **shared_ptr**:
			- https://www.youtube.com/watch?v=Tp5-f9YAzNk
			- `shared_ptr<Class> obj = make_share<Class>()` DO THIS WAY!
			- manages memory of given object
			- when last shared ptr pointing to memory block is destroyed or reset, memory is being freed -> prevents memory leaks
			- **Shared ownership**:
				- multiple share_ptr objects share same memory. Also, when you create a new one from existing one, they both point to same object, SO the memory WON'T be freed until they all are destroyed or reset
			- **Reference count** (use count):
				- tracks how many objects share the same memory
			- can be used for downcast and upcast
			- **Custom deleters**:
				- allows to specify a special function that will be calls when object is about to be released
				- can be used for additional clean up
				- `std::shared_ptr<Class> obj(new Class(), custom_deleter)`
			- shared ptr from another share ptr: `shared_ptr<Class> pt2 = pt1`
		- **weak_ptr**:
			- observer for a shared pointer
			- doesn't claim ownership of managed object
			- tracks without increasing reference count -> does not extend lifetime of managed object
			- you can't directly access manage object
			- `shared_ptr<Class> sp (new Class(), custom_deleter); weak_ptr<Class> wp = sp;`
			- **lock** weak pointer to dereference:
				- `shared_ptr<Class> locked = wp.lock(); locked->do();`
				- actually the right way, cause after shared ptr leaves scope, reference counter will decrement again:
				- ![[Bildschirmfoto 2024-06-16 um 23.33.31.png]]
			- if shared pointer is reset or destroyed, weak ptr will expire
- ## Function template
	- a form for (overloaded?) function
	- avoid ambiguity. WON'T WORK:
```CPP
template<typename Y>
void add(Y& a, Y& b)
{
	cout<<(a+b)<<endl;
}
template<class P, class P>
void add(P&a, P&b)
{
	cout<<(a+b)<<endl;
}
```
- -
	- 
- ## FLTK:
	- compile: `fltk-config --compile GuiMove.cpp`



___
- ## Exam:
	- Grossteil der Fragen - OOP, 2-groesste - Generic Paradigm 