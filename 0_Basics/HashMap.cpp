#include<bits/stdc++.h>
using namespace std;

class HashMap {
public:
    /**
     * @brief Construct a new Hash Map object
     * 
     */
    HashMap() {
        data.resize(size);
    }

    /**
     * @brief put key value pair in hash map
     * 
     * @param key 
     * @param val 
     */
    void put(int key, int val) {
        auto& list = data[key % size];
        for(auto& p : list ) {
            if(p.first == key) {
                p.second = val;
                return;
            }
        }
        list.emplace_back(key, val);
    }

    /**
     * @brief get value from key
     * 
     * @param key 
     * @return int 
     */
    int get(int key) {
        auto& list = data[key % size];
        for(auto& p : list) {
            if(p.first == key)
                return p.second;
        }
        return -1;
    }

    /**
     * @brief remove key value pair
     * 
     * @param key 
     */
    void remove(int key) {
        auto& list = data[key % size];
        for(auto p = list.begin(); p != list.end(); p++) {
            if(p->first == key) {
                list.erase(p);
                return;
            }
        }
    }

private:
    vector<list<pair<int,int>>> data;
    size_t size = 10000;
};

int main() {
    // solution
    HashMap* map = new HashMap();

    for(int i = 0; i < 10; i++) {
        map->put(i, i*10);
    }

    cout << map->get(6) << endl;
    return 0;
}