# CSCI 272 - Lesson 04: Classes and Objects

Instructor: Avijit Roy

Teaching page: https://avijitroy.com/teaching/

This lesson moves from a class definition to objects with their own data, then introduces controlled access, constructors, pointers to objects, and object lifetime. Examples 01-07 build on the same `Car` idea; example 08 applies encapsulation to a bank account. Example 09 is an optional introduction to copying objects.

Review functions, scope, references, pointers, and strings before starting. Constructors and destructors are introduced here and can be explored further in later class lessons.

## Learning Outcomes

After working through the examples, you should be able to:

- define a class and create objects from it;
- distinguish data members from member functions;
- explain why separate objects have independent non-static data members;
- access public members with `.` and through a valid pointer with `->`;
- use private data and public member functions to control changes;
- explain how constructors initialize objects and how constructor overloading works;
- trace when local objects are constructed and destroyed; and
- explain how copy construction creates a separate object in the optional example.

## Use the Examples as Experiments

Read the opening comments, predict the output, run the unchanged program, complete a `TRY THIS` task, and explain what changed. Each file is an independent program with its own `main()` and class definition. Open, compile, and run one file at a time in your IDE; do not combine the examples into one program.

Follow examples 01-08 in order. Try 09 when you can confidently explain objects, references, and constructors. Comments use natural paragraphs so your editor can wrap the text to fit your window.

## Learning Path

| File | Main idea | Expected behavior and experiment |
| --- | --- | --- |
| [01_first_class.cpp](01_first_class.cpp) | Class, object, data, behavior, and `.` | Displays Volkswagen, Polo, 2012, then `Engine started!`. Change the model and add a color member. |
| [02_object_state.cpp](02_object_state.cpp) | Independent object state | Displays Volkswagen Polo 2012 and Tesla Model X 2022. Change only `car1.year`, then display both objects. |
| [03_private_data.cpp](03_private_data.cpp) | Private data and a public interface | `setData()` sets the values; an invalid year is replaced with 1886. Compare a public function call with the commented direct-access statement. |
| [04_constructor.cpp](04_constructor.cpp) | Initialize an object during creation | Two constructor messages appear before the two records. Predict whether a declaration with no arguments compiles. |
| [05_constructor_overloading.cpp](05_constructor_overloading.cpp) | Default and parameterized constructors | One object uses the default constructor and two use the three-argument version. Add a one-argument constructor. |
| [06_object_pointers.cpp](06_object_pointers.cpp) | `.`, `->`, and `(*pointer).` | Four calls display `Model: Polo`; all access the same object. Redirect the pointer to a second live object. |
| [07_destructor.cpp](07_destructor.cpp) | Scope and object lifetime | Tesla is destroyed at the inner closing brace; Polo is destroyed as `main()` exits. Add another inner object and predict destruction order. |
| [08_bank_account.cpp](08_bank_account.cpp) | Encapsulation and validation | Balance starts at 1000 and ends at 1200 after a deposit of 500 and withdrawal of 300. Test rejected operations and confirm the balance stays unchanged. |
| [09_copy_constructor.cpp](09_copy_constructor.cpp) | Optional: copy construction | A regular constructor creates the original and a copy constructor creates the second object. Changing the copy's year to 2025 leaves the original at 2012. |

## Ideas to Keep Separate

**Class versus object:** `Car` defines the type. `Car car1;` creates an object. The object stores its own non-static member values; the class definition describes which members exist. `startEngine()` is a member function, while `brand` is a data member.

**Access versus validation:** `private` prevents direct access from outside the class. Public functions decide which operations are permitted and implement validation. In example 03, 1886 is the chosen minimum year. Merely making `year` private does not enforce that rule automatically. Members of a `class` are private by default unless an access label changes this.

**Initialization versus assignment:** Examples 01-03 give integer members initial values so reading a newly created object is safe. Example 03 also initializes the text members to `Unknown`. Constructors in later examples assign the desired values before construction finishes. Member initializer lists are another initialization technique for later study. Example 04 does not yet validate the supplied year; adding that rule is an exercise.

**Default versus parameterized construction:** A default constructor can be called without arguments. Once you declare a parameterized constructor, the compiler does not automatically add a no-argument constructor. Example 05 explicitly supplies both. `Car car1;` creates an object; `Car car1();` declares a function instead. In example 05, year 0 represents an unspecified year.

**Reading versus changing an object:** A member function marked `const`, such as `display() const`, promises not to change ordinary data members through that object. It can read private data to display it.

**Object versus pointer:** `Car* carPointer = &car1;` stores the address of an existing object. It creates no second `Car`. `carPointer->display()` and `(*carPointer).display()` refer to that same object. The address can change between runs, so predict relationships rather than an exact address.

**Scope versus lifetime:** A local object's lifetime normally ends when execution leaves its scope. The destructor runs automatically, and local objects in the same scope are destroyed in reverse construction order. The example prints messages to make this visible; it owns no resource requiring manual cleanup. Do not explicitly call its destructor or delete a pointer to one of these local objects. **DO NOT RUN** a null-pointer dereference or access an object through a pointer after its lifetime ends.

**Copy versus alias:** In example 09, `Car car2(car1);` creates a separate object by copying its string and integer members. `const Car& other` refers to the source without copying it again or allowing the copy constructor to modify it. A compiler-generated copy constructor would already handle these members; the explicit version makes the call visible. Copying an owning raw pointer raises additional questions for later lessons. Initialization with `Car car2 = car1;` is also copy construction; assignment to an already existing object is a different operation.

**Model versus full application:** The bank account demonstrates controlled state changes using fixed sample amounts. Its `double` values and default output format are a simplified teaching model. Numerical representation, monetary rounding, and complete banking rules require further design.

## Checkpoint Challenges

1. Create two cars and change only the first car's year. Print both and explain the independent state.
2. Add a public function to example 03 that updates only the year while preserving its minimum-year rule. Confirm an invalid request cannot store an invalid year.
3. Apply the same year rule in example 04's constructor. Compare initialization with later updates through a public function.
4. Add a second bank account. Perform valid and invalid operations on one account and verify the other stays unchanged.
5. Add a `const` balance getter to the bank account and use it to compare balances before and after a rejected withdrawal.
6. Optional: copy a car, change the copy, and contrast this with a pointer that refers to the original.

## Reflection Check

1. How do a class definition and an object declaration differ?
2. Why can two objects of the same class contain different values?
3. Why does encapsulation require more than the word `private`?
4. What tells the compiler which overloaded constructor to use?
5. Why does a pointer to an object not create another object?
6. When is the inner-scope object destroyed, and why?
7. Why is a copy constructor's source passed by reference?

Continue to [Lesson 05: Streams and Input/Output](../Lesson%2005/README.md) after completing the core examples.
