#include <iostream>
#include <vector>
using namespace std;

int myhash(string key, int size) { return key.length() % size; }
int myhash(int key, int size) { return key % size; }

template <typename K, typename V>
class HashMap {
   private:
    int TABLE_SIZE;
    vector<vector<pair<K, V> > > table;

   public:
    HashMap(int size) {
        TABLE_SIZE = size;
        for (int i = 0; i < size; i++) table.push_back({});
    }
    ~HashMap() { delete[] table; }
    void insert(K key, V value) {
        int hashValue = myhash(key, TABLE_SIZE);
        // check if key is already present
        if (get(key) != (V)-1) {
            // update the value of the key
            for (int i = 0; i < table[hashValue].size(); i++) {
                if (table[hashValue][i].first == key) {
                    table[hashValue][i] = {key, value};
                    return;
                }
            }
        } else {
            table[hashValue].push_back({key, value});
        }
    }
    V get(K key) {
        int hashValue = myhash(key, TABLE_SIZE);
        for (const auto [k, v] : table[hashValue]) {
            if (k == key) return v;
        }
        return (V)-1;
    }
    bool remove(K key) {
        int hashValue = myhash(key, TABLE_SIZE);
        if (get(key) != (V)-1) {
            for (int i = 0; i < table[hashValue].size(); i++) {
                if (table[hashValue][i].first == key) {
                    // found!
                    table[hashValue].erase(table[hashValue].begin() + i);
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    // implementation of a hash map with template

    HashMap<string, int> *table = new HashMap<string, int>(10);
    table->insert("hello", 1);
    cout << table->get("hello") << endl;  // 1
    table->insert("world", 2);
    table->insert("hello", 3);
    cout << table->get("world") << endl;  // 2
    cout << table->get("hello") << endl;  // 3
    table->remove("hello");
    cout << table->get("hello") << endl;  // -1 (not found)

    HashMap<int, int> *table2 = new HashMap<int, int>(10);
    table2->insert(1, 123);
    table2->insert(2, 456);
    cout << table2->get(1) << endl;  // 123
    cout << table2->get(3) << endl;  // -1 (not found)
    table2->insert(1, 222);
    cout << table2->get(1) << endl;  // 222

    return 0;
}
