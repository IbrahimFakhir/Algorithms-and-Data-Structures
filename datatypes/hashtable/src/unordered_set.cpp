#include <iostream>
#include <vector>
#include <list>
#include <memory>

template <typename T>
class HashSet {
private:
    std::vector<std::list<std::shared_ptr<T>>> table;
    size_t capacity;
    size_t size;
    
    size_t hash(const T& value) const {
        return std::hash<T>()(value) % capacity;
    }
    
public:
    HashSet(size_t capacity = 100) : capacity(capacity), size(0) {
        table.resize(capacity);
    }
    
    void insert(const T& value) {
        size_t index = hash(value);
        for (const auto& v : table[index]) {
            if (*v == value) {
                return; // value already exists
            }
        }
        table[index].push_back(std::make_shared<T>(value));
        size++;
        balance(); // balance after insertion
    }
    
    bool contains(const T& value) const {
        size_t index = hash(value);
        for (const auto& v : table[index]) {
            if (*v == value) {
                return true; // value found
            }
        }
        return false; // value not found
    }
    
    void remove(const T& value) {
        size_t index = hash(value);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (**it == value) {
                table[index].erase(it);
                size--;
                balance(); // balance after removal
                return; // value removed
            }
        }
    }
    
    size_t getSize() const {
        return size;
    }
    
    void balance() {
        double loadFactor = static_cast<double>(size) / capacity;
        if (loadFactor > 0.75) { // if load factor is too high, resize to double the capacity
            size_t newCapacity = capacity * 2;
            auto newTable = std::vector<std::list<std::shared_ptr<T>>>(newCapacity);
            for (size_t i = 0; i < capacity; i++) {
                for (const auto& value : table[i]) {
                    size_t index = hash(*value);
                    newTable[index].push_back(value);
                }
            }
            capacity = newCapacity;
            table = newTable;
        }
        else if (loadFactor < 0.25 && capacity > 100) { // if load factor is too low, resize to half the capacity (with a minimum capacity of 100)
            size_t newCapacity = capacity / 2;
            newCapacity = newCapacity < 100 ? 100 : newCapacity;
            auto newTable = std::vector<std::list<std::shared_ptr<T>>>(newCapacity);
            for (size_t i = 0; i < capacity; i++) {
                for (const auto& value : table[i]) {
                    size_t index = hash(*value);
                    newTable[index].push_back(value);
                }
            }
            capacity = newCapacity;
            table = newTable;
        }
    }
};

int main() {
    HashSet<int> hs;
    hs.insert(1);
    hs.insert(2);
    hs.insert(3);
    std::cout << hs.contains(2) << std::endl; // outputs 1 (true)
    hs.remove(2);
    std::cout << hs.contains(2) << std::endl; // outputs 0 (false)
}
