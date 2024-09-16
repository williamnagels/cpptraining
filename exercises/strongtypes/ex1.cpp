#include <iostream>
#include <string>

// Define the Command struct
struct Command {
    Command(const char* command)
        : m_command(command), m_endIterator(m_command.end()) {}
    
    Command(const std::string& command)
        : m_command(command), m_endIterator(m_command.end()) {}
    
    void setMayPrintArguments(bool printArguments) {
        m_mayPrintArguments = printArguments;
    }
    
    std::string::const_iterator begin() const {
        return m_command.begin();
    }
    
    std::string::const_iterator end() const {
        return m_command.end();
    }
    
    const char* getUnsafeCString() const {
        return m_command.c_str();
    }
    
    // Print command based on the flag
    void printCommand(std::ostream& os) const {
        if (m_mayPrintArguments) {
            os << "Command: " << m_command;
        } else {
            os << "Arguments are hidden.";
        }
    }

private:
    std::string m_command;
    std::string::const_iterator m_endIterator;
    bool m_mayPrintArguments = false;

    // Friend function to enable ostream overload
    friend std::ostream& operator<<(std::ostream& os, const Command& cmd);
};

// Define the ostream overload
std::ostream& operator<<(std::ostream& os, const Command& cmd) {
    cmd.printCommand(os);
    return os;
}

int main() {
    // Create a Command object with a sample command
    Command cmd("run --option value --secret password123");
    
    // Test when printing arguments is not allowed
    cmd.setMayPrintArguments(false);
    std::cout << cmd << std::endl; // Should print "Arguments are hidden."

    // Test when printing arguments is allowed
    cmd.setMayPrintArguments(true);
    std::cout << cmd << std::endl; // Should print "Command: run --option value --secret password123"

    return 0;
}
