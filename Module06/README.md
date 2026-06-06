# Module 06 Study Guide

This module is about C++ type conversion, runtime type identification, and safe casting.

## What you should know

### 1. C++ cast operators

You are expected to understand the main C++ casts and when to use them:

- `static_cast` for normal compile-time conversions between compatible types.
- `reinterpret_cast` for low-level reinterpreting of bits or addresses.
- `dynamic_cast` for safe downcasting in class hierarchies that use polymorphism.
- `const_cast` for adding or removing `const` only when you really know it is safe.

In this module, the important ones are mainly `static_cast`, `reinterpret_cast`, and `dynamic_cast`.

### 2. Polymorphism

Polymorphism means working with objects through a base class pointer or reference while the real object is a derived class.

To make `dynamic_cast` work, the base class must be polymorphic, which usually means it has at least one virtual function. A virtual destructor is the safest choice.

### 3. RTTI

RTTI means Run-Time Type Information. It lets C++ know the real type of an object at runtime.

`dynamic_cast` uses RTTI to:

- safely check whether a base pointer really points to a derived object,
- safely convert a base reference to a derived reference,
- fail cleanly if the cast is not valid.

### 4. Integer and floating-point limits

When converting between numeric types, you must watch for:

- overflow,
- underflow,
- precision loss,
- special floating-point values such as `nan` and `inf`.

### 5. Pointer and integer conversions

`uintptr_t` is an unsigned integer type large enough to store a pointer value.

It is useful when you need to serialize a pointer into an integer and recover it later.

## Exercise by exercise

### ex00 - ScalarConverter

Goal: convert a string into:

- `char`
- `int`
- `float`
- `double`

What you should understand:

- parsing a string into a number,
- detecting pseudo-literals like `nan` and `inf`,
- deciding when a conversion is impossible,
- printing `Non displayable` for control characters,
- handling precision and overflow correctly.

Important edge cases:

- one-character input like `a`,
- values outside the `int` range,
- values that become rounded in `float`,
- `nan`, `nanf`, `+inf`, `-inf`, `+inff`, `-inff`.

### ex01 - Serializer

Goal: convert a `Data*` pointer to an integer type and back again.

What you should understand:

- why `reinterpret_cast` is used here,
- why this is not real serialization in the file/network sense,
- the difference between storing an address and copying an object,
- that the pointer must survive the round trip unchanged.

Key idea:

- `serialize` turns `Data*` into `uintptr_t`,
- `deserialize` turns `uintptr_t` back into `Data*`.

### ex02 - Identify Real Type

Goal: generate one object randomly from classes `A`, `B`, or `C`, then identify its real type through a base class pointer or reference.

What you should understand:

- inheritance,
- virtual destructors,
- downcasting,
- the difference between pointer and reference behavior with `dynamic_cast`.

Important behavior:

- `dynamic_cast<T*>(ptr)` returns `nullptr` when the cast fails.
- `dynamic_cast<T&>(ref)` throws an exception when the cast fails.

## Common mistakes

- Using `reinterpret_cast` when `static_cast` or `dynamic_cast` is the correct tool.
- Forgetting to make the base class polymorphic before using `dynamic_cast`.
- Assuming every float can safely become an `int`.
- Printing wrong results for pseudo-literals like `nan` and `inf`.
- Treating pointer-to-integer conversion as real serialization.
- Not checking pointer validity before using it.

## What to remember for the exam

- Know which cast to use for each situation.
- Know the difference between compile-time and runtime type checks.
- Understand object lifetime and pointer validity.
- Be comfortable with inheritance, virtual functions, and RTTI.
- Always think about boundary values when converting numbers.

## Short summary

If you can explain why each cast exists, when it is safe, and what can go wrong during conversion, you understand this module well enough.