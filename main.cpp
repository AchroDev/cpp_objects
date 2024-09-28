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
        Entity *entity = new Entity("AchroDev");     // Now we are allocating the entity on the heap, declared with 'new' and using a pointer
        e = entity;                                  // The entity is already a pointer now so we no longer need to reference
        std::cout << entity->GetName() << std::endl; // Now that the entity is a pointer, you have to either implicitly dereference or use the arrow operator
        delete entity;                               // You must delete the object from the heap after allocating
    }
    // Once we leave this scope the "AchroDev" assignment is gone, this is where you would want to use heap allocation instead

    std::cin.get();
}
