# Inheritane types

| Base Class Access Specifier | Public Inheritance | Protected Inheritance | Private Inheritance |
|-----------------------------|--------------------|-----------------------|---------------------|
| **public**                  | public             | protected             | private             |
| **protected**               | protected          | protected             | private             |
| **private**                 | Not accessible     | Not accessible        | Not accessible      |

### Key Points:
- **Public Inheritance**: The public and protected members of the base class keep their access levels in the derived class. Public inheritance signifies an "is-a" relationship, meaning the derived class is a subtype of the base class.
- **Protected Inheritance**: Both public and protected members of the base class become protected in the derived class. This means they can be accessed within the derived class and its subclasses, but not by objects of the derived class.
- **Private Inheritance**: Public and protected members of the base class become private in the derived class. This is used when the derived class wants to use the functionality of the base class but does not implement an "is-a" relationship. Private inheritance can be thought of as a form of implementation inheritance rather than interface inheritance.

Note: Private members of the base class are never accessible directly from the derived class, regardless of the type of inheritance. They can only be accessed through public or protected members (methods) of the base class that the derived class inherits.