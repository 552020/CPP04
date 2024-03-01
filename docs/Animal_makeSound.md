# Animal.makeSound()

Should we implement the makeSound function in the parent class Animal, if it will be always overwritten by the derived classes?

When designing a class hierarchy in C++ that involves a method like `makeSound()` in a base class `Animal` and its subclasses, such as `Cat` and `Dog`, there are three common approaches to consider, each with its own implications for design and functionality:

### 1. Pure Virtual Function (Abstract Method)

If the intention is for `Animal` to be an abstract base class that should never be instantiated directly, you can declare `makeSound()` as a pure virtual function. This approach mandates that all subclasses provide their own implementation of `makeSound()`, making `Animal` an abstract class that defines a contract for its subclasses.

```cpp
class Animal {
public:
    virtual void makeSound() = 0; // Pure virtual function
};
```

If a subclass derived from an abstract class does not override all pure virtual functions, it is considered abstract itself. This means if you attempt to instantiate such a subclass, the compiler will produce an error, indicating that you cannot instantiate an abstract class.

### 2. Providing a Default Implementation

Another approach is to provide a default implementation of `makeSound()` in the `Animal` class. This can be useful if there is a generic sound or behavior that is common to most, but not all, animals. Subclasses can override this method to provide a more specific implementation, or use the default if it is appropriate for them.

```cpp
class Animal {
public:
    virtual void makeSound() {
        std::cout << "Some generic animal sound\n";
    }
};
```

### 3. Interface Without Implementation

The term "interface" in C++ is not formally defined as it is in languages like Java, but you can use a class as an interface by having only pure virtual functions (and no data members). This would mean not providing any implementation in the `Animal` class, not even as a default, which forces all concrete subclasses to implement all the methods declared as pure virtual.

This approach is akin to the first scenario but emphasizes the class's role as purely a contract for behavior without suggesting any default behavior.

### Conclusion

Whether to implement `makeSound()` in the `Animal` class depends on the specific requirements of your application and how you intend to use the class hierarchy:

- **Abstract Class with Pure Virtual Function**: Choose this if every animal must make a sound, but the sound is specific to each subclass, with no reasonable default.
- **Base Class with Default Implementation**: Useful when a default implementation is appropriate for many (but not necessarily all) animals.
- **Interface Approach**: When `Animal` should only define a set of behaviors (like making a sound) without any default implementation, ensuring all concrete animals explicitly define their own sounds.

Each approach has its use cases, and the choice depends on the desired flexibility, extensibility, and the specific design requirements of your system.
