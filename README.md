*This project has been created as part of the 42 curriculum by yhajji.*

---

# 42 C++ Modules

A complete overview of the **C++ modules (CPP 00 → CPP 09)** from the [42 Network](https://42.fr/en/homepage/).

These modules introduce C++ progressively, starting with the basics of classes and objects, then moving through memory management, inheritance, polymorphism, exceptions, casts, templates, and finally the STL.

---

## 📚 Table of Contents

- [CPP 00 — Introduction to C++](#cpp-00--introduction-to-c)
- [CPP 01 — Memory Allocation, References and Pointers](#cpp-01--memory-allocation-references-and-pointers)
- [CPP 02 — Ad-hoc Polymorphism & Operator Overloading](#cpp-02--ad-hoc-polymorphism--operator-overloading)
- [CPP 03 — Inheritance](#cpp-03--inheritance)
- [CPP 04 — Subtype Polymorphism, Abstract Classes & Interfaces](#cpp-04--subtype-polymorphism-abstract-classes--interfaces)
- [CPP 05 — Repetition & Exceptions](#cpp-05--repetition--exceptions)
- [CPP 06 — C++ Casts](#cpp-06--c-casts)
- [CPP 07 — Templates](#cpp-07--templates)
- [CPP 08 — Templated Containers, Iterators & Algorithms](#cpp-08--templated-containers-iterators--algorithms)
- [CPP 09 — STL Containers](#cpp-09--stl-containers)
- [Learning Path](#-learning-path)
- [Key C++ Concepts](#-key-c-concepts)

---

# CPP 00 — Introduction to C++

The first module is about understanding the **fundamentals of C++** and the differences between C and C++.

### Main concepts

- Namespaces
- Classes and objects
- Constructors
- Destructors
- Member functions
- `private` / `public`
- `const` member functions
- Static members
- `this` pointer
- Initialization lists
- Standard input/output streams
- `std::cout`, `std::cin`, `std::endl`
- Basic C++ syntax

### Exercises

| Exercise | Topic | What you learn |
|---|---|---|
| `ex00` | Megaphone | Basic C++ syntax and streams |
| `ex01` | PhoneBook | Classes, objects, encapsulation |
| `ex02` | Account | Classes, constructors, member functions, static members |

### Goal

Move from procedural C programming toward **object-oriented programming**.

---

# CPP 01 — Memory Allocation, References and Pointers

This module introduces important differences between **stack and heap memory**, references, pointers, and the use of `new` / `delete`.

### Main concepts

- Stack vs Heap
- Dynamic allocation
- `new` and `delete`
- References
- Pointers
- Pointers to member functions
- `switch`
- File streams
- Resource management

### Exercises

| Exercise | Topic |
|---|---|
| `ex00` | BraiiiiiiinnnzzzZ |
| `ex01` | Moar brainz! |
| `ex02` | HI THIS IS BRAIN |
| `ex03` | Unnecessary violence |
| `ex04` | Sed is for losers |
| `ex05` | Harl 2.0 |
| `ex06` | Harl filter |

### Important distinction

A **pointer** can be `NULL`, can be reassigned, and uses `*` / `->`.

A **reference** must refer to an existing object and normally cannot be reseated.

```cpp
int value = 42;

int *ptr = &value;
int &ref = value;

*ptr = 10;
ref = 20;
```

### Goal

Understand how objects are stored and manipulated in memory while using C++ abstractions instead of C-style programming.

---

# CPP 02 — Ad-hoc Polymorphism & Operator Overloading

This module introduces **operator overloading**, fixed-point numbers, and the **Orthodox Canonical Form**.

### Main concepts

- Operator overloading
- Orthodox Canonical Form
- Copy constructor
- Copy assignment operator
- Destructor
- Constructors
- `const` correctness
- Fixed-point arithmetic
- Conversion operators

### Exercises

| Exercise | Topic |
|---|---|
| `ex00` | Fixed-point class |
| `ex01` | Fixed-point conversions |
| `ex02` | Fixed-point arithmetic and comparisons |

### Orthodox Canonical Form

A classic C++ class is expected to properly handle:

```cpp
Class();
Class(const Class &other);
Class &operator=(const Class &other);
~Class();
```

These correspond to:

1. Default constructor
2. Copy constructor
3. Copy assignment operator
4. Destructor

### Goal

Learn how C++ lets you define the behavior of operators for your own classes.

Example:

```cpp
Fixed a(5);
Fixed b(3);

Fixed c = a + b;
```

The `+` operator can be overloaded to make this possible.

---

# CPP 03 — Inheritance

CPP 03 introduces **inheritance** and shows how classes can extend and specialize other classes.

### Main concepts

- Base classes
- Derived classes
- `protected`
- Inheritance
- Constructor/destructor chaining
- Method overriding
- Multiple inheritance

### Exercises

| Exercise | Topic |
|---|---|
| `ex00` | ClapTrap |
| `ex01` | ScavTrap |
| `ex02` | FragTrap |
| `ex03` | DiamondTrap |

### Example

```text
        ClapTrap
        /      \
   ScavTrap   FragTrap
        \      /
       DiamondTrap
```

This module helps understand how code can be reused through class hierarchies.

### Goal

Build relationships between classes and understand how constructors, destructors, and inherited members behave.

---

# CPP 04 — Subtype Polymorphism, Abstract Classes & Interfaces

This is where **runtime polymorphism** becomes a major topic.

### Main concepts

- Polymorphism
- Virtual functions
- Pure virtual functions
- Abstract classes
- Virtual destructors
- Deep copy
- Interfaces
- Composition
- Dynamic dispatch

### Exercises

| Exercise | Topic |
|---|---|
| `ex00` | Animal hierarchy |
| `ex01` | Deep copy with `Brain` |
| `ex02` | Abstract `Animal` |
| `ex03` | Materia interface system |

### Virtual functions

A base class can define a virtual function:

```cpp
class Animal
{
public:
    virtual void makeSound() const;
    virtual ~Animal();
};
```

Then derived classes can override it:

```cpp
class Dog : public Animal
{
public:
    void makeSound() const override;
};
```

This allows:

```cpp
Animal *animal = new Dog();
animal->makeSound();
```

The correct `Dog` implementation is called at runtime.

### Deep copy

CPP 04 also introduces the difference between:

- **Shallow copy** → copying addresses/references to the same data
- **Deep copy** → allocating new memory and copying the actual data

### Goal

Understand one of the most important ideas in object-oriented programming:

> Program against an abstraction, not a specific implementation.

---

# CPP 05 — Repetition & Exceptions

CPP 05 introduces **exceptions** and more complex class relationships.

### Main concepts

- Exceptions
- `try`
- `catch`
- `throw`
- Custom exception classes
- Nested classes
- Inheritance with exceptions
- `const`

### Exercises

| Exercise | Topic |
|---|---|
| `ex00` | Bureaucrat |
| `ex01` | Form |
| `ex02` | Abstract Form and concrete forms |
| `ex03` | Intern |

### Example

```cpp
try
{
    bureaucrat.incrementGrade();
}
catch (const std::exception &e)
{
    std::cout << e.what() << std::endl;
}
```

### Exception design

A custom exception can inherit from `std::exception`:

```cpp
class GradeTooHighException : public std::exception
{
public:
    const char *what() const throw();
};
```

### Goal

Learn how C++ handles errors through **exceptions** instead of relying only on return values.

---

# CPP 06 — C++ Casts

CPP 06 focuses on the different types of **C++ casting**.

### Main concepts

- `static_cast`
- `dynamic_cast`
- `reinterpret_cast`
- `const_cast`
- Type conversion
- Serialization
- Runtime type identification

### Exercises

| Exercise | Topic |
|---|---|
| `ex00` | Scalar conversion |
| `ex01` | Serialization |
| `ex02` | Identify the real type |

### `static_cast`

Used for explicit conversions that are known at compile time:

```cpp
double value = 42.5;
int number = static_cast<int>(value);
```

### `dynamic_cast`

Used mainly with polymorphic class hierarchies when you need to safely identify or convert derived objects at runtime.

### `reinterpret_cast`

Performs a low-level reinterpretation of a value. It should be used carefully.

### `const_cast`

Used to add or remove `const` from a type.

### Goal

Understand **why C++ provides multiple casts** and when each one should be used.

---

# CPP 07 — Templates

CPP 07 introduces **templates**, one of the foundations of generic programming in C++.

### Main concepts

- Function templates
- Class templates
- Generic programming
- Template instantiation
- `typename`
- Reusable algorithms

### Exercises

| Exercise | Topic |
|---|---|
| `ex00` | Function templates |
| `ex01` | `iter` |
| `ex02` | `Array` template |

### Function template

Instead of writing:

```cpp
int max(int a, int b);
double max(double a, double b);
```

You can write:

```cpp
template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}
```

Now the same function can work with many types.

### Class template

```cpp
template <typename T>
class Array
{
private:
    T *_data;
    unsigned int _size;
};
```

### Goal

Learn how to write code that works with **different data types without duplicating the implementation**.

---

# CPP 08 — Templated Containers, Iterators & Algorithms

CPP 08 introduces the standard concepts behind **STL-style programming**.

### Main concepts

- STL containers
- Iterators
- Algorithms
- Function templates
- `std::vector`
- `std::list`
- `std::stack`
- Generic programming

### Exercises

| Exercise | Topic |
|---|---|
| `ex00` | `easyfind` |
| `ex01` | `Span` |
| `ex02` | `MutantStack` |

### Iterators

An iterator allows you to move through a container without depending on its internal implementation.

Example:

```cpp
std::vector<int> numbers;

for (std::vector<int>::iterator it = numbers.begin();
     it != numbers.end();
     ++it)
{
    std::cout << *it << std::endl;
}
```

### Algorithms

The STL provides generic algorithms such as:

```cpp
std::find()
std::sort()
std::copy()
std::for_each()
```

### Goal

Learn how containers, iterators, and generic algorithms work together.

---

# CPP 09 — STL Containers

The final C++ module focuses heavily on the **Standard Template Library (STL)** and choosing the correct container for a problem.

### Main concepts

- STL containers
- `std::map`
- `std::stack`
- `std::vector`
- `std::deque`
- Algorithms
- Parsing
- Time complexity
- Data structures
- Iterator usage

### Exercises

| Exercise | Topic | Main container |
|---|---|---|
| `ex00` | Bitcoin Exchange | `std::map` |
| `ex01` | Reverse Polish Notation | `std::stack` |
| `ex02` | PmergeMe | `std::vector` / `std::deque` |

### `std::map`

Stores key/value pairs:

```cpp
std::map<std::string, double> prices;

prices["BTC"] = 50000.0;
```

### `std::stack`

Follows **LIFO**:

```text
Push:
1
2
3

Pop:
3
2
1
```

### `std::vector`

A dynamic contiguous array:

```cpp
std::vector<int> numbers;
numbers.push_back(10);
numbers.push_back(20);
```

### `std::deque`

A double-ended queue that allows efficient insertion/removal at both ends.

### PmergeMe

The final exercise focuses on implementing and understanding a sorting approach using different STL containers.

### Goal

Choose and use the appropriate STL container and algorithm while thinking about **performance and complexity**.

---

# 🧠 Learning Path

The modules are designed to progressively build your understanding:

```text
CPP 00
  │
  ├── Classes & Objects
  │
CPP 01
  │
  ├── Memory / References / Pointers
  │
CPP 02
  │
  ├── Operator Overloading
  │
CPP 03
  │
  ├── Inheritance
  │
CPP 04
  │
  ├── Polymorphism / Abstract Classes
  │
CPP 05
  │
  ├── Exceptions
  │
CPP 06
  │
  ├── Casts / RTTI
  │
CPP 07
  │
  ├── Templates
  │
CPP 08
  │
  ├── Containers / Iterators / Algorithms
  │
CPP 09
  │
  └── STL / Data Structures / Algorithms
```

---

# 🔑 Key C++ Concepts Covered

By the end of CPP 00 → CPP 09, you should have worked with:

### Object-Oriented Programming

- Classes
- Objects
- Encapsulation
- Constructors
- Destructors
- Inheritance
- Polymorphism
- Abstract classes
- Interfaces

### Memory Management

- Stack
- Heap
- `new`
- `delete`
- Pointers
- References
- Deep copy
- Shallow copy

### Advanced C++

- Operator overloading
- Orthodox Canonical Form
- Virtual functions
- Pure virtual functions
- Exceptions
- C++ casts
- RTTI
- Templates

### STL

- `std::vector`
- `std::deque`
- `std::list`
- `std::stack`
- `std::map`
- Iterators
- Algorithms

---

# 🗺️ From C to C++

The C++ modules can be seen as a transition from low-level procedural programming to higher-level generic and object-oriented programming:

```text
C
│
├── Procedural Programming
├── Manual Memory Management
└── Functions
        │
        ▼
CPP 00
├── Classes
└── Encapsulation
        │
        ▼
CPP 01
├── Pointers
├── References
└── Dynamic Memory
        │
        ▼
CPP 02
├── Operator Overloading
└── Copy Semantics
        │
        ▼
CPP 03
└── Inheritance
        │
        ▼
CPP 04
├── Polymorphism
├── Abstract Classes
└── Interfaces
        │
        ▼
CPP 05
└── Exceptions
        │
        ▼
CPP 06
└── Type Casting
        │
        ▼
CPP 07
└── Templates
        │
        ▼
CPP 08
├── Containers
├── Iterators
└── Algorithms
        │
        ▼
CPP 09
└── STL + Data Structures + Algorithms
```

---

# 🎯 Final Goal

After completing **CPP 00 → CPP 09**, the objective is not only to know C++ syntax, but to understand how to design and implement programs using:

> **Object-Oriented Programming + Generic Programming + STL + Memory Management + Algorithms**

These modules provide the foundation needed to work on larger C++ projects and to approach C++ code with a deeper understanding of **abstraction, reusability, memory, and performance**.

---

## 📌 42 Network

This repository is part of my journey through the **42 Network** curriculum.

- 🌐 [42 Network](https://42.fr/en/homepage/)
- 💻 Language: **C++**
- 📚 Modules: **CPP 00 → CPP 09**
- 🎯 Focus: **Object-Oriented Programming, Generic Programming, STL & Algorithms**

---

## ⭐ Progress

- [x] CPP 00
- [x] CPP 01
- [x] CPP 02
- [x] CPP 03
- [x] CPP 04
- [x] CPP 05
- [x] CPP 06
- [x] CPP 07
- [x] CPP 08
- [x] CPP 09

---

> **"The best way to learn C++ is to understand what happens behind the abstractions."**
