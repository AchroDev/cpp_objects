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

// Example function of when the object shouldn't be created this way.
void Function()
{
    int a = 2;
    // When you create the object like this, it lives on the stack and will be deleted once the function call ends
    Entity entity = Entity("AchroDev");
}

int main()
{
    Function();

    Entity entity = Entity("AchroDev");         // This does the same thing just written slightly different
    std::cout << entity.GetName() << std::endl; // Printing the value stored for the name of the Entity
    std::cin.get();
}
