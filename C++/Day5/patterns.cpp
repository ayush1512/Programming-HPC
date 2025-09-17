#include <iostream>
#include <vector>
#include <future>

using namespace std;

// Memento Pattern
class Memento {
    string state;
public:
    Memento(const string& s) : state(s) {}
    string getState() const { return state; }
};

class Editor {
    string content;
public:
    void setContent(const string& s) { content = s; }
    string getContent() const { return content; }

    Memento save() const {
        return Memento(content);
    }

    void restore(const Memento& m) {
        content = m.getState();
    }
};

// Observer Pattern
class Observer {
public:
    virtual void update(const string& message) = 0;
};

class User : public Observer {
    string name;
public:
    User(const string& n) : name(n) {};

    void update(const string& message) override {
        cout << "User " << name << " received message: " << message << endl;
    }
};

class Group {
    vector<Observer*> observers;
public:
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }

    void notify(const string& message) {
        for (auto obs : observers) {
            obs->update(message);
        }
    }
};

// Iterator Pattern
class Collection {
    
public:
    vector<int> items;
    void addItem(int item) {
        items.push_back(item);
    }
};

class Iterator{
    const Collection& collection; 
    size_t index;
public:
    Iterator(const Collection& col) : collection(col), index(0) {}

    bool hasNext() const {
        return index < collection.items.size();
    }

    int next() {
        return collection.items[index++];
    }
};

// Composite Pattern

class FileSystem{
public:
    virtual void display(int depth) const = 0;
    virtual ~FileSystem() = default;
};

class File : public FileSystem {
    string name;
public:
    File(const string& n) : name(n) {}
    void display(int depth) const {
        cout << string(depth, '-') << name << endl;
    }
};

class Directory : public FileSystem {
    string name;
    vector<Directory*> subDirs;
    vector<File*> files;
public:
    Directory(const string& n) : name(n) {}

    void display(int depth) const override {
        cout << string(depth, '-') << name << endl;
        for (const auto& file : files) {
            file->display(depth + 2);
        }
        for (const auto& dir : subDirs) {
            dir->display(depth + 2);
        }
    }

    void addDirectory(Directory* dir) {
        subDirs.push_back(dir);
    }

    void addFile(File* file) {
        files.push_back(file);
    }
};

// Command Pattern
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class LightOnCommand : public Command {
public:
    void execute() override {
        cout << "Light is ON" << endl;
    }
};

class LightOffCommand : public Command {
public:
    void execute() override {
        cout << "Light is OFF" << endl;
    }
};

class Remote{
    Command* command; //
public:
    void setCommand(Command* cmd) {
        command = cmd;
    }

    void pressButton() {
        if (command) {
            command->execute();
        }
    }
};

// Pointer to member of class and member function
class A{
    public:
    int data;
    A(int val): data(val) {}
    void show() { cout << "Data: " << data << endl; }
};

int main() {

    // Memento Pattern Demo
    Editor editor;
    editor.setContent("Version 1");
    cout << "Current Content: " << editor.getContent() << endl;

    Memento memento = editor.save();

    editor.setContent("Version 2");
    cout << "Current Content: " << editor.getContent() << endl;

    editor.restore(memento);
    cout << "Restored Content: " << editor.getContent() << endl;

    // Observer Pattern Demo
    Group group;
    User user1("Alice");
    User user2("Bob");

    group.addObserver(&user1);
    group.addObserver(&user2);

    group.notify("Hello, Observers!");

    // Iterator Pattern Demo
    Collection collection;
    collection.addItem(1);
    collection.addItem(2);

    Iterator iterator(collection);
    while (iterator.hasNext()) {
        cout << "Item: " << iterator.next() << endl;
    }

    // Composite Pattern Demo
    Directory root("root");
    Directory* home = new Directory("home");
    Directory* user = new Directory("user");
    File* file1 = new File("file1.txt");
    File* file2 = new File("file2.txt");
    user->addFile(file1);
    home->addFile(file2);
    root.addDirectory(home);
    root.addDirectory(user);

    root.display(1);


    // Command Pattern Demo
    Remote remote;
    LightOnCommand lightOn;
    LightOffCommand lightOff;

    remote.setCommand(&lightOn);
    remote.pressButton();

    remote.setCommand(&lightOff);
    remote.pressButton();

    // auto future = async();
    cout << "Asynchronous task completed." << endl;
    // future.get();

    //Pointer to member of class and member function
    auto A::*ptr = &A::data; // Pointer to member variable
    auto A::*showPtr = &A::show; // Pointer to member function

    A obj(42);
    cout << "Accessing member data using pointer to member: " << obj.*ptr << endl;
    (obj.*showPtr)(); // Calling member function using pointer to member function


    return 0;
}