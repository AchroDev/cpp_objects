#include <iostream>
#include <string>

// Using this to simplify declaring/calling strings
using String = std::string;

// Objects and how to properly create/instantiate them in C++

// Example Entity class
class Entity
{
    // Single private object 'm_Name'
private:
    String m_Name;
    // Public section
public:
    // Default constructor initializing m_Name
    Entity() : m_Name("Unknown") {}
    // Other constructor setting m_Name to the referenced 'name' value
    Entity(const String &name) : m_Name(name) {}

    // Simple getter for the name
    const String &GetName() const { return m_Name; }
};

int main()
{
    Entity *e; // Entity pointer
    // Example scope showing code that would fail when writing the object to the stack
    {
        Entity entity("AchroDev");                  // This does the same thing just written slightly different
        e = &entity;                                // Assigning the entity pointer to the memory address of the entity.
        std::cout << entity.GetName() << std::endl; // Printing the value stored for the name of the Entity
    }
    // Once we leave this scope the "AchroDev" assignment is gone

    std::cin.get();
}
