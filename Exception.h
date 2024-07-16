
#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <exception>
#include <string>
#include <iostream>


class DeckFileNotFound : public std::exception 
{
    public:
    void what() {
        std::cout << "Deck File Error: File not found" << std::endl;
    }
};

class DeckFileFormatError : public std::exception
{
    private:
    int m_line;
    std::string m_problem;
    public:
    explicit DeckFileFormatError(int line) : m_line(line)
    {
        m_problem = "Deck File Error: File format error in line " + std::to_string(m_line);
    }
    const char* what() const noexcept override{
        return m_problem.c_str();
    }
};

class DeckFileInvalidSize : public std::exception
{
    public:
    const char* what() const noexcept override{
        return"Deck File Error: Deck size is invalid";
    }
};

#endif